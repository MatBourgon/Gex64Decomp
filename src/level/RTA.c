#include "common.h"

#include "level/RTA.h"
#include "OBTABLE.h"
#include "INSTANCE.h"
#include "types/G2String.h"
#include "types/intro/QMark.h"

#include "types/Vector.h"

void rta_zgrate_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->work0 = instance->intro->position.z;
}

extern char D_8015EF10_DF580;

void rta_zgrate_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR unused;          /* dead local — reproduces the 8-byte frame */
    long z;
    long zz;

    if (D_8015EF10_DF580 != 0) {
        z = instance->position.z;
        zz = z;
        z = z - instance->work0;
        if (z < 0x9C4) {
            instance->position.z = zz + 100;
        }
    } else {
        instance->position.z = instance->work0;
        instance->work1 = 0;
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

void rta_zshark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if (bsp->instanceSpline == gameTracker->player) {
        if (WORK_AS(int, instance->work0) != 4) {
            if (bsp->_0C[5] == 8) {
                instance->flags = instance->flags & ~0x400;
                INSTANCE_PlainDeath(instance, 5, 3, 0);
            }
            else
            {
                func_80022D54(instance, gameTracker);
                WORK_AS(int, instance->work0) = 5;
                if (instance->currentModelAnim != 1) {
                    instance->currentModelAnim = 1;
                    instance->currentAnimFrame = 0;
                    instance->flags2 &= ~0x10;
                }
            }
        }
    } else {
        instance->position.x += bsp->localOffset.x;
        instance->position.y += bsp->localOffset.y;
        instance->position.z += bsp->localOffset.z;
        COLLIDE_UpdateAllTransforms(instance, &bsp->localOffset, gameTracker);
    }
}

void func_8015A2B0_DA920(Instance* instance, short arg1) {
    if (*(int*)&instance->_34[2] != 0) {
        if (func_80033200(*(int*)&instance->_34[2]) == 0) {
            *(int*)&instance->_34[2] = func_80050508(instance, 0x119, 0, 0x7E, arg1);
        } else if (func_800506B8(instance, *(int*)&instance->_34[2], 0, 0x7E, arg1) == 0) {
            func_800331BC(*(int*)&instance->_34[2]);
            *(int*)&instance->_34[2] = 0;
        }
    } else if (instance->_40[3] != 0) {
        instance->_40[3] -= 1;
    } else if (!(instance->intro->flags & 0x80)) {
        *(int*)&instance->_34[2] = func_80050508(instance, 0x119, 0, 0x7E, arg1);
        if (*(int*)&instance->_34[2] == 0) {
            instance->_40[3] = 5;
        }
    }
}

void rta_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->currentMainState = 0;
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
    instance->currentMainState = 0;
    instance->work1 = 0;
    instance->flags |= 0x800;
    instance->work2 = ((short*)instance->object->animList[1])[1];
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_eel_OnUpdate);

void rta_eel_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    Instance* player = gameTracker->player;
    
    if (func_80027500(bsp, gameTracker) || player->currentSubState == 0x10) {
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
    instance->work0 = 0;
    WORK_AS(int, instance->work4) = 0;
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zturtle_OnUpdate);

extern int D_8015EE24;

void rta_zturtle_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* player;
    Instance* other;

    if (instance->work0 == 0) {
        player = gameTracker->player;
        other = instance->bspTree->instanceSpline;
        if (other == player) {
            instance->work0 = 1;
            instance->work1 = other->position.x - instance->position.x;
            D_8015EF10_DF580 = 1;
            instance->work2 = other->position.y - instance->position.y;
            D_8015EE24 = 0xC8;
            instance->work3 = other->position.z - instance->position.z;
            other->currentSubState = 5;
            other->flags |= 0x100;
            ((int*)gameTracker->camera)[0x444 / 4] = 0x4B0;
            func_80050A80(0, 2);
        }
    }
}

extern int D_800EB8A0;

