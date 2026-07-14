#include "common.h"

#include "level/SCIFI.h"
#include "types/G2String.h"
#include "MATRIX.h"

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159720_DF540);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_801598A4_DF6C4);

extern int* D_8007681C;

int func_80159A08_DF828(void) {
    short* p;

    p = (short*)D_8007681C[7];
    if (p[0xC] == 0) {
        return (short)(*(unsigned short*)&p[0xF] + (p[8] + p[4]) * 30);
    }
    if (p[0xC] == 1) {
        return (short)(*(unsigned short*)&p[0xF] + p[8] * 30);
    }
    return p[0xF];
}

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164DF0_EAC10);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E14_EAC34);

void func_80159A84_DF8A4(Instance* arg0) {
    int* data = ((int*)PlayerInstance->data);

    if (arg0 != 0) {
        INSTANCE_KillInstance(arg0);
    }
    memcpy(data + 0x4C / 4, "helmet__", 9);
    data[0x48 / 4] = 0x14;
    func_800240C8();
    if (D_8007681C != 0 && D_8007681C[7] != 0) {
        ((short*)D_8007681C[7])[0x20 / 2] = 0x12C;
    }
}


INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159B10_DF930);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159D54_DFB74);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159E3C_DFC5C);

void scifi_dust_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[2] = rand() % 10 + 6;
}

void scifi_dust_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    unsigned short z;

    z = instance->position.z - instance->_F4[2];
    instance->position.z = z;
    if ((short)z < instance->intro->position.z - 0x190) {
        INSTANCE_KillInstance(instance);
    }
}

void scifi_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[0] = 0;
    instance->currentModelAnim = 0;
}

void scifi_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void scifi_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
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
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player)&& ((instance->_F4[0] - 1) >= 2U)) {
            func_80022714(instance, gameTracker);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rocket_OnCreate);

void func_8015A36C_E018C(Instance* instance, void* unused, SVECTOR* out, SVECTOR* in) {
    MATRIX mat;
    LVECTOR temp;

    func_80041FD0(&mat, instance->matrix);
    MATH3D_ApplyMatrix(&mat, in, &temp);
    out->x = mat.l[0] + temp.x;
    out->y = mat.l[1] + temp.y;
    out->z = mat.l[2] + temp.z;
}

void func_8015A3F4_E0214(Instance* instance, void* unused, SVECTOR* out, SVECTOR* in) {
    MATRIX* mat;
    LVECTOR temp;

    mat = instance->matrix;
    MATH3D_ApplyMatrix(mat, in, &temp);
    out->x = mat->l[0] + temp.x;
    out->y = mat->l[1] + temp.y;
    out->z = mat->l[2] + temp.z;
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rocket_OnUpdate);

void scifi_rocket_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bspTree;
    bspTree = instance->bspTree;
    GenericCollide(instance, gameTracker);
    if (bspTree->instanceSpline == PlayerInstance) {
        if (PlayerInstance->_F4[0] == 1) {
            instance->_100 = 1;
        }
    }
}

void scifi_onoff_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->intro->flags & 0x1000) {
        instance->intro->flags &= ~0x800;
        return;
    }

    instance->_F4[0] = 0;
    instance->flags |= 0x80;

    if (instance->introData != NULL && *((int*)instance->introData) & 0x12) {
        instance->_F4[0] = 1;
    }

    if (instance->intro->flags & 0x800) {
        instance->_F4[0] = instance->_F4[0] != 1;
    }

    if (instance->object->data != NULL && *((int*)instance->object->data) != 0) {
        instance->_100 = 1;
    }

    if (instance->_F4[0] == 0 || instance->_100 != 0) {
        instance->currentAnimFrame = 0;
    } else if (((short*)&instance->object->_08)[1] != 0) {
        instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[0]))[1] - 1;
    }
}

