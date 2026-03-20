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

    temp_a2 = ((((int***)instance->object->modelList)[instance->_C0[1]]))[0x20/4];
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
INCLUDE_ASM("asm/nonmatchings/_42bd0", common_powertv_OnCollide);
/*void common_powertv_OnCollide(Instance* instance, GameTracker* gameTracker) {
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
            // set new spawn position and script, this is most likely a checkpoint box
            gameTracker->level->spawnPosition.x = (instance->position.x + ((func_8003A6AC(instance->intro->rotation.z) << 0x10) >> 0x14));
            gameTracker->level->spawnPosition.y = (instance->position.y + ((func_8003A4E0(instance->intro->rotation.z) << 0x10) >> 0x14));
            gameTracker->level->spawnPosition.z = instance->position.z;
            gameTracker->level->startSignal = intro->unk;
        }
        if (temp_s5[0x138/4] != 0) {
            if (temp_s3[0x14/4] == (((int**)gameTracker))[3]) {
                temp_s3[0x14/4][0xFC/4] |= 0x800;
            }
        }
    }
}*/

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnCreate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80045320);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800454E4);

INCLUDE_RODATA("asm/nonmatchings/_42bd0", D_8007E5C0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnUpdate);

INCLUDE_ASM("asm/nonmatchings/_42bd0", common_remsilv_OnCollide);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800462C0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046660);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046730);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_8004675C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046924);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046978);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800469A0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046A18);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046AA0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046C48);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046CB0);

void func_80046CE4(Instance* instance)
{
    func_8002E350(instance);
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046D04);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046DA4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046DDC);

void func_80046E70(short* arg0, int arg1)
{
    arg0[0x64/2] = (arg0[0x64/2] + arg1) & 0xFFF;
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046E88);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80046F20);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047058);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047240);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800472A4);

INCLUDE_RODATA("asm/nonmatchings/_42bd0", D_8007E6C0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800472F0);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047344);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800473A4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047438);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80047724);

extern void func_80047438(Instance*, GameTracker*);
extern void func_80047724();

void func_80047768(Instance* instance, int arg1, int arg2, int arg3) {
    Object* temp_a1 = instance->object;
    int var_a2 = 0;

    
    if ((temp_a1->oflags2 & 0x400)) 
    {
        var_a2 |= 0x40;
        var_a2 |= 0x8;
        var_a2 |= 0x1;
    }
    
    if (temp_a1->oflags2 & 0x20000) {
        var_a2 |= 0xC1;
    }

    if (temp_a1->oflags2 & 0x1000) {
        var_a2 |= 0x14;
    }

    if (temp_a1->oflags2 & 0x800) {
        var_a2 |= 3;
    }

    if (temp_a1->oflags2 & 0x2000) {
        var_a2 |= 0x21;
    }

    if (var_a2 == 0) {
        if (instance->flags2 & 1) {
            var_a2 = 3;
        }

        if (instance->flags2 & 2) {
            var_a2 |= 0x10;
            var_a2 |= ((temp_a1->oflags2 & 0x10000) ? 0x48 : 4);
        }

        if (instance->flags2 & 0x01000000) {
            var_a2 |= 0x49;
        }
    }

    if (instance->flags2 & 0x01000000) {
        var_a2 |= 0x100;
    }
    
    if (temp_a1->oflags2 & 0x4000) {
        var_a2 &= 0x11;
        if (var_a2 == 0) {
            var_a2 = 1;
        }
        var_a2 |= 0x40;
    } else if (temp_a1->oflags2 & 0x8000) {
        var_a2 &= ~0x1;
        var_a2 &= ~0x10;
    }
    if (var_a2 != 0) {
        func_80046D04(instance, func_80047438, var_a2, arg1, arg2);
        func_80047438(instance, gameTracker8);
    }
    else if (arg3 != 0) {
        func_80046D04(instance, func_80047724, 0, arg1, arg2);
    }
    else
        func_800473A4(instance, arg1, arg2);
}

