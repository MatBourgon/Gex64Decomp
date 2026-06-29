#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_8001E9F0);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_8001EF4C);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_8001F124);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_8001F444);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_8001F6F4);

extern int D_8006D288;

int func_80020164(Instance* instance) {
    if (instance->_F4[2] & 0x10000000) {
        return 1;
    }
    {
        int* data;
        data = (int*)D_8006D288;
        if (((int*)data)[3] != 0) {
            return (((unsigned short*)((int*)data)[3])[3] & 2) != 0;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800201B4);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80020238);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80020498);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800205A8);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80020E04);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800210B4);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80021330);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80021500);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800215D4);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_8002180C);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800218B0);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800219D0);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80021A78);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80021B1C);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80021C68);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80021DAC);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80021EE8);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800222A4);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800223F8);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_800224CC);

void func_80022714(Instance* instance, GameTracker* gameTracker) {
    func_800224CC(instance, gameTracker, 0, 0);
}

void func_80022738(Instance* instance, GameTracker* gameTracker) {
    func_800224CC(instance, gameTracker, 1, 0);
}

void func_8002275C(Instance* instance, GameTracker* gameTracker) {
    func_800224CC(instance, gameTracker, 1, 1);
}

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80022780);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80022810);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80022918);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80022D54);

INCLUDE_ASM("asm/nonmatchings/1F5F0", func_80023150);
