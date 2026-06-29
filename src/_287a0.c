#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80027BA0);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80027E7C);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_800280A0);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002829C);

void func_80028454(Instance* instance, GameTracker* gameTracker) {
    if ((unsigned int)(((int*)gameTracker)[0x4C48/4] - 1) < 9) {
        if (((int*)gameTracker)[0x4C4C/4] == 0x64) {
            if (func_80052FB8() != 0) {
                func_8001C738(((int*)gameTracker)[3], gameTracker, ((int*)((int*)gameTracker)[3])[8], 0);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/_287a0", func_800284C4);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80028714);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80028844);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_800289A4);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80028AD4);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80028C68);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80028F84);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_800290BC);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_800292D4);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029390);

void func_80029434(Instance* instance, int arg1, void* arg2) {
    if (!(((unsigned short*)arg2)[0x45] & 0x40)) {
        instance->_F4[1] = 0x100;
        ((char*)instance->_40)[0xe] = 0x11;
        instance->currentAnimFrame = 0;
    }
    if ((instance->currentAnimFrame & 7) == 0) {
        func_800247B4(instance, arg1, arg2, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002948C);

void func_800295A0(Instance* instance, int arg1, void* arg2) {
    if (instance->flags2 & 0x10) {
        instance->_F4[1] = 0x1000;
        ((char*)instance->_40)[0xe] = 0x1D;
        instance->currentAnimFrame = 0;
    } else {
        int* p;
        p = (int*)((int*)arg2)[0xB8/4];
        p[0] = ((int*)arg2)[0xAC/4];
        p = (int*)((int*)arg2)[0xC4/4];
        p[0] = ((int*)arg2)[0xAC/4];
        p = (int*)((int*)arg2)[0xD0/4];
        p[0] = ((int*)arg2)[0xAC/4];
    }
}

void func_80029600(Instance* instance, int arg1, void* arg2) {
    if (instance->flags2 & 0x10) {
        instance->_F4[1] = 1;
        ((char*)instance->_40)[0xe] = 0;
        instance->currentAnimFrame = 0;
        ((short*)arg2)[0x4E] = 0;
        ((short*)arg2)[0x4F] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029630);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029914);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029A10);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029B1C);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029C28);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029CC8);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029E74);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029FA4);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002A0AC);

void func_8002A140(Instance* instance, int arg1, void* arg2) {
    if (instance->flags2 & 0x10) {
        instance->_F4[1] = 2;
        ((char*)instance->_40)[0xe] = 8;
        ((short*)arg2)[0x4E] = 0;
        ((short*)arg2)[0x4F] = 0;
        ((short*)arg2)[0x6E] = 0x3C;
    }
}

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002A178);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002A274);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BE40);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BE48);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BE50);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002A488);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002ADB4);

void func_8002AE40(Instance* instance) {
    void* data;

    data = instance->data;
    instance->_F4[0] = 0;
    instance->_F4[1] = 1;
    instance->currentAnimFrame = 0;
    instance->currentModelAnim = 0;
    ((short*)data)[0x4E] = 0;
    ((short*)data)[0x4F] = 0;
    instance->rotation.x = 0;
    instance->rotation.y = 0;
}

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BE7C);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BE84);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BE8C);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BE94);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BEA0);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BEA4);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BEAC);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BEB4);

INCLUDE_RODATA("asm/nonmatchings/_287a0", D_8007BEB8);
