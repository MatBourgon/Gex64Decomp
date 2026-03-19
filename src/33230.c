#include "common.h"

#include <PR/os_message.h>
#include <PR/os_pi.h>

INCLUDE_ASM("asm/nonmatchings/33230", func_80032630);

INCLUDE_ASM("asm/nonmatchings/33230", func_800327C0);

INCLUDE_ASM("asm/nonmatchings/33230", func_800329A0);

INCLUDE_ASM("asm/nonmatchings/33230", func_800329DC);

INCLUDE_ASM("asm/nonmatchings/33230", func_80032B34);

INCLUDE_ASM("asm/nonmatchings/33230", func_80032BD0);

INCLUDE_ASM("asm/nonmatchings/33230", func_80032F30);

INCLUDE_ASM("asm/nonmatchings/33230", func_80032F90);

INCLUDE_ASM("asm/nonmatchings/33230", func_80032FBC);

INCLUDE_ASM("asm/nonmatchings/33230", func_800330DC);

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

INCLUDE_ASM("asm/nonmatchings/33230", func_800331BC);

INCLUDE_ASM("asm/nonmatchings/33230", func_800331DC);

INCLUDE_ASM("asm/nonmatchings/33230", func_80033200);

INCLUDE_ASM("asm/nonmatchings/33230", func_80033220);

INCLUDE_ASM("asm/nonmatchings/33230", func_80033228);

INCLUDE_ASM("asm/nonmatchings/33230", func_80033248);

INCLUDE_ASM("asm/nonmatchings/33230", func_80033268);

void func_80033270(void) {
}

void func_80033278(void) {
}

void func_80033280(void) {
}

void func_80033288(void) {
}

INCLUDE_ASM("asm/nonmatchings/33230", func_80033290);

void func_800332B4(void) {
}

INCLUDE_ASM("asm/nonmatchings/33230", func_800332BC);

void func_800332D8(void) {
}

INCLUDE_ASM("asm/nonmatchings/33230", func_800332E0);

INCLUDE_ASM("asm/nonmatchings/33230", func_80033304);

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

INCLUDE_ASM("asm/nonmatchings/33230", func_8003335C);

INCLUDE_ASM("asm/nonmatchings/33230", func_800333E0);
