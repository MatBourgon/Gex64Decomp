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

void func_8015B4D4_C3E54(Instance* instance, short* arg1);
int func_8015B510_C3E90(Instance* instance, short* arg1, int arg2, short arg3);
void func_8015B5F0_C3F70(Instance* instance, short* arg1);
void func_8015BB44_C44C4(Instance* instance, short* arg1);

void func_8015A084_C2A04(Instance* instance, short arg1, short arg2, short* arg3) {
    Instance* player = gameTracker8->player;

    if (instance->flags2 & 0x10) {
        if (arg3[0x40 / 2] == 0) {
            func_8015B39C_C3D1C(instance, arg1, arg2);
        } else if ((short)func_8004B23C(instance, player) < 0x280) {
            arg3[0x14 / 2] = 6;
            if (func_8015B510_C3E90(instance, arg3, 1, 0) != 0) {
                func_8015B4D4_C3E54(instance, arg3);
            }
        } else {
            func_8015B5F0_C3F70(instance, arg3);
        }
    }
}

void func_8015A150_C2AD0(Instance* instance, short arg1, short arg2) {
    if (instance->flags2 & 0x10) {
        func_8015B39C_C3D1C(instance, arg1, arg2);
    }
}

int func_8015A18C_C2B0C(Instance* instance) {
    if (instance->flags2 & 0x10) {
        PlayerInstance->currentMainState = 2;
        gameTracker8->player->work0 &= ~0x1000000;
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
    c[4] = c[0x18];
    c[5] = c[0x19];
    c[0x17] = c[6] = c[0x1A];
}

void func_8015A2E0_C2C60(Camera* camera, SVECTOR* arg1, SVector* arg2) {
    camera->cameraCore.position = *arg1;
    *(SVector*)&camera->cameraCore._08[0x28 / 4] = *arg2;
    *(SVECTOR*)&camera->cameraCore._08[0x8 / 4] = *arg1;
    *(SVector*)&camera->cameraCore._08[0x10 / 4] = *arg2;
    *(SVector*)&camera->cameraCore._08[0] = *arg2;
    ((short*)camera->cameraCore._08)[0x26 / 2] = arg2->z;
    CAMERA_SetMode(camera, 8);
}

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
        if (instance->work0 == 0) {
            func_80022738(instance, gameTracker);
            data[2] |= 0x4000;
        }
        data[2] |= 0x8000;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moo_OnCollide);

void func_8015B2FC_C3C7C(Instance* instance, int arg1, int arg2) {
    SVECTOR vec;

    if (instance->currentModelAnim == 0) {
        if (instance->currentAnimFrame == 6) {
            MATRIX* m = &instance->oldMatrix[2];

            vec.x = m->l[0];
            vec.y = m->l[1];
            vec.z = m->l[2];
            func_8015D544_C5EC4(&vec, 8, 0x1E, arg2);
        } else if (instance->currentAnimFrame == 0x11) {
            MATRIX* m = &instance->oldMatrix[6];

            vec.x = m->l[0];
            vec.y = m->l[1];
            vec.z = m->l[2];
            func_8015D544_C5EC4(&vec, 8, 0x1E, arg2);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015B39C_C3D1C);

void func_8015B4D4_C3E54(Instance* instance, short* arg1) {
    arg1[0x40/2]--;
    instance->currentModelAnim = 2;
    instance->currentAnimFrame = 0xE;
    instance->flags2 &= ~0x10;
    arg1[6] = 6;
}

int func_8015B510_C3E90(Instance* instance, short* arg1, int arg2, short arg3) {
    short angle;
    int result = 0;

    if (arg2 != 0) {
        arg1[0x4 / 2] |= 1;
    } else {
        arg1[0x12 / 2] = arg3;
        arg1[0x4 / 2] &= ~1;
    }
    if (func_8015B9D0_C4350(instance, arg1, &angle) != 0) {
        result = 1;
        instance->rotation.z = angle + 0x400;
    } else {
        instance->flags2 &= ~0x10;
        if (instance->currentModelAnim != 0) {
            instance->currentModelAnim = 0;
            instance->currentAnimFrame = 0;
        }
        arg1[0xC / 2] = 9;
    }
    return result;
}

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

void func_8015BB44_C44C4(Instance* instance, short* arg1) {
    unsigned short raw = arg1[0x14 / 2];
    short state = raw - 1;

    switch (state) {
        case 1:
            func_8015B614_C3F94(instance, arg1);
            break;
        case 0:
            func_8015B5F0_C3F70(instance, arg1);
            break;
        case 6:
            func_8015B674_C3FF4(instance, arg1);
            break;
        case 7:
            func_8015B6D4_C4054(instance, arg1);
            break;
        case 5:
            func_8015B4D4_C3E54(instance, arg1);
            break;
        case 10:
            func_8015B734_C40B4(instance, arg1);
            break;
        case 8:
            func_8015B510_C3E90(instance, arg1, 1, 0);
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015BC00_C4580);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015BDB4_C4734);

void func_8015C2E0_C4C60(SVECTOR* arg0, short* arg1, short* arg2, int arg3) {
    SVECTOR bounds[4];
    SVECTOR pts[3];

    pts[0] = *arg0;
    bounds[0].x = -0xB40;
    bounds[1].x = 0x8C0;
    bounds[0].y = -0x280;
    bounds[1].y = 0x280;
    bounds[2].x = -0x1040;
    bounds[3].x = 0xDC0;
    bounds[2].y = -0x780;
    bounds[3].y = 0x780;
    func_8015BDB4_C4734(bounds, arg3);
    pts[2].z = arg0->z + 0xB4;
    pts[1].z = arg0->z + 0xB4;
    func_8015BC00_C4580(arg1, &pts[1], &pts[2], 0x200);
    func_8015BC00_C4580(arg2, &pts[2], &pts[1], 0x200);
}

void mooshu_moolevr_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x400;
}


INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moolevr_OnUpdate);

