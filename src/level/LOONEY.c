#include "common.h"

#include "level/LOONEY.h"
#include "types/G2String.h"
#include "OBTABLE.h"
#include "MATRIX.h"

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

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bug_OnUpdate);

void looney_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    short* temp  = (short*)&instance->work0;

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

void looney_bouncer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bouncer_OnUpdate);

void looney_bouncer_OnCollide(Instance* instance, GameTracker* gameTracker) {
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
             && (bsp->instanceSpline == gameTracker->player)
             && (
                 (bsp->_08[4] == 0) || (bsp->_08[4] == 2)
             )) {
        func_80022714(instance, gameTracker);
    }
}

void looney_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->currentMainState = 0;
    instance->currentModelAnim = 0;
}

void looney_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int v0, v1;

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

void looney_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    int temp_a3 = bsp->_06;
    
    if (temp_a3 == 1) {
        if ((bsp->instanceSpline == gameTracker->player) && (bsp->_0C[5] >= 6U)) {
            if (instance->currentMainState == 0)
            {
                ((char*)instance->_40)[0xe] = 1;
                instance->currentMainState = temp_a3;
                instance->currentAnimFrame = 0;
                instance->flags2 &= ~0x10;
                instance->flags |= 0x100000;
            }
            else if (instance->currentMainState == 2)
            {
                INSTANCE_PlainDeath(instance, 5, 3, 0);
            }
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && ((instance->currentMainState - 1) >= 2U)) {
            func_80022714(instance, gameTracker);
        }
    }
}

void looney_bowling_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if ((instance->parent != NULL) && (instance->parent->intro != NULL)) {
        instance->flags |= 0x100400;
        WORK_AS(MultiSpline*, instance->work4) = instance->parent->intro->multiSpline;
    }
}

void looney_bowling_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->parent == NULL) {
        INSTANCE_KillInstance(instance);
    }
    if (SCRIPT_InstanceSplineProcess(instance, (SplineDef*)&instance->work0, WORK_AS_PTR(SplineDef, instance->work2), NULL, 1) > 0) {
        INSTANCE_PlainDeath(instance, 5, -1, 0);
    }
    if (++(WORK_AS(int, instance->work5)) == 0x50) {
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

    if (instance->currentMainState == 0) {
        intro = instance->intro;
        temp_v1 = (short*)intro->_2C;
        if (temp_v1 != NULL) {
            instance->work0 = ((int*)intro->data)[1];
            if (temp_v1[0] != 0) {
                instance->currentModelAnim = temp_v1[1];
            }
            instance->currentMainState = 1;
            instance->intro->_2C = NULL;
        } else if (instance->flags & 0x2000000) {
            instance->currentMainState = 1;
        }
    }
    
    if (instance->currentMainState != 0) {
        func_8002DAF8(instance, -1);
        if (instance->flags2 & 0x10) {
            instance->flags2 &= ~0x10;
            instance->currentMainState = 0;
            instance->flags &= ~0x2000000;
            instance->intro->_2C = NULL;
        }
    }
    
    func_8001DA8C(instance, gameTracker);
    
    if (instance->work0 > 0) {
        instance->work0--;
    }
}

void looney_doeboy_OnCollide(Instance* instance, GameTracker* gameTracker) {
    void* temp_a1;
    void* intro;

    if ((func_80027500(instance->bspTree, gameTracker) != 0) && (instance->work0 == 0)) {
        intro = instance->introData;
        if (intro != NULL) {
            temp_a1 = *(void**)intro;
            if (temp_a1 != 0) {
                SIGNAL_HandleSignal(instance, temp_a1 + 4, 0);
            }
        }
    }
}

void looney_brkblok_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = (int*)instance->introData;
    if (instance->flags & 0x20000) {
        instance->intro->position = instance->position;
    } else {
        if (intro != 0) {
            instance->work0 = intro[0];
            instance->work1 = intro[1];
        }
        instance->flags |= 0x10000;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_brkblok_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015ADD8_B3088);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015AF30_B31E0);

