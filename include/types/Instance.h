#ifndef TINSTANCE_H_
#define TINSTANCE_H_

#include "Intro.h"
#include "Object.h"
#include "LightInstance.h"
#include "NodeType.h"
#include "Rotation.h"
#include "Matrix.h"
#include "BSPTree.h"

typedef void (*AdditionalDrawFunc)(void*, struct Instance_s*, void* /*unused*/, void* /*unused*/, void* /*unused*/);

struct GameTracker_s;

#define WORK_AS_PTR(Type, Object) ((Type*)&Object)
#define WORK_AS_IDX(Type, Object, Index) (((Type*)&Object)[Index])
#define WORK_AS(Type, Object) (*(Type*)&Object)

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
    MATRIX* matrix; // 2C
    MATRIX* oldMatrix; // 30
    short _34[6];
    short _40[4];
    SVECTOR position; // 48, 4A, 4C
    unsigned char currentModelAnim; // 4E
    char lightGroup; // 4F
    SVECTOR oldPos; // 50, 52, 54
    short currentTextureAnimFrame; // 56
    SVECTOR initialPos; // 58, 5A, 5C
    short currentAnimFrame; // 5E
    ROTATION rotation; // 60, 62, 64, 66
    SVector scale; // 68, 6A, 6C, 6E
    int _70;
    int _74;
    BSPTree* bspTree;
    int _7C;
    short _80[2];
    SVector wNormal;
    SVector offset;
    short _94[2];
    LightInstance* shadow0; // 98
    LightInstance* shadow1; // 9C
    int _A0;
    int _A4;
    int _A8;
    void (*processFunc)(struct Instance_s*,struct GameTracker_s*);
    void (*collideFunc)(struct Instance_s*,struct GameTracker_s*);
    AdditionalDrawFunc additionalDrawFunc;
    int _B8;
    SVECTOR shadowPosition; // BC, BE, C0
    short currentModel; // C2
    short _C4[6]; // C4, C6, C8, CA, CC, CE
    int _D0[4];
    int _E0[4];
    int _F0;
    int currentMainState;   //  F4
    int currentSubState;    //  F8
    long work0;             //  FC
    long work1;             // 100
    long work2;             // 104
    long work3;             // 108
    long work4;             // 10C
    long work5;             // 110
    long work6;             // 114
    long work7;             // 118
    long work8;             // 11C
    long work9;             // 120
} Instance; // Should be size accurate now

extern Instance* PlayerInstance;

#endif