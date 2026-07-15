#include "common.h"

#include "CAMERA.h"
#include "level/CIRCUIT.h"
#include "types/intro/QMark.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"

#include "types/Vector.h"
extern int D_800E5FD8;
extern int D_80154834;

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_plat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_plat_OnUpdate);

void circuit_plat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;

    bsp = instance->bspTree;
    if (((int*)instance->introData)[1] & 0x20) {
        if (func_80025798(PlayerInstance) == 0) {
            return;
        }
    }
    if (bsp->_06 == 4) {
        if (instance->currentMainState == 1 && instance->work9 != 2) {
            instance->currentMainState = 0;
        }
        instance->currentSubState = 1;
    }
}

void circuit_bug_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* intro;

    WORK_AS_IDX(short, instance->work1, 1) = 0x18;
    instance->flags |= 0x100000;
    intro = (unsigned short*)instance->introData;

    if (intro != NULL) {
        WORK_AS_IDX(short, instance->work1, 0) = intro[0];
        WORK_AS_IDX(short, instance->work2, 1) = intro[1];
        WORK_AS_IDX(short, instance->work3, 0) = intro[2];
        WORK_AS_IDX(short, instance->work3, 1) = intro[3];
        WORK_AS_IDX(short, instance->work4, 0) = intro[4];
        if (((short*)intro)[5] != 0) {
            WORK_AS_IDX(short, instance->work4, 1) = ((short*)intro)[5];
        } else {
            WORK_AS_IDX(short, instance->work4, 1) = 0x40;
        }
    } else {
        WORK_AS_IDX(short, instance->work1, 0) = 0x96;
        WORK_AS_IDX(short, instance->work2, 1) = ((unsigned short*)&instance->intro->position)[0] - 0x500;
        WORK_AS_IDX(short, instance->work3, 0) = ((unsigned short*)&instance->intro->position)[1] - 0x780;
        WORK_AS_IDX(short, instance->work3, 1) = ((unsigned short*)&instance->intro->position)[0] + 0x500;
        WORK_AS_IDX(short, instance->work4, 0) = ((unsigned short*)&instance->intro->position)[1] + 0x780;
        WORK_AS_IDX(short, instance->work4, 1) = 0x40;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bug_OnUpdate);

void circuit_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    short* temp = (short*)&instance->work0;

    if (bsp->_06 == 1) {
        if ((bsp->instanceSpline == gameTracker->player) && (bsp->_08[4] < 2U) && (bsp->_0C[5] >= 6U)) {
            INSTANCE_PlainDeath(instance, 5, 3, 0);
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && ((bsp->_08[4] == 0) || (bsp->_08[4] == 2))) {
            func_80022714(instance, gameTracker);
            instance->currentMainState = 0;
            temp[4] = 0x5A;
        }
    }
}

void circuit_bouncer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    long* fc;
    
    intro = instance->introData;
    fc = &instance->work0;
    
    if (intro != NULL) {
        WORK_AS_IDX(short, instance->work1, 1) = intro[0];
        WORK_AS_IDX(short, instance->work2, 0) = intro[1];
    } else {
        WORK_AS_IDX(short, instance->work1, 1) = 0U;
        WORK_AS_IDX(short, instance->work2, 0) = 0U;
    }
    fc[3] = instance->intro->position.x;
    fc[4] = instance->intro->position.y;
    ((short*)fc)[5] = 6;
    instance->intro->rotation.z = instance->intro->rotation.z & 0xFFF;
    instance->currentMainState = 1;
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bouncer_OnUpdate);

void circuit_bouncer_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((bsp->_06 == 1)
        && (bsp->instanceSpline == (void*)gameTracker->player)
        && (bsp->_08[4] < 2U)
        && (bsp->_0C[5] >= 6U)
        && (
            (WORK_AS_IDX(short, instance->work2, 0) != 3)
            || ((instance->currentMainState - 2) < 2U)
            || (instance->currentMainState == 4)
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

void circuit_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->currentMainState = 0;
    instance->currentModelAnim = 0;
}

void circuit_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int** a0;
    int v0, v1;

    instance->flags2 &= ~0x10;
    if (instance->currentMainState == 0)
    {
        v1 = instance->oldPos.x;
        v0 = instance->oldPos.y;
        instance->rotation.z = ratan2(v0 - instance->position.y, v1 - instance->position.x) - 0x400;
        func_8002DAF8(instance, -1);
    }
    else if (instance->currentMainState == 1)
    {
        func_8002DAF8(instance, -1);
        if ((instance->flags2 & 0x10))
        {
            instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[(*(unsigned char*)&instance->_40[7])]))[1] - 1; 
            instance->currentMainState = 2;
        }
        
    }
}

