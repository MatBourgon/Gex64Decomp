#include "common.h"

#include "level/GILLIG.h"
#include "INSTANCE.h"
#include "OBTABLE.h"

void gillig_couldrn_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    WORK_AS(int, instance->work3) = 3;
    instance->work0 = 0x5A;
}

INCLUDE_RODATA("asm/nonmatchings/level/GILLIG", D_8015A920_9CF00);

extern short func_8003A6AC(int);
extern short func_8003A4E0(int);

void gillig_couldrn_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int state;

    if (WORK_AS(int, instance->work3) == 3) {
        instance->work0 += 1;
        if ((instance->work0 % 155) == 0) {
            instance->currentMainState = 1;
            ((Intro**)instance->intro->_04)[2]->instance->currentSubState = 1;
            ((Intro**)instance->intro->_04)[3]->instance->currentSubState = 1;
            ((Intro**)instance->intro->_04)[4]->instance->currentSubState = 1;
            instance->work0 = 0;
        }
    } else if (WORK_AS(int, instance->work3) < 3) {
        if ((instance->work0 % 189) == 0) {
            instance->currentMainState = 1;
            ((Intro**)instance->intro->_04)[2]->instance->currentSubState = 1;
            ((Intro**)instance->intro->_04)[3]->instance->currentSubState = 1;
            ((Intro**)instance->intro->_04)[4]->instance->currentSubState = 1;
            instance->work0 = 0;
        }
        if ((instance->work1 % 189) == 0) {
            instance->currentMainState = 2;
            ((Intro**)instance->intro->_04)[2]->instance->currentSubState = 1;
            ((Intro**)instance->intro->_04)[3]->instance->currentSubState = 1;
            ((Intro**)instance->intro->_04)[4]->instance->currentSubState = 1;
            instance->work1 = 0;
        }
        instance->work0 += 1;
        instance->work1 += 1;
    }
    state = instance->currentMainState;
    if (state == 1) {
        Object* obj;
        Object* fcObj;
        Instance* first;
        Instance* second;
        Instance* third;
        int count;

        obj = OBTABLE_FindObject("tikifb__");
        fcObj = OBTABLE_FindObject("tikifc__");
        count = instance->work2;
        first = INSTANCE_BirthObject(instance, fcObj);
        second = INSTANCE_BirthObject(instance, obj);
        third = INSTANCE_BirthObject(instance, obj);
        if (count == 0) {
            first->currentModel = 1;
            first->work0 = -0x80;
            second->work0 = 0;
            third->work0 = 0x80;
        } else if (count == state) {
            first->currentModel = 1;
            first->work0 = 0;
            second->work0 = -0x80;
            third->work0 = 0x80;
        } else {
            first->currentModel = 1;
            first->work0 = 0x80;
            second->work0 = 0;
            third->work0 = -0x80;
            instance->work2 = -1;
        }
        instance->currentMainState = 0;
        instance->work2 += 1;
    } else if (state == 2) {
        Object* obj;
        Instance* fire;

        obj = OBTABLE_FindObject("tikifir_");
        fire = INSTANCE_BirthObject(instance, obj);
        fire->position.x = fire->position.x + (func_8003A6AC(0x60) * 39 >> 6);
        fire->position.y = fire->position.y + (func_8003A4E0(0x60) * 39 >> 6);
        fire->position.z = fire->position.z + 0x80;
        fire->rotation.z = -0x3A0;
        fire->work0 = 0x18;
        fire = INSTANCE_BirthObject(instance, obj);
        fire->position.x = fire->position.x + (func_8003A6AC(0x7A0) * 39 >> 6);
        fire->position.y = fire->position.y + (func_8003A4E0(0x7A0) * 39 >> 6);
        fire->position.z = fire->position.z + 0x80;
        fire->rotation.z = 0x3A0;
        fire->work0 = -0x18;
        instance->currentMainState = 0;
    }
    if (PlayerInstance->work0 & 0x400000) {
        func_800396E0("map", "map5", gameTracker);
    }
}

