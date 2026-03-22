#include "common.h"

#include "level/CIRCUIT.h"
#include "types/intro/QMark.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"

#include "types/Vector.h"
extern int D_800E5FD8;
extern int D_80154834;

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_plat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_plat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_plat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bug_OnCollide);

void circuit_bouncer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    int* fc;
    
    intro = instance->introData;
    fc = &instance->_F4[2];
    
    if (intro != NULL) {
        ((short*)&instance->_100)[1] = intro[0];
        ((short*)&instance->_104)[0] = intro[1];
    } else {
        ((short*)&instance->_100)[1] = 0U;
        ((short*)&instance->_104)[0] = 0U;
    }
    fc[3] = instance->intro->position.x;
    fc[4] = instance->intro->position.y;
    ((short*)fc)[5] = 6;
    instance->intro->rotation.z = instance->intro->rotation.z & 0xFFF;
    instance->_F4[0] = 1;
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bouncer_OnUpdate);

void circuit_bouncer_OnCollide(Instance* instance, GameTracker* gameTracker) {
    unsigned char** temp_a2 = (unsigned char**)instance->_70[2];
    if ((((short*)temp_a2)[3] == 1)
        && (temp_a2[0x14/4] == (void*)gameTracker->player)
        && (temp_a2[2][4] < 2U)
        && (temp_a2[3][5] >= 6U)
        && (
            (*(short*)&instance->_104 != 3)
            || ((instance->_F4[0] - 2) < 2U)
            || (instance->_F4[0] == 4)
        )) {
            INSTANCE_PlainDeath(instance, 5, 3, 0);
    }
    else if ((((short*)temp_a2)[3] == 1)
             && (temp_a2[5] == (void*)gameTracker->player)
             && (
                 (temp_a2[2][4] == 0) || (temp_a2[2][4] == 2)
             )) {
        func_80022714(instance);
    }
}

void circuit_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[0] = 0;
    instance->_4E = 0;
}

void circuit_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int** a0;
    int v0, v1;

    instance->flags2 &= ~0x10;
    if (instance->_F4[0] == 0)
    {
        v1 = instance->oldPos.x;
        v0 = instance->oldPos.y;
        instance->rotation.z = ratan2(v0 - instance->position.y, v1 - instance->position.x) - 0x400;
        func_8002DAF8(instance, -1);
    }
    else if (instance->_F4[0] == 1)
    {
        func_8002DAF8(instance, -1);
        if ((instance->flags2 & 0x10))
        {
            instance->_5E = ((unsigned short*)(instance->object->animList[(*(unsigned char*)&instance->_40[7])]))[1] - 1; 
            instance->_F4[0] = 2;
        }
        
    }
}

void circuit_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int temp_a3;
    int temp_v1;
    char** temp_a2;

    temp_a2 = ((char***)instance->_70)[2];
    temp_a3 = ((short*)temp_a2)[3];
    if (temp_a3 == 1) {
        if ((temp_a2[5] == ((char*)gameTracker->player)) && (temp_a2[12/4][5] >= 6U)) {
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

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_charger_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_charger_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_charger_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_chrganm_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_chrganm_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015B548_82728);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015B570_82750);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ebridge_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015B780_82960);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015B7E0_829C0);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015BA9C_82C7C);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ebridge_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ebridge_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ebrijac_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ebrijac_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ebrijac_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015C18C_8336C);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbplat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbpole_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbpole_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015C9CC_83BAC);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbpole_OnCollide);

void circuit_launch_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_launch_OnUpdate);

void circuit_launch_OnCollide(Instance* instance, GameTracker* gameTracker) {
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
        else if ((((func_80025798(temp_a0, temp_a1) != 0) && (instance->_11C == 0)) || (instance->_11C & 1)) && (func_8015D354_84534(instance, gameTracker) == 0)) {
            func_8015D4B0_84690(instance, gameTracker);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015D304_844E4);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015D354_84534);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015D42C_8460C);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015D4B0_84690);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_follow_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_follow_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_follow_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015D780_84960);

void circuit_pball_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015D7F0_849D0);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_pball_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_pball_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015DB80_84D60);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ppath_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015DD58_84F38);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ppath_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ppath_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_fxgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015E084_85264);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015E140_85320);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_fxgen_OnUpdate);

void circuit_fxgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void circuit_qmark_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0;
    instance->_F4[2] = 0x40;
    instance->_100 = 0;
}

void circuit_qmark_OnUpdate(Instance* instance, GameTracker* arg1) {
    int* temp_s0;
    QMarkIntro* intro;
    
    intro = (QMarkIntro*)instance->introData;
    temp_s0 = &instance->_F4[2];
    if (((*(int*)&instance->_10C) != 0) && !(arg1->gameFlags & 0x2000)) {
        func_8003F6CC(intro->x, intro->y, intro->w, intro->h, intro->numMessages, intro->messages);
    }
    switch (temp_s0[2])
    {
        case 0: break;
        
        case 1:
        if (MATH3D_FastSqrt2(SVECTOR_DistanceSquared(&instance->position, &PlayerInstance->position), 0) > 1000
            || !temp_s0[5])
        {
            temp_s0[2] = 2;
            temp_s0[1] = -6;
        }
        else
            temp_s0[5]--;
            
        break;
        
        case 2:
        if (temp_s0[0] < 0x41) {
            temp_s0[2] = 0;
            temp_s0[0] = 0x40;
            temp_s0[1]= 0;
            temp_s0[4] = 0;
        }
            
        break;
    }
    temp_s0[0] += temp_s0[1];
    instance->rotation.z = ((instance->rotation.z + temp_s0[0]) & 0xFFF);
}

void circuit_qmark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    QMarkIntro* intro;

    intro = (QMarkIntro*)instance->introData;
    if (func_80027500(instance->_70[2]) != 0) {
        instance->_104 = 1;
        instance->_F4[2] = 0x12C;
        *((int*)&instance->_110) = intro->time;
        *((int*)&instance->_10C) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015EC00_85DE0);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_reza_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_reza_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_reza_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015F6B8_86898);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015F708_868E8);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015F720_86900);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015F75C_8693C);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015F780_86960);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_robo_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015F930_86B10);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015FA1C_86BFC);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015FAC4_86CA4);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015FC70_86E50);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_robo_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_robo_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bomb_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635A0_8A780);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635B8_8A798);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635C0_8A7A0);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635CC_8A7AC);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635D8_8A7B8);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635DC_8A7BC);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635E4_8A7C4);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635EC_8A7CC);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635F8_8A7D8);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635FC_8A7DC);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_80163604_8A7E4);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_80163610_8A7F0);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_80163618_8A7F8);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_8016361C_8A7FC);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bomb_OnUpdate);

void circuit_bomb_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_explode_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_explode_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_explode_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_pulse_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_80160D80_87F60);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_8016363C_8A81C);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_80163640_8A820);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_pulse_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_pulse_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_resist_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_801618BC_88A9C);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_resist_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_resist_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_babyres_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_babyres_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_babyres_OnCollide);

void circuit_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

void circuit_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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