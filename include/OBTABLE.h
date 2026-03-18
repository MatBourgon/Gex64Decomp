#ifndef OBTABLE_H_
#define OBTABLE_H_

#include "types/Instance.h"
#include "types/Object.h"

void OBTABLE_InstanceInit(Instance* instance);

void OBTABLE_GetInstanceCollideFunc(Instance* instance);

void OBTABLE_GetInstanceProcessFunc(Instance* instance);

void OBTABLE_ClearObjectReferences(void);

Object* OBTABLE_FindObject(char* name);

#endif