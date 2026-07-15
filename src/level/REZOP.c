#include "common.h"

#include "level/REZOP.h"
#include "INSTANCE.h"
#include "OBTABLE.h"
#include "SIGNAL.h"
#include "SPLINE.h"
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

    if (instance->currentMainState == 1) {
        data = instance->object->modelList[0]->_14;
        off = instance->work0 * 0xC;
        if (*(int*)(off + data + 8) != *(int*)(data + 0x1E8)) {
            *(int*)(off + data + 8) = *(int*)(data + 0x1E8);
            data2 = instance->object->modelList[0]->_14;
            *(int*)(off + data2 + 0x14) = *(int*)(data2 + 0x1F4);
        }
        instance->currentMainState = 0;
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
    instance->currentMainState = 0;
    instance->flags |= 0x100400;
    func_8004AAA8(instance, 0x18, 0);
}

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161530_D9CA0);

INCLUDE_RODATA("asm/nonmatchings/level/REZOP", D_80161558_D9CC8);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezrat_OnUpdate);

extern int D_800EB8A0;
void rezop_rezrat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->_06 == 1 && instance->bspTree->instanceSpline == gameTracker->player
        && instance->bspTree->_0C[5] >= 6U && instance->currentMainState != 2) {
        if (((Instance*)instance->work8)->work1 >= 0x14) {
            func_80017598(instance, 0, 0, 0, D_800EB8A0, 0, 0);
            INSTANCE_KillInstance(instance);
        } else {
            instance->currentMainState = 2;
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
    instance->currentMainState = 2;
    instance->flags |= 0x100080;
    if (*(short*)(intro + 8) != 0) {
        instance->currentMainState = 1;
    } else {
        instance->work0 = *(short*)(intro + 6);
    }
    instance->work1 = 1;
    instance->work2 = 1;
    birthed = INSTANCE_BirthObject(instance, obj);
    birthed->position.z += 0x180;
    WORK_AS(Instance*, instance->work3) = birthed;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rrgen_OnUpdate);

void rezop_rrgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rrzap_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->work0 = 0x20;
    instance->flags |= 0x100080;
}

void rezop_rrzap_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    unsigned short t;

    if (instance->currentMainState == 0) {
        if (*(int*)&instance->position.x != *(int*)&PlayerInstance->position.x) {
            t = ((unsigned short*)&instance->work0)[1];
            func_80049B80(instance, &t, 0x100, 0xDDB, 0x100, &PlayerInstance->position, 0x100);
        }
        instance->currentTextureAnimFrame = ((Instance*)instance->parent)->work9;
        if (instance->parent->work9 == 5) {
            instance->currentMainState = 1;
            gameTracker->player->flags |= 0x100;
        }
    } else if (instance->currentMainState == 1) {
        if (instance->work1 == 0) {
            func_80022714(instance, gameTracker);
        }
        instance->work1 = instance->work1 + 1;
        if (instance->work1 == 0x3C) {
            instance->currentMainState = 0;
            instance->work1 = 0;
            PlayerInstance->flags &= ~0x100;
        }
    }
}

void rezop_rrzap_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rezplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentTextureAnimFrame = 1;
    instance->work2 = 7;
    instance->flags |= 0x80;
    WORK_AS(int, instance->work3) = instance->rotation.y;
    WORK_AS_IDX(short, instance->work4, 0) = instance->rotation.z;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezplat_OnCollide);

void rezop_tbbttn_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbbttn_OnUpdate);

void rezop_tbbttn_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int state;
    int* list;
    BSPTree* bsp = instance->bspTree;
    short six = bsp->_06;

    if (six == 1 && bsp->instanceSpline == gameTracker->player
        && (PlayerInstance->currentSubState == 0x80 || PlayerInstance->currentSubState == 0x20)) {
        state = instance->currentMainState;
        if (state != 3 && bsp->_0C[4] == 9) {
            if (state != six) {
                func_80050508(instance, 0xB4, 0, 0x5A, 0x9C4);
            }
            instance->scale.z = 0x400;
            instance->currentMainState = six;
            list = instance->intro->_04;
            ((Intro**)list)[list[0]]->instance->currentMainState = six;
        }
    }
}

void rezop_tbplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100000;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_tbplat_OnUpdate);

