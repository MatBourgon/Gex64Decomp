#include "common.h"
#include "PR/os_ai.h"

INCLUDE_ASM("asm/nonmatchings/_56790", func_80055B90);

INCLUDE_ASM("asm/nonmatchings/_56790", func_80055FA4);

INCLUDE_ASM("asm/nonmatchings/_56790", func_800561A8);

INCLUDE_ASM("asm/nonmatchings/_56790", func_800562E8);

extern int D_80079534;

void func_800564A0(void) {
    if (((osAiGetLength() >> 2) == 0) && (D_80079534 == 0)) {
        D_80079534 = 0;
    }
}


extern unsigned char D_800B10F0;
extern int D_800B10F4;
extern int D_800B10F8;
extern int D_800B112C;
void func_80055FA4(void); // unknown type

int* func_800564E0(char** arg0) {
    unsigned char* ptr = &D_800B10F0;

    if (*ptr == 0) {
        D_800B10F4 = 0;
        *ptr = 1;
        D_800B10F8 = D_800B112C;
    }

    *arg0 = (char*)ptr;
    return func_80055FA4;
}

INCLUDE_ASM("asm/nonmatchings/_56790", func_80056520);