void func_8015B1BC_B346C(short* arg0) {
    func_800162C0(arg0);
    RotMatrixX(((short*)arg0)[0x44/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixY(((short*)arg0)[0x46/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixZ(((short*)arg0)[0x48/2], (char*)((int*)arg0)[5] + 0xC);
    if (((short*)arg0)[0xE/2] == 0x1D) {
        ((unsigned short*)arg0)[0x4C/2] = -((unsigned short*)arg0)[0x4C/2];
        ((unsigned short*)arg0)[0x4E/2] = -((unsigned short*)arg0)[0x4E/2];
        ((unsigned short*)arg0)[0x50/2] = -((unsigned short*)arg0)[0x50/2];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015B250_B3500);

extern char D_80161DC0_BA070[];
extern unsigned short D_80078A40[][4];
extern void func_80017E88();
extern void func_80016894();

void func_8015B4BC_B376C(Instance* instance) {
    extern int D_800EB8A0;
    Object* obj;
    Model* model;
    SVECTOR pos;
    SVECTOR vel;
    int i;

    obj = OBTABLE_FindObject(D_80161DC0_BA070);
    if (obj != NULL) {
        pos.x = instance->position.x;
        pos.y = instance->position.y;
        pos.z = instance->position.z + 0x140;
        model = obj->modelList[0];
        for (i = 0; i < 20; i++) {
            SVECTOR* entry;
            entry = (SVECTOR*)D_80078A40[rand() % 244];
            vel.x = entry->x >> 7;
            vel.y = entry->y >> 7;
            vel.z = entry->z >> 7;
            func_800170E8(model, model->_14, &pos, &vel, 0, D_800EB8A0, func_80017E88, func_80016894, 0xF);
        }
    }
}

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

void looney_leafgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    const char name[] = "leaffx__";
    char* targetObjectName = instance->introData;
    char* d = instance->object->data;
    long* p = &instance->work0;
    if (targetObjectName == 0) {
        if (d != 0) {
            targetObjectName = d;
        } else {
            instance->introData = (char*)name;
            targetObjectName = (char*)name;
        }
    }
    p[0] = ((int)OBTABLE_FindObject(targetObjectName));
    p[7] = (rand() & 0xF) + 1;
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015B934_B3BE4);

void func_8015BBA4_B3E54(short* arg0) {
    func_800162C0(arg0);
    RotMatrixX(((short*)arg0)[0x44/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixY(((short*)arg0)[0x46/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixZ(((short*)arg0)[0x48/2], (char*)((int*)arg0)[5] + 0xC);
}

extern int D_80078244;
extern int D_800EB8A0;
extern void func_8015B934_B3BE4();

void func_8015BC04_B3EB4(Instance* instance, int arg1, int arg2) {
    Model* model;

    if (instance->work0 != 0) {
        model = ((Object*)instance->work0)->modelList[0];
        D_80078244 = (rand() & 3) + 2;
        func_800170E8(model, model->_14 + 0xC, arg2, 0, 0, D_800EB8A0, func_8015B934_B3BE4, func_8015BBA4_B3E54, 0x28);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_leafgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_leafgen_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_funguy_OnCreate);


INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015BFCC_B427C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015C158_B4408);

void func_8015C230_B44E0(Instance* instance, short* arg1) {
    LVECTOR out;
    MATRIX* m = &instance->matrix[arg1[0xA / 2]];
    Instance* fx;

    MATH3D_ApplyMatrix(m, (SVECTOR*)&arg1[2], &out);
    fx = ((Instance*)func_8000B778(instance, out.x, out.y, out.z, 0, 0, -5, 0x64, 0x64, 0x64));
    fx->position.x = m->l[0];
    fx->position.y = m->l[1];
    fx->position.z = m->l[2];
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015C2D8_B4588);

void looney_funguy_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    long* fc = &instance->work0;
    switch (WORK_AS(int, instance->work3)) {
    case 0:
        func_8015BFCC_B427C(instance, gameTracker);
        break;
    case 1:
        func_8015C158_B4408(instance, gameTracker);
        break;
    case 2:
        func_8015C2D8_B4588(instance, gameTracker);
        break;
    }
    fc[4] -= 1;
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_funguy_OnCollide);

typedef struct {
    char _00[8];
    short min;
    short max;
    short count;
    short _0E;
    short (*entries)[4];
} FallGenIntro;

void looney_fallgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    FallGenIntro* intro;
    long* fc;
    int total;
    int i;

    total = 0;
    intro = instance->introData;
    fc = &instance->work0;
    if (intro != NULL) {
        for (i = 0; i < intro->count; i++) {
            total += intro->entries[i][2];
            intro->entries[i][3] = total;
        }
        fc[1] = total;
        if (intro->max != intro->min) {
            fc[0] = intro->min + rand() % (intro->max - intro->min);
        } else {
            fc[0] = intro->max;
        }
    }
    instance->flags |= 0x800;
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015C6A0_B4950);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallgen_OnUpdate);

void looney_fallgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallobj_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015CB5C_B4E0C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallobj_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fallobj_OnCollide);

void looney_teeter_OnCreate(Instance* instance, GameTracker* gameTracker) {
    extern int D_80161C9C_B9F4C;

    if (instance->introData == NULL) {
        instance->introData = &D_80161C9C_B9F4C;
    }
    instance->work7 = 0;
    instance->work8 = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_teeter_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_teeter_OnCollide);

extern short D_80161CA4_B9F54[];

void looney_trapsit_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->introData == 0) {
        instance->introData = D_80161CA4_B9F54;
    }
    instance->work2 = instance->position.z;
    if (((short*)instance->introData)[0] == 0) {
        instance->work0 = 2;
    } else {
        instance->work0 = 0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161DD8_BA088);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_trapsit_OnUpdate);

void looney_trapsit_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_trapmuv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_trapmuv_OnUpdate);

void looney_trapmuv_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void looney_pusher_OnCreate(Instance* instance, GameTracker* gameTracker) {
    WORK_AS(int, instance->work3) = 0;
    instance->work1 = 0;
    if (G2String_Compare_EQ(instance->object->name, "pusha___")) {
        instance->work2 = 0;
    } else {
        instance->work2 = 0x14;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_pusher_OnUpdate);

void looney_pusher_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void looney_bullet_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR d;
    Intro* intro;
    int angle;

    instance->work0 = 0x5A;
    instance->work1 = 0;
    d.x = PlayerInstance->position.x - instance->position.x;
    d.y = PlayerInstance->position.y - instance->position.y;
    d.z = PlayerInstance->position.z - instance->position.z;
    angle = ratan2(d.y, d.x) << 16;
    intro = instance->intro;
    instance->rotation.z = (angle >> 16) - 0x400;
    intro->rotation.z = 0;
    intro->rotation.y = 0;
    intro->rotation.x = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bullet_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_bullet_OnCollide);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161E0C_BA0BC);

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161E10_BA0C0);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_hunter_OnCreate);

