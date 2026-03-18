#ifndef TGAMETRACKER_H_
#define TGAMETRACKER_H_

#include "types/InstanceList.h"

typedef unsigned char byte;
typedef unsigned int uint;
typedef struct
{
    int     _0000;
    int*   _0004; // Might might level*, see collectible code
    int     _0008; // Might be player instance*
    int     _000C;
    InstanceList *instanceList;
    char    _0014[0x4BE0];
    char    _4BF4[0x14];
    uint    gameFlags;
    int     _4C0C;
    short   _4C10;
    char    _4B12[0x5C];
    byte    red_remote_bits[14];
    char    _4C7C[0x18];
    uint    silver_remote_bits;
    uint    gold_remote_bits;
    byte    _4C9C[5];
    byte    levelIdToLoad;
    char    _4CA2[3];
    char    _4CA5[0x1D];
    short   _4CC2;
    char    _4CC4[0x10];
    int     maybeSelectedHintIndex;
} GameTracker;

extern GameTracker* gameTracker4;
extern GameTracker* gameTracker8;
extern GameTracker gameTrackerX;

#endif
