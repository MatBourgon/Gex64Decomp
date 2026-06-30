#include "common.h"

#include "level/LOONEY.h"

extern int D_80161BD0_B9E80;

void looney_rainbow_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void looney_rainbow_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void looney_shittrn_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void looney_shittrn_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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
        func_80019828(&pos, &randVec, &D_80161BD0_B9E80, pos.z);
    }
}

void looney_shittrn_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void looney_bug_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bug_OnUpdate);

void looney_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void looney_bouncer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bouncer_OnUpdate);

void looney_bouncer_OnCollide(Instance* instance, GameTracker* gameTracker) {
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
             && (bsp->instanceSpline == gameTracker->player)
             && (
                 (bsp->_08[4] == 0) || (bsp->_08[4] == 2)
             )) {
        func_80022714(instance, gameTracker);
    }
}

void looney_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[0] = 0;
    instance->currentModelAnim = 0;
}

void looney_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int v0, v1;

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
            instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[(*(unsigned char*)&instance->_40[7])]))[1] - 1; 
            instance->_F4[0] = 2;
        }
        
    }
}

void looney_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int temp_a3;
    int temp_v1;
    BSPTree* bsp;

    bsp = instance->bspTree;
    temp_a3 = bsp->_06;
    if (temp_a3 == 1) {
        if ((bsp->instanceSpline == gameTracker->player) && (bsp->_0C[5] >= 6U)) {
            if (instance->_F4[0] == 0)
            {
                ((char*)instance->_40)[0xe] = 1;
                instance->_F4[0] = temp_a3;
                instance->currentAnimFrame = 0;
                instance->flags2 &= ~0x10;
                instance->flags |= 0x100000;
            }
            else if (instance->_F4[0] == 2)
            {
                INSTANCE_PlainDeath(instance, 5, 3, 0);
            }
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && ((instance->_F4[0] - 1) >= 2U)) {
            func_80022714(instance, gameTracker);
        }
    }
}

void looney_bowling_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if ((instance->parent != NULL) && (instance->parent->intro != NULL)) {
        instance->flags |= 0x100400;
        *(MultiSpline**)&instance->_10C = instance->parent->intro->multiSpline;
    }
}

void looney_bowling_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->parent == NULL) {
        INSTANCE_KillInstance(instance);
    }
    if (SCRIPT_InstanceSplineProcess(instance, &instance->_F4[2], &instance->_104, 0, 1) > 0) {
        INSTANCE_PlainDeath(instance, 5, -1, 0);
    }
    if (++(*(int*)&instance->_110) == 0x50) {
        instance->flags &= ~0x400;
    }
}

void looney_bowling_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void looney_doeboy_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags &= ~0x2000000;
}

void looney_doeboy_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    Intro* intro;
    short* temp_v1;

    if (instance->_F4[0] == 0) {
        intro = instance->intro;
        temp_v1 = (short*)intro->_2C;
        if (temp_v1 != NULL) {
            instance->_F4[2] = ((int*)intro->data)[1];
            if (temp_v1[0] != 0) {
                instance->currentModelAnim = temp_v1[1];
            }
            instance->_F4[0] = 1;
            instance->intro->_2C = NULL;
        } else if (instance->flags & 0x2000000) {
            instance->_F4[0] = 1;
        }
    }
    
    if (instance->_F4[0] != 0) {
        func_8002DAF8(instance, -1);
        if (instance->flags2 & 0x10) {
            instance->flags2 &= ~0x10;
            instance->_F4[0] = 0;
            instance->flags &= ~0x2000000;
            instance->intro->_2C = NULL;
        }
    }
    
    func_8001DA8C(instance, gameTracker);
    
    if (instance->_F4[2] > 0) {
        instance->_F4[2]--;
    }
}

void looney_doeboy_OnCollide(Instance* instance, GameTracker* gameTracker) {
    void* temp_a1;
    void* intro;

    if ((func_80027500(instance->bspTree, gameTracker) != 0) && (instance->_F4[2] == 0)) {
        intro = instance->introData;
        if (intro != NULL) {
            temp_a1 = *(void**)intro;
            if (temp_a1 != 0) {
                SIGNAL_HandleSignal(instance, temp_a1 + 4, 0);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_brkblok_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_brkblok_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015ADD8_B3088);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015AF30_B31E0);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015B1BC_B346C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015B250_B3500);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015B4BC_B376C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_brkblok_OnCollide);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161BD0_B9E80);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161BD8_B9E88);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161BE0_B9E90);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161BE4_B9E94);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161C00_B9EB0);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161C04_B9EB4);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161C34_B9EE4);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161C38_B9EE8);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161C64_B9F14);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161C6C_B9F1C);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161C70_B9F20);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161C9C_B9F4C);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161CA4_B9F54);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161CA8_B9F58);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161CE4_B9F94);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161CEC_B9F9C);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161CFC_B9FAC);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161D00_B9FB0);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161D2C_B9FDC);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161D34_B9FE4);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161D3C_B9FEC);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161D98_BA048);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161D9C_BA04C);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161DA4_BA054);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161DA8_BA058);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161DC0_BA070);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_leafgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015B934_B3BE4);

void func_8015BBA4_B3E54(short* arg0) {
    func_800162C0(arg0);
    RotMatrixX(((short*)arg0)[0x44/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixY(((short*)arg0)[0x46/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixZ(((short*)arg0)[0x48/2], (char*)((int*)arg0)[5] + 0xC);
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015BC04_B3EB4);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_leafgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_leafgen_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_funguy_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015BFCC_B427C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015C158_B4408);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015C230_B44E0);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015C2D8_B4588);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_funguy_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_funguy_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015C6A0_B4950);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallgen_OnUpdate);

void looney_fallgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallobj_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015CB5C_B4E0C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallobj_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallobj_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_teeter_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_teeter_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_teeter_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_trapsit_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161DD8_BA088);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_trapsit_OnUpdate);

void looney_trapsit_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_trapmuv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_trapmuv_OnUpdate);

void looney_trapmuv_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_pusher_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_pusher_OnUpdate);

void looney_pusher_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bullet_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bullet_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bullet_OnCollide);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161E00_BA0B0);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161E04_BA0B4);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161E0C_BA0BC);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161E10_BA0C0);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_hunter_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015E1E4_B6494);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015E290_B6540);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015E31C_B65CC);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015E4C4_B6774);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_hunter_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_hunter_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015F308_B75B8);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_daisy_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_daisy_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015FEC8_B8178);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_daisy_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_grrfish_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80160164_B8414);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80160318_B85C8);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_grrfish_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_grrfish_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_funplat_OnCreate);

void looney_funplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void looney_funplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fxgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80160B20_B8DD0);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80160BDC_B8E8C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fxgen_OnUpdate);

void looney_fxgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_frocket_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_801615DC_B988C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80161664_B9914);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_frocket_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_frocket_OnCollide);

void looney_genbrk_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_genbrk_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_genbrk_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_jimboat_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_colorset_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_colorset_OnCollide);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161E88_BA138);