int func_8015E1E4_B6494(Instance* instance, int arg1, int arg2) {
    LVECTOR d;
    short* intro = instance->introData;
    unsigned int sum;
    unsigned int rr;

    d.x = instance->position.x - PlayerInstance->position.x;
    d.y = instance->position.y - PlayerInstance->position.y;
    d.z = instance->position.z - PlayerInstance->position.z;
    sum = d.x * d.x + d.y * d.y + d.z * d.z;
    rr = intro[1] * intro[1];
    if (sum < rr) {
        ((short*)instance->_D0)[0] = arg2;
        ((short*)instance->_D0)[1] = 1;
        return 1;
    }
    return 0;
}

extern void func_8004ACB0(short* angle, short target, int step);

/* turn toward the player at 0x80 per tick */
void func_8015E290_B6540(Instance* instance) {
    SVECTOR d;

    d.x = PlayerInstance->position.x - instance->position.x;
    d.y = PlayerInstance->position.y - instance->position.y;
    d.z = PlayerInstance->position.z - instance->position.z;
    func_8004ACB0(&instance->rotation.z, ((ratan2(d.y, d.x) << 16) + 0x4000000) >> 16, 0x80);
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015E31C_B65CC);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015E4C4_B6774);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_hunter_OnUpdate);

void looney_hunter_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    char unused[1];

    if (bsp->instanceSpline == gameTracker->player && bsp->_06 == 1 && bsp->_0C[5] == 8 &&
        ((short*)instance->_D0)[0] != 8 && ((short*)instance->_D0)[0] != 0xC &&
        (unsigned short)(((short*)instance->_D0)[0] - 9) >= 2) {
        if (PlayerInstance->currentSubState != 0x20) {
            ((short*)instance->_D0)[0] = 0xC;
        } else {
            ((short*)instance->_D0)[0] = 8;
        }
        ((short*)instance->_D0)[1] = 1;
        ((short*)instance->_D0)[3] -= 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015F308_B75B8);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_daisy_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_daisy_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_8015FEC8_B8178);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_daisy_OnCollide);

extern int D_80161D98_BA048[];