void circuit_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    int temp_a3 = bsp->_06;

    if (temp_a3 == 1) {
        if ((bsp->instanceSpline == gameTracker->player) && (bsp->_0C[5] >= 6U)) {
            if (instance->currentMainState == 0)
            {
                instance->currentModelAnim = 1;
                instance->currentMainState = temp_a3;
                instance->currentAnimFrame = 0;
                instance->flags2 &= ~0x10;
                instance->flags |= 0x100000;
            }
            else if (instance->currentMainState == 2)
            {
                INSTANCE_PlainDeath(instance, 5, 3, 0);
            }
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == (void*)(gameTracker->player)) && ((instance->currentMainState - 1) >= 2U)) {
            func_80022714(instance, gameTracker);
        }
    }
}

void circuit_charger_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* intro = ((short*)instance->introData);
    short* data = ((short*)instance->object->data);

    if (instance->flags & 0x20000) {
        if (WORK_AS(int, instance->work4) != 0) {
            func_800331BC(WORK_AS(int, instance->work4));
            WORK_AS(int, instance->work4) = 0;
        }
    } else {
        WORK_AS(int, instance->work4) = 0;
        WORK_AS(int, instance->work5) = 0x4D;
        WORK_AS(int, instance->work6) = (rand() & 0x1F) - 0x10;
        instance->work7 = 0;
        instance->work8 = 1;
    }
    instance->work1 = 2;
    instance->work2 = 0x14;
    WORK_AS(int, instance->work3) = 0x12C;
    instance->work0 = 0;
    instance->flags |= 0x10000;
    if (intro != 0) {
        WORK_AS(int, instance->work3) = intro[1];
    } else if (data != 0) {
        instance->work1 = data[0];
        instance->work2 = data[1];
        WORK_AS(int, instance->work3) = data[3];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_charger_OnUpdate);

extern char D_80078240;

void circuit_charger_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->instanceSpline == gameTracker->player && instance->work0 == 0 && func_80025798(PlayerInstance) == 0) {
        instance->work0 = instance->work2;
    }
    if (func_80025798(PlayerInstance) == 0) {
        INSTANCE_BirthCachedObject(instance, 0xC);
        D_80078240 += 1;
    }
    func_80025764(PlayerInstance, gameTracker, WORK_AS_IDX(short, instance->work3, 1));
    func_80050A80(0, 2);
    instance->work7 = 1;
}

void circuit_chrganm_OnCreate(Instance* instance, GameTracker* gameTracker) {
    func_80027110(instance, 0xA, gameTracker);
}

void circuit_chrganm_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    Instance* player = gameTracker->player;
    MATRIX* m;
    int r;
    int flags;

    r = func_80025798(player);
    if (r != 0) {
        m = &player->matrix[10];
        instance->position.x = m->l[0];
        instance->position.y = m->l[1];
        instance->position.z = m->l[2];
        func_8002DAF8(instance, -1);
        flags = instance->flags & ~0x800;
        instance->flags = flags;
        if (r < 0x3D) {
            if (((int*)gameTracker)[0xE0 / 4] & 1) {
                instance->flags = flags | 0x800;
            }
        } else if (r < 0x79) {
            if (((int*)gameTracker)[0xE0 / 4] & 2) {
                instance->flags = flags | 0x800;
            }
        }
    }
}

void func_8015B548_82728(Instance* instance) {
    instance->scale.y = instance->work0;
    func_8002E704();
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015B570_82750);

void func_8015B780_82960(Instance* instance, GameTracker* gameTracker);

