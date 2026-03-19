#ifndef TSPLINE_H_
#define TSPLINE_H_

#include "types/Vector.h"
#include "types/Quat.h"

typedef struct
{
    short currkey;
    unsigned short denomFlag : 1;
    unsigned short fracCurr : 15;
} SplineDef;

// size: 0x20
typedef struct SplineKey
{
    // offset: 0x0000
    short count;
    // offset: 0x0002 (6 bytes)
    SVECTOR point;
    // offset: 0x0008 (12 bytes)
    LVECTOR dd;
    // offset: 0x0014 (12 bytes)
    LVECTOR ds;
} SplineKey;

typedef struct
{
    SplineKey* key;
    short numkeys;
    unsigned char type;
    unsigned char flags;
} Spline;

typedef struct SplineRotKey
{
    // offset: 0x0000
    short count;
    // offset: 0x0002 (8 bytes)
    G2Quat q;
} SplineRotKey;

typedef struct
{
    SplineRotKey* key;
    short numkeys;
    unsigned char type;
    unsigned char flags;
} RSpline;

typedef struct
{
    Spline* positional;
    RSpline* rotational;
    Spline* scaling;
    Spline* color;
    SplineDef curPositional;
    SplineDef curRotational;
    SplineDef curScaling;
} MultiSpline;

#endif