#ifndef INSTANCE_H_
#define INSTANCE_H_

#include "types/InstanceList.h"
#include "types/Instance.h"

void INSTANCE_InitInstanceList(InstanceList *list, InstancePool *pool);

Instance* INSTANCE_NewInstance(InstanceList* list);

int INSTANCE_InstanceGroupNumber(Instance* instance);

void INSTANCE_InsertInstanceGroup(InstanceList* list, Instance* instance);

void func_8002CD1C(InstanceList* list, Instance* instance);

void func_8002CD3C(InstanceList* list, Instance* instance);

void INSTANCE_ReallyRemoveInstance(InstanceList* list, Instance* instance, int reset);

void INSTANCE_CleanUpInstanceList(InstanceList* list, int reset);

void* INSTANCE_BirthObjectFromIntro(Intro* intro);

void INSTANCE_ProcessFunctions(InstanceList* list);

Instance* INSTANCE_BirthObject(Instance* parent, Object* object);

void INSTANCE_DefaultInit(Instance* instance, Object* object);

void func_8002E350(Instance* instance);

void INSTANCE_KillInstance(Instance* instance);

void INSTANCE_PlainDeath(Instance* instance, int arg1, int arg2, int arg3);
void INSTANCE_InsertInstanceWithFlagsCleared(Instance* instance, int flags);

#endif