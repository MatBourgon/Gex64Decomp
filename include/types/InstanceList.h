#ifndef INSTANCELIST_H_
#define INSTANCELIST_H_

#include "types/Instance.h"
#include "types/InstancePool.h"

typedef struct
{
    int numInstances;
    Instance* first;
    InstancePool* pool;
} InstanceList;

#endif