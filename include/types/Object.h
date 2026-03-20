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
    int _14;
    int _18;
    void* data;
    const char* parentName;
    const char* name;
    int _28;
    int _2C;
    int oflags2;
} Object;

#endif