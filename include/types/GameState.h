#ifndef GAMESTATE_H_
#define GAMESTATE_H_

typedef unsigned char byte;
typedef unsigned int uint;
typedef struct
{
    int     _0000;
    int*   _0004;
    char    _0008[0x4BEC];
    char    _4BF4[0x14];
    uint    _4C08;
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
} GameState;

extern GameState* gpGameState4;
extern GameState* gpGameState8;
extern GameState gGameState;

#endif
