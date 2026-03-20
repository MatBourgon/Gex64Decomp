#include "common.h"
#include <compiler/gcc/string.h>
#include "SIGNAL.h"

#include "types/GameTracker.h"
#include "types/TVTextData.h"
#include "types/Instance.h"
#include "types/Signal.h"
#include "types/Matrix.h"

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_80049B80);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A2A4);

int func_8004A344(int*** arg0) {
    int** var_v0 = arg0[7];

  if (var_v0[1] == 0) return 0;

  return *var_v0[1];
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A368);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A3B4);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A420);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A47C);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A4E4);

void INSTANCE_InsertInstanceWithFlagsSet(Instance* instance, int flags) {
    int groupId;

    instance->flags |= flags;
    groupId = INSTANCE_InstanceGroupNumber(instance);
    func_800300BC(instance);
    LIST_InsertFunc(&gameTracker8->instanceList->group[groupId], &instance->node);
}

void INSTANCE_InsertInstanceWithFlagsCleared(Instance* instance, int flags) {
    int groupId;

    instance->flags &= ~flags;
    groupId = INSTANCE_InstanceGroupNumber(instance);
    func_800300BC(instance);
    LIST_InsertFunc(&gameTracker8->instanceList->group[groupId], &instance->node);
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A61C);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A67C);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A6C8);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A7B8);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A820);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A8A8);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A98C);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004A9C8);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004AA38);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004AA70);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004AAA8);

int func_8004AADC(void) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004AAE4);

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


INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004AC78);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004ACB0);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004AD5C);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004ADDC);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004AEC8);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004B090);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004B23C);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004B2DC);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004B32C);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004B380);

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

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E740); // logo1

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E748); // logo2

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E750); // logo3

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E758); // logo4

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E760); // intro1

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E768); // map5

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E770); // CHANNEL Z

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E77C); // final01

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E784); // MECHAREZ

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E790); // GEXZILLA VS.

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7A0); // gexzil9

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7A8); // MOOSHOO PORK

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7B8); // mooshu1

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7C0); // BOSS

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7C8); // GILLIGEX ISLE

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7D8); // gillig1 

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7E0); // CHIPS AND DIPS

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7F0); // circuit0

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E7FC); // BUGGED OUT

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E808); // rezop2

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E810); // CHINA SHOP

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E81C); // LIZARD IN A

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E828); // kungfu4

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E830); // LOVED HIMSELF

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E840); // THE SPY WHO

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E84C); // spy2

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E854); // IN DRAG NET

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E860); // nypd01

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E868); // THURSDAY THE 12TH

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E87C); // horror6

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E884); // BONANZA

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E88C); // BONUS

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E894); // AZTEC 2 STEP

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E8A4); // aztec16

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E8AC); // REZOPOLIS

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E8B8); // AND A FUNERAL

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E8C8); // NO WEDDINGS

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E8D4); // rezop3

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E8DC); // SAMURAI NIGHT FEVER

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E8F0); // kungfu1

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E8F8); // ASTEROIDS

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E904); // PAIN IN THE

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E910); // scifi14

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E918); // THE GECKO

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E924); // HONEY I SHRUNK

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E934); // circuit9

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E940); // THIS OLD CAVE

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E950); // prehst2

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E958); // FINE TOONING

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E968); // looney69

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E974); // PRE-HISTORY

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E980); // PANGAEA 90210

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E990); // prehst1

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E998); // CHANNEL

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9A0); // ROCKET

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9A8); // STRIKES OUT

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9B4); // THE UMPIRE

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9C0); // scifi10

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9C8); // THEATRE

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9D0); // KUNG-FU

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9D8); // MAO TSE TONGUE

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9E8); // kungfu02

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9F4); // CENTRAL

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007E9FC); // CIRCUIT

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA04); // WWW.DOTCOM.COM

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA14); // circuit5

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA20); // FRANKENSTEINFELD

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA34); // horror2

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA3C); // SPAN

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA44); // SEA

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA48); // GECQUES COUSTEAU

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA5C); // rta1

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA64); // SCREAM

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA6C); // SMELLRAISER

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA78); // horror4

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA80); // TV

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA84); // TOON

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA8C); // OUT OF TOON

INCLUDE_RODATA("asm/nonmatchings/SIGNAL", D_8007EA98); // looney30

extern u32 D_800AF060;
extern u32 D_800AF064;
extern u32 D_800AF068;
extern s32 D_800AF06C;