void circuit_ebridge_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro = ((int*)instance->introData);
    int* data = ((int*)instance->object->data);

    if (instance->flags & 0x20000) {
        func_8015B780_82960(instance, gameTracker);
    } else {
        instance->flags |= 0x10000;
        instance->work1 = 0x1FF;
        instance->work6 = 0;
        instance->work0 = 0x201;
        func_8015B548_82728(instance);
        instance->initialPos.x = instance->position.x;
        instance->initialPos.y = instance->position.y;
        instance->initialPos.z = instance->position.z;
        INSTANCE_InsertInstanceWithFlagsSet(instance, 0x1000);
        instance->currentMainState = 0;
        instance->work3 = 0x12C;
        instance->flags |= 0x800;
        if (intro != 0) {
            instance->work3 = intro[0];
        } else if (data != 0) {
            instance->work3 = data[0];
        }
        instance->flags2 |= 8;
    }
}

void func_8015B780_82960(Instance* instance, GameTracker* gameTracker) {
    Camera* camera;

    camera = gameTracker->camera;
    if (instance->work9 & 4) {
        instance->work9 &= ~4;
        CAMERA_SetSmoothValue(camera, instance->_D0[1]);
        CAMERA_CameraUnlock(camera, -1);
        CAMERA_Restore(camera, 1);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015B7E0_829C0);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015BA9C_82C7C);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ebridge_OnUpdate);

void circuit_ebridge_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->instanceSpline == gameTracker->player) {
        instance->_D0[0] = 10;
        instance->work9 |= 1;
    }
}

void circuit_ebrijac_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = instance->introData;
    instance->work0 = -1;
    if (intro != NULL) {
        instance->work0 = intro[0];
    }
    instance->work2 = 0;
}

void circuit_ebrijac_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->work2 != 0) {
        if (instance->scale.z == 0x1000) {
            instance->scale.z = 0x800;
            func_8002E704();
        }
    } else {
        if (instance->scale.z != 0x1000) {
            instance->scale.z = 0x1000;
            func_8002E704();
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ebrijac_OnCollide);

extern G2String D_801635CC_8A7AC;

/* set work2 on every instance in the intro group whose object parentName matches */
void func_8015C18C_8336C(Instance* instance, int val) {
    char unused[1];    /* dead local — reproduces the 8-byte frame */
    int i;
    int* list;
    int count;
    int* p;
    Intro* e;

    list = (int*)instance->intro->_04;
    count = list[0];
    p = list + 1;
    for (i = 0; i < count; i++, p++) {
        e = *(Intro**)p;
        if (e->instance != 0 && G2String_Compare_EQ(e->instance->object->parentName, &D_801635CC_8A7AC)) {
            e->instance->work2 = val;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbplat_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbplat_OnUpdate);

void circuit_orbplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;

    bsp = instance->bspTree;
    if (bsp->_06 == 4) {
        instance->currentSubState = 1;
    }
    if (bsp->_06 == 3 && instance->work9 <= 0 && instance->_D0[0] <= 0 && instance->currentMainState == 2) {
        instance->work9 = 4;
        WORK_AS(int, instance->work5) = -1;
        instance->work0 = (instance->work0 + 0x800) & 0xFFF;
        func_8004AAA8(instance, 0x1A, 0);
    }
}

void circuit_orbpole_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = (int*)instance->introData;
    instance->intro->rotation.z = 0;
    if (intro != 0) {
        instance->currentMainState = intro[1];
        intro[0] = func_8004A3B4(instance) - 1;
        if (intro[1] == 1) {
            instance->currentModelAnim = 1;
        } else {
            instance->currentModelAnim = 0;
        }
        instance->currentAnimFrame = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbpole_OnUpdate);

void func_8015C9CC_83BAC(Instance* instance) {
    instance->currentMainState = 2;
    instance->currentSubState = 1;
    instance->currentModelAnim = 1;
    instance->currentAnimFrame = 0;
    instance->flags2 &= ~0x10;
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_orbpole_OnCollide);

void circuit_launch_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* objData;
    int* intro;

    objData = instance->object->data;
    intro = instance->introData;
    
    WORK_AS(int, instance->work3) = 0;
    instance->initialPos.x = instance->position.x;
    instance->initialPos.y = instance->position.y;
    instance->initialPos.z = instance->position.z;
    instance->work8 = 0;
    instance->flags |= 0x800;
    WORK_AS(int, instance->work4) = 0x500;
    WORK_AS(int, instance->work5) = 0x80;
    instance->work9 = 0x1000;
    instance->work1 = 4;
    instance->work2 = 0x14;
    
    if (intro != NULL) {
        WORK_AS(int, instance->work4) = intro[0];
    } else if (objData != NULL) {
        WORK_AS(int, instance->work4) = objData[0];
        WORK_AS(int, instance->work5) = objData[1];
        instance->work8 = *(int*)&objData[2];
        if (instance->work8 & 2) {
            instance->work7 = 0x200;
            instance->flags &= ~0x800;
        }
        if (instance->work8 & 0x10) {
            instance->work9 = objData[8];
        }
    }
    
    instance->_D0[0] = WORK_AS_IDX(short, instance->work5, 1);
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_launch_OnUpdate);

int func_8015D354_84534(Instance* instance, GameTracker* gameTracker);
void func_8015D4B0_84690(Instance* instance, GameTracker* gameTracker);

void circuit_launch_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* player = gameTracker->player;
    BSPTree* bsp = instance->bspTree;
    char var_a2 = (bsp->_06 == 1) ? bsp->_0C[5] : -1;
    
    if (((instance->currentMainState - 1) >= 2U) && (WORK_AS(int, instance->work3) == 0) && (bsp->instanceSpline == player) && (bsp->_04 == 5) && (var_a2 < 8) && (bsp->_08[2] == 0)) {
        if (instance->work8 & 0x10) {
            player->work0 |= 0x200;
            instance->work8 |= 0x20;
        }
        else if ((((func_80025798(player, bsp) != 0) && (instance->work8 == 0)) || (instance->work8 & 1)) && (func_8015D354_84534(instance, gameTracker) == 0)) {
            func_8015D4B0_84690(instance, gameTracker);
        }
    }
}

