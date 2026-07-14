#include "common.h"

#include "types/Instance.h"

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80027BA0);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80027E7C);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_800280A0);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002829C);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80028454);

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

INCLUDE_ASM("asm/nonmatchings/_287a0", func_80029434);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_8002948C);

INCLUDE_ASM("asm/nonmatchings/_287a0", func_800295A0);

void func_80029600(short* arg0, int* arg1, char* arg2) {
    if (*(int*)((char*)arg0 + 0x14) & 0x10) {
        *(int*)((char*)arg0 + 0xF8) = 1;
        ((char*)arg0)[0x4E] = 0;
        *(short*)((char*)arg0 + 0x5E) = 0;
        *(short*)(arg2 + 0x9C) = 0;
        *(short*)(arg2 + 0x9E) = 0;
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

int func_8002A140(short* arg0, int* arg1, char* arg2) {
    if (*(int*)((char*)arg0 + 0x14) & 0x10) {
        *(int*)((char*)arg0 + 0xF8) = 2;
        *(char*)((char*)arg0 + 0x4e) = 8;
        *(short*)((char*)arg2 + 0x9E) = 0;
         *(short*)((char*)arg2 + 0x9C) = 0;
        *(short*)((int)arg2 + 0xDC) = 0x3C;
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
    instance->currentMainState = 0;
    instance->currentSubState = 1;
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
