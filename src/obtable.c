#include "common.h"

#include "types/GameTracker.h"

#include "types/G2String.h"

void func_8003EA60(void) {
}

void func_8003EA68(void) {
}

void func_8003EA70(void) {
}

void func_8003EA78(void) {
}

void func_8003EA80(void) {
}

void func_8003EA88(void) {
}

void func_8003EA90(void) {
}

void func_8003EA98(void) {
}

void func_8003EAA0(void) {
}

void func_8003EAA8(void) {
}

typedef void(*objFunction)(void*, void*);

typedef struct
{
    char* name;
    char* level;
    objFunction init;
    objFunction process;
    objFunction collide;
} OBTableEntry;

extern OBTableEntry ObjectFunctionTable[];

void OBTABLE_InstanceInit(void* instance) {
    int id;

    id = ((short**)instance)[0x18/4][2];
    
    if (id < 0) {
        GenericInit(instance, gameTracker);
    } else if (ObjectFunctionTable[id].init != NULL) {
        ObjectFunctionTable[id].init(instance, gameTracker);
    }

    ((int*)instance)[0x14/4] |= 0x200000;
    if (!(((int*)instance)[0x10/4] & 0x100000)) {
        SCRIPT_InstanceSplineInit(instance, gameTracker);
    }
}

extern void GenericCollide(void*, void*);

void OBTABLE_GetInstanceCollideFunc(void* instance)
{
    int id;

    id = ((short**)instance)[0x18/4][2];

    if (id >= 0)
    {
        ((objFunction*)instance)[0xB0/4] = ObjectFunctionTable[id].collide;
    }
    else
    {
        ((objFunction*)instance)[0xB0/4] = GenericCollide;
    }
}

extern void GenericProcess(void*, void*);

void OBTABLE_GetInstanceProcessFunc(void* instance)
{
    int id;

    id = ((short**)instance)[0x18/4][2];

    if (id >= 0)
    {
        ((objFunction*)instance)[0xAC/4] = ObjectFunctionTable[id].process;
    }
    else
    {
        ((objFunction*)instance)[0xAC/4] = GenericProcess;
    }
}

INCLUDE_ASM("asm/nonmatchings/obtable", func_8003EBF4);

typedef struct
{
    char* objectName;
    void* object;
} ObjectAccess;

extern ObjectAccess objectAccess[];

void OBTABLE_ClearObjectReferences(void) {
    int i;

    for (i = 0; objectAccess[i].objectName != NULL; ++i) {
        objectAccess[i].object = NULL;
    }
}

void* OBTABLE_FindObject(char* arg0) {
    int** temp_t0;
    int** var_a2;

    if (arg0 != NULL) {
        var_a2 = ((int****)gameTracker)[1][0x10];
        if (*var_a2 != (int*)var_a2) {
            for(temp_t0 = var_a2; *var_a2 != (int*)temp_t0; var_a2++)
            {
                if (*var_a2 != NULL && G2String_Compare_EQ(arg0, (*var_a2)[0x24/4]))
                {
                    return *var_a2;
                }
            }
        }
    }
    return NULL;
}

