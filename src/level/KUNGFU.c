#include "common.h"

#include "level/KUNGFU.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"
#include "SPLINE.h"
#include "OBTABLE.h"


extern int D_800E5FD8;
extern int D_80154834;

void kungfu_kboat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR a;
    SVECTOR b;

    instance->flags |= 0x400;
    a.x = b.x = instance->position.x;
    a.y = b.y = instance->position.y;
    a.z = instance->position.z - 0x100;
    b.z = instance->position.z + 0x200;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, &a, &b, instance);
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_kboat_OnUpdate);

void kungfu_kboat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    GenericCollide(instance, gameTracker);
}

void kungfu_kbgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = (int*)instance->introData;
    instance->currentMainState = 0;
    instance->flags |= 0x100C00;
    if (intro != 0) {
        if (intro[3] == 0 || (((unsigned short*)intro)[0xC] & 4)) {
            instance->work0 = intro[2];
        } else {
            instance->currentMainState = 1;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_kbgen_OnUpdate);

void kungfu_spray_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

typedef struct {
    char _00[0x1C];
    short posX;
    short posY;
    short posZ;
    short _22;
    unsigned short unk24;
    short _26;
    unsigned short unk28;
    short _2A;
    unsigned short unk2C;
    short _2E;
    unsigned short unk30;
    short _32;
    unsigned short unk34;
    short _36;
    unsigned short unk38;
    short _3A;
    unsigned short unk3C;
    short _3E;
    unsigned short unk40;
    char _42[0x2A];
    unsigned short frame;
} SprayData;

extern void func_80016894(void*);
INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80159B1C_A8D3C);
/* near-match (18 diffs: frame a1/a2, mflo v0/v1, z-check v0/v1 swap — scheduler difference):
void func_80159B1C_A8D3C(void* arg0) {
    SprayData* data;
    Instance* player;
    int dz;
    int posZadj;
    int dx;
    int dy;

    data = ((SprayData*)arg0);
    data->unk24 -= 5;
    data->unk28 += 5;
    data->frame++;
    data->unk2C -= 5;
    data->unk30 -= 5;
    data->unk34 += 5;
    data->unk38 += 5;
    data->unk3C += 5;
    data->unk40 -= 5;
    func_80016894(arg0);
    player = PlayerInstance;
    dx = player->position.x - data->posX;
    dy = player->position.y - data->posY;
    if (dx * dx + dy * dy < 0x4000) {
        posZadj = data->posZ - 0x100;
        dz = player->position.z - posZadj;
        if (dz < 0) dz = -dz;
        if (dz < 0x100) {
            if (player->currentSubState != 0x200000) {
                func_800223F8(gameTracker8, 0x78, 0);
            }
        }
    }
}
*/

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_801626C0_B18E0);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_spray_OnUpdate);

void kungfu_spray_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->_06 == 1
        && instance->bspTree->instanceSpline == gameTracker->player
        && instance->bspTree->_0C[5] >= 6U) {
        func_8004AAA8(instance, 10, 0);
        INSTANCE_PlainDeath(instance, 5, 3, 0);
    }
}

void kungfu_bug_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_bug_OnUpdate);

void kungfu_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void kungfu_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->currentMainState = 0;
    instance->currentModelAnim = 0;
}

void kungfu_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void kungfu_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void kungfu_launch_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_launch_OnUpdate);

int func_8015AC6C_A9E8C(Instance* instance, GameTracker* gameTracker);
void func_8015ADC8_A9FE8(Instance* instance, GameTracker* gameTracker);

void kungfu_launch_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* player = gameTracker->player;
    BSPTree* bsp = instance->bspTree;
    char var_a2 = (bsp->_06 == 1) ? bsp->_0C[5] : -1;
    
    if (((instance->currentMainState - 1) >= 2U) && (WORK_AS(int, instance->work3) == 0) && (bsp->instanceSpline == player) && (bsp->_04 == 5) && (var_a2 < 8) && (bsp->_08[2] == 0)) {
        if (instance->work8 & 0x10) {
            player->work0 |= 0x200;
            instance->work8 |= 0x20;
        }
        else if ((((func_80025798(player, bsp) != 0) && (instance->work8 == 0)) || (instance->work8 & 1)) && (func_8015AC6C_A9E8C(instance, gameTracker) == 0)) {
            func_8015ADC8_A9FE8(instance, gameTracker);
        }
    }
}

