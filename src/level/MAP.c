#include "common.h"

#include "level/MAP.h"

#include <PR/gbi.h>
#include <PR/mbi.h>
#include <compiler/gcc/string.h>
#include <ultra64.h>

#include "types/TVTextData.h"
#include "types/G2String.h"
#include "types/Vector.h"

extern char D_8014F34C;
extern void map_lvltv_OnCollide();
extern char D_80161394_C1DC4[];
extern char* D_80161684_C20B4;
extern void func_8015D5E4_BE014();
extern int D_800785CC[];
extern unsigned short D_800E5DB2;
extern int D_80161680_C20B0;

extern Gfx D_8006D578[];
extern Gfx* D_80157050;
extern char D_800E5D00[];

extern G2String D_801612B4_C1CE4;
extern G2String D_80161324_C1D54;
extern int D_800E5CD8;
extern unsigned char D_8006FCD2;
extern char D_80161314_C1D44[];

extern int D_8006FA54;
extern u8 D_80078174[];
extern int D_800B83C8;
extern char D_800E5B98;
extern int D_800E5CD4;
extern char D_800E8EB4;
extern int D_800E97CC;
extern char D_8014F354;
extern OSMesgQueue gGlobalMessageBuffer;
extern char D_80157030;
extern int D_80157034;
extern char D_8006FC69;
extern int D_80078600;
extern int D_80078640;
extern char D_801612C0_C1CF0[];
extern char D_80078184[];
extern char D_80078188[];
extern char D_80078190[];
extern char D_800781B8[];
extern char D_80078170;
extern char D_8006CF20;
extern char D_801611C0_C1BF0[];
extern char D_80161208_C1C38[];
extern char D_801611CC_C1BFC[];
extern GameTracker* gameTracker;
extern char D_801611F8_C1C28[];
extern char D_801614D0_C1F00[];
extern char D_801611D8_C1C08[];
extern int D_80078198;
extern int D_801613E0_C1E10;
extern int D_80154834;
extern char D_8016134_C1DC4[];
extern char D_801611E4_C1C14[];
extern char D_801614F0_C1F20[];
extern int D_80156BE4;
extern char D_80078171;
extern int D_801574FC;
extern int D_80156BDC;
extern char D_801539C4;
extern char D_800E9732;
extern char D_80078150[];
extern int D_80161674_C20A4;
extern int D_8014F358;
extern char D_8006CF58;
extern int D_80161670_C20A0;
extern char D_801611B4_C1BE4[];

// Magic string that signifies this is a Gex 2 save file, and that we're about to read the save's name
#define SAVEFILE_MAGIC_STRING "\x20\x1E\x31\x3E"

typedef struct
{
    char MAGIC[4]; // == SAVEFILE_MAGIC_STRING
    char filename[12];
} SAVEFILENAME_t;

typedef struct
{
    SAVEFILENAME_t filename;
    char GAMECODE[4];
    u8 data[12];
} SAVEFILE_t; // How it should be structured in memory

typedef struct
{
    SAVEFILENAME_t filename;
    char GAMECODE[4];
    u8 data[12];
} SAVEFILE_ALT_t; // How it is being access for some reason

extern SAVEFILE_ALT_t D_800E5DDE[];

extern int D_80078594[];

void map_remrlow_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void map_remrlow_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    instance->_D0[0]++;
}

void map_remrlow_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void map_dish_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void map_dish_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    if (instance->object->_1C != 0) {
        instance->rotation.z += (0x1000 / *instance->object->_1C);
    } else {
        instance->rotation.z += 0x3C;
    }
    
    instance->rotation.z &= 0xFFF;
}

void map_dish_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void map_temptv_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    if (!instance->intro->_04)
        return;

    if (((Instance***)instance->intro->_04)[1][0x24/4] == instance)
    {
        instance->_F4[0] = 1;
    }
    else
    {
        instance->_F4[2] = 1;
    }

    instance->flags |= 0x480;
}

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161130_C1B60);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161194_C1BC4);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801611A4_C1BD4);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801611B4_C1BE4);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801611C0_C1BF0);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801611CC_C1BFC);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801611D8_C1C08);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801611E4_C1C14);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801611F8_C1C28);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161208_C1C38);

void map_temptv_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int* arg2 = ((int*)gameTracker) + 0x18/4;
    if (instance->intro->_04 != 0) {
        instance->_56 = instance->_F4[2] * 2;
        
        if (!instance->_F4[0]) {
            instance->_56 |= 1;
        }
        
        if (!(((GameTracker*)gameTracker)->gameFlags & 1)) {
            if ((((int*)gameTracker)[0x1C/4] & 0x10) && (instance->_F4[0] == 1)) {
                func_800396E0("prehst", "prehst1", gameTracker);
            }
            else
            {
                if ((arg2[0] & 4) || (((int*)gameTracker)[0x4C/4] < -0x20)) {
                    if (instance->_F4[2] == 0) {
                        instance->_F4[0] = 1;
                    }
                    else
                    {
                        instance->_F4[0] = 0;
                    }
                }
                else if ((arg2[0] & 8) || (((int*)gameTracker)[0x4C/4] >= 0x21)) {
                    if (instance->_F4[2] == 1) {
                        instance->_F4[0] = instance->_F4[2];
                    }
                    else
                    {
                        instance->_F4[0] = 0;
                    }
                }
            }
        }
    }
}

void map_temptv_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void map_intro_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* temp_s1;
    int* temp_v0;
    int** temp_a1;
    int** temp_a2;
    short* temp_v0_2;

    if (instance->intro->_04 != 0) {
        temp_a1 = ((int***)instance->intro->_04)[1];
        temp_a2 = ((int***)instance->intro->_04)[2];
        instance->flags |= 0xC00;
        ((int**)gameTracker)[3][0x10/4] |= 0x400;
        ((int**)gameTracker)[3][0x10/4] |= 0x100;
        if ((temp_a1 != 0) && (temp_a2 != 0)) {
            temp_v0 = temp_a1[0x28/4];
            temp_s1 = temp_a2[0x28/4];
            temp_v0_2 = (short*)func_80051638(*temp_v0, temp_v0 + 4);
            if (temp_v0_2 != 0) {
                ((short**)gameTracker)[2][0] = temp_v0_2[0];
                ((short**)gameTracker)[2][1] = temp_v0_2[1];
                ((short**)gameTracker)[2][2] = temp_v0_2[2];
            }
            func_80003A68(((int*)gameTracker)[2], func_80051638(*temp_s1, temp_s1 + 4));
            func_80001408(((int*)gameTracker)[2], 8);
        }
        ((GameTracker*)gameTracker)->gameFlags |= 1;
    }
}

void map_intro_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int *v0, *v1;
    int *s1, *s2;
    int *s3;
    int *s4, *s5;
    s3 = (int*)instance->introData;

    
    if (instance->intro->_04 == 0)
        return;
    
    ((short*)PlayerInstance)[0x64/2] = -0x200;
    ((int**)gameTracker)[0xC/4][0x10/4] |= 0x100;
    v0 = (int*)instance->intro->_04;
    s4 = (int*)v0[0x4/4];
    s5 = (int*)v0[0x8/4];
    
    if (instance->_F4[1])
        return;
    
    s1 = (int*)s4[0x28/4];
    s2 = (int*)s5[0x28/4];
    v1 = (int*)func_80051734(s1[0], s1 + 0x10/4);
    
    if (v1 != 0)
    {
        if ((((int*)gameTracker)[0x40/4] & 0x8010) == 0)
        {
            ((GameTracker*)gameTracker)->gameFlags |= 1; // d0
            ((SVECTOR*)((int*)gameTracker)[0x8/4])->x = ((SVECTOR*)v1)->x;
            ((SVECTOR*)((int*)gameTracker)[0x8/4])->y = ((SVECTOR*)v1)->y;
            ((SVECTOR*)((int*)gameTracker)[0x8/4])->z = ((SVECTOR*)v1)->z;
            goto _1d8;
        } // 104
        else
        {
            v1 = (int*)func_800516E0(s1[0], s1 + 0x10/4);
            ((SVECTOR*)((int*)gameTracker)[0x8/4])->x = ((SVECTOR*)v1)->x;
            ((SVECTOR*)((int*)gameTracker)[0x8/4])->y = ((SVECTOR*)v1)->y;
            ((SVECTOR*)((int*)gameTracker)[0x8/4])->z = ((SVECTOR*)v1)->z;
            func_80003A68(((int*)gameTracker)[0x8/4], func_800516E0(s2[0], s2 + 0x10/4)); // 150
            func_80001408(((int*)gameTracker)[0x8/4], 8); // 170
        }
    } // 17c
    instance->_F4[1] = 1;
    ((int**)gameTracker)[0x4/4][0x74/4] &= -2;

    ((GameTracker*)gameTracker)->gameFlags &= -2;
    if (s3 != 0)
    {
        if (s3[0] & 1)
        {
            INSTANCE_KillInstance(instance);
        } // 1c8
    } // 1c8
    
    func_8001A94C(gameTracker); // 1c8
    return;

    _1d8:
    func_80003A68(((int*)gameTracker)[0x8/4], func_80051734(s2[0], s2 + 0x10/4));
    func_80001408(((int*)gameTracker)[0x8/4], 8);
    
}

void map_intro_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void map_angel_OnCreate(Instance* instance, GameTracker* gameTracker) {
    ((short*)&instance->_100)[1] = -0x1000;
    instance->flags |= 0xC00;
    if (instance->object->_1C != 0) {
        ((short*)&instance->_100)[1] = *instance->object->_1C;
    }
}

void map_angel_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int* temp_v0;
    short* temp_s2;
    short* temp_s3;

    temp_v0 = (int*)instance->intro->_20;
    temp_s3 = (short*)((int*)gameTracker)[3];
    temp_s2 = (short*)&instance->_F4[2];

    if (instance->_F4[0] == 1)
    {
        if ((temp_v0 != 0) && (*temp_v0 != 0)) {
            func_800257B4(((int*)gameTracker)[3]);
        }
        goto block_10;
    
    }
    else if (instance->_F4[0] == 0)
    {
        instance->position = *(SVECTOR*)&temp_s3[0x48/2];
        instance->_40[6] = (s16) ((u16) instance->_40[6] + 0x400);
        if ( temp_s3[0x4C/2] <= ((short*)&instance->_100)[1]) {
            func_8004A5B4(instance, 0x1000);
            instance->_F4[0] = 1;
            ((GameTracker*)gameTracker)->gameFlags |= 1;
            (*(short*)&instance->_104) = 0x5A;
            instance->_40[6] -= 0x400;
            instance->flags &= ~0x800;
        }
        goto block_10;
    }
    else if (instance->_F4[0] == 2)
    {
        
        if (((short*)&instance->_104)[1] <= 0) {
            ((short*)&instance->_104)[1] = 0x1E;
            instance->_F4[0] = 3;
            goto block_10;
        }
        goto block_11;

    }
    else
    {
block_10:
        if (temp_s2[5] > 0) {
block_11:
            temp_s2[5]--;
        }
    }
    
    if (temp_s2[4] > 0) {
        temp_s2[4]--;
        if ((temp_s2[4] << 0x10) <= 0) {
            ((GameTracker*)gameTracker)->gameFlags &= ~1;
            func_8001C978(temp_s3, ((int*)gameTracker)[1] + 0x2C, gameTracker);
            instance->_F4[0] = 0;
            instance->flags |= 0x800;
            func_8004A54C(instance, 0x1000);
        }
    }
}

