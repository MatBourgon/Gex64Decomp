#ifndef TOBJECTFUNCTIONS_H_
#define TOBJECTFUNCTIONS_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

typedef void(*objFunction)(Instance*, GameTracker*);
extern void GenericInit(Instance*, GameTracker*);
extern void GenericCollide(Instance*, GameTracker*);
extern void GenericProcess(Instance*, GameTracker*);

typedef struct
{
    char* name;
    char* level;
    objFunction init;
    objFunction process;
    objFunction collide;
} OBTableEntry;

extern OBTableEntry ObjectFunctionTable[];

typedef struct
{
    char* objectName;
    void* object;
} ObjectAccess;

extern ObjectAccess objectAccess[];

#endif