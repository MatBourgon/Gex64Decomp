#include "common.h"

#include "level/HORROR.h"

#include "types/Vector.h"
extern int* PlayerInstance;
extern int D_800E5FD8;
extern int D_80154834;


INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_drawer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_drawer_OnUpdate);

void horror_drawer_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_chandb_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_chandb_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_chandb_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_chand_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_chand_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_chand_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_axe_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80159D8C_9D5BC);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8015A014_9D844);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_axe_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_axe_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_face_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_face_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_face_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zombie_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C30_A8460);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C38_A8468);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zombie_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zombie_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zomarm_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zomarm_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zomarm_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zomleg_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zomleg_OnUpdate);

void horror_zomleg_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huck_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huck_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huck_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huckhed_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huckhed_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8015BF7C_9F7AC);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huckhed_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_gate_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_gate_OnUpdate);

void horror_gate_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltchst_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltchst_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltchst_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_ledge_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_ledge_OnUpdate);

void horror_ledge_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_ldgeact_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_ldgeact_OnUpdate);

void horror_ldgeact_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_bkshlf_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bkshlf_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bkshlf_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltlamp_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C4C_A847C);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C50_A8480);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C58_A8488);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C64_A8494);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C70_A84A0);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C74_A84A4);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltlamp_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_polter_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_polter_OnUpdate);

void horror_polter_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8015E05C_A188C);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8015E1A8_A19D8);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8015E220_A1A50);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_skel_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_skel_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_skel_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_skelh_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_skelh_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_skelh_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltlamp_OnCollide);

void horror_spray_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8015F620_A2E50);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_spray_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_spray_OnCollide);

void horror_shittrn_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_shittrn_OnUpdate);

void horror_shittrn_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bug_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bouncer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bouncer_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bouncer_OnCollide);

void horror_flasher_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_flasher_OnUpdate);

void horror_flasher_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_hhelev_OnCreate);

void horror_evileye_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_evileye_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_evileye_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_splitob_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_splitob_OnUpdate);

void horror_splitob_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_elevpan_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_elevpan_OnUpdate);

void horror_elevpan_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_onoff_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_onoff_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_onoff_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_funplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_funplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_funplat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_door_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80161F4C_A577C);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162024_A5854);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162118_A5948);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162214_A5A44);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_801622E4_A5B14);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_801623DC_A5C0C);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162438_A5C68);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_801624B4_A5CE4);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162524_A5D54);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8016257C_A5DAC);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_door_OnUpdate);

void horror_door_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_qmark_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0;
    instance->_F4[2] = 0x40;
    instance->_100 = 0;
}

void horror_qmark_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int* temp_s0;
    short* temp_t0;
    
    temp_t0 = (short*)instance->_20[1];
    temp_s0 = &instance->_F4[2];
    if (((*(int*)&instance->_10C) != 0) && !(gameTracker->gameFlags & 0x2000)) {
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

void horror_qmark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    short* temp_s1;

    temp_s1 = (short*)instance->_20[1];
    if (func_80027500(instance->_70[2]) != 0) {
        instance->_104 = 1;
        instance->_F4[2] = 0x12C;
        *((int*)&instance->_110) = temp_s1[4];
        *((int*)&instance->_10C) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80163B88_A73B8);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_reza_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_reza_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_reza_OnCollide);

void horror_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164CC0_A84F0);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164CC4_A84F4);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164CCC_A84FC);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164CD8_A8508);

void horror_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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
        if ((((short*)((int**)gameTracker))[0x4C12/2] == 0) && (var_v1 != 0) && (instance->intro[0x2C/4] == 0)) {
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