void INSTANCE_PlainDeath(Instance* instance, int arg1, int arg2, int arg3) {
    Object* object;

    object = instance->object;
    func_80046CB0(instance);

    if (object->oflags2 & 0x100)
    {
        func_800473A4(instance, arg1, arg2);
    }
    else if (object->oflags2 & 0x200)
    {
        func_80046AA0(instance, arg2);
        func_80046CE4(instance);
    }
    else
    {
        func_80047768(instance, arg1, arg2, 1);
    }
    
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800479AC);

int func_80047D10(short* arg0)
{
    return arg0[3] & 0x69;
}

extern int D_800785CC[];
extern char D_8007E720[8]; // "fpower__"

void func_80047D20(int arg0, int arg1) {
    int result;
    G2String*** temp_v0;

    result = D_800785CC[arg0];
    if (arg1 == 0) {
        temp_v0 = ((G2String******)gameTracker8)[3][8][0x4C];
        result = 0;
        if (temp_v0 != NULL) {
            result = G2String_Compare_EQ(temp_v0[6][8], D_8007E720);
        }
    }
    D_800785CC[arg0] = result;
}

int func_80047DB4()
{
    func_8004A820();
    return 1;
}

int func_80047DD4()
{
    func_8004A7B8();
    return 1;
}

int func_80047DF4(SVECTOR v1, SVECTOR v2, int distance) {    
    return MATH3D_SquareLength((v1.x - v2.x), (v1.y - v2.y), (v1.z - v2.z)) < (distance * distance * 3);
}

extern const ROTATION D_8007E72C; // zero-matrix

void func_80047E64(Instance* instance, short axis) {
    ROTATION sp10;
    ROTATION sp18;
    MATRIX mat;
    int angle;

    sp10 = D_8007E72C;
    sp18 = D_8007E72C;
    sp10.y = -axis;
    MATH3D_SetUnityMatrix(&mat);
    angle = instance->rotation.z;
    if (instance->intro != NULL) {
        angle += instance->intro->rotation.z;
    }
    RotMatrixZ(angle, &mat);
    MATH3D_ApplyMatrixSV(&mat, (SVECTOR*)&sp10, (SVECTOR*)&sp18);
    instance->position.x += sp18.x;
    instance->position.y += sp18.y;
}

void func_80047F5C(Instance* instance, short yDirection) {
    MATRIX rotMatrix;
    SVECTOR axis;
    SVECTOR newPos;

    axis.y = -yDirection;
    axis.z = axis.x = 0;
    
    RotMatrix(&instance->rotation, &rotMatrix);
    
    newPos.x = ((axis.x * rotMatrix.m[0][0]) >> 0xC) + ((axis.y * rotMatrix.m[0][1]) >> 0xC) + ((axis.z * rotMatrix.m[0][2]) >> 0xC);
    newPos.y = ((axis.x * rotMatrix.m[1][0]) >> 0xC) + ((axis.y * rotMatrix.m[1][1]) >> 0xC) + ((axis.z * rotMatrix.m[1][2]) >> 0xC);
    newPos.z = ((axis.x * rotMatrix.m[2][0]) >> 0xC) + ((axis.y * rotMatrix.m[2][1]) >> 0xC) + ((axis.z * rotMatrix.m[2][2]) >> 0xC);
    
    instance->position.x = (newPos.x + instance->position.x);
    instance->position.y = (newPos.y + instance->position.y);
    instance->position.z = (newPos.z + instance->position.z);
}

