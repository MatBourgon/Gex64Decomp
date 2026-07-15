#include "common.h"

#include "level/GEXZIL.h"
#include "types/G2String.h"

void gexzil_bug_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bug_OnUpdate);

void gexzil_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80159B8C_92D0C);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80159DEC_92F6C);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162A90_9BC10);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162AA0_9BC20);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015A09C_9321C);

extern void func_80017AB8(short* arg0, short arg1);
void gexzil_ebolt_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->flags & 0x20000) {
        if (WORK_AS(short*, instance->work3) != 0) {
            func_80017AB8(WORK_AS(short*, instance->work3), 0);
            WORK_AS(short*, instance->work3) = 0;
        }
    } else {
        instance->flags |= 0x100000;
        instance->flags |= 0x10400;
        instance->object->oflags |= 8;
    }
}

void gexzil_ebolt_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    func_80159DEC_92F6C(instance, instance->work1);
    if (instance->work0 > 0) {
        instance->work0--;
    } else if (instance->work0 == 0) {
        func_8002E350(instance);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bldg_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_bldg_OnUpdate);

void func_8015B144_942C4(Instance* instance, GameTracker* gameTracker);

void gexzil_bldg_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    char* data = gameTracker->player->data;

    if (func_80027500(bsp, gameTracker) != 0 && instance->work0 < instance->work1) {
        func_8015B144_942C4(instance, gameTracker);
        if (instance->work8 != 0 && ((int*)data)[0x138 / 4] != 0 && bsp->instanceSpline == gameTracker->player) {
            bsp->instanceSpline->work0 |= 0x800;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015A7F0_93970);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015AC68_93DE8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015AE68_93FE8);

void func_8015B144_942C4(Instance* instance, GameTracker* gameTracker) {
    int one = 1;

    if (instance->currentSubState != one || instance->currentAnimFrame >= 0x12) {
        if (instance->work0 < instance->work1) {
            instance->currentAnimFrame = 0;
            instance->flags2 &= ~0x10;
            CAMERA_SetShake(gameTracker->camera, 0x14, 0x190);
            instance->currentSubState = one;
            instance->work0 += 1;
            if (instance->work0 >= instance->work1) {
                instance->flags |= 0x400;
            }
            if (instance->intro->data != 0) {
                *(int*)instance->intro->data = instance->work0;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015B220_943A0);

int func_8015B334_944B4(Intro* intro) {
    Instance* instance;
    int result;
    int flag;

    instance = intro->instance;
    if (instance != 0) {
        result = instance->work0 < instance->work1;
    } else {
        flag = intro->flags & 8;
        result = flag == 0;
    }
    return result;
}

void gexzil_mechjet_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->flags & 0x20000) {
        ((int*)instance->parent->object->data)[0x94 / 4] = 0;
    } else {
        instance->flags |= 0x10400;
    }
}

void gexzil_mechjet_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->currentMainState == 0) {
        func_8002DAF8(instance, -1);
        if (instance->flags2 & 0x10) {
            instance->currentMainState = 1;
            instance->currentAnimFrame = ((unsigned short*)instance->object->animList[0])[1] - 1;
            instance->flags2 &= ~0x10;
        }
    } else if (instance->currentMainState != 1) {
        func_8002DAF8(instance, -0x3E9);
        if (instance->flags2 & 0x10) {
            func_8002E350(instance);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015B460_945E0);

void gexzil_mechjet_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mecha_OnCreate);

void func_8015B964_94AE4(SVECTOR* from, SVECTOR* to, short* outYaw, short* outPitch) {
    SVECTOR d;
    int r;
    int len;

    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    *outYaw = ratan2(d.y, d.x);
    r = d.x * d.x + d.y * d.y;
    if (0x80000 < r) {
        len = (MATH3D_FastSqrt2(r << 4, 4) + 8) >> 4;
    } else {
        len = MATH3D_FastSqrt(r << 12) >> 12;
    }
    *outPitch = ratan2(d.z, len);
}

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162AB8_9BC38);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162ABC_9BC3C);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162AC4_9BC44);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162AD0_9BC50);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mecha_OnUpdate);

