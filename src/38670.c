#include "common.h"

extern int D_800BDEE0;
extern int D_800BDEE4;
extern int D_800BDEF0;

void func_80037A70(void) {
    D_800BDEE0 = 0xA;
    D_800BDEE4 = 0x10;
    D_800BDEE8 = 0x28;
    D_800BDEEC = 0x1E;
    D_800BDEF0 = 0;
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

extern int D_800BD6D0[];

void func_80038798(char arg0, short arg1, short arg2, char arg3, char arg4, char arg5) {
    char* entry;

    if (D_800BDEF0 < 0xFF) {
        entry = (char*)&D_800BD6D0[D_800BDEF0 * 2];
        ((short*)entry)[0] = arg1;
        ((short*)entry)[1] = arg2;
        entry[4] = arg0;
        entry[5] = arg3;
        entry[6] = arg5;
        D_800BDEF0++;
    }
}

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

extern int D_800EB87C;
extern int D_800E5D20;
extern int D_80157050;

void func_8003959C(void) {
    int* dl;

    dl = (int*)D_80157050;
    D_800EB87C = -1;
    D_800E5D20 = 1;
    D_80157050 = (int)(dl + 2);
    dl[0] = 0xB6000000;
    dl[1] = 0x3000;
    D_80157050 = (int)(dl + 4);
    dl[2] = 0xFCFFFFFF;
    dl[3] = 0xFFFE793C;
}

INCLUDE_ASM("asm/nonmatchings/38670", func_80039600);

extern int D_8006FC08;
extern int D_8006FAA4;
extern int D_8006FAB4;
extern int D_8006FAC4;
extern int D_8006FAD4;

void func_80039688(char arg0, char arg1, char arg2, char* arg3) {
    int color;

    arg3[0x96] = arg2;
    arg3[0x94] = arg0;
    arg3[0x95] = arg1;
    color = ((unsigned char)arg3[0x94] << 24) | ((unsigned char)arg3[0x95] << 16) | ((unsigned char)arg2 << 8);
    D_8006FC08 = color;
    D_8006FAA4 = color;
    D_8006FAB4 = color;
    D_8006FAC4 = color;
    D_8006FAD4 = color;
}

INCLUDE_ASM("asm/nonmatchings/38670", func_800396E0);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003986C);

INCLUDE_ASM("asm/nonmatchings/38670", func_800398FC);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039980);

INCLUDE_ASM("asm/nonmatchings/38670", func_80039A58);

void func_80039C20(int* arg0) {
    short counter;

    counter = ((short*)arg0)[0x98/2];
    if (counter < -1) {
        func_80039A58(arg0, counter + 1);
    } else {
        ((short*)arg0)[0x98/2] = counter - 1;
        func_80039A58(arg0, -1);
    }
}

INCLUDE_ASM("asm/nonmatchings/38670", func_80039C68);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003A028);

INCLUDE_ASM("asm/nonmatchings/38670", func_8003A12C);
