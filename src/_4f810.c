#include "common.h"

extern short D_8007865E;

extern int D_80157508[];

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAC0);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAC8);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAD8);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAE4);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAF0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004EC10);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004EF70);

void func_8004EFD0() {
    int* temp_a0;

    if (D_8007865E != -1) {
        temp_a0 = &D_80157508[D_8007865E * 0x14/4];
        if (*temp_a0 >= 2) {
            (*temp_a0)--;
        }
    }
}