#include "common.h"

INCLUDE_ASM("asm/nonmatchings/38670", func_80037A70);

void func_80037AAC(void) {
}

void func_80037AB4(void) {
}

void func_80037ABC(void) {
}

void func_80037AC4(void) {
}

INCLUDE_ASM("asm/nonmatchings/38670", func_80037ACC);

INCLUDE_ASM("asm/nonmatchings/38670", func_80037AE0);

extern int D_800BDEE8;
extern int D_800BDEEC;

void Set3DTextPosition(short x, short y)
{
    D_800BDEE8 = x;
    D_800BDEEC = y;
}

void func_80037B24(void) {
}

void func_80037B2C(void) {
}

INCLUDE_ASM("asm/nonmatchings/38670", func_80037B34);

INCLUDE_ASM("asm/nonmatchings/38670", func_80037F68);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003860C);

INCLUDE_ASM("asm/nonmatchings/38670", func_80038798);

INCLUDE_ASM("asm/nonmatchings/38670", vPrint3DTextf);

void osSyncPrintf(const char* fmt, ...)
{

}

void Print3DTextf(char* format, ...)
{
    char va_list[0];
    vPrint3DTextf(format, va_list + 12);
}

INCLUDE_ASM("asm/nonmatchings/38670", func_80038BD0);

INCLUDE_ASM("asm/nonmatchings/38670", func_80038FDC);

INCLUDE_ASM("asm/nonmatchings/38670", func_800390CC);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003922C);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003959C);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039600);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039688);

INCLUDE_ASM("asm/nonmatchings/38670", func_800396E0);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003986C);

INCLUDE_ASM("asm/nonmatchings/38670", func_800398FC);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039980);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039A58);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039C20);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039C68);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003A028);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003A12C);
