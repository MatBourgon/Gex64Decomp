#include "common.h"
#include <compiler/gcc/string.h>
#include "_4a780.h"

#include "types/GameTracker.h"
#include "types/TVTextData.h"
#include "types/Instance.h"
#include "types/Signal.h"

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

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B604);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004B968);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004BAAC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004BFBC);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C040);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C110);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C2F4);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C350);

extern int D_8007864C[];

void func_8004C43C() {
    int i;
    
    for (i = 0x20; i < 0x24; ++i)
        D_8007864C[i-0x20] = 0;
}

int SIGNAL_HideObject(Instance* instance, void* signal) {
    ((int**)signal)[1][7] |= 0x80;                    
    return 1;     
}

int SIGNAL_UnhideObject(Instance* instance, void* signal) {
    ((int**)signal)[1][7] &= ~0x80;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004C4A4);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_Timer);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_Frame);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_StartSpline);

int SIGNAL_StopSpline(Instance* instance, void* signal) {
    int* var1 = ((int**)signal)[1]; 

     if (((Instance*)var1[9]) != 0) {
        ((Instance*)var1[9])->flags &= 0xFDFFFFFF;
    }
    return 1;
}

int SIGNAL_StartAniTex(Instance* instance, void* signal) {
    return 1;
}

int SIGNAL_StopAniTex(Instance* instance, void* signal) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_GotoFrame);

int SIGNAL_ChangeModel(Instance* instance, void* signal) {
    int* temp_v0 = ((int**)signal)[1];
    short* temp_v1  = (short*)temp_v0[9];
    
    if (temp_v1 != 0) {
        temp_v1[97] = ((int*)signal)[2];
    }
    return 1;
}

int SIGNAL_DSignal(Instance* instance, void* signal) {
    int var1;
    int* var2;


    var2 = ((int**)signal)[1];
    
    if (var2 != 0) 
    {
        var2[11] = ((int*)signal)[2];
         
    }
    return 1;
}

int SIGNAL_GSignal(Instance* instance, void* signal) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_DeathZ);

int SIGNAL_LightGroup(Instance* instance, void* signal) {
    instance->_4F = ((int*)signal)[1];
    
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraAdjust);

int SIGNAL_Camera(Instance* instance, void* signal) {
    func_80003D4C(((int*)signal)[1]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraMode);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraLock);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraUnlock);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraSmooth);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_8004C844);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraTimer);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraSave);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraRestore);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraValue);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_Teleport);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_FarPlane);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_SoundStartSequence);

int SIGNAL_SoundStopSlot(Instance* instance, void* signal) {
    int* var1[5];

    var1[1] = ((int**)signal)[0];
    var1[2] = ((int**)signal)[1];

    func_80050854(instance, var1);

    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_SoundPauseSlot);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_SoundResumeSlot);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_SoundMuteChannel);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_SoundUnmuteChannel);

int SIGNAL_Times(Instance* instance, void* signal) {
    if (((int*)signal)[1] > 0) {
        --((int*)signal)[1];
        return 1;
    }
   
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_Freeze);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_UnFreeze);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_FreezeAll);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_UnfreezeAll);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_BirthObject);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_8004CFC8);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_HideBG);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_UnhideBG);

int SIGNAL_HideBGObject(Instance* instance, void* signal) {
    short* temp_v1 = ((short**)signal)[1];
        
    if (temp_v1 != 0) {
        *temp_v1 |= 1;
    }
    return 1;
}

int SIGNAL_UnhideBGObject(Instance* instance, void* signal) {
    short* temp_v1 = ((short**)signal)[1];
        
    if (temp_v1 != 0) {
        *temp_v1 &= ~1;
    }
    return 1;
}

int SIGNAL_Mirror(Instance* instance, void* signal) {
    instance->flags |= 0x20000000;
    return 1;
}

int SIGNAL_Unmirror(Instance* instance, void* signal) {
    instance->flags &= ~0x20000000;
    return 1;
}

int SIGNAL_SetMirror(Instance* instance, void* signal)
{
    ((int*)gameTracker8)[0x4C14/4] = ((int*)signal)[1];
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_FogNear);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_FogFar);

int SIGNAL_StartVertexMorph(Instance* instance, void* signal) {
    ((int**)signal)[1][0] &= ~2;
    return 1;
}

int SIGNAL_StopVertexMorph(Instance* instance, void* signal) {
    ((int**)signal)[1][0] |= 2;
    return 1;
}