void func_8015C188_95308(Instance* instance, short* arg1) {
    if (arg1[0xC0 / 2] == 0) {
        if (instance->currentModelAnim == 4) {
            return;
        }
        instance->currentModelAnim = 4;
    } else if (arg1[0xC0 / 2] == 1) {
        if (instance->currentModelAnim == 0xF) {
            return;
        }
        instance->currentModelAnim = 0xF;
    } else {
        if (instance->currentModelAnim == 0x10) {
            return;
        }
        instance->currentModelAnim = 0x10;
    }
    instance->currentAnimFrame = 0;
    arg1[0x14 / 2] = 0;
    instance->flags2 &= ~0x10;
    arg1[0x12 / 2] = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015C208_95388);

void gexzil_mekblst_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->intro = NULL;
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mekblst_OnUpdate);

void func_8015EAB8_97C38(Instance* instance, int* arg1);

void func_8015C484_95604(Instance* instance, short* arg1, int* arg2) {
    extern int D_80154834;
    if (instance->flags2 & 0x10) {
        if (arg1[0x4E/2] <= 0 && D_80154834 == 0 && arg2[0x4C48/4] == 0) {
            func_8015EAB8_97C38(instance, ((int*)arg1));
        } else {
            instance->flags2 &= ~0x10;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015C504_95684);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015C704_95884);

void func_8015CADC_95C5C(Instance* instance, short* arg1) {
    int f;

    f = instance->flags2;
    if (f & 0x10) {
        if (arg1[0x26] <= 0) {
            gameTracker8->player->flags2 |= 0x10;
            PlayerInstance->currentMainState = 2;
            gameTracker8->player->work0 &= ~0x1000000;
            arg1[0x13] = 0x29;
        } else {
            instance->flags2 = f & ~0x10;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015CB68_95CE8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015CE34_95FB4);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015D1D0_96350);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015D3C8_96548);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015D64C_967CC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015D998_96B18);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015DB38_96CB8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015DD28_96EA8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015E084_97204);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015E390_97510);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B0C_9BC8C);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B18_9BC98);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B1C_9BC9C);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B24_9BCA4);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B28_9BCA8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015E8C0_97A40);

void func_8015EA18_97B98(Instance* instance, short* arg1) {
    instance->flags2 &= ~0x10;
    func_8015C188_95308(instance, arg1);
    arg1[0x26/2] = 6;
    ((int*)arg1)[0x18/4] &= ~4;
}

void func_8015EA68_97BE8(Instance* instance, short* arg1) {
    void* data;

    data = (void*)((int*)instance->intro)[8];
    arg1[0x26/2] = 9;
    instance->currentModelAnim = 2;
    instance->currentAnimFrame = 0;
    arg1[0x14/2] = 0;
    instance->flags2 &= ~0x10;
    arg1[0x12/2] = 0;
    instance->currentAnimFrame = 0x39;
    arg1[0x3C/2] = ((unsigned short*)data)[0x92/2];
}

void func_8015EAB8_97C38(Instance* instance, int* arg1) {
    arg1[0x54/4] = 1;
    ((short*)arg1)[0x26/2] = 0x15;
    func_8015C188_95308(instance, (short*)arg1);
    instance->flags2 &= ~0x10;
}

void func_8015EAFC_97C7C(Instance* instance, short* arg1) {
    arg1[0x26/2] = 0x14;
    func_8015C188_95308(instance, arg1);
    instance->flags2 &= ~0x10;
}

void func_8015EB38_97CB8(Instance* instance, void* arg1) {
    ((int*)arg1)[0x54/4] = 0;
    ((short*)arg1)[0x26/2] = 0xA;
    instance->currentModelAnim = 0;
    instance->currentAnimFrame = 0;
    ((short*)arg1)[0x14/2] = 0;
    instance->flags2 &= ~0x10;
    ((short*)arg1)[0x12/2] = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015EB68_97CE8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015EC5C_97DDC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F11C_9829C);