void rezop_tbplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_rezfan_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* intro = ((short*)instance->introData);
    int f;

    instance->currentMainState = 0;
    instance->flags |= 0x100000;
    if (intro[0] != 0) {
        instance->currentMainState = 1;
    } else {
        instance->work0 = intro[1];
    }
    instance->work1 = 0;
    if (intro[4] != 0) {
        instance->work8 = intro[4];
    } else {
        instance->work8 = 0x118;
    }
    if (intro[5] != 0) {
        instance->work9 = intro[5];
    } else {
        instance->work9 = -0x118;
    }
    f = instance->flags;
    if (f & 0x20000) {
        if (instance->work2 != 0) {
            func_800331BC(instance->work2);
            instance->work2 = 0;
        }
    } else {
        instance->flags = f | 0x10000;
        instance->work2 = 0;
        WORK_AS(int, instance->work5) = 0;
        WORK_AS(int, instance->work4) = 0x64;
        WORK_AS(int, instance->work3) = (rand() & 0x3F) - 0x20;
        WORK_AS(int, instance->work6) = 0;
        instance->work7 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezfan_OnUpdate);

void rezop_rezfan_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_simontv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->work1 = instance->intro->_04[1];
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_simontv_OnUpdate);

void rezop_simontv_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    Instance* other = ((Instance*)instance->work1)->introData;
    short* otherIntro = other->introData;

    if (bsp->_06 == 4 && bsp->instanceSpline == PlayerInstance && instance->currentMainState == 0) {
        if (other->currentMainState == 0 || otherIntro[4] != 1) {
            other->currentMainState = 1;
            instance->currentSubState = 1;
        } else if (instance->currentSubState != otherIntro[4]) {
            func_80050508(instance, 0xAE, 0, 0x64, 0xFA0);
        }
    }
}

void rezop_simon_OnCreate(Instance* instance, GameTracker* gameTracker) {
    char* intro;

    intro = instance->introData;
    instance->work1 = (instance->intro->_04[0] - 2) / 2;
    instance->currentMainState = 0;
    instance->work2 = 0;
    WORK_AS(int, instance->work6)= *(int*)(((short)(rand() % *(short*)(intro + 0xA)) << 2) + *(int*)(intro + 0xC));
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
    instance->work0 = PlayerInstance->position.z + 0x282;
    instance->currentModelAnim = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbot_OnCollide);

void rezop_crnkplt_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR a;
    SVECTOR b;

    a.x = b.x = instance->position.x;
    a.y = b.y = instance->position.y;
    a.z = instance->position.z - 0x100;
    b.z = instance->position.z + 0x100;
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

    if (instance->currentMainState == 1) {
        t = instance->work0;
        if (t > 0) {
            instance->work0 = t - 0x10;
            if (instance->work0 < 0) {
                instance->work0 = 0;
            }
        } else if (t == 0) {
            instance->currentMainState = 0;
        }
        instance->rotation.z += instance->work0;
    }
    if (instance->work1 >= 0) {
        instance->work1 = instance->work1 - 1;
    }
}

void rezop_rezcrnk_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int* sig;
    int t;
    short six = instance->bspTree->_06;
    short* intro = instance->introData;

    if (six == 1 && instance->bspTree->instanceSpline == PlayerInstance && instance->bspTree->_0C[5] >= 6U && instance->work1 <= 0) {
        instance->work1 = intro[2];
        sig = ((int**)intro)[0];
        if (sig != NULL) {
            COLLIDE_HandleSignal(gameTracker->player, (BaseSignal*)(sig + 1), sig[0], 0);
        }
        t = instance->work0;
        instance->currentMainState = six;
        instance->flags2 |= 0x400000;
        if (t < 0x180) {
            instance->work0 = t + 0x100;
        }
    }
}

void rezop_snkplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    int* d;
    SVECTOR a;
    SVECTOR b;

    intro = instance->introData;
    instance->flags |= 0x100000;
    a.x = b.x = instance->position.x;
    a.y = b.y = instance->position.y;
    d = instance->_D0;
    a.z = instance->position.z;
    b.z = instance->position.z + 0x300;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, &a, &b, instance);
    if (intro != NULL) {
        instance->_D0[2] = intro[0];
    } else {
        instance->_D0[2] = 0;
    }
    d[0] = instance->position.x + (((short)func_8003A6AC(d[2])) * 0xF >> 6);
    d[1] = instance->position.y + (((short)func_8003A4E0(d[2])) * 0xF >> 6);
}