void func_8015D304_844E4(Instance* instance, GameTracker* gameTracker) {
    instance->flags &= ~0x800;
    if (!(instance->work8 & 8)) {
        instance->work0 = instance->work2;
        instance->position.x = PlayerInstance->position.x;
        instance->position.y = PlayerInstance->position.y;
    }
}

extern G2String D_801635EC_8A7CC;

int func_8015D354_84534(Instance* instance, GameTracker* gameTracker) {
    int* sub;
    Intro** list;
    Intro* entry;
    Instance* other;
    int count;
    int i;

    if (instance->intro != NULL) {
        sub = instance->intro->_04;
        if (sub != NULL) {
            list = (Intro**)(sub + 1);
            count = sub[0];
            for (i = 0; i < count; i++, list++) {
                entry = *list;
                if (G2String_Compare_EQ(entry->object->parentName, &D_801635EC_8A7CC)) {
                    other = entry->instance;
                    if (other != NULL) {
                        if ((other->currentMainState - 1) < 2U) {
                            return 1;
                        }
                        if (*(int*)&other->work3 != 0) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void func_8015D42C_8460C(Instance* instance, GameTracker* gameTracker) {
    short* pData;

    pData = (short*)gameTracker->player->data;
    instance->flags |= 0x400;
    func_8015D304_844E4(instance, gameTracker);
    instance->currentMainState = 2;
    PlayerInstance->_E0[1] = pData[4];
    gameTracker->player->work0 |= 0x400;
    func_8004AAA8(instance, 0x18, 0);
}

void func_8015D4B0_84690(Instance* instance, GameTracker* gameTracker) {
    short* data;
    Instance* player;

    data = gameTracker->player->data;
    instance->flags |= 0x400;
    func_8015D304_844E4(instance, gameTracker);
    player = PlayerInstance;
    data[0x9C/2] = data[0xA0/2] - 1;
    data[0x9E/2] = data[0xA0/2] - 1;
    instance->currentMainState = 1;
    WORK_AS(int, instance->work5) = ((short*)&instance->_D0[0])[1];
    player->_D0[2] = 0;
    player->_E0[1] = 0;
    player->flags |= 0x400000;
    func_800256A8(gameTracker);
    data[0x8C/2] = 0;
    data[0x8E/2] = 0;
    data[0x90/2] = 0;
    data[0x94/2] = 0;
    data[0x96/2] = 0;
    data[0x98/2] = 0;
    func_8004AAA8(instance, 0x18, 0);
}

void circuit_follow_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if ((instance->intro->flags & 0x80) == 0) {
        instance->flags |= 0x400;
    }
    instance->work1 = 1;
    instance->flags |= 0x100800;
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_follow_OnUpdate);

void circuit_follow_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* player;
    Spline* spline;
    int* data;

    if (instance->work0 == 0) {
        instance->work0 = 0x1E;
        if (instance->intro->multiSpline != 0) {
            player = PlayerInstance;
            data = (int*)player->data;
            if (!(player->work0 & 1)) {
                data[0xE0 / 4] = (int)instance;
                spline = instance->intro->multiSpline->positional;
                WORK_AS(int, instance->work4) = spline->key[spline->numkeys - 1].point.y;
                player->work0 |= 2;
            }
        }
    }
}

void func_8015D780_84960(Instance* instance, GameTracker* gameTracker) {
    if (instance->introData != 0) {
        if (((int*)instance->introData)[0] != 0) {
            if (((int*)instance->introData)[0] > 10U) {
                SIGNAL_HandleSignal(instance, ((int*)instance->introData)[0] + 4, 0);
            } else {
                SIGNAL_HandleSignal(instance, ((int*)instance->introData)[1] + 4, 0);
            }
        }
    }
}

void circuit_pball_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015D7F0_849D0);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_pball_OnUpdate);

void circuit_pball_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->instanceSpline == gameTracker->player && !(instance->flags & 0x800)
        && gameTracker->player->currentSubState != 0x10000 && instance->bspTree->_0C[5] < 8U) {
        func_8002275C(instance, gameTracker);
        INSTANCE_KillInstance(instance);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015DB80_84D60);

void circuit_ppath_OnCreate(Instance* instance, GameTracker* gameTracker) {
    Model* model;
    void* introData = instance->introData;

    instance->currentTextureAnimFrame = 0;
    model = instance->object->modelList[instance->currentModel];
    instance->work1 = ((int*)model->_20)[2] * ((int*)model->_20)[3];
    if (instance->intro != 0 && instance->intro->_04 != 0) {
        instance->flags |= 0x80;
    }
    if (introData != 0) {
        if (instance->intro != 0 && instance->intro->_04 != 0 && instance == ((Intro**)instance->intro->_04)[2]->instance) {
            instance->work2 = 1;
            WORK_AS(int, instance->work4) = 0;
            WORK_AS(int, instance->work5) = -1;
        }
    }
}

void func_8015DD58_84F38(Instance* instance) {
    if (instance->currentMainState != 2) {
        instance->currentMainState = 2;
    } else {
        Model* model;

        model = instance->object->modelList[instance->currentModel];
        instance->currentTextureAnimFrame = ((int*)model->_20)[2] * ((int*)model->_20)[3] >> 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_ppath_OnUpdate);

void circuit_ppath_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->object->oflags & 0x400) {
        GenericCollide(instance, gameTracker);
    }
}