void func_8015C780_C5100(Instance* instance, GameTracker* gameTracker);

void mooshu_moolevr_OnCollide(Instance* instance, GameTracker* gameTracker) {
    Instance* target;
    Instance* target2;
    SVECTOR pos;

    if (func_80027500(instance->bspTree, gameTracker)) {
        if (instance->currentMainState == 0) {
            target = 0;
            target2 = 0;
            if (instance->intro->_04[0] >= 3) {
                target = ((Intro**)instance->intro->_04)[1]->instance;
                target2 = ((Intro**)instance->intro->_04)[3]->instance;
            }
            if (target != 0 && target2 != 0) {
                pos = target2->position;
                pos.z += 0x320;
                func_8015DA78_C63F8(target2, target, 7, &pos, 0xF);
            }
            func_8015C780_C5100(instance, gameTracker);
            func_8015B8B0_C4230(target, gameTracker);
            instance->currentSubState = 4;
        }
    }
}

int func_8015C6D0_C5050(Instance* instance) {
    if (instance->rotation.x == 0 || (instance->currentMainState == 3 && instance->rotation.x < 0x400)) {
        return 1;
    }
    return 0;
}

void func_8015C708_C5088(Instance* instance, GameTracker* gameTracker)
{
    instance->work0 = 0;
}

void func_8015C710_C5090(Instance* instance, GameTracker* gameTracker) {
    instance->work0 = 0;
    if (instance->currentMainState == 1) {
        instance->work2 = 0x10;
        instance->currentSubState = 0;
        instance->currentMainState = 3;
        func_80050508(instance, 0x126, (short)((rand() & 0x1F) - 0xF), 0xC8, 0x2710);
    }
}

void func_8015C780_C5100(Instance* instance, GameTracker* gameTracker) {
    if (instance->work0 == 0) {
        instance->currentSubState = 0;
        instance->work2 = 0;
        if (instance->currentMainState == 1) {
            instance->work0 = 0x14;
            instance->currentMainState = 3;
            func_80050508(instance, 0x126, (short)((rand() & 0x1F) - 0xF), 0xC8, 0x2710);
        } else if (instance->currentMainState == 0) {
            instance->work0 = 0x14;
            instance->currentMainState = 2;
            instance->work1 = 0x40;
        }
    }
}

void mooshu_moosprk_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_E0[1] = -0x10;
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_moosprk_OnUpdate);

void mooshu_moosprk_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp = instance->bspTree;

    if (bsp->_06 == 1 && bsp->instanceSpline == gameTracker->player && bsp->_0C[5] < 6) {
        instance->work2 = 0x5A;
        func_80022714(instance, gameTracker);
    } else if (bsp->_06 == 2 || bsp->_06 == 5 || bsp->_06 == 3 || bsp->_06 == 1) {
        instance->position.x += bsp->localOffset.x;
        instance->position.y += bsp->localOffset.y;
        instance->position.z += bsp->localOffset.z;
        COLLIDE_UpdateAllTransforms(instance, &bsp->localOffset);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_jacob_OnCreate);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_jacob_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D084_C5A04);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D190_C5B10);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D240_C5BC0);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D544_C5EC4);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D6B0_C6030);

void func_8015D7B4_C6134(Instance* instance, GameTracker* gameTracker)
{
    WORK_AS_IDX(short, instance->work0, 0)++;
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015D7C8_C6148);

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", func_8015DA78_C63F8);

extern void func_80017AB8(short* arg0, short arg1);
void mooshu_ebolt_OnCreate(Instance* instance, GameTracker* gameTracker) {
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

void mooshu_ebolt_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    func_8015D7C8_C6148(instance, instance->work1);
    if (instance->work0 > 0) {
        instance->work0--;
    } else if (instance->work0 == 0) {
        func_8002E350(instance);
    }
}

void mooshu_vandb_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0x400;
}

INCLUDE_ASM("asm/nonmatchings/level/MOOSHU", mooshu_vandb_OnUpdate);
