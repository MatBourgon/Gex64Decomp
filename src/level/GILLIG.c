#include "common.h"

#include "level/GILLIG.h"

void gillig_couldrn_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    *(int*)&instance->_108 = 3;
    instance->_F4[2] = 0x5A;
}

INCLUDE_RODATA("asm/nonmatchings/level/GILLIG", D_8015A920_9CF00);

INCLUDE_ASM("asm/nonmatchings/level/GILLIG", gillig_couldrn_OnUpdate);

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

extern short func_8003A6AC(int);
extern short func_8003A4E0(int);
extern short ratan2(int, int);

void gillig_tikifb_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int state;
    int px, py;

    state = instance->_F4[0];
    if (state == 0) {
        if (instance->position.z < instance->intro->position.z + 0x320) {
            instance->position.z = instance->position.z + 0x30;
            return;
        }
        px = instance->position.x;
        py = instance->position.y;
        instance->_100 = ratan2(py - PlayerInstance->position.y, px - PlayerInstance->position.x) + 0x800;
        instance->_F4[0] = 1;
        return;
    }
    if (state == 1) {
        if (instance->intro->position.z + 0x100 < instance->position.z) {
            instance->position.x = (unsigned short)instance->position.x + (func_8003A6AC(instance->_100 + instance->_F4[2]) * 3 >> 7);
            instance->position.y = (unsigned short)instance->position.y + (func_8003A4E0(instance->_100 + instance->_F4[2]) * 3 >> 7);
            instance->position.z = (unsigned short)instance->position.z - 0x1E;
            return;
        }
        instance->position.x = (unsigned short)instance->position.x + (func_8003A6AC(instance->_100 + instance->_F4[2]) * 25 >> 10);
        instance->position.y = (unsigned short)instance->position.y + (func_8003A4E0(instance->_100 + instance->_F4[2]) * 25 >> 10);
        return;
    }
    if (state == 2) {
        instance->position.x = (unsigned short)instance->position.x + (func_8003A6AC((instance->_100 + instance->_F4[2]) - 0x800) * 3 >> 6);
        instance->position.y = (unsigned short)instance->position.y + (func_8003A4E0((instance->_100 + instance->_F4[2]) - 0x800) * 3 >> 6);
        return;
    }
    if (state == 3) {
        instance->_104 = instance->_104 + 1;
        if (instance->_104 >= 4) {
            INSTANCE_KillInstance(instance);
        }
    }
}

extern int D_8015A960_9CF40;
extern int D_8015A964_9CF44;

void gillig_tikifb_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;
    SVECTOR point;
    int playerState;
    int type;

    bsp = instance->bspTree;
    type = bsp->_06;
    if ((type == 1) && (bsp->instanceSpline == gameTracker->player)) {
        playerState = PlayerInstance->_F4[1];
        if ((playerState == 0x10) || (playerState == 0x2000)) {
            if ((func_80027578() == 0) && (instance->currentModel == type) && (instance->_F4[0] != 2)) {
                instance->_F4[0] = 2;
                func_80050508(instance, 0xBF, -0x5A, 0x64, 0x2710);
            }
        } else {
            if (instance->currentModel == 0) {
                func_80022714(instance, gameTracker);
                return;
            }
            instance->_F4[0] = 3;
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
                    instance->_F4[0] = 2;
                }
            }
        } else if (*(int*)bsp->instanceSpline->object->parentName == D_8015A960_9CF40
                   && ((int*)bsp->instanceSpline->object->parentName)[1] == D_8015A964_9CF44) {
            *(int*)&instance->parent->_108 = *(int*)&instance->parent->_108 - 1;
            if (*(int*)&instance->parent->_108 == 2) {
                instance->parent->_F4[2] = 0xBD;
                instance->parent->_100 = 0x7C;
            }
            INSTANCE_KillInstance(instance);
            bsp->instanceSpline->_F4[0] = 3;
            bsp->instanceSpline->currentModelAnim = 2;
            bsp->instanceSpline->currentAnimFrame = 0;
            bsp->instanceSpline->flags2 &= ~0x10;
        }
    }
}

void gillig_tikifir_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->scale.z = 1;
    instance->_104 = 0;
    *(int*)&instance->_108 = 1;
    *(int*)&instance->_10C = ((rand() & 0x1F) - 0x10);
}

