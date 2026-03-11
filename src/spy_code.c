#include "common.h"

#include "types/Level.h"

void spy_qsofa_OnCreate(void) {
}

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_qsofa_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_qsofa_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_launch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_launch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_launch_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/spy_code", func_80159EEC_EB5BC);

INCLUDE_ASM("asm/nonmatchings/spy_code", func_80159F3C_EB60C);

INCLUDE_ASM("asm/nonmatchings/spy_code", func_8015A014_EB6E4);

INCLUDE_ASM("asm/nonmatchings/spy_code", func_8015A098_EB768);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_onoff_OnCreate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_onoff_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_onoff_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_gnrobot_OnCreate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_gnrobot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_gnrobot_OnDestroy);

void spy_btimer_OnCreate(Level_t* level, int* arg1) {
    int var_s0;
    short* temp_a2;
    int* temp_v1;
    int* temp_v1_2;

    temp_a2 = (short*)level->_20[1];
    level->_104 = (temp_a2[0] * 30);
    level->_F0[6] = (unsigned short)temp_a2[1];
    *(short*)&level->_100 = 0;
    level->flags |= 0xC00;
    temp_v1 = (int*)arg1[3];
    temp_v1[0xFC/4] |= 0x4000;
    temp_v1_2 = (int*)arg1[3];
    temp_v1_2[4] |= 0x100;
    func_8002CA2C(4, temp_a2[1], temp_a2);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    level->_F4[1] = 0;
}

INCLUDE_RODATA("asm/nonmatchings/spy_code", D_8015AD70_EC440);

INCLUDE_RODATA("asm/nonmatchings/spy_code", D_8015AE00_EC4D0);

INCLUDE_RODATA("asm/nonmatchings/spy_code", D_8015AE0C_EC4DC);

INCLUDE_RODATA("asm/nonmatchings/spy_code", D_8015AE10_EC4E0);

INCLUDE_ASM("asm/nonmatchings/spy_code", spy_btimer_OnUpdate);