void gillig_couldrn_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void gillig_tikifb_OnCreate(Instance* instance, GameTracker* gameTracker) {

    if (instance->flags & 0x20000) {
        if (instance->object->oflags2 & 4) {
            if (instance->flags2 & 0x2000) {
                instance->flags2 &= ~0x2000;
                func_800331BC(*(int*)&instance->_34[4]);
                *(int*)&instance->_34[4] = 0;
            }
        }
    } else {
        instance->flags |= 0x10000;
    }
}

extern short ratan2(int, int);

void gillig_tikifb_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int state;
    int px, py;

    state = instance->currentMainState;
    if (state == 0) {
        if (instance->position.z < instance->intro->position.z + 0x320) {
            instance->position.z = instance->position.z + 0x30;
            return;
        }
        px = instance->position.x;
        py = instance->position.y;
        instance->work1 = ratan2(py - PlayerInstance->position.y, px - PlayerInstance->position.x) + 0x800;
        instance->currentMainState = 1;
        return;
    }
    if (state == 1) {
        if (instance->intro->position.z + 0x100 < instance->position.z) {
            instance->position.x += (func_8003A6AC(instance->work1 + instance->work0) * 3 >> 7);
            instance->position.y += (func_8003A4E0(instance->work1 + instance->work0) * 3 >> 7);
            instance->position.z -= 0x1E;
            return;
        }
        instance->position.x += (func_8003A6AC(instance->work1 + instance->work0) * 25 >> 10);
        instance->position.y += (func_8003A4E0(instance->work1 + instance->work0) * 25 >> 10);
        return;
    }
    if (state == 2) {
        instance->position.x += (func_8003A6AC((instance->work1 + instance->work0) - 0x800) * 3 >> 6);
        instance->position.y += (func_8003A4E0((instance->work1 + instance->work0) - 0x800) * 3 >> 6);
        return;
    }
    if (state == 3) {
        instance->work2 = instance->work2 + 1;
        if (instance->work2 >= 4) {
            INSTANCE_KillInstance(instance);
        }
    }
}

extern int D_8015A960_9CF40;
extern int D_8015A964_9CF44;

void gillig_tikifb_OnCollide(Instance* instance, GameTracker* gameTracker) {
    SVECTOR point;
    int playerState;
    BSPTree* bsp  = instance->bspTree;
    int six = bsp->_06;

    if ((six == 1) && (bsp->instanceSpline == gameTracker->player)) {
        playerState = PlayerInstance->currentSubState;
        if ((playerState == 0x10) || (playerState == 0x2000)) {
            if ((func_80027578() == 0) && (instance->currentModel == six) && (instance->currentMainState != 2)) {
                instance->currentMainState = 2;
                func_80050508(instance, 0xBF, -0x5A, 0x64, 0x2710);
            }
        } else {
            if (instance->currentModel == 0) {
                func_80022714(instance, gameTracker);
                return;
            }
            instance->currentMainState = 3;
        }
    } else if (((bsp->_06 == 2) || (bsp->_06 == 5) || (bsp->_06 == 3)) && (bsp->instanceSpline != PlayerInstance)) {
        if (bsp->_06 == 3) {
            if (!(((short*)bsp->_0C)[3] & 0x8000)) {
                func_8004AAE4(bsp, &point, gameTracker);
                if (point.z < 0xFC3) {
                    if (instance->currentModel == 0) {
                        INSTANCE_KillInstance(instance);
                        return;
                    }
                    instance->currentMainState = 2;
                }
            }
        } else if (*(int*)bsp->instanceSpline->object->parentName == D_8015A960_9CF40
                   && ((int*)bsp->instanceSpline->object->parentName)[1] == D_8015A964_9CF44) {
            *(int*)&instance->parent->work3 = *(int*)&instance->parent->work3 - 1;
            if (*(int*)&instance->parent->work3 == 2) {
                instance->parent->work0 = 0xBD;
                instance->parent->work1 = 0x7C;
            }
            INSTANCE_KillInstance(instance);
            bsp->instanceSpline->currentMainState = 3;
            bsp->instanceSpline->currentModelAnim = 2;
            bsp->instanceSpline->currentAnimFrame = 0;
            bsp->instanceSpline->flags2 &= ~0x10;
        }
    }
}

