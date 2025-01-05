#include "common.h"

#include "zlib/codes.h"
#include "zlib/zlib.h"

extern char D_801E0BC0;
int inflate(z_stream* z, int compressedDataStart, int compressedDataSize) {
    int blockSize;
    int comnpressedBytesRemaining;
    int dataOffset;
    BOOL isDone;

    isDone = FALSE;
    comnpressedBytesRemaining = compressedDataSize;
    dataOffset = 0;
    
    while (z->avail_out != 0) {
        if ((z->avail_in == 0) && !isDone) {
            blockSize = 0x4000;
            if (comnpressedBytesRemaining < 0x4001) {
                blockSize = comnpressedBytesRemaining;
            }
            if (blockSize != 0) {
                func_8003BA7C(compressedDataStart + dataOffset, &D_801E0BC0, (blockSize + 7) & ~7);
                comnpressedBytesRemaining -= blockSize;
                dataOffset += blockSize;
                z->avail_in = blockSize;
            } else {
                z->avail_in = 0;
                isDone = TRUE;
            }
            z->next_in = &D_801E0BC0;
        }
        
        if (inflate_blocks(z->state, z, -5) != 0)
            break;
        
        if (isDone)
            break;
    }
    
    return z->total_out;
}

INCLUDE_ASM("asm/nonmatchings/zlib", func_801DA910_ED200);

INCLUDE_ASM("asm/nonmatchings/zlib", inflate_flush);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_mask);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_fixed_built);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_border);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_cplens);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_cplext);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_cpdist);

INCLUDE_RODATA("asm/nonmatchings/zlib", inflate_cpdext);

INCLUDE_ASM("asm/nonmatchings/zlib", inflate_blocks);

extern inflate_codes_state inflate_codesState;
inflate_codes_state* inflate_codes_new(unsigned int bl, unsigned int bd, struct inflate_huft* tl, struct inflate_huft* td, z_stream* z)
{
    inflate_codesState.mode = START;
    inflate_codesState.lbits = bl;
    inflate_codesState.dbits = bd;
    inflate_codesState.ltree = tl;
    inflate_codesState.dtree = td;
    return &inflate_codesState;
}

INCLUDE_ASM("asm/nonmatchings/zlib", inflate_codes);

INCLUDE_ASM("asm/nonmatchings/zlib", huft_build);

INCLUDE_ASM("asm/nonmatchings/zlib", inflate_trees_bits);

INCLUDE_ASM("asm/nonmatchings/zlib", inflate_trees_dynamic);

INCLUDE_ASM("asm/nonmatchings/zlib", inflate_trees_fixed);