void rta_zarchsig_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* player;
    Instance* other;
    Object* obj;
    Instance* born;

    player = gameTracker->player;
    other = instance->bspTree->instanceSpline;
    if (other == player) {
        obj = OBTABLE_FindObject("count___");
        born = INSTANCE_BirthObject(other, obj);
        born->rotation.x = 0;
        born->rotation.y = 0;
        born->rotation.z = 0;
        born = INSTANCE_BirthObject(other, obj);
        born->rotation.x = 0;
        born->rotation.y = 0;
        born->rotation.z = 0x7FE;
        func_80018B60(other, D_800EB8A0, other->position.x, other->position.y, other->position.z + 0x15E);
        INSTANCE_PlainDeath(instance, 1, 0, 0);
    }
}

void rta_count_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->work0 = 0x20;
    instance->work1 = 0x15E;
    instance->flags |= 0x80;
    instance->currentTextureAnimFrame = ((int*)gameTracker8)[0x4CC8 / 4] + 1;
}

void rta_count_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->work1 >= 0x7D1) {
        func_8002E350(instance);
    } else {
        instance->rotation.z += instance->work0;
        if (instance->rotation.z >= 0x1000) {
            instance->rotation.z -= 0x1000;
        }
        instance->position.x = gameTracker->player->position.x;
        instance->position.y = gameTracker->player->position.y;
        instance->position.z = gameTracker->player->position.z + instance->work1;
        instance->work1 += 0x14;
        instance->work0 += 0x10;
    }
}

void rta_zcargo_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int* data = ((int*)instance->object->data);
    int val = 3;

    if (data != 0) {
        val = data[0];
    }
    if (instance->bspTree->instanceSpline == gameTracker->player) {
        func_80018B60(PlayerInstance, D_800EB8A0, instance->position.x, instance->position.y, instance->position.z);
        INSTANCE_PlainDeath(instance, 5, val, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zwleak_OnCreate);

extern short D_8015ED9C_DF40C;

void rta_zwleak_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    Instance* player;
    int dx;
    int dy;
    int dz;

    instance->work2 += 1;
    if (D_8015ED9C_DF40C < instance->work2) {
        player = gameTracker->player;
        dx = instance->position.x - player->position.x;
        dy = instance->position.y - player->position.y;
        dz = instance->position.z - player->position.z;
        if (dx * dx + dy * dy + dz * dz < (3500 * 3500)) {
            func_8015B1D4_DB844(instance);
        }
        instance->work2 = 0;
    }
    func_8015A2B0_DA920(instance, 0x9C4);
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zwleak_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015B1D4_DB844);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015B4EC_DBB5C);

extern char D_8015EE74_DF4E4[];

void rta_zgeyser_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->work0 = (int)OBTABLE_FindObject(D_8015EE74_DF4E4);
    instance->scale.x = 0x1000;
    instance->scale.y = 0x1000;
    WORK_AS_IDX(short, instance->work1, 0) = 0;
    WORK_AS_IDX(short, instance->work1, 1) = 0;
    WORK_AS_IDX(short, instance->work2, 0) = 0;
    instance->scale.z = 0x180;
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zgeyser_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zgeyser_OnCollide);

void func_8015BD04_DC374(Instance* instance);

