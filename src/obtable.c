#include "common.h"

#include "types/GameTracker.h"

#include "types/G2String.h"

#include "types/obtable.h"

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

void OBTABLE_InstanceInit(Instance* instance) {
    int id;

    id = ((short**)instance)[0x18/4][2];
    
    if (id < 0) {
        GenericInit(instance, gameTracker8);
    } else if (ObjectFunctionTable[id].init != NULL) {
        ObjectFunctionTable[id].init(instance, gameTracker8);
    }

    ((int*)instance)[0x14/4] |= 0x200000;
    if (!(((int*)instance)[0x10/4] & 0x100000)) {
        SCRIPT_InstanceSplineInit(instance, gameTracker8);
    }
}


void OBTABLE_GetInstanceCollideFunc(Instance* instance)
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


void OBTABLE_GetInstanceProcessFunc(Instance* instance)
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
        var_a2 = ((int****)gameTracker8)[1][0x10];
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

