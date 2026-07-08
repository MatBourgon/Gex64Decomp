#include "common.h"

#include "level/REZOP.h"
#include "INSTANCE.h"
#include "OBTABLE.h"
#include "SIGNAL.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"

extern int D_800E5FD8;
extern int D_80154834;

void rezop_rrdoor_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rrdoor_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int data;
    int data2;
    int off;

    if (instance->_F4[0] == 1) {
        data = instance->object->modelList[0]->_14;
        off = instance->_F4[2] * 0xC;
        if (*(int*)(off + data + 8) != *(int*)(data + 0x1E8)) {
            *(int*)(off + data + 8) = *(int*)(data + 0x1E8);
            data2 = instance->object->modelList[0]->_14;
            *(int*)(off + data2 + 0x14) = *(int*)(data2 + 0x1F4);
        }
        instance->_F4[0] = 0;
    }
}

void rezop_rrdoor_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rrspark_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrspark_OnUpdate);

void rezop_rrspark_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rezrat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[0] = 0;
    instance->flags |= 0x100400;
    func_8004AAA8(instance, 0x18, 0);
}

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161530_D9CA0);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161558_D9CC8);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezrat_OnUpdate);

void rezop_rezrat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    extern int D_800EB8A0;
    BSPTree* bsp;

    bsp = instance->bspTree;
    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player
        && bsp->_0C[5] >= 6U && instance->_F4[0] != 2) {
        if (((Instance*)instance->_11C)->_100 >= 0x14) {
            func_80017598(instance, 0, 0, 0, D_800EB8A0, 0, 0);
            INSTANCE_KillInstance(instance);
        } else {
            instance->_F4[0] = 2;
            func_80017598(instance, 0, 0, 0, D_800EB8A0, 0, 0);
            instance->flags |= 0x800;
        }
    }
}

void rezop_rrgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    char* intro;
    Object* obj;
    Instance* birthed;

    intro = instance->introData;
    obj = OBTABLE_FindObject("rrzap___");
    instance->_F4[0] = 2;
    instance->flags |= 0x100080;
    if (*(short*)(intro + 8) != 0) {
        instance->_F4[0] = 1;
    } else {
        instance->_F4[2] = *(short*)(intro + 6);
    }
    instance->_100 = 1;
    instance->_104 = 1;
    birthed = INSTANCE_BirthObject(instance, obj);
    birthed->position.z += 0x180;
    *(Instance**)&instance->_108 = birthed;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrgen_OnUpdate);

void rezop_rrgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rrzap_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[2] = 0x20;
    instance->flags |= 0x100080;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrzap_OnUpdate);

void rezop_rrzap_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rezplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentTextureAnimFrame = 1;
    instance->_104 = 7;
    instance->flags |= 0x80;
    *(int*)&instance->_108 = instance->rotation.y;
    *(short*)&instance->_10C = instance->rotation.z;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnCollide);

void rezop_tbbttn_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbbttn_OnUpdate);

void rezop_tbbttn_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;
    short six;
    int state;
    int* list;

    bsp = instance->bspTree;
    six = bsp->_06;
    if (six == 1 && bsp->instanceSpline == gameTracker->player
        && (PlayerInstance->_F4[1] == 0x80 || PlayerInstance->_F4[1] == 0x20)) {
        state = instance->_F4[0];
        if (state != 3 && bsp->_0C[4] == 9) {
            if (state != six) {
                func_80050508(instance, 0xB4, 0, 0x5A, 0x9C4);
            }
            instance->scale.z = 0x400;
            instance->_F4[0] = six;
            list = instance->intro->_04;
            ((Intro**)list)[list[0]]->instance->_F4[0] = six;
        }
    }
}

void rezop_tbplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbplat_OnUpdate);

void rezop_tbplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezfan_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezfan_OnUpdate);

void rezop_rezfan_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_simontv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_100 = instance->intro->_04[1];
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simontv_OnUpdate);

void rezop_simontv_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;
    char* d;
    char* d2;
    short t;

    bsp = instance->bspTree;
    d = ((Instance*)instance->_100)->introData;
    d2 = ((char**)d)[9];
    if (bsp->_06 == 4 && bsp->instanceSpline == PlayerInstance && instance->_F4[0] == 0) {
        if (*(int*)(d + 0xF4) == 0 || (t = *(short*)(d2 + 8)) != 1) {
            *(int*)(d + 0xF4) = 1;
            instance->_F4[1] = 1;
        } else if (instance->_F4[1] != t) {
            func_80050508(instance, 0xAE, 0, 0x64, 0xFA0);
        }
    }
}