void func_8015F558_986D8(Instance* instance, void* arg1) {
    ((short*)arg1)[0x26/2] = 3;
    instance->currentModelAnim = 6;
    instance->currentAnimFrame = 0;
    ((short*)arg1)[0x14/2] = 0;
    instance->flags2 &= ~0x10;
    ((short*)arg1)[0x12/2] = 0;
}

void func_8015F588_98708(Instance* instance, short* arg1) {
    arg1[0x26/2] = 1;
    if (instance->currentModelAnim != 6) {
        instance->currentModelAnim = 6;
        instance->currentAnimFrame = 0;
        arg1[0x14/2] = 0;
        instance->flags2 &= ~0x10;
        arg1[0x12/2] = 0;
    }
    instance->flags2 &= ~0x10;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F5D4_98754);


void func_8015F680_98800(Instance* instance) {
    short* d;

    d = (short*)instance->object->data;
    d[8] = -1;
    d[0x13] = 7;
    instance->currentModelAnim = 2;
    instance->currentAnimFrame = 0;
    d[0xA] = 0;
    instance->flags2 &= ~0x10;
    d[9] = 0;
    instance->currentAnimFrame = 5;
    instance->_B8 = 0;
    d[0x1C] = d[0x1D];
    if (((int*)d)[0x90 / 4] != 0) {
        func_8002E350(((int*)d)[0x90 / 4]);
        ((int*)d)[0x90 / 4] = 0;
    }
}

int func_8015F708_98888(Instance* instance, Instance* arg1) {
    char* data = arg1->object->data;
    int** list;
    int result;
    int i;

    result = 0;
    list = ((int**)((int*)data)[0xA4 / 4]);
    if (list != 0) {
        i = 0;
        if (((short*)data)[0x44 / 2] > i) {
            do {
                if (func_8015AC68_93DE8(list[0], instance) != 0) {
                    result = 1;
                    break;
                }
                i += 1;
                list += 1;
            } while (((short*)data)[0x44 / 2] > i);
        }
    }
    return result;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F7B4_98934);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015F93C_98ABC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015FA98_98C18);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015FD80_98F00);

void func_8015FF70_990F0(Instance* instance, short* arg1)
{
    arg1[0x28/2] = 0;
    arg1[0x26/2] = 0x23;
}

void func_8015FF80_99100(Instance* instance, short* arg1) {
    void* data;

    data = (void*)((int*)instance->intro)[8];
    if (arg1[0x26/2] != 0x28) {
        arg1[0x26/2] = 0x28;
        instance->currentModelAnim = 7;
        instance->currentAnimFrame = 0;
        arg1[0x14/2] = 0;
        instance->flags2 &= ~0x10;
        arg1[0x12/2] = 0;
        arg1[0x4C/2] = ((unsigned short*)data)[5];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8015FFDC_9915C);

typedef struct {
    char _00[0x26];
    short state;         // 0x26
    char _28[2];
    unsigned short _2A;
    short _2C;
    char _2E[0xE];
    short _3C;
    char _3E[0x56];
    int _94;
} MechaData;

int func_8016014C_992CC(Instance* instance, MechaData* d) {
    int result;
    short state;
    int unused[1];

    result = 0;
    if (d->_2C == -1 && d->_3C == 0) {
        state = d->state;
        if (state != 5 && d->_94 == 0 && (unsigned short)(state - 2) >= 2 && d->_2A - 2 >= 2U && state != 7) {
            result = state != 0x1E;
        }
    }
    return result;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_801601D8_99358);

void func_80160344_994C4(void) {
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8016034C_994CC);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", gexzil_mecha_OnCollide);

/* p0/p1 are packed short pairs; returns the 12.4 planar distance between them */
int func_80160B70_99CF0(int p0, int p1) {
    int dx;
    int dy;

    dx = ((short*)&p0)[0] - ((short*)&p1)[0];
    dy = ((short*)&p0)[1] - ((short*)&p1)[1];
    return MATH3D_FastSqrt2((dx * dx >> 12) + (dy * dy >> 12), 0xC);
}

/* p0/p1 are packed short pairs (x in the high half, y in the low half) */
int func_80160BD8_99D58(int p0, int p1) {
    int angle;

    angle = (short)ratan2(((short*)&p1)[1] - ((short*)&p0)[1], ((short*)&p1)[0] - ((short*)&p0)[0]);
    if (angle < 0) {
        angle += 0x1000;
    }
    return angle;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80160C28_99DA8);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80160DF8_99F78);

