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
    short x, y, z;
    short id;
    short rx, ry, rz;
    short flags;
    short tx, ty, tz;
    short pad;
} CameraKey;

typedef struct
{
    SVECTOR position;
    short _pad;
    int _08[0x54/4];
    int farPlane;
} CameraCore;

typedef struct
{
    CameraCore cameraCore;
    int _data[0x3A];
    CameraKey* cameraKey;
    int mode;
    int smooth;
    int _data2[0x0A];
    short targetFocusRotationX;
    short targetFocusRotationZ;
    short focusRotationX;
    short focusRotationZ;
    int _data7[0x1E];
    int targetFocusDistance;
    int _data8[4];
    ROTATION savedFocusRotation;
    int targetStack;
    int savedTargetFocusDistance[0x9];
    int lock;
    int _data3[0x22];
    int rotState;
    int tiltState;
    int distanceState;
    int signalFocusDistance;
    int _data4[0x39];
    int minFocusDistance;
    int maxFocusDistance;
    int _data5[0x28];
    int timer;
    int _data9[0x1C];
    int stack;
} Camera;

#endif