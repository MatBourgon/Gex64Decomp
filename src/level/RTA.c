#include "common.h"

#include "level/RTA.h"
#include "OBTABLE.h"
#include "types/G2String.h"
#include "types/intro/QMark.h"

#include "types/Vector.h"

void rta_zgrate_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[2] = instance->intro->position.z;
}

extern char D_8015EF10_DF580;

void rta_zgrate_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR unused;          /* dead local — reproduces the 8-byte frame */
    int z;
    int zz;

    if (D_8015EF10_DF580 != 0) {
        z = instance->position.z;
        zz = z;
        z = z - instance->_F4[2];
        if (z < 0x9C4) {
            instance->position.z = zz + 100;
        }
    } else {
        instance->position.z = instance->_F4[2];
        instance->_100 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zshark_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED10_DF380);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED20_DF390);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED30_DF3A0);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED40_DF3B0);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED50_DF3C0);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED60_DF3D0);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED70_DF3E0);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED80_DF3F0);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED90_DF400);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED94_DF404);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED98_DF408);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015ED9C_DF40C);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EDA0_DF410);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EDC8_DF438);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EDD0_DF440);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EDD4_DF444);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EDF0_DF460);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE00_DF470);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE04_DF474);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE08_DF478);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE10_DF480);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE18_DF488);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE1C_DF48C);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE20_DF490);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE24_DF494);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE28_DF498);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE2C_DF49C);

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE40_DF4B0);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zshark_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zshark_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015A2B0_DA920);

void rta_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[0] = 0;
    instance->currentModelAnim = 0;
}

void rta_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    
    int v0, v1;

    
    v1 = instance->oldPos.x;
    v0 = instance->oldPos.y;
    instance->rotation.z = ratan2(v0 - instance->position.y, v1 - instance->position.x) - 0x400;
    func_8002DAF8(instance, -1);
}

void rta_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((bsp->instanceSpline == gameTracker->player) && (bsp->_06 == 1)) {
        if (bsp->_0C[5] >= 6U) {
            INSTANCE_PlainDeath(instance, 5, 3, 0);
        }
        else
        {
            func_80022714(instance, gameTracker);
        }
    }
}


void rta_eel_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentModelAnim = 0;
    instance->currentAnimFrame = 0;
    instance->_D0[3] = 0;
    instance->_F4[0] = 0;
    instance->_100 = 0;
    instance->flags |= 0x800;
    instance->_104 = ((short*)instance->object->animList[1])[1];
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_eel_OnUpdate);

void rta_eel_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    Instance* player = gameTracker->player;
    
    if (func_80027500(bsp, gameTracker) || player->_F4[1] == 0x10) {
        INSTANCE_PlainDeath(instance, 5, 3, 0);
    } else if (bsp->_06 == 1 && bsp->instanceSpline == player) {
        func_80022714(instance, gameTracker);
    }
}

void rta_bug_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void rta_bug_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void rta_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rta_lavadrp_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void rta_lavadrp_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void rta_lavadrp_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rta_zturtle_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SCRIPT_InstanceSplineInit(instance, gameTracker);
    *(int*)&instance->_34[0] = 5;
    instance->scale.x = instance->scale.y = instance->scale.z = 0xCE4;
    instance->_F4[2] = 0;
    *(int*)&instance->_10C = 0;
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zturtle_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zturtle_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zarchsig_OnCollide);

void rta_count_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[2] = 0x20;
    instance->_100 = 0x15E;
    instance->flags |= 0x80;
    instance->currentTextureAnimFrame = ((int*)gameTracker8)[0x4CC8 / 4] + 1;
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_count_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zcargo_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zwleak_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zwleak_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zwleak_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015B1D4_DB844);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015B4EC_DBB5C);

extern char D_8015EE74_DF4E4[];

void rta_zgeyser_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[2] = (int)OBTABLE_FindObject(D_8015EE74_DF4E4);
    instance->scale.x = 0x1000;
    instance->scale.y = 0x1000;
    *(short*)&instance->_100 = 0;
    ((short*)&instance->_100)[1] = 0;
    *(short*)&instance->_104 = 0;
    instance->scale.z = 0x180;
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zgeyser_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zgeyser_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zdoor_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zdoor_OnUpdate);

void func_8015BD04_DC374(Instance* instance) {
    if (instance->_F4[0] == ((int*)instance->introData)[0]) {
        instance->position.x = instance->initialPos.x;
        instance->position.y = instance->initialPos.y;
        instance->position.z = instance->initialPos.z;
    } else {
        instance->position.x = instance->_F4[2];
        instance->position.y = instance->_100;
        instance->position.z = instance->_104;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015BD54_DC3C4);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zswitch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zswitch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zswitch_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zswitchm_OnCreate);

