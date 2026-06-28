#include "common.h"

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001AE60);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001B760);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001B7C0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001B804);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001BDB8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C260);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C438);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C4F8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C650);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C738);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C920);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001C978);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CB9C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CDFC);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CE54);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CF90);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001CFE8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D180);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D29C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001D950);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DA8C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DC80);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DDD8);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DE2C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DE8C);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001DFC0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E064);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E0C4);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E114);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E154);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E1C0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E368);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E648);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E6E0);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E838);

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E874);

// arg0 may be Instance*
void func_8001E980(int* arg0, int arg1, unsigned short* arg2) {
    if (!(arg2[0x45] & 0x10)) {
        arg0[0x3E] = 0x80000;
        ((short*)arg0)[0x2F] = 0;
        ((char*)arg0)[0x4E] = 0x21;
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", func_8001E9AC);
