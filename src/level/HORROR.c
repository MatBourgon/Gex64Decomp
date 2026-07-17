#include "common.h"

#include "types/Camera.h"
#include "level/HORROR.h"
#include "types/intro/QMark.h"
#include "types/intro/BTimer.h"
#include "types/G2String.h"
#include "level/COMMON.h"
#include "OBTABLE.h"

#include "types/Vector.h"
extern int D_800E5FD8;
extern int D_80154834;
extern int D_80164C30_A8460;


void horror_drawer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;
    int v;

    intro = (int*)instance->introData;
    if (intro != 0) {
        v = intro[0];
        instance->currentMainState = v;
        if (v == 1) {
            instance->scale.x = 1;
            func_8002E704();
        }
    } else {
        instance->currentMainState = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_drawer_OnUpdate);

void horror_drawer_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_chandb_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = (int*)instance->introData;
    instance->currentMainState = 0;
    instance->flags |= 0x100000;
    if (intro[0] == 1) {
        instance->currentModelAnim = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_chandb_OnUpdate);

void horror_chandb_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if (bsp->_04 == 1) {
        instance->currentSubState = 2;
    }
    if (bsp->_06 == 4) {
        instance->currentSubState = 1;
    }
}

void horror_chand_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_E0[1] = -8;
    instance->currentMainState = 0;
    instance->_D0[2] = 0;
    instance->flags |= 0x100000;
    WORK_AS(int, instance->work3) = instance->position.z;
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_chand_OnUpdate);

void horror_chand_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int on;

    on = 1;    /* materialized early — required for the original register allocation */
    if (instance->bspTree->_06 == 4) {
        instance->currentSubState = on;
    }
    if (instance->intro->multiSpline != 0) {
        GenericCollide(instance, gameTracker);
    }
}

void horror_axe_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int v;

    v = *(int*)instance->introData;
    if (v != 0) {
        v = 4;
    } else {
        v = 1;
    }
    instance->currentMainState = v;
    v = 2;
    instance->work2 = v;
    instance->work1 = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80159D8C_9D5BC);

extern void func_80016894();

void func_8015A014_9D844(short* p, int arg1) {
    short t;

    if (p[0x20 / 2] + p[0x50 / 2] <= p[0x44 / 2]) {
        t = p[0x46 / 2];
        if (t == 0) {
            p[0x46 / 2] = t + 1;
            p[0x48 / 2] = p[0x50 / 2] = p[0x48 / 2] - 0xF;
        } else if (t == 1) {
            p[0x46 / 2] = t + 1;
            p[0x48 / 2] = p[0x50 / 2] = p[0x48 / 2] - 0xF;
        } else if (t == 2) {
            p[0x46 / 2] = t + 1;
            p[0x48 / 2] = p[0x50 / 2] = p[0x48 / 2] - 0xA;
        }
    }
    p[0x24 / 2] -= 1;
    p[0x28 / 2] += 3;
    p[0x2C / 2] -= 1;
    p[0x30 / 2] -= 1;
    p[0x34 / 2] += 3;
    p[0x38 / 2] -= 1;
    func_80016894(p, arg1);
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_axe_OnUpdate);

void horror_axe_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->_06 == 1 && instance->bspTree->instanceSpline == gameTracker->player && instance->currentMainState != 0) {
        func_80022714(instance, gameTracker);
    }
}

void horror_face_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentMainState = 1;
    instance->flags |= 0x100000;
    if (((short*)instance->introData)[1] != 0) {
        instance->currentMainState = 0;
        instance->flags |= 0x800;
    }
    instance->work2 = 0;
    WORK_AS(int, instance->work3) = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_face_OnUpdate);

void horror_face_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp  = instance->bspTree;
    int state = instance->currentMainState;

    if (state == 1 && bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player) {
        func_80022714(instance, gameTracker);
    }
}

void horror_zombie_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = (int*)instance->introData;
    if (instance->flags & 0x20000) {
        if (WORK_AS_IDX(short, instance->work6, 0) >= 3) {
            instance->intro->flags |= 8;
        }
    } else {
        instance->currentMainState = 1;
        instance->currentModelAnim = 0;
        instance->work9 = intro[0];
        instance->flags |= 0x10000;
    }
    *(int*)&instance->_34[2] = 0;
}

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C30_A8460);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C38_A8468);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zombie_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zombie_OnCollide);