void rezop_simon_OnCreate(Instance* instance, GameTracker* gameTracker) {
    char* intro;

    intro = instance->introData;
    instance->_100 = (instance->intro->_04[0] - 2) / 2;
    instance->_F4[0] = 0;
    instance->_104 = 0;
    *(int*)&instance->_114 = *(int*)(((short)(rand() % *(short*)(intro + 0xA)) << 2) + *(int*)(intro + 0xC));
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015B750_D3EC0);

void func_8015B9AC_D411C(short* arg0) {
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

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015BA40_D41B0);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simon_OnUpdate);

void rezop_simon_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rezbot_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[2] = PlayerInstance->position.z + 0x282;
    instance->currentModelAnim = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnCollide);

void rezop_crnkplt_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR a;
    SVECTOR b;

    a.x = b.x = instance->position.x;
    a.y = b.y = instance->position.y;
    a.z = (unsigned short)instance->position.z - 0x100;
    b.z = (unsigned short)instance->position.z + 0x100;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, &a, &b, instance);
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_crnkplt_OnUpdate);

void rezop_crnkplt_OnCollide(Instance* instance, GameTracker* gameTracker) {
    GenericCollide(instance, gameTracker);
}

void rezop_rezcrnk_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rezcrnk_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int t;

    if (instance->_F4[0] == 1) {
        t = instance->_F4[2];
        if (t > 0) {
            instance->_F4[2] = t - 0x10;
            if (instance->_F4[2] < 0) {
                instance->_F4[2] = 0;
            }
        } else if (t == 0) {
            instance->_F4[0] = 0;
        }
        instance->rotation.z = (unsigned short)instance->rotation.z + instance->_F4[2];
    }
    if (instance->_100 >= 0) {
        instance->_100 = instance->_100 - 1;
    }
}

void rezop_rezcrnk_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;
    short* intro;
    int* sig;
    short six;
    int t;

    bsp = instance->bspTree;
    six = bsp->_06;
    intro = instance->introData;
    if (six == 1 && bsp->instanceSpline == PlayerInstance && bsp->_0C[5] >= 6U && instance->_100 <= 0) {
        instance->_100 = intro[2];
        sig = ((int**)intro)[0];
        if (sig != NULL) {
            COLLIDE_HandleSignal(gameTracker->player, (BaseSignal*)(sig + 1), sig[0], 0);
        }
        t = instance->_F4[2];
        instance->_F4[0] = six;
        instance->flags2 |= 0x400000;
        if (t < 0x180) {
            instance->_F4[2] = t + 0x100;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_snkplat_OnCreate);

void rezop_snkplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int d[2];
    SVector dead; /* dead local — reproduces the original's 0x30-byte frame */

    instance->_D0[2] += 0x20;
    instance->_D0[0] = instance->position.x + (((func_8003A6AC(instance->_D0[2]) << 16) >> 16) * 0xF >> 6);
    instance->_D0[1] = instance->position.y + (((func_8003A4E0(instance->_D0[2]) << 16) >> 16) * 0xF >> 6);
    d[0] = instance->_D0[0] - instance->position.x;
    d[1] = instance->_D0[1] - instance->position.y;
    instance->rotation.x = d[0] >> 3;
    instance->rotation.y = d[1] >> 3;
    GenericProcess(instance, gameTracker);
}

void rezop_snkplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((bsp->_06 == 4) && (bsp->instanceSpline == PlayerInstance)) {
        GenericCollide(instance, gameTracker);
    }
}

void rezop_rezbull_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_E0[1] = -0xF;
    instance->_F4[0] = 0;
    instance->_D0[2] = 0x3C;
    *(int*)&instance->_108 = 0x3C;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnCollide);

void rezop_srchlit_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* fc;
    short* intro;
    short i;

    fc = (short*)&instance->_F4[2];
    intro = instance->introData;
    for (i = 0; i < gameTracker->level->_68; i++) {
        if (*(int*)((char*)gameTracker->level->_6C + i * 12) == intro[0]) {
            fc[0] = i;
        }
    }
    fc[1] = ((unsigned short*)intro)[1];
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_srchlit_OnUpdate);

void rezop_srchlit_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_spotlit_OnCreate(Instance* instance, GameTracker* gameTracker) {
    *(short*)&instance->_F4[2] = (unsigned char)PlayerInstance->lightGroup;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spotlit_OnUpdate);

