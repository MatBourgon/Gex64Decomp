#include "common.h"

INCLUDE_ASM("asm/nonmatchings/405D0", func_8003F9D0);

INCLUDE_ASM("asm/nonmatchings/405D0", func_8003FA48);

INCLUDE_ASM("asm/nonmatchings/405D0", func_8003FAD0);

extern int D_80156BD4;
extern int D_80156BE4;
extern char D_800E9760;

int func_8003FD84(void) {
    int bitPos;
    int bytePos;
    int bit;

    bytePos = D_80156BE4;
    bitPos = D_80156BD4;
    bit = (((char*)&D_800E9760)[bytePos] >> bitPos) & 1;
    D_80156BD4 = bitPos - 1;
    if (bitPos - 1 < 0) {
        D_80156BD4 = 7;
        D_80156BE4 = bytePos + 1;
    }
    return bit;
}

INCLUDE_ASM("asm/nonmatchings/405D0", func_8003FDD8);
