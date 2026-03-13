#include "common.h"

#include "level/CIRCUIT.h"

#include "types/Vector.h"
extern int* PlayerInstance;
extern int D_800E5FD8;
extern int D_80154834;

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_plat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_plat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_plat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bug_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bouncer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bouncer_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bouncer_OnCollide);

void circuit_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[0] = 0;
    instance->_4E = 0;
}

void circuit_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int a0, v0, v1;

    instance->flags2 &= ~0x10;
    if (instance->_F4[0] == 0)
    {
        v1 = instance->_50[0];
        v0 = instance->_50[1];
        instance->_60[2] = func_80030538(v0 - instance->_40[5], v1 - instance->_40[4]) - 0x400;
        func_8002DAF8(instance, -1);
    }
    else if (instance->_F4[0] == 1)
    {
        func_8002DAF8(instance, -1);
        if ((instance->flags2 & 0x10))
        {
            a0 = (*(unsigned char*)&instance->_40[7] << 2) + ((int*)(instance->_18 + 4))[0];
            instance->_50[7] = ((unsigned short*)(*((int*)a0)))[1] - 1; 
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
        if ((temp_a2[5] == ((char**)gameTracker)[12/4]) && (temp_a2[12/4][5] >= 6U)) {
            if (instance->_F4[0] == 0)
            {
                ((char*)instance->_40)[0xe] = 1;
                instance->_F4[0] = temp_a3;
                instance->_50[7] = 0;
                instance->flags2 &= ~0x10;
                instance->flags |= 0x100000;
            }
            else if (instance->_F4[0] == 2)
            {
                func_80047904(instance, 5, 3, 0);
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

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_launch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_launch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_launch_OnCollide);

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
    short* temp_t0;
    
    temp_t0 = (short*)instance->_20[1];
    temp_s0 = &instance->_F4[2];
    if (((*(int*)&instance->_10C) != 0) && !(arg1->gameFlags & 0x2000)) {
        func_8003F6CC(temp_t0[0], temp_t0[1], temp_t0[2], temp_t0[3], temp_t0[5], temp_t0 + 6);
    }
    switch (temp_s0[2])
    {
        case 0: break;
        
        case 1:
        if (MATH3D_FastSqrt(SVECTOR_DistanceSquared((SVECTOR*)&instance->_40[4], (SVECTOR*)&PlayerInstance[0x48/4]), 0) > 1000
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
    instance->_60[2] = ((instance->_60[2] + temp_s0[0]) & 0xFFF);
}

void circuit_qmark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    short* temp_s1;

    temp_s1 = (short*)instance->_20[1];
    if (func_80027500(instance->_70[2]) != 0) {
        instance->_104 = 1;
        instance->_F4[2] = 0x12C;
        *((int*)&instance->_110) = temp_s1[4];
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

void circuit_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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
        if ((((short*)((int**)gameTracker))[0x4C12/2] == 0) && (var_v1 != 0) && (instance->intro->_2C == 0)) {
            temp_s2[0x8/4] -= D_800E5FD8;
        }
        if (((((int**)gameTracker)[0xC/4][0xFC/4] & 0x600000) == 0x600000) && (instance->_F4[1] == 0)) {
            ((short*)temp_s2)[0] = (((unsigned short*)temp_s3)[1] - 1);
            if (temp_s3[0x4/4] == 0x3F2) {
                SIGNAL_HandleSignal(PlayerInstance, temp_s3[0x8/4] + 4, 0);
            }
            instance->_F4[1] = 1;
            PlayerInstance[0xFC/4] &= 0xFFBFFFFF;
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