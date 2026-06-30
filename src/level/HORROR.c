#include "common.h"

#include "types/Camera.h"
#include "level/HORROR.h"
#include "types/intro/QMark.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"

#include "types/Vector.h"
extern int D_800E5FD8;
extern int D_80154834;
extern int D_80164C30_A8460;


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

void func_8015E1A8_A19D8(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;

    bsp = instance->bspTree;
    if (bsp->_06 == 1) {
        if (bsp->instanceSpline == gameTracker->player) {
            if (bsp->_0C[5] >= 6U) {
                instance->flags |= 0x10;
                INSTANCE_PlainDeath(instance, 5, 3, 0);
            }
        }
    }
}

int* func_8015E220_A1A50(Instance* instance, int arg1) {
    int* list;
    int* result;

    result = NULL;
    list = ((int**)instance->intro)[1];
    if (list != NULL) {
        if (arg1 < list[0]) {
            result = (int*)list[arg1 + 1];
        }
    }
    return result;
}

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

void horror_shittrn_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVector pos;
    SVector randVec;
    int i;

    pos.x = instance->position.x;
    pos.y = instance->position.y;
    pos.z = instance->position.z;

    for (i = 0; i < 2; i++) {
        randVec.x = rand() % 60 - 30;
        randVec.y = rand() % 60 - 30;
        randVec.z = rand() % 30 + 25;
        func_80019828(&pos, &randVec, &D_80164C30_A8460, pos.z);
    }
}

void horror_shittrn_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_bug_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* intro;

    ((short*)&instance->_100)[1] = 0x18;
    instance->flags |= 0x100000;
    intro = (unsigned short*)instance->introData;

    if (intro != NULL) {
        *(short*)&instance->_100 = intro[0];
        ((short*)&instance->_104)[1] = intro[1];
        *(short*)&instance->_108 = intro[2];
        ((short*)&instance->_108)[1] = intro[3];
        *(short*)&instance->_10C = intro[4];
        if (((short*)intro)[5] != 0) {
            ((short*)&instance->_10C)[1] = ((short*)intro)[5];
        } else {
            ((short*)&instance->_10C)[1] = 0x40;
        }
    } else {
        *(short*)&instance->_100 = 0x96;
        ((short*)&instance->_104)[1] = ((unsigned short*)&instance->intro->position)[0] - 0x500;
        *(short*)&instance->_108 = ((unsigned short*)&instance->intro->position)[1] - 0x780;
        ((short*)&instance->_108)[1] = ((unsigned short*)&instance->intro->position)[0] + 0x500;
        *(short*)&instance->_10C = ((unsigned short*)&instance->intro->position)[1] + 0x780;
        ((short*)&instance->_10C)[1] = 0x40;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bug_OnUpdate);

void horror_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;
    short* temp;

    bsp = instance->bspTree;
    temp = (short*)&instance->_F4[2];

    if (bsp->_06 == 1) {
        if ((bsp->instanceSpline == gameTracker->player) && (bsp->_08[4] < 2U) && (bsp->_0C[5] >= 6U)) {
            INSTANCE_PlainDeath(instance, 5, 3, 0);
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && ((bsp->_08[4] == 0) || (bsp->_08[4] == 2))) {
            func_80022714(instance, gameTracker);
            instance->_F4[0] = 0;
            temp[4] = 0x5A;
        }
    }
}

void horror_bouncer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bouncer_OnUpdate);

void horror_bouncer_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((bsp->_06 == 1)
        && (bsp->instanceSpline == (void*)gameTracker->player)
        && (bsp->_08[4] < 2U)
        && (bsp->_0C[5] >= 6U)
        && (
            (*(short*)&instance->_104 != 3)
            || ((instance->_F4[0] - 2) < 2U)
            || (instance->_F4[0] == 4)
        )) {
            INSTANCE_PlainDeath(instance, 5, 3, 0);
    }
    else if ((bsp->_06 == 1)
             && (bsp->instanceSpline == (void*)gameTracker->player)
             && (
                 (bsp->_08[4] == 0) || (bsp->_08[4] == 2)
             )) {
        func_80022714(instance, gameTracker);
    }
}

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

void horror_onoff_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->intro->flags & 0x1000) {
        instance->intro->flags &= ~0x800;
        return;
    }

    instance->_F4[0] = 0;
    instance->flags |= 0x80;

    if (instance->introData != NULL && *((int*)instance->introData) & 0x12) {
        instance->_F4[0] = 1;
    }

    if (instance->intro->flags & 0x800) {
        instance->_F4[0] = instance->_F4[0] != 1;
    }

    if (instance->object->data != NULL && *((int*)instance->object->data) != 0) {
        instance->_100 = 1;
    }

    if (instance->_F4[0] == 0 || instance->_100 != 0) {
        instance->currentAnimFrame = 0;
    } else if (((short*)&instance->object->_08)[1] != 0) {
        instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[0]))[1] - 1;
    }
}

