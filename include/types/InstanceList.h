#ifndef TINSTANCELIST_H_
#define TINSTANCELIST_H_

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