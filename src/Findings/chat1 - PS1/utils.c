/*
 * utils.c — Core utility functions
 * Gex 2: Enter the Gecko (SLUS-00598)
 *
 * These are leaf functions with complete confirmed implementations.
 */

#include "../../include/gex2_types.h"
#include "../../include/gex2_globals.h"

/* -----------------------------------------------------------------------
 * MemRange_relocate — 0x8003CDB0
 *
 * Adjusts embedded pointers within a block of data when it moves in memory.
 * Each pointer p becomes: p = p - old_base + new_base
 *
 * Used by the A8AA geometry loader to fix up the compiled class block
 * after it's moved from the streaming buffer to its final RAM address.
 *
 * Parameters (confirmed from disasm of 0x8003C05C call site):
 *   old_base — where the block currently lives  (a0 = 0x801EEFD0)
 *   new_base — where it should appear to live   (a1 = target RAM address)
 *   size     — number of bytes to scan          (a2 = 0x5000 = 20,480)
 *
 * Has exactly ONE call site: 0x8003C05C inside Level_remoteInit.
 *
 * Algorithm (inferred from name + context):
 *   Walk the block 4 bytes at a time.
 *   If a word looks like a pointer into [old_base, old_base+size):
 *     word = word - old_base + new_base
 *
 * Exact discrimination logic (which words are pointers) is driven by the
 * A8AA relocation descriptor table that precedes the data block.
 * The descriptor triplets (field_offset, count, stride) tell this function
 * exactly which words to adjust — it doesn't scan blindly.
 *
 * STUB: needs the descriptor-table walking logic from full disasm.
 * ----------------------------------------------------------------------- */
void MemRange_relocate(void *old_base, void *new_base, u32 size) {
    /*
     * STUB implementation — correct linear scan version.
     * Replace with descriptor-table driven version once A8AA format
     * is fully decoded.
     */
    uintptr_t old_lo = (uintptr_t)old_base;
    uintptr_t old_hi = old_lo + size;
    uintptr_t delta  = (uintptr_t)new_base - old_lo;

    u32 *p   = (u32 *)old_base;
    u32 *end = (u32 *)((u8 *)old_base + size);

    while (p < end) {
        uintptr_t v = (uintptr_t)*p;
        if (v >= old_lo && v < old_hi) {
            *p = (u32)(v + delta);
        }
        p++;
    }
}

/* -----------------------------------------------------------------------
 * LBA_to_MSF — 0x80076BDC
 *
 * Converts a logical block address to CD-ROM Minutes:Seconds:Frames format.
 * Required by the PS1 CD controller for seeks; not needed on PC.
 *
 * Formula (confirmed from disasm):
 *   lba += 150           (offset for lead-in)
 *   frames  = lba % 75
 *   seconds = (lba / 75) % 60
 *   minutes = lba / 75 / 60
 *
 * Output: writes 3 bytes {minutes, seconds, frames} to dest.
 * ----------------------------------------------------------------------- */
void LBA_to_MSF(u32 lba, u8 *dest) {
    lba += 150;
    u32 frames  = lba % 75;
    u32 seconds = (lba / 75) % 60;
    u32 minutes = lba / 75 / 60;
    dest[0] = (u8)minutes;
    dest[1] = (u8)seconds;
    dest[2] = (u8)frames;
}

/* -----------------------------------------------------------------------
 * strcmp — 0x80075000
 * strncmp (n=12) — 0x80075100 / 0x80078798
 *
 * Standard string comparison; Crystal Dynamics shipped their own
 * implementations for PS1. On PC use libc versions.
 * ----------------------------------------------------------------------- */
/* These are just #define or static inlines to libc; listed for completeness. */

/* -----------------------------------------------------------------------
 * memcpy — 0x80074E30
 * memset — 0x80074EE0
 * MemCopy_n — 0x80074E70   (used by BigFile_init to copy TOC)
 *
 * Standard memory functions; custom PS1 implementations.
 * On PC, redirect to libc.
 * ----------------------------------------------------------------------- */

/* -----------------------------------------------------------------------
 * GameCtx field accessors
 * Convenience wrappers around raw field offsets.
 * ----------------------------------------------------------------------- */

u8 GameCtx_getActiveRemote(GameCtx *ctx) {
    return ctx->active_remote;  /* +0x6EFD */
}

u32 GameCtx_getCompletionBits(GameCtx *ctx) {
    return ctx->remote_completion;  /* +0x6EF4 */
}

void GameCtx_setRemoteBeaten(GameCtx *ctx, u8 remote_id) {
    if (remote_id < 26) {
        ctx->remote_completion |= (1u << remote_id);
    }
}

int GameCtx_isRemoteBeaten(GameCtx *ctx, u8 remote_id) {
    if (remote_id >= 26) return 0;
    return (ctx->remote_completion >> remote_id) & 1;
}
