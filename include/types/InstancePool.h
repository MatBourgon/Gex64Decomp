#ifndef INSTANCEPOOL_H_
#define INSTANCEPOOL_H_

typedef struct
{
    int numFreeInstances;
    Instance instance[90];
    Instance* first_free;
} InstancePool;

#endif