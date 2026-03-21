#include "common.h"

// Assigned to shadows
void func_80018FD0(short* arg0) {
    if (arg0[0xE/2] == 0) {
        func_80015EC0();
    }
}

INCLUDE_ASM("asm/nonmatchings/19BD0", func_80019000);

INCLUDE_ASM("asm/nonmatchings/19BD0", func_80019680);

INCLUDE_ASM("asm/nonmatchings/19BD0", func_80019828);

INCLUDE_ASM("asm/nonmatchings/19BD0", func_800198A8);

INCLUDE_ASM("asm/nonmatchings/19BD0", func_800199C0);