void rezop_snkplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    LVECTOR d;

    instance->_D0[2] += 0x20;
    instance->_D0[0] = instance->position.x + (((short)func_8003A6AC(instance->_D0[2])) * 0xF >> 6);
    instance->_D0[1] = instance->position.y + (((short)func_8003A4E0(instance->_D0[2])) * 0xF >> 6);
    d.x = instance->_D0[0] - instance->position.x;
    d.y = instance->_D0[1] - instance->position.y;
    instance->rotation.x = d.x >> 3;
    instance->rotation.y = d.y >> 3;
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
    instance->currentMainState = 0;
    instance->_D0[2] = 0x3C;
    WORK_AS(int, instance->work3) = 0x3C;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_rezbull_OnUpdate);

extern int D_800EB8A0;
void rezop_rezbull_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    SVECTOR out;
    int px;

    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player
        && bsp->_0C[5] >= 6U && instance->currentMainState != 5) {
        px = instance->position.x;
        instance->work0 = (short)ratan2(instance->position.y - PlayerInstance->position.y,
                                   px - PlayerInstance->position.x);
        instance->work1 = 0x20;
        instance->currentMainState = 4;
    } else if (bsp->_06 == 2) {
        if (instance->currentMainState == bsp->_06) {
            func_8004AAE4(bsp, &out, gameTracker);
            if (out.z >= 0xED9) {
                WORK_AS(Instance*, instance->work2) = bsp->instanceSpline;
            }
        }
    } else if (bsp->_06 == 3 && (*(unsigned short*)&bsp->_0C[6] & 8)) {
        instance->position.z += 0x500;
        func_80017598(instance, 0, 0, 0, D_800EB8A0, 0, 0);
        INSTANCE_KillInstance(instance);
    }
}

void rezop_srchlit_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* fc;
    short* intro;
    short i;

    fc = (short*)&instance->work0;
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
    *(short*)&instance->work0 = (unsigned char)PlayerInstance->lightGroup;
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
    instance->work0 = 1;
    instance->currentMainState = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_spnplat_OnUpdate);

void rezop_spnplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int* intro = instance->introData;
    BSPTree* bsp = instance->bspTree;
    Instance* other;

    if ((unsigned int)(instance->currentMainState - 3) >= 2U) {
        if (bsp->instanceSpline == gameTracker->player) {
            instance->currentSubState = 1;
            instance->currentMainState = instance->work0;
        } else if (bsp->_06 == 3 && instance->work2 == 0) {
            instance->work2 = 1;
            instance->position.x += (unsigned short)bsp->localOffset.x * 2;
            instance->position.y += (unsigned short)bsp->localOffset.y * 2;
            instance->position.z += (unsigned short)bsp->localOffset.z * 2;
            COLLIDE_UpdateAllTransforms(instance, &bsp->localOffset, gameTracker);
            other = ((Instance*)intro[2]);
            if (other->work0 == 1) {
                other->work0 = 2;
            } else {
                other->work0 = 1;
            }
            other = ((Instance*)intro[2]);
            other->currentMainState = other->work0;
        }
    }
}

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
        instance->work0 = v;
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
    if (instance->bspTree->_06 != 1 || instance->bspTree->instanceSpline != gameTracker->player)
        return;

    if (instance->bspTree->_0C[5] >= 6U) {
        if (instance->currentMainState == 3) {
            func_8002275C(instance, gameTracker);
            return;
        }
            
        instance->currentMainState = 5;
        if (instance->currentModelAnim == 4) {
            instance->currentModelAnim = 0;
            instance->currentAnimFrame = 0;
        } else if (instance->currentModelAnim == 0) {
            if (instance->currentAnimFrame >= 0x15) {
                instance->currentAnimFrame = 0;
                instance->flags2 &= ~0x10;
            }
        } else {
            instance->currentAnimFrame = 0;
            instance->currentModelAnim = 0;
            instance->flags2 &= ~0x10;
        }
    } else if (instance->currentMainState == 3) {
        func_80022714(instance, gameTracker);
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
    if (((short*)&instance->work0)[1] * ((short*)&instance->work0)[1] < dx * dx + dy * dy) {
        INSTANCE_PlainDeath(instance, 4, -1, 0);
    }
    func_80047E64(instance, ((short*)&instance->work0)[0]);
}

