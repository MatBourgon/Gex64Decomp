#ifndef TINSTANCEPOOL_H_
#define TINSTANCEPOOL_H_

#include "types/Instance.h"

typedef struct
{
    int numFreeInstances;
    Instance instance[90];
    Instance* first_free;
} InstancePool;

#endif