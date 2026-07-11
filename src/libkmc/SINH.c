#include "common.h"


/*** for Turboc ***/
/**** for GCC ****/
#define GCC 1
#define MBIT 0x4000000000000000LL
#define CBIT 52
#define NR 1.0e-8
#define XLONG long long



#define  PI 3.14159265358979312
#define KH 1.20749706776307231

INCLUDE_ASM("asm/nonmatchings/libkmc/SINH", _xsinhcosh);

INCLUDE_ASM("asm/nonmatchings/libkmc/SINH", sinh);

INCLUDE_ASM("asm/nonmatchings/libkmc/SINH", cosh);

double tanh(th)
double th;
{
    double s,c;
    int ti;
    
    ti = (th / PI)+(th>=0 ? 0.5 : -0.5);
    th = th - ti*PI;

    if(th < NR && th >-NR) return th;

    _xsinhcosh(th,&s,&c);
    return s/c;
}
