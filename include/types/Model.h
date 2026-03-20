#ifndef TMODEL_H_
#define TMODEL_H_

#include "Spline.h"

typedef struct
{
    char _[0x24]; // probably matches 1:1 to KAIN's
    short maxRad;
    short _26;
    int _28;
    MultiSpline* multiSpline;
    // probably two more entries here
} Model;

#endif