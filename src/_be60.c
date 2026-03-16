#include "common.h"

#include "types/GameTracker.h"
#include "types/Instance.h"
#include "types/intro/TVEnd.h"
#include "types/G2String.h"

extern int D_800785CC[];
extern const char D_8007B944[];

INCLUDE_ASM("asm/nonmatchings/_be60", func_8000B260);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B8F0);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B8FC);

INCLUDE_ASM("asm/nonmatchings/_be60", func_8000B3B4);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B920);

INCLUDE_ASM("asm/nonmatchings/_be60", func_8000B778);

void func_8000B968(Instance* instance, GameTracker* gameTracker) {
    Object* object;

    object = NULL;
    
    *(short*)&instance->_110 = -0x7D00;
    instance->flags |= 0x80;
    instance->_F4[2] &= ~1;
    
    if (instance->parent != 0) {
        instance->flags |= 0x100000;
    }
    
    *(int*)&instance->_30[4] = 0;
    
    instance->flags |= 0x40;
    
    if (*(int*)&instance->_108 == 0)
        object = (Object*)OBTABLE_FindObject(gameTracker8->_0004[0x94/4]); // CollectibleCountA
    else if (*(int*)&instance->_108 == 1)
        object = (Object*)OBTABLE_FindObject(gameTracker8->_0004[0x98/4]); // CollectibleCountB
    else if (*(int*)&instance->_108 == 2)
        object = (Object*)OBTABLE_FindObject(gameTracker8->_0004[0x9C/4]); // CollectibleCountC
    
    if (object != NULL) {
        instance->object->modelList = object->modelList;
    }
}

INCLUDE_ASM("asm/nonmatchings/_be60", func_8000BA70);

void common_cola_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    func_8000BA70(instance, gameTracker);
}

INCLUDE_ASM("asm/nonmatchings/_be60", func_8000BB88);

void common_cola_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    *(int*)&instance->_108 = 0;
    func_8000B968(instance, gameTracker);
}

void common_cola_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    func_8000BB88(instance, gameTracker);
}

void common_colb_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    *(int*)&instance->_108 = 1;
    func_8000B968(instance, gameTracker);
}

void common_colb_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    func_8000BB88(instance, gameTracker);
}

void common_colb_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    func_8000BA70(instance, gameTracker);
}

void common_colc_OnCreate(Instance* instance, GameTracker* gameTracker)
{
    *(int*)&instance->_108 = 2;
    func_8000B968(instance, gameTracker);
}

void common_colc_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    func_8000BB88(instance, gameTracker);
}

void common_colc_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    func_8000BA70(instance, gameTracker);
}

void common_cold_OnCreate(Instance* instance, GameTracker* gameTracker) {
    int* temp_a2;
    int* temp_a3;

    temp_a2 = gameTracker->_0004;
    temp_a3 = &instance->_F4[2];
    if (((int*)gameTracker)[0x4C00/4] >= temp_a2[0x38/4]) {  // CollectibleCType*
        *(int*)&instance->_108 = 2;
    } else if (((int*)gameTracker)[0x4BFC/4] >= temp_a2[0x34/4]) { // CollectibleBType*
        *(int*)&instance->_108 = 1;
    } else {
        *(int*)&instance->_108 = 0;
    }
    if ((((unsigned char*)gameTracker)[0x4CA1] - 0xE) < 7U) {
        temp_a3[3] = 0;
    }
    func_8000B968(instance, gameTracker);
}

void common_cold_OnUpdate(Instance* instance, GameTracker* gameTracker)
{
    func_8000BB88(instance, gameTracker);
}

void common_cold_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    func_8000BA70(instance, gameTracker);
}

void common_derez_OnCreate(Instance* instance, GameTracker* gameTracker) {
    instance->flags |= 0x100080;
    instance->_56 = 0;
}

INCLUDE_ASM("asm/nonmatchings/_be60", common_derez_OnUpdate);

void common_derez_OnCollide(Instance* instance, GameTracker* gameTracker) {
}