extern int D_800785CC[];

int SIGNAL_LogicValue(Instance* instance, void* signal)
{
    D_800785CC[((int*)signal)[1]] = ((int*)signal)[2];
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraShake);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_LogicAnd);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_LogicOr);

int SIGNAL_LogicXor(Instance* instance, void* signal) {
    D_800785CC[((unsigned char*)signal)[4]] = D_800785CC[((unsigned char*)signal)[5]] ^ D_800785CC[((unsigned char*)signal)[6]];
    return 1;
}

int SIGNAL_LogicTrue(Instance* instance, void* signal) {
    if (D_800785CC[((unsigned char*)signal)[4]] != 0) {
        if (((int**)signal)[2] != 0) {
            SIGNAL_HandleSignal(instance, ((int**)signal)[2], NULL);
            return 0;
        }
    }
    else if (((int**)signal)[2] == NULL) {
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_LogicFalse);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CallSignal);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_Offset);

int SIGNAL_LogicAdd(Instance* instance, void* signal) {
    D_800785CC[((unsigned char*)signal)[4]] = D_800785CC[((unsigned char*)signal)[5]] + D_800785CC[((unsigned char*)signal)[6]];
    return 1;
}

int SIGNAL_LogicSub(Instance* instance, void* signal) {
    D_800785CC[((unsigned char*)signal)[4]] = D_800785CC[((unsigned char*)signal)[5]] - D_800785CC[((unsigned char*)signal)[6]];
    return 1;
}

int SIGNAL_Goto(Instance* instance, void* signal) {
    SIGNAL_HandleSignal(instance, ((int**)signal)[1], 0);
    return 0;
}

int SIGNAL_Label(Instance* instance, void* signal) {
    return 1;
}

int SIGNAL_End(Instance* instance, void* signal) {
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_GoSub);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_StopPlayerControl);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_StartPlayerControl);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004D5A4);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_SetPlayerControl);

int SIGNAL_Launch(Instance* instance, void* signal) {
    func_80027468();
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CostumeChange);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_GameValue);

typedef struct
{
    short a;
    short b;
    int c;
    int d;
} func_8004D83C_t_1;

extern func_8004D83C_t_1 D_800EB9B0[];

int SIGNAL_SetZSignal(Instance* instance, void* signal) {
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

int SIGNAL_ResetZSignal(Instance* instance, void* signal) {
    int i = ((short*)signal)[2] * 3;

    D_800EB9B4[i] = 0;
    D_800EB9B8[i] = 0;

    return 1;
}

int SIGNAL_SoundEffect(Instance* instance, void* signal) {
    
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

int SIGNAL_MusicControl(Instance* instance, void* signal) {
    func_80033334(((int*)signal)[1]);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_SetMusicVariable);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_LevelChange);

int SIGNAL_VoiceControl(Instance* instance, void* signal) {
    return 1;
}

int SIGNAL_BankChange(Instance* instance, void* signal) {
    return 1;
}
int SIGNAL_GameLoadSave(Instance* instance, void* signal) {
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_HideObjectGroup);

int SIGNAL_UnhideObjectGroup(Instance* instance, void* signal) {
    int length;
    int index;
    int** ptr;

    length = ((int**)signal)[1][0];
    ptr = &(((int***)signal)[1][1]);
    
    for (index = 0; index < length; ++index) {
        ptr[index][7] = (ptr[index][7] & ~0x80);
    }
    return 1;
}


INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004DB04);

INCLUDE_ASM("asm/nonmatchings/_4a780", func_8004DD08);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_Shards);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_CameraSpline);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_ScreenWipe);

int SIGNAL_VoiceQueue(Instance* instance, void* signal) {
    func_80052944(((int*)signal)[1]);
    return 1;
}

int SIGNAL_VoiceUnQueue(Instance* instance, void* signal) {
    func_8005294C(((int*)signal)[1]);
    return 1;
}

int SIGNAL_VoiceRequest(Instance* instance, void* signal) {
    func_80052A7C(((int*)signal)[1]);
    return 1;
}

int SIGNAL_VoiceForce(Instance* instance, void* signal) {
    func_80052AA8(((int*)signal)[1]);
    return 1;
}

int SIGNAL_VoiceClearQueue(Instance* instance, void* signal) {
    func_80052954();
    return 1;
}

