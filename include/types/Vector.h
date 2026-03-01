#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct
{
    short x, y, z;
} SVECTOR;

FORCE_INLINE int SVECTOR_DistanceSquared(SVECTOR* v1, SVECTOR* v2)
{
    SVECTOR d;
    d.x = (v1->x - v2->x);
    d.y = (v1->y - v2->y);
    d.z = (v1->z - v2->z);

    return d.x * d.x + d.y * d.y + d.z * d.z;
}

#endif 