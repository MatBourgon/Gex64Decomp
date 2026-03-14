#include "common.h"

#include "level/NYPD.h"

extern int D_800E5FD8;
extern int D_80154834;

void func_80159720_C6800(Instance* instance, GameTracker* gameTracker)
{
    if (instance->_20[1] != 0) {
        if (((int**)instance->_20)[1][0] != 0) {
            if (((int**)instance->_20)[1][0] > 10U) {
                SIGNAL_HandleSignal(instance, ((int**)instance->_20)[1][0] + 4, 0);
            } else {
                SIGNAL_HandleSignal(instance, ((int**)instance->_20)[1][1] + 4, 0);
            }
        }
    }
}

void nypd_slider_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x100400;
}

void nypd_slider_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    if (instance->_F4[2] > 0)
    {
        instance->_F4[2]--;
    }
}

void nypd_slider_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int* temp_s1;

    temp_s1 = (int*)PlayerInstance->_20[0];
    if (!(PlayerInstance->_F4[2] & 1) && (instance->_F4[2] == 0)) {
        func_80159720_C6800(instance, gameTracker);
        
        instance->_F4[2] = 0x3C;
        temp_s1[0xE0/4] = (int)instance;
        PlayerInstance->_F4[2] &= ~2;
        
        func_8002B7CC(PlayerInstance);

        if (!func_80033220(0x39)) {
            func_80050508(PlayerInstance, 0x39, (short)((rand() & 31) - 15), 0x3C, 2000);
        }
    }
}

void nypd_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int var_s0;
    short* temp_a2;
    int* temp_v1;
    int* temp_v1_2;

    temp_a2 = (short*)instance->_20[1];
    instance->_104 = (temp_a2[0] * 30);
    instance->_F0[6] = (unsigned short)temp_a2[1];
    *(short*)&instance->_100 = 0;
    instance->flags |= 0xC00;
    temp_v1 = ((int**)gameTracker)[3];
    temp_v1[0xFC/4] |= 0x4000;
    temp_v1_2 = ((int**)gameTracker)[3];
    temp_v1_2[4] |= 0x100;
    func_8002CA2C(4, temp_a2[1], temp_a2);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    instance->_F4[1] = 0;
}

void nypd_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    char sp10[0x50];
    int temp_s0;
    int temp_s3_2;
    int temp_s6;
    int var_v1;
    int* temp_s2;
    int* temp_s3;

    var_v1 = 1;
    temp_s3 = (int*)instance->_20[1];
    temp_s2 = &instance->_F4[2];
    if (*(short*)&instance->_100 == 0) {
        if (((short*)temp_s2)[0] != 0) {
            if ((int)(((int**)gameTracker))[0x4BFC/4] < ((int**)gameTracker)[0x4/4][0x34/4]) {
                if (D_80154834 != 0) {
                    *(short*)&instance->_108 = 1;
                }
                func_80037B00(0x64, 0x69);
                Print3DTextf("#2COLLECT");
                sprintf(sp10, "%2d", ((int**)gameTracker)[0x4/4][0x34/4]);
                func_80037B00(0x8C, 0x91);
                Print3DTextf(sp10);
                ((int**)gameTracker)[0xC/4][0x10/4] |= 0x100;
            } else {
                func_8002C18C(4);
                func_80037B00(0x50, 0x64);
                Print3DTextf("#2CATCH THE");
                func_80037B00(0x6E, 0x8C);
                Print3DTextf("#2TRAIN");
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
            ((short*)temp_s2)[0] = (((unsigned short*)temp_s3)[1] - 1);
            if (temp_s3[0x4/4] == 0x3F2) {
                SIGNAL_HandleSignal(PlayerInstance, temp_s3[0x8/4] + 4, 0);
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
            if ((((short*)temp_s2)[0] == 0) && ((int)((int**)gameTracker)[0x4BFC/4] < ((int**)gameTracker)[0x4/4][0x34/4])) {
                func_80037B00(0xF0, 0xC8);
                sprintf(sp10, "%2d", ((int**)gameTracker)[0x4/4][0x34/4] - (int)((int**)gameTracker)[0x4BFC/4]);
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
            func_80037B00(0x64, 0x64);
            Print3DTextf("TIME UP!");
        }
    }
}
