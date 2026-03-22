#ifndef TBSPTREE_H_
#define TBSPTREE_H_

typedef struct
{
    int _00;
    short _04;
    short _06;
    unsigned char* _08;
    unsigned char* _0C;
    int _10;
    struct Instance_s* instanceSpline;
} BSPTree;

#endif