void func_800480AC(SVECTOR* arg0, SVECTOR* arg1, int arg2) {
    int temp_v1;

    temp_v1 = (arg0->z * arg2) >> 4;
    arg1->x = ((temp_v1 * arg0->x) >> 0x14);
    arg1->y = ((temp_v1 * arg0->y) >> 0x14);
    arg1->z = 0;
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", SCRIPT_InstanceSplineInit);

short SCRIPT_CountFramesInSpline(Instance *instance)
{

    SplineKey *key;
    Spline *spline;
    RSpline *rspline;
    short kf;
    short frames;

    kf = 0;
    frames = 0;

    spline = ScriptGetPosSpline(instance);

    if (spline != NULL)
    {
        for (key = spline->key; kf < spline->numkeys; kf++, key++)
        {
            frames += key->count;
        }
    }
    else
    {

        SplineRotKey *rkey;

        rspline = ScriptGetRotSpline(instance);
        if (rspline != NULL)
        {
            for (rkey = rspline->key; kf < rspline->numkeys; kf++, rkey++)
            {
                frames += rkey->count;
            }
        }
        else
        {

            MultiSpline *multi;
            multi = SCRIPT_GetMultiSpline(instance, 0, 0);

            if (multi != NULL)
            {
                spline = multi->scaling;
                for (key = spline->key; kf < spline->numkeys; kf++, key++)
                {
                    frames += key->count;
                }
            }
        }
    }
    return frames;
}

Spline *ScriptGetPosSpline(Instance *instance)
{
    MultiSpline *multi;

    multi = SCRIPT_GetMultiSpline(instance, NULL, NULL);

    if (multi != NULL)
    {
        return multi->positional;
    }

    return NULL;
}

RSpline *ScriptGetRotSpline(Instance *instance)
{
    MultiSpline *multi;

    multi = SCRIPT_GetMultiSpline(instance, NULL, NULL);

    if (multi != NULL)
    {
        return multi->rotational;
    }

    return NULL;
}

unsigned short SplineGetFrameNumber(Spline*, SplineDef*);
int SCRIPT_GetSplineFrameNumber(Instance* arg0, SplineDef* arg1) {
    if (ScriptGetPosSpline(arg0) != 0) {
        return SplineGetFrameNumber(ScriptGetPosSpline(arg0), arg1);
    } else {
        return SplineGetFrameNumber((Spline*)ScriptGetRotSpline(arg0), arg1);
    }
}

MultiSpline* SCRIPT_GetMultiSpline(Instance *instance, int *isParent, int *isClass)
{
    MultiSpline *multi;

    multi = NULL;

    if (isParent != NULL)
    {
        *isParent = 0;
    }

    if (isClass != NULL)
    {
        *isClass = 0;
    }

    if ((instance != NULL) && (instance->intro != NULL) && (instance->intro->multiSpline != NULL))
    {
        multi = instance->intro->multiSpline;

        if (((instance->flags & 0x100002) == 0x2) && (isParent != NULL))
        {
            *isParent = 1;
        }
    }

    if ((multi == NULL) && (instance->object->modelList[0] != NULL))
    {
        multi = instance->object->modelList[0]->multiSpline;

        if (isClass != NULL)
        {
            *isClass = 1;
        }
    }

    return multi;
}

SplineDef *SCRIPT_GetPosSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass)
{
    SplineDef *splineDef;

    if ((isParent != 0) || (isClass != 0))
    {
        splineDef = (SplineDef *)&instance->_F4[2]; // work0

        return splineDef;
    }

    if (multi == NULL)
    {
        return NULL;
    }

    return &multi->curPositional;
}

SplineDef *SCRIPT_GetRotSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass)
{
    SplineDef *splineDef;

    if ((isParent != 0) || (isClass != 0))
    {
        splineDef = (SplineDef *)&instance->_104; // work2

        return splineDef;
    }

    if (multi == NULL)
    {
        return NULL;
    }

    return &multi->curRotational;
}

SplineDef *SCRIPT_GetScaleSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass)
{
    SplineDef *splineDef;

    if ((isParent != 0) || (isClass != 0))
    {
        splineDef = (SplineDef *)&instance->_10C; // work4

        return splineDef;
    }

    if (multi == NULL)
    {
        return NULL;
    }

    return &multi->curScaling;
}