void map_angel_OnCollide(Instance* instance, GameTracker* gameTracker) {
    if (instance->_F4[0] == 1) {
        instance->_F4[0] = 2;
        ((short*)&instance->_104)[1] = 0x1E;
    }
}

void map_lktorch_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    *((short*)&instance->_F4[2]) = 1;
    *(((short*)&instance->_F4[2]) + 1) = 1;
    instance->flags |= 0x400;
}

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161230_C1C60);

INCLUDE_ASM("asm/nonmatchings/level/MAP", map_lktorch_OnUpdate);

void map_lktorch_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void map_lkdoor_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    *(((short*)&instance->_F4[2]) + 1) = 1;
    instance->flags |= 0x400;
    *((short*)&instance->_100) = instance->rotation.z;
}

void map_lkdoor_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int var_s2;
    int var_v1;
    short* temp_s1;
    short* temp_s3;
    int* temp_v0;

    var_s2 = 1;
    temp_s1 = (short*)instance->introData;
    temp_s3 = &instance->_F0[6];
    switch (temp_s3[0]) {
    case 0:
        osSyncPrintf("LKDOOR_CLOSED\n");
        if (temp_s3[1] != 0) {
            if (temp_s1 != 0) {
                for (var_v1 = 0; var_v1 < temp_s1[0x6/2]; var_v1 += 1) {
                    temp_v0 = ((int***)temp_s1 + var_v1)[0x8/4][0x24/4];
                    if (temp_v0 != 0) {
                        ((short*)temp_v0)[0xFC/2] = 1;
                        ((short*)temp_v0)[0xFE/2] = 1;
                    }
                }
                temp_s3[1] = 0;
            }
        } 
        
        if (temp_s1 != 0) {
            for (var_v1 = 0; var_v1 < temp_s1[0x6/2]; ++var_v1)
            {
                temp_v0 = ((int***)temp_s1 + var_v1)[0x8/4][0x24/4];
                if ((temp_v0 == 0) || (((short*)temp_v0)[0xFC/2] != 0)) {
                    var_s2 = 0;
                }
            }
        }
        
        if ((var_s2 != 0) && (temp_s1 != 0)) {
            if (((int*)temp_s1)[0] != 0) {
                SIGNAL_HandleSignal(instance, ((int*)temp_s1)[0] + 4, 0);
            }
            temp_s3[0] = 4;
            temp_s3[1] = 1;
        }
        
        break;
    case 4:
        if (temp_s3[1] != 0) {
            ((short*)&instance->_100)[1] = 0x2DU;
            temp_s3[1] = 0;
        }
        osSyncPrintf("LKDOOR_PREOPEN\n");
        if ((--((short*)&instance->_100)[1] << 0x10) < 0) {
            temp_s3[0] = 3;
            func_8004AAA8(instance, 0x49, 0);
        }
        break;
    case 3:
        if (temp_s1[0x4/2] == 0) {
            instance->rotation.z -= 0x20;
            if (instance->rotation.z == (((short*)&instance->_100)[0] - 0x400)) {
                temp_s3[0] = 1;
                temp_s3[1] = 1;
            }
        } else {
            instance->rotation.z += 0x20;
            if (instance->rotation.z == (((short*)&instance->_100)[0] + 0x400)) {
                temp_s3[0] = 1;
                temp_s3[1] = 1;
            }
        }
        
        osSyncPrintf("LKDOOR_OPENING\n");
        return;
    case 1:
        if (temp_s3[1] != 0) {
            temp_s3[1] = 0;
        }
        break;
    }
}

void map_lkdoor_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void map_qmark_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_104 = 0;
    instance->_F4[2] = 0x40;
    instance->_100 = 0;
}

void map_qmark_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int* temp_s0;
    short* temp_t0;
    
    temp_t0 = (short*)instance->introData;
    temp_s0 = &instance->_F4[2];
    if (((*(int*)&instance->_10C) != 0) && !(gameTracker->gameFlags & 0x2000)) {
        func_8003F6CC(temp_t0[0], temp_t0[1], temp_t0[2], temp_t0[3], temp_t0[5], temp_t0 + 6);
    }
    switch (temp_s0[2])
    {
        case 0: break;
        
        case 1:
        if (MATH3D_FastSqrt(SVECTOR_DistanceSquared(&instance->position, &PlayerInstance->position), 0) > 1000
            || !temp_s0[5])
        {
            temp_s0[2] = 2;
            temp_s0[1] = -6;
        }
        else
            temp_s0[5]--;
            
        break;
        
        case 2:
        if (temp_s0[0] < 0x41) {
            temp_s0[2] = 0;
            temp_s0[0] = 0x40;
            temp_s0[1]= 0;
            temp_s0[4] = 0;
        }
            
        break;
    }
    temp_s0[0] += temp_s0[1];
    instance->rotation.z = ((instance->rotation.z + temp_s0[0]) & 0xFFF);
}

void map_qmark_OnCollide(Instance* instance, GameTracker* gameTracker) {
    short* temp_s1;

    temp_s1 = (short*)instance->introData;
    if (func_80027500(instance->_70[2]) != 0) {
        instance->_104 = 1;
        instance->_F4[2] = 0x12C;
        *((int*)&instance->_110) = temp_s1[4];
        *((int*)&instance->_10C) = 1;
    }
}

void func_8015A854_BB284(char* arg0, short arg1) {
    char buffer[40];
    int var_a0;
    char* bufferPtr;
    char* var_s1;
    int temp_a0;
    char last_char;

    strcpy(buffer, arg0);
    var_s1 = buffer;
    do {
        bufferPtr = var_s1;
        while(*bufferPtr != '\0' && *bufferPtr != '\n') ++bufferPtr;
        
        last_char = *bufferPtr;
        *bufferPtr = 0;
        
        temp_a0 = (unsigned int)(0x140 - ((strlen(var_s1) - 1) * 0x14)) >> 1U;
        
        if (temp_a0 < 0x28) {
            temp_a0 = 0x28;
        }
        
        func_80037B00((temp_a0 << 0x10) >> 0x10, arg1);
        Print3DTextf("#2%s", var_s1);
        var_s1 = bufferPtr + 1;
        arg1 += 0x1E;
    } while (last_char != 0);
}

void map_speaker_OnCreate(Instance* instance, GameTracker* gameTracker) {
    s32 var_a1;
    short* temp_s0;
    int* temp_s0_2;
    short* temp_s1;

    temp_s0 = (short*)instance->introData;
    temp_s1 = (short*)&instance->_F4[2];
    if (temp_s0 != 0) {
        instance->_C0[1] = (temp_s0[2] * 2);
    }
    instance->flags |= 0x100000;
    func_80048DE4(instance, temp_s1, &instance->_100, &instance->_104);
    if (temp_s0 != 0) {
        switch (temp_s0[2])
        {
        case 0:
            (*(short*)&instance->_10A) = ((int*)gameTracker8)[0x4C58/4];
            instance->_F4[0] = ((char*)gameTracker8)[0x4C60];
            break;
        case 1:
            (*(short*)&instance->_10A) = ((int*)gameTracker8)[0x4C54/4];
            instance->_F4[0] = ((char*)gameTracker8)[0x4C61];
            *(short*)&instance->_10E = 0x5A;
            *(short*)&instance->_110 = func_8003333C();
            break;
        case 2:
            (*(short*)&instance->_10A) = ((int*)gameTracker8)[0x4C5C/4];
            var_a1 = 0;
            if (((int*)gameTracker8)[0x90/4] & 0x80000) {
                var_a1 = ((char*)gameTracker8)[0x4C62] != 0;
            }
            instance->_F4[0] = var_a1;
            if (var_a1 != 0) {
                func_80052F7C(gameTracker8, var_a1);
            }
            break;
        }
    }
    temp_s0_2 = ((int**)(*(((s32) ((instance->_C0[1] | 1) << 0x10) >> 0x10) + (int*)instance->object->_0C)))[0x2C/4];
    func_80051360(temp_s0_2[2], &temp_s1[4], ((temp_s1[0xE/2] << 8) / 127) & 0xFFFF);
    func_80048A4C(instance, temp_s0_2, 0, 0, &temp_s1[4], 0, 1);
}

INCLUDE_ASM("asm/nonmatchings/level/MAP", map_speaker_OnUpdate);

void map_start_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* temp_a1;
    int* temp_a2;
    short* temp_s4;
    int* temp_v1;
    int* temp_v1_2;
    int* temp_v1_3;
    char* ptr;

    temp_a1 = (int*)instance->introData;
    temp_s4 = (short*)PlayerInstance->data;
    ptr = (char*)&instance->_F4[2];
    if (!(instance->flags & 0x20000)) {
        temp_a2 = ((int***)gameTracker)[1][0x90/4];
        
        if (G2String_Compare_NEQ(D_801612C0_C1CF0, temp_a2))
        {
            SIGNAL_HandleSignal(PlayerInstance, temp_a1[0] + 4, 0);
        } else {
            SIGNAL_HandleSignal(PlayerInstance, temp_a1[1] + 4, 0);
        }
        
        ptr[0x24] = 1;
        ((char*)gameTracker8)[0x4C60] = ((char*)gameTracker8)[0x4C61] = 1;
        ((int*)gameTracker8)[0x4C58/4] = 0x7A;
        func_80033334(0x78);
        ((int*)gameTracker8)[0x4C5C/4] = 0x7A;
        ((char*)gameTracker8)[0x4C62] = 1;
        instance->flags |= 0x10C00;
        temp_v1 = ((int**)gameTracker)[0xC/4];
        temp_v1[0x10/4] = (temp_v1[0x10/4] | 0x800);
        temp_v1_2 = ((int**)gameTracker)[0xC/4];
        temp_v1_2[0x10/4] = (temp_v1_2[0x10/4] | 0x400);
        temp_s4[0xDC/2] = 0;
        temp_v1_3 = ((int**)gameTracker)[0xC/4];
        temp_v1_3[0xFC/4] = (temp_v1_3[0xFC/4] | 0x1000);
        temp_s4[0x12C/2] = 0;
        ((char*)PlayerInstance)[0x4E] = 0;
        PlayerInstance->_F4[1] = 1;
        PlayerInstance->_F4[0] = 0;
        ((int**)gameTracker)[0xC/4][0xF4/4] = 5;
        func_80052F58();
        ((int*)instance->_D0)[0] = 0x258;
        ((int*)instance->_D0)[2] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MAP", map_start_OnUpdate);

void map_bobbox_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->flags |= 0xC00;
}

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612B4_C1CE4);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612B8_C1CE8);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612C0_C1CF0);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612C4_C1CF4);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612CC_C1CFC);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612D4_C1D04);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612DC_C1D0C);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612E4_C1D14);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612EC_C1D1C);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801612F8_C1D28);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161300_C1D30);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161308_C1D38);