void func_8004B604(int* arg0, char** strs, s32 arg2, s32* arg3, s32* flagsOut, s32 arg5) {
    char* var_a0;
    s32 temp_v1;
    s32 i;
    s32 var_s2;
    s32 flags;
    s32 temp_v0;

    flags = 0;
    
    var_s2 = arg5;
    if (var_s2 == -1) {
        var_s2 = 0x2D;
    } else if (var_s2 == 0) {
        var_s2 = 0x1E;
    }
    
    for (i = 0; i < arg2; i++) {
        Set3DTextPosition((s32) ((0x140 - ((strlen(strs[i]) - 1) * 0x14)) << 0xF) >> 0x10, (s16) var_s2);
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
    if ((u32) D_800AF064 >= 0x10U) {
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

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004B968);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004BAAC);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004BFBC);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004C040);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004C110);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004C2F4);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004C350);

extern int D_8007864C[];

void func_8004C43C() {
    int i;
    
    for (i = 0x20; i < 0x24; ++i)
        D_8007864C[i-0x20] = 0;
}

s32 SIGNAL_HideObject(Instance* instance, void* signal) {
    ((int**)signal)[1][7] |= 0x80;                    
    return 1;     
}

s32 SIGNAL_UnhideObject(Instance* instance, void* signal) {
    ((int**)signal)[1][7] &= ~0x80;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004C4A4);

s32 SIGNAL_Timer(Instance* instance, void* signal) {
    int a = ((int*)signal)[1];
    int* b = &((int*)signal)[2];
    return func_8004C4A4(instance, a, 0, 0, b);
}

s32 SIGNAL_Frame(Instance* instance, void* signal) {
    return func_8004C4A4(instance, ((int*)signal)[1] - ((int*)gameTracker8)[0xE0/4], 0, 0, &((int*)signal)[2]);
}

s32 SIGNAL_StartSpline(Instance* instance, void* signal) {
    Intro* intro;

    intro = ((Intro**)signal)[1];
    
    if (intro->instance == NULL) {
        INSTANCE_BirthObjectFromIntro(intro);
    }
    
    if (intro->instance != NULL) {
        if (!(intro->instance->flags & 0x100000) && !(intro->instance->flags2 & 0x10000)) {
            intro->instance->flags2 |=  0x1000;
        }
        intro->instance->flags |= 0x02000000;
    }
    
    return 1;
}

s32 SIGNAL_StopSpline(Instance* instance, void* signal) {
    int* var1 = ((int**)signal)[1]; 

     if (((Instance*)var1[9]) != 0) {
        ((Instance*)var1[9])->flags &= ~0x2000000;
    }
    return 1;
}

s32 SIGNAL_StartAniTex(Instance* instance, void* signal) {
    return 1;
}

s32 SIGNAL_StopAniTex(Instance* instance, void* signal) {
    return 1;
}

s32 SIGNAL_GotoFrame(Instance* instance, void* signal) {
    short* temp_v1;

    temp_v1 = ((short***)signal)[1][0x24/4];
    if (temp_v1 != NULL) {
        temp_v1[0x5E/2] = ((unsigned char*)signal)[11];
    }
    return 1;
}

s32 SIGNAL_ChangeModel(Instance* instance, void* signal) {
    int* temp_v0 = ((int**)signal)[1];
    short* temp_v1  = (short*)temp_v0[9];
    
    if (temp_v1 != 0) {
        temp_v1[97] = ((int*)signal)[2];
    }
    return 1;
}

s32 SIGNAL_DSignal(Instance* instance, void* signal) {
    int var1;
    int* var2;

    var2 = ((int**)signal)[1];
    
    if (var2 != 0) 
    {
        var2[11] = ((int*)signal)[2];
         
    }
    return 1;
}

s32 SIGNAL_GSignal(Instance* instance, void* signal) {
    return 1;
}

s32 SIGNAL_DeathZ(Instance* instance, void* signal) {
    gameTracker8->level->deathZ = ((int*)signal)[1];
    return 1;
}

s32 SIGNAL_LightGroup(Instance* instance, void* signal) {
    instance->lightGroup = ((int*)signal)[1];
    return 1;
}