void horror_zomarm_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int v;

    instance->_E0[1] = -0x10;
    instance->_D0[2] = 0;
    instance->currentMainState = 1;
    /* the interleaved work1 store keeps rand's result in a temp; a plain
       inline call places the stores on the wrong side of the modulo */
    v = rand();
    instance->work1 = 0;
    instance->work0 = v % 20 + 90;
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_zomarm_OnUpdate);

void horror_zomarm_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if (!(((unsigned short*)bsp->_0C)[3] & 1) && instance->_D0[2] <= 0) {
        instance->currentSubState = 1;
        instance->position.x += bsp->localOffset.x;
        instance->position.y += bsp->localOffset.y;
        instance->position.z += bsp->localOffset.z;
        instance->_D0[2] = 0;
    }
}

void horror_zomleg_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentMainState = 1;
    instance->work0 = 0x3C;
}

void horror_zomleg_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->currentMainState == 1) {
        if (instance->rotation.y < 0x400) {
            instance->rotation.y += 0x80;
        } else {
            instance->currentMainState = 0;
        }
    }
    if (instance->work0 > 0) {
        instance->position.x -= instance->work0 * ((short)func_8003A6AC(instance->rotation.z - 0x400)) >> 12;
        instance->position.y -= instance->work0 * ((short)func_8003A4E0(instance->rotation.z - 0x400)) >> 12;
        instance->work0 -= 4;
    }
}

void horror_zomleg_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void func_8015BF7C_9F7AC(Instance* instance, GameTracker* gameTracker);

void horror_huck_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* introData = instance->introData;
    int flags = instance->flags;
    Instance* linked;
    int v;

    if (flags & 0x20000) {
        v = instance->work9;
        if (v != 0) {
            v = ~0x400;
            linked = ((Instance*)instance->work9);
            instance->flags = flags & v;
            linked->parent = NULL;
            instance->work9 = 0;
            if (linked->flags2 & 4) {
                func_8015BF7C_9F7AC(linked, gameTracker);
            } else {
                INSTANCE_PlainDeath(linked, 5, 3, 0);
            }
        }
    } else {
        instance->currentMainState = 1;
        instance->currentModelAnim = 0;
        WORK_AS(int, instance->work3) = 0x19;
        instance->work7 = 1;
        if (introData != 0) {
            instance->work8 = introData[0];
        } else {
            instance->work8 = 0;
        }
        instance->flags |= 0x10000;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huck_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huck_OnCollide);

void horror_huckhed_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->flags & 0x20000) {
        if (instance->parent != 0) {
            instance->parent->work9 = 0;
            if (instance->parent->flags2 & 4) {
                func_8015BF7C_9F7AC(instance->parent, gameTracker);
                instance->parent = 0;
            } else {
                INSTANCE_PlainDeath(instance->parent, 5, 3, 0);
                instance->parent = 0;
            }
        }
    } else {
        instance->object->oflags |= 0x2000000;
        WORK_AS_IDX(short, instance->work9, 1) = 0x60;
        WORK_AS_IDX(short, instance->work9, 0) = 0x3E8;
        instance->currentModelAnim = 1;
        instance->_E0[1] = -0x10;
        instance->_D0[3] = -4;
        instance->currentMainState = 0;
        instance->_D0[2] = 0;
        instance->_D0[0] = 0x60;
        instance->flags |= 0x10400;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huckhed_OnUpdate);

extern G2String D_80164C58_A8488;

void func_8015BF7C_9F7AC(Instance* instance, GameTracker* gameTracker) {
    Instance* e;

    for (e = gameTracker->instanceList->first; e != 0; e = e->next) {
        if (e != gameTracker->player && G2String_Compare_EQ(e->object->name, &D_80164C58_A8488) && e->work1 == ((int)instance)) {
            common_icecube_OnCollide(e, gameTracker);
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_huckhed_OnCollide);

void horror_gate_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* intro;

    intro = (short*)instance->introData;
    if (intro != 0 && intro[0] == 1) {
        instance->scale.z = 1;
        instance->currentMainState = 2;
        func_8002E704();
    }
}

void horror_gate_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short* intro;

    intro = (short*)instance->introData;
    if (intro != 0 && instance->currentMainState == 1) {
        instance->scale.z -= 0x44;
        if (instance->scale.z <= 0) {
            instance->scale.z = 1;
            instance->currentMainState = 2;
            intro[0] = 1;
        }
        func_8002E704();
    }
}

void horror_gate_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltchst_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltchst_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltchst_OnCollide);

void horror_ledge_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = instance->introData;
    instance->work1 = 0xA;
    if (intro != NULL && intro[0] == 1) {
        instance->currentModel = 1;
    }
}

