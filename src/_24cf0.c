#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/BSPTree.h"

void func_800240F0(Instance* instance, void* arg1) {
    void* data;

    if (instance != NULL) {
        instance->flags &= ~0x400;
    }
    if (arg1 != NULL) {
        data = (void*)((int*)arg1)[3];
        if (data != NULL) {
            data = (void*)((int*)data)[8];
            if (data != NULL) {
                ((int*)data)[0x130/4] = 0;
                ((short*)data)[0x134/2] = 0;
                ((short*)data)[0xDE/2] = 0;
                ((short*)data)[0x18C/2] = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024148);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024528);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800247B4);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024938);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024A80);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80024B94);

void func_80024C30(Instance* instance, void* arg1) {
    Instance* target;
    int* entry;

    target = (Instance*)((int*)arg1)[0x130/4];
    if (target != NULL) {
        entry = (int*)((char*)instance->matrix + ((short*)arg1)[0x134/2] * 0x20);
        target->position.x = entry[0x14/4];
        target = (Instance*)((int*)arg1)[0x130/4];
        target->position.y = entry[0x18/4];
        target = (Instance*)((int*)arg1)[0x130/4];
        target->position.z = entry[0x1C/4];
    }
}

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

void func_80025764(Instance* instance, int arg1, short arg2) {
    if (instance->data != NULL) {
        if (((short*)instance->data)[0x6F] == 0) {
            D_800B83BC = 2;
        }
        ((short*)instance->data)[0x6F] = arg2;
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
    void* data;
    int result;

    state = instance->_F4[0];
    data = instance->data;
    result = 0;
    if (state == 1 || state == 0x8000) {
        result = 1;
    } else if (data != NULL) {
        if (((unsigned short*)data)[0x45] & 0x80) {
            result = 1;
        }
    }
    return result;
}

short* func_80025800(void) {
    short* ptr;
    short i;

    ptr = D_80157650;
    for (i = 0; i < 0x14; i++) {
        if (ptr[0] == 0) {
            ptr[0] = 1;
            return ptr;
        }
        ptr += 4;
    }
    return NULL;
}

extern short D_80157650[];

void func_80025850(void) {
    short i;
    for (i = 0; i < 0x14; i++) {
        D_80157650[i * 4] = 0;
    }
}

short* func_80025884(short arg0) {
    short* ptr;
    short i;

    ptr = D_80157650;
    for (i = 0; i < 0x14; i++) {
        if (ptr[0] != 0 && ptr[3] == arg0) {
            return ptr;
        }
        ptr += 4;
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800258E4);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800259FC);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025A9C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025B4C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025E8C);

void func_80025F70(GameTracker* gameTracker, Instance* instance, void* arg2) {
    func_800240F0(instance, arg2);
    D_800B83BC = 0;
    INSTANCE_KillInstance(instance);
    func_80025850();
    if (((int*)gameTracker)[0x13C/4] != 0) {
        func_800331BC(((int*)gameTracker)[0x13C/4]);
        ((int*)gameTracker)[0x13C/4] = 0;
    }
}

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

void func_800270C8(Instance* instance, void* arg1) {
    int offset;
    int* data;

    offset = instance->_110 * 6 + 0x162;
    data = (int*)((int*)arg1)[3];
    data = (int*)((int*)data)[8];
    func_80027028(instance, (char*)((int*)data)[0x70/4] + offset);
}

void func_80027110(Instance* instance, short arg1, void* arg2) {
    void* data;

    data = (void*)((int*)arg2)[3];
    instance->flags |= 0x400;
    data = (void*)((int*)data)[8];
    if (((int*)data)[0x4C] == 0) {
        ((int*)data)[0x4C] = (int)instance;
        ((short*)data)[0x9A] = arg1;
    }
}

void func_80027144(Instance* instance) {
    func_800240F0(instance);
    func_8002E350(instance);
    D_800B83BC = 0;
    func_80050A80(0, 0xA);
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027184);

int func_80027398(void) {
    int state;
    void* data;

    state = PlayerInstance->_F4[0];
    data = PlayerInstance->data;
    if (state != 0) {
        return 0;
    }
    if (PlayerInstance->_F4[1] != 1) {
        return 0;
    }
    if (((int*)data)[0x74/4] & 2) {
        return 0;
    }
    return ((unsigned char*)gameTracker8)[0x4CA1] != 0x16;
}

void func_80027400(Instance* instance) {
    instance->_F4[0] = 4;
    ((char*)instance->_40)[0xe] = 0;
}

void func_80027410(Instance* instance) {
    instance->_F4[0] = 0;
    instance->_B8 = *(int*)instance->data;
}

extern Instance* PlayerInstance;

void func_80027428(int arg0) {
    short* data;

    data = (short*)PlayerInstance->data;
    if (data[0x78/2] == 0) {
        data[0x82/2] = ((unsigned short*)data)[0x86/2] + arg0 - ((unsigned short*)data)[0x88/2];
    }
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027468);

int func_80027500(BSPTree* bsp, GameTracker* gameTracker) {

    if ((bsp->instanceSpline == gameTracker->player) && (bsp->_06 == 1) && bsp->_0C[5] == 8) {
        return 1;
    }
    
    return 0;
}

int func_80027548(BSPTree* bsp, GameTracker* gameTracker) {
    int result;

    result = 0;
    if (bsp->instanceSpline == gameTracker->player) {
        result = bsp->_06 == 4;
    }
    return result;
}

extern int* gameTracker8;

int func_80027578(void) {
    int state;
    short* data;
    int result;

    state = PlayerInstance->_F4[0];
    data = (short*)((int*)gameTracker8[3])[8];
    result = 0;
    if ((unsigned int)(state - 2) < 2) {
        result = 1;
    } else if (data[0xDC/2] != 0) {
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
