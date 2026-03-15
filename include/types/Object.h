#ifndef OBJECT_H_
#define OBJECT_H_

#include "Model.h"

typedef struct
{
    int oflags;
    short id;
    short _06;
    int _08;
    Model** modelList;
    int numAnims;
    int _14;
    int _18;
    int* _1C;
    int _20;
    const char* name;
    int _28;
    int _2C;
    int oflags2;
} Object;

#endif