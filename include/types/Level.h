#ifndef LEVEL_H_
#define LEVEL_H_

#include "Intro.h"

typedef struct
{
    char _00[0x40];
    void* objectNameList;
    char _44[0x38];
    int numIntros;
    Intro* introList;
    char _74[0x64];
} Level;

#endif