void map_bobbox_OnUpdate(Instance* arg1, GameTracker* gameTracker) {
    short var_a2;
    short var_s0;
    int var_a1;
    int var_s2;
    short* var_a1_2;
    int* temp_a0;

    var_s2 = 0;
    temp_a0 = ((int**)gameTracker)[0x8/4];
    
    var_a1 =     temp_a0[0x14C/4] == 5
              && temp_a0[0x480/4] != 0
              && temp_a0[0x484/4] != 0;
    
    if (var_a1 != 0) {
        temp_a0 = (int*)*((int***)gameTracker)[0x8/4][0x480/4];
        
        
        var_s0 = var_a2 = 0;
        if (temp_a0 != 0) {
            var_a1_2 = (short*)temp_a0[0x0];
            for(;var_a2 < ((short*)temp_a0)[0x4/2];)
            {
                var_a2++;
                var_s0 += *var_a1_2;
                var_a1_2 += 0x20/2;
            }
        }
        
        if ((func_800512BC(temp_a0, ((int***)gameTracker)[0x8/4][0x480/4] + 0x10/4) & 0xFFFF) >= (var_s0 - 1))
        {
            var_s2 = 1;
        }
    } else {
        var_s2 = 1;
    }
    
    if ((int)((int**)gameTracker)[0x44/4] & 0x4000) {
        var_s2 = 1;
    }
    
    if (var_s2 != 0) {
        ((int**)gameTracker)[0xC/4][0xF4/4] = 0;
        ((int**)gameTracker)[0xC/4][0xFC/4] &= ~0x1000;
        func_800396E0("map", D_80161314_C1D44, gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MAP", func_8015B96C_BC39C);

void func_8015BED0_BC900(Instance* instance, GameTracker* gameTracker) {
    int temp_t0;
    int i;
    int*** temp_a0;
    int** var_a2;

    i = 0;
    temp_t0 = *(int*)instance->intro->_04;
    var_a2 = (int**)instance->intro->_04 + 1;
    
    for(i = 0; i < temp_t0; ++i)
    {
        var_a2[i][0x1C/4] &= ~0x80;
        temp_a0 = (int***)var_a2[i][0x24/4];
        if (temp_a0 != 0) {
            ((int*)temp_a0)[0x10/4] &= ~0x400;
            if (G2String_Compare_EQ(temp_a0[0x18/4][0x20/4], &D_801612B4_C1CE4)) {
                ((int*)temp_a0)[0xF4/4] = 3;
            }
            else if (G2String_Compare_EQ(temp_a0[0x18/4][0x20/4], &D_80161324_C1D54)) {
                ((int*)temp_a0)[0xF4/4] = 3;
                ((char*)temp_a0)[0x10E] = 1;
            }
        }
    }
}

void func_8015BFE0_BCA10(Instance* instance, GameTracker* gameTracker) {
    int count;
    int var_a2;
    int i;
    int** temp_v1;
    int* temp_v0;

    temp_v1 = (int**)instance->intro->_04;
    count = (int)*temp_v1++;
    var_a2 = 1;
    
    for(i = 0; i < count; ++i)
    {
        temp_v0 = (int*)(temp_v1[i])[0x24/4];
        if ((temp_v0 != 0) && ((temp_v0[0x10/4] & 0xA00) == 0x200)) {
            var_a2 = 0;
        }
    }
    
    if (var_a2 == 0 && (((int*)gameTracker)[0x11] & 0x4000)) {
        var_a2 = 1;
    }
    
    if (var_a2 != 0) {
        for(i = 0; i < count; ++i)
        {
            if ((temp_v1[i])[0x24/4] != 0) {
                func_8002E350((temp_v1[i])[0x24/4]);
            }
            temp_v1[i][0x1C/4] |= 0x80;
            temp_v1[i][0x1C/4] &= ~8;
        }
    }
}

void func_8015C110_BCB40(Instance* instance, short** arg1) {
    short* temp_a3;
    short* temp_t0;

    temp_a3 = (short*)instance->introData;
    temp_t0 = (short*)PlayerInstance->data;
    if ((temp_a3 != 0) && ((((int*)temp_a3)[0x10/4] != 0) || (temp_a3[0x14/2] != 0))) {
        
        PlayerInstance->oldPos
          = (PlayerInstance->position)
              = *(SVECTOR*)&temp_a3[0x10/2];
        
        temp_t0[0x82/2]
            = ((short*)PlayerInstance)[0x64/2]
            = temp_a3[0x18/2];
        
        if (((short*)PlayerInstance)[0x4C/2] < temp_a3[0x14/2]) {
            arg1[3][0xC0/2]
                = ((short*)PlayerInstance)[0x54/2]
                = ((short*)PlayerInstance)[0x4C/2]
                = temp_a3[0x14/2];
            temp_t0[0x8A/2] |= 1;
        }
    }
}

void map_tvmenu_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int temp_s2;
    int var_s1;
    int** var_s0;

    temp_s2 = func_8004A344();
    instance->flags |= 0xC00;
    
    if (instance->flags & 0x20000) {
        var_s0 = 1 + (int**)instance->intro->_04;
        for(var_s1 = 0; var_s1 < temp_s2; var_s1++)
        {
            if (var_s0[var_s1][9]) {
                func_8002E350(var_s0[var_s1][9]);
            }
            var_s0[var_s1][7] |= 0x80;
            var_s0[var_s1][7] &= ~8;
        }
    } else {
        ((char**)gameTracker)[3][0x4E] = 0;
        instance->flags |= 0x10000;
    }
}

INCLUDE_ASM("asm/nonmatchings/level/MAP", map_tvmenu_OnUpdate);

int func_8015C63C_BD06C(int arg0) {
    int temp_v0;
    int i;
    int var_s1;
    G2String* temp_a0;
    int** temp_v0_2;
    int* v;
    
    temp_v0 = func_8004A344(arg0);
    var_s1 = -1;
    
    for(i = 0; i < temp_v0; i++)
    {
        if (var_s1 != -1) break;
        if (temp_v0_2 = (int**)func_8004A368(arg0, i)) {
            if (G2String_Compare_EQ(temp_v0_2[0x18/4][0x20/4], &D_801612B4_C1CE4)
                && (((char*)temp_v0_2)[0x10B]) == 1) {
                var_s1 = i;
            }
        }

    }
    return var_s1;
}

void map_tvbutn_OnCreate(Instance* instance, GameTracker* gameTracker) {
    char temp_v0;
    int* temp_s1;
    char* s2;

    temp_s1 = (int*)instance->introData;
    instance->flags |= 0x80;
    s2 = (u8*)(instance->_F0 + 6);
    func_8004A5B4(instance, 0x4000);
    instance->_10D = 5U;
    instance->_10C = 5U;
    if (temp_s1 != 0) {
        instance->_C0[1] = (temp_s1[1] * 2);
    }
    instance->_10E = 1;

    if (temp_s1[1] == 0)
    {
        instance->_10F = 1U;
        instance->_110 = 4U;
        instance->_111 = 9;
        instance->_112 = 8;
    }
    else if (temp_s1[1] == 1)
    {
        temp_v0 = ((char*)temp_s1)[8];
        instance->_10D = temp_v0;
        instance->_10C = temp_v0;
        instance->_110 = temp_v0;
        instance->_10F = temp_v0;
    }
    else if (temp_s1[1] == 2)
    {
        instance->_10F = 0x11U;
        instance->_110 = 0x14U;
        instance->_111 = 0xF;
        instance->_112 = 0x10;
    }
    else
    {
        instance->_10F = 0U;
        instance->_110 = 0U;
        instance->_111 = 0;
        instance->_112 = 0;
    }
    instance->_56 = s2[0x13];
}

void map_tvbutn_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    s16 sp10[2];
    int temp_a1;
    int temp_a0;
    int var_a0;
    int var_v0;
    int* temp_s0;
    short* temp_s2;
    int* temp_v0;
    char* temp_v0_5;
    short* temp_v1;
    int* var_s4;
    int* var_s5;

    var_s4 = NULL;
    temp_v0 = (int*)instance->_F4[2];
    temp_s0 = (int*)instance->introData;
    temp_s2 = &instance->_F0[6];
    if (temp_v0 != NULL) {
        var_s4 = &temp_v0[0xFC/4];
        var_s5 = (int*)temp_v0[0x24/4];
    }
    if (instance->_F4[0] != 0) {
        func_8004A54C(instance, 0x5000);
        if (instance->_56 < instance->_10C) {
            instance->_56 = instance->_10C;
        }
        if (instance->_F4[0] == 3) {
            func_8015BFE0_BCA10(instance, gameTracker);
            return;
        }
        if (instance->_F4[0] == 2) {
            temp_a0 = ((instance->_C0[1] ^ 1) & 1);
            if (instance->_10B == 1) {
                if (temp_a0 == instance->_10B) {
                    goto block_12;
                }
            } else if (temp_a0 == 0) {
block_12:
                instance->_C0[1] = (u16) (instance->_C0[1] ^ 1);
            }
        }
        if (instance->_F4[0] == 1) {
            if (instance->_56 >= ((char*)temp_s2)[0x14]) {
                instance->_56 = ((char*)temp_s2)[0x10];
                instance->_F4[0] = 2;
            } else {
                instance->_56++;
            }
        } else if (instance->_F4[0] == 2) {
            if ((temp_s0 != NULL) && (((char*)temp_s0)[0x8] >= 0x62) && (instance->flags & 0x200)) {
                func_8003EA60(gameTracker, instance, 0, &sp10);
                func_80037B24(sp10[0], sp10[1]);
            }
            
            if (instance->_56 >= ((char*)temp_s2)[0x11]) {
                instance->_56 = ((char*)temp_s2)[0x10];
            } else {
                instance->_56++;
            }
            if ((((char*)temp_s2)[0xF] == 1) && (((short*)var_s4)[0x6/2] != 0)) {
                if (((int*)gameTracker8)[0xE0/4] & 8) {
                    instance->_C0[1] = (instance->_C0[1] ^ 1);
                }
                if (instance->_C0[1] & 1) {
                    ((char*)temp_s2)[0x17]++;
                }
                if ((((char*)temp_s2)[0x17] >= 8) && ((((char*)temp_s2)[0x17] = 0U, (var_s5 == NULL)) || (((short*)var_s5)[0x16/2] == 0))) {
                    ((char*)temp_s2)[0x12] = 1;
                }
                
                if ((((int*)gameTracker)[0x28/4] != 0) || (((int*)gameTracker)[0x24/4] != 0)) {
                    
                    if (abs(((int*)gameTracker)[0x28/4]) >= abs(((int*)gameTracker)[0x24/4])) {
                        var_v0 = ((int*)gameTracker)[0x28/4] < 1;
                    } else {
                        var_v0 = 3;
                        if ( ((int*)gameTracker)[0x24/4] > 0) {
                            var_v0 = 2;
                        }
                    }
                    
                    if (var_v0 != -1) {
                        temp_a1 = ((var_v0) + temp_s2)[0x4/2];
                        if ((temp_a1 != -1) && (((char*)temp_s2)[0x12] != 0) && (((char**)temp_s2)[0][0x10F] != 0)) {
                            temp_v0_5 = (char*)func_8004A368(instance, temp_a1);
                            if (temp_v0_5 != NULL) {
                                func_80050980(0x81);
                                ((int*)temp_v0_5)[0xF4/4] = 1;
                                ((short*)temp_v0_5)[0x56/2] = 0;
                                temp_v0_5[0x10B] = 1;
                                temp_v0_5[0x10E] = 0;
                                ((char*)temp_s2)[0xF] = 0;
                                
                                if (temp_v0_5[0x110] != 0) {
                                    ((short*)temp_v0_5)[0x56/2] = temp_v0_5[0x110];
                                }
                            }
                        }
                    }
                } else {
                    var_a0 = 1;
                    if (instance->_C0[1] & 1) {
                        ((char*)temp_s2)[0x12] = 1;
                    }
                    temp_v1 = ((short**)temp_s2)[0];
                    if ((temp_v1 != NULL) && ((temp_v1[0x102/2] == 0) || (((char*)temp_v1)[0x10F] == 0))) {
                        var_a0 = 0;
                    }
                    if ((var_a0 != 0) && (((int*)gameTracker)[0x44/4] & 0x80)) {
                        if ( ((char*)temp_s2)[0xE] == 1) {
                            ((char*)temp_s2)[0xE] = 0;
                        } else if (((char*)temp_s2)[0xE] == 0) {
                            ((char*)temp_s2)[0xE] = 1;
                        }
                        instance->_56 = ((char*)temp_s2)[0x10];
                        if (temp_s0 != NULL) {
                            if (temp_s0[0x0/4] != 0) {
                                SIGNAL_HandleSignal(PlayerInstance, temp_s0[0x0/4] + 4, 0);
                                if (func_80033268(0x81) == 0) {
                                    func_80050980(0x81);
                                }
                            }
                        }
                        temp_v1 = ((short**)temp_s2)[0];
                        if (temp_v1 != NULL) {
                            temp_v1[0xFE/2] = 1;
                            if ((temp_s0 != NULL) && (temp_s0[0] != 0)) {
                                temp_v1[0x102/2] = 0;
                            }
                        }
                    }
                }
            }
        }
        if (instance->intro->flags & 0x80) {
            func_8015BED0_BC900(instance, gameTracker);
        }
    }
}

void map_tvbutn_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

void map_loadtv_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void map_loadtv_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    int* a1;
    a1 = ((int*)instance->introData);
    if ((((int*)gameTracker)[0x44/4] & 0x10) == 0)
        return;
    
    if (a1[1])
    {
        SIGNAL_HandleSignal(PlayerInstance, 4 + a1[1], 0);
    }
}

