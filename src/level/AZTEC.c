#include "common.h"

#include "level/AZTEC.h"
#include "types/intro/BTimer.h"

extern int D_800E5FD8;
extern int D_80154834;

const int D_8015A090_808B0[4] = { 0x02000014, 0, 0, 0 };

void aztec_funplat_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    short sp10[6];

    if (instance->introData == 0) {
        instance->introData = (void*)D_8015A090_808B0;
    }
    sp10[0] = sp10[4] = instance->position.x;
    sp10[1] = sp10[5] = instance->position.y;
    sp10[2] = instance->_E0[2] = instance->position.z;

    // Out of bounds access?
    sp10[6] = instance->_40[6] + 0x80;
    func_8000F0B0(gameTracker8->_0004[0], &sp10[0], &sp10[4], instance);
}

INCLUDE_ASM("asm/nonmatchings/level/AZTEC", aztec_funplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/AZTEC", aztec_funplat_OnCollide);

void aztec_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int var_s0;
    BTimerIntro* intro;
    int* temp_v1;
    int* temp_v1_2;

    intro = (BTimerIntro*)instance->introData;
    instance->_104 = (intro->missionTime * 30);
    instance->_F0[6] = intro->cutsceneTime;
    *(short*)&instance->_100 = 0;
    instance->flags |= 0xC00;
    temp_v1 = ((int**)gameTracker)[3];
    temp_v1[0xFC/4] |= 0x4000;
    temp_v1_2 = ((int**)gameTracker)[3];
    temp_v1_2[4] |= 0x100;
    func_8002CA2C(4, intro->cutsceneTime, intro);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    instance->_F4[1] = 0;
}

void aztec_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    char sp10[0x50];
    int temp_s0;
    int temp_s3_2;
    int temp_s6;
    int var_v1;
    int* temp_s2;
    BTimerIntro* intro;

    var_v1 = 1;
    intro = instance->introData;
    temp_s2 = &instance->_F4[2];
    if (*(short*)&instance->_100 == 0) {
        if (((short*)temp_s2)[0] != 0) {
            if ((int)(((int**)gameTracker))[0x4BFC/4] < ((int*)gameTracker->_0004)[0x34/4]) {
                if (D_80154834 != 0) {
                    *(short*)&instance->_108 = 1;
                }
                Set3DTextPosition(0x64, 0x69);
                Print3DTextf("#2COLLECT");
                sprintf(sp10, "%2d", ((int*)gameTracker->_0004)[0x34/4]);
                Set3DTextPosition(0x8C, 0x91);
                Print3DTextf(sp10);
                ((int**)gameTracker)[0xC/4][0x10/4] |= 0x100;
            } else {
                func_8002C18C(4);
                Set3DTextPosition(0x64, 0x64);
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
        if ((((short*)((int**)gameTracker))[0x4C12/2] == 0) && (var_v1 != 0) && (instance->intro->_2C == 0)) {
            temp_s2[0x8/4] -= D_800E5FD8;
        }
        if (((((int**)gameTracker)[0xC/4][0xFC/4] & 0x600000) == 0x600000) && (instance->_F4[1] == 0)) {
            ((short*)temp_s2)[0] = (intro->cutsceneTime - 1);
            if (intro->collectType == EBTIMER_COLLECTTYPE_CUTSCENE) {
                SIGNAL_HandleSignal(PlayerInstance, intro->b + 4, 0);
            }
            instance->_F4[1] = 1;
            PlayerInstance->_F4[2] &= 0xFFBFFFFF;
        }
        if ((((int**)gameTracker)[0xC/4][0xFC/4] & 0x400000) && ((((int**)gameTracker)[0x4C00/4] != 0) || (((int**)gameTracker)[0x4C04/4] != 0))) {
            func_8002C18C(5);
            temp_s2[0x8/4] = 0x3C;
            ((short*)temp_s2)[2] = 1;
            ((int**)gameTracker)[0xC/4][0x10/4] |= 0x100;
        }
        if ((temp_s2[0x8/4] < 0) && (((int**)gameTracker)[0x4C00/4] == 0) && (((int**)gameTracker)[0x4C04/4] == 0)) {
            ((int**)gameTracker)[0x4BFC/4] = 0;
            func_8002C18C(5);
            temp_s2[0x8/4] = 0x3C;
            ((short*)temp_s2)[2] = 2;
            ((int**)gameTracker)[0xC/4][0x10/4] |= 0x100;
        }
        if (((short*)temp_s2)[2] == 0) {
            temp_s0 = temp_s2[0x8/4];
            temp_s3_2 = temp_s2[0x8/4] / 1800;
            temp_s6 = (temp_s2[0x8/4] % 1800) / 30;
            if ((temp_s0 >= 0x12D) || ((temp_s2[0x8/4] % 15) >= 5)) {
                Set3DTextPosition(0x2D, 0xC8);
                if ((temp_s0 % 30) >= 0xF) {
                    sprintf(sp10, "%d", temp_s3_2);
                } else {
                    sprintf(sp10, "%d.", temp_s3_2);
                }
                Print3DTextf(sp10);
                Set3DTextPosition(0x53, 0xC8);
                sprintf(sp10, "%2d", temp_s6 + 0x64);
                Print3DTextf(&sp10[1]);
            }
            if ((((short*)temp_s2)[0] == 0) && ((int)((int**)gameTracker)[0x4BFC/4] < ((int*)gameTracker->_0004)[0x34/4])) {
                Set3DTextPosition(0xF0, 0xC8);
                sprintf(sp10, "%2d", ((int*)gameTracker->_0004)[0x34/4] - (int)((int**)gameTracker)[0x4BFC/4]);
                Print3DTextf(sp10);
            }
        }
    } else {
        ((int**)gameTracker)[0xC/4][0x10/4] |= 0x100;
        if (*(short*)&instance->_100 == 2) {
            if (--instance->_104 < 0) {
                func_800396E0("map", "map5", ((int**)gameTracker));
                return;
            }
            Set3DTextPosition(0x64, 0x64);
            Print3DTextf("TIME UP!");
        }
    }
}
