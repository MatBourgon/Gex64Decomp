/*
 * bigfile.c — BIGFILE.DAT table management
 * Gex 2: Enter the Gecko (SLUS-00598)
 *
 * Functions confirmed from disassembly of 0x8003B738..0x8003BB40.
 * All function addresses noted inline for cross-reference.
 */

#include "../../include/gex2_types.h"
#include "../../include/gex2_globals.h"
#include <string.h>

/* -----------------------------------------------------------------------
 * BigFile_hashName — 0x8003BA1C / inner loop 0x8003BA34 / delay 0x8003BA7C
 *
 * Computes a 32-bit identifier for a filename string.
 *
 * Algorithm (confirmed including delay-slot or 0x8003BA7C):
 *   For each byte b in name (NUL-terminated, NOT space-terminated):
 *     if 'a' <= b <= 'z': c = b & 0xDF   (lowercase → uppercase)
 *     else:               c = b           (digits, spaces, symbols: unchanged)
 *     sum_chars += c
 *     xor_products ^= (c * char_index)   (0-based index)
 *     char_count++
 *   return (char_count << 24) | (sum_chars << 12) | (xor_products & 0xFFF)
 *
 * Notes:
 *   - ONLY NUL (0x00) terminates — SPACE does NOT
 *   - Digit '7' becomes 0x17=23 (via &0xDF), NOT '7'=55
 *     (0x37 & 0xDF = 0x17) — this is a quirk of the masking approach
 *   - First character has index 0, so c[0]*0=0 contributes nothing to XOR
 * ----------------------------------------------------------------------- */
u32 BigFile_hashName(const char *name) {
    u32 sum_chars   = 0;
    u32 xor_products = 0;
    u32 char_count  = 0;

    for (;;) {
        u8 b = (u8)*name++;
        if (b == 0) break;

        /* lowercase a-z → uppercase (other chars unchanged) */
        u8 c;
        if ((u8)(b - 0x61u) < 0x1Au) {
            c = b & 0xDFu;
        } else {
            c = b;
        }

        sum_chars    = (sum_chars + c) & 0xFFFFFFFFu;
        /* NOTE: char_count is the CURRENT index (0 for first char) at time
         * of multiply — it increments AFTER the multiply per the asm.
         * The delay-slot XOR fires with the product of the current index. */
        xor_products = (xor_products ^ (u32)(c * char_count)) & 0xFFFFFFFFu;
        char_count++;
    }

    return (char_count  << 24)
         | ((sum_chars  << 12) & 0xFFFFFFFFu)
         | (xor_products & 0xFFFu);
}

/* -----------------------------------------------------------------------
 * BigFile_lookup — 0x8003BA80
 *
 * Searches g_StreamSlotTable for an entry whose name_hash matches the
 * hash of the given filename string.
 *
 * Returns: slot index [0, g_StreamSlotCount) on success,
 *          -1 (or some error value) on failure (logs to debug).
 *
 * Original logs: "CD ERROR: file %s not in bigfile"
 * ----------------------------------------------------------------------- */
int BigFile_lookup(const char *filename) {
    u32 target_hash = BigFile_hashName(filename);
    u32 n = g_StreamSlotCount;

    for (u32 i = 0; i < n; i++) {
        if (g_StreamSlotTable[i].name_hash == target_hash) {
            return (int)i;
        }
    }

    /* STUB: original logs "CD ERROR: file %s not in bigfile" via debug_log */
    return -1;
}

/* -----------------------------------------------------------------------
 * BigFile_init — 0x8003B738
 *
 * Called once at boot. Locates BIGFILE.DAT on the disc using CdSearchFile,
 * reads the first 8KB (4 sectors), stores TOC count to g_StreamSlotCount,
 * copies 192 × 24-byte entries to g_StreamSlotTable, and initialises the
 * CD streaming ring (g_CD_readSlots) and remote state table.
 *
 * On PC: reads from an OTR archive or a pre-extracted directory instead.
 * The CdSearchFile / LBA arithmetic is replaced by open()/fread().
 * ----------------------------------------------------------------------- */
void BigFile_init(/* const char *bigfile_path_on_disc — ignored on PC */) {
    /*
     * STUB — On PC this function becomes:
     *   1. Open the OTR/extracted BIGFILE
     *   2. fread first 8KB
     *   3. g_StreamSlotCount = *(u32*)buf
     *   4. memcpy(g_StreamSlotTable, buf+4, g_StreamSlotCount * 24)
     *   5. Clear g_RemoteStateTable
     *   6. Initialise g_CD_readSlots ring
     *
     * The BIGFILE format (confirmed from boot disasm):
     *   [0x0000] u32   n_resources  = 192
     *   [0x0004] BigFileTocEntry[192]   (24 bytes each, 4608 bytes total)
     *   [0x1204] resource data begins
     */
    extern void BigFile_init_pc(const char *archive_path);
    /* BigFile_init_pc("gex2.otr"); */
}