void horror_ledge_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int v;

    if (instance->currentMainState == 1) {
        v = instance->work0++;
        if (v + 1 == instance->work1) {
            instance->currentMainState = 2;
            instance->work1 = v;
            instance->currentModel = 1;
            instance->work0 = 0;
        }
    } else if (instance->currentMainState == 2) {
        if (instance->work1 > 0) {
            instance->currentMainState = 1;
            instance->currentModel = 0;
        } else {
            instance->currentMainState = 3;
            *(int*)instance->introData = 1;
        }
    }
}

void horror_ledge_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_ldgeact_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void horror_ldgeact_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    Intro* intro = instance->intro;
    int* introData;
    int* sig;

    if (intro->_2C != 0 && *intro->_2C == 1) {
        introData = instance->introData;
        if (*(int*)((Intro**)intro->_04)[1]->data == 0) {
            if (introData[0] != 0) {
                ((Intro**)intro->_04)[1]->instance->currentMainState = 1;
                ((Intro**)instance->intro->_04)[2]->instance->currentMainState = 1;
                instance->currentMainState = 1;
                sig = ((int*)introData[0]);
                if (sig != 0) {
                    COLLIDE_HandleSignal(gameTracker->player, sig + 1, sig[0], 0);
                }
                introData[0] = 0;
            }
        }
    }
}

void horror_ldgeact_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_bkshlf_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void horror_bkshlf_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->currentSubState == 1) {
        instance->rotation.z -= 0xC;
    } else if (instance->currentSubState == 2) {
        instance->rotation.z += 0xC;
    }
    instance->currentSubState = 0;
}

void horror_bkshlf_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player) {
        if (bsp->globalOffset.y < -0x77) {
            if (bsp->globalOffset.x <= 0) {
                instance->currentSubState = 1;
            } else {
                instance->currentSubState = 2;
            }
        } else if (bsp->globalOffset.y > 0x77) {
            if (bsp->globalOffset.x <= 0) {
                instance->currentSubState = 2;
            } else {
                instance->currentSubState = 1;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltlamp_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C4C_A847C);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C50_A8480);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C58_A8488); // icecube_

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C64_A8494);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C70_A84A0);

INCLUDE_RODATA("asm/nonmatchings/level/HORROR", D_80164C74_A84A4);

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltlamp_OnUpdate);

void horror_polter_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->scale.z = instance->scale.y = instance->scale.x = 1;
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_polter_OnUpdate);

void horror_polter_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8015E05C_A188C);

void func_8015E1A8_A19D8(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->_06 == 1) {
        if (instance->bspTree->instanceSpline == gameTracker->player) {
            if (instance->bspTree->_0C[5] >= 6U) {
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

void horror_skelh_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentMainState = 0;
    if (instance->parent != 0 && instance->parent->intro != 0) {
        instance->flags |= 0x100400;
        WORK_AS(int, instance->work4) = 0;
        WORK_AS(int, instance->work5) = (int)instance->parent->intro->multiSpline;
        WORK_AS(int, instance->work6)= (int)instance->parent->introData;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_skelh_OnUpdate);

void horror_skelh_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;

    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player && bsp->_0C[5] >= 6 && bsp->_08[4] == 0) {
        INSTANCE_PlainDeath(instance, 5, -1, 0);
    } else if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player) {
        func_80022714(instance, gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_fltlamp_OnCollide);

void horror_spray_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_8015F620_A2E50);

extern int D_800EB8A0;
extern void func_80017E88();
extern void func_8015F620_A2E50();

void horror_spray_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR rot;
    SVECTOR pos;
    Model* model;
    int state;

    int dy, dx;
    dx = PlayerInstance->position.x - instance->position.x;
    dy = PlayerInstance->position.y - instance->position.y;

    func_8004ACB0(&instance->rotation.z, (short)(ratan2(dy, dx) + 0x400), 0x200);

    state = instance->currentMainState;
    instance->work9 += 1;
    if (state == 0) {
        if (instance->work9 >= 0x5A) {
            instance->currentMainState = 1;
            instance->work9 = 0;
        }
    } else if (state == 1) {
        model = OBTABLE_FindObject("sprysht_")->modelList[0];
        if (WORK_AS(int, instance->work7) != 0) {
            WORK_AS(int, instance->work8) += 8;
            if (WORK_AS(int, instance->work8) == 0x80) {
                WORK_AS(int, instance->work7) = 0;
            }
        } else {
            WORK_AS(int, instance->work8) -= 8;
            if (WORK_AS(int, instance->work8) == -0x80) {
                WORK_AS(int, instance->work7) = state;
            }
        }
        pos.x = instance->position.x + (((short)func_8003A6AC(instance->rotation.z - 0x400)) >> 5);
        pos.y = instance->position.y + (((short)func_8003A4E0(instance->rotation.z - 0x400)) >> 5);
        pos.z = instance->position.z;
        rot.x = (short)func_8003A6AC(instance->rotation.z - 0x400 + (WORK_AS(int, instance->work8))) * 0x19 >> 0xB;
        rot.y = (short)func_8003A4E0(instance->rotation.z - 0x400 + (WORK_AS(int, instance->work8))) * 0x19 >> 0xB;
        rot.z = 0;
        func_800170E8(model, model->_14, &pos, &rot, 0, D_800EB8A0, func_80017E88, func_8015F620_A2E50, 0x14);
        if (PlayerInstance->currentSubState == 0x200000) {
            WORK_AS(int, instance->work6) += 1;
        }
        if (instance->work9 >= 0x5A || WORK_AS(int, instance->work6) >= 0xA) {
            instance->work9 = 0;
            WORK_AS(int, instance->work6) = 0;
            instance->currentMainState = 0;
        }
    }
}

