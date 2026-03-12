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

extern int* PlayerInstance;
extern int D_800E5FD8;
extern int D_80154834;

void spy_btimer_OnUpdate(Level_t* arg0, int** arg1) {
    char sp10[0x50];
    int temp_s0;
    int temp_s3_2;
    int temp_s6;
    int var_v1;
    int* temp_s2;
    int* temp_s3;

    var_v1 = 1;
    temp_s3 = (int*)arg0->_20[1];
    temp_s2 = &arg0->_F4[2];
    if (*(short*)&arg0->_100 == 0) {
        if (((short*)temp_s2)[0] != 0) {
            if ((int)arg1[0x4BFC/4] < arg1[0x4/4][0x34/4]) {
                if (D_80154834 != 0) {
                    *(short*)&arg0->_108 = 1;
                }
                func_80037B00(0x64, 0x69);
                Print3DTextf("#2COLLECT");
                sprintf(sp10, "%2d", arg1[0x4/4][0x34/4]);
                func_80037B00(0x8C, 0x91);
                Print3DTextf(sp10);
                arg1[0xC/4][0x10/4] |= 0x100;
            } else {
                func_8002C18C(4);
                func_80037B00(0x64, 0x64);
                Print3DTextf("#2GET THE");
                func_8002CA2C(5, ((short*)temp_s2)[0]);
            }
            var_v1 = 0;
            ((short*)temp_s2)[0]--;
        }
        if (((short*)temp_s2)[0xC/2] != 0) {
            if (D_80154834 != 0) {
                var_v1 = 0;
            } else {
                ((short*)temp_s2)[0xC/2] = 0;
            }
        }
        if ((((short*)arg1)[0x4C12/2] == 0) && (var_v1 != 0) && (arg0->_1C[0x2C/4] == 0)) {
            temp_s2[0x8/4] -= D_800E5FD8;
        }
        if (((arg1[0xC/4][0xFC/4] & 0x600000) == 0x600000) && (arg0->_F4[1] == 0)) {
            ((short*)temp_s2)[0] = (((unsigned short*)temp_s3)[1] - 1);
            if (temp_s3[0x4/4] == 0x3F2) {
                SIGNAL_HandleSignal(PlayerInstance, temp_s3[0x8/4] + 4, 0);
            }
            arg0->_F4[1] = 1;
            PlayerInstance[0xFC/4] &= 0xFFBFFFFF;
        }
        if ((arg1[0xC/4][0xFC/4] & 0x400000) && ((arg1[0x4C00/4] != 0) || (arg1[0x4C04/4] != 0))) {
            func_8002C18C(5);
            temp_s2[0x8/4] = 0x3C;
            ((short*)temp_s2)[2] = 1;
            arg1[0xC/4][0x10/4] |= 0x100;
        }
        if ((temp_s2[0x8/4] < 0) && (arg1[0x4C00/4] == 0) && (arg1[0x4C04/4] == 0)) {
            arg1[0x4BFC/4] = 0;
            func_8002C18C(5);
            temp_s2[0x8/4] = 0x3C;
            ((short*)temp_s2)[2] = 2;
            arg1[0xC/4][0x10/4] |= 0x100;
        }
        if (((short*)temp_s2)[2] == 0) {
            temp_s0 = temp_s2[0x8/4];
            temp_s3_2 = temp_s2[0x8/4] / 1800;
            temp_s6 = (temp_s2[0x8/4] % 1800) / 30;
            if ((temp_s0 >= 0x12D) || ((temp_s2[0x8/4] % 15) >= 5)) {
                func_80037B00(0x2D, 0xC8);
                if ((temp_s0 % 30) >= 0xF) {
                    sprintf(sp10, "%d", temp_s3_2);
                } else {
                    sprintf(sp10, "%d.", temp_s3_2);
                }
                Print3DTextf(sp10);
                func_80037B00(0x53, 0xC8);
                sprintf(sp10, "%2d", temp_s6 + 0x64);
                Print3DTextf(&sp10[1]);
            }
            if ((((short*)temp_s2)[0] == 0) && ((int)arg1[0x4BFC/4] < arg1[0x4/4][0x34/4])) {
                func_80037B00(0xF0, 0xC8);
                sprintf(sp10, "%2d", arg1[0x4/4][0x34/4] - (int)arg1[0x4BFC/4]);
                Print3DTextf(sp10);
            }
        }
    } else {
        arg1[0xC/4][0x10/4] |= 0x100;
        if (*(short*)&arg0->_100 == 2) {
            if (--arg0->_104 < 0) {
                func_800396E0("map", "map5", arg1);
                return;
            }
            func_80037B00(0x64, 0x64);
            Print3DTextf("TIME UP!");
        }
    }
}

