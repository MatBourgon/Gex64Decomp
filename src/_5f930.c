#include "common.h"

typedef union
{
    int i[12];
    short s[12*2];
} _5f930_t;

extern void alFilterNew(_5f930_t*, void*, void*, int);
extern int alHeapDBAlloc(int, int, int*, int, int);

INCLUDE_RODATA("asm/nonmatchings/_5f930", D_8007EE10);

INCLUDE_ASM("asm/nonmatchings/_5f930", init_lpfilter);

INCLUDE_ASM("asm/nonmatchings/_5f930", alFxNew);

extern void alEnvmixerPull();
extern void alEnvmixerParam();

void alEnvmixerNew(_5f930_t* arg0, int* arg1) {
    alFilterNew(arg0, &alEnvmixerPull, &alEnvmixerParam, 4);
    arg0->i[5] = alHeapDBAlloc(0, 0, arg1, 1, 0x50);
    arg0->i[14] = 1;
    arg0->i[18] = 0;
    arg0->s[13] = 1;
    arg0->s[20] = 1;
    arg0->s[23] = 1;
    arg0->s[14] = 1;
    arg0->s[15] = 1;
    arg0->s[16] = 0;
    arg0->s[17] = 0;
    arg0->s[19] = 1;
    arg0->s[18] = 0;
    arg0->s[19] = 1;
    arg0->s[18] = 0;
    arg0->i[12] = 0;
    arg0->i[13] = 0;
    arg0->s[12] = 0;
    arg0->i[15] = 0;
    arg0->i[16] = 0;
    arg0->i[17] = 0;
}

extern void alAdpcmPull();
extern void alLoadParam();

void alLoadNew(_5f930_t* arg0, int (*arg1)(int*), int* arg2) {
    alFilterNew(arg0, &alAdpcmPull, &alLoadParam, 0);
    arg0->i[5] = alHeapDBAlloc(0, 0, arg2, 1, 0x20);
    arg0->i[6] = alHeapDBAlloc(0, 0, arg2, 1, 0x20);
    arg0->i[12] = arg1(&arg0->i[13]);
    arg0->i[15] = 0;
    arg0->i[16] = 1;
    arg0->i[17] = 0;
}

extern void alResamplePull();
extern void alResampleParam();

void alResampleNew(_5f930_t* arg0, int* arg1) {
    alFilterNew(arg0, &alResamplePull, &alResampleParam, 1);
    arg0->i[5] = alHeapDBAlloc(0, 0, arg1, 1, 0x20);
    arg0->i[8] = 0;
    arg0->i[9] = 1;
    arg0->i[12] = 0;
    arg0->i[7] = 0;
    arg0->i[10] = 0;
    arg0->i[11] = 0;
    *(float*)&arg0->i[6] = 1.0f;
}

extern void alAuxBusPull();
extern void alAuxBusParam();

void alAuxBusNew(_5f930_t* arg0, int arg1, int arg2) {
    alFilterNew(arg0, &alAuxBusPull, &alAuxBusParam, 6);
    arg0->i[5] = 0;
    arg0->i[6] = arg2;
    arg0->i[7] = arg1;
}

extern void alMainBusPull();
extern void alMainBusParam();

void alMainBusNew(_5f930_t* arg0, int arg1, int arg2) {
    alFilterNew(arg0, &alMainBusPull, &alMainBusParam, 7);
    arg0->i[5] = 0;
    arg0->i[6] = arg2;
    arg0->i[7] = arg1;
}


extern void alSavePull();
extern void alSaveParam();

void alSaveNew(_5f930_t* arg0) {
    alFilterNew(arg0, &alSavePull, &alSaveParam, 3);
    arg0->i[5] = 0;
    arg0->i[6] = 1;
}
