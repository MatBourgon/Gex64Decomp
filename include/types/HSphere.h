#ifndef THSPHERE_H_
#define THSPHERE_H_

#include "types/Vector.h"

// size: 0x14
typedef struct _HSphere
{
    // offset: 0x0000
    long attr;
    // offset: 0x0004
    unsigned char id;
    // offset: 0x0005
    unsigned char rank;
    // offset: 0x0006
    short pad;
    // offset: 0x0008 (6 bytes)
    SVECTOR position;
    // offset: 0x000E
    unsigned short radius;
    // offset: 0x0010
    unsigned long radiusSquared;
} HSphere;

#endif