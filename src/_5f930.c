#include "common.h"

INCLUDE_RODATA("asm/nonmatchings/_5f930", D_8007EE10);

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005ED30);

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005EDD4);

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005F26C);

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005F324);

extern void func_80060E30(int*, void*, void*, int);
extern int func_80057C00(int, int, int*, int, int);
extern void func_80060FC0();
extern void func_800611AC();

void func_8005F3D4(int* arg0, int* arg1) {
    func_80060E30(arg0, &func_80060FC0, &func_800611AC, 1);
    arg0[0x14/4] = func_80057C00(0, 0, arg1, 1, 0x20);
    arg0[0x20/4] = 0;
    arg0[0x24/4] = 1;
    arg0[0x30/4] = 0;
    arg0[0x1C/4] = 0;
    arg0[0x28/4] = 0;
    arg0[0x2C/4] = 0;
    *(float*)&arg0[0x18/4] = 1.0f;
}

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005F460);

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005F4BC);

INCLUDE_ASM("asm/nonmatchings/_5f930", func_8005F518);
