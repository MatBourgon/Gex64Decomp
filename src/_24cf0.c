#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/BSPTree.h"
#include "INSTANCE.h"

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800240F0);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024148);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024528);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800247B4);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024938);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024A80);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024B94);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024C30);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024C84);

void func_8002527C(short* arg0, short arg1, short arg2, int arg3) {
    arg0[6] = arg1;
    arg0[7] = arg2;
    ((int*)arg0)[4] = arg3;
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_8002528C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025588);

void func_8002569C(Instance* instance) {
    instance->_F4[0] = 3;
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800256A8);

extern int D_800B83BC;

void func_80025764(Instance* instance, GameTracker* gameTracker, short value) {
    short* data = ((short*)instance->data);

    if (data != NULL) {
        if (data[0x6F] == 0) {
            D_800B83BC = 2;
        }
        data[0x6F] = value;
    }
}

int func_80025798(Instance* instance) {
    int result;

    result = 0;
    if (instance->data != NULL) {
        result = ((short*)instance->data)[0x6F];
    }
    return result;
}

int func_800257B4(Instance* instance) {
    int state;
    unsigned short* data;
    int result;

    state = instance->_F4[0];
    data = ((unsigned short*)instance->data);
    result = 0;
    if (state == 1 || state == 0x8000) {
        result = 1;
    } else if (data != 0 && (data[0x45] & 0x80)) {
        result = 1;
    }
    return result;
}

extern short D_80157650[20][4];

short* func_80025800(void) {
    short* entry;
    short index;

    entry = D_80157650[0];
    index = 0;
    while (1) {
        if (*entry == 0) {
            *entry = 1;
            return entry;
        }
        index++;
        if (index >= 0x14) {
            return 0;
        }
        entry += 4;
    }
}

void func_80025850(void) {
    short *ptr;
    short i;

    ptr = D_80157650[0];
    for (i = 0; i < 20; i++) {
        *ptr = 0;
        ptr += 4;
    }
}

short* func_80025884(short arg0) {
    short* entry;
    short index;

    entry = D_80157650[0];
    index = 0;
    while (1) {
        if (*entry != 0 && entry[3] == arg0) {
            return entry;
        }
        index++;
        if (index >= 0x14) {
            return 0;
        }
        entry += 4;
    }
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800258E4);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800259FC);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025A9C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025B4C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025E8C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025F70);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025FDC);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800260A4);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80026374);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80026470);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80026674);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80026768);

void func_800269C0(short* arg0) {
    arg0[4] = 0;
    arg0[5] = 0;
    arg0[3] = 0;
    arg0[2] = 0;
}

void func_800269D4(void) {
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800269DC);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80026FA4);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027028);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800270C8);

void func_80027110(Instance* instance, short value, GameTracker* gameTracker) {
    void* data;

    data = gameTracker->player->data;
    instance->flags |= 0x400;
    if (*(int*)((char*)data + 0x130) == 0) {
        *(int*)((char*)data + 0x130) = (int)instance;
        *(short*)((char*)data + 0x134) = value;
    }
}

extern int D_800B83BC;
extern void func_80050A80(int arg0, int arg1);

void func_80027144(Instance* instance, GameTracker* gameTracker) {
    func_800240F0(instance, gameTracker);
    func_8002E350(instance);
    D_800B83BC = 0;
    func_80050A80(0, 0xA);
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027184);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027398);

void func_80027400(Instance* instance) {
    instance->_F4[0] = 4;
    ((char*)instance->_40)[0xe] = 0;
}

void func_80027410(Instance* instance) {
    instance->_F4[0] = 0;
    instance->_B8 = *(int*)instance->data;
}

void func_80027428(int arg0) {
    char* data;

    data = ((char*)PlayerInstance->data);
    if (*(short*)(data + 0x78) == 0) {
        *(short*)(data + 0x82) = *(unsigned short*)(data + 0x86) + (arg0 - *(unsigned short*)(data + 0x88));
    }
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027468);

int func_80027500(BSPTree* bsp, GameTracker* gameTracker) {

    if ((bsp->instanceSpline == gameTracker->player) && (bsp->_06 == 1) && bsp->_0C[5] == 8) {
        return 1;
    }
    
    return 0;
}

/* arg0 = BSPTree*, arg1 = GameTracker*. Confirmed by cross-reference: same
 * bsp->instanceSpline / bsp->_06 fields at the same offsets, with the same
 * early-return shape, are used in func_80027500 just above (which already
 * matches 100%). */
int func_80027548(BSPTree* bsp, GameTracker* gameTracker) {
    if ((bsp->instanceSpline == gameTracker->player) && (bsp->_06 == 4)) {
        return 1;
    }

    return 0;
}

int func_80027578(void) {
    int state;
    short* data;
    int result;

    state = PlayerInstance->_F4[0];
    data = ((short*)gameTracker8->player->data);
    result = 0;
    if ((unsigned int)(state - 2) < 2 || data[0x6E] != 0) {
        result = 1;
    }
    return result;
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800275C4);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_8002768C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027770);

void func_8002780C(GameTracker* gameTracker) {
    func_8002CA2C(6, ((int*)gameTracker)[0x4BF8/4]);
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027834);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BDE0);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BDE4);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BDEC);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BDF4);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BDFC);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BE00);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800278EC);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027930);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800279AC);

INCLUDE_ASM("asm/nonmatchings/_24cf0", common_starz_OnUpdate);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BE14);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BE1C);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BE30);

INCLUDE_RODATA("asm/nonmatchings/_24cf0", D_8007BE38);
