#ifndef TLEVEL_H_
#define TLEVEL_H_

#include "types/Intro.h"
#include "types/BGObject.h"

typedef struct
{
    void* segmentAddress;
    char _04[0x1C];
    int numBGObjects; // 20
    BGObject* bgObjectList; // 24
    int _28; // 28
    SVECTOR spawnPosition; // 2C, 2E, 30, 32
    int collectibleCountA; // 34
    int collectibleCountB; // 38
    int collectibleCountC; // 3C
    void* objectNameList; // 40
    int _44;
    int _48;
    int _4C;
    short fogFar;
    short fogNear;
    int _54;
    int _58;
    int _5C;
    int _60;
    int _64;
    int _68;
    int _6C;
    int deathZ; // 70
    int flags; // 74
    void* startSignal; // 78
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