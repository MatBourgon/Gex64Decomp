#include "common.h"

extern short D_80131798;
extern short D_8014E828;
extern int D_801317B8;
extern int D_8014E848;
extern int D_80200000;
extern int D_80225800;

void func_8002B840(void) {
    D_80131798 = 2;
    D_8014E828 = 2;
    D_801317B8 = (int)&D_80200000;
    D_8014E848 = (int)&D_80225800;
    osViSetSpecialFeatures(0x42);
}

INCLUDE_ASM("asm/nonmatchings/2C440", func_8002B894);

INCLUDE_ASM("asm/nonmatchings/2C440", func_8002B998);

INCLUDE_ASM("asm/nonmatchings/2C440", func_8002BB80);