void SCRIPT_RelativisticSpline(Instance *instance, SVECTOR *point)
{
    SVECTOR pt;       

    if ((instance->intro != NULL) && ((instance->intro->rotation.x != 0) || (instance->intro->rotation.y != 0) || (instance->intro->rotation.z != 0))) 
    {
        MATRIX segMatrix; 
        SVECTOR newPt;  
        SVECTOR localPt; 
        
        pt.x = point->x;
        pt.y = point->y;
        pt.z = point->z;
        
        localPt.x = pt.x;
        localPt.y = pt.y;
        localPt.z = pt.z;
        
        RotMatrix((SVECTOR*)&instance->intro->rotation, &segMatrix);
       
        segMatrix.l[2] = 0;
        segMatrix.l[1] = 0;
        segMatrix.l[0] = 0;
       
        newPt.x = ((localPt.x * segMatrix.m[0][0]) >> 12) + ((localPt.y * segMatrix.m[0][1]) >> 12) + ((localPt.z * segMatrix.m[0][2]) >> 12);
        newPt.y = ((localPt.x * segMatrix.m[1][0]) >> 12) + ((localPt.y * segMatrix.m[1][1]) >> 12) + ((localPt.z * segMatrix.m[1][2]) >> 12);
        newPt.z = ((localPt.x * segMatrix.m[2][0]) >> 12) + ((localPt.y * segMatrix.m[2][1]) >> 12) + ((localPt.z * segMatrix.m[2][2]) >> 12);


        instance->position.x = newPt.x + instance->initialPos.x;
        instance->position.y = newPt.y + instance->initialPos.y;
        instance->position.z = newPt.z + instance->initialPos.z;
    }
    else 
    {
        instance->position.x = instance->initialPos.x + point->x;
        instance->position.y = instance->initialPos.y + point->y;
        instance->position.z = instance->initialPos.z + point->z;
    }
}

void SCRIPT_InstanceSplineSet(Instance* instance, short frameNum, SplineDef* splineDef, SplineDef* rsplineDef, SplineDef* ssplineDef) {
    Spline* spline;
    RSpline* rspline;
    Spline* sspline;
    MultiSpline* multi;
    int isClass;
    int isParent;
    SVECTOR point;

    multi = SCRIPT_GetMultiSpline(instance, &isParent, &isClass);
    if (multi != NULL) {
        if (frameNum == -1) {
            frameNum = SCRIPT_CountFramesInSpline(instance);
        }
        if ((isParent != 0) || (isClass != 0) || ((splineDef == 0) && (rsplineDef == 0) && (ssplineDef == 0))) {
            splineDef = SCRIPT_GetPosSplineDef(instance, multi, isParent, isClass);
            rsplineDef = SCRIPT_GetRotSplineDef(instance, multi, isParent, isClass);
            ssplineDef = SCRIPT_GetScaleSplineDef(instance, multi, isParent, isClass);
        }
        
        spline = multi->positional;
        rspline = multi->rotational;
        sspline = multi->scaling;
        
        if ((splineDef != 0) && (spline != 0)) {
            SplineSetDef2FrameNumber(spline, splineDef, frameNum);
            SplineGetData(spline, splineDef, &point);
            
            if (isClass != 0) {
                SCRIPT_RelativisticSpline(instance, &point);
            } else {
                instance->position.x = point.x;
                instance->position.y = point.y;
                instance->position.z = point.z;
            }
        }
        
        if ((rsplineDef != 0) && (rspline != 0)) {
            SplineSetDef2FrameNumber((Spline*)rspline, rsplineDef, frameNum);
            SplineGetData((Spline*)rspline, rsplineDef, &instance->rotation);
        }
        
        if ((ssplineDef != 0) && (sspline != 0)) {
            
            SVECTOR scale;
            
            SplineSetDef2FrameNumber(sspline, ssplineDef, frameNum);
            SplineGetData(sspline, ssplineDef, &scale);
            instance->scale.x = scale.x;
            instance->scale.y = scale.z;
            instance->scale.z = scale.y;
        }
    }
}