void func_8015AC1C_A9E3C(Instance* instance, GameTracker* gameTracker) {
    instance->flags &= ~0x800;
    if (!(instance->work8 & 8)) {
        instance->work0 = instance->work2;
        instance->position.x = PlayerInstance->position.x;
        instance->position.y = PlayerInstance->position.y;
    }
}

extern G2String D_801626DC_B18FC;

int func_8015AC6C_A9E8C(Instance* instance, GameTracker* gameTracker) {
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
                if (G2String_Compare_EQ(entry->object->parentName, &D_801626DC_B18FC)) {
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

void func_8015AD44_A9F64(Instance* instance, GameTracker* gameTracker) {
    short* pData;

    pData = (short*)gameTracker->player->data;
    instance->flags |= 0x400;
    func_8015AC1C_A9E3C(instance, gameTracker);
    instance->currentMainState = 2;
    PlayerInstance->_E0[1] = pData[4];
    gameTracker->player->work0 |= 0x400;
    func_8004AAA8(instance, 0x6A, 0);
}

void func_8015ADC8_A9FE8(Instance* instance, GameTracker* gameTracker) {
    short* data;
    Instance* player;

    data = gameTracker->player->data;
    instance->flags |= 0x400;
    func_8015AC1C_A9E3C(instance, gameTracker);
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
    func_8004AAA8(instance, 0x6A, 0);
}

void func_8015AE8C_AA0AC(Instance* instance, GameTracker* gameTracker)
{
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

void kungfu_onoff_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->intro->flags & 0x1000) {
        instance->intro->flags &= ~0x800;
        return;
    }

    instance->currentMainState = 0;
    instance->flags |= 0x80;

    if (instance->introData != NULL && *((int*)instance->introData) & 0x12) {
        instance->currentMainState = 1;
    }

    if (instance->intro->flags & 0x800) {
        instance->currentMainState = instance->currentMainState != 1;
    }

    if (instance->object->data != NULL && *((int*)instance->object->data) != 0) {
        instance->work1 = 1;
    }

    if (instance->currentMainState == 0 || instance->work1 != 0) {
        instance->currentAnimFrame = 0;
    } else if (instance->object->_0A != 0) {
        instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[0]))[1] - 1;
    }
}

void kungfu_onoff_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    instance->currentTextureAnimFrame = instance->currentMainState ^ 1;

    if (instance->currentSubState == 1) {
        if (instance->currentMainState == 1 || instance->work1 != 0) {
            func_8002DAF8(instance, -1);
        } else {
            func_8002DAF8(instance, -0x3E9);
        }

        if (instance->flags2 & 0x10) {
            instance->flags2 &= ~0x10;
            instance->currentSubState = 0;
            if (instance->currentMainState == 0 || instance->work1 != 0) {
                instance->currentAnimFrame = 0;
            } else if (instance->object->_0A != 0) {
                instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[0]))[1] - 1;
            }
        }
    }
}

extern char D_801626E8_B1908[];

