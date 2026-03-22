#include "common.h"

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

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_8002527C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_8002528C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025588);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_8002569C);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800256A8);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025764);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80025798);

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

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_800269C0);

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

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027400);

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_80027410);

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

INCLUDE_ASM("asm/nonmatchings/_24cf0", func_8002780C);

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
