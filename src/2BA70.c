#include "common.h"

#include "types/Instance.h"

INCLUDE_ASM("asm/nonmatchings/2BA70", func_8002AE70);

extern int D_8007BEB4;
extern int D_8007BEB8;

void func_8002AF18(Instance* instance, void* arg1) {
    int* data;

    data = (int*)((int*)arg1)[6];
    data = (int*)((int*)data)[8];
    if (data[0] == D_8007BEB4 && data[1] == D_8007BEB8) {
        func_8002B428(instance, arg1);
    } else {
        func_8002B0F0(instance, arg1);
    }
}

INCLUDE_ASM("asm/nonmatchings/2BA70", func_8002AF84);

INCLUDE_ASM("asm/nonmatchings/2BA70", func_8002B0F0);

INCLUDE_ASM("asm/nonmatchings/2BA70", func_8002B2D8);

INCLUDE_ASM("asm/nonmatchings/2BA70", func_8002B428);

void func_8002B7CC(Instance* instance) {
    int* data;

    data = (int*)((int*)instance->data)[0xE0/4];
    if (func_8002AE70(instance, data) != 0) {
        instance->_F4[1] = 0x10000;
        instance->flags |= 0x100;
        instance->_D0[0] = 0;
        instance->_D0[1] = 0;
        instance->_D0[2] = 0;
        instance->_E0[1] = 0;
        instance->_E0[0] = 0;
        instance->_D0[3] = 0;
        instance->_F4[2] |= 1;
    }
}
