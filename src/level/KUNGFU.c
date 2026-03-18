#include "common.h"

#include "level/KUNGFU.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"


extern int D_800E5FD8;
extern int D_80154834;

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_kboat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_kboat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_kboat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_kbgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_kbgen_OnUpdate);

void kungfu_spray_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80159B1C_A8D3C);

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_801626C0_B18E0);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_spray_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_spray_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_bug_OnCollide);

void kungfu_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[0] = 0;
    instance->_4E = 0;
}

void kungfu_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    
    int a0, v0, v1;

    if (instance->_F4[0] == 0)
    {
        v1 = instance->oldPos.x;
        v0 = instance->oldPos.y;
        instance->rotation.z = func_80030538(v0 - instance->position.y, v1 - instance->position.x) - 0x400;
        func_8002DAF8(instance, -1);
    }
    else if (instance->_F4[0] == 1)
    {
        func_8002DAF8(instance, -1);
        if ((instance->flags2 & 0x10))
        {
            a0 = (*(unsigned char*)&instance->_40[7] << 2) + instance->object->animList;
            instance->_5E = ((unsigned short*)(*((int*)a0)))[1] - 1; 
            instance->_F4[0] = 2;
        }
        
    }
}

void kungfu_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int temp_a3;
    int temp_v1;
    char** temp_a2;

    temp_a2 = ((char***)instance->_70)[2];
    temp_a3 = ((short*)temp_a2)[3];
    if (temp_a3 == 1) {
        if ((temp_a2[5] == ((char*)gameTracker->_000C)) && (temp_a2[12/4][5] >= 6U)) {
            if (instance->_F4[0] == 0)
            {
                ((char*)instance->_40)[0xe] = 1;
                instance->_F4[0] = temp_a3;
                instance->_5E = 0;
                instance->flags2 &= ~0x10;
                instance->flags |= 0x100000;
            }
            else if (instance->_F4[0] == 2)
            {
                INSTANCE_PlainDeath(instance, 5, 3, 0);
            }
        } else if ((((short*)temp_a2)[3] == 1) && (temp_a2[5] == ((char**)gameTracker)[12/4]) && ((instance->_F4[0] - 1) >= 2U)) {
            func_80022714(instance);
        }
    }
}

void kungfu_launch_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_launch_OnUpdate);

void kungfu_launch_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int temp_a0;
    unsigned char** temp_a1;
    char var_a2;

    temp_a1 = (unsigned char**)instance->_70[2];
    temp_a0 = gameTracker->_000C;
    
    var_a2 = (((short*)temp_a1)[3] == 1) ? temp_a1[3][5] : -1;
    
    if (((instance->_F4[0] - 1) >= 2U) && (*(int*)&instance->_108 == 0) && (temp_a1[0x14/4] == (void*)temp_a0) && (((short*)temp_a1)[2] == 5) && (var_a2 < 8) && ((temp_a1)[2][2] == 0)) {
        if (instance->_11C & 0x10) {
            ((int*)temp_a0)[0xFC/4] |= 0x200;
            instance->_11C |= 0x20;
        }
        else if ((((func_80025798(temp_a0, temp_a1) != 0) && (instance->_11C == 0)) || (instance->_11C & 1)) && (func_8015AC6C_A9E8C(instance, gameTracker) == 0)) {
            func_8015ADC8_A9FE8(instance, gameTracker);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015AC1C_A9E3C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015AC6C_A9E8C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015AD44_A9F64);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015ADC8_A9FE8);

void func_8015AE8C_AA0AC(Instance* instance, GameTracker* gameTracker)
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

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_onoff_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_onoff_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_onoff_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_spike_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_spike_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_spike_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015B5A8_AA7C8);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragon_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_801626DC_B18FC);

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_801626E8_B1908);

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_801626EC_B190C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragon_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragflm_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragflm_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragflm_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015C884_ABAA4);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragbod_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragbod_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragon_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_cannon_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_80162700_B1920);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_cannon_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_canball_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_canball_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_canball_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_cannon_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015D5E8_AC808);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015D770_AC990);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_samuri_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015DB1C_ACD3C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015DB50_ACD70);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015DBB0_ACDD0);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015DC00_ACE20);