void scifi_onoff_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    instance->currentTextureAnimFrame = instance->_F4[0] ^ 1;

    if (instance->_F4[1] == 1) {
        if (instance->_F4[0] == 1 || instance->_100 != 0) {
            func_8002DAF8(instance, -1);
        } else {
            func_8002DAF8(instance, -0x3E9);
        }

        if (instance->flags2 & 0x10) {
            instance->flags2 &= ~0x10;
            instance->_F4[1] = 0;
            if (instance->_F4[0] == 0 || instance->_100 != 0) {
                instance->currentAnimFrame = 0;
            } else if (((short*)&instance->object->_08)[1] != 0) {
                instance->currentAnimFrame = ((unsigned short*)(instance->object->animList[0]))[1] - 1;
            }
        }
    }
}

void scifi_onoff_OnCollide(Instance* instance, GameTracker* gameTracker) {
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
    if (intro != NULL && bsp->_06 == 1 && bsp->_0C[5] >= 8U && instance->_F4[1] != 1) {
        list = (int**)(intro + 2);
        if (intro[1] == 0) {
            match = 1;
        } else if (intro[1] == 1) {
            if (instance->_F4[0] == 0) {
                match = 1;
                checkState = 1;
            }
        } else if (intro[1] == 2) {
            if (instance->_F4[0] == 1) {
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
            instance->_F4[0] ^= 1;
            fire = 1;
        } else if (G2String_Compare_EQ(instance->object->name, "gong____")) {
            fire = 1;
        }
        if (fire != 0) {
            if (((short*)&instance->object->_08)[1] != 0) {
                instance->_F4[1] = 1;
            }
            if (*(int*)list == 0x29A) {
                SIGNAL_HandleSignal(instance, (int*)((int*)list)[1] + 1, 0);
            }
        }
    }
}

void scifi_bub_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* introData;
    short* objData;

    introData = instance->introData;
    objData = instance->object->data;
    if (introData != NULL) {
        instance->_F4[2] = introData[0];
        instance->_100 = introData[1];
        WORK_AS(int, instance->_10C) = introData[2];
    } else if (objData != NULL) {
        instance->_F4[2] = objData[0];
        instance->_100 = objData[1];
        WORK_AS(int, instance->_10C) = objData[2];
    }
    if (((short*)&instance->_F4[2])[1] == 0) {
        instance->_F4[2] = 0x64;
    }
    if (((short*)&instance->_100)[1] == 0) {
        instance->_100 = 0x1E;
    }
    if (WORK_AS_IDX(short, instance->_10C, 1) == 0) {
        WORK_AS(int, instance->_10C) = 0x384;
    }
    INSTANCE_InsertInstanceWithFlagsSet(instance, 0x1000);
    func_8004A7B8(instance, 0, 0);
    instance->currentTextureAnimFrame = -1;
    instance->_F4[0] = 0;
    instance->rotation.x = 0;
    instance->rotation.y = 0;
    instance->rotation.z = 0;
    instance->flags |= 0x80;
    instance->initialPos = instance->position;
    *(int*)&instance->_110 = 1;
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015AC28_E0A48);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_bub_OnUpdate);

void scifi_bub_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->instanceSpline == gameTracker->player && instance->bspTree->_08[4] == 0) {
        func_80159720_DF540(((short*)&instance->_F4[2])[1]);
        instance->_F4[0] = 1;
    }
}

void scifi_eel_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentModelAnim = 0;
    instance->currentAnimFrame = 0;
    instance->_D0[3] = 0;
    instance->_F4[0] = 0;
    instance->_100 = 0;
    instance->flags |= 0x800;
    instance->_104 = ((short*)instance->object->animList[1])[1];
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_eel_OnUpdate);

void scifi_eel_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (func_80027500(instance->bspTree, gameTracker)) {
        INSTANCE_PlainDeath(instance, 5, 3, 0);
    }
}

void scifi_stmvent_OnCreate(Instance* instance, GameTracker* gameTracker) {
    MATRIX mat;
    short* introData;

    introData = instance->introData;
    RotMatrix(&instance->intro->rotation, &mat);
    WORK_AS(int, instance->_10C) = mat.m[0][2] * 25 >> 10;
    *(int*)&instance->_110 = mat.m[1][2] * 25 >> 10;
    *(int*)&instance->_114 = mat.m[2][2] * 25 >> 10;
    if (introData != NULL) {
        instance->_D0[0] = introData[1];
        instance->_D0[1] = introData[2];
        if (introData[4] != 0) {
            instance->_D0[3] |= 1;
        }
        instance->_E0[0] = introData[0];
        instance->_E0[1] = instance->_D0[0] + instance->_D0[1];
        instance->_E0[3] = introData[5];
    } else {
        instance->_D0[0] = 0x3C;
        instance->_D0[1] = 0x3C;
        instance->_E0[1] = 0x78;
        instance->_E0[0] = 0;
        instance->_E0[3] = 0;
        instance->_D0[3] &= ~1;
    }
    *(int*)&instance->_34[2] = 0;
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
    short _42;
    short _44;
    char _46[0x26];
    unsigned short frame;
} VentSprayData;

