#include "common.h"

#include "types/Instance.h"

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_800073B0);

void func_80007CBC(int* arg0) {
    if (arg0[0x4BC/4] == 0) {
        arg0[0x4BC/4] = 0xF;
        func_8004AAA8(PlayerInstance, 0x7B, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80007D00);

INCLUDE_RODATA("asm/nonmatchings/_7fb0", D_8007B7B0);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80007D68);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000853C);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80008580);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80009600);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80009C24);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000A3FC);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000A5C0);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000AA60);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000AAA0);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000AF78);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000B054);
