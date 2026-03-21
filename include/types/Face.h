#ifndef TFACE_H_
#define TFACE_H_

typedef struct
{
    // offset: 0x0000
    unsigned short v0;
    // offset: 0x0002
    unsigned short v1;
    // offset: 0x0004
    unsigned short v2;
} Face;

typedef struct
{
    Face face;
    unsigned char attr;
    char sortPush;
    short normal;
    short textoff;
} TFace;

#endif