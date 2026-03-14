#ifndef INSTANCE_H_
#define INSTANCE_H_

#include "Intro.h"
#include "Object.h"
#include "LightInstance.h"
#include "NodeType.h"

typedef struct Instance_s
{
    NodeType node;
    struct Instance_s* next;
    struct Instance_s* prev;
    int flags; // 10
    int flags2; // 14
    Object* object; // 0x18
    Intro* intro; // 0x1C
    int _20[4]; // _20 : Data?, _24 : IntroData?
    short _30[8];
    short _40[4];
    SVECTOR position;
    char _4E;
    char _4F;
    short _50[8];
    short _60[8];
    int _70[4];
    short _80[8];
    short _90[4];
    LightInstance* shadow0;
    LightInstance* shadow1;
    int _A0;
    int _A4;
    int _A8;
    void (*processFunc)();
    void (*collideFunc)();
    void* _B4;
    int _B8;
    int _BC;
    short _C0[8];
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