Instance* CreateRemRedInstance(Instance* instance, Object* object) {
    Instance* newInstance;
    instance->position.x += (func_8003A4E0(instance->intro->rotation.z) << 0x10) >> 0x13;
    instance->position.y += -((func_8003A6AC(instance->intro->rotation.z) << 0x10) >> 7) >> 0xC;
    instance->position.z += 0x100;
    newInstance = (Instance*)INSTANCE_BirthObject(instance, object);
    instance->position.x -= (func_8003A4E0(instance->intro->rotation.z) << 0x10) >> 0x13;
    instance->position.y -= -((func_8003A6AC(instance->intro->rotation.z) << 0x10) >> 7) >> 0xC;
    instance->position.z -= 0x100;
    return newInstance;
}

void common_tvend_OnCreate(Instance* instance, GameTracker* gameTracker) {
    Object* oEtvbtn;
    Object* oRemred;
    Instance* iRemred;
    Instance* iEtvbtn;
    TVEndIntro* intro;

    intro = (TVEndIntro*)instance->introData;
    
    if (!(instance->flags & 0x20000)) {
        oEtvbtn = (Object*)OBTABLE_FindObject("etvbutn_");
        oRemred = (Object*)OBTABLE_FindObject(D_8007B944);
        if (oEtvbtn != 0) {
            iEtvbtn = (Instance*)INSTANCE_BirthObject(instance, oEtvbtn);
            instance->_F4[2] = (int)iEtvbtn;
            iEtvbtn->flags |= 0x400;
        }
        instance->_56 = 1;
        intro->condition = 1;
        if ((intro->_04 != 0) && ((D_800785CC[intro->_04]) == 0)) {
            if (!(((&((unsigned char*)gameTracker)[((unsigned char*)gameTracker)[0x4CA1]])[0x4C6E] >> intro->remoteId) & 1)) {
                instance->_56 = 0;
            }
            intro->condition = 0;
        }
        if ((oRemred != 0) && !(instance->intro->flags & 0x100)) {
            if (intro->condition != 0) {
                instance->_100 = (int)CreateRemRedInstance(instance, oRemred);
                ((Instance*)instance->_100)->flags |= 0x400;
                if (((&((unsigned char*)gameTracker)[((unsigned char*)gameTracker)[0x4CA1]])[0x4C6E] >> intro->remoteId) & 1) {
                    ((short**)instance)[0x100/4][0xC2/2] = 1;
                }
            } else {
                instance->_100 = NULL;
            }
        }
        instance->flags |= 0x10000;
        instance->_F4[1] = 0;
        instance->flags |= 0x80;
    }
    else
    {
        iEtvbtn = (Instance*)instance->_F4[2];
        iRemred = (Instance*)instance->_100;
        if (iEtvbtn != NULL) {
            (iEtvbtn)->flags &= ~0x400;
            func_8002E350(iEtvbtn);
        }
        if (iRemred != NULL) {
            iRemred->flags &= ~0x400;
            func_8002E350(iRemred);
        }
    }
}

typedef struct
{
    short rotScale[9];
    short scaleFlag;
    short _[6];
} common_tvend_OnUpdate_struct; // Some kind of matrix maybe?
extern common_tvend_OnUpdate_struct D_8007B950;

void common_tvend_OnUpdate(Instance* instance, Object* gameTracker) {
    common_tvend_OnUpdate_struct sp18;
    int temp_a0;
    Object* oRemred;
    Instance* iRemred2;
    TVEndIntro* intro;
    Instance* iRemred;

    intro = instance->introData;
    if ((intro->condition == 0) && (D_800785CC[intro->_04] != 0)) {
        instance->_56 = 1;
        if ((instance->_100 == NULL) && (D_800785CC[intro->_04] >= 2)) {
            oRemred = (Object*)OBTABLE_FindObject(&D_8007B944);
            if (oRemred != 0) {
                iRemred = (Instance*)CreateRemRedInstance(instance, oRemred);
                instance->_100 = (int)iRemred;
                ((Instance*)instance->_100)->oldRotation.x = 1;
                ((Instance*)instance->_100)->oldRotation.y = 1;
                ((Instance*)instance->_100)->oldRotation.z = 1;
                instance->_F4[1] = 3;
                intro->condition = 1;
                (*(int*)&instance->_10C) = 0x10;
                if (((&((unsigned char*)gameTracker)[((unsigned char*)gameTracker)[0x4CA1]])[0x4C6E] >> intro->remoteId) & 1) {
                    ((Instance*)instance->_100)->_C0[1] = 1;
                }
                func_80050508(gameTracker8->_000C, 0x7A, -0x190, 0x64, 0x5DC);
            }
        }
    }
    if ((instance->_F4[1] == 3))
    {
        iRemred2 = (Instance*)instance->_100;
        sp18 = D_8007B950;
        
        if ((iRemred2 != NULL)) {
            temp_a0 = (*(int*)&instance->_10C) - 1;
            (*(int*)&instance->_10C) = temp_a0;
            if (temp_a0 <= 0) {
                instance->_F4[1] = 0;
            }
            else if (temp_a0 < 0x10) {
                iRemred2->oldRotation.x = ((short*)&sp18)[0x10 - (*(int*)&instance->_10C)];
                iRemred2->oldRotation.y = ((short*)&sp18)[0x10 - (*(int*)&instance->_10C)];
                iRemred2->oldRotation.z = ((short*)&sp18)[0x10 - (*(int*)&instance->_10C)];
            }
        }
    }
}


