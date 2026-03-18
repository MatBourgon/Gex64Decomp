#ifndef TSPLINE_H_
#define TSPLINE_H_

typedef struct
{
    short currKey;
    unsigned short fracCurr;
} SplineDef;

typedef struct
{
    int* key;
    short numkeys;
    unsigned char type;
    unsigned char flags;
} Spline;

typedef struct
{
    int* SplineRotKey;
    short numKeys;
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