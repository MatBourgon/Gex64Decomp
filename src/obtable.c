#include "common.h"

#include "types/G2String.h"

#include "types/obtable.h"
#include "OBTABLE.h"

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

    id = instance->object->id;
    
    if (id < 0) {
        GenericInit(instance, gameTracker8);
    } else if (ObjectFunctionTable[id].init != NULL) {
        ObjectFunctionTable[id].init(instance, gameTracker8);
    }

    instance->flags2 |= 0x200000;
    if (!(instance->flags & 0x100000)) {
        SCRIPT_InstanceSplineInit(instance, gameTracker8);
    }
}


void OBTABLE_GetInstanceCollideFunc(Instance* instance)
{
    if (instance->object->id >= 0)
    {
        instance->collideFunc = ObjectFunctionTable[instance->object->id].collide;
    }
    else
    {
        instance->collideFunc = GenericCollide;
    }
}


void OBTABLE_GetInstanceProcessFunc(Instance* instance)
{
    if (instance->object->id >= 0)
    {
        instance->processFunc = ObjectFunctionTable[instance->object->id].process;
    }
    else
    {
        instance->processFunc = GenericProcess;
    }
}

INCLUDE_ASM("asm/nonmatchings/obtable", func_8003EBF4);

void OBTABLE_ClearObjectReferences(void) {
    int i;

    for (i = 0; objectAccess[i].objectName != NULL; ++i) {
        objectAccess[i].object = NULL;
    }
}

Object* OBTABLE_FindObject(char* name) {
    Object** listStart;
    Object** objectPtr;

    if (name != NULL) {
        objectPtr = (Object**)((int****)gameTracker8)[1][0x10];
        if ((void*)*objectPtr != (void*)objectPtr) {
            for(listStart = objectPtr; (void*)*objectPtr != (void*)listStart; objectPtr++)
            {
                if (*objectPtr != NULL && G2String_Compare_EQ(name, (*objectPtr)->name))
                {
                    return (Object*)*objectPtr;
                }
            }
        }
    }
    return NULL;
}