void map_ctrlbutn_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int temp_a1;
    SVECTOR* temp_v0;

    ((short*)&instance->_100)[1] = 2;
    instance->_F0[6] = 0x64;
    temp_a1 = (int)instance->introData;
    instance->flags |= 0x800;
    if (temp_a1 != 0) {
        temp_v0 = (SVECTOR*)((((short*)&instance->_100)[1] * sizeof(SVECTOR)) + temp_a1 + 4);
        PlayerInstance->oldPos
            = PlayerInstance->position
            = *(SVECTOR*)temp_v0;
    }
}

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161314_C1D44);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_8016131C_C1D4C);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161324_C1D54);

INCLUDE_ASM("asm/nonmatchings/level/MAP", map_ctrlbutn_OnUpdate);

void map_mapgate_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    instance->_100 = 0xC8;
    if (D_800785CC[((int*)instance->introData)[0]] != 3)
        return;

    func_80048828(instance, -1, 0, 0, 0);
    instance->flags |= 0x100000;
}

void map_mapgate_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int v0;

    if (instance->_100 != 0) {
        instance->_100--;
    }

    v0 = *((int*)instance->introData);
    
    switch (D_800785CC[v0])
    {
        case 0:
            break;
        
        case 1:
        {
            instance->flags |= 0x02000000, D_800785CC[v0] = 2;
            break;
        }

        case 2:
        {
            instance->flags |= 0x02000000, D_800785CC[v0] = 3;
            break;
        }
        
    }
}

void map_mapgate_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int temp_v1;

    temp_v1 = *(int*)instance->introData;
    if (!D_800785CC[temp_v1] && !instance->_100) {
        func_80052C2C(TVTextInformation[0x1E].levelName[temp_v1-1]); // todo: definitely wrong
        instance->_100 = 0xC8;
    }
}

void func_8015D52C_BDF5C(Instance* instance, GameTracker* gameTracker) {
    char buffer[0x10];
    char* v1;
    
    instance->_56 = -1;
    instance->flags |= 0x80;
    
    sprintf(buffer, D_80161394_C1DC4, (short*)instance->introData + 2, ((short*)(instance->introData))[1]);
    
    instance->_F4[2] = GetLevelIndexFromId(buffer);
    
    v1 = ((char***) instance->object->_0C)[0][5];
    
    if (v1 != 0)
    {
        D_80161684_C20B4 = v1;
        ((int***)instance->object->_0C)[0][5] = 0;
    }
    
    instance->_B4 = func_8015D5E4_BE014;
}

void map_lvllabl_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void func_8015D5E4_BE014(int* arg0, Instance* instance) {
    int a1;
    int i;
    int* a3;
    char* a0;

    instance->_56 = -1;
    instance->flags |= 0x80;
    a3 = ((int***)instance->object->_0C)[0][0xF];
    for(i = 0; i < a3[0]; ++i)
    {
        a1 = D_800E5CD8 & 0x7F;
        a0 = (char*)a3[1 + i];
        a0[4] = a0[0x14] + a1;
        a0[6] = a0[0x16] + a1;
        a0[8] =  a0[0x18] + a1;
        *((int*)a0) = ((int*)(instance->_F4[2] * 4 + (int)a0))[0x1C/4];
    }
    
    ((char***)instance->object->_0C)[0][0x14/4] = D_80161684_C20B4;
    func_8003D698(instance, arg0, 0);
    ((int**)instance->object->_0C)[0][0x14/4] = 0;
}

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_8016136C_C1D9C);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161374_C1DA4);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161380_C1DB0);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161388_C1DB8);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_80161394_C1DC4);

INCLUDE_ASM("asm/nonmatchings/level/MAP", func_8015D6F0_BE120);

void func_8015D9E4_BE414(Instance* instance) {
    SVECTOR v = instance->position;

    func_80047E64(instance, -0x14);
    instance->_40[6] += 0x80;
    instance->_F4[2] = INSTANCE_BirthObject(instance, OBTABLE_FindObject("lvllabl_"));
    instance->position = v;
    instance->flags |= 0x10000;
    ((int*)instance->_F4[2])[0x10/4] |= 0x100000;
    ((int*)instance->_F4[2])[0x10/4] |= 0x400;
    (*(char**)&instance->_F0[6])[0x100] = instance->_112;
    func_8015D52C_BDF5C((Instance*)instance->_F4[2], gameTracker8);
}

void func_8015DAC8_BE4F8(Instance* instance) {
    instance->_100 = INSTANCE_BirthObject(instance, OBTABLE_FindObject("etvbutn_" /*etvbutn_*/));
    instance->flags |= 0x10000;
    ((int*)instance->_100)[0x10/4] |= 0x100000;
    ((int*)instance->_100)[0x10/4] |= 0x400;
    ((void**)instance->_100)[0xB0/4] = &map_lvltv_OnCollide;
}

void func_8015DB54_BE584(Instance* instance) {
    int var_s1;
    int** var_s0;

    var_s0 = (int**)instance->_D0;
    if (instance->_F4[2] != 0) {
        ((int*)instance->_F4[2])[0x10/4] &= ~0x400;
        INSTANCE_PlainDeath(instance->_F4[2], -1, 0, 0);
    }
    if (instance->_100 != 0) {
        ((int*)instance->_100)[0x10/4] &= ~0x400;
        func_8002E350(instance->_100);
    }
    
    for(var_s1 = 0; var_s1 < 3; var_s1++)
     {
        if (var_s0[var_s1] != 0) {
            var_s0[var_s1][0x10/4] &= ~0x400;
            func_8002E350(var_s0[var_s1]);
        }
        
    }
}

void map_lvltv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    char sp10[0x10];
    short temp_a2;
    int var_a0;
    int var_a1;
    int var_s3;
    short* temp_s1;
    u8* temp_s2;
    u8* ptr;

    char sp20[4] = {0x00, 0x03, 0x04, 0x00 };
    temp_s1 = (short*)instance->introData;
    temp_s2 = (u8*)instance->_D0;
    if (instance->flags & 0x20000) {
        func_8015DB54_BE584(instance); // shouldn't need a second argument?
        return;
    }
    sprintf(sp10, (char*)&D_80161394_C1DC4, (temp_s1 + 2), temp_s1[0x2/2]);
    
    instance->_112 = GetLevelIndexFromId(&sp10);
    if (instance->_112 < 0x15U) {
        var_s3 = GetRedRemotesForLevel(instance->_112);
    }
    instance->flags |= 0x80;
    if (instance->_112 >= 0x15) {
        instance->_113 = 0;
        instance->_F4[1] = 2;
        if ((D_80078594[instance->_112]) == 2) {
            instance->_113 = 1;
            instance->_F4[1] = 0;
            instance->_111 = instance->_110 = (temp_s1[0x0/4] * 9) + 7;
        } else {
            goto skip;
        }
    } else {
        instance->_F4[1] = 0;
        instance->_113 = 1;
        temp_a2 = temp_s1[0x0/4];
        var_a1 = 0;
        if (temp_a2 >= 0) {
            var_a0 = var_s3 - 1;
            instance->_56 = (sp20[var_s3]) + (temp_a2 * 9);
            if (var_a0 >= 0) {
                ptr = (u8*)gameTracker8;
                ptr = &ptr[instance->_112];
                while(var_a0 >= 0)
                {
                    if ((ptr[0x4C6E] >> var_a0) & 1) {
                        var_a1 += 1;
                    }
                    var_a0 -= 1;
                }
            }
            temp_s2[0x40] = instance->_56 = instance->_56 + var_a1;
            temp_s2[0x41] = instance->_56;
        } else {
            skip:
            *(u8*)&instance->_110 = 7U;
            instance->_111 = 0x2AU;
            instance->_56 = *(u8*)&instance->_110;
        }
    }
    if (instance->intro->flags & 0x80) {
        instance->flags |= 0x800;
    }
    else
    {
        if ((temp_s2)[0x42] < 0xEU) {
            func_8015D6F0_BE120(instance, var_s3);
        }
        if (((temp_s2)[0x42] >= 0x15U) && ((char*)temp_s2)[0x43] != 0)
        {
            func_8015D6F0_BE120(instance, var_s3);
        }
        if (((temp_s2)[0x42] - 0xEU) >= 7U) {
            func_8015D9E4_BE414(instance);
        }   
    }
}

