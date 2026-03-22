#include "common.h"
#include "types/GameTracker.h"
#include "types/G2String.h"
#include "types/intro/PowerTV.h"

#include "types/Instance.h"
#include "types/obtable.h"

#include "types/Matrix.h"
#include "types/Quat.h"

#include "level/COMMON.h"
#include "INSTANCE.h"

#include "SPLINE.h"

MultiSpline* SCRIPT_GetMultiSpline(Instance *instance, int *isParent, int *isClass);

extern short SplineSetDef2FrameNumber(Spline *spline, SplineDef *def, unsigned short frame_number);
extern SplineDef *SCRIPT_GetPosSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);
extern SplineDef *SCRIPT_GetRotSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);
extern SplineDef *SCRIPT_GetScaleSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);

Spline *ScriptGetPosSpline(Instance *instance);
RSpline *ScriptGetRotSpline(Instance *instance);

// Hint: Probably SCRIPT.c

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80041FD0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042120);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042184);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042330);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042674);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042A4C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80042CC0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800434BC);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80043708);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_fpower_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80043958);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_colfire_OnUpdate);

INCLUDE_RODATA("asm/nonmatchings/_42bd0", D_8007E510);

INCLUDE_RODATA("asm/nonmatchings/_42bd0", jtbl_8007E518);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_ice_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_icecube_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_icecube_OnCollide);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800444B8);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnCreate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powerbug_OnCollide);

void func_80044B2C(Instance* instance) {
    int temp_v1;
    int* temp_a2;

    temp_a2 = ((((int***)instance->object->modelList)[instance->currentModel]))[0x20/4];
    temp_v1 = (instance->_F0[6] * 3);
    ((short*)&instance->_100)[0] = ((temp_v1 + 1) * temp_a2[3]);
    ((short*)&instance->_100)[1] = (((temp_v1 + 4) * temp_a2[3]) - 1);
    *(short*)&instance->_104 = -1;
    instance->_56 = *(short*)&instance->_100;
}

void common_powertv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int temp_v1;
    Intro* temp_a1;
    PowerTVIntro* intro;

    if (instance->intro->flags & 0x1000) {
        instance->intro->flags &= ~0x800;
        return;
    }
    
    intro = (PowerTVIntro*)instance->introData;
    
    instance->_4E = 0U;
    instance->_5E = 0;
    instance->flags |= 0x80;
    
    if (intro != NULL) {
        instance->_F0[6] = intro->type;
        instance->_F0[7] = intro->respawns;
    } else {
        instance->_F0[6] = EPTV_HEALTH;
    }
    
    instance->_F4[0] = 0;
    
    if (instance->intro->flags & 0x800) {
        instance->_F4[0] = 2;
        instance->_5E = ((((short**)instance->object->animList)[instance->_4E])[1] - 1);
        instance->_56 = 0;
    }
    else
    {
        func_80044B2C(instance);
    }
}