void rta_zdoor_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->flags & 0x20000) {
        instance->intro->flags &= ~8;
    } else {
        instance->flags |= 0x10400;
        if (((int*)instance->introData) != 0) {
            int* intro = ((int*)instance->introData);
            if (intro[0] == 0) {
                intro[0] = 0;
            } else {
                intro[0] = 1;
            }
            instance->currentSubState = 0;
            memset(&instance->work0, 0, 0x28);
            instance->work0 = instance->initialPos.x + intro[2] * intro[3];
            instance->work1 = instance->initialPos.y + intro[2] * intro[4];
            instance->work2 = instance->initialPos.z + intro[2] * intro[5];
            func_8015BD04_DC374(instance);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zdoor_OnUpdate);

void func_8015BD04_DC374(Instance* instance) {
    if (instance->currentMainState == ((int*)instance->introData)[0]) {
        instance->position.x = instance->initialPos.x;
        instance->position.y = instance->initialPos.y;
        instance->position.z = instance->initialPos.z;
    } else {
        instance->position.x = instance->work0;
        instance->position.y = instance->work1;
        instance->position.z = instance->work2;
    }
}

int func_8015BD54_DC3C4(Instance* instance) {
    int* intro = instance->introData;
    int done = 0;

    if (instance->currentSubState == 0) {
        done = 1;
    } else if (WORK_AS(int, instance->work3) >= intro[2]) {
        done = 1;
        WORK_AS(int, instance->work3) = 0;
    } else {
        WORK_AS(int, instance->work3) += 1;
        if (instance->currentMainState == intro[0]) {
            instance->position.x += intro[3];
            instance->position.y += intro[4];
            instance->position.z += intro[5];
        } else {
            instance->position.x -= intro[3];
            instance->position.y -= intro[4];
            instance->position.z -= intro[5];
        }
    }
    return done;
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zswitch_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zswitch_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zswitch_OnCollide);

extern short D_8015EDFE_DF46E;
extern short D_8015EE00_DF470;
extern int D_8015EE04_DF474;
extern int D_8015EE08_DF478;

void rta_zswitchm_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int scale = D_8015EE08_DF478;
    int f;

    instance->position.z = D_8015EE04_DF474;
    D_8015EDFE_DF46E = 0;
    D_8015EE00_DF470 = 0;
    instance->scale.x = scale;
    instance->scale.y = scale;
    instance->scale.z = scale;
    if (instance->flags & 0x20000) {
        instance->intro->flags &= ~8;
    } else {
        f = instance->flags | 0x10000;
        instance->flags = f | 0x400;
        if (instance->intro->flags & 0x1000) {
            instance->intro->flags &= ~0x800;
        } else {
            instance->flags = f | 0x480;
            instance->currentMainState = 0;
            instance->currentSubState = 0;
            instance->currentAnimFrame = 0;
            memset(&instance->work0, 0, 0x28);
            instance->work0 = func_8015C344_DC9B4(instance);
            gameTracker->player->rotation.z = 0x800;
        }
    }
}

int func_8015C344_DC9B4(Instance* instance) {
    int result;
    Object* object;
    short* animData;

    result = 0;
    if (instance != NULL) {
        object = instance->object;
        if (object != NULL) {
            if (object->_0A > 0) {
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

void rta_zbubgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    long* p = &instance->work0;

    if (instance->flags & 0x20000) {
        instance->intro->flags &= ~8;
    } else {
        instance->flags |= 0x10400;
        if (instance->intro->flags & 0x1000) {
            instance->intro->flags &= ~0x800;
        } else {
            memset(p, 0, 0x28);
            instance->work0 = ((int)OBTABLE_FindObject("zbubblb_"));
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_zbubgen_OnUpdate);

void rta_qmark_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->work2 = 0;
    instance->work0 = 0x40;
    instance->work1 = 0;
}

void rta_qmark_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    long* temp_s0;
    QMarkIntro* intro;
    volatile char _[4];
    
    intro = (QMarkIntro*)instance->introData;
    temp_s0 = &instance->work0;
    if (((WORK_AS(int, instance->work4)) != 0) && !(gameTracker->gameFlags & 0x2000)) {
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
        if (instance->work2 != 1) {
            func_80050508(instance, 3, 0, 0x64, 0x1388);
        }
        instance->work2 = 1;
        instance->work0 = 0x12C;
         (WORK_AS(int, instance->work5)) = intro->time;
        (WORK_AS(int, instance->work4)) = 1;
        instance->flags |= 0x400;
    }
}

void rta_zarrow_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->flags & 0x20000) {
        instance->intro->flags &= ~8;
    } else {
        instance->flags |= 0x10400;
        instance->work0 = 0;
    }
}

extern int D_8015EF14_DF584;
extern short D_8015ED10_DF380[];

void rta_zarrow_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int v;

    v = instance->work0 + 1;
    instance->work0 = v;
    if (v >= 0x14) {
        instance->work0 = 0;
        if (D_8015EF14_DF584 != 0) {
            func_8015C8C8_DCF38(&instance->position, 0x206C, D_8015EF14_DF584, D_8015ED10_DF380);
        }
    }
}

void func_8015C8C0_DCF30(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015C8C8_DCF38);

extern int D_8015EE10_DF480;