s32 SIGNAL_CameraAdjust(Instance* instance, void* signal) {
    func_80003B1C(gameTracker8->_0008, ((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_Camera(Instance* instance, void* signal) {
    func_80003D4C(((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_CameraMode(Instance* instance, void* signal) {
    func_80001408(gameTracker8->_0008, ((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_CameraLock(Instance* instance, void* signal) {
    func_80003118(gameTracker8->_0008, ((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_CameraUnlock(Instance* instance, void* signal) {
    func_8000312C(gameTracker8->_0008, ((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_CameraSmooth(Instance* instance, void* signal) {
    func_80003140(gameTracker8->_0008, ((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_8004C844(Instance* instance, void* signal)
{
    ((short*)gameTracker8->_0008)[0x16/2] = ((int*)signal)[1];
    return 1;
}

s32 SIGNAL_CameraTimer(Instance* instance, void* signal) {
    func_800039E8(gameTracker8->_0008, ((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_CameraSave(Instance* instance, void* signal) {
    func_80003148(gameTracker8->_0008, ((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_CameraRestore(Instance* instance, void* signal) {
    func_80003910(gameTracker8->_0008, ((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_CameraValue(Instance* instance, void* signal) {
    func_80002198(gameTracker8->_0008, ((int*)signal)[1], ((int*)signal)[2]);
    return 1;
}

typedef struct
{
    int id;
    SVECTOR entryLocation;
    short r;
    SVECTOR exitLocation;
} TeleportSignal;

s32 SIGNAL_Teleport(Instance* instance, void* signal) {
    SVECTOR sp10;
    MATRIX sp18;
    SVECTOR deltaPosition;
    TeleportSignal* tpSignal = signal;

    deltaPosition.x = instance->position.x - tpSignal->entryLocation.x;
    deltaPosition.y = instance->position.y - tpSignal->entryLocation.y;
    deltaPosition.z = instance->position.z - tpSignal->entryLocation.z;
    // Probably some kind of matrix being built to rotate the instance after teleportation
    MATH3D_SetUnityMatrix(&sp18); // int vector? [1 0 0] [0 1 0] [1 0 0]
    RotMatrixZ(tpSignal->r, &sp18); // rotate
    MATH3D_ApplyMatrixSV(&sp18, &deltaPosition, &sp10); // (Matrix x Vector) -> Vector
    instance->_80[6] = tpSignal->exitLocation.x - deltaPosition.x;
    instance->_80[7] = tpSignal->exitLocation.y - deltaPosition.y;
    instance->_90[0] = tpSignal->exitLocation.z - deltaPosition.z;
    instance->_80[6] += sp10.x;
    instance->_80[7] += sp10.y;
    instance->_90[0] += sp10.z;
    instance->_90[1] = tpSignal->r;
    ((short*)gameTracker8->_0008)[0x140/2] += instance->_90[0];
    ((short*)gameTracker8->_0008)[0x142/2] += instance->_90[0];
    ((int*)gameTracker8->_0008)[0x450/4] = 1;
    ((short*)gameTracker8->_0008)[0x16/2] = 3;
    ((short*)gameTracker8->_0008)[0x17A/2] = ((short*)gameTracker8->_0008)[6] + tpSignal->r;
    return 1;
}

s32 SIGNAL_FarPlane(Instance* instance, void* signal) {
    ((int*)gameTracker8->_0008)[0x5C/4] = ((int*)signal)[1];
    return 1;
}

s32 SIGNAL_SoundStartSequence(Instance* instance, void* signal) {
    int sp10[5];

    sp10[1] = ((int*)signal)[0];
    sp10[2] = ((int*)signal)[1];
    sp10[3] = ((int*)signal)[2];
    func_80050854(instance, &sp10);
    return 1;
}

s32 SIGNAL_SoundStopSlot(Instance* instance, void* signal) {
    int* var1[5];

    var1[1] = ((int**)signal)[0];
    var1[2] = ((int**)signal)[1];

    func_80050854(instance, var1);

    return 1;
}

s32 SIGNAL_SoundPauseSlot(Instance* instance, void* signal) {
    int sp10[5];

    sp10[1] = ((int*)signal)[0];
    sp10[2] = ((int*)signal)[1];
    func_80050854(instance, &sp10);
    return 1;
}


s32 SIGNAL_SoundResumeSlot(Instance* instance, void* signal) {
    int sp10[5];

    sp10[1] = ((int*)signal)[0];
    sp10[2] = ((int*)signal)[1];
    func_80050854(instance, &sp10);
    return 1;
}

s32 SIGNAL_SoundMuteChannel(Instance* instance, void* signal) {
    int sp10[5];

    sp10[1] = ((int*)signal)[0];
    sp10[2] = ((int*)signal)[1];
    sp10[3] = ((int*)signal)[2];
    func_80050854(instance, &sp10);
    return 1;
}

s32 SIGNAL_SoundUnmuteChannel(Instance* instance, void* signal) {
    int sp10[5];

    sp10[1] = ((int*)signal)[0];
    sp10[2] = ((int*)signal)[1];
    sp10[3] = ((int*)signal)[2];
    func_80050854(instance, &sp10);
    return 1;
}

s32 SIGNAL_Times(Instance* instance, void* signal) {
    if (((int*)signal)[1] > 0) {
        --((int*)signal)[1];
        return 1;
    }
   
    return 0;
}

extern s32 D_800785C8;

typedef struct
{
    int id;
    Intro* intro;
} FreezeSignal;

s32 SIGNAL_Freeze(Instance* instance, void* signal) {
    s32 n;
    Instance* frInstance;
    FreezeSignal* frSignal = signal;

    if (frSignal->intro == NULL) {
        n = PlayerInstance->_F4[0];
        if (n != 5) {
            if (n == 4) {
                func_8000B054(gameTracker8->_0008);
            }
            D_800785C8 = PlayerInstance->_F4[0];
        } else {
            D_800785C8 = 0;
        }
        PlayerInstance->_F4[0] = 5;
    } else {
        frSignal->intro->flags |= 0x100;
        frInstance = frSignal->intro->instance;
        if (frInstance != NULL) {
            if (frInstance->flags2 & 0x10000) {
                func_800331BC(frInstance->_D0[0]);
                frInstance->flags2 &= ~0x10000;
                frInstance->flags2 &= ~0x20000;
            }
        }
    }
    return 1;
}

s32 SIGNAL_UnFreeze(Instance* instance, void* signal) {
    Instance* inst;
    FreezeSignal* frSignal = signal;

    if (frSignal->intro == NULL) {
        PlayerInstance->_F4[0] = D_800785C8;
    } else {
        frSignal->intro->flags &= ~0x100;
        inst = frSignal->intro->instance;
        if (inst != NULL) {
            inst->flags &= ~0x800000;
            if (!(inst->flags & 0x100000)) {
                if (!(inst->flags2 & 0x10000)) {
                    inst->flags2 |= 0x1000;
                }
            }
        }
    }
    return 1;
}

s32 SIGNAL_FreezeAll(Instance* instance, void* signal) {
    Intro* temp_a0_2;
    Intro* var_v1;
    char _[0x10]; // very cool
    
    temp_a0_2 = &gameTracker8->level->introList[gameTracker8->level->numIntros];

    for (var_v1 = gameTracker8->level->introList; var_v1 < temp_a0_2; var_v1++) {
        var_v1->flags |= 0x100;
    }
    
    if (PlayerInstance->_F4[0] != 4) {
        if (PlayerInstance->_F4[0] == 5) {
            D_800785C8 = 0;
        } else {
            D_800785C8 = PlayerInstance->_F4[0];
        }
    }
    PlayerInstance->_F4[0] = 5;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", SIGNAL_UnfreezeAll);
/*s32 SIGNAL_UnfreezeAll(Instance* instance, void* signal) {
    Instance* temp_a0_3;
    Intro* temp_v1;
    Intro* temp_a0_2;
    
    temp_a0_2 = &gameTracker8->level->introList[gameTracker8->level->numIntros];

    for(temp_v1 = gameTracker8->level->introList; temp_v1 < temp_a0_2; temp_v1++)
    {
        temp_v1->flags &= ~0x100;
        temp_a0_3 = temp_v1->instance;
        if (temp_a0_3 != NULL)
        {
            temp_a0_3->flags &= ~0x800000;
            if (!(temp_a0_3->flags & 0x100000) && !(temp_a0_3->flags2 & 0x10000))
            {
                temp_a0_3->flags2 |= 0x1000;
            }
        }
    }
    
    PlayerInstance->_F4[0] = D_800785C8;
    return 1;
}*/

s32 SIGNAL_BirthObject(Instance* instance, void* signal) {
    Intro* intro = ((Intro**)signal)[1];
    if ((intro != NULL) && !(intro->flags & 8)) {
        INSTANCE_BirthObjectFromIntro(intro);
    }
    return 1;
}

s32 SIGNAL_8004CFC8(Instance* instance, void* signal) {
    Intro* intro;

    intro = ((Intro**)signal)[1];
    if (intro->instance != NULL) {
        INSTANCE_KillInstance(intro->instance);
        intro->instance = NULL;
    }
    return 1;
}

s32 SIGNAL_HideBG(Instance* instance, void* signal) {
    BGObject* pEnd;
    BGObject* pObj;

    pObj = gameTracker8->level->bgObjectList;
    pEnd = pObj + gameTracker8->level->numBGObjects;
    while (pObj < pEnd) {
        (pObj++)->flags |= 1;
    }
    return 1;
}

s32 SIGNAL_UnhideBG(Instance* instance, void* signal) {
    BGObject* pEnd;
    BGObject* pObj;

    pObj = gameTracker8->level->bgObjectList;
    pEnd = pObj + gameTracker8->level->numBGObjects;
    while (pObj < pEnd) {
        (pObj++)->flags &= ~1;
    }
    return 1;
}

s32 SIGNAL_HideBGObject(Instance* instance, void* signal) {
    short* temp_v1 = ((short**)signal)[1];
        
    if (temp_v1 != 0) {
        *temp_v1 |= 1;
    }
    return 1;
}

s32 SIGNAL_UnhideBGObject(Instance* instance, void* signal) {
    short* temp_v1 = ((short**)signal)[1];
        
    if (temp_v1 != 0) {
        *temp_v1 &= ~1;
    }
    return 1;
}

s32 SIGNAL_Mirror(Instance* instance, void* signal) {
    instance->flags |= 0x20000000;
    return 1;
}

s32 SIGNAL_Unmirror(Instance* instance, void* signal) {
    instance->flags &= ~0x20000000;
    return 1;
}

s32 SIGNAL_SetMirror(Instance* instance, void* signal)
{
    ((int*)gameTracker8)[0x4C14/4] = ((int*)signal)[1];
    return 1;
}

s32 SIGNAL_FogNear(Instance* instance, void* signal)
{
    gameTracker8->level->fogNear = ((int*)signal)[1];
    return 1;
}

s32 SIGNAL_FogFar(Instance* instance, void* signal)
{
    gameTracker8->level->fogFar = ((int*)signal)[1];
    return 1;
}

s32 SIGNAL_StartVertexMorph(Instance* instance, void* signal) {
    ((int**)signal)[1][0] &= ~2;
    return 1;
}

s32 SIGNAL_StopVertexMorph(Instance* instance, void* signal) {
    ((int**)signal)[1][0] |= 2;
    return 1;
}

extern int D_800785CC[];

s32 SIGNAL_LogicValue(Instance* instance, void* signal)
{
    D_800785CC[((int*)signal)[1]] = ((int*)signal)[2];
    return 1;
}

s32 SIGNAL_CameraShake(Instance* instance, void* signal) {
    func_80003D68(gameTracker8->_0008, ((int*)signal)[1], ((int*)signal)[2]);
    return 1;
}

s32 SIGNAL_LogicAnd(Instance* instance, void* signal) {
    D_800785CC[((unsigned char*)signal)[4]] = D_800785CC[((unsigned char*)signal)[5]] && D_800785CC[((unsigned char*)signal)[6]];
    return 1;
}

s32 SIGNAL_LogicOr(Instance* instance, void* signal) {
    D_800785CC[((unsigned char*)signal)[4]] = D_800785CC[((unsigned char*)signal)[5]] || D_800785CC[((unsigned char*)signal)[6]];
    return 1;
}

s32 SIGNAL_LogicXor(Instance* instance, void* signal) {
    D_800785CC[((unsigned char*)signal)[4]] = D_800785CC[((unsigned char*)signal)[5]] ^ D_800785CC[((unsigned char*)signal)[6]];
    return 1;
}

s32 SIGNAL_LogicTrue(Instance* instance, void* signal) {
    if (D_800785CC[((unsigned char*)signal)[4]] != 0) {
        if (((int**)signal)[2] != 0) {
            SIGNAL_HandleSignal(instance, ((int**)signal)[2], 0);
            return 0;
        }
    }
    else if (((int**)signal)[2] == NULL) {
        return 0;
    }
    return 1;
}

s32 SIGNAL_LogicFalse(Instance* instance, void* signal) {
    if (D_800785CC[((unsigned char*)signal)[4]] == 0) {
        if (((int**)signal)[2] != 0) {
            SIGNAL_HandleSignal(instance, ((int**)signal)[2], 0);
            return 0;
        }
    }
    else if (((int**)signal)[2] == NULL) {
        return 0;
    }
    return 1;
}

s32 SIGNAL_CallSignal(Instance* instance, void* signal)
{
    SIGNAL_HandleSignal(instance, ((void**)signal)[1]+4, 0);
    return 1;
}

s32 SIGNAL_Offset(Instance* instance, void* signal) {
    *(ROTATION*)&instance->_80[6] =  *(ROTATION*)&(((short*)signal)[2]);
    return 1;
}

s32 SIGNAL_LogicAdd(Instance* instance, void* signal) {
    D_800785CC[((unsigned char*)signal)[4]] = D_800785CC[((unsigned char*)signal)[5]] + D_800785CC[((unsigned char*)signal)[6]];
    return 1;
}

s32 SIGNAL_LogicSub(Instance* instance, void* signal) {
    D_800785CC[((unsigned char*)signal)[4]] = D_800785CC[((unsigned char*)signal)[5]] - D_800785CC[((unsigned char*)signal)[6]];
    return 1;
}

s32 SIGNAL_Goto(Instance* instance, void* signal) {
    SIGNAL_HandleSignal(instance, ((int**)signal)[1], 0);
    return 0;
}

s32 SIGNAL_Label(Instance* instance, void* signal) {
    return 1;
}

s32 SIGNAL_End(Instance* instance, void* signal) {
    return 0;
}

s32 SIGNAL_GoSub(Instance* instance, void* signal)
{
    SIGNAL_HandleSignal(instance, ((void**)signal)[1], 0);
    return 1;
}

s32 SIGNAL_StopPlayerControl(Instance* instance, void* signal)
{
    ((int*)gameTracker8)[0x4C08/4] |= 0x90;
    return 1;
}

s32 SIGNAL_StartPlayerControl(Instance* instance, void* signal)
{
    ((int*)gameTracker8)[0x4C08/4] &= ~0x80;
    ((int*)gameTracker8)[0x4C08/4] &= ~0x10;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004D5A4);

extern void func_8004D5A4(void);

s32 SIGNAL_SetPlayerControl(Instance* instance, void* signal) {
    void* signal1 = ((void**)signal)[1];
    void* signal3 = &((void**)signal)[3];
    return func_8004C4A4(instance, signal1, &func_8004D5A4, signal, signal3);
}

s32 SIGNAL_Launch(Instance* instance, void* signal) {
    func_80027468();
    return 1;
}

s32 SIGNAL_CostumeChange(Instance* instance, void* signal) {
    func_80023828(gameTracker8->_000C, gameTracker8, signal + 4 /* i think this was a char* on n64 */);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", SIGNAL_GameValue);

typedef struct
{
    short a;
    short b;
    int c;
    int d;
} func_8004D83C_t_1;

extern func_8004D83C_t_1 D_800EB9B0[];

s32 SIGNAL_SetZSignal(Instance* instance, void* signal) {
    int temp_a0;
    int temp_a2;
    short temp_v2;
    short temp_v0;

    temp_v0 = ((short*)signal)[2];
    temp_a0 = ((int*)signal)[2];
    temp_a2 = ((int*)signal)[3];
    temp_v2 = ((short*)signal)[3];
    
    if (temp_v0 < 0x10U) {
        (D_800EB9B0)[temp_v0].a = temp_v2;
        if (temp_a0 != 0) {
            (D_800EB9B0)[temp_v0].c = temp_a0 + 4;
        }
        if (temp_a2 != 0) {
            (D_800EB9B0)[temp_v0].d = temp_a2 + 4;
        }
    }
    return 1;
}

extern int D_800EB9B4[];
extern int D_800EB9B8[];

s32 SIGNAL_ResetZSignal(Instance* instance, void* signal) {
    int i = ((short*)signal)[2] * 3;

    D_800EB9B4[i] = 0;
    D_800EB9B8[i] = 0;

    return 1;
}

s32 SIGNAL_SoundEffect(Instance* instance, void* signal) {
    
    if (((int*)signal)[1] == 0xFFFF) {
        ((char*)gameTracker8)[0x4C60] = 1;
    } else if (((int*)signal)[1] == 0xFFFE) {
        func_800331DC();
        ((char*)gameTracker8)[0x4C60] = 0;
    } else {
        func_80050980(((int*)signal)[1]);
    }
    return 1;
}

s32 SIGNAL_MusicControl(Instance* instance, void* signal) {
    func_80033334(((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_SetMusicVariable(Instance* instance, void* signal)
{
    int sp10[5];

    sp10[1] = ((int*)signal)[0];
    sp10[2] = ((int*)signal)[1];
    sp10[3] = ((int*)signal)[2];
    func_80050854(instance, &sp10);

    return 1;
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", SIGNAL_LevelChange);
/*
s32 SIGNAL_LevelChange(Instance* instance, void* signal) {
    char sp10[0x10];
    s32 var_v1;
    char temp_v0;
    char* var_a0;
    char* var_a1;

    var_a1 = &((char**)signal)[1];
    var_v1 = 0;
    do
    {
        sp10[var_v1++] = *var_a1++;
    } while(var_v1 < 8 && *var_a1 != '_');

    sp10[var_v1] = 0;
    if (((short*)gameTracker8)[0x9C/2] == 0xB) {
        ((short*)gameTracker8)[0x9C/2] = -1;
    }
    func_800396E0(0, sp10, gameTracker8);
    return 1;
}*/

s32 SIGNAL_VoiceControl(Instance* instance, void* signal) {
    return 1;
}

s32 SIGNAL_BankChange(Instance* instance, void* signal) {
    return 1;
}
s32 SIGNAL_GameLoadSave(Instance* instance, void* signal) {
    return 1;
}

s32 SIGNAL_HideObjectGroup(Instance* instance, void* signal) {
    int length;
    int index;
    int** ptr;

    length = ((int**)signal)[1][0];
    ptr = &(((int***)signal)[1][1]);
    
    for (index = 0; index < length; ++index) {
        ptr[index][7] |= 0x80;
    }
    return 1;
}

s32 SIGNAL_UnhideObjectGroup(Instance* instance, void* signal) {
    int length;
    int index;
    int** ptr;

    length = ((int**)signal)[1][0];
    ptr = &(((int***)signal)[1][1]);
    
    for (index = 0; index < length; ++index) {
        ptr[index][7] &= ~0x80;
    }
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004DB04);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", func_8004DD08);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", SIGNAL_Shards);

INCLUDE_ASM("asm/nonmatchings/SIGNAL", SIGNAL_CameraSpline);

s32 SIGNAL_ScreenWipe(Instance* instance, void* signal) {
    ((short*)gameTracker8)[0x98/2] = (u16) ((short*)signal)[3];
    ((short*)gameTracker8)[0x9A/2] = abs(((short*)signal)[3]);
    ((short*)gameTracker8)[0x9C/2] = (u16) ((short*)signal)[2];
    return 1;
}

s32 SIGNAL_VoiceQueue(Instance* instance, void* signal) {
    func_80052944(((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_VoiceUnQueue(Instance* instance, void* signal) {
    func_8005294C(((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_VoiceRequest(Instance* instance, void* signal) {
    func_80052A7C(((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_VoiceForce(Instance* instance, void* signal) {
    func_80052AA8(((int*)signal)[1]);
    return 1;
}

s32 SIGNAL_VoiceClearQueue(Instance* instance, void* signal) {
    func_80052954();
    return 1;
}

s32 SIGNAL_VoiceDisable(Instance* instance, void* signal) {
    func_80052F58();
    return 1;
}

s32 SIGNAL_VoiceReEnable(Instance* instance, void* signal) {
    func_80052F7C();
    return 1;
}

s32 SIGNAL_IntroActive(Instance* instance, void* signal) {
    if ((((int**)signal)[1] != 0) && (((int**)signal)[1][7] & 8)) {
        if (((int*)signal)[2] != NULL) {
            SIGNAL_HandleSignal(instance, ((int**)signal)[2], 0);
            return 0;
        }
    }
    return 1;
}

s32 SIGNAL_IntroFX(Instance* instance, void* signal) {
    if ((((Intro**)signal)[2] == NULL) || (((Intro**)signal)[2]->instance != 0)) {
        ((int*)gameTracker8)[0x4C48/4] = ((int*)signal)[1];
        ((int*)gameTracker8)[0x4C4C/4] = abs(((int*)signal)[1]);
        ((Intro**)gameTracker8)[0x4CA8/4] = ((Intro**)signal)[2];
    }
    return 1;
}

s32 SIGNAL_GotoPos(Instance* instance, void* signal) {
    instance->_80[6] = ((short*)signal)[2] - instance->position.x;
    instance->_80[7] = ((short*)signal)[3] - instance->position.y;
    instance->_90[0] = ((short*)signal)[4] - instance->position.z;
    ((short*)gameTracker8->_0008)[3] = 3;
    return 1;
}

s32 SIGNAL_BlendStart(Instance* instance, void* signal)
{
    gameTracker8->level->_54 = ((int*)signal)[1];
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", SIGNAL_MiscValue);

s32 SIGNAL_SetTimes(Instance* instance, void* signal) {
    ((int**)signal)[1][1] = ((int*)signal)[2]; 
    return 1;
}             

s32 SIGNAL_ScreenWipeColor(Instance* instance, void* signal) {
    func_80039688(((char*)signal)[4], ((char*)signal)[5], ((char*)signal)[6], gameTracker8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/SIGNAL", SIGNAL_Relocate);

s32 SIGNAL_LogicTrueElse(Instance* instance, void* signal) {
    if (D_800785CC[((unsigned char*)signal)[4]] != 0 && ((int**)signal)[2] != 0) {
        SIGNAL_HandleSignal(instance, ((int**)signal)[2], 0);
        return 0;
    }
    return 1;
}

s32 SIGNAL_LogicFalseElse(Instance* instance, void* signal) {
    if (D_800785CC[((unsigned char*)signal)[4]] == 0 && ((int**)signal)[2] != 0) {
        SIGNAL_HandleSignal(instance, ((int**)signal)[2], 0);
        return 0;
    }
    return 1;
}

typedef struct
{
    short a, b;
    int c;
    int d;
} SIGNAL_Print_t;

extern SIGNAL_Print_t D_800E9788[];

s32 SIGNAL_Print(Instance* instance, void* signal) {
    int i;

    for (i = 0; i < 5; ++i) {
        if (D_800E9788[i].d == 0) {
            D_800E9788[i].c = ((short*)signal)[0xA/2];
            D_800785CC[((short*)signal)[0xA/2]] = ((short*)signal)[0x8/2];
            D_800E9788[i].a = ((short*)signal)[0x4/2];
            D_800E9788[i].b = ((short*)signal)[0x6/2];
            D_800E9788[i].d = ((int*)signal)[0xC/4];
        }
    }
    return 1;
}

extern short D_8007865C;

s32 SIGNAL_TagTimer(Instance* instance, void* signal) {
    D_8007865C = 1;
    return 1;
}

s32 SIGNAL_SetNoRemove(Instance* instance, void* signal) {
    Instance* inst;
    Intro* intro = ((Intro**)signal)[1];

    if (intro != NULL) {
        intro->flags |= 0x2000;
        inst = ((Intro**)signal)[1]->instance;
        if (inst != NULL) {
            inst->flags = (s32) (inst->flags | 0x400);
        }
    }
    return 1;
}

s32 SIGNAL_ResetNoRemove(Instance* instance, void* signal) {
    
    Intro* intro = ((Intro**)signal)[1];
    if (intro) {
        
        Instance* inst = intro->instance;
        intro->flags &= ~0x2000;
        
        if (inst) {
            inst->flags &= ~0x400;
        }
        
    }
    return 1;
}

s32 SIGNAL_8004E95C(Instance* instance, void* signal) {
    int temp_v1 = ((int*)signal)[1];
    
    if ((temp_v1 != 0) && (temp_v1 == 1)) {
        func_8015E228();
    } else {
        func_8002AE40();
    }
    return 1;
}

extern int D_8015EE24;

s32 SIGNAL_8004E9A8(Instance* instance, void* signal) {
    D_8015EE24 = ((int*)signal)[1];
    return 1;
}

extern int D_8015EE28;

s32 SIGNAL_8004E9BC(Instance* instance, void* signal) {
    D_8015EE28 = ((int*)signal)[1];
    return 1;
}

extern int D_8015EE2C;

s32 SIGNAL_8004E9D0(Instance* instance, void* signal) {
    D_8015EE2C = ((int*)signal)[1];
    return 1;
}

extern int D_8015EE30;

s32 SIGNAL_8004E9E4(Instance* instance, void* signal) {
    D_8015EE30 = ((int*)signal)[1];
    return 1;
}

s32 SIGNAL_8004E9F8(Instance* instance, void* signal) {
    int* temp_v0;
    int* temp_v1;

    temp_v1 = ((int**)signal)[2];
    if (temp_v1 != 0) {
        temp_v0 = (int*)temp_v1[9];
        
        if (temp_v0 != 0) {
        temp_v1 =  ((int**)signal)[1];
        (int*)temp_v0[72] = temp_v1;
        }
    } 
    
    return 1;
}

s32 SIGNAL_8004EA2C(Instance* instance, void* signal) {
    s32* temp_v0;
    short* temp_v1;

    temp_v0 = (s32*)gameTracker8->_000C;
    temp_v1 = (short*)temp_v0[0x20/4];
    ((short*)temp_v0)[0x64/2] = 0;
    temp_v1[0x82/2] = 0;
    temp_v1[0x84/2] = 0;
    return 1;
}

void COLLIDE_HandleSignal(Instance* instance, BaseSignal* signal, int numSignals, int arg3) {
    int s4, s3;
    int v0;
    int s2 = 0;
    BaseSignal* baseSignal = signal;

    if (arg3 == 1U || arg3 == 0)
        s2 = 1;
    else if (*(int*)(arg3+16) >= 2U) // Doesn't make sense
        return;

    if (numSignals == 0)
        return;
    
    s4 = 0x80000000;
    s3 = 0x7FFFFFFF;
    
    while (!((D_80078664[signal->id].onlyPlayer == 0 || instance == PlayerInstance || s2 != 0)
        && ((gameTracker8->gameFlags & 0x40) == 0 || ((signal->id & s4) == 0))
        && (D_80078664[(signal->id & s3)].func(instance, signal) == 0)))
    {
        v0 = (D_80078664[signal->id].length + 1);
        signal += v0;
    }

}

void SIGNAL_HandleSignal(Instance* instance, void* signal, int arg2) {
    COLLIDE_HandleSignal(instance, signal, 1, arg2);
}

typedef struct
{
    int* ptr;
    int value;
} func_8004EBD0_t;

int func_8004EBD0(func_8004EBD0_t* arg0) {
    if (arg0 == NULL)
        return;
    
    while (arg0->ptr != NULL)
    {
        *arg0->ptr = arg0->value;
        arg0++;
    }
}
