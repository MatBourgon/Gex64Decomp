#ifndef TINSTANCE_H_
#define TINSTANCE_H_

#include "Intro.h"
#include "Object.h"
#include "LightInstance.h"
#include "NodeType.h"
#include "Rotation.h"

typedef struct Instance_s
{
    NodeType node; // 00 (prev), 04 (next)
    struct Instance_s* next; // 08
    struct Instance_s* prev; // 0C
    int flags; // 10
    int flags2; // 14
    Object* object; // 18
    Intro* intro; // 1C
    void* data; // 20
    void* introData; // 24
    struct Instance_s* parent; // 28
    void* _2C;
    short _30[8];
    short _40[4];
    SVECTOR position; // 48, 4A, 4C
    unsigned char _4E;
    char lightGroup;
    SVECTOR oldPos; // 50, 52, 54
    short _56;
    SVECTOR initialPos; // 58, 5A, 5C
    short _5E;
    ROTATION rotation; // 60, 62, 64, 66
    SVector scale; // 68, 6A, 6C, 6E
    int _70[4];
    short _80[2];
    SVector wNormal;
    SVECTOR offset;
    short _92;
    short _94[2];
    LightInstance* shadow0; // 98
    LightInstance* shadow1; // 9C
    int _A0;
    int _A4;
    int _A8;
    void (*processFunc)(void*,void*);
    void (*collideFunc)(void*,void*);
    void* _B4;
    int _B8;
    SVECTOR shadowPosition;
    short currentModel;
    short _C0[6];
    int _D0[4];
    int _E0[4];
    short _F0[2];
    int _F4[3];
    int _100;
    int _104;
    char _108;
    char _109;
    char _10A;
    char _10B;
    char _10C;
    char _10D;
    char _10E;
    char _10F;
    char _110;
    char _111;
    unsigned char _112;
    char _113;
    char _114;
    unsigned char _115;
    char _116;
    char _117;
    int _118;
    int _11C;
    int _120;
} Instance; // Should be size accurate now

extern Instance* PlayerInstance;

#endif