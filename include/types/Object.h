#ifndef OBJECT_H_
#define OBJECT_H_

typedef struct
{
    int _00;
    short id;
    short _06;
    int _08;
    int _0C;
    int numAnims;
    int _14;
    int _18;
    int* _1C;
    int _20;
    const char* name;
} Object;

#endif