void func_8015DC9C_ACEBC(Instance* instance, GameTracker* gameTracker)
{
    instance->_4E = 2;
    instance->_5E = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_samuri_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_samuri_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_boat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_boat_OnUpdate);

void kungfu_boat_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void kungfu_slider_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x100400;
}

void kungfu_slider_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    if (instance->_F4[2] > 0)
    {
        instance->_F4[2]--;
    }
}

void kungfu_slider_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int* temp_s1;

    temp_s1 = (int*)PlayerInstance->data;
    if (!(PlayerInstance->_F4[2] & 1) && (instance->_F4[2] == 0)) {
        func_8015AE8C_AA0AC(instance, gameTracker);
        
        instance->_F4[2] = 0x3C;
        temp_s1[0xE0/4] = (int)instance;
        PlayerInstance->_F4[2] &= ~2;
        
        func_8002B7CC(PlayerInstance);

        if (!func_80033220(0x39)) {
            func_80050508(PlayerInstance, 0x39, (short)((rand() & 31) - 15), 0x3C, 2000);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_pend_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_pend_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_pend_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_ninja_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015F570_AE790);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015F598_AE7B8);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015F5D0_AE7F0);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015F5F4_AE814);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015F61C_AE83C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_ninja_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_ninja_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_swing_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_swing_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_swing_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_oneway_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_oneway_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_oneway_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80160D4C_AFF6C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80160E4C_B006C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80160F68_B0188);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_joyride_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8016121C_B043C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_joyride_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_joyride_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_leafgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_801616D4_B08F4);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80161944_B0B64);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_801619A4_B0BC4);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_leafgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_leafgen_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_funplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_funplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_funplat_OnCollide);

void kungfu_brkbone_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void kungfu_brkbone_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_brkbone_OnCollide);

void kungfu_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int var_s0;
    BTimerIntro* intro;

    intro = (BTimerIntro*)instance->introData;
    instance->_104 = (intro->exitTime * 30);
    instance->_F0[6] = intro->missionTime;
    *(short*)&instance->_100 = 0;
    instance->flags |= 0xC00;
    ((int*)gameTracker->_000C)[0xFC/4] |= 0x4000;
    ((int*)gameTracker->_000C)[0x10/4] |= 0x100;
    func_8002CA2C(4, intro->missionTime, intro);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    instance->_F4[1] = 0;
}

void kungfu_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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
        if (((((int*)gameTracker->_000C)[0xFC/4] & 0x600000) == 0x600000) && (instance->_F4[1] == 0)) {
            temp_s2[0] = (intro->missionTime - 1);
            if (intro->collectType == EBTIMER_COLLECTTYPE_CUTSCENE) {
                SIGNAL_HandleSignal(PlayerInstance, intro->b + 4, 0);
            }
            instance->_F4[1] = 1;
            PlayerInstance->_F4[2] &= 0xFFBFFFFF;
        }
        if ((((int*)gameTracker->_000C)[0xFC/4] & 0x400000) && ((((int**)gameTracker)[0x4C00/4] != 0) || (((int**)gameTracker)[0x4C04/4] != 0))) {
            func_8002C18C(5);
            ((int*)temp_s2)[0x8/4] = 0x3C;
            temp_s2[2] = 1;
            ((int*)gameTracker->_000C)[0x10/4] |= 0x100;
        }
        if ((((int*)temp_s2)[0x8/4] < 0) && (((int**)gameTracker)[0x4C00/4] == 0) && (((int**)gameTracker)[0x4C04/4] == 0)) {
            ((int**)gameTracker)[0x4BFC/4] = 0;
            func_8002C18C(5);
            ((int*)temp_s2)[0x8/4] = 0x3C;
            temp_s2[2] = 2;
            ((int*)gameTracker->_000C)[0x10/4] |= 0x100;
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