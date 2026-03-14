#ifndef INSTANCEPOOL_H_
#define INSTANCEPOOL_H_

typedef struct
{
    int numFreeInstances;
    unsigned char _[0x66A8]; // Instance[X], unknown total size
    Instance* first_free;
} InstancePool;

#endif