extern char D_801635A0_8A780[];

void circuit_fxgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    long* fc;
    unsigned char* intro;

    fc = &instance->work0;
    if (instance->flags & 0x20000) {
        if (WORK_AS(int, instance->work3) != 0) {
            func_800331BC(WORK_AS(int, instance->work3));
            WORK_AS(int, instance->work3) = 0;
        }
    } else {
        if (instance->introData == NULL) {
            instance->introData = D_801635A0_8A780;
        }
        intro = instance->introData;
        fc[0] = OBTABLE_FindObject(intro + 0xC);
        if ((intro[1] & 1) == 0) {
            if ((intro[1] & 2) != 0) {
                WORK_AS_IDX(short, instance->work5, 0) = 0x119;
                WORK_AS_IDX(short, instance->work5, 1) = 0x46;
                WORK_AS_IDX(short, instance->work6, 1) = 0xDAC;
                WORK_AS_IDX(short, instance->work6, 0)= (rand() & 0x7F) - 0x15E;
                WORK_AS_IDX(short, instance->work4, 1) = WORK_AS_IDX(short, instance->work4, 0) = rand() & 7;
                intro[1] |= 0x80;
            }
        }
        fc[3] = 0;
        instance->flags |= 0x10000;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015E084_85264);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015E140_85320);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_fxgen_OnUpdate);

