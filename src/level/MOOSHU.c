#include "common.h"

#include "level/MOOSHU.h"

/* quantize a stick/velocity pair into a direction code (0-3) */
void func_80159720_C20A0(short* out, int arg1, short* vec) {
    if (vec[0] > 0x200) {
        if (vec[1] > 0x280) {
            *out = 1;
        } else if (vec[1] < -0x280) {
            *out = 0;
        }
    } else if (vec[0] < -0x480) {
        if (vec[1] > 0x280) {
            *out = 3;
        } else if (vec[1] < -0x280) {
            *out = 2;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_80159798_C2118);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_801599E8_C2368);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_80159B78_C24F8);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_80159D0C_C268C);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_80159EC4_C2844);

void func_8015A07C_C29FC(Instance* instance, GameTracker* gameTracker) {
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015A084_C2A04);

void func_8015A150_C2AD0(Instance* instance, short arg1, short arg2) {
    if (instance->flags2 & 0x10) {
        func_8015B39C_C3D1C(instance, arg1, arg2);
    }
}

int func_8015A18C_C2B0C(Instance* instance) {
    if (instance->flags2 & 0x10) {
        PlayerInstance->_F4[0] = 2;
        gameTracker8->player->_F4[2] &= ~0x1000000;
        return 1;
    }
    return 0;
}

void func_8015A1E0_C2B60(Instance* instance, int arg1, int arg2, short* arg3) {
    short angle;

    if (func_8015B9D0_C4350(instance, arg3, &angle) != 0) {
        instance->rotation.z = angle + 0x400;
        func_8015BB44_C44C4(instance, arg3);
    } else {
        func_8004ACB0(&instance->rotation.z, (short)(angle + 0x400), arg3[8]);
    }
}

/* snap the camera to pos and reset its focus history */
void func_8015A258_C2BD8(SVECTOR* pos, int arg1, GameTracker* gameTracker) {
    Camera* cam;
    unsigned short* c;

    cam = gameTracker->camera;
    c = (unsigned short*)cam;
    cam->cameraCore.position.x = pos->x;
    cam->cameraCore.position.y = pos->y;
    cam->cameraCore.position.z = pos->z;
    func_80003A68(cam);
    CAMERA_SetMode(cam, 8);
    c[0xC] = c[0x18];
    c[0xD] = c[0x19];
    c[0xE] = c[0x1A];
    cam->cameraCore.rx = c[0x18];
    cam->cameraCore.ry = c[0x19];
    c[0x17] = cam->cameraCore.rz = c[0x1A];
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015A2E0_C2C60);

void func_8015A398_C2D18()
{
    volatile char _[0x40];
}

INCLUDE_RODATA("asm/nonmatchings/level/MOOSHU", D_8015DDE0_C6760);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moo_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moo_OnUpdate);

void mooshu_moobar_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->intro = NULL;
    instance->flags = (instance->flags | 0x100C00) & ~1;
}

void mooshu_moobar_OnCollide(Instance* instance, GameTracker* gameTracker) {
    unsigned short* data;

    if (instance->parent != 0) {
        data = (unsigned short*)instance->parent->object->data;
        if (instance->_F4[2] == 0) {
            func_80022738(instance, gameTracker);
            data[2] |= 0x4000;
        }
        data[2] |= 0x8000;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moo_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015B2FC_C3C7C);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015B39C_C3D1C);

void func_8015B4D4_C3E54(Instance* instance, short* arg1) {
    arg1[0x40/2]--;
    instance->currentModelAnim = 2;
    instance->currentAnimFrame = 0xE;
    instance->flags2 &= ~0x10;
    arg1[6] = 6;
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015B510_C3E90);

void func_8015B5C0_C3F40(Instance* instance, short* arg1) {
    arg1[5] = (gameTracker8->player->position.y > 0) ? -1 : 1;
}

void func_8015B5F0_C3F70(Instance* instance, short* arg1) {
    instance->currentModelAnim = 0;
    instance->currentAnimFrame = 0;
    instance->flags2 &= ~0x10;
    arg1[6] = 1;
}

