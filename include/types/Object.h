#ifndef TOBJECT_H_
#define TOBJECT_H_

#include "Model.h"

typedef struct
{
    int oflags;
    short id;
    short _06;
    int _08;
    Model** modelList; // 0C
    int** animList; // 10
    short _14;
    short introDist;
    int _18;
    void* data; // 1C
    const char* parentName; // 20
    const char* name; // 24
    int _28;
    int _2C;
    int oflags2;
} Object;

#endif