void map_lvltv_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR sp10;
    int sp18;
    int sp1C;
    short* temp_s1;
    int* temp_a2;
    u8* temp_s2;
    int* temp_v0_3;

    instance->flags = (s32) (instance->flags & ~0x800);
    temp_s1 = (short*)instance->introData;
    temp_s2 = (u8*)&instance->_D0;
    if (instance->_113 != 0) {
        instance->_56 = ((*temp_s1 * 9) + 7);
        if ((instance->_112 >= 0x15U) && (instance->_D0[0] == 0)) {
            func_8015D6F0_BE120(instance, 1);
        }
        if (((int*)temp_s2)[0x30/4] == NULL) {
            func_8015DAC8_BE4F8(instance);
        }
    } else if (D_80078594[instance->_112] == 1) {
        if (instance->_115 == 0U) {
            instance->_115 = 0x69U;
        }
        if ((rand() % ((instance->_115 >> 3) + 1)) == 0) {
            instance->_111 = instance->_110 = (*temp_s1 * 9) + 7;
        } else {
            instance->_110 = 7;
            instance->_111 = 0x2A;
        }
        temp_s2[0x45] = temp_s2[0x45] - 1;
        if (!temp_s2[0x45]) {
            temp_s2[0x43] = 1;
            instance->_F4[1] = 0;
            D_80078594[temp_s2[0x42]] = 2;
            instance->_56 = ((*temp_s1 * 9) + 7);
        }
    }
    instance->_56 += 9;
    if (instance->_56 < temp_s2[0x40]) {
        instance->_56 = temp_s2[0x40];
    }
    if (instance->_56 > temp_s2[0x41]) {
        instance->_56 = temp_s2[0x40];
    }
    
    if ((temp_s2[0x42] - 0xE) < 7U) {
        if (instance->flags & 0x02000000) {
            temp_a2 = (int*)((int*)temp_s2)[0x30/4];
            if (temp_a2 != NULL) {
                (*(SVECTOR*)&temp_a2[0x48/4]) = instance->position;
            }
        } else if (((int*)temp_s2)[0x2C/4] == 0) {
            if (instance->intro->multiSpline != NULL) {
                temp_v0_3 = (int*)SCRIPT_GetMultiSpline(instance, &sp18, &sp1C);
                if (temp_v0_3[1] != 0) {
                    func_80051C64(temp_v0_3[1], func_800485F8(instance, temp_v0_3, sp18, sp1C), &sp10);
                    instance->intro->rotation.x += sp10.x;
                    instance->intro->rotation.y += sp10.y;
                    instance->intro->rotation.z += sp10.z;
                }
                instance->intro->position = instance->position;
                instance->intro->multiSpline = NULL;
                instance->flags &= ~1;
            }
            func_8015D6F0_BE120(instance, GetRedRemotesForLevel(temp_s2[0x42]));
            func_8015D9E4_BE414(instance);
            ((SVECTOR**)temp_s2)[0x30/4][0x48/6] = instance->position;
            D_80078594[temp_s2[0x42]] = 2;
        }
    }
}

void func_8015E274_BECA4(Instance* instance) {
    SVECTOR temp = instance->position;

    func_80047E64(instance, 0x3E8);
    *(SVECTOR*)&(((short*)gameTracker8)[0x4C66/2]) = instance->position;
    ((short*)gameTracker8)[0x4C6A/2] -= 0x20;
    ((short*)gameTracker8)[0x4C6C/2] = instance->rotation.z & 0xFFF;
    ((short*)gameTracker8)[0x4C6C/2] = (((short*)gameTracker8)[0x4C6C/2] + instance->intro->rotation.z) & 0xfff;
    instance->position = temp;
}

void map_lvltv_OnCollide(Instance* instance, GameTracker* gameTracker) {
    char sp10[0x10];
    int* temp_a0;
    int* temp_s2;
    char* var_s0;

    temp_s2 = (int*)instance->introData;
    var_s0 = (char*)&instance->_D0;
    if (G2String_Compare_EQ(instance->object->name, "bobbox__")) {
        PlayerInstance->flags |= 0x800;
        while (D_80154834 == 3) {
            func_80052814();
        }
        PlayerInstance->flags &= ~0x800;
        sprintf(sp10, (char*)D_80161394_C1DC4, temp_s2 + 1, ((short*)temp_s2)[1]);
        func_800396E0(temp_s2 + 1, &sp10, gameTracker);
        return;
    }
    
    if (G2String_Compare_NEQ(instance->object->name, "lvltv___")) {
        if (G2String_Compare_EQ(instance->object->name, "etvbutn_")) {
            var_s0 = (char*)(instance->parent->_D0);
        }
        if ((temp_s2 != 0) && (var_s0[0x43] != 0)) {
            if ((((u8*)var_s0)[0x44] == 0) && ((u8*)PlayerInstance)[0x4E] == 0xB) {
                var_s0[0x44] = 1U;

                switch(((u8*)var_s0)[0x42])
                {
                    case 0x16:
                        func_80052C2C(0x48);
                    break;

                    case 0x15:
                        func_80052C2C(0x4A);
                    break;

                    case 0x17:
                        func_80052C2C(0x46);
                    break;

                    case 0x18:
                        func_80052C2C(0x4B);
                    break;
                }
            }
            
            ((int*)var_s0)[0x48/4] = ((short*)instance->parent)[0x56/2];
            if (func_8000C8E8(instance, gameTracker) != 0) {
                func_8015E274_BECA4(instance);
            }
            ((short*)instance->parent)[0x56/2] = ((int*)var_s0)[0x48/4];
        }
        else if (!(((int*)gameTracker8)[0x90/4] & 0x40000) && (var_s0[0x43] == 0)) {
            temp_a0 = (int*)instance->_70[2];
            if ((((short*)temp_a0)[0x6/2] == 1) && ((u8) ((u8*)temp_a0[0xC/4])[0x5] >= 7U)) {
                var_s0[0x43] = 1;
                var_s0[0x41] = var_s0[0x40] = (((short*)temp_s2)[0x0/2] * 9) + 7;
                ((int*)instance->parent)[0xF8/4] = 0;
            }
        }
    }
}

void func_8015E630_BF060(int arg0, int arg1, int arg2, int arg3) {
    int sp10[8];

    sp10[3] = arg0;
    sp10[4] = arg1;
    sp10[0] = 0x32;
    sp10[1] = arg2;
    sp10[2] = 0;
    sp10[6] = arg3;
    sp10[7] = arg3;
    func_80037B34(&sp10, 0);
}

void func_8015E674_BF0A4(char* arg0, int* arg1, GameTracker* gameTracker) {
    int temp_a0;
    int temp_s0;
    int var_a1;
    int var_s0;
    int var_s1;

    if (D_80078640 == 0) {
        GetRemoteCount(arg0 + 8);
        var_s0 = func_8001A1D8(arg0 + 8) & ~((int*)gameTracker)[0x4C9C/4];
        if (D_8006FCD2 != 0) {
            var_s0 &= ~0x2000;
        }
        if (var_s0 != 0) {
            if (*arg0 != 6) {
                SIGNAL_HandleSignal(((int*)gameTracker)[3], arg1[2] + 4, 0);
            }
            *arg0 = 6;
            var_s1 = 0;
            
countbits:
            if (!(var_s0 & 1)) {
                var_s1 += 1;
                var_s0 >>= 1;
                goto countbits;
            }
            
            D_800785CC[var_s1] = 1;
            
            if (var_s1 == 2) {
                if (var_s0 & 0x800) {
                    D_8006FCD2 = 1;
                    D_80078600 = 1;
                    func_800509E0(0x136, 0x64, 0, 0);
                }
            }
            temp_a0 = (1 << var_s1);
            ((int*)gameTracker)[0x4C9C/4] |= (1 << var_s1);

            if (temp_a0 & 0xF800) {
                SIGNAL_HandleSignal(((int*)gameTracker)[3], arg1[4] + 4, 0);
            }
            else if (temp_a0 & 0x780) {
                SIGNAL_HandleSignal(((int*)gameTracker)[3], arg1[5] + 4, 0);
            }
            else if (temp_a0 & 0x7F) {
                SIGNAL_HandleSignal(((int*)gameTracker)[3], arg1[7] + 4, 0);
            }
        }
        else if (*arg0 == 6)
        {
            SIGNAL_HandleSignal(((int*)gameTracker)[3], arg1[3] + 4, 0);
            *arg0 = 0;
        }
    }
}

void map_select_OnCreate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR sp10;
    SVECTOR sp18;
    char* temp_s6;
    int var_a1;
    int var_s1;
    int var_s2;
    int* temp_a3;
    int** temp_s0_2;
    int* temp_s4;
    int* temp_v1_3;

    temp_s6 = (char*)&instance->_D0[0];
    temp_a3 = (int*)PlayerInstance->data;
    instance->flags |= 0xC00;
    temp_s4 = (int*)instance->introData;
    ((int**)gameTracker)[3][0x4] &= ~0x800;
    ((short*)temp_a3)[0xDC/2] = 0;
    ((char*)instance->_D0)[0] = 0;
    GetRemoteCount(&instance->_D0[2]);
    var_s1 = 0;
    for(var_s2 = func_8001A1D8(&instance->_D0[2]); var_s2 != 0; var_s1++, var_s2 >>= 1)
    {
        if ((var_s2 & 1) == 0)
            continue;
         
        D_800785CC[var_s1] = 2;
        
        if (var_s1 >= 11 ) {
            D_800785CC[var_s1] = 3;
            if ((var_s1 == 11))
            {
                temp_v1_3 = (int*)temp_s4[8];
                var_a1 = *temp_v1_3;
                temp_v1_3++;
                while (var_a1 != 0) {
                     var_a1--;
                    (((int**)temp_v1_3++)[0])[7] |= 0x80;
                }
            }
        } else if (var_s1 >= 7) {
                temp_v1_3 = (temp_s4 + var_s1) + 2;
                (*(int**)temp_v1_3)[7] |= 0x80;
        } else {
            temp_s0_2 = (int**)(&temp_s4[var_s1])[0x34/4];
            func_800516E0(((int*)temp_s0_2[10])[0], &sp10);
            func_80051C64(((int*)temp_s0_2[10])[0], &sp10, temp_s0_2 + 4);
            if (((int*)temp_s0_2[10])[1] != 0) {
                func_800516E0(((int*)temp_s0_2[10])[1], &sp10);
                func_80051C64(((int*)temp_s0_2[10])[1], &sp10, &sp18);
                ((short*)temp_s0_2)[4] += sp18.x;
                ((short*)temp_s0_2)[5] += sp18.y;
                ((short*)temp_s0_2)[6] += sp18.z;
            }
            temp_s0_2[10] = 0;
            temp_s0_2[7] =  (int*)((int)temp_s0_2[7] & ~0x80);
            temp_s0_2[7] =  (int*)((int)temp_s0_2[7] & ~0x100);
        }
    }
    if (((int*)gameTracker)[0x4BF4/4] == 0) {
        func_80032F30();
        func_80040170(0xF);
        D_8006FC69 = 0;
        ((short*)gameTracker8)[0x4C66/2] = 0;
        ((short*)gameTracker8)[0x4C68/2] = 0;
    }
    else
        func_8015E674_BF0A4(temp_s6, temp_s4, gameTracker);
}

