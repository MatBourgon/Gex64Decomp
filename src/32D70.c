#include "common.h"

#include <PR/os_message.h>
#include <PR/os_pi.h>
#include "types/Vector.h"
#include "types/Matrix.h"

void MATH3D_ApplyMatrix(MATRIX* mat, SVECTOR* rhs, LVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC);
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC);
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC);
}

void MATH3D_ApplyMatrixLV(MATRIX* mat, LVECTOR* rhs, LVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC);
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC);
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC);
}

void MATH3D_ApplyMatrixSV(MATRIX* mat, SVECTOR* rhs, SVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC);
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC);
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC);
}

void func_80032428(MATRIX* mat, SVECTOR* rhs, LVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC) + mat->l[0];
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC) + mat->l[1];
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC) + mat->l[2];
}

INCLUDE_ASM("asm/nonmatchings/32D70", func_80032528);

/*void func_80032528(MATRIX* mat, SVECTOR* rhs, SVECTOR* out) {
    out->x = (((mat->m[0][0] * rhs->x) + (mat->m[0][1] * rhs->y) + (mat->m[0][2] * rhs->z)) >> 0xC) + mat->l[0];
    out->y = (((mat->m[1][0] * rhs->x) + (mat->m[1][1] * rhs->y) + (mat->m[1][2] * rhs->z)) >> 0xC) + mat->l[1];
    out->z = (((mat->m[2][0] * rhs->x) + (mat->m[2][1] * rhs->y) + (mat->m[2][2] * rhs->z)) >> 0xC) + mat->l[2];
}*/

// Split missing here?

// Load music?
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

extern OSMesgQueue D_800E5FE8;

void func_8003310C(int arg0, void* arg1, int arg2) {
    OSIoMesg sp20;
    void* sp38;
    int var_s0;
    int var_s1;
    int var_s3;
    void* var_s2;

    var_s3 = arg0;
    var_s2 = arg1;
    var_s1 = arg2;
    while (var_s1 != 0) {
        var_s0 = var_s1;
        if (var_s1 > 0x4000) {
            var_s0 = 0x4000;
        }
        osInvalDCache(var_s2, var_s0);
        osPiStartDma(&sp20, 0, 0, var_s3, var_s2, var_s0, &D_800E5FE8);
        osRecvMesg(&D_800E5FE8, &sp38, 1);
        var_s3 += var_s0;
        var_s1 -= var_s0;
        var_s2 += var_s0;
    }
}

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
