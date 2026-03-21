#include "common.h"

#include "LIST.h"

INCLUDE_ASM("asm/nonmatchings/161C0", func_800155C0);

INCLUDE_ASM("asm/nonmatchings/161C0", G2Quat_ToEuler);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800157BC);

INCLUDE_ASM("asm/nonmatchings/161C0", G2Quat_ToMatrix_S);

INCLUDE_ASM("asm/nonmatchings/161C0", G2Quat_Slerp_VM);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80015DA0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80015E80);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80015EC0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80015F14);

// At least used to create two shadows
void* func_80015F60(void* arg0) {
    void* temp_v0;

    temp_v0 = LIST_GetFunc(arg0 + 0x11418); // <-- that's a really big offset into some struct
    if (temp_v0 != 0) {
        memset(temp_v0, 0, 0x74);
    }
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/161C0", func_80015FA8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800160A4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001617C);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800162C0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800163A4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800166C4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80016894);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80016D58);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80016F84);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800170E8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017138);

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001719C);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017598);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800175D0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800176E8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017768);

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001788C);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017AB8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017AE0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017C58);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017CD8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017D28);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017D78);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017E48);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80017E88);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800180C8);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018180);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018380);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018460);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800185A4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_8001873C);

INCLUDE_ASM("asm/nonmatchings/161C0", func_800187C4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018974);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018AB4);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018B60);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018DC0);

INCLUDE_ASM("asm/nonmatchings/161C0", func_80018DFC);
