#include "common.h"

#include "types/GameState.h"

INCLUDE_ASM("asm/nonmatchings/_1050", func_80000450);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80000F24);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80000F60);

INCLUDE_RODATA("asm/nonmatchings/_1050", D_8007B440);

extern int GetLevelIndexFromId(const char*);
BOOL IsLooneyLoading(const GameState* gameState)
{
    int looney30Id, looney69Id;

    looney30Id = GetLevelIndexFromId("looney30");
    looney69Id = GetLevelIndexFromId("looney69");

    if (gameState->levelIdToLoad == looney30Id || gameState->levelIdToLoad == looney69Id)
        return TRUE;

    return FALSE;
}

INCLUDE_ASM("asm/nonmatchings/_1050", func_80001408);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800018F0);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80001DF4);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80001E3C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80001EAC);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800020D0);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002134);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002198);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002600);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002678);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002734);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002888);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002908);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002A88);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80002B18);

int func_80003118(int* arg0, int arg1) {
    arg0[144] |= arg1;
}

int func_8000312C(int* arg0, int arg1) {
    arg0[144] &= ~arg1;
}

int func_80003140(int* arg0, int arg1) {
    arg0[84] = (int)arg1;
}

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003148);

void func_8000322C(void) {
}

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003234);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003910);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800039E8);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003A0C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003A68);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003B1C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003D4C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003D68);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003DAC);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003E18);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003F6C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_8000486C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80004930);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80004A60);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80004B70);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005398);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005438);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800054D4);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800056B8);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005864);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800058E4);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005920);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005DB4);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005E18);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005E8C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005F04);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800060D0);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80006374);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800064A0);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800064D0);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800064F0);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80006548);

INCLUDE_ASM("asm/nonmatchings/_1050", func_8000674C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80006AB4);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80006B98);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80006CB8);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80006E2C);

void func_8000732C(void) {
}

int func_80007334()
{
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_1050", func_8000733C);

INCLUDE_RODATA("asm/nonmatchings/_1050", D_8007B7A4);
