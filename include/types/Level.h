#ifndef TLEVEL_H_
#define TLEVEL_H_

#include "Intro.h"

typedef struct
{
    char _00[0x40];
    void* objectNameList; // 0x40
    char _44[0x38];
    int numIntros; // 7C
    Intro* introList; // 80
    char _74[0x64];
} Level;

#endif