void horror_spray_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->_06 == 1
        && instance->bspTree->instanceSpline == gameTracker->player
        && instance->bspTree->_0C[5] >= 6U) {
        func_8004AAA8(instance, 10, 0);
        INSTANCE_PlainDeath(instance, 5, 3, 0);
    }
}

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

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bug_OnUpdate);

void horror_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void horror_bouncer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_bouncer_OnUpdate);

void horror_bouncer_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void horror_flasher_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void horror_flasher_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (((unsigned int*)gameTracker8)[0xE0 / 4] % 80 == 0) {
        func_800509E0(0x1E5, 0x78, 0x40, (rand() & 0x7F) - 0x40);
    }
}

void horror_flasher_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_hhelev_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x400;
}

void horror_evileye_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_evileye_OnUpdate);

void horror_evileye_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = (int*)instance->introData;
    if (instance->bspTree->instanceSpline == PlayerInstance
        && instance->bspTree->instanceSpline->currentSubState == 0x1000
        && (unsigned int)(instance->currentMainState - 1) >= 2 && intro[0] == 0) {
        instance->currentMainState = 1;
        instance->work0 = 0;
        func_80050508(instance, 0x1D0, 0, 0x64, 0xFA0);
    }
}

void horror_splitob_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR a;
    SVECTOR b;
    int table;

    a.x = b.x = instance->position.x;
    a.y = b.y = instance->position.y;
    a.z = instance->position.z - 0x80;
    b.z = instance->position.z + 0x80;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, &a, &b, instance);
    if (*(int*)&instance->_C4[0] != 0) {
        instance->work0 = *(int*)&instance->_C4[0];
        table = ((int*)gameTracker8->level->segmentAddress)[0x24 / 4];
        instance->work1 = *(short*)((**(unsigned short**)&instance->_C4[0] << 4) + table + 4);
    }
    instance->flags |= 0x400;
}

void horror_splitob_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    Instance* player;

    player = PlayerInstance;
    if (player->position.z < instance->work1 && instance->work1 - 0x100 < player->position.z) {
        *(int*)&player->_C4[0] = instance->work0;
        player->_C4[2] = player->position.x;
        player->_C4[3] = player->position.y;
        player->_C4[4] = instance->work1;
    }
}

void horror_splitob_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_elevpan_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x80;
    if (*(short*)instance->introData == 1) {
        instance->currentTextureAnimFrame = 1;
    }
}

extern int D_80078654;

void horror_elevpan_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short* intro;

    intro = (short*)instance->introData;
    if (D_80078654 != 0 && instance->currentTextureAnimFrame != 1) {
        instance->currentTextureAnimFrame = 1;
        intro[0] = 1;
    }
}

void horror_elevpan_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void horror_onoff_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

void horror_onoff_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void horror_onoff_OnCollide(Instance* instance, GameTracker* gameTracker) {
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
        } else if (G2String_Compare_EQ(instance->object->name, "gong____")) {
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

extern int D_80164C38_A8468[];
void horror_funplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVector newPoint;
    SVector oldPoint;

    if (instance->introData == 0) {
        instance->introData = (void*)D_80164C38_A8468;
    }
    newPoint.x = oldPoint.x = instance->position.x;
    newPoint.y = oldPoint.y = instance->position.y;
    newPoint.z = instance->_E0[2] = instance->position.z;
    oldPoint.z = instance->_40[6] + 0x80;
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, (SVECTOR*)&newPoint, (SVECTOR*)&oldPoint, instance);
}

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