int SCRIPT_SplineProcess(Instance* instance, MultiSpline* multi, SplineDef* splineDef, SplineDef* rsplineDef, SplineDef* ssplineDef, int direction, int isClass) {
    SVECTOR rot;
    SVECTOR temp;
    Spline* sspline;
    RSpline* rspline;
    Spline* spline;
    SVECTOR* point;
    union
    {
        G2Quat q;
        SVECTOR v;
    } data;
    int retVal;

    retVal = -1;
    
    spline = multi->positional;
    sspline = multi->scaling;
    rspline = multi->rotational;
    
    point = NULL;
    
    if (sspline != 0) {
        if (direction > 0) {
            point = SplineGetNextPoint(sspline, ssplineDef);
        } else if (direction < 0) {
            point = SplineGetPreviousPoint(sspline, ssplineDef);
        } else if (SplineGetData(sspline, ssplineDef, &temp) != 0) {
            point = &temp;
        }
        if (point != NULL) {
            retVal = 0;
            instance->scale.x = point->x;
            instance->scale.y = point->z;
            instance->scale.z = point->y;
        } else {
            retVal = 1;
        }
    }
    
    if (rspline != 0) {
        retVal = 0;
        if (direction > 0) {
            retVal = SplineGetOffsetNext((Spline*)rspline, rsplineDef) == 0;
        } else if ((direction < 0) && (SplineGetOffsetPrev(rspline, rsplineDef) == 0)) {
            retVal = 1;
        }
        
        if (retVal == 0) {
            if (instance->flags & 1) {
                if (SplineGetQuatData((Spline*)rspline, rsplineDef, &data.q) != 0) {
                    G2Quat_ToMatrix_S(&((int*)multi)[0x20/4], &data.q); // cutRotMatrix, G2Quat_ToMatrix_S?
                } else {
                    retVal = 1;
                }
            } else if (SplineGetData((Spline*)rspline, rsplineDef, &rot) != 0) {
                instance->rotation.x = rot.x;
                instance->rotation.y = rot.y;
                instance->rotation.z = rot.z;
            } else {
                retVal = 1;
            }
        }
    }
    
    if (spline != 0) {
        
        if (direction > 0) {
            point = (SVECTOR*)SplineGetNextPoint(spline, splineDef);
        } else if (direction < 0) {
            point = (SVECTOR*)SplineGetPreviousPoint(spline, splineDef);
        } else if (SplineGetData(spline, splineDef, &data.v) != 0) {
            point = &data.v;
        }
        
        if (point != NULL) {
            retVal = 0;
            
            if (isClass != 0) {
                SCRIPT_RelativisticSpline(instance, point);
            }
            else
            {
                instance->position.x = point->x;
                instance->position.y = point->y;
                instance->position.z = point->z;
            }
        }
        else
        {
            retVal = 1;
        }

    }
    return retVal;
}

int SCRIPT_InstanceSplineProcess(Instance* instance, SplineDef* splineDef, SplineDef* rsplineDef, SplineDef* ssplineDef, int direction) {
    MultiSpline* multi;
    int isParent;
    int isClass;

    multi = SCRIPT_GetMultiSpline(instance, &isParent, &isClass);
    if (multi != 0) {
        if ((isParent != 0 || isClass != 0) || (splineDef == NULL && rsplineDef == NULL && ssplineDef == NULL)) {
            splineDef = SCRIPT_GetPosSplineDef(instance, multi, isParent, isClass);
            rsplineDef = SCRIPT_GetRotSplineDef(instance, multi, isParent, isClass);
            ssplineDef = SCRIPT_GetScaleSplineDef(instance, multi, isParent, isClass);
        }
    
        return SCRIPT_SplineProcess(instance, multi, splineDef, rsplineDef, ssplineDef, direction, isClass);
    }
    return -1;
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048DE4);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80048E7C);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049224);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049250);

void func_80049330(short* arg0)
{
    arg0[0xC0 / 2] = arg0[0x4C / 2];
}

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049340);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_800494C8);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049684);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049810);

INCLUDE_ASM("asm/nonmatchings/_42bd0", func_80049A58);

INCLUDE_RODATA("asm/nonmatchings/_42bd0", D_8007E720);

INCLUDE_RODATA("asm/nonmatchings/_42bd0", D_8007E724);

const ROTATION D_8007E72C = {0, 0, 0, 0};

INCLUDE_RODATA("asm/nonmatchings/_42bd0", D_8007E734);