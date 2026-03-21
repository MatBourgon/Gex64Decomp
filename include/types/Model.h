#ifndef TMODEL_H_
#define TMODEL_H_

#include "Spline.h"

typedef struct
{
    int _00;
    int _04;
    int _08;
    int _0C;
    int _10;
    int _14;
    int numSegments;
    int _1C;
    int _20;
    short maxRad;
    short _26;
    int _28;
    MultiSpline* multiSpline;
    // probably two more entries here
} Model;

#endif