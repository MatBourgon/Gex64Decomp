#include "common.h"

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003DEA0);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003DF24);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E06C);

INCLUDE_ASM("asm/nonmatchings/3EAA0", func_8003E1B4);

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

