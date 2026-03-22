#include "common.h"

#include "level/NYPD.h"
#include "types/intro/BTimer.h"

#include "types/G2String.h"

extern int D_800E5FD8;
extern int D_80154834;

void func_80159720_C6800(Instance* instance, GameTracker* gameTracker)
{
    if (instance->introData != 0) {
        if (((int*)instance->introData)[0] != 0) {
            if (((int*)instance->introData)[0] > 10U) {
                SIGNAL_HandleSignal(instance, ((int*)instance->introData)[0] + 4, 0);
            } else {
                SIGNAL_HandleSignal(instance, ((int*)instance->introData)[1] + 4, 0);
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

    temp_s1 = (int*)PlayerInstance->data;
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
    BTimerIntro* intro;

    intro = (BTimerIntro*)instance->introData;
    instance->_104 = (intro->exitTime * 30);
    instance->_F0[6] = intro->missionTime;
    *(short*)&instance->_100 = 0;
    instance->flags |= 0xC00;
    gameTracker->player->_F4[2] |= 0x4000;
    gameTracker->player->flags |= 0x100;
    func_8002CA2C(4, intro->missionTime, intro);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    instance->_F4[1] = 0;
}

void nypd_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    char buffer[0x50];
    int timeLeft;
    int minutesLeft;
    int secondsLeft;
    int var_v1;
    short* temp_s2;
    BTimerIntro* intro;

    var_v1 = 1;
    intro = instance->introData;
    temp_s2 = &instance->_F0[6];
    if (*(short*)&instance->_100 == 0) {
        if (temp_s2[0] != 0) {
            if ((int)(((int**)gameTracker))[0x4BFC/4] < gameTracker->level->collectibleCountA) {
                if (D_80154834 != 0) {
                    *(short*)&instance->_108 = 1;
                }
                Set3DTextPosition(0x64, 0x69);
                Print3DTextf(ANIMATED_3DTEXT("COLLECT"));
                sprintf(buffer, "%2d", gameTracker->level->collectibleCountA);
                Set3DTextPosition(0x8C, 0x91);
                Print3DTextf(buffer);
                ((int**)gameTracker)[0xC/4][0x10/4] |= 0x100;
            } else {
                func_8002C18C(4);
                Set3DTextPosition(0x50, 0x64);
                Print3DTextf(ANIMATED_3DTEXT("CATCH THE"));
                Set3DTextPosition(0x6E, 0x8C);
                Print3DTextf(ANIMATED_3DTEXT("TRAIN"));
                func_8002CA2C(5, temp_s2[0]);
            }
            var_v1 = 0;
            temp_s2[0]--;
        }
        if (temp_s2[6] != 0) {
            if (D_80154834 != 0) {
                var_v1 = 0;
            } else {
                temp_s2[6] = 0;
            }
        }
        if ((((short*)((int**)gameTracker))[0x4C12/2] == 0) && (var_v1 != 0) && (instance->intro->_2C == 0)) {
            ((int*)temp_s2)[0x8/4] -= D_800E5FD8;
        }
        if (((gameTracker->player->_F4[2] & 0x600000) == 0x600000) && (instance->_F4[1] == 0)) {
            temp_s2[0] = (intro->missionTime - 1);
            if (intro->collectType == EBTIMER_COLLECTTYPE_CUTSCENE) {
                SIGNAL_HandleSignal(PlayerInstance, intro->b + 4, 0);
            }
            instance->_F4[1] = 1;
            PlayerInstance->_F4[2] &= ~0x400000;
        }
        if ((gameTracker->player->_F4[2] & 0x400000) && ((((int**)gameTracker)[0x4C00/4] != 0) || (((int**)gameTracker)[0x4C04/4] != 0))) {
            func_8002C18C(5);
            ((int*)temp_s2)[0x8/4] = 0x3C;
            temp_s2[2] = 1;
            gameTracker->player->flags |= 0x100;
        }
        if ((((int*)temp_s2)[0x8/4] < 0) && (((int**)gameTracker)[0x4C00/4] == 0) && (((int**)gameTracker)[0x4C04/4] == 0)) {
            ((int**)gameTracker)[0x4BFC/4] = 0;
            func_8002C18C(5);
            ((int*)temp_s2)[0x8/4] = 0x3C;
            temp_s2[2] = 2;
            gameTracker->player->flags |= 0x100;
        }
        if (temp_s2[2] == 0) {
            timeLeft = ((int*)temp_s2)[0x8/4];
            minutesLeft = timeLeft / 1800;
            secondsLeft = (timeLeft % 1800) / 30;
            // Show text unless < 10s and blinking
            if ((timeLeft > 300) || ((timeLeft % 15) >= 5)) {
                Set3DTextPosition(0x2D, 0xC8);
                if ((timeLeft % 30) >= 15) {
                    sprintf(buffer, "%d", minutesLeft);
                } else {
                    sprintf(buffer, "%d.", minutesLeft);
                }
                Print3DTextf(buffer);
                Set3DTextPosition(0x53, 0xC8);
                sprintf(buffer, "%2d", secondsLeft + 100);
                Print3DTextf(&buffer[1]);
            }
            if ((temp_s2[0] == 0) && ((int)((int**)gameTracker)[0x4BFC/4] < gameTracker->level->collectibleCountA)) {
                Set3DTextPosition(0xF0, 0xC8);
                sprintf(buffer, "%2d", gameTracker->level->collectibleCountA - (int)((int**)gameTracker)[0x4BFC/4]);
                Print3DTextf(buffer);
            }
        }
    } else {
        ((int**)gameTracker)[0xC/4][0x10/4] |= 0x100;
        if (*(short*)&instance->_100 == 2) {
            // Delay map load
            if (--instance->_104 < 0) {
                func_800396E0("map", "map5", ((int**)gameTracker));
            }
            else
            {
                Set3DTextPosition(0x64, 0x64);
                Print3DTextf("TIME UP!");
            }
        }
    }
}