void kungfu_onoff_OnCollide(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    BSPTree* bsp;
    int** list;
    Instance* other;
    int match;
    int toggled;
    int checkState;
    int fire;
    short i;

    match = 0;
    toggled = 0;
    checkState = 0;
    fire = 0;
    intro = instance->introData;
    bsp = instance->bspTree;
    if (intro != NULL && bsp->_06 == 1 && bsp->_0C[5] >= 8U && instance->currentSubState != 1) {
        list = (int**)(intro + 2);
        if (intro[1] == 0) {
            match = 1;
        } else if (intro[1] == 1) {
            if (instance->currentMainState == 0) {
                match = 1;
                checkState = 1;
            }
        } else if (intro[1] == 2) {
            if (instance->currentMainState == 1) {
                match = 1;
                checkState = 1;
            }
        }
        for (i = 0; i < intro[0]; i++, list++) {
            other = ((Intro*)list[0])->instance;
            if (other == NULL) continue;
            if (other->flags & 0x2000000) continue;
            if (match == 0) continue;
            if (checkState != 0) {
                if (!((((unsigned short*)intro)[1] & 1) && !(other->flags & 0x1000000))) {
                    if (!(((unsigned short*)intro)[1] & 2)) continue;
                    if (!(other->flags & 0x1000000)) continue;
                }
            }
            other->flags &= ~0x100000;
            if (!(other->flags2 & 0x10000)) {
                other->flags2 |= 0x1000;
            }
            other->flags |= 0x2000000;
            toggled = 1;
        }
        if ((match != 0 && toggled != 0) || intro[0] == 0) {
            instance->intro->flags ^= 0x800;
            instance->currentMainState ^= 1;
            fire = 1;
        } else if (G2String_Compare_EQ(instance->object->name, D_801626E8_B1908)) {
            fire = 1;
        }
        if (fire != 0) {
            if (instance->object->_0A != 0) {
                instance->currentSubState = 1;
            }
            if (*(int*)list == 0x29A) {
                SIGNAL_HandleSignal(instance, (int*)((int*)list)[1] + 1, 0);
            }
        }
    }
}

void kungfu_spike_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* p = ((short*)&instance->work0);
    int v;
    int t;

    p[0] = 0;
    p[2] = 0x1E;
    p[3] = 0x1E;
    if (instance->introData != 0) {
        *(SVector*)&instance->work0 = *((SVector*)instance->introData);
    }
    t = p[0];
    instance->currentMainState = t;
    if (t == 1) {
        v = ((unsigned short*)instance->object->animList[0])[1] - 1;
    } else {
        v = 0;
    }
    instance->currentAnimFrame = v;
    v = p[1];
    if (v == 0) {
        v = p[2];
    }
    *(int*)&p[4] = v;
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_spike_OnUpdate);

void kungfu_spike_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int frame = instance->currentAnimFrame;
    BSPTree* bsp = instance->bspTree;

    if (frame != 0 && bsp->instanceSpline == gameTracker->player) {
        func_80022714(instance, gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015B5A8_AA7C8);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragon_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_801626DC_B18FC); // launch__

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_801626E8_B1908); // gong____

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_801626EC_B190C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragon_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragflm_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragflm_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_dragflm_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_8015C884_ABAA4);

void kungfu_dragbod_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100400;
}

void func_8015C884_ABAA4(Instance* instance, Instance* arg1, GameTracker* gameTracker);

extern G2String D_80162700_B1920;

void kungfu_dragbod_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Intro** p = ((Intro**)instance->intro->_04);
    int count = ((int*)p)[0];
    int i;
    Intro* entry;

    p += 1;
    for (i = 0; i < count; i++) {
        entry = p[0];
        if (G2String_Compare_EQ(entry->object->name, &D_80162700_B1920)) {
            func_8015C884_ABAA4(instance, entry->instance, gameTracker);
            break;
        }
        p += 1;
    }
}