void gillig_tikifir_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->scale.z = 1;
    instance->work2 = 0;
    WORK_AS(int, instance->work3) = 1;
    WORK_AS(int, instance->work4) = ((rand() & 0x1F) - 0x10);
}

void gillig_tikifir_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short newScale;

    if (instance->work2 != 0) {
        if (func_800506B8(instance, instance->work2, WORK_AS_IDX(short, instance->work4, 1), WORK_AS_IDX(short, instance->work3, 1), 0xDAC) == 0) {
            func_800331BC(instance->work2);
            instance->work2 = 0;
        }
    } else {
        instance->work2 = func_80050508(instance, 0x69, WORK_AS_IDX(short, instance->work4, 1), WORK_AS_IDX(short, instance->work3, 1), 0xDAC);
    }
    if (instance->currentMainState == 0) {
        WORK_AS(int, instance->work3) = WORK_AS(int, instance->work3) + 9;
        newScale = instance->scale.z + 0x200;
        instance->scale.z = newScale;
        if (newScale >= 0x1000) {
            instance->currentMainState = 1;
        }
    } else if (instance->currentMainState == 1) {
        instance->work1 = instance->work1 + 1;
        if ((instance->work1 >= 0x4D))
        {
            instance->currentMainState = 2;
        }
        else
        {
            instance->rotation.z = instance->rotation.z + instance->work0;
            instance->position.x = instance->parent->position.x + (func_8003A6AC(instance->rotation.z + 0x400) * 39 >> 6);
            instance->position.y = instance->parent->position.y + (func_8003A4E0(instance->rotation.z + 0x400) * 39 >> 6);
            if (((int**)((int**)instance->intro->_04)[1])[0x24/4][0x108/4] == 0)
               instance->currentMainState = 2;
        }
    } else if (instance->currentMainState == 2) {
        WORK_AS(int, instance->work3) = WORK_AS(int, instance->work3) - 9;
        if (WORK_AS(int, instance->work3) <= 0) {
            WORK_AS(int, instance->work3) = 1;
        }
        newScale = instance->scale.z - 0x200;
        instance->scale.z = newScale;
        if (newScale < 2) {
            if (instance->work2 != 0) {
                func_800331BC(instance->work2);
            }
            INSTANCE_KillInstance(instance);
        }
    }
}

void gillig_tikifir_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;

    bsp = instance->bspTree;
    if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player)
        && ((bsp->_0C[5] < 6U) && (PlayerInstance->currentSubState != 0x200000))) {
        func_800223F8(gameTracker8, 0x64, 0);
    }
}

void gillig_hedhntr_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->intro->flags &= ~0x80;
    instance->currentModelAnim = 4;
    instance->currentMainState = -1;
    instance->flags2 &= ~0x10;
}

extern short D_8015A920_9CF00[];