extern char D_801615AC_D9D1C[];
void rezop_mtntsht_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player) {
        if ((gameTracker->gameFlags & 4) != 4) {
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

    if (instance->currentMainState == 1) {
        obj = OBTABLE_FindObject("rebug___");
        birthed = INSTANCE_BirthObject(instance, obj);
        if (birthed != NULL) {
            birthed->rotation.z += 0x400;
            obj->oflags |= 0x2000;
            birthed->introData = NULL;
        }
        instance->currentMainState = 0;
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

    if (instance->currentMainState != 1) {
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
    WORK_AS_IDX(short, instance->work1, 1) = (short)data[0] / 2;
    WORK_AS_IDX(short, instance->work2, 0) = -((short)data[0] / 2);
    WORK_AS_IDX(short, instance->work4, 1) = data[3];
    WORK_AS_IDX(short, instance->work2, 1) = (short)data[1] / 2 + 0x140;
    x = -0x140 - (short)data[1] / 2;
    WORK_AS_IDX(short, instance->work3, 0) = x;
    y = data[2];
    x = -0x40;
    WORK_AS_IDX(short, instance->work4, 0) = x;
    ((short*)&instance->work0)[1] = 0;
    WORK_AS_IDX(short, instance->work3, 1) = x - y;
}

INCLUDE_ASM("asm/nonmatchings/level/REZOP", rezop_iris_OnUpdate);

void rezop_iris_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void rezop_tvgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentMainState = 0;
    instance->flags |= 0x100800;
}

void rezop_tvgen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    char* intro;
    Object* obj;
    Instance* birthed;
    int v;

    intro = instance->introData;
    obj = OBTABLE_FindObject(intro + 8);
    if (intro == NULL || obj == NULL) {
        INSTANCE_KillInstance(instance);
    } else if (instance->currentMainState == 1) {
        instance->work0 = instance->work0 + 1;
        if (instance->work0 == ((int*)intro)[1]) {
            v = ((int*)intro)[0];
            instance->currentMainState = 0;
            instance->work0 = v;
        }
    } else {
        instance->work0 += 1;
        if ((unsigned int)gameTracker8->_0051[0x14] % (unsigned int)((int*)intro)[0] == 0) {
            instance->work0 = 0;
            birthed = INSTANCE_BirthObject(instance, obj);
            if (birthed != NULL) {
                obj->oflags |= 0x2000;
                birthed->introData = NULL;
                if ((instance->object->oflags & 0x400) && (((unsigned short*)intro)[8] & 4) && instance->work1 == 0) {
                    instance->work1 = 1;
                    SCRIPT_InstanceSplineSet(birthed, ((short*)intro)[3], 0, 0, 0);
                }
            }
        }
    }
}

void rezop_tvgurny_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR a;
    SVECTOR b;

    instance->flags |= 0x40000000;
    a.x = instance->position.x;
    a.y = instance->position.y;
    b.x = instance->position.x + (((short)func_8003A6AC(instance->intro->rotation.z + 0x400)) * 5 >> 4);
    b.y = instance->position.y + (((short)func_8003A4E0(instance->intro->rotation.z + 0x400)) * 5 >> 4);
    a.z = b.z = instance->position.z;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, &a, &b, instance);
    instance->work9 = (SCRIPT_CountFramesInSpline(instance) << 16) >> 16;
}

void rezop_tvgurny_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR a;
    SVECTOR b;
    SVECTOR* pt;

    instance->work8 += 1;
    if (instance->work8 == 0x28) {
        *(int*)&instance->_C4[0] = 0;
    }
    if (instance->work8 == instance->work9 - 0x28) {
        b.x = instance->position.x;
        b.y = instance->position.y;
        b.z = instance->position.z;
        pt = SplineGetLastPoint(instance->intro->multiSpline->positional, (SplineDef*)&instance->work0);
        a = *pt;
        COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, &a, &b, instance);
        SCRIPT_InstanceSplineSet(instance, (short)(instance->work9 - 0x28), (SplineDef*)&instance->work0, WORK_AS_PTR(SplineDef, instance->work2), 0);
        instance->_D0[0] += 1;
    }
    GenericProcess(instance, gameTracker);
}

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

void rezop_gas_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void rezop_gas_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void rezop_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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
                SIGNAL_HandleSignal(PlayerInstance, (void*)(intro->b + 4), 0);
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