void kungfu_dragon_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    char c = -1;
    short* p = (short*)&instance->_E0[2];
    if (bsp->_04 == 1) {
        c = bsp->_08[4];
    } else if (bsp->_04 == 5) {
        c = bsp->_08[2];
    }
    if (c == 1) {
        p[0] |= 1;
    } else {
        func_8015C884_ABAA4(instance, instance, gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_cannon_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/KUNGFU", D_80162700_B1920); // draga___

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_cannon_OnUpdate);

void kungfu_canball_OnCreate(Instance* instance, GameTracker* gameTracker) {
    Instance* parent = instance->parent;
    short* p = WORK_AS_PTR(short, parent->work0);

    if (instance->flags & 0x20000) {
        if (instance->object->oflags2 & 4) {
            if (instance->flags2 & 0x2000) {
                instance->flags2 &= ~0x2000;
                func_800331BC(*(int*)&instance->_34[4]);
                *(int*)&instance->_34[4] = 0;
            }
        }
        p[0x18 / 2] -= 1;
    } else {
        instance->flags |= 0x10000;
        WORK_AS_IDX(short, parent->work6, 0) += 1;
    }
}

void kungfu_canball_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    MATRIX m;
    SVECTOR out;
    int spin;

    instance->position.x += instance->_D0[0];
    instance->position.y += instance->_D0[1];
    instance->position.z += instance->_D0[2];
    instance->_D0[2] += instance->_E0[1];
    spin = WORK_AS(int, instance->work3);
    if (spin != 0) {
        instance->work2 += spin;
        MATH3D_SetUnityMatrix(&m);
        RotMatrixX(instance->work0, &m);
        RotMatrixY(instance->work1, &m);
        RotMatrixZ(instance->work2, &m);
        func_800157BC(&m, &out);
        instance->rotation.x = out.x;
        instance->rotation.y = out.y;
        instance->rotation.z = out.z;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_canball_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_cannon_OnCollide);

int func_8015D5E8_AC808(Instance* instance, short dist, SVector* out) {
    SVector start;
    SVector probe;
    int result;
    short deltaS;

    probe = *(SVector*)&instance->position;
    start = probe;
    if (out != NULL) {
        *out = probe;
    }
    start.z += (dist < 0x80) ? 0x80 : dist;
    probe.z -= (dist < 0x80) ? 0x80 : dist;
    result = COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, (SVECTOR*)&probe, (SVECTOR*)&start, instance);
    deltaS = probe.z - instance->position.z;
    if (dist < ((deltaS >= 0) ? deltaS : -deltaS)) return 0;
    if (result == 0) return 0;
    if (func_80047D10(result) != 0) return 0;
    if (out != NULL) {
        *out = probe;
    }
    return 1;
}

short func_8015D770_AC990(Instance* instance, short rotStep, short zStep, short dist, int flag) {
    SVector probe;
    SVECTOR savedPos;
    int result;
    int ok;

    result = 0;
    savedPos = instance->position;
    ok = 1;
    if (rotStep != 0) {
        func_80047E64(instance, rotStep * 2);
        if (func_8015D5E8_AC808(instance, dist, &probe) == 0) {
            ok = 0;
        } else {
            instance->position = savedPos;
            func_80047E64(instance, rotStep);
        }
    }
    if (ok != 0) {
        if (func_8015D5E8_AC808(instance, dist, &probe) == 0) {
            ok = 0;
        }
    }
    if (ok == 0 && flag != 0) {
        instance->position.x = savedPos.x;
        instance->position.y = savedPos.y;
        result |= 2;
    } else if (ok == 0 || instance->position.z + zStep > probe.z) {
        instance->position.x = probe.x;
        instance->position.y = probe.y;
        instance->position.z = instance->position.z + zStep;
    } else {
        instance->position.x = probe.x;
        instance->position.y = probe.y;
        instance->position.z = probe.z;
        result |= 1;
    }
    return result;
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_samuri_OnCreate);

void func_8015DB1C_ACD3C(Instance* instance, short* arg1) {
    int anim;

    anim = 6;
    instance->flags2 &= ~0x10;
    arg1[0x18/2] = 5;
    if (arg1[0x10/2] == 0) {
        anim = 1;
    }
    instance->currentModelAnim = anim;
    instance->currentAnimFrame = 0;
}

void func_8015DB50_ACD70(Instance* instance, short* arg1) {
    instance->flags2 &= ~0x10;
    arg1[0x18/2] = 0;
    if (arg1[8] == 0) {
        instance->currentModelAnim = 2;
        instance->currentAnimFrame = 0;
    } else {
        instance->currentModelAnim = 6;
        instance->currentAnimFrame = 0x3D;
    }
    instance->position = instance->initialPos;
}

void func_8015DBB0_ACDD0(Instance* instance, short* arg1) {
    instance->flags2 &= ~0x10;
    arg1[0x18 / 2] = 1;
    if (instance->currentModelAnim != 0 && instance->currentModelAnim != 5) {
        instance->currentModelAnim = arg1[0x10 / 2] != 0 ? 5 : 0;
        instance->currentAnimFrame = 0;
    }
}