extern char* D_80078288;

/* find the type-2 entry with the smallest coordinate sum in the 0x1C-stride table */
char* func_801614B0_9A630(void) {
    unsigned int unused[1];    /* dead local — reproduces the 0x10 frame */
    int best;
    char* result;
    char* e;
    int sum;

    best = 0x40000000;
    result = 0;
    for (e = D_80078288; e[7] != 0; e += 0x1C) {
        if (e[7] == 2) {
            sum = *(short*)(e + 0xA) + *(short*)(e + 0xC);
            if (sum < best) {
                best = sum;
                result = e;
            }
        }
    }
    return result;
}

extern int gGlobalMessageBuffer[];
extern int D_800BF1B8[];
extern int D_8007828C;

/* pool bookkeeping: D_8007828C is a table of 16-byte {count, chunk base}
   entries indexed by the node's pool id at p[6]; nodes are 28 bytes with a
   0x1C header. Returns the payload of the chunk's end node, or 0 for the
   two reserved sentinels. */
/* gGlobalMessageBuffer is currently defined as an OSMesgQueue due to main.c,
   but that object is exactly 0x18 bytes, so this indexing makes no sense.
   Either gGlobalMessageBuffer is a bigger struct containing an OSMesgQueue, or
   there is another variable stored right after it that we're trying to index
   here. */
char* func_80161538_9A6B8(char* p) {
    int t;

    if (p == (char*)gGlobalMessageBuffer[0x18 / 4]) {
        return 0;
    }
    if (p == (char*)D_800BF1B8[1]) {
        return 0;
    }
    t = p[6] * 16 + D_8007828C;
    if (*(char**)(t + 4) == p) {
        return p + *(int*)t * 28 - 0x1C;
    }
    return p - 0x1C;
}

/* companion to func_80161538: returns the successor node's payload, or the
   next chunk's base when p is its chunk's end node */
/* gGlobalMessageBuffer is currently defined as an OSMesgQueue due to main.c,
   but that object is exactly 0x18 bytes, so this indexing makes no sense.
   Either gGlobalMessageBuffer is a bigger struct containing an OSMesgQueue, or
   there is another variable stored right after it that we're trying to index
   here. */
char* func_801615A8_9A728(char* p) {
    int t;
    int e;

    if (p == (char*)gGlobalMessageBuffer[0x18 / 4]) {
        return 0;
    }
    if (p == (char*)D_800BF1B8[1]) {
        return 0;
    }
    t = p[6] * 16 + D_8007828C;
    e = *(int*)(t + 4) + *(int*)t * 28;
    if ((char*)(e - 0x1C) == p) {
        return *(char**)(((char*)e)[-0x16] * 16 + D_8007828C + 4);
    }
    return p + 0x1C;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161624_9A7A4);

typedef struct {
    int minX;
    int minY;
    int maxX;
    int maxY;
} BoundsRect;

BoundsRect func_80161938_9AAB8(short* box) {
    BoundsRect r;
    short x;

    x = box[0];
    if (box[2] < box[0]) {
        x = box[2];
    }
    r.minX = x;
    x = box[0];
    if (box[0] < box[2]) {
        x = box[2];
    }
    r.maxX = x;
    x = box[1];
    if (box[3] < box[1]) {
        x = box[3];
    }
    r.minY = x;
    x = box[1];
    if (box[1] < box[3]) {
        x = box[3];
    }
    r.maxY = x;
    return r;
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161A18_9AB98);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161B4C_9ACCC);