void circuit_fxgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void circuit_qmark_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->work2 = 0;
    instance->work0 = 0x40;
    instance->work1 = 0;
}

void circuit_qmark_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    long* temp_s0;
    QMarkIntro* intro;
    
    intro = (QMarkIntro*)instance->introData;
    temp_s0 = &instance->work0;
    if ((WORK_AS(int, instance->work4) != 0) && !(gameTracker->gameFlags & 0x2000)) {
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

void circuit_qmark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    QMarkIntro* intro;

    intro = (QMarkIntro*)instance->introData;
    if (func_80027500(instance->bspTree, gameTracker) != 0) {
        instance->work2 = 1;
        instance->work0 = 0x12C;
        WORK_AS(int, instance->work5) = intro->time;
        WORK_AS(int, instance->work4) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015EC00_85DE0);

extern char D_80163604_8A7E4[];

void circuit_reza_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned char* fc = WORK_AS_PTR(unsigned char, instance->work0);
    short* intro = ((short*)instance->introData);

    instance->flags |= 0x100000;
    if (strcmp(gameTracker->level->levelType, D_80163604_8A7E4) == 0) {
        instance->currentModelAnim = 0;
        instance->currentAnimFrame = 0;
        WORK_AS(int, instance->work3) = 0;
        instance->flags &= ~0x100000;
        instance->flags2 &= ~0x10;
        WORK_AS_IDX(char, instance->work7, 0) = SCRIPT_CountFramesInSpline(instance);
    } else {
        if (intro == 0) {
            WORK_AS_IDX(char, instance->work7, 1) = 0;
            WORK_AS(int, instance->work6) = 0x80;
        } else {
            if (intro[1] == 0) {
                intro[1] = 0x80;
            }
            if (intro[0] == 2) {
                WORK_AS_IDX(char, instance->work7, 1) = 0;
            }
            if (instance->intro->multiSpline != 0) {
                WORK_AS_IDX(char, instance->work7, 2) = 0;
                WORK_AS_IDX(char, instance->work7, 0) = SCRIPT_CountFramesInSpline(instance);
                WORK_AS_IDX(char, instance->work7, 3) |= 1;
                WORK_AS_IDX(char, instance->work7, 1) = ((unsigned char*)intro)[1] & 0xFB;
            } else {
                WORK_AS_IDX(char, instance->work7, 1) = 0;
                WORK_AS_IDX(char, instance->work7, 3) |= 8;
            }
            *(int*)(fc + 0x18) = intro[1];
        }
        if (fc[0x1D] == 1) {
            func_8004A7B8(instance, 3, 0);
        } else {
            fc[0x1F] |= 2;
            func_8004A7B8(instance, 0, 0);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_reza_OnUpdate);

void circuit_reza_OnCollide(Instance* instance, GameTracker* gameTracker) {
    SVECTOR unused;    /* dead local — reproduces the 0x20 frame */
    BSPTree* bsp;
    int f;
    int g;

    bsp = instance->bspTree;
    if (bsp->instanceSpline == gameTracker->player && bsp->_06 == 1 && instance->currentModelAnim != 5) {
        /* the in-place mask keeps the original byte alive in g (register scheduling) */
        f = ((char*)&instance->work7)[3];
        g = f;
        f &= 0x80;
        if (f == 0) {
            if (g & 2) {
                ((char*)&instance->work7)[3] = g | 0x80;
                func_8004A7B8(instance, 2, 0);
            } else {
                func_80022714(instance, gameTracker);
            }
        }
    }
}

void func_8015FC70_86E50(Instance* instance);

void func_8015F6B8_86898(Instance* instance, int arg1, int arg2) {
    instance->currentMainState = 1;
    instance->currentSubState = 2;
    instance->currentModelAnim = 1;
    instance->currentAnimFrame = 0;
    WORK_AS_IDX(short, instance->work5, 0) = arg1;
    WORK_AS_IDX(short, instance->work5, 1) = arg2;
    instance->flags &= ~1;
    func_8015FC70_86E50(instance);
}

void func_8015F708_868E8(Instance* instance) {
    instance->currentMainState = 5;
    instance->currentModelAnim = 7;
    instance->currentAnimFrame = 0;
}

void func_8015F720_86900(Instance* instance) {
    if (instance->work0 == 0) {
        instance->work0 = instance->currentMainState | (instance->currentSubState << 16) | (instance->currentModelAnim << 24);
    }
}

void func_8015F75C_8693C(Instance* instance) {
    unsigned short val0;
    unsigned char val1;
    int val2;

    val0 = ((unsigned short*)&instance->work0)[1];
    val1 = ((unsigned char*)&instance->work0)[1];
    val2 = ((char*)&instance->work0)[0];
    instance->currentAnimFrame = 0;
    instance->work0 = 0;
    instance->currentMainState = val0;
    instance->currentSubState = val1;
    instance->currentModelAnim = val2;
}

/* walks a list of 0x14-byte weighted records, returning the record where
   the running weight sum first exceeds val (weighted random pick) */
int* func_8015F780_86960(int* p, int val) {
    int sum;

    sum = 0;
    if (val >= 0) {
        while (1) {
            sum += p[0];
            if (val < sum) {
                break;
            }
            p += 0x14 / 4;
        }
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_robo_OnCreate);

short func_8015F930_86B10(Instance* instance, int* arg1, int frame) {
    short* fc = WORK_AS_PTR(short, instance->work0);

    if (arg1[1] & 8) {
        frame = arg1[3];
    } else {
        if (arg1[1] & 4) {
            if (instance->currentSubState == 2) {
                instance->currentSubState = 3;
            } else {
                instance->currentSubState = 2;
            }
        } else if (frame == WORK_AS_IDX(short, instance->work4, 1) - 1) {
            func_8015F708_868E8(instance);
            return frame;
        }
        if (instance->currentSubState == 3) {
            if (frame > 0) {
                frame -= 1;
            } else {
                instance->currentSubState = 2;
                frame = 1;
            }
        } else if (frame < fc[9] - 1) {
            frame += 1;
        } else {
            instance->currentSubState = 3;
            frame = fc[9] - 2;
        }
    }
    return frame;
}

int* func_8015FA1C_86BFC(Instance* instance) {
    int* intro = (int*)instance->introData + 1;
    int* p;
    int* q;

    p = func_8015F780_86960(intro, WORK_AS_IDX(short, instance->work5, 0));
    q = func_8015F780_86960(intro, WORK_AS_IDX(short, instance->work5, 1));
    if (WORK_AS_IDX(short, instance->work6, 0)< q[2]) {
        return p;
    }
    p = q;
    WORK_AS_IDX(short, instance->work6, 0)= WORK_AS_IDX(short, instance->work6, 0)- q[2];
    WORK_AS_IDX(short, instance->work5, 0) = WORK_AS_IDX(short, instance->work5, 1);
    *(short*)&instance->work7 = p[1];
    WORK_AS_IDX(short, instance->work5, 1) = func_8015F930_86B10(instance, p, WORK_AS_IDX(short, instance->work5, 1));
    return p;
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_8015FAC4_86CA4);

extern unsigned short D_801635B8_8A798;

void func_8015FC70_86E50(Instance* instance) {
    Intro* intro = instance->intro;
    short** list = ((short**)(intro->_04 + 2));
    short* ea;
    short* eb;
    short dx;
    short dy;
    short base;
    int ext;

    eb = list[WORK_AS_IDX(short, instance->work5, 0)];
    ea = list[WORK_AS_IDX(short, instance->work5, 1)];
    dx = ea[0x10 / 2] - eb[0x10 / 2];
    dy = ea[0x12 / 2] - eb[0x12 / 2];
    base = D_801635B8_8A798 - intro->rotation.z;
    instance->rotation.z = base;
    if (dx == 0) {
        ext = base;
        if (dy > 0) {
            instance->rotation.z = ext + 0x400;
        } else {
            instance->rotation.z = ext - 0x400;
        }
    } else {
        instance->rotation.z += ratan2(dy, dx);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_robo_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_robo_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bomb_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635A0_8A780);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635B8_8A798);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635C0_8A7A0); // ebridge_

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635CC_8A7AC); // ebrijac_

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635D8_8A7B8); // orbplat_

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635DC_8A7BC);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635E4_8A7C4);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635EC_8A7CC); // launch__

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635F8_8A7D8); // ppathd__

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_801635FC_8A7DC);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_80163604_8A7E4); // horror______

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_80163610_8A7F0);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_80163618_8A7F8); // robo____

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_8016361C_8A7FC);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_bomb_OnUpdate);

