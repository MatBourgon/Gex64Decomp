#include "common.h"

#include "level/GEXZIL.h"

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bug_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80159B8C_92D0C);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80159DEC_92F6C);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162A90_9BC10);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162AA0_9BC20);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015A09C_9321C);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_ebolt_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_ebolt_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bldg_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bldg_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bldg_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015A7F0_93970);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015AC68_93DE8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015AE68_93FE8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015B144_942C4);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015B220_943A0);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015B334_944B4);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mechjet_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mechjet_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015B460_945E0);

void gexzil_mechjet_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mecha_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015B964_94AE4);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162AB8_9BC38);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162ABC_9BC3C);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162AC4_9BC44);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162AD0_9BC50);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mecha_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015C188_95308);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015C208_95388);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mekblst_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mekblst_OnUpdate);

void func_8015C484_95604(Instance* instance, short* arg1, int* arg2) {
    extern int D_80154834;
    if (instance->flags2 & 0x10) {
        if (arg1[0x4E/2] <= 0 && D_80154834 == 0 && arg2[0x4C48/4] == 0) {
            func_8015EAB8_97C38(instance, arg1);
        } else {
            instance->flags2 &= ~0x10;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015C504_95684);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015C704_95884);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015CADC_95C5C);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015CB68_95CE8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015CE34_95FB4);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015D1D0_96350);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015D3C8_96548);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015D64C_967CC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015D998_96B18);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015DB38_96CB8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015DD28_96EA8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015E084_97204);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015E390_97510);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B0C_9BC8C);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B18_9BC98);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B1C_9BC9C);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B24_9BCA4);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B28_9BCA8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015E8C0_97A40);

void func_8015EA18_97B98(Instance* instance, short* arg1) {
    instance->flags2 &= ~0x10;
    func_8015C188_95308(instance, arg1);
    arg1[0x26/2] = 6;
    ((int*)arg1)[0x18/4] &= ~4;
}

void func_8015EA68_97BE8(Instance* instance, short* arg1) {
    void* data;

    data = (void*)((int*)instance->intro)[8];
    arg1[0x26/2] = 9;
    instance->currentModelAnim = 2;
    instance->currentAnimFrame = 0;
    arg1[0x14/2] = 0;
    instance->flags2 &= ~0x10;
    arg1[0x12/2] = 0;
    instance->currentAnimFrame = 0x39;
    arg1[0x3C/2] = ((unsigned short*)data)[0x92/2];
}

void func_8015EAB8_97C38(Instance* instance, int* arg1) {
    arg1[0x54/4] = 1;
    ((short*)arg1)[0x26/2] = 0x15;
    func_8015C188_95308(instance, arg1);
    instance->flags2 &= ~0x10;
}

void func_8015EAFC_97C7C(Instance* instance, short* arg1) {
    arg1[0x26/2] = 0x14;
    func_8015C188_95308(instance, arg1);
    instance->flags2 &= ~0x10;
}

void func_8015EB38_97CB8(Instance* instance, void* arg1) {
    ((int*)arg1)[0x54/4] = 0;
    ((short*)arg1)[0x26/2] = 0xA;
    instance->currentModelAnim = 0;
    instance->currentAnimFrame = 0;
    ((short*)arg1)[0x14/2] = 0;
    instance->flags2 &= ~0x10;
    ((short*)arg1)[0x12/2] = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015EB68_97CE8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015EC5C_97DDC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F11C_9829C);

void func_8015F558_986D8(Instance* instance, void* arg1) {
    ((short*)arg1)[0x26/2] = 3;
    instance->currentModelAnim = 6;
    instance->currentAnimFrame = 0;
    ((short*)arg1)[0x14/2] = 0;
    instance->flags2 &= ~0x10;
    ((short*)arg1)[0x12/2] = 0;
}

void func_8015F588_98708(Instance* instance, short* arg1) {
    arg1[0x26/2] = 1;
    if (instance->currentModelAnim != 6) {
        instance->currentModelAnim = 6;
        instance->currentAnimFrame = 0;
        arg1[0x14/2] = 0;
        instance->flags2 &= ~0x10;
        arg1[0x12/2] = 0;
    }
    instance->flags2 &= ~0x10;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F5D4_98754);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F680_98800);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F708_98888);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F7B4_98934);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F93C_98ABC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015FA98_98C18);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015FD80_98F00);

void func_8015FF70_990F0(Instance* instance, short* arg1)
{
    arg1[0x28/2] = 0;
    arg1[0x26/2] = 0x23;
}

void func_8015FF80_99100(Instance* instance, short* arg1) {
    void* data;

    data = (void*)((int*)instance->intro)[8];
    if (arg1[0x26/2] != 0x28) {
        arg1[0x26/2] = 0x28;
        instance->currentModelAnim = 7;
        instance->currentAnimFrame = 0;
        arg1[0x14/2] = 0;
        instance->flags2 &= ~0x10;
        arg1[0x12/2] = 0;
        arg1[0x4C/2] = ((unsigned short*)data)[5];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015FFDC_9915C);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8016014C_992CC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_801601D8_99358);

void func_80160344_994C4(void) {
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8016034C_994CC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mecha_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80160B70_99CF0);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80160BD8_99D58);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80160C28_99DA8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80160DF8_99F78);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_801614B0_9A630);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161538_9A6B8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_801615A8_9A728);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161624_9A7A4);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161938_9AAB8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161A18_9AB98);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161B4C_9ACCC);

void func_80161EC4_9B044(int arg0, int arg1) {
    func_80161B4C_9ACCC(arg0, arg1 + 8);
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161EE4_9B064);

void func_80161FF8_9B178(int arg0) {
    func_80161624_9A7A4(arg0);
    func_80161EE4_9B064(arg0);
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80162024_9B1A4);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8016218C_9B30C);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_gas_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B3C_9BCBC);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B48_9BCC8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_gas_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_gas_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_explode_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_explode_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_explode_OnCollide);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B70_9BCF0);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B74_9BCF4);
