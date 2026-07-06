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

INCLUDE_ASM("asm/nonmatchings/level/GILLIG", gillig_tikifb_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/level/GILLIG", gillig_tikifb_OnCollide);

void gillig_tikifir_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->scale.z = 1;
    instance->_104 = 0;
    *(int*)&instance->_108 = 1;
    *(int*)&instance->_10C = ((rand() & 0x1F) - 0x10);
}

extern short func_8003A6AC(int);
extern short func_8003A4E0(int);

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

INCLUDE_ASM("asm/nonmatchings/level/GILLIG", gillig_hedhntr_OnUpdate);

void gillig_hedhntr_OnCollide(Instance* instance, GameTracker* gameTracker)
{
}

INCLUDE_RODATA("asm/nonmatchings/level/GILLIG", D_8015A960_9CF40);

INCLUDE_RODATA("asm/nonmatchings/level/GILLIG", D_8015A964_9CF44);
