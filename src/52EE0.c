#include "common.h"

extern int D_800791E0;
extern int D_800791E4;

void func_800522E0(int arg0) {
    D_800791E0 += arg0;
    D_800791E4 = D_800791E0 >> 8;
}

INCLUDE_ASM("asm/nonmatchings/52EE0", func_80052308);
