#include "common.h"

#include "types/Level.h"

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_kboat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_kboat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_kboat_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_kbgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_kbgen_OnUpdate);

void kungfu_spray_OnCreate(void) {
}

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_80159B1C_A8D3C);

INCLUDE_RODATA("asm/nonmatchings/kungfu_code", D_801626C0_B18E0);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_spray_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_spray_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_bug_OnDestroy);

void kungfu_crawler_OnCreate(Level_t* level)
{
    level->_F4[0] = 0;
    level->_4E = 0;
}

void kungfu_crawler_OnUpdate(Level_t* level) {
    
    int a0, v0, v1;

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

void kungfu_crawler_OnDestroy(Level_t* level, int* arg1) {
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

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_launch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_launch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_launch_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015AC1C_A9E3C);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015AC6C_A9E8C);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015AD44_A9F64);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015ADC8_A9FE8);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015AE8C_AA0AC);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_onoff_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_onoff_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_onoff_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_spike_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_spike_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_spike_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015B5A8_AA7C8);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_dragon_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/kungfu_code", D_801626DC_B18FC);

INCLUDE_RODATA("asm/nonmatchings/kungfu_code", D_801626E8_B1908);

INCLUDE_RODATA("asm/nonmatchings/kungfu_code", D_801626EC_B190C);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_dragon_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_dragflm_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_dragflm_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_dragflm_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015C884_ABAA4);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_dragbod_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_dragbod_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_dragon_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_cannon_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/kungfu_code", D_80162700_B1920);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_cannon_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_canball_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_canball_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_canball_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_cannon_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015D5E8_AC808);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015D770_AC990);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_samuri_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015DB1C_ACD3C);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015DB50_ACD70);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015DBB0_ACDD0);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015DC00_ACE20);

void func_8015DC9C_ACEBC(Level_t* level)
{
    level->_4E = 2;
    level->_50[7] = 0;
}

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_samuri_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_samuri_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_boat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_boat_OnUpdate);

void kungfu_boat_OnDestroy(void) {
}

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_slider_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_slider_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_slider_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_pend_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_pend_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_pend_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_ninja_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015F570_AE790);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015F598_AE7B8);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015F5D0_AE7F0);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015F5F4_AE814);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8015F61C_AE83C);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_ninja_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_ninja_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_swing_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_swing_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_swing_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_oneway_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_oneway_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_oneway_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_80160D4C_AFF6C);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_80160E4C_B006C);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_80160F68_B0188);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_joyride_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_8016121C_B043C);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_joyride_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_joyride_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_leafgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_801616D4_B08F4);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_80161944_B0B64);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", func_801619A4_B0BC4);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_leafgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_leafgen_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_funplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_funplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_funplat_OnDestroy);

void kungfu_brkbone_OnCreate(void) {
}

void kungfu_brkbone_OnUpdate(void) {
}

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_brkbone_OnDestroy);

void kungfu_btimer_OnCreate(Level_t* level, int* arg1) {
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

INCLUDE_ASM("asm/nonmatchings/kungfu_code", kungfu_btimer_OnUpdate);
