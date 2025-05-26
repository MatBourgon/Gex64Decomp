#include "common.h"

typedef union
{
    int i[12];
    short s[12*2];
} _5f930_t;

extern void func_80060E30(_5f930_t*, void*, void*, int);
extern int func_80057C00(int, int, int*, int, int);

INCLUDE_RODATA("asm/nonmatchings/_5f930", D_8007EE10);

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005ED30);

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005EDD4);

extern void func_80060180();
extern void func_80060680();

void func_8005F26C(_5f930_t* arg0, int* arg1) {
    func_80060E30(arg0, &func_80060180, &func_80060680, 4);
    arg0->i[5] = func_80057C00(0, 0, arg1, 1, 0x50);
    arg0->i[14] = 1;
    arg0->i[18] = 0;
    arg0->s[13] = 1;
    arg0->s[20] = 1;
    arg0->s[23] = 1;
    arg0->s[14] = 1;
    arg0->s[15] = 1;
    arg0->s[16] = 0;
    arg0->s[17] = 0;
    arg0->s[19] = 1;
    arg0->s[18] = 0;
    arg0->s[19] = 1;
    arg0->s[18] = 0;
    arg0->i[12] = 0;
    arg0->i[13] = 0;
    arg0->s[12] = 0;
    arg0->i[15] = 0;
    arg0->i[16] = 0;
    arg0->i[17] = 0;
}

extern void func_8005F560();
extern void func_8005FD40();

void func_8005F324(_5f930_t* arg0, int (*arg1)(int*), int* arg2) {
    func_80060E30(arg0, &func_8005F560, &func_8005FD40, 0);
    arg0->i[5] = func_80057C00(0, 0, arg2, 1, 0x20);
    arg0->i[6] = func_80057C00(0, 0, arg2, 1, 0x20);
    arg0->i[12] = arg1(&arg0->i[13]);
    arg0->i[15] = 0;
    arg0->i[16] = 1;
    arg0->i[17] = 0;
}

extern void func_80060FC0();
extern void func_800611AC();

void func_8005F3D4(_5f930_t* arg0, int* arg1) {
    func_80060E30(arg0, &func_80060FC0, &func_800611AC, 1);
    arg0->i[5] = func_80057C00(0, 0, arg1, 1, 0x20);
    arg0->i[8] = 0;
    arg0->i[9] = 1;
    arg0->i[12] = 0;
    arg0->i[7] = 0;
    arg0->i[10] = 0;
    arg0->i[11] = 0;
    *(float*)&arg0->i[6] = 1.0f;
}

extern void func_80060070();
extern void func_8006014C();

void func_8005F460(_5f930_t* arg0, int arg1, int arg2) {
    func_80060E30(arg0, &func_80060070, &func_8006014C, 6);
    arg0->i[5] = 0;
    arg0->i[6] = arg2;
    arg0->i[7] = arg1;
}

extern void func_80060E50();
extern void func_80060F90();

void func_8005F4BC(_5f930_t* arg0, int arg1, int arg2) {
    func_80060E30(arg0, &func_80060E50, &func_80060F90, 7);
    arg0->i[5] = 0;
    arg0->i[6] = arg2;
    arg0->i[7] = arg1;
}


extern void func_80061E10();
extern void func_80061EB8();

void func_8005F518(_5f930_t* arg0) {
    func_80060E30(arg0, &func_80061E10, &func_80061EB8, 3);
    arg0->i[5] = 0;
    arg0->i[6] = 1;
}