extern void func_80016894(void*);
INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015B4BC_E12DC);
/* near-match (8 diffs: frame a1/a2, mflo v0/v1, z-check load order — scheduler difference):
void func_8015B4BC_E12DC(void* arg0) {
    VentSprayData* data;
    Instance* player;
    int dz;
    int dx;
    int dy;

    data = ((VentSprayData*)arg0);
    data->unk24 -= 10;
    data->unk28 += 10;
    data->frame++;
    data->unk2C -= 10;
    data->unk30 -= 10;
    data->unk34 += 10;
    data->unk38 += 10;
    data->unk3C += 10;
    data->unk40 -= 10;
    func_80016894(arg0);
    if (data->_44 != 0) return;
    player = PlayerInstance;
    dx = player->position.x - data->posX;
    dy = player->position.y - data->posY;
    if (dx * dx + dy * dy < 0x4000) {
        dz = player->position.z - data->posZ;
        if (dz < 0) dz = -dz;
        if (dz < 0x80) {
            if (player->_F4[1] != 0x200000) {
                func_800223F8(gameTracker8, 0x78, 0);
            }
        }
    }
}
*/

extern void func_80017E88();
extern void func_8015B4BC_E12DC();

void func_8015B5F0_E1410(Instance* instance) {
    extern int D_800EB8A0;
    Object* obj;
    Model* model;
    SVECTOR rot;
    SVECTOR vel;
    VentSprayData* spray;

    obj = ((Object*)OBTABLE_FindObject("sprysht_"));
    if (instance->_E0[3] == 0) {
        model = obj->modelList[0];
    } else {
        model = obj->modelList[1];
    }
    if (instance->_104 != 0) {
        WORK_AS(int, instance->_108) += 0x1000;
        if (WORK_AS(int, instance->_108) == 0xC000) {
            instance->_104 = 0;
        }
    } else {
        WORK_AS(int, instance->_108) -= 0x1000;
        if (WORK_AS(int, instance->_108) == -0xC000) {
            instance->_104 = 1;
        }
    }
    if (*(int*)&instance->_118 != 0) {
        *(int*)&instance->_11C += 0x1000;
        if (*(int*)&instance->_11C == 0xA000) {
            *(int*)&instance->_118 = 0;
        }
    } else {
        *(int*)&instance->_11C -= 0x1000;
        if (*(int*)&instance->_11C == -0xA000) {
            *(int*)&instance->_118 = 1;
        }
    }
    rot.x = (WORK_AS(int, instance->_10C) >> 1) + (*(int*)&instance->_11C >> 12);
    rot.y = (*(int*)&instance->_110 >> 1) + (*(int*)&instance->_11C >> 12);
    rot.z = (*(int*)&instance->_114 >> 1) + (WORK_AS(int, instance->_108) >> 12);
    vel.x = 0;
    vel.y = 0;
    vel.z = 0;
    spray = ((VentSprayData*)func_800170E8(model, model->_14, &instance->position, &rot, 0, D_800EB8A0, func_80017E88, func_8015B4BC_E12DC, 0x14));
    if (*(int*)&instance->_34[2] == 0) {
        *(int*)&instance->_34[2] = func_80050508(instance, 0x112, -0x15E, 0x50, 0xBB8);
    }
    if (instance->_E0[3] == 0) {
        spray->_44 = 0;
    } else {
        spray->_44 = 1;
    }
}

