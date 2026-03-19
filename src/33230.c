#include "common.h"

#include <PR/os_message.h>
#include <PR/os_pi.h>

INCLUDE_ASM("asm/nonmatchings/33230", func_80032630);

INCLUDE_ASM("asm/nonmatchings/33230", func_800327C0);

void func_800329A0(int arg0, int arg1) {
    MusSetMasterVolume(1, arg0);
    MusSetMasterVolume(2, arg1);
}

INCLUDE_ASM("asm/nonmatchings/33230", func_800329DC);

extern u8 D_8006FCD0;
extern int D_800B83B8;
extern int D_800BF2D4;
extern int D_800E97D0;
extern int D_800EB880[];
extern int D_8015482C;
extern int D_80156B10;

void func_80032B34(int arg0, int arg1, int arg2, int arg3, int arg4) {
    if ((D_8006FCD0 == 0) && (D_800EB880[arg1] == 0) && ((arg1 != D_8015482C) || (D_800B83B8 != 3))) {
        if (arg0 == -1) {
            D_80156B10 = D_8015482C;
        } else {
            D_80156B10 = arg0;
        }
        D_8015482C = arg1;
        D_800E97D0 = arg2;
        D_800BF2D4 = arg4;
        D_800B83B8 = 3;
    }
}

INCLUDE_ASM("asm/nonmatchings/33230", func_80032BD0);

extern int D_800BF1B0;
extern int D_800E9734;
extern int D_80154714;
extern unsigned int* D_80156B14;

void func_800331DC();

void func_80032F30(void) {
    D_80154714 = 0;
    D_800BF1B0 = 1;
    D_800E9734 = D_80156B14[1] / 10;
    func_800331DC();
    func_80050980(0x82);
}

void func_80032F90(void) {
    D_800BF1B0 = 2;
    func_80050980(0x82);
}

INCLUDE_ASM("asm/nonmatchings/33230", func_80032FBC);

extern int D_800BDF08[];

void func_800330DC(int i, void* arg2) {
    func_8005409C(D_800BDF08[i], arg2);
}

extern OSMesgQueue D_800E5FE8;

void func_8003310C(int arg0, void* arg1, int arg2) {
    OSIoMesg sp20;
    OSMesg msg;
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
        osRecvMesg(&D_800E5FE8, &msg, 1);
        var_s3 += var_s0;
        var_s1 -= var_s0;
        var_s2 += var_s0;
    }
}

void func_800331BC(void* arg0)
{
    func_8005409C(arg0, 0);
}

void func_800331DC()
{
    func_80053FA0(1, 0);
}

void func_80033200(void* arg)
{
    func_8005410C(arg);
}

int func_80033220()
{
    return 0;
}

void func_80033228(void) {
    func_80054164();
}

void func_80033248(void* arg)
{
    func_8005410C(arg);
}

int func_80033268()
{
    return 0;
}

void func_80033270(void) {
}

void func_80033278(void) {
}

void func_80033280(void) {
}

void func_80033288(void) {
}

void func_80033290()
{
    func_80053FA0(2, 0);
}

void func_800332B4(void) {
}

extern short D_80154698[];

short func_800332BC(int arg0) {
    return D_80154698[(short)arg0];
}

void func_800332D8(void) {
}

void func_800332E0()
{
    func_800329A0(0, 0);
}

extern unsigned int* D_80156B14;

void func_80033304()
{
    func_800329A0(D_80156B14[2], D_80156B14[1]);
}

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

extern int D_8006FA0C[];
extern int D_8006FA10[];
extern int D_8006FA14[];
extern int D_800BDF00;
extern short D_800E5CDC;
extern char D_800E81D0[];

int func_8003335C(int arg0) {
    int temp_a0;

    if (arg0 >= 5) return 0;
    arg0--;
    
    temp_a0 = D_8006FA0C[arg0 * 3];
    D_800E5CDC = D_8006FA14[arg0 * 3];
    func_8003310C(temp_a0, D_800E81D0, D_8006FA10[arg0 * 3] - temp_a0);
    D_800BDF00 = 2;
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/33230", func_800333E0);
