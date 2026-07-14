#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001AE60);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001B760);

int func_8001B7C0(Instance* instance) {
    int temp_v0;
    int temp_a0;
    temp_v0 = instance->_D0[2] + instance->_E0[1];
    temp_a0 = -instance->_F0;
    instance->_D0[2] = temp_v0;

    if (temp_v0 < temp_a0) {
        instance->_D0[2] = temp_a0;
    }
    instance->position.z += instance->_D0[2];
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001B804);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001BDB8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C260);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C438);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C4F8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C650);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C738);

void func_8001C920(Instance* instance, int* arg1, short* arg2) {
    if (arg2[0xDC/2] != 0) {
        arg2[0xDC/2]--;
        if (instance->currentSubState != 0x4000000) {
            if (arg2[0xDC/2] & 2) {
                instance->flags |= 0x800;
            } else {
                instance->flags &= ~0x800;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C978);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CB9C);

void func_8001CDFC(short* arg0, short arg1, short arg2) {
    short temp_v0;
    short temp_v0_2;

    temp_v0 = *arg0;
    if ((temp_v0 + arg2) < arg1) {
        *arg0 = temp_v0 + arg2;
    }
    temp_v0_2 = *arg0;
    if (arg1 < (temp_v0_2 - arg2)) {
        *arg0 = temp_v0_2 - arg2;
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CE54);

extern int D_8006CFA4;

void func_8001CF90(Instance* instance, GameTracker *gameTracker) {
    instance->currentMainState = 3;
    
    if ((*(int*)&gameTracker->_4BF4) == 1) {
        D_8006CFA4 = 0xBE;
    } 
    else {
        D_8006CFA4 = 0x5A;
    }
    
    if ((gameTracker->gameFlags & 0x20000) != 0) {
        D_8006CFA4 -= 0x1E;
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CFE8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D180);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D29C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D950);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DA8C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DC80);

int func_8001DDD8(Instance* instance, int* arg1, int* arg2) {
    if (!(*(unsigned short*)((int)arg2 + 0x8A) & 1)) {
        instance->currentSubState = 0x40;
        instance->currentModelAnim = 19;
        instance->currentAnimFrame = 0;
        
        *(unsigned short*)((int)arg2 + 0x148) = instance->position.z;
        
        if (*(unsigned short*)((int)arg2 + 0x8A) & 0x100) {
            *(unsigned short*)((int)arg2 + 0xEC) = 0;
        } else {
            *(unsigned short*)((int)arg2 + 0xEC) = *(unsigned short*)((int)arg2 + 0x10);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DE2C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DE8C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DFC0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E064);

int func_8001E0C4(Instance* instance, int* arg1, int* arg2, int* arg3) {
    if ((*(int*)((int)arg3 + 4) & 0x10) && !(WORK_AS(int, instance->work0) & 0x8000)) {
        instance->currentSubState = 0x20;
        instance->currentModelAnim = 0x19;
        instance->currentAnimFrame = 0;
        WORK_AS(int, instance->work0) &= ~8;
    }
}

int func_8001E114(Instance* instance, int* arg1, int* arg2, int* arg3) {
    if ((*(int*)((int)arg3 + 4) & 0x3000) && !(WORK_AS(int, instance->work0) & 0x8000)) {
        instance->currentSubState = 0x1000;
        instance->currentModelAnim = 0x1B;
        instance->currentAnimFrame = 0;
    }
}


INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E154);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E1C0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E368);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E648);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E6E0);

void func_8001E838(Instance* instance, void* arg1, unsigned short* data, int arg3) {
    if (data[0x45] & 0x2) {
        if (!(instance->work0 & 0x8000)) {
            instance->currentSubState = 0x400;
            instance->currentModelAnim = 0x18;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E874);

// arg0 may be Instance*
void func_8001E980(Instance* instance, int arg1, unsigned short* arg2) {
    if (!(arg2[0x8A/2] & 0x10)) {
        instance->currentSubState = 0x80000;
        instance->currentAnimFrame = 0;
        instance->currentModelAnim = 33;
    }
}

int func_8001E9AC(Instance* instance, int* arg1, int* arg2) {
    if ((*(unsigned short*)((int)arg2 + 0x8A) & 0x40) && !(WORK_AS(int, instance->work0) & 0x8000)) {
        instance->currentSubState = 0x800;
        instance->currentModelAnim = 23;
        instance->currentAnimFrame = 0;
    }
}
