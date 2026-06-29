#!/usr/bin/env python3
"""
n64_decompress.py — Gex 64: Enter the Gecko N64 Asset Decompressor
====================================================================

Crystal Dynamics stored all N64 game assets (object blobs and level blobs)
as raw DEFLATE streams (zlib wbits=-15, i.e., no zlib header or Adler32 trailer).
This is identical to the "deflate" Content-Encoding in HTTP, or to zip's
compressed data portion.

Usage:
    python3 n64_decompress.py <rom.z64> [output_dir]

Extracts all 26 levels and 735 objects to output_dir/.
"""

import struct, zlib, os, sys

def decompress_blob(rom_bytes, start, end):
    """Decompress a raw DEFLATE blob from ROM[start:end].
    Handles trailing zero padding (up to 16 bytes) automatically.
    Returns decompressed bytes, or raises ValueError on failure.
    """
    data = rom_bytes[start:end]
    for strip in range(0, 17):
        try:
            compressed = data[:-strip] if strip > 0 else data
            return zlib.decompressobj(-15).decompress(compressed)
        except zlib.error:
            continue
    raise ValueError(f"Could not decompress blob at ROM 0x{start:07X}-0x{end:07X}")


def extract_all(rom_path, out_dir=None):
    rom = open(rom_path, 'rb').read()
    assert rom[:4] in (b'\x80\x37\x12\x40', b'\x37\x80\x40\x12', b'\x40\x12\x37\x80'), \
        "Not a valid N64 ROM"
    # Ensure big-endian (.z64)
    if rom[0] == 0x37:  # .v64 byteswapped
        rom = bytes(b for pair in zip(rom[1::2], rom[0::2]) for b in pair)
    elif rom[0] == 0x40:  # .n64 wordswapped
        import array
        a = array.array('I', rom); a.byteswap(); rom = a.tobytes()
    assert rom[0] == 0x80, "Could not normalize to z64 format"

    RDRAM_BASE = 0x80000400

    # ── LEVEL INDEX ───────────────────────────────────────────────────────────
    # 26 entries × 32 bytes at ROM 0x0708E0
    # Each entry:
    #   +0x00 uint32 rom_start
    #   +0x04 uint32 rom_end
    #   +0x08 uint32 func1_rom_offset  (per-level update function, ROM-relative)
    #   +0x0C uint32 func2_rom_offset
    #   +0x10 uint32 rdram_target       (per-mission struct RDRAM address)
    #   +0x14 char[12] level_name
    LEV_IDX  = 0x0708E0
    LEV_COUNT = 26

    # ── OBJECT INDEX ──────────────────────────────────────────────────────────
    # 735 entries × 16 bytes at ROM 0x0745F0
    # Each entry:
    #   +0x00 char[8] name
    #   +0x08 uint32 rom_start
    #   +0x0C uint32 rom_end
    OBJ_IDX  = 0x0745F0
    OBJ_COUNT = 735

    if out_dir:
        os.makedirs(out_dir, exist_ok=True)
        lev_dir = os.path.join(out_dir, 'levels')
        obj_dir = os.path.join(out_dir, 'objects')
        os.makedirs(lev_dir, exist_ok=True)
        os.makedirs(obj_dir, exist_ok=True)

    print("=== LEVELS ===")
    lev_ok = lev_fail = 0
    for i in range(LEV_COUNT):
        off  = LEV_IDX + i * 32
        rs   = struct.unpack_from('>I', rom, off+0)[0]
        re   = struct.unpack_from('>I', rom, off+4)[0]
        name = rom[off+20:off+32].split(b'\x00')[0].decode('ascii', 'replace')
        try:
            data = decompress_blob(rom, rs, re)
            lev_ok += 1
            ratio = len(data) / (re - rs)
            print(f"  [{i:2d}] {name:<12} {(re-rs)//1024:5d}KB → {len(data)//1024:6d}KB ({ratio:.2f}x)")
            if out_dir:
                fname = os.path.join(lev_dir, f"{name}.bin")
                open(fname, 'wb').write(data)
        except Exception as e:
            lev_fail += 1
            print(f"  [{i:2d}] {name:<12} FAILED: {e}")

    print(f"\n=== OBJECTS ===")
    obj_ok = obj_fail = obj_stub = 0
    for i in range(OBJ_COUNT):
        off  = OBJ_IDX + i * 16
        name = rom[off:off+8].split(b'\x00')[0].decode('ascii', 'replace')
        rs   = struct.unpack_from('>I', rom, off+8)[0]
        re   = struct.unpack_from('>I', rom, off+12)[0]
        if rom[rs] == 0x63:   # stub/null object, already uncompressed
            obj_stub += 1
            if out_dir:
                fname = os.path.join(obj_dir, f"{name}.bin")
                open(fname, 'wb').write(bytes(rom[rs:re]))
            continue
        try:
            data = decompress_blob(rom, rs, re)
            obj_ok += 1
            if out_dir:
                fname = os.path.join(obj_dir, f"{name}.bin")
                open(fname, 'wb').write(data)
        except Exception as e:
            obj_fail += 1
            print(f"  [{i:3d}] {name:<10} FAILED: {e}")

    print(f"Objects: {obj_ok} decompressed, {obj_stub} uncompressed stubs, {obj_fail} failures")
    print(f"Levels:  {lev_ok} decompressed, {lev_fail} failures")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <rom.z64> [output_dir]")
        sys.exit(1)
    extract_all(sys.argv[1], sys.argv[2] if len(sys.argv) > 2 else None)