void rezop_spotlit_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_spnplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;
    Intro* other;
    Instance* birthed;

    intro = instance->introData;
    if (!(intro[0] & 2)) {
        other = ((Intro*)intro[1]);
        intro[0] |= 1;
        other->flags |= 0x10;
        birthed = INSTANCE_BirthObjectFromIntro(other);
        intro[2] = (int)birthed;
        ((int*)birthed->introData)[0] |= 2;
        OBTABLE_InstanceInit(birthed);
        ((Instance**)birthed->introData)[2] = instance;
    }
    instance->_F4[2] = 1;
    instance->_F4[0] = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnCollide);

void rezop_mutant_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;
    int f;
    int v;

    intro = instance->introData;
    f = instance->flags;
    if (f & 0x20000) {
        if (instance->currentModelAnim == 0) {
            instance->intro->flags |= 8;
        }
    } else {
        instance->flags = f | 0x100000;
        if (intro == NULL || *intro == 0) {
            v = 0x384000;
        } else {
            v = *intro;
        }
        instance->_F4[2] = v;
        instance->currentModelAnim = 4;
        instance->flags2 &= ~0x10;
        instance->flags |= 0x10000;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015E950_D70C0);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015EAB0_D7220);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", func_8015ECB8_D7428);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161590_D9D00);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_mutant_OnUpdate);

void rezop_mutant_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;
    int v;

    bsp = instance->bspTree;
    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player) {
        if (bsp->_0C[5] >= 6U) {
            if (instance->_F4[0] == 3) {
                func_8002275C(instance, gameTracker);
            } else {
                v = instance->currentModelAnim;
                instance->_F4[0] = 5;
                if (v == 4) {
                    instance->currentModelAnim = 0;
                    instance->currentAnimFrame = 0;
                } else if (v == 0) {
                    if (instance->currentAnimFrame >= 0x15) {
                        instance->currentAnimFrame = 0;
                        instance->flags2 &= ~0x10;
                    }
                } else {
                    instance->currentAnimFrame = 0;
                    instance->currentModelAnim = 0;
                    instance->flags2 &= ~0x10;
                }
            }
        } else if (instance->_F4[0] == 3) {
            func_80022714(instance, gameTracker);
        }
    }
}

void rezop_mtntsht_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->initialPos = instance->position;
    *(ROTATION*)&instance->intro->rotation = instance->rotation;
    instance->flags |= 0x100000;
}

void rezop_mtntsht_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short dx;
    short dy;

    dx = instance->position.x - instance->initialPos.x;
    dy = instance->position.y - instance->initialPos.y;
    if (((short*)&instance->_F4[2])[1] * ((short*)&instance->_F4[2])[1] < dx * dx + dy * dy) {
        INSTANCE_PlainDeath(instance, 4, -1, 0);
    }
    func_80047E64(instance, ((short*)&instance->_F4[2])[0]);
}

void rezop_mtntsht_OnCollide(Instance* instance, GameTracker* gameTracker) {
    extern char D_801615AC_D9D1C[];
    BSPTree* bsp;

    bsp = instance->bspTree;
    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player) {
        if (!(gameTracker->gameFlags & 4)) {
            func_8002275C(instance, gameTracker);
        }
        INSTANCE_PlainDeath(instance, 4, -1, 0);
    } else if (bsp->instanceSpline == NULL) {
        INSTANCE_PlainDeath(instance, 4, -1, 0);
    } else if (G2String_Compare_NEQ(bsp->instanceSpline->object->parentName, D_801615AC_D9D1C)) {
        INSTANCE_PlainDeath(instance, 4, -1, 0);
    }
}

void rezop_rebggen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100000;
}

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_801615AC_D9D1C);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_801615B0_D9D20);

void rezop_rebggen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    Object* obj;
    Instance* birthed;

    if (instance->_F4[0] == 1) {
        obj = OBTABLE_FindObject("rebug___");
        birthed = INSTANCE_BirthObject(instance, obj);
        if (birthed != NULL) {
            birthed->rotation.z = (unsigned short)birthed->rotation.z + 0x400;
            obj->oflags |= 0x2000;
            birthed->introData = NULL;
        }
        instance->_F4[0] = 0;
    }
}

void rezop_rebggen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rbmastr_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rbmastr_OnUpdate);

void rezop_rbmastr_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rebug_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x400;
}

