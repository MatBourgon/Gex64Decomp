#ifndef TLEVEL_H_
#define TLEVEL_H_

#include "Intro.h"

typedef struct
{
    void* segmentAddress;
    char _04[0x28];
    SVECTOR spawnPosition;
    int collectibleCountA;
    int collectibleCountB;
    int collectibleCountC;
    void* objectNameList; // 0x40
    char _44[0x30];
    int deathZ;
    void* startSignal;
    int numIntros; // 7C
    Intro* introList; // 80
    char _84[0x8];
    int _8C;
    const char* levelType;
    const char* collectibleTypeA; // 94
    const char* collectibleTypeB; // 98
    const char* collectibleTypeC; // 9C
} Level;

#endif