void common_powertv_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    int var_a1;
    short temp_a2;
    short tvType;
    Instance* flyInstance;
    int var_a0;
    short* temp_s1;

    temp_s1 = &instance->_F0[6];
    if ((instance->_F4[0] - 1) >= 2U) {
        instance->_56++;
        if (((short*)&instance->_100)[1] < instance->_56) {
            instance->_56 = *(short*)&instance->_100;
        }
    }
    else if (instance->_F4[0] == 1) {
        if (((short*)&instance->_104)[1] > 0) {
            ((short*)&instance->_104)[1]--;
            if ((((short*)&instance->_104)[1] << 0x10) == 0) {
                instance->_56 = ((short*)&instance->_100)[0];
                goto block_7;
            }
        }
        else
        {
block_7:
            func_8002DAF8(instance, ((short*)&instance->_104)[0]);
            if ((((short*)&instance->_104)[0] == -0x3E9) && (instance->_5E == 0x1A)) {
                instance->flags2 |= 0x10;
            }
            if (instance->flags2 & 0x10) {
                if (temp_s1[1] & 1) {
                    if (temp_s1[4] == -0x3E9) {
                        instance->_F4[0] = 0;
                        instance->_5E = 0;
                        temp_s1[4] = -1;
                        return;
                    }
                    temp_s1[5] = 0x1E;
                    temp_s1[4] = -0x3E9;
                    func_8002DAF8(instance, -0x3E9);
                    instance->flags2 = (int) (instance->flags2 & ~0x10);
                }
                else
                {
                    instance->_F4[0] = 2;
                    func_8002DAF8(instance, -0x3E9);
                }
                func_80050508(instance, 0x10, (short) ((rand() & 0x1F) - 0xF), 0x6E, 0x9C4);
                // type
                switch (temp_s1[0]) {
                case EPTV_HEALTH:
                    tvType = EPTV_HEALTH;
                    break;
                case EPTV_FIRE:
                    tvType = EPTV_FIRE;
                    break;
                case EPTV_ICE:
                    tvType = EPTV_ICE;
                    break;
                case EPTV_UNUSED:
                    tvType = EPTV_UNUSED;
                    break;
                case EPTV_LIFE:
                    tvType = EPTV_LIFE;
                    break;
                case EPTV_CHECKPOINT:
                    tvType = EPTV_CHECKPOINT;
                    break;
                }
                if (tvType != EPTV_CHECKPOINT) {
                    instance->position.x -= 0x8C;
                    instance->position.z += 0x8C;
                    flyInstance = (Instance*)INSTANCE_BirthCachedObject(instance, EOBJECT_PTBUG);
                    instance->position.x += 0x8C;
                    instance->position.z -= 0x8C;
                    if (flyInstance != NULL) {
                        func_800444B8(flyInstance, tvType);
                        func_80050508(instance, 9, (short) ((rand() & 0x1F) - 0xF), 0x50, 0x9C4);
                    }
                }
            }
            
        }
    }
    
    if (instance->_F4[1] == 1) {
        var_a0 = (temp_s1[6] + 1) * 0x55;
        if (var_a0 >= 0x100) {
            var_a0 = 0xFF;
        }
        var_a0 = (var_a0 << 0x18) | (var_a0 << 0x10) | (var_a0 << 8) | 0x7F;
        if (temp_s1[6] < 3) {
            temp_s1[6] = temp_s1[6] + 1;
        } else {
            instance->_F4[1] = 2;
            temp_s1[6] = 0x33;
        }
        func_8003F748(var_a0, 0);
    }
    else if (instance->_F4[1] == 2) {
        var_a1 = 0;
        var_a0 = temp_s1[6] * 5;
        if (var_a0 >= 0x100) {
            var_a0 = 0xFF;
        }
        var_a0 = (var_a0 << 0x18) | (var_a0 << 0x10) | (var_a0 << 8) | 0x7F;
        if (temp_s1[6] > 0) {
            temp_s1[6]--;
            if (temp_s1[6] >= 0xA) {
                var_a1 = 1;
            }
        } else {
            instance->_F4[1] = 0;
        }
        func_8003F748(var_a0, var_a1);
    }
}

void common_powertv_OnCollide(Instance* instance, GameTracker* gameTracker) {
    int temp_a2;
    int temp_a1;
    int* temp_a0;
    short* temp_s2;
    int** temp_s3;
    int* temp_s5;
    PowerTVIntro* intro;
    Intro* temp_v1;
    int* temp_v1_2;

    temp_a0 = (int*)gameTracker->_000C;
    temp_s3 = (int**)instance->_70[2];
    temp_a2 = temp_a0[0xF4/4] == 6;
    intro = instance->introData;
    temp_a1 = ((unsigned char*)temp_s3[3])[5];
    temp_s5 = (int*)temp_a0[0x20/4];
    temp_s2 = &instance->_F0[6];
    if ((instance->_F4[0] == 0) && (((((short*)temp_s3)[3] == 1) && (temp_a1 >= 8)) || ((temp_s3[0x14/4] == temp_a0) && (temp_a2 != 0)))) {
        if (!(temp_s2[1] & 1)) {
            instance->intro->flags |= 0x800;
        }
        instance->_F4[0] = 1;
        instance->_56 = 0;
        instance->flags2 &= ~0x10;
        func_80050508(instance, 0x11, (short) ((rand(temp_a0) & 0x1F) - 0xF), 0x6E, 0x9C4);
        if ((*temp_s2 == 5) && (instance->_F4[1] == 0)) {
            func_8004AAA8(instance, 0x84, 0);
            instance->_F4[1] = 1;
            temp_s2[6] = 0;
            gameTracker->level->spawnPosition.x = (instance->position.x + ((func_8003A6AC(instance->intro->rotation.z) << 0x10) >> 0x14));
            gameTracker->level->spawnPosition.y = (instance->position.y + ((func_8003A4E0(instance->intro->rotation.z) << 0x10) >> 0x14));
            gameTracker->level->spawnPosition.z = instance->position.z;
            gameTracker->level->startSignal = intro->checkpointStartSignal;
        }
        if (temp_s5[0x138/4] != 0) {
            if (temp_s3[0x14/4] == (((int**)gameTracker))[3]) {
                temp_s3[0x14/4][0xFC/4] |= 0x800;
            }
        }
    }
}