void map_select_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    SVECTOR sp10;
    SVECTOR sp18;
    int* temp_a1;
    int* temp_a2;
    short* temp_s0;
    short* temp_s2;

    temp_s2 = (short*)PlayerInstance->data;
    temp_a1 = (int*)instance->introData;
    ((GameTracker*)gameTracker)->gameFlags &= ~0x2000;
    temp_a2 = (int*)((int*)gameTracker)[0xC/4];
    temp_s0 = (short*)&instance->_D0;
    
    if (!(temp_a2[0xFC/4] & 0x02000000)) {
        if ((PlayerInstance->_F4[0] == 0) && (PlayerInstance->_F4[1] == 1)) {
            temp_a2[0x104/4]++;
        } else {
            ((int**)gameTracker)[0xC/4][0x104/4] = 0;
        }
        ((short**)PlayerInstance)[0x20/4][0xDC/2] = 5;
        if (temp_s0[0x6/2] != 0) {
            temp_s0[0x6/2] = (temp_s0[0x6/2] + 1);
        }
        if (temp_s0[0x6/2] >= 8) {
            temp_s0[0x6/2] = 0;
        }
        switch (*(char*)temp_s0) {
        case 0:
            ((u8*)temp_s0)[0x20]++;
            if ((PlayerInstance->_F4[0] == 5) && (((char*)temp_s0)[0x20] >= 0x15)) {
                func_8002DAF8(PlayerInstance, -1);
                temp_s2[0x82/2] = ((short*)PlayerInstance)[0x64/2] = ((short*)gameTracker8)[0x4C6C/2];
                if (PlayerInstance->flags2 & 0x10) {
                    ((u8*)temp_s0)[0x20] = 0x42U;
                }
            }
            if ((((s8*) temp_s0)[0x20] < 0x43) && (((short*)gameTracker8)[0x4C66/2] != 0) && (((short*)gameTracker8)[0x4C68/2] != 0)) {
                sp10 = *(SVECTOR*)&((short*)PlayerInstance)[0x48/2];
                PlayerInstance->_F4[0] = 5;
                ((u8*)PlayerInstance)[0x4E] = 0x32;
                ((short*)PlayerInstance)[0x4C/2] = ((short*)gameTracker8)[0x4C6A/2];
                ((short*)PlayerInstance)[0x54/2] = ((short*)gameTracker8)[0x4C6A/2];
                ((short*)PlayerInstance)[0x48/2] = ((short*)gameTracker8)[0x4C66/2];
                ((short*)PlayerInstance)[0x50/2] = ((short*)gameTracker8)[0x4C66/2];
                ((short*)PlayerInstance)[0x4A/2] = ((short*)gameTracker8)[0x4C68/2];
                ((short*)PlayerInstance)[0x52/2] = ((short*)gameTracker8)[0x4C68/2];
                ((short*)PlayerInstance)[0x64/2] = ((short*)gameTracker8)[0x4C6C/2];
                sp18.x = ((short*)PlayerInstance)[0x48/2] - sp10.x;
                sp18.y = ((short*)PlayerInstance)[0x4A/2] - sp10.y;
                sp18.z = ((short*)PlayerInstance)[0x4C/2] - sp10.z;
                func_80012BD0(PlayerInstance, &sp18, gameTracker);
                func_80001DF4((s16) ((short*)PlayerInstance)[0x64/2]);
                ((short*)gameTracker8)[0x4C66/2] = 0;
                ((short*)gameTracker8)[0x4C68/2] = 0;
                if (D_8006FC69 != 0) {
                    func_80032F30();
                    func_80040170(2);
                }
            }
            if (((char*)temp_s0)[0x20] == 0x42) {
                *(u8*)temp_s0 = 4;
                ((short*)gameTracker8)[0x4C90/2] &= 0xFFFD;
                if (PlayerInstance->_F4[0] == 5) {
                    PlayerInstance->_F4[0] = 0;
                    ((u8*)PlayerInstance)[0x4E] = 0;
                }
                D_80161670_C20A0 = 0;
                ((char*)gameTracker)[0x4CDC] = 0;
                return;
            }
            break;
        case 4:
            if (D_8006CF58 != 0) {
                if ((((int*)gameTracker)[0x18/4] != 0) || (((int*)gameTracker)[0x24/4] != 0) || (((int*)gameTracker)[0x28/4] != 0)) {
                    D_80161670_C20A0 = 0;
                    return;
                }
                if (((short*)gameTracker)[0x4C12/2] != 6) {
                    D_80161670_C20A0++;
                    if (D_80161670_C20A0 >= 0x4B1) {
                        ((short*)gameTracker)[0x4C12/2] = 0;
                        D_80078170 = 1;
                        func_8001A854();
                        D_8014F358 = 0;
                        return;
                    }
                }
            }
            break;
        case 6:
            func_8015E674_BF0A4((char*)temp_s0, temp_a1, gameTracker);
            break;
        }
    }
}

void map_password_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void map_password_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void map_markey_OnCreate(Instance* instance, GameTracker* gameTracker) {
}

void map_markey_OnUpdate(Instance* instance, GameTracker* gameTracker) {
}

void func_8015EEC8_BF8F8(Instance* instance, GameTracker* gameTracker) {
}

void func_8015EED0_BF900(Instance* instance, GameTracker* gameTracker) {
}

void func_8015EED8_BF908(int* arg0) {
    char sp10[0x40];

    if ((arg0[0x18/4] != 0) || (arg0[0x24/4] != 0) || (arg0[0x28/4] != 0)) {
        D_80161674_C20A4 = 0;
    }
    else
    {
        D_80161674_C20A4++;
        if (D_80161674_C20A4 >= 0x4B1) {
            ((short*)arg0)[0x4C12/2] = 0;
            D_80078170 = 1;
            func_8001A854();
            D_8014F358 = 0;
            return;
        }
    }
    
    if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
        D_8014F34C--;
    }
    else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
        D_8014F34C++;
    }
    
    if (D_8014F34C < 0) {
        D_8014F34C = 0;
    }
    
    if (D_8014F34C > 2) {
        D_8014F34C = 2;
    }
    
    func_80037B00(0x5F, 0x4B);
    if (D_8014F34C == 0) {
        sprintf(sp10, "%s%s", &D_80078184, D_801611C0_C1BF0);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_801611C0_C1BF0);
    }
    
    func_80037B00(0x53, 0x6E);
    if (D_8014F34C == 1) {
        sprintf(sp10, "%s%s", &D_80078184, D_801611CC_C1BFC);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_801611CC_C1BFC);
    }
    
    func_80037B00(0x64, 0x91);
    if (D_8014F34C == 2) {
        sprintf(sp10, "%s%s", &D_80078184, D_80078190);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_80078190);
    }
    
    if (D_800E5DB2 & 0x9000) {
        switch (D_8014F34C) {
        case 0:
            D_80078170 = 1;
            D_8006CF20 = 0;
            ((short*)arg0)[0x4C12/2] = 0;
            func_80032F90();
            break;
        case 1:
            func_80040170(1);
            D_80156BE4 = 0;
            break;
        case 2:
            func_80040170(3);
            break;
        }
    }
    gSPDisplayList(D_80157050++, D_8006D578);
    DrawTextToScreen("PRESS A TO SELECT", 0x58, 0xD2, 1);
    gDPPipeSync(D_80157050++);
}

void func_8015F228_BFC58(int* arg0) {
    char sp10[0x40];
    s32 var_v1;

    if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
        D_8014F34C--;
    }
    else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
        D_8014F34C++;
    }
    
    if (D_8014F34C < 0) {
        D_8014F34C = 0;
    }
    
    if (D_8014F34C > 5) {
        D_8014F34C = 5;
    }
    
    func_80037B00(0x69, 0x32);
    
    if (D_8014F34C == 0) {
        sprintf(sp10, "%s%s", D_80078184, D_80078188);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_80078188);
    }
    
    func_80037B00(0x5F, 0x4B);
    
    if (D_8014F34C == 1) {
        sprintf(sp10, "%s%s", D_80078184, D_801611C0_C1BF0);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_801611C0_C1BF0);
    }
    
    func_80037B00(0x53, 0x64);
    
    if (D_8014F34C == 2) {
        sprintf(sp10, "%s%s", D_80078184, D_801611CC_C1BFC);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_801611CC_C1BFC);
    }
    
    func_80037B00(0x52, 0x7D);
    
    if (D_8014F34C == 3) {
        sprintf(sp10, "%s%s", D_80078184, D_801611B4_C1BE4);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_801611B4_C1BE4);
    }
    
    func_80037B00(0x64, 0x96);
    
    if (D_8014F34C == 4) {
        sprintf(sp10, "%s%s", D_80078184, D_80078190);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_80078190);
    }
    
    func_80037B00(0x6E, 0xAF);
    
    if (D_8014F34C == 5) {
        sprintf(sp10, "%s%s", D_80078184, D_800781B8);
        Print3DTextf(sp10);
    } else {
        Print3DTextf(D_800781B8);
    }
    
    if ((D_800E5DB2 & 0x8000)) {
        switch (D_8014F34C) {
        case 1:
            
            for(var_v1 = 0; var_v1 < 0x18; var_v1 += 1) {
                D_800E5D00[var_v1] = D_80161208_C1C38[var_v1];
            }
            
            if (func_8003FDD8(arg0) == 0) {
                D_80078170 = 1;
                D_8006CF20 = 0;
                ((short*)gameTracker8)[0x4C66/2] = 0;
                ((short*)gameTracker8)[0x4C68/2] = 0;
                func_800396E0(0, D_80161314_C1D44, arg0);
            }
            break;
            
        case 2:
            func_80040170(1);
            break;
            
        case 3:
        func_80040170(2);
            break;
            
        case 4:
        func_80040170(3);
            break;
            
        case 5:
        func_80040170(16);
            break;
            
        case 0:
            ((short*)arg0)[0x4C12/2] = 0;
            func_80032F90();
            break;
        }
    }
    else if (D_800E5DB2 & 0x1000)
    {
        ((short*)arg0)[0x4C12/2] = 0;
        func_80032F90();
    }
    
    gSPDisplayList(D_80157050++, D_8006D578);
    DrawTextToScreen("A=SELECT  START=ABORT", 0x4B, 0xD7, 1);
    gDPPipeSync(D_80157050++);
}

