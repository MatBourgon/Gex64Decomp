#include "common.h"

#include "types/Level.h"

#include "types/GameState.h"

#include "types/Vector.h"
extern int* PlayerInstance;

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zgrate_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zgrate_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zshark_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED10_DF380);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED20_DF390);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED30_DF3A0);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED40_DF3B0);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED50_DF3C0);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED60_DF3D0);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED70_DF3E0);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED80_DF3F0);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED90_DF400);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED94_DF404);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED98_DF408);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015ED9C_DF40C);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EDA0_DF410);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EDC8_DF438);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EDD0_DF440);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EDD4_DF444);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EDF0_DF460);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE00_DF470);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE04_DF474);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE08_DF478);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE10_DF480);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE18_DF488);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE1C_DF48C);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE20_DF490);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE24_DF494);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE28_DF498);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE2C_DF49C);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE40_DF4B0);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zshark_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zshark_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015A2B0_DA920);

void rta_crawler_OnCreate(Level_t* level)
{
    level->_F4[0] = 0;
    level->_4E = 0;
}

void rta_crawler_OnUpdate(Level_t* level) {
    
    int v0, v1;

    
    v1 = level->_50[0];
    v0 = level->_50[1];
    level->_60[2] = func_80030538(v0 - level->_40[5], v1 - level->_40[4]) - 0x400;
    func_8002DAF8(level, -1);
}

void rta_crawler_OnDestroy(Level_t* level, int* arg1) {
    char** temp_a2;

    temp_a2 = (char**)level->_70[2];
    if ((temp_a2[5] == (char*)arg1[12/4]) && (((short*)temp_a2)[3] == 1)) {
        if (temp_a2[12/4][5] >= 6U) {
            func_80047904(level, 5, 3, 0);
        }
        else
        {
            func_80022714(level, arg1);
        }
    }
}


INCLUDE_ASM("asm/nonmatchings/rta_code", rta_eel_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_eel_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_eel_OnDestroy);

void rta_bug_OnCreate(void) {
}

void rta_bug_OnUpdate(void) {
}

void rta_bug_OnDestroy(void) {
}

void rta_lavadrp_OnCreate(void) {
}

void rta_lavadrp_OnUpdate(void) {
}

void rta_lavadrp_OnDestroy(void) {
}

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zturtle_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zturtle_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zturtle_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zarchsig_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_count_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_count_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zcargo_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zwleak_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zwleak_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zwleak_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015B1D4_DB844);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015B4EC_DBB5C);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zgeyser_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zgeyser_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zgeyser_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zdoor_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zdoor_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015BD04_DC374);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015BD54_DC3C4);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zswitch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zswitch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zswitch_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zswitchm_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015C344_DC9B4);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EE74_DF4E4);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zbubgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zbubgen_OnUpdate);

void rta_qmark_OnCreate(Level_t* level)
{
    level->_104 = 0;
    level->_F4[2] = 0x40;
    level->_100 = 0;
}

void rta_qmark_OnUpdate(Level_t* level, GameState* arg1) {
    int* temp_s0;
    short* temp_t0;
    volatile char _[4];
    
    temp_t0 = (short*)level->_20[1];
    temp_s0 = &level->_F4[2];
    if (((*(int*)&level->_10C) != 0) && !(arg1->gameFlags & 0x2000)) {
        func_8003F6CC(temp_t0[0], temp_t0[1], temp_t0[2], temp_t0[3], temp_t0[5], temp_t0 + 6);
    }
    switch (temp_s0[2])
    {
        case 0: break;
        
        case 1:
        if (!temp_s0[5])
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
            level->flags &= ~0x400;
        }
            
        break;
    }
    temp_s0[0] += temp_s0[1];
    level->_60[2] = ((level->_60[2] + temp_s0[0]) & 0xFFF);
}

void rta_qmark_OnDestroy(Level_t* level, int* arg1) {
    short* temp_s2;
    temp_s2 = (short*)level->_20[1];
    
    if (((int*)level->_70[2])[5] == arg1[12/4]) {
        if (level->_104 != 1) {
            func_80050508(level, 3, 0, 0x64, 0x1388);
        }
        level->_104 = 1;
        level->_F4[2] = 0x12C;
         (*(int*)&level->_110) = temp_s2[4];
        (*(int*)&level->_10C) = 1;
        level->flags |= 0x400;
    }
}

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zarrow_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zarrow_OnUpdate);

void func_8015C8C0_DCF30(void) {
}

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015C8C8_DCF38);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015CA24_DD094);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_fxgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_fxgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015CE34_DD4A4);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zstmvent_OnCreate);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zstmvent_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015D0B4_DD724);

INCLUDE_ASM("asm/nonmatchings/rta_code", rta_zstmvent_OnDestroy);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015D20C_DD87C);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015D374_DD9E4);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015D548_DDBB8);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015D74C_DDDBC);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015D9A0_DE010);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015DAF0_DE160);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015DE80_DE4F0);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015DF08_DE578);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015E038_DE6A8);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EEB8_DF528);

INCLUDE_RODATA("asm/nonmatchings/rta_code", D_8015EEBC_DF52C);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015E228_DE898);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015E27C_DE8EC);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015E3AC_DEA1C);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015E538_DEBA8);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015E5E0_DEC50);

INCLUDE_ASM("asm/nonmatchings/rta_code", func_8015E6F4_DED64);