void func_8015C710_C5090(Instance* instance, GameTracker* gameTracker);

void func_8015B614_C3F94(Instance* instance, short* arg1) {
    Instance* target;

    instance->currentModelAnim = 4;
    instance->flags2 &= ~0x10;
    instance->currentAnimFrame = 0;
    arg1[0xC / 2] = 2;
    *(unsigned short*)&arg1[0x4 / 2] &= 0xEFF7;
    target = ((Instance**)arg1)[0];
    if (target != 0) {
        func_8015C710_C5090(target, gameTracker8);
    }
}

void func_8015B674_C3FF4(Instance* instance, short* arg1) {
    instance->flags2 &= ~0x10;
    if ((rand() % 4) != 0) {
        instance->currentModelAnim = 8;
    } else {
        instance->currentModelAnim = 6;
    }
    instance->currentAnimFrame = 0;
    arg1[6] = 7;
}

void func_8015B6D4_C4054(Instance* instance, short* arg1) {
    instance->flags2 &= ~0x10;
    if ((rand() % 4) != 0) {
        instance->currentModelAnim = 6;
    } else {
        instance->currentModelAnim = 8;
    }
    instance->currentAnimFrame = 0;
    arg1[6] = 8;
}

void func_8015B734_C40B4(Instance* instance, short* arg1) {
    instance->currentModelAnim = 7;
    instance->currentAnimFrame = 0;
    instance->flags2 &= ~0x10;
    arg1[6] = 0xB;
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015B75C_C40DC);

INCLUDE_RODATA("asm/nonmatchings/level/MOOSHU", D_8015DDFC_C677C);

INCLUDE_RODATA("asm/nonmatchings/level/MOOSHU", D_8015DE08_C6788);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015B8B0_C4230);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015B9D0_C4350);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015BB44_C44C4);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015BC00_C4580);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015BDB4_C4734);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015C2E0_C4C60);

void mooshu_moolevr_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x400;
}


INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moolevr_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moolevr_OnCollide);

int func_8015C6D0_C5050(Instance* instance) {
    if (instance->rotation.x == 0 || (instance->_F4[0] == 3 && instance->rotation.x < 0x400)) {
        return 1;
    }
    return 0;
}

void func_8015C708_C5088(Instance* instance, GameTracker* gameTracker)
{
    instance->_F4[2] = 0;
}

void func_8015C710_C5090(Instance* instance, GameTracker* gameTracker) {
    instance->_F4[2] = 0;
    if (instance->_F4[0] == 1) {
        instance->_104 = 0x10;
        instance->_F4[1] = 0;
        instance->_F4[0] = 3;
        func_80050508(instance, 0x126, (short)((rand() & 0x1F) - 0xF), 0xC8, 0x2710);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015C780_C5100);

void mooshu_moosprk_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_E0[1] = -0x10;
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moosprk_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moosprk_OnCollide);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_jacob_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_jacob_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D084_C5A04);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D190_C5B10);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D240_C5BC0);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D544_C5EC4);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D6B0_C6030);

void func_8015D7B4_C6134(Instance* instance, GameTracker* gameTracker)
{
    instance->_F0[6]++;
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D7C8_C6148);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015DA78_C63F8);

extern void func_80017AB8(short* arg0, short arg1);
void mooshu_ebolt_OnCreate(Instance* instance, GameTracker* gameTracker) {
    if (instance->flags & 0x20000) {
        if (*(int*)&instance->_108 != 0) {
            func_80017AB8(*(short**)&instance->_108, 0);
            *(int*)&instance->_108 = 0;
        }
    } else {
        instance->flags |= 0x100000;
        instance->flags |= 0x10400;
        instance->object->oflags |= 8;
    }
}

void mooshu_ebolt_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    func_8015D7C8_C6148(instance, instance->_100);
    if (instance->_F4[2] > 0) {
        instance->_F4[2]--;
    } else if (instance->_F4[2] == 0) {
        func_8002E350(instance);
    }
}

void mooshu_vandb_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x400;
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_vandb_OnUpdate);
