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

// size: 0xC
typedef struct _HFace
{
    // offset: 0x0000
    short v0;
    // offset: 0x0002
    short v1;
    // offset: 0x0004
    short v2;
    // offset: 0x0006
    unsigned char attr;
    // offset: 0x0007
    char pad;
    // offset: 0x0008
    unsigned short normal;
    // offset: 0x000A
    unsigned short n0;
} HFace;

#endif