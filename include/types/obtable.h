#ifndef TOBJECTFUNCTIONS_H_
#define TOBJECTFUNCTIONS_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

typedef void(*objFunction)(Instance*, GameTracker*);
extern void GenericInit(Instance*, GameTracker*);
extern void GenericCollide(Instance*, GameTracker*);
extern void GenericProcess(Instance*, GameTracker*);

typedef struct
{
    char* name;
    char* level;
    objFunction init;
    objFunction process;
    objFunction collide;
} OBTableEntry;

extern OBTableEntry ObjectFunctionTable[];

typedef struct
{
    char* objectName;
    void* object;
} ObjectAccess;

enum EObjectType
{
    EOBJECT_SHADOW1 =   0x00,
    EOBJECT_SHADOW2 =   0x01,
    EOBJECT_HUD =       0x02,
    EOBJECT_FLAME =     0x03,
    EOBJECT_PUFFA =     0x04,
    EOBJECT_SPLATA =    0x05,
    EOBJECT_DBGCAM =    0x06,
    EOBJECT_HELMET =    0x07,
    EOBJECT_FPOWER =    0x08,
    EOBJECT_WHACK =     0x09,
    EOBJECT_FONTS =     0x0A,
    EOBJECT_GEXEYES =   0x0B,
    EOBJECT_CHRGANM =   0x0C,
    EOBJECT_PUFSTAR =   0x0D,
    EOBJECT_SPARKA =    0x0E,
    EOBJECT_SPARKB =    0x0F,
    EOBJECT_SPARKD =    0x10,
    EOBJECT_DEREZ =     0x11,
    EOBJECT_ZAPFLSH =   0x12,
    EOBJECT_ZAPELEC =   0x13,
    EOBJECT_BOMB =      0x14,
    EOBJECT_EXPLODE =   0x15,
    EOBJECT_BABYRES =   0x16,
    EOBJECT_SKELH =     0x17,
    EOBJECT_CAVETL =    0x18,
    EOBJECT_RPLANK =    0x19,
    EOBJECT_FBALL =     0x1A,
    EOBJECT_BIGBLK =    0x1B,
    EOBJECT_PBALL =     0x1C,
    EOBJECT_COLFIRE =   0x1D,
    EOBJECT_TAILPUF =   0x1E,
    EOBJECT_PTBUG =     0x1F,
    EOBJECT_BOULDER =   0x20,
    EOBJECT_SPTBALL =   0x21,
    EOBJECT_COLA =      0x22,
    EOBJECT_COLB =      0x23,
    EOBJECT_COLC =      0x24,
    EOBJECT_ZOMARM =    0x25,
    EOBJECT_ZOMLEG =    0x26,
    EOBJECT_HUCKHED =   0x27,
    EOBJECT_SUNGLASS =  0x28,
    EOBJECT_WATERFX =   0x29,
    EOBJECT_CAMMODE =   0x2A,
    EOBJECT_ICE =       0x2B,
    EOBJECT_ICECUBE =   0x2C,
    EOBJECT_INTROFX =   0x2D,
    EOBJECT_PUFFB =     0x2E,
    EOBJECT_BTIMER =    0x2F,
    EOBJECT_SMOKEB =    0x30,
    EOBJECT_STARZ =     0x31,
    EOBJECT_MAPICON =   0x32,
    EOBJECT_MECHLIF =   0x33,

    EOBJECT_COUNT
};

extern ObjectAccess objectAccess[EOBJECT_COUNT];

#endif