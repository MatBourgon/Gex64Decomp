#include "common.h"

#include "level/SPY.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"

void spy_qsofa_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_qsofa_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_qsofa_OnCollide);

void spy_launch_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* objData;
    int* intro;

    objData = instance->object->data;
    intro = instance->introData;
    
    *(int*)&instance->_108 = 0;
    instance->initialPos.x = instance->position.x;
    instance->initialPos.y = instance->position.y;
    instance->initialPos.z = instance->position.z;
    instance->_11C = 0;
    instance->flags |= 0x800;
    *(int*)&instance->_10C = 0x500;
    *(int*)&instance->_110 = 0x80;
    instance->_120 = 0x1000;
    instance->_100 = 4;
    instance->_104 = 0x14;
    
    if (intro != NULL) {
        *(int*)&instance->_10C = intro[0];
    } else if (objData != NULL) {
        *(int*)&instance->_10C = objData[0];
        *(int*)&instance->_110 = objData[1];
        instance->_11C = *(int*)&objData[2];
        if (instance->_11C & 2) {
            instance->_118 = 0x200;
            instance->flags &= ~0x800;
        }
        if (instance->_11C & 0x10) {
            instance->_120 = objData[8];
        }
    }
    
    instance->_D0[0] = *(short*)&instance->_112;
}

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_launch_OnUpdate);

void spy_launch_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* temp_a0;
    unsigned char** temp_a1;
    char var_a2;

    temp_a1 = (unsigned char**)instance->_70[2];
    temp_a0 = gameTracker->player;
    
    var_a2 = (((short*)temp_a1)[3] == 1) ? temp_a1[3][5] : -1;
    
    if (((instance->_F4[0] - 1) >= 2U) && (*(int*)&instance->_108 == 0) && (temp_a1[0x14/4] == (void*)temp_a0) && (((short*)temp_a1)[2] == 5) && (var_a2 < 8) && ((temp_a1)[2][2] == 0)) {
        if (instance->_11C & 0x10) {
            temp_a0->_F4[2] |= 0x200;
            instance->_11C |= 0x20;
        }
        else if ((((func_80025798(temp_a0, temp_a1) != 0) && (instance->_11C == 0)) || (instance->_11C & 1)) && (func_80159F3C_EB60C(instance, gameTracker) == 0)) {
            func_8015A098_EB768(instance, gameTracker);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/SPY", func_80159EEC_EB5BC);

INCLUDE_ASM("asm/nonmatchings/level/SPY", func_80159F3C_EB60C);

INCLUDE_ASM("asm/nonmatchings/level/SPY", func_8015A014_EB6E4);

INCLUDE_ASM("asm/nonmatchings/level/SPY", func_8015A098_EB768);

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_onoff_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_onoff_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_onoff_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_gnrobot_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_gnrobot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SPY", spy_gnrobot_OnCollide);

void spy_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_RODATA("asm/nonmatchings/level/SPY", D_8015AD70_EC440);

INCLUDE_RODATA("asm/nonmatchings/level/SPY", D_8015AE00_EC4D0);

INCLUDE_RODATA("asm/nonmatchings/level/SPY", D_8015AE0C_EC4DC);

INCLUDE_RODATA("asm/nonmatchings/level/SPY", D_8015AE10_EC4E0);

extern int D_800E5FD8;
extern int D_80154834;

void spy_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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
                gameTracker->player->flags |= 0x100;
            } else {
                func_8002C18C(4);
                Set3DTextPosition(0x64, 0x64);
                Print3DTextf(ANIMATED_3DTEXT("GET THE"));
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
        gameTracker->player->flags |= 0x100;
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


