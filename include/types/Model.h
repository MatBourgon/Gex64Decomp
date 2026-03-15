#ifndef MODEL_H_
#define MODEL_H_

#include "Spline.h"

typedef struct
{
    char _[0x2C]; // probably matches 1:1 to KAIN's
    MultiSpline* multiSpline;
    // probably two more entries here
} Model;

#endif