void scifi_stmvent_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->_D0[3] & 1) {
        func_8015B5F0_E1410(instance);
    } else {
        instance->_E0[2] = instance->_E0[0] % instance->_E0[1];
        if (instance->_D0[0] < instance->_E0[2]) {
            if (PlayerInstance->_F4[1] == 0x200000) {
                instance->_100++;
            }
            if (instance->_100 >= 10) {
                instance->_E0[0] = 0;
                instance->_100 = 0;
            }
            func_8015B5F0_E1410(instance);
        }
        instance->_E0[0]++;
    }
    if (*(int*)&instance->_34[2] != 0) {
        if (func_80033248(*(int*)&instance->_34[2]) == 0) {
            *(int*)&instance->_34[2] = 0;
        } else {
            func_800506B8(instance, *(int*)&instance->_34[2], -0x15E, 0x50, 0xBB8);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015B904_E1724);

void func_8015BB90_E19B0(short* arg0) {
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

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015BC24_E1A44);

void scifi_genbrk_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void scifi_genbrk_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    GenericProcess(instance, gameTracker);
}

extern int D_800EB8A0;
void scifi_genbrk_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (func_80027500(instance->bspTree, gameTracker)) {
        func_8015BC24_E1A44(instance, D_800EB8A0);
        func_80046978(instance);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015BF08_E1D28);

void func_8015BFA8_E1DC8(Instance* instance) {
    instance->flags &= ~0x400;
    func_8002E350(instance);
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015BFD4_E1DF4);

void scifi_bldbota_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->flags & 0x20000) {
        func_8015BFA8_E1DC8((Instance*)instance->_F4[2]);
        instance->_F4[2] = 0xCDCDCDCD;
    } else {
        instance->flags |= 0x10080;
        instance->currentTextureAnimFrame = 0;
        instance->_F4[2] = func_8015BF08_E1D28(instance);
    }
}

void scifi_bldbota_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    unsigned short frame;

    frame = instance->currentTextureAnimFrame;
    instance->currentTextureAnimFrame = frame + 1;
    func_8015BFD4_E1DF4(instance->_F4[2], (short)frame);
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_abubble_OnCreate);

void scifi_abubble_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR unused;    /* dead local — reproduces the 0x20 frame */
    int v;

    v = instance->_104;
    if (WORK_AS_IDX(short, instance->_104, 1) < ((short*)&instance->_100)[1]) {
        if (instance->flags & 0x1000) {
            instance->_104 = (short)(v + 1);
        }
    } else if (instance->flags & 0x1000) {
        INSTANCE_InsertInstanceWithFlagsCleared(instance, 0x1000);
    }
}

void scifi_abubble_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->instanceSpline == gameTracker->player && instance->bspTree->_08[4] == 0) {
        func_80159720_DF540(((short*)&instance->_F4[2])[1]);
        INSTANCE_PlainDeath(instance, 5, -1, 0);
    }
}

void scifi_acrate_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* intro;
    unsigned short* data;
    short* fc;

    intro = (unsigned short*)instance->introData;
    data = (unsigned short*)instance->object->data;
    fc = (short*)&instance->_F4[2];
    if (intro != 0) {
        fc[0] = intro[0];
        fc[1] = intro[1];
    } else if (data != 0) {
        fc[0] = data[0];
        fc[1] = data[1];
    }
    if (fc[0] == 0) {
        fc[0] = 10;
    }
    if (fc[1] == 0) {
        fc[1] = 0x1E;
    }
}

void scifi_acrate_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_acrate_OnCollide);

void scifi_xa_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[2] = 0;
}


void scifi_xa_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int w;

    instance->_F4[2] += 1;
    instance->scale.x += 0x555;
    w = instance->_F4[2];
    instance->scale.y += 0x555;
    instance->scale.z += 0x555;
    if (w >= 0xD) {
        func_8002E350(instance);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_apod_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015C5CC_E23EC);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_apod_OnUpdate);

void scifi_apod_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->bspTree->instanceSpline == gameTracker->player && (instance->bspTree->_04 == 2 || instance->bspTree->_04 == 5)) {
        GenericCollide(instance, gameTracker);
    }
}

typedef struct {
    short _00;
    short _02;
    short _04;
    short _06;
    short _08;
    short _0A;
    short _0C;
    short _0E;
} AlienData;

