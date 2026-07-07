#include "common.h"

#include "level/PREHST.h"

void prehst_ttplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->introData != NULL) {
        instance->scale.z = *(int*)instance->introData;
    }
    instance->_F4[0] = 4;
    instance->_F4[2] = 0;
    instance->_100 = 2;
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ttplat_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ttplat_OnCollide);

void prehst_bug_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned short* intro;

    ((short*)&instance->_100)[1] = 0x18;
    instance->flags |= 0x100000;
    intro = (unsigned short*)instance->introData;

    if (intro != NULL) {
        *(short*)&instance->_100 = intro[0];
        ((short*)&instance->_104)[1] = intro[1];
        *(short*)&instance->_108 = intro[2];
        ((short*)&instance->_108)[1] = intro[3];
        *(short*)&instance->_10C = intro[4];
        if (((short*)intro)[5] != 0) {
            ((short*)&instance->_10C)[1] = ((short*)intro)[5];
        } else {
            ((short*)&instance->_10C)[1] = 0x40;
        }
    } else {
        *(short*)&instance->_100 = 0x96;
        ((short*)&instance->_104)[1] = ((unsigned short*)&instance->intro->position)[0] - 0x500;
        *(short*)&instance->_108 = ((unsigned short*)&instance->intro->position)[1] - 0x780;
        ((short*)&instance->_108)[1] = ((unsigned short*)&instance->intro->position)[0] + 0x500;
        *(short*)&instance->_10C = ((unsigned short*)&instance->intro->position)[1] + 0x780;
        ((short*)&instance->_10C)[1] = 0x40;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_bug_OnUpdate);

void prehst_bug_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;
    short* temp;

    bsp = instance->bspTree;
    temp = (short*)&instance->_F4[2];

    if (bsp->_06 == 1) {
        if ((bsp->instanceSpline == gameTracker->player) && (bsp->_08[4] < 2U) && (bsp->_0C[5] >= 6U)) {
            INSTANCE_PlainDeath(instance, 5, 3, 0);
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && ((bsp->_08[4] == 0) || (bsp->_08[4] == 2))) {
            func_80022714(instance, gameTracker);
            instance->_F4[0] = 0;
            temp[4] = 0x5A;
        }
    }
}

void prehst_bouncer_OnCreate(Instance* instance, GameTracker* gameTracker) {
    short* intro;
    int* fc;
    
    intro = instance->introData;
    fc = &instance->_F4[2];
    
    if (intro != NULL) {
        ((short*)&instance->_100)[1] = intro[0];
        ((short*)&instance->_104)[0] = intro[1];
    } else {
        ((short*)&instance->_100)[1] = 0U;
        ((short*)&instance->_104)[0] = 0U;
    }
    fc[3] = instance->intro->position.x;
    fc[4] = instance->intro->position.y;
    ((short*)fc)[5] = 6;
    instance->intro->rotation.z = instance->intro->rotation.z & 0xFFF;
    instance->_F4[0] = 1;
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_bouncer_OnUpdate);

void prehst_bouncer_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((bsp->_06 == 1)
        && (bsp->instanceSpline == gameTracker->player)
        && (bsp->_08[4] < 2U)
        && (bsp->_0C[5] >= 6U)
        && (
            (*(short*)&instance->_104 != 3)
            || ((instance->_F4[0] - 2) < 2U)
            || (instance->_F4[0] == 4)
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

void prehst_crawler_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[0] = 0;
    instance->currentModelAnim = 0;
}

void prehst_crawler_OnUpdate(Instance* instance, GameTracker* gameTracker) {
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

void prehst_crawler_OnCollide(Instance* instance, GameTracker* gameTracker) {
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
        } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && ((instance->_F4[0] - 1) >= 2U)) {
            func_80022714(instance, gameTracker);
        }
    }
}

