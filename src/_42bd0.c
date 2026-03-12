#include "common.h"
#include "types/GameState.h"
#include "types/G2String.h"

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80041FD0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042120);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042184);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042330);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042674);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042A4C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042CC0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800434BC);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80043708);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_fpower_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80043958);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_colfire_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_ice_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_icecube_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_icecube_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800444B8);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80044B2C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powertv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powertv_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powertv_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80045320);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800454E4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800462C0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046660);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046730);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_8004675C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046924);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046978);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800469A0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046A18);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046AA0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046C48);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046CB0);

void func_80046CE4()
{
    func_8002E350();
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046D04);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046DA4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046DDC);

void func_80046E70(short* arg0, int arg1)
{
    arg0[0x64/2] = (arg0[0x64/2] + arg1) & 0xFFF;
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046E88);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046F20);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047058);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047240);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800472A4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800472F0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047344);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800473A4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047438);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047724);

extern void func_80047438(int*, GameState*);
extern void func_80047724();

void func_80047768(int* arg0, int arg1, int arg2, int arg3) {
    int temp_a0;
    int* temp_a1;
    int var_a2 = 0;

    temp_a1 = ((int*)arg0[0x18/4]);
    temp_a0 = temp_a1[0x30/4];
    
    if ((temp_a0 & 0x400)) 
    {
        var_a2 |= 0x40;
        var_a2 |= 0x8;
        var_a2 |= 0x1;
    }
    
    if (temp_a0 & 0x20000) {
        var_a2 |= 0xC1;
    }
    if (temp_a0 & 0x1000) {
        var_a2 |= 0x14;
    }
    if (temp_a0 & 0x800) {
        var_a2 |= 3;
    }
    if (temp_a0 & 0x2000) {
        var_a2 |= 0x21;
    }
    if (var_a2 == 0) {
        if (arg0[0x14/4] & 1) {
            var_a2 = 3;
        }
        if (arg0[0x14/4] & 2) {
            var_a2 |= 0x10;
            if (temp_a0 & 0x10000) {
                var_a2 |= 0x48;
            } else {
                var_a2 |= 4;
            }
        }
        if (arg0[0x14/4] & 0x01000000) {
            var_a2 |= 0x49;
        }
    }
    if (arg0[0x14/4] & 0x01000000) {
        var_a2 |= 0x100;
    }
    
    if (temp_a1[0x30/4] & 0x4000) {
        var_a2 &= 0x11;
        if (var_a2 == 0) {
            var_a2 = 1;
        }
        var_a2 |= 0x40;
    } else if (temp_a1[0x30/4] & 0x8000) {
        var_a2 &= ~0x1;
        var_a2 &= ~0x10;
    }
    if (var_a2 != 0) {
        func_80046D04(arg0, func_80047438, var_a2, arg1, arg2);
        func_80047438(arg0, gpGameState8);
    }
    else if (arg3 != 0) {
        func_80046D04(arg0, func_80047724, 0, arg1, arg2);
    }
    else
        func_800473A4(arg0, arg1, arg2);
}

void func_80047904(int** arg0, int arg1, int arg2) {
    int* iVar1;

    iVar1 = arg0[6];
    func_80046CB0();

    if (iVar1[12] & 0x100)
    {
        func_800473A4(arg0, arg1, arg2);
    }
    else if (iVar1[12] & 0x200)
    {
        func_80046AA0(arg0, arg2);
        func_80046CE4(arg0);
    }
    else
    {
        func_80047768((int*)arg0, arg1, arg2, 1);
    }
    
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800479AC);

int func_80047D10(short* arg0)
{
    return arg0[3] & 0x69;
}

extern int D_800785CC[];
extern char D_8007E720[8]; // "fpower__"

void func_80047D20(int arg0, int arg1) {
    int result;
    G2String*** temp_v0;

    result = D_800785CC[arg0];
    if (arg1 == 0) {
        temp_v0 = ((G2String******)gpGameState8)[3][8][0x4C];
        result = 0;
        if (temp_v0 != NULL) {
            result = G2String_Compare_EQ(temp_v0[6][8], D_8007E720);
        }
    }
    D_800785CC[arg0] = result;
}

int func_80047DB4()
{
    func_8004A820();
    return 1;
}

int func_80047DD4()
{
    func_8004A7B8();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047DF4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047E64);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047F5C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800480AC);

INCLUDE_ASM("asm/nonmatchings/_42bd0", SCRIPT_InstanceSplineInit);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048304);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048454);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_8004848C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800484C4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048524);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800485D4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800485F8);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_8004861C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048640);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048828);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048A4C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048CC8);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048DE4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048E7C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049224);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049250);

void func_80049330(short* arg0)
{
    arg0[0xC0 / 2] = arg0[0x4C / 2];
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049340);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800494C8);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049684);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049810);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049A58);
