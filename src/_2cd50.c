#include "common.h"

extern short D_800EB808[];
extern short D_800EB80C[];

void func_8002C150(void) {
    int i;
    int byteOffset;
    int value;

    i = 0;
    value = 4;
    byteOffset = 0;
    do {
        *(short*)((char*)D_800EB80C + byteOffset) = value;
        *(short*)((char*)D_800EB808 + byteOffset) = 0;
        byteOffset += 0xC;
        i++;
    } while (i < 7);
}

void func_8002C18C(int arg0) {
    D_800EB80C[arg0 * 6] = 4;
}

void func_8002C1AC(int arg0) {
    func_8002C18C(arg0);
    D_800EB80C[arg0 * 6] = 5;
}

void func_8002C1EC(void) {
    int i;
    for (i = 0; i < 7; i++) {
        func_8002C18C(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/_2cd50", func_8002C224);

INCLUDE_ASM("asm/nonmatchings/_2cd50", func_8002C28C);

INCLUDE_ASM("asm/nonmatchings/_2cd50", func_8002C4A0);

INCLUDE_ASM("asm/nonmatchings/_2cd50", func_8002CA2C);