void func_8015F678_C00A8(short* arg0) {
    int var_a0;
    char* var_v1;

    func_80037B00(0x46, 0x6E);
    Print3DTextf("#2GAME OVER");
    gSPDisplayList(D_80157050++, D_8006D578);
    DrawTextToScreen("PRESS A TO START NEW GAME", 0x2D, 0xB4, 1);
    gDPPipeSync2(D_80157050);
    if (D_800E5DB2 & 0x8000) {
        ((int*)arg0)[0x4BF4/4] = 5;
        ((int*)arg0)[0x4C9C/4] = 0;
        arg0[0x4C8E/2] = 0;
        arg0[0x4C90/2] = 0;
        ((int*)arg0)[0x4C94/4] = 0;
        ((int*)arg0)[0x4C98/4] = 0;
        
        var_a0 = 0x1E;
        var_v1 = (char*)arg0 + 0x1E;
        
        for(var_a0; var_a0 >= 0; var_a0--)
        {
            (var_v1--)[0x4C6E] = 0;
        }
        
        D_8006FCD2 = 0;
        func_800396E0(0, D_80161314_C1D44, arg0);
    }
}

void func_8015F770_C01A0(void) {
    if (D_80161680_C20B0 < 0x3C) {
        D_80161680_C20B0 += 1;
        func_80037B00(0x5A, 0x50);
        Print3DTextf("GAME LOAD");
        func_80037B00(0x6E, 0x6E);
        Print3DTextf("FAILED");
    } else {
        func_80040170(4);
    }
    if (D_800E5DB2 & 0x8000) {
        D_80161680_C20B0 = 0x3C;
    }
}

void func_8015F804_C0234(short* arg0) {
    char buffer[18];
    int i;

    if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
        D_800E5D00[D_80156BE4]++;
        D_8014F34C = 0;
    }
    else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
        D_800E5D00[D_80156BE4]--;
        D_8014F34C = 0;
    } else if ((D_800E5DB2 & 0x202) || (D_801539C4 != 0)) {
        D_80156BE4--;
        D_8014F34C = 0;
        if (D_80156BE4 < 0) {
            D_80156BE4 = 0;
        }
    } else if ((D_800E5DB2 & 0x101) || (D_800E9732 != 0)) {
        D_80156BE4++;
        D_8014F34C = 0;
        if (D_80156BE4 > 17) {
            D_80156BE4 = 17;
        }
    }
    
    if (D_800E5D00[D_80156BE4] < 0) {
        D_800E5D00[D_80156BE4] = 31;
    }
    
    if (D_800E5D00[D_80156BE4] > 31) {
        D_800E5D00[D_80156BE4] = 0;
    }

    for (i = 0; i < 18; i++) {
        if ((D_800E5D00[i] < 0x20U) && !(i == D_80156BE4 && (D_8014F34C & 0x10))) {
            buffer[i] = D_80078150[D_800E5D00[i]];
        } else {
            buffer[i] = '*';
        }
    }
    buffer[i] = 0;
    
    func_80037B00(0x73, 0x46);
    Print3DTextf("ENTER");
    func_80037B00(0x62, 0x64);
    Print3DTextf(D_801611D8_C1C08);
    gSPDisplayList(D_80157050++, D_8006D578);
    DrawTextToScreen(buffer, 0x50, 0x8C, 1);
    if (D_800E5DB2 & 0x8000) {
        if (func_8003FDD8(arg0) == 0) {
            D_80078170 = 1;
            ((short*)gameTracker8)[0x4C66/2] = 0;
            ((short*)gameTracker8)[0x4C68/2] = 0;
            func_800396E0(0, &D_80161314_C1D44, arg0);
        } else {
            func_80040170(8);
            D_80161680_C20B0 = 0;
        }
    }
    else if (D_800E5DB2 & 0x4000) {
        func_80040170(1);
    }
    else if (D_800E5DB2 & 0x1000) {
        if (D_80078170 != 0) {
            arg0[0x4C12/2] = 0;
            func_80032F90();
        }
    }
    if (D_80078170 != 0) {
        DrawTextToScreen("A=ACCEPT  B=BACK  START=ABORT", 0x1E, 0xD2, 1);
    } else {
        DrawTextToScreen("A=ACCEPT  B=BACK", 0x55, 0xD2, 1);
    }
    gDPPipeSync(D_80157050++);
    D_8014F34C++;
}

void func_8015FBBC_C05EC(short* arg0) {

    func_80037B00(0x3C, 0x5F);
    Print3DTextf("PASSWORD IS");
    gSPDisplayList(D_80157050++, D_8006D578);
    DrawTextToScreen(D_800E5D00, 0x50, 0x82, 1);
    DrawTextToScreen("PRESS A TO CONTINUE", 0x50, 0xC8, 1);
    gDPPipeSync2(D_80157050);
    if (D_800E5DB2 & 0x8000) {
        arg0[0x4C12/2] = 0;
        func_80032F90();
    }
}

void func_8015FC88_C06B8(int* arg0) {
    char sp10[0x40];

    if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
        D_8014F34C--;
    }
    else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
        D_8014F34C++;
    }
    if (D_8014F34C < 0) {
        D_8014F34C = 0;
    }
    if (D_8014F34C > 1) {
        D_8014F34C = 1;
    }
    
    func_80037B00(0x37, 0x32);
    Print3DTextf(&D_801611E4_C1C14);
    func_80037B00(0x62, 0x64);
    if (D_8014F34C == 0) {
        sprintf(sp10, "%s%s", &D_80078184, &D_801611D8_C1C08);
        Print3DTextf(&sp10);
    } else {
        Print3DTextf(&D_801611D8_C1C08);
    }
    func_80037B00(0x32, 0x8C);
    if (D_8014F34C == 1) {
        sprintf(sp10, "%s%s", &D_80078184, &D_80078198);
        Print3DTextf(&sp10);
    } else {
        Print3DTextf(&D_80078198);
    }
    if (D_800E5DB2 & 0x8000) {
        switch (D_8014F34C) {
        case 0:
            func_80040170(4);
            D_80156BE4 = 0;
            break;
        case 1:
            func_80040170(5);
            break;
        }
    } else if (D_800E5DB2 & 0x4000) {
        if (D_80078170 != 0) {
            func_80040170(0);
        } else {
            func_80040170(0xD);
        }
    } else if ((D_800E5DB2 & 0x1000) && (D_80078170 != 0)) {
        ((short*)arg0)[0x4C12/2] = 0;
        func_80032F90();
    }
    gSPDisplayList(D_80157050++, &D_8006D578);
    if (D_80078170 != 0) {
        DrawTextToScreen(&D_801614D0_C1F00, 0x23, 0xD2, 1);
    } else {
        DrawTextToScreen(&D_801614F0_C1F20, 0x4B, 0xD2, 1);
    }
    gDPPipeSync(D_80157050++);
}

void func_8015FF60_C0990(int* arg0) {
    char sp10[0x40];

    if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
        D_8014F34C--;
    }
    else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
        D_8014F34C++;
    }
    if (D_8014F34C < 0) {
        D_8014F34C = 0;
    }
    if (D_8014F34C > 1) {
        D_8014F34C = 1;
    }
    func_80037B00(0x46, 0x32);
    Print3DTextf(&D_801611F8_C1C28);
    func_80037B00(0x62, 0x64);
    if (D_8014F34C == 0) {
        sprintf(sp10, "%s%s", &D_80078184, &D_801611D8_C1C08);
        Print3DTextf(&sp10);
    } else {
        Print3DTextf(&D_801611D8_C1C08);
    }
    func_80037B00(0x32, 0x8C);
    if (D_8014F34C == 1) {
        sprintf(sp10, "%s%s", &D_80078184, &D_80078198);
        Print3DTextf(&sp10);
    } else {
        Print3DTextf(&D_80078198);
    }
    if (D_800E5DB2 & 0x8000) {
        switch (D_8014F34C) {
        case 0:
            func_80040170(6);
            func_8003FAD0(arg0, 1);
            break;
        case 1:
            func_80040170(7);
            break;
        }
    } else if (D_800E5DB2 & 0x4000) {
        if (D_8006FC69 != 0) {
            ((short*)arg0)[0x4C12/2] = 0;
            func_80032F90();
            D_8006FC69 = 0;
        } else {
            func_80040170(0);
        }
    } else if (D_800E5DB2 & 0x1000) {
        ((short*)arg0)[0x4C12/2] = 0;
        func_80032F90();
    }
    
    gSPDisplayList(D_80157050++, D_8006D578);
    DrawTextToScreen(D_801614D0_C1F00, 0x23, 0xD2, 1);
    gDPPipeSync(D_80157050++);
    
}

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801614D0_C1F00);

INCLUDE_RODATA("asm/nonmatchings/level/MAP", D_801614F0_C1F20);