void func_80161EC4_9B044(int arg0, int arg1) {
    func_80161B4C_9ACCC(arg0, arg1 + 8);
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80161EE4_9B064);

void func_80161FF8_9B178(int arg0) {
    func_80161624_9A7A4(arg0);
    func_80161EE4_9B064(arg0);
}

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_80162024_9B1A4);

INCLUDE_ASM("asm/nonmatchings/level/GEXZIL", func_8016218C_9B30C);

typedef struct {
    short _00;
    short _02;
    short _04;
    short _06;
} GasData;

void gexzil_gas_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int t;
    unsigned short* introData;
    char* fc;
    void* data;
    int r;
    unsigned int m;

    t = 0;
    introData = ((unsigned short*)instance->introData);
    data = instance->data;
    fc = (char*)&instance->work0;
    if (instance->flags & 0x20000) {
        if (instance->currentMainState == 5) {
            func_800331BC(instance->work2);
        }
    } else {
        *(GasData*)&instance->work0 = *(GasData*)data;
        r = rand();
        instance->flags |= 0x80;
        instance->currentTextureAnimFrame = r % 24;
        if (introData != NULL) {
            if (introData[0] != 0xFFFF) {
                *(GasData*)&instance->work0 = *(GasData*)(introData + 1);
                if (WORK_AS_IDX(char, instance->work1, 2) < 0) {
                    WORK_AS(int, instance->work3) |= 0x8000;
                    WORK_AS_IDX(char, instance->work1, 2) = ~WORK_AS_IDX(unsigned char, instance->work1, 2);
                }
                t = INSTANCE_GetCurrentAnimationFrameCount(instance);
                m = introData[0];
                m %= (unsigned int)(((unsigned short*)&instance->work0)[1] + *(unsigned short*)&instance->work0 + WORK_AS_IDX(unsigned char, instance->work1, 1));
                if (m < ((unsigned short*)&instance->work0)[1]) {
                    WORK_AS_IDX(short, instance->work3, 0) = m;
                    instance->currentMainState = 0;
                } else {
                    m -= ((unsigned short*)&instance->work0)[1];
                    if (m < WORK_AS_IDX(unsigned char, instance->work1, 1)) {
                        WORK_AS_IDX(short, instance->work3, 0) = m;
                        instance->currentMainState = 1;
                    } else {
                        m -= WORK_AS_IDX(unsigned char, instance->work1, 1);
                        if (m < t) {
                            instance->currentMainState = 2;
                            t = m;
                        } else {
                            m -= t;
                            if (m < *(unsigned short*)&instance->work0) {
                                WORK_AS_IDX(short, instance->work3, 0) = m;
                                instance->currentMainState = 3;
                            } else {
                                m -= *(unsigned short*)&instance->work0;
                                if (m < t) {
                                    instance->currentMainState = 4;
                                    t = t - m;
                                } else {
                                    t = 0;
                                }
                            }
                        }
                    }
                }
            } else {
                instance->currentMainState = 5;
                t = INSTANCE_GetCurrentAnimationFrameCount(instance) - 1;
                instance->flags |= 0x10000;
            }
        }
        if (fc[6] >= 3) {
            fc[6] = 2;
        }
        func_8004A7B8(instance, fc[6], t);
    }
}

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B3C_9BCBC);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B48_9BCC8);

