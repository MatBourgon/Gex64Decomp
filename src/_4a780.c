#include "common.h"

#include "INSTANCE.h"
#include "types/GameTracker.h"
#include "types/TVTextData.h"

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E730);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_80049B80);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A2A4);

int func_8004A344(int*** arg0) {
    int** var_v0 = arg0[7];

  if (var_v0[1] == 0) return 0;

  return *var_v0[1];
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A368);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A3B4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A420);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A47C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A4E4);

void INSTANCE_InsertInstanceWithFlagsSet(Instance* instance, int flags) {
    int groupId;

    instance->flags |= flags;
    groupId = INSTANCE_InstanceGroupNumber(instance);
    LIST_DeleteFunc(&instance->node);
    LIST_InsertFunc(&gameTracker8->instanceList->group[groupId], &instance->node);
}

void INSTANCE_InsertInstanceWithFlagsCleared(Instance* instance, int flags) {
    int groupId;

    instance->flags &= ~flags;
    groupId = INSTANCE_InstanceGroupNumber(instance);
    LIST_DeleteFunc(&instance->node);
    LIST_InsertFunc(&gameTracker8->instanceList->group[groupId], &instance->node);
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A61C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A67C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A6C8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A7B8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A820);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A8A8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A98C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004A9C8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AA38);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AA70);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AAA8);

int func_8004AADC(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AAE4);

int func_8004AC10(int *arg0, int unused, int arg2, int arg3) {
    int var1 = 2;
    int var2 = arg2 < 0 ? arg2 + 3 : arg2;
    int msb;

    if (arg3 < (var2 >> 2))
        var1 = 1;

    msb = (unsigned int)arg2 >> 31;
    if (arg3 < ((arg2 + msb) >> 1)) {

        if (arg3 & var1) {
            arg0[4] |=  0x800;  
        } else {
            arg0[4] &= ~0x800;    
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AC78);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004ACB0);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AD5C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004ADDC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004AEC8);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B090);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B23C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B2DC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B32C);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B380);

int GetLevelIndexFromId(const char* targetLevelId)
{
    char correctLevelId[16];
    int levelNameLen = strlen(targetLevelId);
    int i;
    
    for (i = 0; i < levelNameLen; ++i)
        correctLevelId[i] = ctoupper(targetLevelId[i]);

    correctLevelId[i] = '\0';

    for (i = 0; i < NUM_LEVELS; ++i)
    {
        if (strcmp(correctLevelId, TVTextInformation[i].levelId) == 0)
            return i;
    }
    
    return -1;
}

short GetRedRemotesForLevel(unsigned int levelIndex) {
    if (levelIndex >= NUM_LEVELS) {
        levelIndex = 0;
    }
    return TVTextInformation[levelIndex].nRedRemotes;
}

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E740);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E748);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E750);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E758);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E760);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E768);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E770);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E77C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E784);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E790);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7A0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7A8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7B8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7C0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7C8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7D8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7E0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7F0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E7FC);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E808);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E810);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E81C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E828);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E830);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E840);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E84C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E854);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E860);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E868);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E87C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E884);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E88C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E894);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8A4);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8AC);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8B8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8C8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8D4);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8DC);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8F0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E8F8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E904);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E910);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E918);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E924);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E934);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E940);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E950);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E958);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E968);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E974);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E980);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E990);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E998);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9A0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9A8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9B4);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9C0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9C8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9D0);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9D8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9E8);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9F4);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007E9FC);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA04);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA14);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA20);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA34);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA3C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA44);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA48);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA5C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA64);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA6C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA78);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA80);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA84);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA8C);

INCLUDE_RODATA("asm/nonmatchings/_4a780", D_8007EA98);

extern unsigned int D_800AF060;
extern unsigned int D_800AF064;
extern unsigned int D_800AF068;
extern int D_800AF06C;

void func_8004B604(int* arg0, char** strs, int arg2, int* arg3, int* flagsOut, int arg5) {
    char* var_a0;
    int temp_v1;
    int i;
    int var_s2;
    int flags;
    int temp_v0;

    flags = 0;
    
    var_s2 = arg5;
    if (var_s2 == -1) {
        var_s2 = 0x2D;
    } else if (var_s2 == 0) {
        var_s2 = 0x1E;
    }
    
    for (i = 0; i < arg2; i++) {
        Set3DTextPosition((int) ((0x140 - ((strlen(strs[i]) - 1) * 0x14)) << 0xF) >> 0x10, (short) var_s2);
        if (i == *arg3) {
            Print3DTextf("#2%s", strs[i]);
        } else {
            Print3DTextf("#0%s", strs[i]);
        }
        var_s2 += 0x1E;
    }
    
    D_800AF064++;
    if ((D_800AF068 + D_800AF064) < ((int*)gameTracker8)[0xE0/4]) {
        D_800AF068 = ((int*)gameTracker8)[0xE0/4];
        D_800AF064 = 0;
        D_800AF060 = 1;
        D_800AF06C = 0;
    }
    if ((unsigned int) D_800AF064 >= 0x10U) {
        if (arg0[0x11] & 0x80) {
            D_800AF06C |= 1;
        }
        if (arg0[0x11] & 0x40) {
            D_800AF06C |= 2;
        }
        if (arg0[0x11] & 0x20) {
            D_800AF06C |= 4;
        }
        if (arg0[0x11] & 0x10) {
            D_800AF06C |= 8;
        }
        if (arg0[0x12] & 0x80) {
            flags |= 1;
        }
        if (arg0[0x12] & 0x40) {
            flags |= 2;
        }
        if (arg0[0x12] & 0x20) {
            flags |= 4;
        }
        if (arg0[0x12] & 0x10) {
            flags |= 8;
        }
        if (flags & D_800AF06C) {
            *flagsOut = flags;
            D_800AF068 = 0;
            return;
        }
        if (D_800AF060 == 0) {
            if (arg0[10] < 0) {
                if (--*arg3 < 0) {
                    *arg3 = 0;
                } else {
                    D_800AF060 = 1;
                }
            } else if (arg0[10] > 0) {
                if (++*arg3 >= arg2) {
                    *arg3 = arg2 - 1;
                } else {
                    D_800AF060 = 1;
                }
            }
            if (D_800AF060 != 0) {
                func_800509E0(0x81, 0x7A, 0x40, 0);
            }
        } else {
            D_800AF060++;
            if (D_800AF060 >= 4U) {
                D_800AF060 = 0;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B968);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004BAAC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004BFBC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C040);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C110);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C2F4);
