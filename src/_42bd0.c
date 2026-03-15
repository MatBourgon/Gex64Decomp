#include "common.h"
#include "types/GameTracker.h"
#include "types/G2String.h"

#include "types/Instance.h"

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

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_icecube_OnCollide);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800444B8);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnCollide);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80044B2C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powertv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powertv_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powertv_OnCollide);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80045320);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800454E4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnCollide);

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

extern void func_80047438(Instance*, GameTracker*);
extern void func_80047724();

void func_80047768(Instance* instance, int arg1, int arg2, int arg3) {
    Object* temp_a1 = instance->object;
    int var_a2 = 0;

    
    if ((temp_a1->oflags2 & 0x400)) 
    {
        var_a2 |= 0x40;
        var_a2 |= 0x8;
        var_a2 |= 0x1;
    }
    
    if (temp_a1->oflags2 & 0x20000) {
        var_a2 |= 0xC1;
    }

    if (temp_a1->oflags2 & 0x1000) {
        var_a2 |= 0x14;
    }

    if (temp_a1->oflags2 & 0x800) {
        var_a2 |= 3;
    }

    if (temp_a1->oflags2 & 0x2000) {
        var_a2 |= 0x21;
    }

    if (var_a2 == 0) {
        if (instance->flags2 & 1) {
            var_a2 = 3;
        }

        if (instance->flags2 & 2) {
            var_a2 |= 0x10;
            var_a2 |= ((temp_a1->oflags2 & 0x10000) ? 0x48 : 4);
        }

        if (instance->flags2 & 0x01000000) {
            var_a2 |= 0x49;
        }
    }

    if (instance->flags2 & 0x01000000) {
        var_a2 |= 0x100;
    }
    
    if (temp_a1->oflags2 & 0x4000) {
        var_a2 &= 0x11;
        if (var_a2 == 0) {
            var_a2 = 1;
        }
        var_a2 |= 0x40;
    } else if (temp_a1->oflags2 & 0x8000) {
        var_a2 &= ~0x1;
        var_a2 &= ~0x10;
    }
    if (var_a2 != 0) {
        func_80046D04(instance, func_80047438, var_a2, arg1, arg2);
        func_80047438(instance, gameTracker8);
    }
    else if (arg3 != 0) {
        func_80046D04(instance, func_80047724, 0, arg1, arg2);
    }
    else
        func_800473A4(instance, arg1, arg2);
}

void INSTANCE_PlainDeath(Instance* instance, int arg1, int arg2, int arg3) {
    Object* object;

    object = instance->object;
    func_80046CB0(instance);

    if (object->oflags2 & 0x100)
    {
        func_800473A4(instance, arg1, arg2);
    }
    else if (object->oflags2 & 0x200)
    {
        func_80046AA0(instance, arg2);
        func_80046CE4(instance);
    }
    else
    {
        func_80047768(instance, arg1, arg2, 1);
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
        temp_v0 = ((G2String******)gameTracker8)[3][8][0x4C];
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

MultiSpline* SCRIPT_GetMultiSpline(Instance *instance, unsigned long *isParent, unsigned long *isClass)
{
    MultiSpline *multi;

    multi = NULL;

    if (isParent != NULL)
    {
        *isParent = 0;
    }

    if (isClass != NULL)
    {
        *isClass = 0;
    }

    if ((instance != NULL) && (instance->intro != NULL) && (instance->intro->multiSpline != NULL))
    {
        multi = instance->intro->multiSpline;

        if (((instance->flags & 0x100002) == 0x2) && (isParent != NULL))
        {
            *isParent = 1;
        }
    }

    if ((multi == NULL) && (instance->object->modelList[0] != NULL))
    {
        multi = instance->object->modelList[0]->multiSpline;

        if (isClass != NULL)
        {
            *isClass = 1;
        }
    }

    return multi;
}

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