void gexzil_gas_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* fc;
    unsigned short x;
    unsigned short y;
    int w;

    fc = (unsigned short*)&instance->work0;
    x = WORK_AS_IDX(unsigned short, instance->work3, 0);
    y = instance->currentTextureAnimFrame;
    WORK_AS_IDX(unsigned short, instance->work3, 0) = x + 1;
    w = WORK_AS(int, instance->work3);
    instance->currentTextureAnimFrame = y + 1;
    if (w & 0x8000) {
        instance->rotation.z = (instance->rotation.z + 0x2200) & 0xFFF;
    }
    switch (instance->currentMainState) {
    case 0:
        if (fc[6] >= fc[1]) {
            fc[6] = 0;
            instance->currentMainState = 1;
            instance->currentSubState = 2;
            instance->flags2 &= ~0x10;
        }
        break;
    case 1:
        if (fc[6] >= ((unsigned char*)fc)[5]) {
            fc[6] = 0;
            instance->currentMainState = 2;
            instance->flags2 &= ~0x10;
            instance->flags |= 0x400;
        } else if (instance->currentSubState == 2) {
            func_8004A820(instance, 0);
            if (instance->currentAnimFrame >= ((unsigned char*)fc)[4]) {
                instance->currentSubState = 4;
                instance->currentAnimFrame = ((unsigned char*)fc)[4];
            } else if (instance->flags2 & 0x10) {
                instance->currentSubState = 4;
            }
        } else if (instance->currentSubState == 4) {
            func_8004A8A8(instance, 0);
            if (instance->flags2 & 0x10) {
                instance->currentSubState = 0;
            }
            instance->flags2 &= ~0x10;
        }
        break;
    case 2:
        func_8004A820(instance, 0);
        if (instance->flags2 & 0x10) {
            fc[6] = INSTANCE_GetCurrentAnimationFrameCount(instance);
            instance->currentMainState = 3;
        }
        break;
    case 3:
        if (fc[6] >= fc[0]) {
            fc[6] = 0;
            instance->currentMainState = 4;
            instance->flags2 &= ~0x10;
        }
        break;
    case 4:
        func_8004A8A8(instance, 0);
        if (instance->flags2 & 0x10) {
            fc[6] = INSTANCE_GetCurrentAnimationFrameCount(instance);
            instance->currentMainState = 0;
            func_800331BC(((int*)fc)[2]);
            instance->flags &= ~0x400;
        }
        break;
    case 5:
        break;
    }
}

void gexzil_gas_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* bspPlayer;
    int playerState;

    bspPlayer = instance->bspTree->instanceSpline;
    playerState = (int)gameTracker->player;
    if (bspPlayer->object != NULL && bspPlayer == (Instance*)playerState
        && instance->currentMainState >= 2 && func_80027578(instance, gameTracker, bspPlayer) == 0) {
        playerState = PlayerInstance->currentSubState;
        if (playerState != 0x200000 && playerState != 0x10 && playerState != 0x2000) {
            func_800223F8(gameTracker8, 0x78, 0);
        }
    }
}

extern char D_80162B70_9BCF0[];

void gexzil_explode_OnCreate(Instance* instance, GameTracker* gameTracker) {
    Instance* parent;
    int* p = WORK_AS_PTR(int, instance->work0);
    LVECTOR dims;
    int r;

    dims = *(LVECTOR*)((int*)instance->object->modelList[instance->currentModel]->_20 + 1);
    WORK_AS_IDX(short, instance->work0, 0) = 0;
    WORK_AS_IDX(short, instance->work0, 1) = (dims.y - 1) * dims.z;
    instance->currentTextureAnimFrame = 0;
    parent = instance->parent;
    if (G2String_Compare_EQ(parent->object->parentName, D_80162B70_9BCF0)) {
        instance->position.x += WORK_AS_IDX(unsigned short, parent->work3, 0);
        instance->position.z += WORK_AS_IDX(unsigned short, parent->work4, 0);
    }
    instance->flags |= 0x100480;
    r = (rand() & 0x3F) - 0x20;
    p[2] = r;
    p[1] = func_80050508(instance, 0x20, (short)r, 0x5C, 0x1D4C);
}

void gexzil_explode_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void gexzil_explode_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->instanceSpline == gameTracker->player && instance->bspTree->_06 == 1) {
        func_80022714(instance, gameTracker);
    }
}

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B70_9BCF0);

INCLUDE_RODATA("asm/nonmatchings/level/GEXZIL", D_80162B74_9BCF4);
