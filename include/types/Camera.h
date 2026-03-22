#ifndef TCAMERA_H_
#define TCAMERA_H_

#include "types/Spline.h"
#include "types/Vector.h"

typedef struct
{
    // offset: 0x0000 (4 bytes)
    MultiSpline *posSpline;
    // offset: 0x0004 (4 bytes)
    MultiSpline *targetSpline;
    // offset: 0x0008 (8 bytes)
    SVector lastSplinePos;
    // offset: 0x0010
    short splinePointAhead;
    // offset: 0x0012
    short cinema_done;
    // offset: 0x0014
    int splinecam_currkey;
    // offset: 0x0018
    int splinecam_helpkey;
} Cinematic;

typedef struct
{

} Camera;

#endif