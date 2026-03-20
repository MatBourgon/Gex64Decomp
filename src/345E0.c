#include "common.h"

#include "types/Matrix.h"

INCLUDE_ASM("asm/nonmatchings/345E0", func_800339E0);

INCLUDE_ASM("asm/nonmatchings/345E0", func_80033A80);

INCLUDE_ASM("asm/nonmatchings/345E0", func_80034640);

INCLUDE_ASM("asm/nonmatchings/345E0", func_800346EC);

INCLUDE_ASM("asm/nonmatchings/345E0", func_80034BF8);

INCLUDE_ASM("asm/nonmatchings/345E0", func_80034DB8);

INCLUDE_ASM("asm/nonmatchings/345E0", func_80034F20);

INCLUDE_ASM("asm/nonmatchings/345E0", func_80034FE4);

void func_80035100(int* arg0) {
    int temp_a0;

    temp_a0 = arg0[0x34/4];
    if (temp_a0 != 0) {
        func_80034F20(temp_a0);
    }
}

MATRIX* func_80035130(MATRIX* lhs, MATRIX* rhs, MATRIX* dest) {
    dest->m[0][0] = (((lhs->m[0][0] * rhs->m[0][0]) + (lhs->m[0][1] * rhs->m[1][0]) + (lhs->m[0][2] * rhs->m[2][0])) >> 0xC);
    dest->m[0][1] = (((lhs->m[0][0] * rhs->m[0][1]) + (lhs->m[0][1] * rhs->m[1][1]) + (lhs->m[0][2] * rhs->m[2][1])) >> 0xC);
    dest->m[0][2] = (((lhs->m[0][0] * rhs->m[0][2]) + (lhs->m[0][1] * rhs->m[1][2]) + (lhs->m[0][2] * rhs->m[2][2])) >> 0xC);
    dest->m[1][0] = (((lhs->m[1][0] * rhs->m[0][0]) + (lhs->m[1][1] * rhs->m[1][0]) + (lhs->m[1][2] * rhs->m[2][0])) >> 0xC);
    dest->m[1][1] = (((lhs->m[1][0] * rhs->m[0][1]) + (lhs->m[1][1] * rhs->m[1][1]) + (lhs->m[1][2] * rhs->m[2][1])) >> 0xC);
    dest->m[1][2] = (((lhs->m[1][0] * rhs->m[0][2]) + (lhs->m[1][1] * rhs->m[1][2]) + (lhs->m[1][2] * rhs->m[2][2])) >> 0xC);
    dest->m[2][0] = (((lhs->m[2][0] * rhs->m[0][0]) + (lhs->m[2][1] * rhs->m[1][0]) + (lhs->m[2][2] * rhs->m[2][0])) >> 0xC);
    dest->m[2][1] = (((lhs->m[2][0] * rhs->m[0][1]) + (lhs->m[2][1] * rhs->m[1][1]) + (lhs->m[2][2] * rhs->m[2][1])) >> 0xC);
    dest->m[2][2] = (((lhs->m[2][0] * rhs->m[0][2]) + (lhs->m[2][1] * rhs->m[1][2]) + (lhs->m[2][2] * rhs->m[2][2])) >> 0xC);
    dest->l[0] = ((((lhs->m[0][0] * rhs->l[0]) + (lhs->m[0][1] * rhs->l[1]) + (lhs->m[0][2] * rhs->l[2])) >> 0xC) + lhs->l[0]);
    dest->l[1] = ((((lhs->m[1][0] * rhs->l[0]) + (lhs->m[1][1] * rhs->l[1]) + (lhs->m[1][2] * rhs->l[2])) >> 0xC) + lhs->l[1]);
    dest->l[2] = ((((lhs->m[2][0] * rhs->l[0]) + (lhs->m[2][1] * rhs->l[1]) + (lhs->m[2][2] * rhs->l[2])) >> 0xC) + lhs->l[2]);
}
