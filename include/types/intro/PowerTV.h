#ifndef POWERTVINTRO_H_
#define POWERTVINTRO_H_

enum EPowerTVType
{
    EPTV_HEALTH     = 0,
    EPTV_FIRE       = 1,
    EPTV_ICE        = 2,
    EPTV_UNUSED     = 3, // unused, but still referenced in some places
    EPTV_LIFE       = 4,
    EPTV_CHECKPOINT = 5
};

typedef struct
{
    short type;
    short respawns;
    int unk; // maybe fly pointer?
} PowerTVIntro;

#endif