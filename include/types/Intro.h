#ifndef TINTRO_H_
#define TINTRO_H_

#include "Vector.h"
#include "Spline.h"

struct Instance_s;

typedef struct
{
    int* _00;
    int* _04;
    SVECTOR rotation; // 08, 0A, 0C
    short lightGroup; // 0E
    SVECTOR position; // 10, 12, 14
    int* _18;
    int flags; // 1C
    void* data; // 20
    struct Instance_s* instance;
    MultiSpline* multiSpline; // 0x28
    int* _2C; // Maybe dsignal?
} Intro;

#endif