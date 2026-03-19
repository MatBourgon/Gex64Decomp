#include "common.h"

#include "types/Matrix.h"

INCLUDE_ASM("asm/nonmatchings/3EAA0", RotMatrix);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003DF24);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E06C);

MATRIX* RotMatrixZ(int angle, MATRIX* mat) {
    short temp_s0;
    short temp_v0;
    
    int x1;
    int x2;
    int y1;
    int y2;
    int z1;
    int z2;

    temp_s0 = func_8003A4E0(angle); // probably sin
    temp_v0 = func_8003A6AC(angle); // probably cos
    
    x1 = mat->m[0][0];
    x2 = mat->m[1][0];
    
    y1 = mat->m[0][1];
    y2 = mat->m[1][1];
    
    z1 = mat->m[0][2];
    z2 = mat->m[1][2];
    
    mat->m[0][0] = (((x1 * temp_v0) - (x2 * temp_s0)) >> 0xC);
    mat->m[1][0] = (((x1 * temp_s0) + (x2 * temp_v0)) >> 0xC);
    
    mat->m[0][1] = (((y1 * temp_v0) - (y2 * temp_s0)) >> 0xC);
    mat->m[1][1] = (((y1 * temp_s0) + (y2 * temp_v0)) >> 0xC);
    
    mat->m[0][2] = (((z1 * temp_v0) - (z2 * temp_s0)) >> 0xC);
    mat->m[1][2] = (((z1 * temp_s0) + (z2 * temp_v0)) >> 0xC);

    return mat;
}

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E2FC);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E378);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E478);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E65C);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E758);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E940);

int strcmp(const char* arg0, const char* arg1) {
    while(*arg0 == *arg1 && *arg0 != '\0')
    {
        arg0++, arg1++;
    }
    
    if (*arg0 >= *arg1) {
        return *arg0 != *arg1;
    }
    
    return -1;
}

char* strcpy(char* dst, const char* src) {
    char temp_v0;
    char temp_v0_2;
    char* temp_v1;
    char* var_a0;
    const char* var_a1;

    var_a0 = dst;
    var_a1 = src;
    temp_v0 = *var_a1;
    temp_v1 = var_a0;
    *var_a0 = temp_v0;
    if (*var_a0 != 0) {
        do {
            var_a1 += 1;
            temp_v0_2 = *var_a1;
            var_a0 += 1;
            *var_a0 = temp_v0_2;
        } while (temp_v0_2 != 0);
    }
    return temp_v1;
}