void func_80160214_C0C44(short* arg0) {
    s32 var_s1;
    s32 var_s3;
    int temp_v0_3;
    SAVEFILE_ALT_t* var_s0;

    switch (D_8006FA54) {
    case 1:
        D_8006FA54 = 2;
        osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_SW2, OS_MESG_NOBLOCK);
        return;
    case 3:
        if (D_80156BDC == 0) {
            D_80078171 = 1;
            D_8006CF20 = 0;
            D_8006FA54 = 4;
            osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_CART, OS_MESG_NOBLOCK);
            return;
        }
        func_80040170(10);
        D_8006FA54 = 0x12;
        return;
    case 5:
        if (D_80156BDC == 0) {
            if (D_800E97CC != 0) {
                D_800E5CD4 = 0;
                D_8006FA54 = 6;
                return;
            }
            func_80040170(12);
            D_8006FA54 = 0x12;
            return;
        }
        func_80040170(10);
        D_8006FA54 = 0x12;
        return;
    case 6:
        if (D_800E5CD4 < D_80157034) {
            D_8006FA54 = 7;
            osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_SP, OS_MESG_NOBLOCK);
        return;
        }
        D_8014F34C = func_80014D00(-1);
        if (D_8014F34C == -1) {
            func_80040170(12);
            D_8006FA54 = 0x12;
            return;
        }
        D_8006FA54 = 0x13;
        D_801574FC = D_8014F34C;
        return;
    case 19:
        if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
            D_8014F34C = func_80014C80(D_8014F34C);
            if (D_8014F34C < D_801574FC) {
                D_801574FC = D_8014F34C;
            }
        } else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
            temp_v0_3 = func_80014D00(D_8014F34C);
            if (temp_v0_3 != D_8014F34C) {
                
                var_s3 = 0;
                for (var_s1 = D_801574FC; var_s1 < temp_v0_3; var_s1++) {
                    var_s0 = &D_800E5DDE[var_s1];
                    if ((   var_s0->filename.MAGIC[0] == SAVEFILE_MAGIC_STRING[0])
                        && (var_s0->filename.MAGIC[1] == SAVEFILE_MAGIC_STRING[1])
                        && (var_s0->filename.MAGIC[2] == SAVEFILE_MAGIC_STRING[2])
                        && (var_s0->filename.MAGIC[3] == SAVEFILE_MAGIC_STRING[3])
                       ) {
                        var_s3++;
                    }
                }
                if (var_s3 >= 5) {
                    D_801574FC = func_80014D00(D_801574FC);
                }
                D_8014F34C = temp_v0_3;
            }
        }
        if (D_800E5DB2 & 0x8000) {
            D_8006FA54 = 0x14;
            D_800E5CD4 = D_8014F34C;
            osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_VI, OS_MESG_NOBLOCK);
        } else if (D_800E5DB2 & 0x1000) {
            if (D_80078170 != 0) {
                arg0[0x4C12/2] = 0;
                func_80032F90();
                D_8006FA54 = 0xD;
            }
        } else if (D_800E5DB2 & 0x4000) {
            func_80040170(1);
        }
        gSPDisplayList(D_80157050++, D_8006D578);
        DrawTextToScreen("PICK FILE TO LOAD", 0x50, 0x32, 1);
        if (func_80014C80(D_801574FC) != D_801574FC) {
            DrawTextToScreen("^", 0x50, 0x49, 1);
        }
        var_s1 = D_801574FC;
        var_s3 = 0;
        while (var_s1 < D_80157034 && var_s3 < 5)
        {
            var_s0 = &D_800E5DDE[var_s1];
            if ((   var_s0->filename.MAGIC[0] == SAVEFILE_MAGIC_STRING[0])
                && (var_s0->filename.MAGIC[1] == SAVEFILE_MAGIC_STRING[1])
                && (var_s0->filename.MAGIC[2] == SAVEFILE_MAGIC_STRING[2])
                && (var_s0->filename.MAGIC[3] == SAVEFILE_MAGIC_STRING[3])) {
                DrawTextToScreen(var_s0, 0x64, 0x5A + var_s3 * 0x14, 0);
                if (var_s1 == D_8014F34C) {
                    DrawTextToScreen(">", 0x50, 0x5A + var_s3 * 0x14, 1);
                }
                var_s3 += 1;
            }
            var_s1 += 1;
        }
        if (func_80014D00(var_s1 - 1) != (var_s1 - 1)) {
            DrawTextToScreen("$", 0x50, 0xBE, 1);
        }
        if (D_80078170 != 0) {
            DrawTextToScreen(D_801614D0_C1F00, 0x23, 0xD2, 1);
        } else {
            DrawTextToScreen(D_801614F0_C1F20, 0x4B, 0xD2, 1);
        }
        
        gDPPipeSync(D_80157050++);
        return;
        
    case 21:
        if (D_80156BDC != 0) {
            func_80040170(10);
            D_8006FA54 = 0x12;
            return;
        }
        if (func_8003FDD8(arg0) == 0) {
            D_80078170 = 1;
            ((short*)gameTracker8)[0x4C66/2] = 0;
            ((short*)gameTracker8)[0x4C68/2] = 0;
            func_800396E0(0, &D_80161314_C1D44, arg0);
            D_8006CF20 = D_800E5CD4 + 1;
        }
    }
}

void func_80160838_C1268(void) {
    gSPDisplayList(D_80157050++, D_8006D578);
    if (D_800E8EB4 == 0) {
        DrawTextToScreen("USE ONE PAGE OF MEMORY", 0x41, 0x32, 1);
        DrawTextToScreen("TO CREATE FILE:", 0x5A, 0x46, 1);
        DrawTextToScreen(D_80078174, 0x50, 0x73, 0);
    } else {
        DrawTextToScreen("SAVE TO FILE:", 0x5A, 0x46, 1);
        DrawTextToScreen(&D_800E5DDE[D_800E5CD4], 0x50, 0x73, 0);
    }
    if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
        D_8014F34C = 0;
    } else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
        D_8014F34C = 1;
    }
    DrawTextToScreen("YES, SAVE FILE", 0x3C, 0x96, 1);
    DrawTextToScreen("NO, DON'T SAVE", 0x3C, 0xAA, 1);
    DrawTextToScreen(">", 0x2D, (D_8014F34C * 0x14) + 0x96, 1);
    DrawTextToScreen("PRESS A TO SELECT", 0x55, 0xC8, 1);
    if (D_800E5DB2 & 0x8000) {
        if (D_8014F34C == 0) {
            func_80040170(7);
            if (D_800E8EB4 == 0) {
                D_8006FA54 = 0x10;
                osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_SI, OS_MESG_NOBLOCK);
            } else {
                D_8006FA54 = 0xA;
                osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_AI, OS_MESG_NOBLOCK);
            }
            return;
        }
        if ((D_800B83C8 < 0x100) || (D_800E97CC >= D_80157034)) {
            D_8014F354 = 1;
            func_80040170(0x14);
            return;
        }
        func_80040170(0xE);
        D_8006FA54 = 0xE;
    }
}

void func_80160ACC_C14FC(short* arg0) {
    char var_s1;

    if ((D_800E5DB2 & 0x808) || (D_800E5B98 != 0)) {
        D_80078174[D_80156BE4]++;
        if ((D_80078174[D_80156BE4] - 0x10) >= 0x32U) {
            D_80078174[D_80156BE4] = 0x10;
        }
        D_8014F34C = 0;
    }
    else if ((D_800E5DB2 & 0x404) || (D_80157030 != 0)) {
        D_80078174[D_80156BE4]--;
        if (((char*)D_80078174)[D_80156BE4] < 0x10) {
            D_80078174[D_80156BE4] = 0x41;
        }
        D_8014F34C = 0;
    } else if ((D_800E5DB2 & 0x202) || (D_801539C4 != 0)) {
        D_8014F34C = 0;
        D_80156BE4 = D_80156BE4 - 1;
        if (D_80156BE4 < 4) {
            D_80156BE4 = 4;
        }
    } else if ((D_800E5DB2 & 0x101) || (D_800E9732 != 0)) {
        D_8014F34C = 0;
        D_80156BE4++;
        if (D_80156BE4 >= 15) {
            D_80156BE4 = 14;
        }
    }
    gSPDisplayList(D_80157050++, D_8006D578);
    DrawTextToScreen("ENTER NAME FOR THIS GAME", 0x32, 0x50, 1);
    if (D_8014F34C & 0x10) {
        var_s1 = D_80078174[D_80156BE4];
        D_80078174[D_80156BE4] = 15;
    }
    DrawTextToScreen(&D_80078174, 0x50, 0x73, 0);
    DrawTextToScreen("PRESS A TO SAVE", 0x50, 0x96, 1);
    DrawTextToScreen("PRESS START TO ABORT", 0x41, 0xAA, 1);
    if (D_8014F34C & 0x10) {
        D_80078174[D_80156BE4] = var_s1;
    }
    if (D_800E5DB2 & 0x8000) {
        D_800E8EB4 = 0;
        func_80040170(21);
    } else if (D_800E5DB2 & 0x1000) {
        arg0[0x4C12/2] = 0;
        func_80032F90();
        D_8006FA54 = 13;
    }
    gDPPipeSync(D_80157050++);
    D_8014F34C++;
}

void func_80160DF0_C1820(void* arg0) {
    switch (D_8006FA54) {
        
    case 1:
        D_8006FA54 = 2;
        osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_SW2, OS_MESG_NOBLOCK);
        break;
        
    case 3:
        if (D_80156BDC != 0) {
            func_80040170(0xA);
            D_8006FA54 = 0xE;
            D_8006CF20 = 0;
            break;
        }
            
        D_80078171 = 1;
        func_8003FAD0(arg0, 0);
        
        if (D_8006CF20 != 0) {
            D_800E5CD4 = D_8006CF20 - 1;
            D_800E8EB4 = 1;
            func_80040170(0x15);
            break;
        }
            
        D_8006FA54 = 4;
        osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_CART, OS_MESG_NOBLOCK);
        
        break;
        
    case 5:
        
        if (D_80156BDC == 0) {
            D_8006FA54 = 8;
            osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_COUNTER, OS_MESG_NOBLOCK);
            break;
        }
            
        func_80040170(0xA);
        D_8006FA54 = 0xE;
        break;
        
    case 9:
        if (D_80156BDC != 0)
        {
            func_80040170(0xA);
            D_8006FA54 = 0xE;
            break;
        }
        
        if (D_800B83C8 >= 0x100 && D_800E97CC < D_80157034) {
            func_80040170(0xE);
            D_8006FA54 = 0xE;
            break;
        }
        
        D_8014F354 = 1;
        func_80040170(0x14);
        break;
        
    case 6:
        if ((D_80156BDC == 0) || ((D_80156BDC == 5))) {
            if (D_800E5CD4 < D_80157034) {
                D_8006FA54 = 7;
                osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_SP, OS_MESG_NOBLOCK);
            }
            else
            {
                D_8006FA54 = 0xE;
                D_8014F354 = 1;
                func_80040170(0xB);
                D_801574FC = D_8014F34C = func_80014DD4(-1);
            }
        }
        else
        {
            func_80040170(0xA);
            D_8006FA54 = 0xE;
        }
        break;
        
    case 17:
        if (D_80156BDC != 0) {
            func_80040170(0xA);
            D_8006FA54 = 0xE;
        } else {
            D_8006FA54 = 0xA;
            osSendMesg(&gGlobalMessageBuffer, (void*)OS_EVENT_AI, OS_MESG_NOBLOCK);
        }
        
    case 11:
        if (D_80156BDC != 0) {
            func_80040170(0xA);
            D_8006FA54 = 0xE;
        }
        else
        {
            D_8006FA54 = 0xD;
            D_8006CF20 = D_800E5CD4 + 1;
            func_80040170(0x1B);
        }
        return;
    }
}

void func_801610B8_C1AE8(short* arg0) {
    func_80037B00(0x50, 0x6E);
    Print3DTextf("#2DATA SAVED");
    if (++D_8014F34C >= 0x1F) {
        arg0[0x4C12/2] = 0;
        func_80032F90();
    }
}