void func_8015DC00_ACE20(Instance* instance, short* arg1) {
    Intro* intro;
    int dx;
    int dy;

    instance->flags2 &= ~0x10;
    arg1[0x18 / 2] = 7;
    if (instance->currentModelAnim != 0 && instance->currentModelAnim != 5) {
        instance->currentModelAnim = (arg1[0x10 / 2] != 0) ? 5 : 0;
        instance->currentAnimFrame = 0;
    }
    intro = instance->intro;
    dx = intro->position.x - instance->position.x;
    dy = intro->position.y - instance->position.y;
    ((int*)arg1)[0x14 / 4] = (short)ratan2(dy, dx);
    arg1[0x1A / 2] = 0;
}

void func_8015DC9C_ACEBC(Instance* instance, GameTracker* gameTracker)
{
    instance->currentModelAnim = 2;
    instance->currentAnimFrame = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_samuri_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_samuri_OnCollide);

void kungfu_boat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    MultiSpline* spline = instance->intro->multiSpline;
    short* p;

    instance->flags |= 0x100000;
    p = ((short*)&instance->work0);
    if (instance->introData != 0) {
        ((short*)&instance->work0)[1] = ((unsigned short*)instance->introData)[1];
    } else {
        ((short*)&instance->work0)[1] = 0x19;
    }
    if (p[1] < 0 && spline != 0) {
        instance->position = *SplineGetLastPoint(spline->positional, &spline->curPositional);
    }
}

SVECTOR* func_800517E4(Spline* spline, short frame, SplineDef* def);

void kungfu_boat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    MultiSpline* ms;
    SVECTOR* point;

    ms = instance->intro->multiSpline;
    if (ms != 0) {
        point = func_800517E4(ms->positional, ((short*)&instance->work0)[1], &ms->curPositional);
        if (point != 0) {
            instance->position.x = point->x;
            instance->position.y = point->y;
            instance->position.z = point->z;
        }
    }
}

void kungfu_boat_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void kungfu_slider_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x100400;
}

void kungfu_slider_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    if (instance->work0 > 0)
    {
        instance->work0--;
    }
}

void kungfu_slider_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int* temp_s1;

    temp_s1 = (int*)PlayerInstance->data;
    if (!(PlayerInstance->work0 & 1) && (instance->work0 == 0)) {
        func_8015AE8C_AA0AC(instance, gameTracker);
        
        instance->work0 = 0x3C;
        temp_s1[0xE0/4] = (int)instance;
        PlayerInstance->work0 &= ~2;
        
        func_8002B7CC(PlayerInstance);

        if (!func_80033220(0x39)) {
            func_80050508(PlayerInstance, 0x39, (short)((rand() & 31) - 15), 0x3C, 2000);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_pend_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_pend_OnUpdate);

void kungfu_pend_OnCollide(Instance* instance, GameTracker* gameTracker) {
    GenericCollide(instance, gameTracker);
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_ninja_OnCreate);

void func_8015F570_AE790(Instance* instance, short* arg1) {
    instance->flags2 &= ~0x10;
    arg1[8] = 5;
    instance->currentModelAnim = 1;
    instance->currentAnimFrame = 0;
}

void func_8015F598_AE7B8(Instance* instance, short* arg1) {
    instance->flags2 &= ~0x10;
    arg1[8] = 1;
    if (instance->currentModelAnim != 0) {
        instance->currentModelAnim = 0;
        instance->currentAnimFrame = 0;
    }
}

void func_8015F5D0_AE7F0(Instance* instance, short* arg1) {
    instance->currentModelAnim = 0;
    instance->currentAnimFrame = 0;
    instance->flags2 &= ~0x10;
    arg1[8] = 0xA;
}

void func_8015F5F4_AE814(Instance* instance, short* arg1) {
    instance->currentModelAnim = 6;
    instance->currentAnimFrame = 0;
    instance->flags2 &= ~0x10;
    arg1[8] = 0xB;
}

void func_8015F61C_AE83C(Instance* instance) {
    if ((instance->flags2 & 0x10) || (unsigned int)(instance->currentModelAnim - 7) >= 2) {
        instance->flags2 &= ~0x10;
        if (rand() % 100 < 0x14) {
            instance->currentModelAnim = 7;
        } else {
            instance->currentModelAnim = 8;
        }
        instance->currentAnimFrame = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_ninja_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_ninja_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_swing_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_swing_OnUpdate);

void kungfu_swing_OnCollide(Instance* instance, GameTracker* gameTracker) {
    func_80022D54(instance, gameTracker);
}

void kungfu_oneway_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* d = ((short*)instance->object->data);
    int r;
    short m;

    ((short*)instance->_D0)[0] = 1;
    instance->flags |= 0x100000;
    r = func_8004A3B4(instance);
    m = 0xA;
    ((short*)instance->_D0)[2] = 0x3C;
    if (d != 0) {
        ((short*)instance->_D0)[2] = d[0];
        m = d[1];
    }
    if (r >= 0) {
        ((short*)instance->_D0)[1] = r * m;
    }
    SCRIPT_InstanceSplineInit(instance, gameTracker);
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_oneway_OnUpdate);

void kungfu_oneway_OnCollide(Instance* instance, GameTracker* gameTracker) {
    func_80022D54(instance, gameTracker);
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80160D4C_AFF6C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80160E4C_B006C);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_80160F68_B0188);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_joyride_OnCreate);

