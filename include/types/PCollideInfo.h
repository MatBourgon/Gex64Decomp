#ifndef TPCOLLIDEINFO_H_
#define TPCOLLIDEINFO_H_

#include "types/Instance.h"

typedef struct
{
    // offset: 0x0000
    int type;
    // offset: 0x0004
    void *prim;
    // offset: 0x0008 (4 bytes)
    Instance *inst;
    // offset: 0x000C (8 bytes)
    SVECTOR wNormal;
    // offset: 0x0014 (4 bytes)
    SVECTOR *newPoint;
    // offset: 0x0018 (4 bytes)
    SVECTOR *oldPoint;
    // offset: 0x001C (8 bytes)
    SVECTOR cldPoint;
    // offset: 0x0024
    long collideType;
    // offset: 0x0028 (4 bytes)
    Instance *instance;
} PCollideInfo;

#endif