int SIGNAL_VoiceDisable(Instance* instance, void* signal) {
    func_80052F58();
    return 1;
}

int SIGNAL_VoiceReEnable(Instance* instance, void* signal) {
    func_80052F7C();
    return 1;
}

int SIGNAL_IntroActive(Instance* instance, void* signal) {
    if ((((int**)signal)[1] != 0) && (((int**)signal)[1][7] & 8)) {
        if (((int*)signal)[2] != NULL) {
            SIGNAL_HandleSignal(instance, ((int**)signal)[2], 0);
            return 0;
        }
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_IntroFX);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_GotoPos);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_BlendStart);

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_MiscValue);

int SIGNAL_SetTimes(Instance* instance, void* signal) {
    ((int**)signal)[1][1] = ((int*)signal)[2]; 
    return 1;
}             

int SIGNAL_ScreenWipeColor(Instance* instance, void* signal) {
    func_80039688(((char*)signal)[4], ((char*)signal)[5], ((char*)signal)[6], gameTracker8);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_Relocate);

int SIGNAL_LogicTrueElse(Instance* instance, void* signal) {
    if (D_800785CC[((unsigned char*)signal)[4]] != 0 && ((int**)signal)[2] != 0) {
        SIGNAL_HandleSignal(instance, ((int**)signal)[2], 0);
        return 0;
    }
    return 1;
}

int SIGNAL_LogicFalseElse(Instance* instance, void* signal) {
    if (D_800785CC[((unsigned char*)signal)[4]] == 0 && ((int**)signal)[2] != 0) {
        SIGNAL_HandleSignal(instance, ((int**)signal)[2], 0);
        return 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_Print);

extern short D_8007865C;

int SIGNAL_TagTimer(Instance* instance, void* signal) {
    D_8007865C = 1;
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_SetNoRemove);

int SIGNAL_ResetNoRemove(Instance* instance, void* signal) {
    
    int* a2ptr = ((int**)signal)[1];
    if (a2ptr) {
        
        int* ptr = (int*)a2ptr[9];
        a2ptr[7] &= ~0x2000;
        
        if (ptr) {
            ptr[4] &= ~0x400;
        }
        
    }
    return 1;
}

int SIGNAL_8004E95C(Instance* instance, void* signal) {
    int temp_v1 = ((int*)signal)[1];
    
    if ((temp_v1 != 0) && (temp_v1 == 1)) {
        func_8015E228();
    } else {
        func_8002AE40();
    }
    return 1;
}

extern int D_8015EE24;

int SIGNAL_8004E9A8(Instance* instance, void* signal) {
    D_8015EE24 = ((int*)signal)[1];
    return 1;
}

extern int D_8015EE28;

int SIGNAL_8004E9BC(Instance* instance, void* signal) {
    D_8015EE28 = ((int*)signal)[1];
    return 1;
}

extern int D_8015EE2C;

int SIGNAL_8004E9D0(Instance* instance, void* signal) {
    D_8015EE2C = ((int*)signal)[1];
    return 1;
}

extern int D_8015EE30;

int SIGNAL_8004E9E4(Instance* instance, void* signal) {
    D_8015EE30 = ((int*)signal)[1];
    return 1;
}

int SIGNAL_8004E9F8(Instance* instance, void* signal) {
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

INCLUDE_ASM("asm/nonmatchings/_4a780", SIGNAL_8004EA2C);

void COLLIDE_HandleSignal(Instance* instance, void* signal, int numSignals, int* arg3) {
    int s4, s3;
    int v0;
    int s2 = 0;

    if (arg3 == (void*)1 || arg3 == 0)
        s2 = 1;
    else if (arg3[4] >= 2U)
        return;

    if (numSignals == 0)
        return;
    
    s4 = 0x80000000;
    s3 = 0x7FFFFFFF;
    
    while (!((D_80078664[((int*)signal)[0]].onlyPlayer == 0 || instance == PlayerInstance || s2 != 0)
        && ((gameTracker8->gameFlags & 0x40) == 0 || ((((int*)signal)[0] & s4) == 0))
        && (D_80078664[(((int*)signal)[0] & s3)].func(instance, signal) == 0)))
    {
        v0 = (D_80078664[((int*)signal)[0]].length + 1);
        ((int*)signal) += v0;
    }

}

void SIGNAL_HandleSignal(Instance* instance, void* signal, int* arg2) {
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
