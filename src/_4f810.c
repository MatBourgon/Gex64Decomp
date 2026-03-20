#include "common.h"

#include "types/GameTracker.h"

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAC0);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAC8);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAD8);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAE4);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAF0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004EC10);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004EF70);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004EFD0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F020);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F124);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F25C);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F398);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F4D0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F60C);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F784);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F920);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004FBBC);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004FE44);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8005011C);

void func_800503F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050400);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050508);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800506B8);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050854);

void func_800508CC(void) {
}

extern unsigned int* D_80156B14;

void func_800508D4(void) {
    gameTracker8->_4B12[0x4E] = 1;
    gameTracker8->_4B12[0x4F] = 1;
    gameTracker8->_4B12[0x50] = 1;
    gameTracker8->_4B12[0x51] = 1;
    D_80156B14 = (unsigned int*)&gameTracker8->_4B12[0x3E];
}

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050930);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050980);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800509E0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050A80);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050B64);

extern int D_8006F5AC[]; // large and in charge (24 bytes)
extern int D_800BDF08[];
extern int D_800EB860[];
extern int D_8014F360[];

void func_80050BC4(int arg0, int arg1, int arg2) {
    if (gameTracker8->_4B12[0x4F] != 0) {
        if (D_800EB860[arg0] != 0) {
            D_800BDF08[arg0] = func_800543D4(D_8014F360, D_800EB860[arg0]);
            func_80054164(D_800BDF08[arg0], arg1);
            if (D_8006F5AC[arg2 * 0x24/4] != 0) {
                func_80054330(D_800BDF08[arg0], D_8006F5AC[arg2 * 0x24/4]);
            }
        }
    }
}