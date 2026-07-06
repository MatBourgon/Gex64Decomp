#!/usr/bin/env python3
"""
coddog_scan.py — Systematic cluster scan for Gex 64 decompilation.

Finds groups of functions with identical or near-identical assembly across
modules. Decompiling one function in a cluster gives all the others for free.

Usage:
    python3 tools/coddog_scan.py [--output CODDOG_CLUSTERS.md]

Output levels:
  EXACT   — raw instruction bytes are identical (guaranteed free match)
  NEAR    — same instruction sequence after normalizing absolute addresses
             (jal targets, lui/addiu address loads). High-confidence match;
             verify with objdiff before committing.
"""

import os
import re
import sys
import hashlib
import argparse
from collections import defaultdict

NONMATCHINGS = os.path.join(os.path.dirname(os.path.dirname(__file__)), "asm", "nonmatchings")
DEFAULT_OUTPUT = os.path.join(os.path.dirname(os.path.dirname(__file__)), "CODDOG_CLUSTERS.md")

# Mnemonics that reference absolute ROM addresses in their operand
JAL_MNEMONICS = {"jal", "j", "bal"}
ABS_ADDR_MNEMONICS = {"lui", "addiu", "ori", "la"}


def parse_asm_file(filepath):
    """
    Parse a .s file and return (text_instructions, rodata_labels).

    text_instructions: list of (raw_hex_bytes, full_instruction_text)
    rodata_labels: list of dlabel names embedded in this file

    Most function files have no section headers — instructions start at line 1.
    Files with rodata have a .section .rodata block first, then .section .text.
    We distinguish instruction lines (3-field comment: OFFSET VADDR BYTES) from
    rodata data lines (2-field comment: OFFSET VADDR) by checking the 8-hex byte field.
    """
    text_insts = []
    rodata_labels = []
    # Default: we're in text mode. .section .rodata switches us out;
    # .section .text switches us back in.
    in_text = True

    try:
        with open(filepath, "r", errors="replace") as f:
            for line in f:
                line = line.rstrip()

                if re.search(r"\.section\s+\.text", line):
                    in_text = True
                    continue
                if re.search(r"\.section\s+\.rodata", line):
                    in_text = False
                    continue

                if not in_text:
                    m = re.match(r"\s*dlabel\s+(\S+)", line)
                    if m:
                        rodata_labels.append(m.group(1))
                    continue

                # Instruction lines: /* ROM_OFFSET VADDR 8HEXBYTES */ mnemonic operands
                # Rodata data lines only have 2 fields in the comment, so they won't match.
                m = re.match(
                    r"\s*/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s*\*/\s*(\S.*)",
                    line,
                )
                if m:
                    raw_bytes = m.group(1)
                    inst_text = m.group(2).strip()
                    text_insts.append((raw_bytes, inst_text))
    except OSError:
        pass

    return text_insts, rodata_labels


def raw_hash(instructions):
    """Hash of the raw instruction byte sequence (exact match)."""
    raw = " ".join(b for b, _ in instructions)
    return hashlib.md5(raw.encode()).hexdigest()


def normalized_hash(instructions):
    """
    Hash after normalizing all module-specific address references:
      - jal/j/bal targets          → 'jal FUNC'
      - %hi(any_symbol)            → '%hi(SYM)'
      - %lo(any_symbol)            → '%lo(SYM)'
      - .LXXXXxxxx_xxxxxx labels   → '.LABEL'   (branch targets)
      - raw 0x8xxxxxxx hex values  → 'ADDR'

    This catches pairs that are structurally identical but compiled into
    different module segments (different rodata labels, different local branch
    addresses, same external jal targets).
    """
    lines = []
    for _, inst in instructions:
        parts = inst.split()
        if not parts:
            continue
        mnem = parts[0]
        if mnem in JAL_MNEMONICS:
            lines.append(f"{mnem} FUNC")
        else:
            normalized = inst
            # Branch target labels: .L80xxxxxx_xxxxxx
            normalized = re.sub(r"\.(L[0-9A-Fa-f]{8}_[0-9A-Fa-f]+|L[0-9A-Fa-f]{8})\b", ".LABEL", normalized)
            # %hi(symbol) and %lo(symbol) — module-local data refs
            normalized = re.sub(r"%hi\([^)]+\)", "%hi(SYM)", normalized)
            normalized = re.sub(r"%lo\([^)]+\)", "%lo(SYM)", normalized)
            # Raw absolute addresses 0x80xxxxxx
            normalized = re.sub(r"\b0x8[0-9A-Fa-f]{5,7}\b", "ADDR", normalized)
            lines.append(normalized)
    content = "\n".join(lines)
    return hashlib.md5(content.encode()).hexdigest()


def scan(nonmatchings_root):
    """Walk nonmatchings dir, parse every function .s file, return cluster maps."""
    exact_map = defaultdict(list)    # raw_hash  -> list of FileInfo
    norm_map  = defaultdict(list)    # norm_hash -> list of FileInfo

    all_files = []
    for root, dirs, files in os.walk(nonmatchings_root):
        dirs.sort()
        for fname in sorted(files):
            if fname.endswith(".s") and not fname.startswith("D_"):
                all_files.append(os.path.join(root, fname))

    print(f"Scanning {len(all_files)} function .s files...", file=sys.stderr)

    no_text = 0
    for fpath in all_files:
        insts, rodata = parse_asm_file(fpath)
        if not insts:
            no_text += 1
            continue

        rel = os.path.relpath(fpath, nonmatchings_root)
        info = {
            "path": rel,
            "inst_count": len(insts),
            "has_rodata": bool(rodata),
            "rodata_labels": rodata,
        }
        rh = raw_hash(insts)
        nh = normalized_hash(insts)
        info["raw_hash"] = rh
        info["norm_hash"] = nh
        exact_map[rh].append(info)
        norm_map[nh].append(info)

    print(f"  (skipped {no_text} files with no parsed instructions)", file=sys.stderr)
    return exact_map, norm_map