void gillig_tikifir_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short newScale;

    if (instance->_104 != 0) {
        if (func_800506B8(instance, instance->_104, *(short*)&instance->_10E, *(short*)&instance->_10A, 0xDAC) == 0) {
            func_800331BC(instance->_104);
            instance->_104 = 0;
        }
    } else {
        instance->_104 = func_80050508(instance, 0x69, *(short*)&instance->_10E, *(short*)&instance->_10A, 0xDAC);
    }
    if (instance->_F4[0] == 0) {
        *(int*)&instance->_108 = *(int*)&instance->_108 + 9;
        newScale = (unsigned short)instance->scale.z + 0x200;
        instance->scale.z = newScale;
        if (newScale >= 0x1000) {
            instance->_F4[0] = 1;
        }
    } else if (instance->_F4[0] == 1) {
        instance->_100 = instance->_100 + 1;
        if ((instance->_100 >= 0x4D) ||
            (instance->rotation.z = (unsigned short)instance->rotation.z + instance->_F4[2],
             instance->position.x = (unsigned short)instance->parent->position.x + (func_8003A6AC(instance->rotation.z + 0x400) * 39 >> 6),
             instance->position.y = (unsigned short)instance->parent->position.y + (func_8003A4E0(instance->rotation.z + 0x400) * 39 >> 6),
             ((int**)((int**)instance->intro->_04)[1])[0x24/4][0x108/4] == 0)) {
            instance->_F4[0] = 2;
        }
    } else if (instance->_F4[0] == 2) {
        *(int*)&instance->_108 = *(int*)&instance->_108 - 9;
        if (*(int*)&instance->_108 <= 0) {
            *(int*)&instance->_108 = 1;
        }
        newScale = (unsigned short)instance->scale.z - 0x200;
        instance->scale.z = newScale;
        if (newScale < 2) {
            if (instance->_104 != 0) {
                func_800331BC(instance->_104);
            }
            INSTANCE_KillInstance(instance);
        }
    }
}

void gillig_tikifir_OnCollide(Instance* instance, GameTracker* gameTracker) {
    BSPTree* bsp;

    bsp = instance->bspTree;
    if ((bsp->_06 == 1) && (bsp->instanceSpline == gameTracker->player)
        && ((bsp->_0C[5] < 6U) && (PlayerInstance->_F4[1] != 0x200000))) {
        func_800223F8(gameTracker8, 0x64, 0);
    }
}

void gillig_hedhntr_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->intro->flags &= ~0x80;
    instance->currentModelAnim = 4;
    instance->_F4[0] = -1;
    instance->flags2 &= ~0x10;
}

extern short D_8015A920_9CF00[];

void gillig_hedhntr_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    short* introData;
    int state;

    state = instance->_F4[0];
    introData = instance->introData;
    if (state == -1) {
        func_8002DAF8(instance, -1);
        if (instance->flags2 & 0x10) {
            instance->_F4[0] = 0;
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
            if (instance->_F4[1] == 1) {
                instance->_F4[1] = 0;
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
            instance->_F4[0] = link;
            instance->currentModelAnim = 0;
            if (*introData == 0) {
                instance->_F4[2] = 0x9D2;
                instance->rotation.z = 0x5D2 - (unsigned short)instance->intro->rotation.z;
            } else if (*introData == link) {
                instance->_F4[2] = 0xC22;
                instance->rotation.z = 0x822 - (unsigned short)instance->intro->rotation.z;
            } else {
                instance->_F4[2] = 0xE66;
                instance->rotation.z = 0xA66 - (unsigned short)instance->intro->rotation.z;
            }
            if (*introData != 2) {
                instance->_100 = *introData + 1;
                return;
            }
            instance->_100 = 1;
            instance->_104 = 0;
        }
    } else if (state == 1) {
        int accel;
        int idx;

        func_8002DAF8(instance, -1);
        instance->position.x = (unsigned short)((Instance*)((int**)((int**)instance->intro->_04)[1])[0x24/4])->position.x + (func_8003A6AC(instance->_F4[2]) * 39 >> 6);
        instance->position.y = (unsigned short)((Instance*)((int**)((int**)instance->intro->_04)[1])[0x24/4])->position.y + (func_8003A4E0(instance->_F4[2]) * 39 >> 6);
        if (instance->_104 != 0) {
            idx = instance->_100;
            accel = instance->_F4[2];
            if (accel < D_8015A920_9CF00[idx]) {
                instance->_F4[2] = accel + 8;
            } else {
                if (idx != 2) {
                    instance->_100 = idx + 1;
                } else {
                    instance->_100 = 1;
                    instance->_104 = 0;
                }
                instance->_F4[0] = 2;
            }
        } else {
            idx = instance->_100;
            accel = instance->_F4[2];
            if (D_8015A920_9CF00[idx] < accel) {
                instance->_F4[2] = accel - 8;
            } else {
                if (idx != 0) {
                    instance->_100 = idx - 1;
                } else {
                    instance->_100 = 1;
                    instance->_104 = 1;
                }
                instance->_F4[0] = 2;
            }
        }
        instance->rotation.z = (instance->_F4[2] - (unsigned short)instance->intro->rotation.z) - 0x400;
        return;
    } else if (state == 2) {
        func_8002DAF8(instance, -1);
        if (((int**)((int**)instance->intro->_04)[1])[0x24/4][0xFC/4] == 0x7C) {
            instance->_F4[0] = 1;
        }
    } else if (state == 3) {
        int link;

        func_8002DAF8(instance, -1);
        if (instance->flags2 & 0x10) {
            instance->flags |= 0x800;
            instance->currentAnimFrame = ((short*)instance->object->animList[instance->currentModelAnim])[1] - 1;
            instance->intro->flags |= 0x80;
            instance->_F4[0] = 4;
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
