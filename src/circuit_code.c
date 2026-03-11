#include "common.h"

#include "types/Level.h"

#include "types/Vector.h"
extern int* D_8006CFA0;

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_plat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_plat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_plat_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bug_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bouncer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bouncer_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bouncer_OnDestroy);

void circuit_crawler_OnCreate(Level_t* level)
{
    level->_F4[0] = 0;
    level->_4E = 0;
}

void circuit_crawler_OnUpdate(Level_t* level) {
    int a0, v0, v1;

    level->_14 &= ~0x10;
    if (level->_F4[0] == 0)
    {
        v1 = level->_50[0];
        v0 = level->_50[1];
        level->_60[2] = func_80030538(v0 - level->_40[5], v1 - level->_40[4]) - 0x400;
        func_8002DAF8(level, -1);
    }
    else if (level->_F4[0] == 1)
    {
        func_8002DAF8(level, -1);
        if ((level->_14 & 0x10))
        {
            a0 = (*(unsigned char*)&level->_40[7] << 2) + ((int*)(level->_18 + 4))[0];
            level->_50[7] = ((unsigned short*)(*((int*)a0)))[1] - 1; 
            level->_F4[0] = 2;
        }
        
    }
}

void circuit_crawler_OnDestroy(Level_t* level, int* arg1) {
    int temp_a3;
    int temp_v1;
    char** temp_a2;

    temp_a2 = ((char***)level->_70)[2];
    temp_a3 = ((short*)temp_a2)[3];
    if (temp_a3 == 1) {
        if ((temp_a2[5] == (char*)arg1[12/4]) && (temp_a2[12/4][5] >= 6U)) {
            if (level->_F4[0] == 0)
            {
                ((char*)level->_40)[0xe] = 1;
                level->_F4[0] = temp_a3;
                level->_50[7] = 0;
                level->_14 &= ~0x10;
                level->flags |= 0x100000;
            }
            else if (level->_F4[0] == 2)
            {
                func_80047904(level, 5, 3, 0);
            }
        } else if ((((short*)temp_a2)[3] == 1) && (temp_a2[5] == (char*)arg1[12/4]) && ((level->_F4[0] - 1) >= 2U)) {
            func_80022714(level);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_charger_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_charger_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_charger_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_chrganm_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_chrganm_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015B548_82728);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015B570_82750);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebridge_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015B780_82960);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015B7E0_829C0);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015BA9C_82C7C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebridge_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebridge_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebrijac_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebrijac_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ebrijac_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015C18C_8336C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbplat_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbpole_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbpole_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015C9CC_83BAC);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_orbpole_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_launch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_launch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_launch_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D304_844E4);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D354_84534);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D42C_8460C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D4B0_84690);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_follow_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_follow_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_follow_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D780_84960);

void circuit_pball_OnCreate(Level_t* level)
{
    level->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015D7F0_849D0);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pball_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pball_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015DB80_84D60);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ppath_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015DD58_84F38);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ppath_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_ppath_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_fxgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015E084_85264);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015E140_85320);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_fxgen_OnUpdate);

void circuit_fxgen_OnDestroy(void) {
}

void circuit_qmark_OnCreate(Level_t* level)
{
    level->_104 = 0;
    level->_F4[2] = 0x40;
    level->_100 = 0;
}

void circuit_qmark_OnUpdate(Level_t* level, int* arg1) {
    int* temp_s0;
    short* temp_t0;
    
    temp_t0 = (short*)level->_20[1];
    temp_s0 = &level->_F4[2];
    if (((*(int*)&level->_10C) != 0) && !(arg1[0x4C08/4] & 0x2000)) {
        func_8003F6CC(temp_t0[0], temp_t0[1], temp_t0[2], temp_t0[3], temp_t0[5], temp_t0 + 6);
    }
    switch (temp_s0[2])
    {
        case 0: break;
        
        case 1:
        if (func_80030840(SVECTOR_DistanceSquared((SVECTOR*)&level->_40[4], (SVECTOR*)&D_8006CFA0[0x48/4]), 0) > 1000
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
    level->_60[2] = ((level->_60[2] + temp_s0[0]) & 0xFFF);
}

void circuit_qmark_OnDestroy(Level_t* level) {
    short* temp_s1;

    temp_s1 = (short*)level->_20[1];
    if (func_80027500(level->_70[2]) != 0) {
        level->_104 = 1;
        level->_F4[2] = 0x12C;
        *((int*)&level->_110) = temp_s1[4];
        *((int*)&level->_10C) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015EC00_85DE0);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_reza_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_reza_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_reza_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F6B8_86898);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F708_868E8);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F720_86900);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F75C_8693C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F780_86960);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_robo_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015F930_86B10);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015FA1C_86BFC);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015FAC4_86CA4);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_8015FC70_86E50);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_robo_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_robo_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bomb_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635A0_8A780);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635B8_8A798);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635C0_8A7A0);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635CC_8A7AC);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635D8_8A7B8);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635DC_8A7BC);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635E4_8A7C4);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635EC_8A7CC);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635F8_8A7D8);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_801635FC_8A7DC);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_80163604_8A7E4);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_80163610_8A7F0);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_80163618_8A7F8);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_8016361C_8A7FC);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_bomb_OnUpdate);

void circuit_bomb_OnDestroy(void) {
}

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_explode_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_explode_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_explode_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pulse_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_80160D80_87F60);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_8016363C_8A81C);

INCLUDE_RODATA("asm/nonmatchings/circuit_code", D_80163640_8A820);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pulse_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_pulse_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_resist_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", func_801618BC_88A9C);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_resist_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_resist_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_babyres_OnCreate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_babyres_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_babyres_OnDestroy);

void circuit_btimer_OnCreate(Level_t* level, int* arg1) {
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

INCLUDE_ASM("asm/nonmatchings/circuit_code", circuit_btimer_OnUpdate);
