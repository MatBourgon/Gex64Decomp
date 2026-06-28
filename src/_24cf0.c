#include "common.h"

#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/BSPTree.h"

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

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025764);

int func_80025798(Instance* instance) {
    int result;

    result = 0;
    if (instance->data != NULL) {
        result = ((short*)instance->data)[0x6F];
    }
    return result;
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800257B4);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025800);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025850);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025884);

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

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027110);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027144);

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

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027428);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027468);

int func_80027500(BSPTree* bsp, GameTracker* gameTracker) {

    if ((bsp->instanceSpline == gameTracker->player) && (bsp->_06 == 1) && bsp->_0C[5] == 8) {
        return 1;
    }
    
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027548);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027578);

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
