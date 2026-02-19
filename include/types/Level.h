#ifndef LEVEL_H_
#define LEVEL_H_

typedef struct
{
    int _00[4];
    int flags;
    int _14;
    int** _18;
    int* _1C;
    int _20[4];
    short _30[8];
    short _40[7];
    char _4E;
    char _4F;
    short _50[8];
    short _60[8];
    int _70[4];
    short _80[8];
    short _90[8];
    short _A0[8];
    short _B0[8];
    short _C0[8];
    int _D0[4];
    int _E0[4];
    short _F0[2];
    int _F4[3];
    int _100;
    int _104;
    char _108;
    char _109;
    char _10A;
    char _10B;
    char _10C;
    char _10D;
    char _10E;
    char _10F;
    char _110;
    char _111;
    unsigned char _112;
    char _113;
} Level_t;

#endif