void circuit_bomb_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

extern char D_8016363C_8A81C[];

void circuit_explode_OnCreate(Instance* instance, GameTracker* gameTracker) {
    Instance* parent;
    int* p = WORK_AS_PTR(int, instance->work0);
    LVECTOR dims;
    int r;

    dims = *(LVECTOR*)((int*)instance->object->modelList[instance->currentModel]->_20 + 1);
    WORK_AS_IDX(short, instance->work0, 0) = 0;
    WORK_AS_IDX(short, instance->work0, 1) = (dims.y - 1) * dims.z;
    instance->currentTextureAnimFrame = 0;
    parent = instance->parent;
    if (G2String_Compare_EQ(parent->object->parentName, D_8016363C_8A81C)) {
        instance->position.x += WORK_AS_IDX(short, parent->work3, 0);
        instance->position.z += WORK_AS_IDX(short, parent->work4, 0);
    }
    instance->flags |= 0x100480;
    r = (rand() & 0x3F) - 0x20;
    p[2] = r;
    p[1] = func_80050508(instance, 0x20, (short)r, 0x5C, 0x1D4C);
}

void circuit_explode_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short* p = WORK_AS_PTR(short, instance->work0);

    if (instance->work1 != 0) {
        if (func_80033200(instance->work1) == 0) {
            instance->work1 = 0;
        } else {
            func_800506B8(instance, instance->work1, WORK_AS_IDX(short, instance->work2, 1), 0x5C, 0x1D4C);
        }
    }
    p[0] += 1;
    if (p[1] < p[0]) {
        INSTANCE_KillInstance(instance);
    } else {
        instance->currentTextureAnimFrame += 1;
    }
}