void func_8016121C_B043C(Instance* instance, GameTracker* gameTracker) {
    Instance* player;

    player = gameTracker->player;
    func_8004AEC8(instance, 0, 0, 0x80, (SVECTOR*)((short*)instance->_D0 + 5));
    player->position = *(SVECTOR*)((short*)instance->_D0 + 5);
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_joyride_OnUpdate);

void kungfu_joyride_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* player = gameTracker->player;
    BSPTree* bsp = instance->bspTree;

    if (bsp->instanceSpline == player) {
        ((short*)instance->_D0)[0] |= 1;
    }
    if (*(short*)&instance->_D0[2] == 0) {
        if (bsp->_04 == 1) {
            func_8004AEC8(instance, 0, 0, 0x80, (SVECTOR*)((short*)instance->_D0 + 5));
            *(short*)&instance->_D0[2] = 1;
            gameTracker->gameFlags |= 1;
        }
        player->currentMainState = 5;
    } else if (*(short*)&instance->_D0[2] == 3) {
        func_80022D54(instance, gameTracker);
    }
}

void kungfu_leafgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
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
    p[0] = ((long)OBTABLE_FindObject(targetObjectName));
    p[7] = (rand() & 0xF) + 1;
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", func_801616D4_B08F4);

void func_80161944_B0B64(short* arg0) {
    func_800162C0(arg0);
    RotMatrixX(((short*)arg0)[0x44/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixY(((short*)arg0)[0x46/2], (char*)((int*)arg0)[5] + 0xC);
    RotMatrixZ(((short*)arg0)[0x48/2], (char*)((int*)arg0)[5] + 0xC);
}

extern int D_80078244;
extern int D_800EB8A0;
extern void func_801616D4_B08F4();

void func_801619A4_B0BC4(Instance* instance, int arg1, int arg2) {
    Model* model;

    if (instance->work0 != 0) {
        model = ((Object*)instance->work0)->modelList[0];
        D_80078244 = (rand() & 3) + 2;
        func_800170E8(model, model->_14 + 0xC, arg2, 0, 0, D_800EB8A0, func_801616D4_B08F4, func_80161944_B0B64, 0x28);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_leafgen_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/KUNGFU", kungfu_leafgen_OnCollide);

extern int D_801626C0_B18E0[];
void kungfu_funplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVector newPoint;
    SVector oldPoint;

    if (instance->introData == 0) {
        instance->introData = (void*)D_801626C0_B18E0;
    }
    newPoint.x = oldPoint.x = instance->position.x;
    newPoint.y = oldPoint.y = instance->position.y;
    newPoint.z = instance->_E0[2] = instance->position.z;
    oldPoint.z = instance->_40[6] + 0x80;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, (SVECTOR*)&newPoint, (SVECTOR*)&oldPoint, instance);
}

void kungfu_funplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void kungfu_funplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void kungfu_brkbone_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void kungfu_brkbone_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void kungfu_brkbone_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (func_80027500(instance->bspTree, gameTracker)) {
        if (instance->object->_08 >= 2) {
            instance->currentModel = 1;
        }
        INSTANCE_PlainDeath(instance, 5, -1, 0);
    }
}

void kungfu_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

void kungfu_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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