#include "common.h"

INCLUDE_ASM("asm/nonmatchings/14AC0", func_80013EC0);

INCLUDE_ASM("asm/nonmatchings/14AC0", func_8001409C);

INCLUDE_ASM("asm/nonmatchings/14AC0", func_80014294);

INCLUDE_ASM("asm/nonmatchings/14AC0", func_80014374);

INCLUDE_ASM("asm/nonmatchings/14AC0", func_800145C8);

INCLUDE_ASM("asm/nonmatchings/14AC0", func_800146FC);

INCLUDE_ASM("asm/nonmatchings/14AC0", func_800148D4);

INCLUDE_ASM("asm/nonmatchings/14AC0", func_80014C80);

INCLUDE_ASM("asm/nonmatchings/14AC0", func_80014D00);

extern char D_800E5DDE;

int func_80014D94(int arg0) {
    int i;

    for (i = arg0 - 1; i >= 0; i--) {
        if (((char*)&D_800E5DDE)[i * 0x20] != 0) {
            return i;
        }
    }
    return arg0;
}

extern int D_80157034;

int func_80014DD4(int arg0) {
    int i;
    int max;

    max = D_80157034;
    for (i = arg0 + 1; i < max; i++) {
        if (((char*)&D_800E5DDE)[i * 0x20] != 0) {
            return i;
        }
    }
    return arg0;
}

INCLUDE_ASM("asm/nonmatchings/14AC0", func_80014E28);