void circuit_explode_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->instanceSpline == gameTracker->player && instance->bspTree->_06 == 1) {
        func_80022714(instance, gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", circuit_pulse_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/CIRCUIT", func_80160D80_87F60);

INCLUDE_RODATA("asm/nonmatchings/level/CIRCUIT", D_8016363C_8A81C); // bomb____

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
    BTimerIntro* intro;

    intro = (BTimerIntro*)instance->introData;
    instance->work2 = (intro->exitTime * 30);
    WORK_AS_IDX(short, instance->work0, 0) = intro->missionTime;
    WORK_AS_IDX(short, instance->work1, 0) = 0;
    instance->flags |= 0xC00;
    gameTracker->player->work0 |= 0x4000;
    gameTracker->player->flags |= 0x100;
    func_8002CA2C(4, intro->missionTime, intro);
    for (var_s0 = 1; var_s0 < 4; var_s0++) {
        func_8002C1AC(var_s0);
    }
    instance->currentSubState = 0;
}

void circuit_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    char buffer[0x50];
    int timeLeft;
    int minutesLeft;
    int secondsLeft;
    int var_v1;
    short* temp_s2;
    BTimerIntro* intro;

    var_v1 = 1;
    intro = instance->introData;
    temp_s2 = WORK_AS_PTR(short, instance->work0);
    if (WORK_AS_IDX(short, instance->work1, 0) == 0) {
        if (temp_s2[0] != 0) {
            if ((int)(((int**)gameTracker))[0x4BFC/4] < gameTracker->level->collectibleCountA) {
                if (D_80154834 != 0) {
                    WORK_AS_IDX(short, instance->work3, 0) = 1;
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
        if (((gameTracker->player->work0 & 0x600000) == 0x600000) && (instance->currentSubState == 0)) {
            temp_s2[0] = (intro->missionTime - 1);
            if (intro->collectType == EBTIMER_COLLECTTYPE_CUTSCENE) {
                SIGNAL_HandleSignal(PlayerInstance, intro->b + 4, 0);
            }
            instance->currentSubState = 1;
            PlayerInstance->work0 &= ~0x400000;
        }
        if ((gameTracker->player->work0 & 0x400000) && ((((int**)gameTracker)[0x4C00/4] != 0) || (((int**)gameTracker)[0x4C04/4] != 0))) {
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
        if (WORK_AS_IDX(short, instance->work1, 0) == 2) {
            // Delay map load
            if (--instance->work2 < 0) {
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