int func_8015AC20_C84A0(Instance* instance, short dist, SVector* out) {
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

short func_8015ADA8_C8628(Instance* instance, short rotStep, short zStep, short dist, int flag) {
    SVector probe;
    SVECTOR savedPos;
    int result;
    int ok;

    result = 0;
    savedPos = instance->position;
    ok = 1;
    if (rotStep != 0) {
        func_80047E64(instance, rotStep * 2);
        if (func_8015AC20_C84A0(instance, dist, &probe) == 0) {
            ok = 0;
        } else {
            instance->position = savedPos;
            func_80047E64(instance, rotStep);
        }
    }
    if (ok != 0) {
        if (func_8015AC20_C84A0(instance, dist, &probe) == 0) {
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

void prehst_eel_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->currentModelAnim = 0;
    instance->currentAnimFrame = 0;
    instance->_D0[3] = 0;
    instance->_F4[0] = 0;
    instance->_100 = 0;
    instance->flags |= 0x800;
    instance->_104 = ((short*)instance->object->animList[1])[1];
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_eel_OnUpdate);

void prehst_eel_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (func_80027500(instance->bspTree, gameTracker)) {
        INSTANCE_PlainDeath(instance, 5, 3, 0);
    }
}

void prehst_stmvent_OnCreate(Instance* instance, GameTracker* gameTracker) {
    MATRIX mat;
    short* introData;

    introData = instance->introData;
    RotMatrix(&instance->intro->rotation, &mat);
    *(int*)&instance->_10C = mat.m[0][2] * 25 >> 10;
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
INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015B47C_C8CFC);
/* near-match (8 diffs: frame a1/a2, mflo v0/v1, z-check load order — scheduler difference):
void func_8015B47C_C8CFC(void* arg0) {
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
extern void func_8015B47C_C8CFC();

void func_8015B5B0_C8E30(Instance* instance) {
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
        *(int*)&instance->_108 += 0x1000;
        if (*(int*)&instance->_108 == 0xC000) {
            instance->_104 = 0;
        }
    } else {
        *(int*)&instance->_108 -= 0x1000;
        if (*(int*)&instance->_108 == -0xC000) {
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
    rot.x = (*(int*)&instance->_10C >> 1) + (*(int*)&instance->_11C >> 12);
    rot.y = (*(int*)&instance->_110 >> 1) + (*(int*)&instance->_11C >> 12);
    rot.z = (*(int*)&instance->_114 >> 1) + (*(int*)&instance->_108 >> 12);
    vel.x = 0;
    vel.y = 0;
    vel.z = 0;
    spray = ((VentSprayData*)func_800170E8(model, model->_14, &instance->position, &rot, 0, D_800EB8A0, func_80017E88, func_8015B47C_C8CFC, 0x14));
    if (spray != NULL) {
        if (*(int*)&instance->_34[2] == 0) {
            *(int*)&instance->_34[2] = func_80050508(instance, 0x112, -0x15E, 0x50, 0xBB8);
        }
        if (instance->_E0[3] == 0) {
            spray->_44 = 0;
        } else {
            spray->_44 = 1;
        }
    }
}

void prehst_stmvent_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->_D0[3] & 1) {
        func_8015B5B0_C8E30(instance);
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
            func_8015B5B0_C8E30(instance);
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

void prehst_stmvent_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void prehst_sptball_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_100 = 0x10;
    instance->_104 = 0x1E;
    *(int*)&instance->_108 = instance->parent->position.z;
    instance->position.z += 0x80;
}

void prehst_sptball_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->_F4[0] == 0) {
        if (instance->_104 >= -0x17) {
            instance->_104 -= 1;
        }
        if (*(int*)&instance->_108 < instance->position.z + instance->_104) {
            instance->position.z = instance->position.z + instance->_104;
        } else {
            instance->_F4[0] = 1;
        }
        instance->position.x = instance->position.x + ((instance->_100 * ((func_8003A6AC(instance->_F4[2]) << 16) >> 16)) >> 12);
        instance->position.y = instance->position.y + ((instance->_100 * ((func_8003A4E0(instance->_F4[2]) << 16) >> 16)) >> 12);
        instance->_F4[2] += 0x20;
    } else if (instance->_F4[0] == 1) {
        if (instance->scale.x >= 0x1F5) {
            instance->scale.x -= 0x199;
            instance->scale.y -= 0x199;
            instance->scale.z -= 0x199;
        } else {
            INSTANCE_KillInstance(instance);
        }
    }
}

void prehst_sptball_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;
    if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player)) {
        func_80022714(instance, gameTracker);
    }
}

void prehst_cavegex_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = instance->introData;
    instance->_F4[0] = 2;
    instance->_F4[2] = 2;
    *(int*)&instance->_108 = instance->position.x;
    *(int*)&instance->_10C = instance->position.y;
    *(int*)&instance->_110 = instance->position.z;
    if (intro != NULL) {
        instance->_104 = intro[0] * intro[0];
        instance->_100 = intro[1] * intro[1];
        return;
    }
    instance->_104 = 0x895440;
    instance->_100 = 0x190000;
}

extern int D_80164480_D1D00;
void func_8015BAFC_C937C(Instance* instance, GameTracker* gameTracker, int arg2) {
    D_80164480_D1D00 ^= 1;
    if (arg2 == 0) {
        if (D_80164480_D1D00 != 0) {
            *(int*)&instance->_114 = 2;
        } else {
            *(int*)&instance->_114 = 1;
        }
    } else {
        *(int*)&instance->_114 = arg2;
    }
    instance->_F4[1] = 1;
    instance->currentAnimFrame = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavegex_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavegex_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavetl_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_cavetl_OnUpdate);

void prehst_cavetl_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;

    if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && (bsp->_0C[5] >= 8U)
        && (instance->_F4[0] != 2)) {
        instance->_F4[0] = 2;
        instance->currentAnimFrame = 0;
    } else if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && (bsp->_0C[5] < 7U)
        && (instance->_F4[0] == 1)) {
        func_80022714(instance, gameTracker);
    } else if ((instance->_F4[0] == 0) && (bsp->instanceSpline != gameTracker->player)) {
        instance->position.x += ((unsigned short*)bsp)[0x14];
        instance->position.y += ((unsigned short*)bsp)[0x15];
        COLLIDE_UpdateAllTransforms(instance, ((SVECTOR*)&((unsigned short*)bsp)[0x14]), gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_tricer_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_tricer_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_tricer_OnCollide);

void prehst_raptor_OnCreate(Instance* instance, GameTracker* gameTracker) {
    unsigned char* fc;
    unsigned short* data;

    fc = (unsigned char*)&instance->_F4[2];
    data = instance->data;
    if (instance->intro->multiSpline == NULL || ((int*)instance->intro->multiSpline)[0] == 0) {
        fc[0xB] = 1;
    } else if (((int*)instance->intro->multiSpline)[1] != 0) {
        fc[0xC] = 1;
    }
    fc[0xA] = fc[0xB] == 0;
    instance->flags |= 0x100000;
    func_80048DE4(instance, fc, fc + 4, 0);
    if (data[3] == 0) {
        func_8004A7B8(instance, 3, 0);
        data[3] = (func_8004A61C(instance) - 1) * data[0];
    }
    instance->_F4[0] = 2;
    instance->_F4[1] = 2;
    if (fc[0xA] == 0) {
        func_8004A7B8(instance, 2, 0);
    } else {
        func_8004A7B8(instance, 0, 0);
    }
    func_80049330(instance);
    data[6] = 0;
}

INCLUDE_RODATA("asm/nonmatchings/level/PREHST", D_80164514_D1D94);

INCLUDE_RODATA("asm/nonmatchings/level/PREHST", D_80164518_D1D98);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_raptor_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_raptor_OnCollide);

void prehst_zviolet_OnCreate(Instance* instance, GameTracker* gameTracker) {
    void* data;

    data = instance->data;
    *(SVECTOR*)&instance->_F4[2] = *(SVECTOR*)data;
    instance->_104 = (int)((char*)data + 4);
    func_8004A7B8(instance, 1, 0);
    if (*(char*)&instance->_F4[2] != 0) {
        instance->flags2 |= 8;
    }
    instance->_10E = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_zviolet_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_zviolet_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015F1F0_CCA70);

void func_8015F290_CCB10(Instance* instance) {
    if (instance->flags & 0x400) {
        instance->flags &= ~0x400;
        PlayerInstance->flags &= ~0x400000;
    }
    ((short*)&instance->_108)[0] = 0;
    ((short*)&instance->_108)[1] = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_gas_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_gas_OnUpdate);

void prehst_gas_OnCollide(Instance* instance, GameTracker* gameTracker) {
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

void prehst_brkbone_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void prehst_brkbone_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void prehst_brkbone_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (func_80027500(instance->bspTree, gameTracker)) {
        if (((short*)&instance->object->_08)[0] >= 2) {
            instance->currentModel = 1;
        }
        INSTANCE_PlainDeath(instance, 5, -1, 0);
    }
}

void prehst_bldrgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[0] = 0;
    instance->flags |= 0x100000;
    if (((int*)instance->introData)[1] != 0) {
        instance->_F4[0] = 1;
    } else {
        instance->_F4[2] = ((int*)instance->introData)[0];
    }
}

void prehst_bldrgen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int* intro;

    intro = instance->introData;
    if (instance->_F4[0] == 1) {
        instance->_F4[2]++;
        if (instance->_F4[2] >= intro[1]) {
            instance->_F4[2] = intro[0];
            instance->_F4[0] = 0;
        }
    } else {
        instance->_F4[2]++;
        if (instance->_F4[2] >= intro[0]) {
            INSTANCE_BirthCachedObject(instance, 0x20);
            instance->_F4[2] = 0;
        }
    }
}

void prehst_bldrgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void prehst_boulder_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[0] = 0;
    *(int*)&instance->_10C = 0;
    instance->flags |= 0x100400;
    *(int*)&instance->_110 = ((int)instance->parent->intro->multiSpline);
    *(int*)&instance->_114 = ((int)instance->parent->introData);
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015F9A4_CD224);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_8015FC2C_CD4AC);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_boulder_OnUpdate);

void prehst_boulder_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;

    bsp = instance->bspTree;
    if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player) && (func_80027578() == 0)) {
        func_8004AAA8(instance, 0x25, 0xC8);
        func_8004AAA8(instance, 0x25, 0);
        func_8002275C(instance, gameTracker);
    }
}

void prehst_spitplt_OnCreate(Instance* instance, GameTracker* gameTracker) {
    char* intro;
    int accum;
    int i;

    intro = instance->introData;
    accum = 0;
    if (intro != NULL) {
        for (i = 0; i < ((int*)intro)[1]; i++) {
            accum += *(short*)(intro + i * 8 + 0xC);
            *(short*)(intro + i * 8 + 0xE) = accum;
        }
    }
    instance->_118 = accum;
    instance->_F4[0] = 0;
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_spitplt_OnUpdate);

void prehst_spitplt_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (func_80027500(instance->bspTree, gameTracker)) {
        instance->_F4[0] = 4;
        instance->currentModelAnim = 1;
        instance->currentAnimFrame = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ptera_OnCreate);

void func_80160840_CE0C0(Instance* instance) {
    BSPTree* bsp;

    bsp = instance->bspTree;
    if (bsp->_06 == 3) {
        instance->position.x = (unsigned short)instance->position.x + ((unsigned short*)bsp)[0x28/2];
        instance->position.y = (unsigned short)instance->position.y + ((unsigned short*)bsp)[0x2A/2];
        instance->position.z = (unsigned short)instance->position.z + ((unsigned short*)bsp)[0x2C/2];
    }
}

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ptera_OnCollide);

INCLUDE_RODATA("asm/nonmatchings/level/PREHST", D_80164598_D1E18);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_ptera_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_801630A0_D0920);

/* near-match kept for reference: matches only with `register int result __asm__("$2")` to pin the
   return register; leader prefers no asm constructs, so it stays commented until properly matched.
int func_801630A0_D0920(Instance* instance) {
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

int func_80163138_D09B8(Instance* instance) {
    instance->rotation.x &= 0xFFF;
    instance->rotation.y &= 0xFFF;
    return instance->rotation.x == 0 && instance->rotation.y == 0;
}

int func_80163160_D09E0(Instance* instance, GameTracker* gameTracker) {
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

int func_80163264_D0AE4(Instance* instance, GameTracker* gameTracker, short base, short min, short angle) {
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

int func_801633DC_D0C5C(Instance* instance, GameTracker* gameTracker) {
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

int func_80163500_D0D80(Instance* instance, GameTracker* gameTracker) {
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

SVECTOR func_80163604_D0E84(Instance* instance, short dist) {
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

SVECTOR func_801636E8_D0F68(Instance* instance, short dist) {
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

void func_801637D0_D1050(Instance* instance, SVECTOR offset, short dist, short angle) {
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

void func_801639D0_D1250(Instance* instance, SVECTOR offset, short dist, short angle) {
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

void func_80163BC8_D1448(Instance* instance, short target, short step) {
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

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163C4C_D14CC);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163EE0_D1760);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", func_80163F94_D1814);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_lavadrp_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_lavadrp_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/PREHST", prehst_lavadrp_OnCollide);