void rezop_rebug_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int ox;
    int oy;

    if (instance->_F4[0] != 1) {
        ox = instance->oldPos.x;
        oy = instance->oldPos.y;
        instance->rotation.z = ratan2(oy - instance->position.y, ox - instance->position.x) + 0x400;
        func_8002DAF8(instance, -1);
    } else if (instance->currentAnimFrame != ((short*)instance->object->animList[instance->currentModelAnim])[1] - 1) {
        func_8002DAF8(instance, -1);
    } else {
        INSTANCE_PlainDeath(instance, 4, -1, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rebug_OnCollide);

void rezop_iris_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* data;
    int x;
    int y;

    data = ((unsigned short*)instance->object->data);
    ((short*)&instance->_100)[1] = (short)data[0] / 2;
    *(short*)&instance->_104 = -((short)data[0] / 2);
    *(short*)&instance->_10E = data[3];
    ((short*)&instance->_104)[1] = (short)data[1] / 2 + 0x140;
    x = -0x140 - (short)data[1] / 2;
    *(short*)&instance->_108 = x;
    y = data[2];
    x = -0x40;
    *(short*)&instance->_10C = x;
    ((short*)&instance->_F4[2])[1] = 0;
    ((short*)&instance->_108)[1] = x - y;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_iris_OnUpdate);

void rezop_iris_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_tvgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[0] = 0;
    instance->flags |= 0x100800;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgen_OnUpdate);

void rezop_tvgurny_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR a;
    SVECTOR b;

    instance->flags |= 0x40000000;
    a.x = instance->position.x;
    a.y = instance->position.y;
    b.x = (unsigned short)instance->position.x + (((func_8003A6AC(instance->intro->rotation.z + 0x400) << 16) >> 16) * 5 >> 4);
    b.y = (unsigned short)instance->position.y + (((func_8003A4E0(instance->intro->rotation.z + 0x400) << 16) >> 16) * 5 >> 4);
    a.z = b.z = instance->position.z;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, &a, &b, instance);
    instance->_120 = (SCRIPT_CountFramesInSpline(instance) << 16) >> 16;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tvgurny_OnUpdate);

void rezop_tvgurny_OnCollide(Instance* instance, GameTracker* gameTracker) {
    GenericCollide(instance, gameTracker);
}

typedef struct {
    short _00;
    short _02;
    short _04;
    short _06;
} GasData;

void rezop_gas_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int t;
    unsigned short* introData;
    char* fc;
    void* data;
    int r;
    unsigned int m;

    t = 0;
    introData = ((unsigned short*)instance->introData);
    data = instance->data;
    fc = (char*)&instance->_F4[2];
    if (instance->flags & 0x20000) {
        if (instance->_F4[0] == 5) {
            func_800331BC(instance->_104);
        }
    } else {
        *(GasData*)&instance->_F4[2] = *(GasData*)data;
        r = rand();
        instance->flags |= 0x80;
        instance->currentTextureAnimFrame = r % 24;
        if (introData != NULL) {
            if (introData[0] != 0xFFFF) {
                *(GasData*)&instance->_F4[2] = *(GasData*)(introData + 1);
                if (((char*)&instance->_100)[2] < 0) {
                    *(int*)&instance->_108 |= 0x8000;
                    ((char*)&instance->_100)[2] = ~((unsigned char*)&instance->_100)[2];
                }
                t = func_8004A61C(instance);
                m = introData[0];
                m %= (unsigned int)(((unsigned short*)&instance->_F4[2])[1] + *(unsigned short*)&instance->_F4[2] + ((unsigned char*)&instance->_100)[1]);
                if (m < ((unsigned short*)&instance->_F4[2])[1]) {
                    *(short*)&instance->_108 = m;
                    instance->_F4[0] = 0;
                } else {
                    m -= ((unsigned short*)&instance->_F4[2])[1];
                    if (m < ((unsigned char*)&instance->_100)[1]) {
                        *(short*)&instance->_108 = m;
                        instance->_F4[0] = 1;
                    } else {
                        m -= ((unsigned char*)&instance->_100)[1];
                        if (m < t) {
                            instance->_F4[0] = 2;
                            t = m;
                        } else {
                            m -= t;
                            if (m < *(unsigned short*)&instance->_F4[2]) {
                                *(short*)&instance->_108 = m;
                                instance->_F4[0] = 3;
                            } else {
                                m -= *(unsigned short*)&instance->_F4[2];
                                if (m < t) {
                                    instance->_F4[0] = 4;
                                    t = t - m;
                                } else {
                                    t = 0;
                                }
                            }
                        }
                    }
                }
            } else {
                instance->_F4[0] = 5;
                t = func_8004A61C(instance) - 1;
                instance->flags |= 0x10000;
            }
        }
        if (fc[6] >= 3) {
            fc[6] = 2;
        }
        func_8004A7B8(instance, fc[6], t);
    }
}

