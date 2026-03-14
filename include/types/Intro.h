#ifndef INTRO_H_
#define INTRO_H_

#include "Vector.h"
#include "Spline.h"

typedef struct
{
    int* _00;
    int* _04;
    SVECTOR rotation;
    short _pad;
    SVECTOR position;
    // int* _14; // not used?
    int* _18;
    int flags;
    int* _20;
    int* _24;
    MultiSpline* multiSpline; // 0x28
    int* _2C;
} Intro;

#endif