void horror_funplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    LVECTOR newPosition;
    MATRIX transformMatrix;

    BSPTree* instanceBsp = instance->bspTree;
    Instance** s4 = ((Instance**)instance->_D0);

    if (instanceBsp->_06 == 4) {
        if (instanceBsp->instanceSpline == gameTracker->player) {
            if (instance->matrix) {

                func_80041FD0(&transformMatrix, instance->matrix);
                MATH3D_ApplyMatrixT(&transformMatrix, &instanceBsp->globalOffset, &newPosition);

                instance->_D0[0] = (-newPosition.y) << 6;
                instance->_D0[1] = newPosition.x << 6;

                if (instance->work0 != 0) {
                    instance->_E0[3] = -0x1000;
                } else {
                    instance->_E0[3] = -0x4000;
                }

                s4[0x28/4] = instanceBsp->instanceSpline;
                GenericCollide(instance, gameTracker);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_door_OnCreate);

void func_80161F4C_A577C(Instance* instance, SVECTOR offset) {
    MATRIX m;
    SVECTOR vec;
    SVECTOR res;

    MATH3D_SetUnityMatrix(&m);
    if (instance->rotation.z >= -0x3FF) {
        instance->rotation.z -= 0x20;
        RotMatrixZ(instance->rotation.z + instance->intro->rotation.z, &m);
        vec.y = 0x40;
        vec.x = 0;
        vec.z = 0;
        res.x = (vec.x * m.m[0][0] >> 12) + (vec.y * m.m[0][1] >> 12) + (vec.z * m.m[0][2] >> 12);
        res.y = (vec.x * m.m[1][0] >> 12) + (vec.y * m.m[1][1] >> 12) + (vec.z * m.m[1][2] >> 12);
        res.z = (vec.x * m.m[2][0] >> 12) + (vec.y * m.m[2][1] >> 12) + (vec.z * m.m[2][2] >> 12);
        instance->position.x = res.x + offset.x;
        instance->position.y = res.y + offset.y;
        instance->position.z = res.z + offset.z;
    } else {
        WORK_AS_IDX(char, instance->work8, 2) = 4;
    }
}

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

void func_80162438_A5C68(GameTracker* gameTracker, short* arg1, Instance* arg2) {
    Camera* cam;
    unsigned short flags;

    cam = gameTracker->camera;
    cam->smooth = arg1[5];
    flags = arg2->_C4[4];
    if (!(flags & 0x10)) {
        if (((int*)cam)[0x520 / 4] == (int)arg2 + 0x106 || ((int*)cam)[0x520 / 4] == (int)arg2 + 0xEE || (flags & 4)) {
            func_80003234(cam);
        }
        ((int*)cam)[0x4D4 / 4] = 0;
        cam->cameraKey = 0;
        ((int*)cam)[0x520 / 4] = 0;
        cam->smooth = 8;
    }
}

/* set _C0[3] on this instance and every instance in its intro group
   (intro->_04 points at a count-prefixed array of Intro*) */
void func_801624B4_A5CE4(Instance* instance, short val) {
    int i;

    instance->_C4[3] = val;
    for (i = 1; i < *(int*)instance->intro->_04 + 1; i++) {
        ((Intro**)instance->intro->_04)[i]->instance->_C4[3] = val;
    }
}

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
    instance->work2 = 0;
    instance->work0 = 0x40;
    instance->work1 = 0;
}

void horror_qmark_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void horror_qmark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    QMarkIntro* intro;

    intro = (QMarkIntro*)instance->introData;
    if (func_80027500(instance->bspTree, gameTracker) != 0) {
        instance->work2 = 1;
        instance->work0 = 0x12C;
        WORK_AS(int, instance->work5) = intro->time;
        WORK_AS(int, instance->work4) = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/HORROR", func_80163B88_A73B8);

extern char D_80164CCC_A84FC[];

void horror_reza_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned char* fc = WORK_AS_PTR(unsigned char, instance->work0);
    short* intro = ((short*)instance->introData);

    instance->flags |= 0x100000;
    if (strcmp(gameTracker->level->levelType, D_80164CCC_A84FC) == 0) {
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

INCLUDE_ASM("asm/nonmatchings/level/HORROR", horror_reza_OnUpdate);

void horror_reza_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void horror_btimer_OnCreate(Instance* instance, GameTracker* gameTracker) {
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
            PlayerInstance->work0 &= 0xFFBFFFFF;
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