void func_8015CA24_DD094(SVECTOR* pos, int count) {
    SVector randVec;
    int i;

    for (i = 0; i < count; i++) {
        randVec.x = rand() % 30 - 15;
        randVec.y = rand() % 30 - 15;
        randVec.z = rand() % 10 + 25;
        func_80019828(pos, &randVec, &D_8015EE10_DF480, pos->z);
    }
}

extern char D_8015EE18_DF488[];

void rta_fxgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    Object* obj;

    if (instance->introData == 0) {
        instance->introData = D_8015EE18_DF488;
    }
    memset(&instance->work0, 0, 0x28);
    obj = OBTABLE_FindObject(D_8015EE74_DF4E4);
    if (obj != 0) {
        instance->work0 = (int)obj->modelList[0];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", rta_fxgen_OnUpdate);

int func_8015CE34_DD4A4(Instance* instance, SVECTOR* offset, int arg2, short arg3, int arg4) {
    SVECTOR rel;
    SVECTOR pos;
    int other;

    MATH3D_ApplyMatrixSV(instance->matrix, offset, &rel);
    pos.x = instance->position.x + rel.x;
    pos.y = instance->position.y + rel.y;
    pos.z = instance->position.z + rel.z;
    other = func_800176E8(&pos, instance->work0, D_800EB8A0, arg3);
    if (other != 0) {
        func_80017CD8(other, 0, 0, arg2);
        func_80017D28(other, 0, 0, -3);
        func_80017AE0(other, arg4);
    }
    return other;
}

void rta_zstmvent_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int r;
    int z;

    instance->scale.x = 0x2000;
    instance->scale.y = 0x2000;
    instance->scale.z = 0x1000;
    memset(&instance->work0, 0, 0x28);
    instance->work0 = ((int)OBTABLE_FindObject("zstmbub_"));
    r = rand();
    z = instance->position.z;
    WORK_AS(int, instance->work3) = z;
    instance->work7 = z + 0x15E0;
    WORK_AS(int, instance->work4) = WORK_AS(int, instance->work3) - 0x514;
    WORK_AS(int, instance->work5) = WORK_AS(int, instance->work3);
    WORK_AS(int, instance->work6)= instance->work7;
    instance->position.z = WORK_AS(int, instance->work4);
    instance->work1 = r & 0x3F;
    instance->work2 = 0;
}

void rta_zstmvent_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int* fc = WORK_AS_PTR(int, instance->work0);

    if (instance->work2 == 0 && instance->position.z < WORK_AS(int, instance->work5)) {
        if (instance->work1 > 0) {
            instance->work1 -= 1;
        } else {
            instance->work1 = 0;
            instance->work2 = 1;
        }
        return;
    }
    if (instance->position.z >= fc[6]) {
        instance->position.z = fc[4];
        fc[1] = (rand() & 0x3F) + 0x80;
        fc[2] = 0;
    } else {
        if (fc[5] < instance->position.z) {
            fc[2] = 0;
        } else {
            if (fc[2] == 0) {
                return;
            }
            if (fc[0] == 0) {
                return;
            }
            func_8015D0B4_DD724(instance);
        }
        instance->position.z += 0x28;
    }
}

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
    instance->currentMainState = 6;
    instance->currentAnimFrame = 0x1A;
    instance->currentModelAnim = 0x35;
    instance->currentSubState = 0;
    D_8015EF18_DF588 = 0x10;
    D_8015EF14_DF584 = (int)OBTABLE_FindObject("zbubbl__");
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E27C_DE8EC);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E3AC_DEA1C);

void func_8015E538_DEBA8(short* rot, short dist, LVECTOR* out) {
    SVector v;
    MATRIX m;

    memset(&v, 0, sizeof(SVector));
    v.x = 0;
    v.y = dist;
    v.z = 0;
    MATH3D_SetUnityMatrix(&m);
    RotMatrixX(rot[0], &m);
    RotMatrixY(rot[1], &m);
    RotMatrixZ(rot[2], &m);
    MATH3D_ApplyMatrix(&m, (SVECTOR*)&v, out);
}

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E5E0_DEC50);

INCLUDE_ASM("asm/nonmatchings/level/RTA", func_8015E6F4_DED64);
