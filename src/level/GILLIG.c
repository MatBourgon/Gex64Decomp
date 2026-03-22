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

INCLUDE_ASM("asm/nonmatchings/level/GILLIG", gillig_tikifir_OnUpdate);

void gillig_tikifir_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int* temp_a0;

    temp_a0 = (int*)instance->_70[2];
    if ((((short*)temp_a0)[3] == 1) && (temp_a0[0x14/4] == (int)gameTracker->player)
        && (((char**)temp_a0)[12/4][5] < 6U) && (PlayerInstance->_F4[1] != 0x200000)) {
        func_800223F8(gameTracker8, 0x64, 0);
    }
}

void gillig_hedhntr_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->intro->flags &= ~0x80;
    instance->_4E = 4;
    instance->_F4[0] = -1;
    instance->flags2 &= ~0x10;
}

INCLUDE_ASM("asm/nonmatchings/level/GILLIG", gillig_hedhntr_OnUpdate);

void gillig_hedhntr_OnCollide(Instance* instance, GameTracker* gameTracker)
{
}

INCLUDE_RODATA("asm/nonmatchings/level/GILLIG", D_8015A960_9CF40);

INCLUDE_RODATA("asm/nonmatchings/level/GILLIG", D_8015A964_9CF44);