void gillig_hedhntr_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short* introData;
    int state;

    state = instance->currentMainState;
    introData = instance->introData;
    if (state == -1) {
        func_8002DAF8(instance, -1);
        if (instance->flags2 & 0x10) {
            instance->currentMainState = 0;
            instance->currentAnimFrame = 0;
            instance->flags2 &= ~0x10;
            if (*introData == 0) {
                instance->currentModelAnim = 0;
                return;
            }
            instance->currentModelAnim = 1;
        }
    } else if (state == 0) {
        int anim;
        int link;

        func_8002DAF8(instance, -1);
        if (instance->flags2 & 0x10) {
            if (instance->currentSubState == 1) {
                instance->currentSubState = 0;
                instance->currentModelAnim = 3;
                instance->currentAnimFrame = 0;
            } else {
                anim = instance->currentModelAnim;
                if (anim == 3) {
                    if (!(rand() % 2)) {
                        instance->currentModelAnim = 1;
                        instance->currentAnimFrame = 0;
                    } else {
                        instance->currentModelAnim = 0;
                        instance->currentAnimFrame = 0;
                    }
                } else if (anim < 2U) {
                    if (!(rand() % 4)) {
                        instance->currentModelAnim = 1;
                        instance->currentAnimFrame = 0;
                    } else {
                        instance->currentModelAnim = 0;
                        instance->currentAnimFrame = 0;
                    }
                }
            }
            instance->flags2 &= ~0x10;
        }
        link = ((int**)((int**)instance->intro->_04)[1])[0x24/4][0x108/4];
        if (link == 1) {
            instance->currentMainState = link;
            instance->currentModelAnim = 0;
            if (*introData == 0) {
                instance->work0 = 0x9D2;
                instance->rotation.z = 0x5D2 - instance->intro->rotation.z;
            } else if (*introData == link) {
                instance->work0 = 0xC22;
                instance->rotation.z = 0x822 - instance->intro->rotation.z;
            } else {
                instance->work0 = 0xE66;
                instance->rotation.z = 0xA66 - instance->intro->rotation.z;
            }
            if (*introData != 2) {
                instance->work1 = *introData + 1;
                return;
            }
            instance->work1 = 1;
            instance->work2 = 0;
        }
    } else if (state == 1) {
        int accel;
        int idx;

        func_8002DAF8(instance, -1);
        instance->position.x = ((Intro**)instance->intro->_04)[1]->instance->position.x + (func_8003A6AC(instance->work0) * 39 >> 6);
        instance->position.y = ((Intro**)instance->intro->_04)[1]->instance->position.y + (func_8003A4E0(instance->work0) * 39 >> 6);
        if (instance->work2 != 0) {
            idx = instance->work1;
            accel = instance->work0;
            if (accel < D_8015A920_9CF00[idx]) {
                instance->work0 = accel + 8;
            } else {
                if (idx != 2) {
                    instance->work1 = idx + 1;
                } else {
                    instance->work1 = 1;
                    instance->work2 = 0;
                }
                instance->currentMainState = 2;
            }
        } else {
            idx = instance->work1;
            accel = instance->work0;
            if (D_8015A920_9CF00[idx] < accel) {
                instance->work0 = accel - 8;
            } else {
                if (idx != 0) {
                    instance->work1 = idx - 1;
                } else {
                    instance->work1 = 1;
                    instance->work2 = 1;
                }
                instance->currentMainState = 2;
            }
        }
        instance->rotation.z = (instance->work0 - instance->intro->rotation.z) - 0x400;
        return;
    } else if (state == 2) {
        func_8002DAF8(instance, -1);
        if (((int**)((int**)instance->intro->_04)[1])[0x24/4][0xFC/4] == 0x7C) {
            instance->currentMainState = 1;
        }
    } else if (state == 3) {
        int link;

        func_8002DAF8(instance, -1);
        if (instance->flags2 & 0x10) {
            instance->flags |= 0x800;
            instance->currentAnimFrame = ((short*)instance->object->animList[instance->currentModelAnim])[1] - 1;
            instance->intro->flags |= 0x80;
            instance->currentMainState = 4;
            link = ((int**)((int**)instance->intro->_04)[1])[0x24/4][0x108/4];
            if (link == 2) {
                func_80050A80(0, 1);
            } else if (link == 1) {
                func_80050A80(0, 2);
            }
            if (((int**)((int**)instance->intro->_04)[1])[0x24/4][0x108/4] == 0) {
                func_800278EC(PlayerInstance);
            }
        }
    }
}

void gillig_hedhntr_OnCollide(Instance* instance, GameTracker* gameTracker)
{
}

INCLUDE_RODATA("asm/nonmatchings/level/GILLIG", D_8015A960_9CF40);

INCLUDE_RODATA("asm/nonmatchings/level/GILLIG", D_8015A964_9CF44);
