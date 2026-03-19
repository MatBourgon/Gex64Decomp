#include "common.h"

#include "types/Matrix.h"

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030270);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030538);

INCLUDE_ASM("asm/nonmatchings/30E70", func_800305FC);

INCLUDE_ASM("asm/nonmatchings/30E70", func_800306DC);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030758);

INCLUDE_ASM("asm/nonmatchings/30E70", MATH3D_FastSqrt);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030938);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030A2C);

void MATH3D_IdentityMatrix(_Matrix* mat) {
    mat->m[0][0] = 0x1000;
    mat->m[0][1] = 0;
    mat->m[0][2] = 0;
    mat->m[1][0] = 0;
    mat->m[1][1] = 0x1000;
    mat->m[1][2] = 0;
    mat->m[2][0] = 0;
    mat->m[2][1] = 0;
    mat->m[2][2] = 0x1000;
}


INCLUDE_ASM("asm/nonmatchings/30E70", func_80030B88);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030BA0);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030BE0);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030C50);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030CB4);

INCLUDE_ASM("asm/nonmatchings/30E70", func_80030D34);
