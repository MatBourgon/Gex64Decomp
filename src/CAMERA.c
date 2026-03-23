#include "common.h"

#include "CAMERA.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80000450);

extern int D_800B83B0;
extern int D_800E8EC8;

void func_80000F24(Camera* camera, int arg1)
{
    D_800B83B0 = arg1;
    D_800E8EC8 = arg1 / 2;
    camera->cameraCore._08[14] = arg1;
    func_80000450(camera);
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", CAMERA_SaveMode);

INCLUDE_RODATA("asm/nonmatchings/CAMERA", D_8007B440);

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

INCLUDE_ASM("asm/nonmatchings/CAMERA", CAMERA_SetMode);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_800018F0);

void func_80001DF4(short arg0) // set z rot?
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

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80001E3C);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80001EAC);

int CAMERA_LengthSVector(SVECTOR* sv) {
    return (MATH3D_FastSqrt2((sv->x * sv->x + sv->y * sv->y + sv->z * sv->z) << 4, 4) + 8) >> 4;
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80002134);

INCLUDE_ASM("asm/nonmatchings/CAMERA", CAMERA_SetValue);

short CAMERA_AngleDifference(short angle0, short angle1) {
    angle0 &= 0xFFF;
    angle1 &= 0xFFF;

    if ((angle1 - angle0) > 2048)
        angle0 |= 0x1000;
    else if ((angle0 - angle1) > 2048)
    {
        angle1 |= 0x1000;
    }

    return (angle0 > angle1 ? angle0 : angle1) - (angle0 < angle1 ? angle0 : angle1);
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80002678);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80002734);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80002888);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80002908);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80002A88);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80002B18);

int CAMERA_CameraLock(Camera* camera, int arg1) {
    camera->lock |= arg1;
}

int CAMERA_CameraUnlock(Camera* camera, int arg1) {
    camera->lock &= ~arg1;
}

int CAMERA_SetSmoothValue(Camera* camera, int arg1) {
    camera->smooth = arg1;
}

void CAMERA_Save(Camera* camera, int save) {
    int i;

    if (((int*)camera)[0x14C/4] == 0x10) {
        func_8015E27C();
        return;
    }
    else if (((int*)camera)[0x14C/4] != 2) {
        if (save & 1) {
            camera->targetStack++;
            if (camera->targetStack == 8) {
                camera->targetStack = 7;
                
                for (i = 0; i < 7; i++) {
                    camera->savedTargetFocusDistance[i] = camera->savedTargetFocusDistance[i + 1];
                }
            }
            camera->savedTargetFocusDistance[camera->targetStack] = camera->targetFocusDistance;
        }
        
        if (save & 2) {
            camera->savedFocusRotation.x = camera->targetFocusRotationX;
        }
        
        if (save & 4) {
            camera->savedFocusRotation.z = camera->focusRotationX;
        }
    }
    if (save & 0x100) {
        CAMERA_SaveMode(camera, ((int*)camera)[0x14C/4], ((int*)camera)[0x43C/4]); // CAMERA_SaveMode, one of these is camera->mode
    }
}

void func_8000322C(void) {
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80003234);

INCLUDE_ASM("asm/nonmatchings/CAMERA", CAMERA_Restore);

void CAMERA_SetTimer(Camera* camera, int arg1)
{
    camera->timer = arg1;
    CAMERA_Save(camera, -1);
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80003A0C);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80003A68);

INCLUDE_ASM("asm/nonmatchings/CAMERA", CAMERA_Adjust);

void CAMERA_ChangeTo(CameraKey* key)
{
    gameTracker8->camera->cameraKey = key;
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", CAMERA_SetShake);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80003DAC);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80003E18);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80003F6C);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_8000486C);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80004930);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80004A60);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80004B70);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80005398);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80005438);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_800054D4);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_800056B8);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80005864);

void func_800058E4(SVECTOR* newPoint, SVECTOR* oldPoint)
{
    COLLIDE_PointAndTerrain(gameTracker8->level->segmentAddress, newPoint, oldPoint, NULL);
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80005920);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80005DB4);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80005E18);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80005E8C);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80005F04);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_800060D0);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80006374);

void func_800064A0(int* arg0)
{
    func_80003234();
    arg0[0x1FC/4] = arg0[0x3A0/4];
}

void func_800064D0(SVECTOR* newPoint, SVECTOR* oldPoint)
{
    func_800058E4(newPoint, oldPoint);
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_800064F0);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80006548);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_8000674C);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80006AB4);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80006B98);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80006CB8);

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_80006E2C);

void func_8000732C(void) {
}

int func_80007334()
{
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/CAMERA", func_8000733C);

INCLUDE_RODATA("asm/nonmatchings/CAMERA", D_8007B7A4);