void rezop_gas_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* fc;
    unsigned short x;
    unsigned short y;
    int w;

    fc = (unsigned short*)&instance->_F4[2];
    x = *(unsigned short*)&instance->_108;
    y = instance->currentTextureAnimFrame;
    *(unsigned short*)&instance->_108 = x + 1;
    w = *(int*)&instance->_108;
    instance->currentTextureAnimFrame = y + 1;
    if (w & 0x8000) {
        instance->rotation.z = ((unsigned short)instance->rotation.z + 0x2200) & 0xFFF;
    }
    switch (instance->_F4[0]) {
    case 0:
        if (fc[6] >= fc[1]) {
            fc[6] = 0;
            instance->_F4[0] = 1;
            instance->_F4[1] = 2;
            instance->flags2 &= ~0x10;
        }
        break;
    case 1:
        if (fc[6] >= ((unsigned char*)fc)[5]) {
            fc[6] = 0;
            instance->_F4[0] = 2;
            instance->flags2 &= ~0x10;
            instance->flags |= 0x400;
        } else if (instance->_F4[1] == 2) {
            func_8004A820(instance, 0);
            if (instance->currentAnimFrame >= ((unsigned char*)fc)[4]) {
                instance->_F4[1] = 4;
                instance->currentAnimFrame = ((unsigned char*)fc)[4];
            } else if (instance->flags2 & 0x10) {
                instance->_F4[1] = 4;
            }
        } else if (instance->_F4[1] == 4) {
            func_8004A8A8(instance, 0);
            if (instance->flags2 & 0x10) {
                instance->_F4[1] = 0;
            }
            instance->flags2 &= ~0x10;
        }
        break;
    case 2:
        func_8004A820(instance, 0);
        if (instance->flags2 & 0x10) {
            fc[6] = func_8004A61C(instance);
            instance->_F4[0] = 3;
        }
        break;
    case 3:
        if (fc[6] >= fc[0]) {
            fc[6] = 0;
            instance->_F4[0] = 4;
            instance->flags2 &= ~0x10;
        }
        break;
    case 4:
        func_8004A8A8(instance, 0);
        if (instance->flags2 & 0x10) {
            fc[6] = func_8004A61C(instance);
            instance->_F4[0] = 0;
            func_800331BC(((int*)fc)[2]);
            instance->flags &= ~0x400;
        }
        break;
    case 5:
        break;
    }
}

void rezop_gas_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* bspPlayer;
    int playerState;

    bspPlayer = instance->bspTree->instanceSpline;
    playerState = (int)gameTracker->player;
    if (bspPlayer->object != NULL && bspPlayer == (Instance*)playerState
        && instance->_F4[0] >= 2 && func_80027578(instance, gameTracker, bspPlayer) == 0) {
        playerState = PlayerInstance->_F4[1];
        if (playerState != 0x200000 && playerState != 0x10 && playerState != 0x2000) {
            func_800223F8(gameTracker8, 0x78, 0);
        }
    }
}

void rezop_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

extern char D_80161590_D9D00[];

void rezop_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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
                SIGNAL_HandleSignal(PlayerInstance, (void*)(intro->b + 4), 0);
            }
            instance->_F4[1] = 1;
            PlayerInstance->_F4[2] &= ~0x400000;
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
                    sprintf(buffer, D_80161590_D9D00, minutesLeft);  // "%d" — emitted earlier in this TU by a still-undecompiled function (INCLUDE_RODATA blob); a literal here would duplicate it and shift .rodata
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

void rezop_markey_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void rezop_markey_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    extern int D_800E5CD8;
    int* data;
    char* q;
    char v;
    char w;

    data = ((int*)instance->object->modelList[0]->_14);
    v = D_800E5CD8 & 0x7F;
    w = v + 0x7F;
    q = ((char*)data[2]);
    q[4] = w;
    q[6] = v;
    q[8] = w;
    q = ((char*)data[5]);
    q[4] = w;
    q[6] = v;
    q[8] = v;
}
