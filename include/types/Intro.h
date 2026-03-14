#ifndef INTRO_H_
#define INTRO_H_

#include "Vector.h"
#include "Spline.h"

typedef struct
{
    int* _00;
    int* _04;
    SVECTOR rotation; // 08, 0A, 0C, 0E
    short _pad;
    SVECTOR position;
    // int* _14; // not used?
    int* _18;
    int flags;
    int* _20; // intro data?
    int* instance;
    MultiSpline* multiSpline; // 0x28
    int* _2C;
} Intro;

#endif