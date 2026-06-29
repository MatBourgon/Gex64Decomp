#include "common.h"

INCLUDE_ASM("asm/nonmatchings/42BD0", func_80041FD0);

int func_80042120(short* arg0, int arg1) {
    short* ptr;

    ptr = arg0 + arg1;
    return MATH3D_FastSqrt(ptr[0] * ptr[0] + ptr[3] * ptr[3] + ptr[6] * ptr[6]) >> 6;
}

INCLUDE_ASM("asm/nonmatchings/42BD0", func_80042184);

INCLUDE_ASM("asm/nonmatchings/42BD0", func_80042330);

INCLUDE_ASM("asm/nonmatchings/42BD0", func_80042674);

INCLUDE_ASM("asm/nonmatchings/42BD0", func_80042A4C);

INCLUDE_ASM("asm/nonmatchings/42BD0", func_80042CC0);

INCLUDE_ASM("asm/nonmatchings/42BD0", func_800434BC);

INCLUDE_ASM("asm/nonmatchings/42BD0", func_80043708);
