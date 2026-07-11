#include "common.h"

extern int D_800BDEE0[5];

void func_80037A70(void) {
    D_800BDEE0[0] = 0xA;
    D_800BDEE0[1] = 0x10;
    D_800BDEE0[2] = 0x28;
    D_800BDEE0[3] = 0x1E;
    D_800BDEE0[4] = 0;
}

void func_80037AAC(void) {
}

void func_80037AB4(void) {
}

void func_80037ABC(void) {
}

void func_80037AC4(void) {
}

extern int D_8006FA88;

void func_80037ACC(short arg0) {
    D_8006FA88 = arg0;
}

void func_80037AE0(void) {
    func_80037ACC(0x140);
}

void Set3DTextPosition(short x, short y)
{
    D_800BDEE0[2] = x;
    D_800BDEE0[3] = y;
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

extern int* D_80157050;
extern int D_800EB87C;
extern int D_800E5D20;

void func_8003959C(void) {
    int* ptr;

    ptr = D_80157050;
    D_800EB87C = -1;
    D_800E5D20 = 1;
    D_80157050 = ptr + 2;
    ptr[0] = 0xB6000000;
    ptr[1] = 0x3000;
    D_80157050 = ptr + 4;
    ptr[2] = 0xFCFFFFFF;
    ptr[3] = 0xFFFE793C;
}

extern int* gameTracker8;
extern unsigned int* D_80156B14;
extern int D_800B83B8;
extern int D_801574F8;
extern int D_80157058;
extern int D_800E9734;
extern int D_80154714;

void func_80039600(void) {
    D_801574F8 = D_80156B14[1];
    D_800B83B8 = 2;
    D_80157058 = D_80156B14[2];
    D_800E9734 = D_80156B14[1] / ((short*)gameTracker8)[0x9A/2];
    D_80154714 = D_80156B14[2] / ((short*)gameTracker8)[0x9A/2];
}

INCLUDE_ASM("asm/nonmatchings/38670", func_80039688);

INCLUDE_ASM("asm/nonmatchings/38670", func_800396E0);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003986C);

INCLUDE_ASM("asm/nonmatchings/38670", func_800398FC);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039980);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039A58);

int func_80039C20(int* arg0, short* arg1) {
    short val = *(short*)((char*)arg0 + 0x98);
    int var_a1;

    if (val < -1) {
        var_a1 = val + 1;
    } else {
        *(short*)((char*)arg0 + 0x98) = val - 1;
        var_a1 = -1;
    }
    
    func_80039A58(arg0, var_a1);
}

INCLUDE_ASM("asm/nonmatchings/38670", func_80039C68);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003A028);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003A12C);
