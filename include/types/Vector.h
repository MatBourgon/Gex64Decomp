#ifndef TVECTOR_H_
#define TVECTOR_H_

#include "common.h" // FORCE_INLINE

FORCE_INLINE unsigned int MATH3D_SquareLength(int x, int y, int z) // eventually move into MATH3D.h
{
    return x * x + y * y + z * z;
}

typedef struct
{
    short x, y, z;
} SVECTOR;

typedef struct
{
    short x, y, z;
    short pad;
} SVector; // Required padding difference

typedef struct
{
    int x, y, z;
} LVECTOR;

FORCE_INLINE void SVECTOR_Subtract(SVECTOR* lhs, SVECTOR* rhs, SVECTOR* out)
{
    out->x = lhs->x - rhs->x;
    out->y = lhs->y - rhs->y;
    out->z = lhs->z - rhs->z;
}

FORCE_INLINE int SVECTOR_DistanceSquared(SVECTOR* v1, SVECTOR* v2)
{
    SVECTOR d;
    SVECTOR_Subtract(v1, v2, &d);

    return MATH3D_SquareLength(d.x, d.y, d.z);
}

extern int SVECTOR_Length(SVECTOR* v);

#endif 