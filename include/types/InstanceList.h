#ifndef INSTANCELIST_H_
#define INSTANCELIST_H_

#include "Instance.h"
#include "InstancePool.h"

typedef struct
{
    int numInstances;
    Instance* first;
    InstancePool* pool;
    NodeType group[32];
} InstanceList;

#endif