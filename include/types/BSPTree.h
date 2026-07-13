#ifndef TBSPTREE_H_
#define TBSPTREE_H_

#include "Vector.h"

typedef struct
{
    int _00;
    short _04;
    short _06;
    unsigned char* _08; // 08
    unsigned char* _0C; // 0C
    int _10; // 10
    struct Instance_s* instanceSpline; // 14
    SVECTOR globalOffset;
    int _20; // 20
    int _24; // 24
    SVECTOR localOffset; // 28
} BSPTree;

#endif