def build_report(exact_map, norm_map):
    """Produce the markdown cluster report."""
    import datetime
    # Exact clusters (>1 member)
    exact_clusters = sorted(
        [(h, m) for h, m in exact_map.items() if len(m) > 1],
        key=lambda x: (-len(x[1]), x[1][0]["inst_count"]),
    )

    # Near-match clusters: same norm_hash but different raw_hashes within the group
    near_clusters = []
    for nh, members in norm_map.items():
        if len(members) < 2:
            continue
        raw_hashes_in_group = {info["raw_hash"] for info in members}
        if len(raw_hashes_in_group) > 1:
            # At least two distinct raw_hashes → genuine near-match
            near_clusters.append((nh, members))
    near_clusters.sort(key=lambda x: (-len(x[1]), x[1][0]["inst_count"]))

    total_exact_funcs = sum(len(m) for _, m in exact_clusters)
    total_near_funcs  = sum(len(m) for _, m in near_clusters)
    total_scanned     = sum(len(m) for m in exact_map.values())
    today = datetime.date.today().isoformat()

    lines = []
    lines += [
        "# Coddog Cluster Report",
        "",
        f"Auto-generated by `tools/coddog_scan.py` on {today}.",
        "Re-run after decompiling functions to keep this up to date: `python3 tools/coddog_scan.py`",
        "",
        "## Summary",
        "",
        f"| | Count | Functions |",
        f"|---|---|---|",
        f"| Functions scanned | — | {total_scanned} |",
        f"| **Exact clusters** (byte-for-byte identical, guaranteed free) | **{len(exact_clusters)}** | **{total_exact_funcs}** |",
        f"| **Near-match clusters** (same structure, different addresses/labels) | **{len(near_clusters)}** | **{total_near_funcs}** |",
        f"| **Total coddog yield** | **{len(exact_clusters)+len(near_clusters)}** | **{total_exact_funcs+total_near_funcs}** |",
        "",
        "**How to use:**",
        "1. Pick the smallest cluster you haven't tackled yet.",
        "2. Decompile any one member; the rest are free copies — just change the function name.",
        "3. For NEAR clusters, diff with `make buildobjdiff` before committing.",
        "   A near-match where `jal` targets differ between members is NOT a free copy.",
        "",
        "---",
        "",
    ]

    # ---- EXACT ----
    lines += [
        f"## Exact Matches — {len(exact_clusters)} clusters, {total_exact_funcs} functions",
        "",
        "Raw instruction bytes are byte-for-byte identical. Guaranteed free matches.",
        "",
    ]

    for i, (h, members) in enumerate(exact_clusters, 1):
        ic = members[0]["inst_count"]
        has_rd = any(info["has_rodata"] for info in members)
        rd_note = " ⚠️ has rodata" if has_rd else ""
        lines.append(f"### E{i:03d} · {len(members)} functions · {ic} instructions{rd_note}")
        for info in sorted(members, key=lambda x: x["path"]):
            lines.append(f"- `{info['path']}`")
        lines.append("")

    # ---- NEAR ----
    lines += [
        "---",
        "",
        f"## Near-Matches — {len(near_clusters)} clusters, {total_near_funcs} functions",
        "",
        "Same instruction sequence after normalizing `jal` targets and absolute address loads.",
        "Verify with objdiff before committing — a differing jal target means a different helper function is called.",
        "",
    ]

    for i, (h, members) in enumerate(near_clusters, 1):
        ic = members[0]["inst_count"]
        has_rd = any(info["has_rodata"] for info in members)
        rd_note = " ⚠️ has rodata" if has_rd else ""
        lines.append(f"### N{i:03d} · {len(members)} functions · {ic} instructions{rd_note}")
        for info in sorted(members, key=lambda x: x["path"]):
            lines.append(f"- `{info['path']}`")
        lines.append("")

    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--output", default=DEFAULT_OUTPUT)
    parser.add_argument("--nonmatchings", default=NONMATCHINGS)
    args = parser.parse_args()

    exact_map, norm_map = scan(args.nonmatchings)
    report = build_report(exact_map, norm_map)

    with open(args.output, "w") as f:
        f.write(report)

    # Print summary to stderr
    exact_c = [(h, m) for h, m in exact_map.items() if len(m) > 1]
    near_c  = [(h, m) for h, m in norm_map.items() if len(m) > 1
                and len({i["raw_hash"] for i in m}) > 1]
    print(
        f"\nResults:\n"
        f"  Exact clusters:      {len(exact_c):4d}  ({sum(len(m) for _, m in exact_c)} functions)\n"
        f"  Near-match clusters: {len(near_c):4d}  ({sum(len(m) for _, m in near_c)} functions)\n"
        f"\nReport written to {args.output}",
        file=sys.stderr,
    )


if __name__ == "__main__":
    main()