typedef struct
{
    short x;
} ETVButnIntro;

extern char D_8006FC69;
extern int D_800EB8A0;
extern char D_8007B970[]; // "tvend___"
int func_8000C8E8(Instance* instance, GameTracker* gameTracker) {
    ETVButnIntro* intro;
    int var_a1;
    unsigned char temp_v1;
    unsigned char** temp_a0;
    char* temp_a0_3;
    int* temp_a0_4;
    Instance* temp_s2;
    int* temp_s4;

    intro = instance->introData;
    temp_a0 = (unsigned char**)instance->_70[2];
    var_a1 = 0;
    if (((((unsigned char*)gameTracker))[0x4CA1] == 2) || ((((short*)temp_a0)[3] != 1))) {
        temp_s2 = (Instance*)instance->parent->_100;
        if (temp_a0[2][2] == 1 && temp_s2 != NULL && !(instance->parent->intro->flags & 0x100) && instance->parent->_F4[1] == 0) {
            temp_s4 = ((int**)gameTracker->_000C)[0x20/4];
            func_80018B60(gameTracker->_000C, D_800EB8A0, temp_s2->position.x, temp_s2->position.y, temp_s2->position.z + 0x40);
            func_80050508(instance, 3, -0x64, 0x7F, 0x5DC);
            temp_a0_3 = instance->parent->object->parentName;
            if (G2String_Compare_EQ(temp_a0_3, D_8007B970)) {
                INSTANCE_KillInstance(temp_s2);
            }
            temp_v1 = (((unsigned char*)gameTracker))[0x4CA1];
            if (temp_v1 < 0x1FU) {
                (&((char*)gameTracker)[temp_v1])[0x4C6E] |= (1 << intro->x);
                (((short*)gameTracker))[0x4DA2/2] = intro->x;
                D_8006FC69 = 1;
            }
            instance->parent->_F4[1] = 1;
            instance->_C0[1] = 1;
            temp_a0_4 = (int*)gameTracker->_000C;
            temp_a0_4[0xFC/4] |= 0x02000000;
            temp_s4[0x178/4] = (int)instance->parent;
            (((int*)gameTracker))[0x4C08/4] |= 0x80;
            var_a1 = 1;
        }
    }
    else
        return 1;
    return var_a1;
}

void common_etvbutn_OnCollide(Instance* instance, GameTracker* gameTracker)
{
    func_8000C8E8(instance, gameTracker);
}

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B944);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B950);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B970);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B974);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B97C);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B988);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B998);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B9AC);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B9C4);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B9DC);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007B9F4);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BA00);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BA04);

INCLUDE_RODATA("asm/nonmatchings/_be60", jtbl_8007BA18);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BA4C);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BA68);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BA74);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BA80);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BA90);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BAA8);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BAC0);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BADC);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BAF4);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BB0C);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BB20);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BB3C);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BB58);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BB74);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BB90);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BBAC);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BBC8);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BBE0);

INCLUDE_RODATA("asm/nonmatchings/_be60", jtbl_8007BBF8);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BC24);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BC3C);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BC50);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BC5C);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BC70);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BC88);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCA4);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCA8);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCAC);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCB0);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCC0);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCD8);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCDC);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCE4);

INCLUDE_RODATA("asm/nonmatchings/_be60", D_8007BCE8);
