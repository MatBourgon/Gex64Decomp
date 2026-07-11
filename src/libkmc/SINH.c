/*
    Copyright (c) 1995,1996 by Kyoto Micro Computer Co. Ltd.
    All Rights Reserved.
*/

/*
	double sinh(double ),cosh(double),tanh(double)
*/

#include "_KMCLIB.h"
#include <math.h>


/*** for Turboc ***/
/**** for GCC ****/
#define GCC 1
#define MBIT 0x1000000000000000LL
#define CBIT 52
#define NR 1.0e-8
#define XLONG long long



#define  PI 3.14159265358979312
#define KH 0.6072529350088812

XLONG _ahtbl[64] = {
    0.7853981633974483*MBIT,
    0.4636476090008061*MBIT,
    0.24497866312686414*MBIT,
    0.12435499454676144*MBIT,
    0.06241880999595735*MBIT,
    0.031239833430268277*MBIT,
    0.015623728620476831*MBIT,
    0.007812341060101111*MBIT,
    0.0039062301319669713*MBIT,
    0.0019531225164788188*MBIT,
    0.000976562189559319*MBIT,
    0.00048828121119489764*MBIT,
    0.000244140620149361*MBIT,
    0.00012207031189366991*MBIT,
    6.1035156174208197e-05*MBIT,
    3.0517578115525808e-05*MBIT,
    1.5258789061315184e-05*MBIT,
    7.629394531101681e-06*MBIT,
    3.814697265605918e-06*MBIT,
    1.907348632809898e-06*MBIT,
    9.536743164053826e-07*MBIT,
    4.7683715820225764e-07*MBIT,
    2.3841857910069514e-07*MBIT,
    1.1920928954991389e-07*MBIT,
    5.960464477452326e-08*MBIT,
    2.980232238682795e-08*MBIT,
    1.4901161192980295e-08*MBIT,
    7.450580596923828e-09*MBIT,
    3.725290298461914e-09*MBIT,
    1.862645149230957e-09*MBIT,
    9.313225746154785e-10*MBIT,
    4.656612873077393e-10*MBIT,
    2.3283064365386963e-10*MBIT,
    1.1641532182693481e-10*MBIT,
    5.820766091346741e-11*MBIT,
    2.9103830456733704e-11*MBIT,
    1.4551915228366852e-11*MBIT,
    7.275957614183426e-12*MBIT,
    3.637978807091713e-12*MBIT,
    1.8189894035458565e-12*MBIT,
    9.094947017729282e-13*MBIT,
    4.547473508864641e-13*MBIT,
    2.2737367544323206e-13*MBIT,
    1.1368683772161603e-13*MBIT,
    5.684341886080802e-14*MBIT,
    2.842170943040401e-14*MBIT,
    1.4210854715202004e-14*MBIT,
    7.105427357601002e-15*MBIT,
    3.552713678800501e-15*MBIT,
    1.7763568394002505e-15*MBIT,
    8.881784197001252e-16*MBIT,
    4.440892098500626e-16*MBIT,
    2.220446049250313e-16*MBIT,
    1.1102230246251565e-16*MBIT,
    5.551115123125783e-17*MBIT,
    2.7755575615628914e-17*MBIT,
    1.3877787807814457e-17*MBIT,
    6.938893903907228e-18*MBIT,
    3.469446951953614e-18*MBIT,
    1.734723475976807e-18*MBIT,
    8.673617379884035e-19*MBIT,
    0*MBIT,
    0*MBIT,
    0*MBIT, 	/* 63 */
};

_xsinhcosh(th,sinhp,coshp)
double th;		/* -pi/2 <= th <= pi/2 */
double *sinhp,*coshp;	/* sinh , cosh */
{
    int i;
    XLONG x,xx,y,z;
    
    x=(double)KH*MBIT;
    y=0;
    z=th*MBIT;
    for(i=0;i<CBIT;++i) {
        if (z>=0) {
            xx=x-(y>>i);
            y=y+(x>>i);
            z=z-_ahtbl[i];
        }
        else {
            xx=x+(y>>i);
            y=y-(x>>i);
            z=z+_ahtbl[i];
        }
        x=xx;
    }
    *sinhp = (double)y/MBIT;
    *coshp = (double)x/MBIT;
}

double sinh(th)
double th;
{
    double s,c;
    int ti;

    ti = (th / PI) + (th>=0 ? 0.5 : -0.5);
    th = th - (ti * PI);
    
    if(th < NR && th >-NR) return th;
    
    _xsinhcosh(th, &s, &c);
    return (ti&1 ? -s : s);
}

double cosh(th)
double th;
{
    double s,c;
    int ti;
    
    ti = (th / PI)+(th>=0 ? 0.5 : -0.5);
    th = th - ti*PI;

    _xsinhcosh(th,&s,&c);
    return (ti&1 ? -c : c);
}

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
