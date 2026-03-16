#ifndef BTIMERINTRO_H_
#define BTIMERINTRO_H_

typedef struct
{
    short missionTime;
    short cutsceneTime;
    int collectType;
    int b;
} BTimerIntro;

#define EBTIMER_COLLECTTYPE_CUTSCENE 0x3F2

#endif