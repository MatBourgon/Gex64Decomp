#include "common.h"

#include "types/GameTracker.h"
#include "types/Vector.h"

INCLUDE_ASM("asm/nonmatchings/_1050", func_80000450);

extern int D_800B83B0;
extern int D_800E8EC8;

void func_80000F24(Camera* camera, int arg1)
{
    D_800B83B0 = arg1;
    D_800E8EC8 = arg1 / 2;
    camera->cameraCore._08[14] = arg1;
    func_80000450(camera);
}

INCLUDE_ASM("asm/nonmatchings/_1050", func_80000F60);

INCLUDE_RODATA("asm/nonmatchings/_1050", D_8007B440);

extern int GetLevelIndexFromId(const char*);
BOOL IsLooneyLoading(const GameTracker* gameState)
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

void func_80001DF4(short arg0)
{
    short* ptr = (short*)gameTracker8->camera;
    ptr[0x180/2] = arg0;
    ptr[0x34/2] = arg0;
    ptr[0x3C/2] = arg0;
    ptr[0xC/2] = arg0;
    ptr[0x1C/2] = arg0;
    ptr[0x198/2] = arg0;

    ptr[0x1A8/2] = 0;
    ptr[0x1A0/2] = 0;
    ptr[0x2C4/2] = 0;
    ptr[0x2BC/2] = 0;
    ptr[0x268/2] = 0;
    ptr[0x260/2] = 0;
}

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

void func_800039E8(int* arg0, int arg1)
{
    arg0[0x468/4] = arg1;
    func_80003148(arg0, -1);
}

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003A0C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003A68);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80003B1C);

void func_80003D4C(int arg0)
{
    ((int*)gameTracker8->camera)[0x148/4] = arg0;
}

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

void func_800058E4(SVECTOR* newPoint, SVECTOR* oldPoint)
{
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, newPoint, oldPoint, NULL);
}

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005920);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005DB4);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005E18);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005E8C);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80005F04);

INCLUDE_ASM("asm/nonmatchings/_1050", func_800060D0);

INCLUDE_ASM("asm/nonmatchings/_1050", func_80006374);

void func_800064A0(int* arg0)
{
    func_80003234();
    arg0[0x1FC/4] = arg0[0x3A0/4];
}

void func_800064D0(SVECTOR* newPoint, SVECTOR* oldPoint)
{
    func_800058E4(newPoint, oldPoint);
}

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