void horror_onoff_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    instance->currentTextureAnimFrame = instance->_F4[0] ^ 1;

    if (instance->_F4[1] == 1) {
        if (instance->_F4[0] == 1 || instance->_100 != 0) {
            func_8002DAF8(instance, -1);
        } else {
            func_8002DAF8(instance, -0x3E9);
        }

        if (instance->flags2 & 0x10) {
            instance->flags2 &= ~0x10;
            instance->_F4[1] = 0;
            if (instance->_F4[0] == 0 || instance->_100 != 0) {
                instance->currentAnimFrame = 0;
            } else if (((short*)&instance->object->_08)[1] != 0) {
                instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[0]))[1] - 1;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_onoff_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_funplat_OnCreate);

void horror_funplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short* introData;
    int* state;
    int accelX;
    int accelY;

    introData = (short*)instance->introData;
    state = instance->_D0;
    accelX = (-instance->rotation.x << 5) - (instance->_D0[2] >> 6);
    accelX <<= 1;
    accelY = ((-instance->rotation.y << 5) - (instance->_D0[3] >> 6));
    accelY <<= 1;

    if (instance->_F4[1]) {
        GenericProcess(instance, gameTracker);
    }

    instance->_D0[2] += accelX + instance->_D0[0];
    instance->_D0[3] += accelY + instance->_D0[1];

    if (instance->_D0[2] > introData[1] << 12) {
        instance->_D0[2] = introData[1] << 12;
    } else if (instance->_D0[2] < -introData[1] << 12) {
        instance->_D0[2] = -introData[1] << 12;
    }

    if (state[3] > introData[1] << 12) {
        state[3] = introData[1] << 12;
    } else if (state[3] < -introData[1] << 12) {
        state[3] = -introData[1] << 12;
    }

    state[4] += state[2];
    state[5] += state[3];

    if (state[4] > introData[0] << 12) {
        state[4] = introData[0] << 12;
    } else if (state[4] < -introData[0] << 12) {
        state[4] = -introData[0] << 12;
    }

    if (state[5] > introData[0] << 12) {
        state[5] = introData[0] << 12;
    } else if (state[5] < -introData[0] << 12) {
        state[5] = -introData[0] << 12;
    }

    instance->rotation.x = (state[4] >> 12);
    instance->rotation.y = (state[5] >> 12);

    state[8] += state[7] + ((-state[9] >> 4) - (state[8] >> 6));
    state[9] += state[8];

    instance->position.z = state[6] + (state[9] >> 12);

    state[11] = state[10];
    state[10] = 0;
    state[0] = 0;
    state[1] = 0;
    state[7] = 0;
}

void horror_funplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    LVECTOR newPosition;
    MATRIX transformMatrix;

    BSPTree* instanceBsp = instance->bspTree;
    int* s4 = ((int*)instance->_D0);

    if (instanceBsp->_06 == 4) {
        if (instanceBsp->instanceSpline == gameTracker->player) {
            if (instance->matrix) {

                func_80041FD0(&transformMatrix, instance->matrix);
                MATH3D_ApplyMatrixT(&transformMatrix, (SVECTOR*)&((int*)instanceBsp)[0x18/4], &newPosition);

                instance->_D0[0] = (-newPosition.y) << 6;
                instance->_D0[1] = newPosition.x << 6;

                if (instance->_F4[2] != 0) {
                    instance->_E0[3] = -0x1000;
                } else {
                    instance->_E0[3] = -0x4000;
                }

                ((Instance**)s4)[0x28/4] = instanceBsp->instanceSpline;
                GenericCollide(instance, gameTracker);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_door_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80161F4C_A577C);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162024_A5854);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162118_A5948);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162214_A5A44);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_801622E4_A5B14);

void func_801623DC_A5C0C(GameTracker* arg0, short arg1, int arg2, void* arg3) {
    Camera* camera;

    camera = arg0->camera;
    if (!(((unsigned short*)arg3)[0xCC/2] & 0x10)) {
        if (camera->_data10[19] == 0) {
            ((char*)arg3)[0x120] = 1;
            camera->_data10[19] = (int)arg3;
            if (camera->mode != 2) {
                func_801622E4_A5B14(arg0, arg1, arg2, arg3);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80162438_A5C68);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_801624B4_A5CE4);

int func_80162524_A5D54(short* arg0, short* arg1) {
    int result;

    result = 0;
    if (arg0[0x3B8/2] == arg1[0]) {
        if (arg0[0x3BA/2] == arg1[1]) {
            if (arg0[0x3BE/2] == arg1[0xA]) {
                result = arg0[0x3BC/2] == arg1[2];
            }
        }
    }
    return result;
}

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
    QMarkIntro* intro;
    
    intro = (QMarkIntro*)instance->introData;
    temp_s0 = &instance->_F4[2];
    if (((*(int*)&instance->_10C) != 0) && !(gameTracker->gameFlags & 0x2000)) {
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

void horror_qmark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    QMarkIntro* intro;

    intro = (QMarkIntro*)instance->introData;
    if (func_80027500(instance->bspTree, gameTracker) != 0) {
        instance->_104 = 1;
        instance->_F4[2] = 0x12C;
        *((int*)&instance->_110) = intro->time;
        *((int*)&instance->_10C) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80163B88_A73B8);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_reza_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_reza_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_reza_OnCollide);

void horror_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164CC0_A84F0);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164CC4_A84F4);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164CCC_A84FC);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164CD8_A8508);

void horror_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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
            PlayerInstance->_F4[2] &= 0xFFBFFFFF;
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