void scifi_alien_OnCreate(Instance* instance, GameTracker* gameTracker) {
    *(AlienData*)&instance->_F4[2] = *(AlienData*)instance->data;
    if (!(instance->flags & 0x20000)) {
        instance->flags |= 0x10000;
        instance->_F4[0] = 2;
        func_8004A7B8(instance, 2, 0);
        instance->position.z += ((AlienData*)&instance->_F4[2])->_08;
        func_80049330(instance);
        instance->flags |= 0x100000;
        *(short*)&instance->_112 = ((AlienData*)&instance->_F4[2])->_00 / 2 + 1;
        *(short*)&instance->_110 = *(short*)&instance->_114 = ((AlienData*)&instance->_F4[2])->_00;
    } else if (instance->_120 != 0) {
        instance->intro->flags |= 8;
    }
}

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E60_EAC80); // rtblast_

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E6C_EAC8C); // bub_____

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E78_EAC98);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_alien_OnUpdate);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164EA8_EACC8); // aliens__

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164EAC_EACCC);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_alien_OnCollide);

typedef struct {
    short _00;
    short _02;
    short _04;
    short _06;
} GasData;

void scifi_gas_OnCreate(Instance* instance, GameTracker* gameTracker) {
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
                    WORK_AS(int, instance->_108) |= 0x8000;
                    ((char*)&instance->_100)[2] = ~((unsigned char*)&instance->_100)[2];
                }
                t = func_8004A61C(instance);
                m = introData[0];
                m %= (unsigned int)(((unsigned short*)&instance->_F4[2])[1] + *(unsigned short*)&instance->_F4[2] + ((unsigned char*)&instance->_100)[1]);
                if (m < ((unsigned short*)&instance->_F4[2])[1]) {
                    WORK_AS_IDX(short, instance->_108, 0) = m;
                    instance->_F4[0] = 0;
                } else {
                    m -= ((unsigned short*)&instance->_F4[2])[1];
                    if (m < ((unsigned char*)&instance->_100)[1]) {
                        WORK_AS_IDX(short, instance->_108, 0) = m;
                        instance->_F4[0] = 1;
                    } else {
                        m -= ((unsigned char*)&instance->_100)[1];
                        if (m < t) {
                            instance->_F4[0] = 2;
                            t = m;
                        } else {
                            m -= t;
                            if (m < *(unsigned short*)&instance->_F4[2]) {
                                WORK_AS_IDX(short, instance->_108, 0) = m;
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

void scifi_gas_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* fc;
    unsigned short x;
    unsigned short y;
    int w;

    fc = (unsigned short*)&instance->_F4[2];
    x = WORK_AS_IDX(unsigned short, instance->_108, 0);
    y = instance->currentTextureAnimFrame;
    WORK_AS_IDX(unsigned short, instance->_108, 0) = x + 1;
    w = WORK_AS(int, instance->_108);
    instance->currentTextureAnimFrame = y + 1;
    if (w & 0x8000) {
        instance->rotation.z = (instance->rotation.z + 0x2200) & 0xFFF;
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

void scifi_gas_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_mylot_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015E070_E3E90);
/* near-match kept for reference: matches only with `register int result __asm__("$2")` to pin the
   return register; leader prefers no asm constructs, so it stays commented until properly matched.
int func_8015E070_E3E90(Instance* instance) {
    MATRIX mat;
    unsigned short out[3];
    unsigned short out2[3];
    register int result __asm__("$2");
    unsigned short x;
    unsigned short y;
    unsigned short z;

    MATH3D_SetUnityMatrix(&mat);
    RotMatrixX(instance->rotation.x, &mat);
    RotMatrixY(instance->rotation.y + 0x800, &mat);
    RotMatrixZ(instance->rotation.z, &mat);
    func_800157BC(&mat, out);
    result = 0;
    x = out[0];
    y = out[1];
    z = out[2];
    out2[0] = x;
    x &= 0xFFF;
    out2[1] = y;
    y &= 0xFFF;
    out2[2] = z;
    out2[0] = x;
    out2[1] = y;
    if (x == 0) result = (y < 1);
    return result;
}
*/

int func_8015E108_E3F28(Instance* instance) {
    instance->rotation.x &= 0xFFF;
    instance->rotation.y &= 0xFFF;
    return instance->rotation.x == 0 && instance->rotation.y == 0;
}

int func_8015E130_E3F50(Instance* instance, GameTracker* gameTracker) {
    MATRIX mat;
    SVector pos;
    SVECTOR result;
    SVECTOR delta;
    int temp;

    MATH3D_SetUnityMatrix(&mat);
    pos.x = instance->position.x;
    pos.y = instance->position.y;
    pos.z = instance->position.z;
    delta.x = pos.x - gameTracker->player->position.x;
    delta.y = pos.y - gameTracker->player->position.y;
    delta.z = pos.z - gameTracker->player->position.z;
    RotMatrixZ(-instance->rotation.z, &mat);
    temp = (mat.m[1][0] * delta.x + mat.m[1][1] * delta.y + mat.m[1][2] * delta.z) >> 12;
    result.y = temp;
    return (temp << 16) > 0;
}

int func_8015E234_E4054(Instance* instance, GameTracker* gameTracker, short base, short min, short angle) {
    MATRIX mat;
    SVector pos;
    SVECTOR result;
    SVECTOR delta;
    int temp;

    MATH3D_SetUnityMatrix(&mat);
    pos.x = instance->position.x;
    pos.y = instance->position.y;
    pos.z = instance->position.z;
    delta.x = pos.x - gameTracker->player->position.x;
    delta.y = pos.y - gameTracker->player->position.y;
    delta.z = pos.z - gameTracker->player->position.z;
    RotMatrixZ(-angle, &mat);
    temp = (mat.m[1][0] * delta.x + mat.m[1][1] * delta.y + mat.m[1][2] * delta.z) >> 12;
    result.y = temp;
    if (result.y > 0) {
        return base;
    }
    if (min < base + result.y / 5) {
        return base + result.y / 5;
    }
    return min;
}

int func_8015E3AC_E41CC(Instance* instance, GameTracker* gameTracker) {
    MATRIX mat;
    SVector pos;
    SVECTOR result;
    SVECTOR delta;
    int temp;

    MATH3D_SetUnityMatrix(&mat);
    pos.x = instance->position.x;
    pos.y = instance->position.y;
    pos.z = instance->position.z;
    delta.x = pos.x - gameTracker->player->position.x;
    delta.y = pos.y - gameTracker->player->position.y;
    delta.z = pos.z - gameTracker->player->position.z;
    RotMatrixX(instance->rotation.x, &mat);
    RotMatrixY(instance->rotation.y, &mat);
    RotMatrixZ(-instance->rotation.z, &mat);
    temp = (mat.m[0][0] * delta.x + mat.m[0][1] * delta.y + mat.m[0][2] * delta.z) >> 12;
    result.x = temp;
    return (unsigned)(temp << 16) >> 31;
}

int func_8015E4D0_E42F0(Instance* instance, GameTracker* gameTracker) {
    MATRIX mat;
    SVector pos;
    SVECTOR result;
    SVECTOR delta;
    int temp;

    MATH3D_SetUnityMatrix(&mat);
    pos.x = instance->position.x;
    pos.y = instance->position.y;
    pos.z = instance->position.z;
    delta.x = pos.x - gameTracker->player->position.x;
    delta.y = pos.y - gameTracker->player->position.y;
    delta.z = pos.z - gameTracker->player->position.z;
    RotMatrixZ(-instance->rotation.z, &mat);
    temp = (mat.m[0][0] * delta.x + mat.m[0][1] * delta.y + mat.m[0][2] * delta.z) >> 12;
    result.x = temp;
    return (unsigned)(temp << 16) >> 31;
}

SVECTOR func_8015E5D4_E43F4(Instance* instance, short dist) {
    MATRIX mat;
    SVECTOR result;
    SVECTOR vec;
    SVECTOR final;

    RotMatrix(&instance->rotation, &mat);
    vec.x = 0;
    vec.y = 0;
    vec.z = dist;
    result.x = (vec.x * mat.m[0][0] >> 12) + (vec.y * mat.m[0][1] >> 12) + (vec.z * mat.m[0][2] >> 12);
    result.y = (vec.x * mat.m[1][0] >> 12) + (vec.y * mat.m[1][1] >> 12) + (vec.z * mat.m[1][2] >> 12);
    result.z = (vec.x * mat.m[2][0] >> 12) + (vec.y * mat.m[2][1] >> 12) + (vec.z * mat.m[2][2] >> 12);
    final.x = result.x + instance->position.x;
    final.y = result.y + instance->position.y;
    final.z = result.z + instance->position.z;
    return final;
}

SVECTOR func_8015E6B8_E44D8(Instance* instance, short dist) {
    MATRIX mat;
    SVECTOR result;
    SVECTOR vec;
    SVECTOR final;

    RotMatrix(&instance->rotation, &mat);
    vec.x = 0;
    vec.y = 0;
    vec.z = -dist;
    result.x = (vec.x * mat.m[0][0] >> 12) + (vec.y * mat.m[0][1] >> 12) + (vec.z * mat.m[0][2] >> 12);
    result.y = (vec.x * mat.m[1][0] >> 12) + (vec.y * mat.m[1][1] >> 12) + (vec.z * mat.m[1][2] >> 12);
    result.z = (vec.x * mat.m[2][0] >> 12) + (vec.y * mat.m[2][1] >> 12) + (vec.z * mat.m[2][2] >> 12);
    final.x = result.x + instance->position.x;
    final.y = result.y + instance->position.y;
    final.z = result.z + instance->position.z;
    return final;
}

void func_8015E7A0_E45C0(Instance* instance, SVECTOR offset, short dist, short angle) {
    MATRIX m1;
    MATRIX m2;
    MATRIX m3;
    SVECTOR result;
    SVECTOR vec;
    SVECTOR euler;
    SVECTOR rot;

    MATH3D_SetUnityMatrix(&m1);
    MATH3D_SetUnityMatrix(&m2);
    MATH3D_SetUnityMatrix(&m3);
    vec.x = 0;
    vec.y = 0;
    vec.z = -dist;
    rot.x = instance->rotation.x;
    rot.y = instance->rotation.y;
    rot.z = instance->rotation.z;
    RotMatrixX(-angle, &m2);
    RotMatrix(&rot, &m3);
    MulMatrix0(&m3, &m2, &m1);
    result.x = (vec.x * m1.m[0][0] >> 12) + (vec.y * m1.m[0][1] >> 12) + (vec.z * m1.m[0][2] >> 12);
    result.y = (vec.x * m1.m[1][0] >> 12) + (vec.y * m1.m[1][1] >> 12) + (vec.z * m1.m[1][2] >> 12);
    result.z = (vec.x * m1.m[2][0] >> 12) + (vec.y * m1.m[2][1] >> 12) + (vec.z * m1.m[2][2] >> 12);
    instance->position.x = result.x + offset.x;
    instance->position.y = result.y + offset.y;
    instance->position.z = result.z + offset.z;
    func_800157BC(&m1, &euler);
    instance->rotation.x = euler.x;
    instance->rotation.y = euler.y;
    instance->rotation.z = euler.z;
}

void func_8015E9A0_E47C0(Instance* instance, SVECTOR offset, short dist, short angle) {
    MATRIX m1;
    MATRIX m2;
    MATRIX m3;
    SVECTOR result;
    SVECTOR vec;
    SVECTOR euler;
    SVECTOR rot;

    MATH3D_SetUnityMatrix(&m1);
    MATH3D_SetUnityMatrix(&m2);
    MATH3D_SetUnityMatrix(&m3);
    vec.x = 0;
    vec.y = 0;
    vec.z = dist;
    rot.x = instance->rotation.x;
    rot.y = instance->rotation.y;
    rot.z = instance->rotation.z;
    RotMatrixX(angle, &m2);
    RotMatrix(&rot, &m3);
    MulMatrix0(&m3, &m2, &m1);
    result.x = (vec.x * m1.m[0][0] >> 12) + (vec.y * m1.m[0][1] >> 12) + (vec.z * m1.m[0][2] >> 12);
    result.y = (vec.x * m1.m[1][0] >> 12) + (vec.y * m1.m[1][1] >> 12) + (vec.z * m1.m[1][2] >> 12);
    result.z = (vec.x * m1.m[2][0] >> 12) + (vec.y * m1.m[2][1] >> 12) + (vec.z * m1.m[2][2] >> 12);
    instance->position.x = result.x + offset.x;
    instance->position.y = result.y + offset.y;
    instance->position.z = result.z + offset.z;
    func_800157BC(&m1, &euler);
    instance->rotation.x = euler.x;
    instance->rotation.y = euler.y;
    instance->rotation.z = euler.z;
}

void func_8015EB98_E49B8(Instance* instance, short target, short step) {
    int s;
    int delta;

    s = step;
    delta = instance->position.z - target;
    if ((delta >= 0) ? (s >= delta) : (s >= target - instance->position.z)) {
        instance->position.z = target;
    } else {
        if (instance->position.z > target) {
            instance->position.z = instance->position.z - step;
        } else {
            instance->position.z = instance->position.z + step;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_mylot_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_mylot_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rt_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80161C3C_E7A5C);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80161D18_E7B38);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80161DF4_E7C14);

/* write 0x30000000 into every unprotected 12-byte segment entry of the
   first model (meaning of the value unknown) */
void func_80161ED0_E7CF0(int arg0, Instance* instance) {
    Model* model;
    char* p;
    char* end;
    int value;

    value = 0x30000000;
    if (instance->object != 0) {
        model = instance->object->modelList[0];
        p = (char*)model->_14;
        end = p + model->_10 * 12;
        for (; p < end; p += 12) {
            if (!(p[7] & 2)) {
                *(int*)(p + 8) = value;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80161F50_E7D70);

void func_80162154_E7F74(Instance* instance, short arg1) {
    MATRIX mat;
    SVECTOR euler;

    MATH3D_SetUnityMatrix(&mat);
    RotMatrix(&instance->rotation, &mat);
    RotMatrixZ(arg1, &mat);
    func_800157BC(&mat, &euler);
    instance->rotation.x = euler.x;
    instance->rotation.y = euler.y;
    instance->rotation.z = euler.z;
}

void func_801621D4_E7FF4(Instance* instance, SVECTOR offset, short dist, short angle) {
    MATRIX m1;
    MATRIX m2;
    MATRIX m3;
    SVECTOR result;
    SVECTOR vec;
    SVECTOR euler;
    SVECTOR rot;

    MATH3D_SetUnityMatrix(&m1);
    MATH3D_SetUnityMatrix(&m2);
    MATH3D_SetUnityMatrix(&m3);
    vec.x = 0;
    vec.y = 0;
    vec.z = dist;
    rot.x = instance->rotation.x;
    rot.y = instance->rotation.y;
    rot.z = instance->rotation.z;
    RotMatrixX(angle, &m2);
    RotMatrix(&rot, &m3);
    MulMatrix0(&m3, &m2, &m1);
    result.x = (vec.x * m1.m[0][0] >> 12) + (vec.y * m1.m[0][1] >> 12) + (vec.z * m1.m[0][2] >> 12);
    result.y = (vec.x * m1.m[1][0] >> 12) + (vec.y * m1.m[1][1] >> 12) + (vec.z * m1.m[1][2] >> 12);
    result.z = (vec.x * m1.m[2][0] >> 12) + (vec.y * m1.m[2][1] >> 12) + (vec.z * m1.m[2][2] >> 12);
    instance->position.x = result.x + offset.x;
    instance->position.y = result.y + offset.y;
    instance->position.z = result.z + offset.z;
    func_800157BC(&m1, &euler);
    instance->rotation.x = euler.x;
    instance->rotation.y = euler.y;
    instance->rotation.z = euler.z;
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rt_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rt_OnCollide);

void scifi_rtblast_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->initialPos = instance->position;
    *(ROTATION*)&instance->intro->rotation = instance->rotation;
}

void scifi_rtblast_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short dx;
    short dy;

    dx = instance->position.x - instance->initialPos.x;
    dy = instance->position.y - instance->initialPos.y;
    if (((short*)&instance->_F4[2])[1] * ((short*)&instance->_F4[2])[1] < dx * dx + dy * dy) {
        INSTANCE_PlainDeath(instance, 4, -1, 0);
    }
    func_80047E64(instance, ((short*)&instance->_F4[2])[0]);
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rtblast_OnCollide);