void looney_grrfish_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->object->data == 0) {
        instance->object->data = D_80161D98_BA048;
    }
    instance->_D0[0] = instance->intro->position.z;
    if (*(int*)instance->object->data >= 0) {
        instance->currentModel = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80160164_B8414);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80160318_B85C8);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_grrfish_OnUpdate);

void looney_grrfish_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;

    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player && bsp->_0C[5] >= 6) {
        INSTANCE_PlainDeath(instance, 5, 3, 0);
    } else if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player) {
        func_80022714(instance, gameTracker);
    }
}

extern int D_80161DA4_BA054[];
void looney_funplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVector newPoint;
    SVector oldPoint;

    if (instance->introData == 0) {
        instance->introData = (void*)D_80161DA4_BA054;
    }
    newPoint.x = oldPoint.x = instance->position.x;
    newPoint.y = oldPoint.y = instance->position.y;
    newPoint.z = instance->_E0[2] = instance->position.z;
    oldPoint.z = instance->_40[6] + 0x80;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, (SVECTOR*)&newPoint, (SVECTOR*)&oldPoint, instance);
}

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

    if (instance->currentSubState) {
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

    BSPTree* bsp = instance->bspTree;
    Instance** s4 = ((Instance**)instance->_D0);

    if (bsp->_06 == 4) {
        if (bsp->instanceSpline == gameTracker->player) {
            if (instance->matrix) {

                func_80041FD0(&transformMatrix, instance->matrix);
                MATH3D_ApplyMatrixT(&transformMatrix, &bsp->globalOffset, &newPosition);

                instance->_D0[0] = (-newPosition.y) << 6;
                instance->_D0[1] = newPosition.x << 6;

                if (instance->work0 != 0) {
                    instance->_E0[3] = -0x1000;
                } else {
                    instance->_E0[3] = -0x4000;
                }

                s4[0x28/4] = bsp->instanceSpline;
                GenericCollide(instance, gameTracker);
            }
        }
    }
}

extern char D_80161DA8_BA058[];

void looney_fxgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
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
            instance->introData = D_80161DA8_BA058;
        }
        intro = instance->introData;
        fc[0] = (int)OBTABLE_FindObject(intro + 0xC);
        if ((intro[1] & 1) == 0) {
            if ((intro[1] & 2) != 0) {
                WORK_AS_IDX(short, instance->work5, 0) = 0x119;
                WORK_AS_IDX(short, instance->work5, 1) = 0x78;
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

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80160B20_B8DD0);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", func_80160BDC_B8E8C);

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_fxgen_OnUpdate);

void looney_fxgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_frocket_OnCreate);

void func_801615DC_B988C(Instance* instance, void* unused, SVECTOR* out, SVECTOR* in) {
    MATRIX mat;
    LVECTOR temp;

    func_80041FD0(&mat, instance->matrix);
    MATH3D_ApplyMatrix(&mat, in, &temp);
    out->x = mat.l[0] + temp.x;
    out->y = mat.l[1] + temp.y;
    out->z = mat.l[2] + temp.z;
}

void func_80161664_B9914(Instance* instance, void* unused, SVECTOR* out, SVECTOR* in) {
    MATRIX* mat;
    LVECTOR temp;

    mat = instance->matrix;
    MATH3D_ApplyMatrix(mat, in, &temp);
    out->x = mat->l[0] + temp.x;
    out->y = mat->l[1] + temp.y;
    out->z = mat->l[2] + temp.z;
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_frocket_OnUpdate);

void looney_frocket_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bspTree;
    bspTree = instance->bspTree;
    GenericCollide(instance, gameTracker);
    if (bspTree->instanceSpline == PlayerInstance) {
        if (PlayerInstance->currentMainState == 1) {
            instance->work1 = 1;
        }
    }
}

void looney_genbrk_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void looney_genbrk_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    GenericProcess(instance, gameTracker);
}

extern int D_800EB8A0;
void looney_genbrk_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (func_80027500(instance->bspTree, gameTracker)) {
        func_8015B250_B3500(instance, D_800EB8A0);
        func_80046978(instance);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/LOONEY", looney_jimboat_OnCollide);

void looney_colorset_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* intro;

    intro = instance->introData;
    instance->flags |= 0x80;
    if (intro != NULL) {
        instance->currentTextureAnimFrame = intro[0];
    }
}

void looney_colorset_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((instance->object->oflags & 0x40000) && bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player && bsp->_0C[5] >= 6U) {
        INSTANCE_PlainDeath(instance, 5, 3, 0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/level/LOONEY", D_80161E88_BA138);
