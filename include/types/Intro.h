#ifndef INTRO_H_
#define INTRO_H_

#include "Vector.h"

typedef struct
{
    int* _00;
    int* _04;
    SVECTOR rotation;
    short _pad;
    SVECTOR position;
    // int* _14; // not used?
    int* _18;
    int _1C;
    int* _20;
    int* _24;
    void* multiSpline; // 0x28
    int* _2C;
} Intro;

#endif