#include "common.h"

#include "level/REZOP.h"
#include "types/intro/BTimer.h"

extern int D_800E5FD8;
extern int D_80154834;

void rezop_rrdoor_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrdoor_OnUpdate);

void rezop_rrdoor_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrspark_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrspark_OnUpdate);

void rezop_rrspark_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezrat_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161530_D9CA0);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161558_D9CC8);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezrat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezrat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrgen_OnUpdate);

void rezop_rrgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrzap_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrzap_OnUpdate);

void rezop_rrzap_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnCollide);

void rezop_tbbttn_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbbttn_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbbttn_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbplat_OnUpdate);

void rezop_tbplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezfan_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezfan_OnUpdate);

void rezop_rezfan_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simontv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simontv_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simontv_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simon_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015B750_D3EC0);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015B9AC_D411C);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015BA40_D41B0);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simon_OnUpdate);

void rezop_simon_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_crnkplt_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_crnkplt_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_crnkplt_OnCollide);

void rezop_rezcrnk_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezcrnk_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezcrnk_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_snkplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_snkplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_snkplat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_srchlit_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_srchlit_OnUpdate);

void rezop_srchlit_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spotlit_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spotlit_OnUpdate);

void rezop_spotlit_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mutant_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015E950_D70C0);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015EAB0_D7220);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015ECB8_D7428);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161590_D9D00);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mutant_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mutant_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mtntsht_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mtntsht_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mtntsht_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebggen_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_801615AC_D9D1C);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_801615B0_D9D20);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebggen_OnUpdate);

void rezop_rebggen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rbmastr_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rbmastr_OnUpdate);

void rezop_rbmastr_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebug_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_iris_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_iris_OnUpdate);

void rezop_iris_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgurny_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgurny_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgurny_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_gas_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_gas_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_gas_OnCollide);

void rezop_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

// Failing to match due to ro section?
INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_btimer_OnUpdate);

/*void rezop_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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
}*/

void rezop_markey_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_markey_OnUpdate);
