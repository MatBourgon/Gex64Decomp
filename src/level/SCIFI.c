#include "common.h"

#include "level/SCIFI.h"
#include "MATRIX.h"

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159720_DF540);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_801598A4_DF6C4);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159A08_DF828);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164DF0_EAC10);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E14_EAC34);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159A84_DF8A4);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159B10_DF930);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159D54_DFB74);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80159E3C_DFC5C);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_dust_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_dust_OnUpdate);

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

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_onoff_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_bub_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015AC28_E0A48);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_bub_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_bub_OnCollide);

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

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_stmvent_OnCreate);

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

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E3C_EAC5C);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E40_EAC60);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015B5F0_E1410);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_stmvent_OnUpdate);

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

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_bldbota_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_bldbota_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_abubble_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_abubble_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_abubble_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_acrate_OnCreate);

void scifi_acrate_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_acrate_OnCollide);

void scifi_xa_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[2] = 0;
}


INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_xa_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_apod_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015C5CC_E23EC);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_apod_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_apod_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_alien_OnCreate);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E60_EAC80);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E6C_EAC8C);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164E78_EAC98);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_alien_OnUpdate);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164EA8_EACC8);

INCLUDE_RODATA("asm/nonmatchings/level/SCIFI", D_80164EAC_EACCC);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_alien_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_gas_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_gas_OnUpdate);

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

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_8015E234_E4054);

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

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_80161ED0_E7CF0);

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

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", func_801621D4_E7FF4);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rt_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rt_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/SCIFI", scifi_rtblast_OnCreate);

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
