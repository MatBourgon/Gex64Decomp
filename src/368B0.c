#include "common.h"

unsigned int func_80035CB0(unsigned int arg0, unsigned int arg1) {
    unsigned int r;
    unsigned int g;
    unsigned int b;

    r = ((arg0 >> 24) * (arg1 >> 24)) >> 8;
    g = (((arg0 >> 16) & 0xFF) * ((arg1 >> 16) & 0xFF)) >> 8;
    b = (((arg0 >> 8) & 0xFF) * ((arg1 >> 8) & 0xFF)) & 0xFF00;
    return (r << 24) + 0xFF + (g << 16) + b;
}

INCLUDE_ASM("asm/nonmatchings/368B0", func_80035D1C);

INCLUDE_ASM("asm/nonmatchings/368B0", func_80036250);

INCLUDE_ASM("asm/nonmatchings/368B0", func_8003645C);

INCLUDE_ASM("asm/nonmatchings/368B0", func_80036BA8);

INCLUDE_ASM("asm/nonmatchings/368B0", func_80037418);

INCLUDE_ASM("asm/nonmatchings/368B0", func_800374FC);

INCLUDE_ASM("asm/nonmatchings/368B0", func_800375E0);

INCLUDE_ASM("asm/nonmatchings/368B0", func_800376D0);

INCLUDE_ASM("asm/nonmatchings/368B0", func_800378D8);
