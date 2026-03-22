#include "common.h"

#include "types/Instance.h"
#include "types/Spline.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_800073B0);

void func_80007CBC(int* arg0) {
    if (arg0[0x4BC/4] == 0) {
        arg0[0x4BC/4] = 0xF;
        func_8004AAA8(PlayerInstance, 0x7B, 0);
    }
}

int func_80007D00(int* arg0 /*Camera?*/, int arg1, int arg2, int arg3) {
    if (!(arg0[0x240/4] & 0x80) && (arg2 != 0)) {
        return (arg1 * arg3) / arg2;
    }
    return arg3;
}

INCLUDE_RODATA("asm/nonmatchings/_7fb0", D_8007B7B0);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80007D68);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000853C);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80008580);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80009600);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_80009C24);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000A3FC);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000A5C0);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000AA60);

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000AAA0);

void func_8000AF78(int* arg0) {
    MultiSpline* multi;
    int* temp_s1;

    temp_s1 = (int*)arg0[2];
    if ((gameTracker8->levelIdToLoad != 0x19) && (temp_s1[0x438/4] != 0) && (temp_s1[0x14C/4]  == 5)) {
        if (arg0[0x40/4] & 0x20) {
            func_8004EF70(arg0);
        }
        
        if (arg0[0x40/4] & 0xF0) {
            func_8004EFD0();
            multi = (MultiSpline*)temp_s1[0x480/4]; /*camera->data.posSpline?*/
            if (multi != NULL) {
                SplineGetNextPoint(multi->positional, &multi->curPositional);
            }
            multi = (MultiSpline*)temp_s1[0x484/4]; /*camera->data.targetSpline?*/
            if (multi != NULL) {
                SplineGetNextPoint(multi->positional, &multi->curPositional);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/_7fb0", func_8000B054);