int func_8015C344_DC9B4(Instance* instance) {
    int result;
    Object* object;
    short* animData;

    result = 0;
    if (instance != NULL) {
        object = instance->object;
        if (object != NULL) {
            if (((short*)&object->_08)[1] > 0) {
                animData = (short*)(object->animList)[0];
                if (animData != NULL) {
                    if (animData[1] > 0) {
                        result = animData[1] - 1;
                    }
                }
            }
        }
    }
    return result;
}

INCLUDE_RODATA("asm/nonmatchings/level/RTA", D_8015EE74_DF4E4); // geysfx__

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zbubgen_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zbubgen_OnUpdate);

void rta_qmark_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0;
    instance->_F4[2] = 0x40;
    instance->_100 = 0;
}

void rta_qmark_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int* temp_s0;
    QMarkIntro* intro;
    volatile char _[4];
    
    intro = (QMarkIntro*)instance->introData;
    temp_s0 = &instance->_F4[2];
    if (((*(int*)&instance->_10C) != 0) && !(gameTracker->gameFlags & 0x2000)) {
        func_8003F6CC(intro->x, intro->y, intro->w, intro->h, intro->numMessages, intro->messages);
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
            instance->flags &= ~0x400;
        }
            
        break;
    }
    temp_s0[0] += temp_s0[1];
    instance->rotation.z = ((instance->rotation.z + temp_s0[0]) & 0xFFF);
}

void rta_qmark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    QMarkIntro* intro;
    intro = (QMarkIntro*)instance->introData;
    
    if (instance->bspTree->instanceSpline == gameTracker->player) {
        if (instance->_104 != 1) {
            func_80050508(instance, 3, 0, 0x64, 0x1388);
        }
        instance->_104 = 1;
        instance->_F4[2] = 0x12C;
         (*(int*)&instance->_110) = intro->time;
        (*(int*)&instance->_10C) = 1;
        instance->flags |= 0x400;
    }
}

void rta_zarrow_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->flags & 0x20000) {
        instance->intro->flags &= ~8;
    } else {
        instance->flags |= 0x10400;
        instance->_F4[2] = 0;
    }
}

extern int D_8015EF14_DF584;
extern short D_8015ED10_DF380[];

void rta_zarrow_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int v;

    v = instance->_F4[2] + 1;
    instance->_F4[2] = v;
    if (v >= 0x14) {
        instance->_F4[2] = 0;
        if (D_8015EF14_DF584 != 0) {
            func_8015C8C8_DCF38(&instance->position, 0x206C, D_8015EF14_DF584, D_8015ED10_DF380);
        }
    }
}

void func_8015C8C0_DCF30(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015C8C8_DCF38);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015CA24_DD094);

extern char D_8015EE18_DF488[];

void rta_fxgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    Object* obj;

    if (instance->introData == 0) {
        instance->introData = D_8015EE18_DF488;
    }
    memset(&instance->_F4[2], 0, 0x28);
    obj = OBTABLE_FindObject(D_8015EE74_DF4E4);
    if (obj != 0) {
        instance->_F4[2] = (int)obj->modelList[0];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_fxgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015CE34_DD4A4);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zstmvent_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zstmvent_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015D0B4_DD724);

void rta_zstmvent_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* player = gameTracker->player;
    if (instance->bspTree->instanceSpline == player) {
        func_80022714(instance->bspTree->instanceSpline, gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015D20C_DD87C);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015D374_DD9E4);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015D548_DDBB8);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015D74C_DDDBC);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015D9A0_DE010);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015DAF0_DE160);

void func_8015DE80_DE4F0(Instance* instance, GameTracker* gameTracker) {
    BSPTree newTree;

    instance = instance->bspTree->instanceSpline;
    if (instance != 0 && instance->object != 0) {
        if (G2String_Compare_EQ(instance->object->name, "ptbug___")) {
            instance->bspTree = &newTree;
            newTree.instanceSpline = PlayerInstance;
            common_cola_OnCollide(instance, gameTracker);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015DF08_DE578);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E038_DE6A8);

extern int D_8015EF18_DF588;

void func_8015E228_DE898(Instance* instance) {
    instance->_F4[0] = 6;
    instance->currentAnimFrame = 0x1A;
    instance->currentModelAnim = 0x35;
    instance->_F4[1] = 0;
    D_8015EF18_DF588 = 0x10;
    D_8015EF14_DF584 = (int)OBTABLE_FindObject("zbubbl__");
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E27C_DE8EC);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E3AC_DEA1C);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E538_DEBA8);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E5E0_DEC50);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E6F4_DED64);
