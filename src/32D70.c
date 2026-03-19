#include "common.h"

#include "types/Vector.h"
#include "types/Matrix.h"

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032170);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032258);

void MATH3D_ApplyMatrix(_Matrix* mat, SVECTOR* rhs, SVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC);
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC);
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC);
}


INCLUDE_ASM("asm/nonmatchings/32D70", func_80032428);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032528);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032630);

INCLUDE_ASM("asm/nonmatchings/32D70", func_800327C0);

INCLUDE_ASM("asm/nonmatchings/32D70", func_800329A0);

INCLUDE_ASM("asm/nonmatchings/32D70", func_800329DC);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032B34);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032BD0);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032F30);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032F90);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032FBC);

INCLUDE_ASM("asm/nonmatchings/32D70", func_800330DC);

INCLUDE_ASM("asm/nonmatchings/32D70", func_8003310C);

INCLUDE_ASM("asm/nonmatchings/32D70", func_800331BC);

INCLUDE_ASM("asm/nonmatchings/32D70", func_800331DC);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80033200);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80033220);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80033228);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80033248);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80033268);

void func_80033270(void) {
}

void func_80033278(void) {
}

void func_80033280(void) {
}

void func_80033288(void) {
}

INCLUDE_ASM("asm/nonmatchings/32D70", func_80033290);

void func_800332B4(void) {
}

INCLUDE_ASM("asm/nonmatchings/32D70", func_800332BC);

void func_800332D8(void) {
}

INCLUDE_ASM("asm/nonmatchings/32D70", func_800332E0);

INCLUDE_ASM("asm/nonmatchings/32D70", func_80033304);

void func_80033334(void) {
}

void func_8003333C(void) {
}

void func_80033344(void) {
}

void func_8003334C(void) {
}

void func_80033354(void) {
}

INCLUDE_ASM("asm/nonmatchings/32D70", func_8003335C);

INCLUDE_ASM("asm/nonmatchings/32D70", func_800333E0);
