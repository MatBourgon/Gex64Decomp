#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001AE60);

extern Instance* PlayerInstance;

void func_8001B760(int* arg0) {
    int* dest;

    dest = (int*)((char*)PlayerInstance->data + 0xF8);
    memcpy(dest, arg0, 0x2C);
}

void func_8001B7C0(Instance* instance) {
    int vel;
    int limit;

    vel = instance->_D0[2] + instance->_E0[1];
    limit = -instance->_F0[0];
    instance->_D0[2] = vel;
    if (vel < limit) {
        instance->_D0[2] = limit;
    }
    instance->position.z = instance->position.z + instance->_D0[2];
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001B804);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001BDB8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C260);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C438);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C4F8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C650);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C738);

void func_8001C920(Instance* instance, int arg1, void* arg2) {
    short timer;

    timer = ((short*)arg2)[0xDC/2];
    if (timer != 0) {
        timer--;
        ((short*)arg2)[0xDC/2] = timer;
        if (instance->_F4[1] != 0x4000000) {
            if (timer & 2) {
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
    short val;

    val = *arg0;
    if (val + arg2 < arg1) {
        *arg0 = val + arg2;
    }
    val = *arg0;
    if (arg1 < val - arg2) {
        *arg0 = val - arg2;
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CE54);

extern int D_8006CFA4;

void func_8001CF90(Instance* instance, GameTracker* gameTracker) {
    int val;

    instance->_F4[0] = 3;
    if (((int*)gameTracker)[0x4BF4/4] == 1) {
        val = 0xBE;
    } else {
        val = 0x5A;
    }
    D_8006CFA4 = val;
    if (((int*)gameTracker)[0x4C08/4] & 0x20000) {
        D_8006CFA4 -= 0x1E;
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CFE8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D180);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D29C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D950);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DA8C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DC80);

void func_8001DDD8(Instance* instance, int arg1, void* arg2) {
    if (!(((unsigned short*)arg2)[0x45] & 1)) {
        instance->_F4[1] = 0x40;
        ((char*)instance->_40)[0xe] = 0x13;
        instance->currentAnimFrame = 0;
        if (((unsigned short*)arg2)[0x45] & 0x100) {
            ((short*)arg2)[0xA4] = instance->position.z;
            ((short*)arg2)[0x76] = 0;
        } else {
            ((short*)arg2)[0x76] = ((unsigned short*)arg2)[8];
        }
    }
}

void func_8001DE2C(Instance* instance, GameTracker* gameTracker, int arg2, void* arg3) {
    if ((((int*)arg3)[1] & 0x3830) || (((int*)arg3)[0] & 0x8000000F)) {
        if (!(instance->flags & 0x100)) {
            if (((short*)gameTracker)[0x4C12/2] == 4) {
                instance->currentModelAnim = 0;
                instance->currentAnimFrame = 0;
                instance->_F4[1] = 1;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DE8C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DFC0);

void func_8001E064(Instance* instance, void* arg1, int arg2, void* arg3) {
    Instance* other;

    if ((((int*)arg3)[1] & 0x800) || (((int*)((int*)arg1)[3])[0xFC/4] & 0x800)) {
        ((char*)instance->_40)[0xe] = 0x22;
        instance->currentAnimFrame = 0;
        instance->_F4[1] = 0x100000;
        other = (Instance*)((int*)arg1)[3];
        other->_F4[2] &= ~0x800;
    }
}

void func_8001E0C4(Instance* instance, int arg1, int arg2, void* arg3) {
    if (((int*)arg3)[1] & 0x10) {
        if (!(instance->_F4[2] & 0x8000)) {
            instance->_F4[1] = 0x20;
            ((char*)instance->_40)[0xe] = 0x19;
            instance->currentAnimFrame = 0;
            instance->_F4[2] &= ~8;
        }
    }
}

void func_8001E114(Instance* instance, int arg1, int arg2, void* arg3) {
    if (((int*)arg3)[1] & 0x3000) {
        if (!(instance->_F4[2] & 0x8000)) {
            instance->_F4[1] = 0x1000;
            ((char*)instance->_40)[0xe] = 0x1B;
            instance->currentAnimFrame = 0;
        }
    }
}

void func_8001E154(Instance* instance, int arg1, void* arg2, void* arg3) {
    if (((int*)arg3)[1] & 0x20) {
        instance->_F4[1] = 0x2000;
        instance->currentModelAnim = 0x1E;
        instance->currentAnimFrame = 0;
        {
            int* p;
            p = (int*)((int*)arg2)[0xB8/4];
            p[0] = ((int*)arg2)[0xAC/4];
            p = (int*)((int*)arg2)[0xC4/4];
            p[0] = ((int*)arg2)[0xAC/4];
            p = (int*)((int*)arg2)[0xD0/4];
            p[0] = ((int*)arg2)[0xAC/4];
        }
        instance->_F4[2] &= ~8;
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E1C0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E368);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E648);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E6E0);

void func_8001E838(Instance* instance, int arg1, void* arg2) {
    if (((unsigned short*)arg2)[0x45] & 2) {
        if (!(instance->_F4[2] & 0x8000)) {
            instance->_F4[1] = 0x400;
            ((char*)instance->_40)[0xe] = 0x18;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E874);

// arg0 may be Instance*
void func_8001E980(int* arg0, int arg1, unsigned short* arg2) {
    if (!(arg2[0x45] & 0x10)) {
        arg0[0x3E] = 0x80000;
        ((short*)arg0)[0x2F] = 0;
        ((char*)arg0)[0x4E] = 0x21;
    }
}

void func_8001E9AC(Instance* instance, int arg1, void* arg2) {
    if (((unsigned short*)arg2)[0x45] & 0x40) {
        if (!(instance->_F4[2] & 0x8000)) {
            instance->_F4[1] = 0x800;
            ((char*)instance->_40)[0xe] = 0x17;
            instance->currentAnimFrame = 0;
        }
    }
}
