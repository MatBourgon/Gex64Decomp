#ifndef TVECTOR_H_
#define TVECTOR_H_

#include "common.h" // FORCE_INLINE

typedef struct
{
    short x, y, z;
} SVECTOR;

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

    return d.x * d.x + d.y * d.y + d.z * d.z;
}

extern int SVECTOR_Length(SVECTOR* v);

#endif 