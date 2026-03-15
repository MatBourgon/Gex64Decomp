#include "common.h"

#include <PR/os_thread.h>
#include <PR/os_message.h>
#include <ultra64.h>
#include <PR/sched.h>

#include "types/Instance.h"
#include "types/GameTracker.h"

#define ARRAY_COUNT(x) (sizeof(x) / sizeof((x)[0]))

extern OSThread D_800ABAB0;
extern int D_800AE0C0;
extern OSMesgQueue gGlobalMessageBuffer;

void func_8003B5F8(void*);

void bootproc(void* arg0) {
    char padding[0x40];
    osInitialize();
    osCreateThread(&D_800ABAB0, 1, func_8003B5F8, arg0, &D_800AE0C0, 14);
    osStartThread(&D_800ABAB0);
}

extern OSMesgQueue D_800AEFE0;
extern OSMesg D_800AECC0[0xC8];
extern OSMesgQueue D_800AEFF8;
extern OSMesg D_800AF028[1];
extern OSMesgQueue D_800E9748;
extern OSMesg D_800E8188[0x10];
extern OSMesgQueue D_800AF010;
extern OSMesg D_800AF02C[1];
extern OSMesg D_800AF030[2];
extern OSMesgQueue D_800E5FE8;
extern OSMesg D_800E8EF0[8];

extern int D_800ADFC0;

extern OSMesgQueue* D_800B83D8;
extern OSThread D_800AB900;

extern OSSched D_800E7EF8;
extern OSScClient D_800BF2D8;

extern OSThread D_800ABE10;
extern char D_80159710[]; // stack memory

extern int D_800AE4C0;
extern OSThread D_800ABC60;

void func_8003BFB8(void*);
void func_800354E0(void*);
void func_8003B804(void*);

void func_8003B5F8(void* arg0) {

    osCreatePiManager(OS_PRIORITY_PIMGR, &D_800AEFE0, D_800AECC0, ARRAY_COUNT(D_800AECC0));
    osCreateMesgQueue(&D_800AEFF8, D_800AF028, ARRAY_COUNT(D_800AF028));
    osCreateMesgQueue(&D_800E9748, D_800E8188, ARRAY_COUNT(D_800E8188));
    osCreateMesgQueue(&D_800AF010, D_800AF02C, ARRAY_COUNT(D_800AF02C));
    osCreateMesgQueue(&gGlobalMessageBuffer, D_800AF030, ARRAY_COUNT(D_800AF030));
    osCreateMesgQueue(&D_800E5FE8, D_800E8EF0, ARRAY_COUNT(D_800E8EF0));

    if (osTvType == OS_TV_MPAL) {
        osCreateScheduler(&D_800E7EF8, D_80159710, 15, OS_VI_MPAL_LAN1, 1);
    } else {
        osCreateScheduler(&D_800E7EF8, D_80159710, 15, OS_VI_NTSC_LAN1, 1);
    }

    osScAddClient(&D_800E7EF8, &D_800BF2D8, &D_800E9748);
    D_800B83D8 = osScGetCmdQ(&D_800E7EF8);

    osCreateThread(&D_800ABE10, 8, &func_800354E0, 0, &D_800AECC0, 12);
    osStartThread(&D_800ABE10);

    osCreateThread(&D_800ABC60, 7, &func_8003BFB8, 0, &D_800AE4C0, 9);
    osStartThread(&D_800ABC60);

    // Possibly main thread
    osCreateThread(&D_800AB900, 6, &func_8003B804, arg0, &D_800ADFC0, 10);
    osStartThread(&D_800AB900);

    osSetThreadPri(0, 0);

    while(1);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8003B804);

void func_8003BA7C(unsigned int devAddr, void* dramAddr, unsigned int size) {
    OSIoMesg ioMesg;
    OSMesg mesg;

    osInvalDCache(dramAddr, size);
    osPiStartDma(&ioMesg, /*priority*/ 0, /*direction*/ 0, devAddr, dramAddr, size, &D_800AEFF8);
    osRecvMesg(&D_800AEFF8, &mesg, 1);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8003BAF8);

INCLUDE_ASM("asm/nonmatchings/main", func_8003BB78);

INCLUDE_ASM("asm/nonmatchings/main", func_8003BEF4);

extern void* D_800EB7F4;
extern int D_8006FCCC;
extern int D_80070134;

void func_8003BFB8(void* arg0) {
    OSMesg mesg;

    // Seems very related to file 3BAA0
    while(1)
    {
        osRecvMesg(&D_800AF010, &mesg, 1);
        D_800EB7F4 = (void*)0x8024B000; // Where level data is stored
        func_8003B54C();
        D_8006FCCC = func_8003B300(gameTracker8->levelIdToLoad); // Unpack level?
        func_8003B198(D_8006FCCC);
        func_8003B484(gameTracker8->levelIdToLoad); // Load level overlay?
        func_80030BA0();
        PlayerInstance->object = (Object*)func_8003B3D4();
        D_80070134 = 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_8003C070);

INCLUDE_ASM("asm/nonmatchings/main", func_8003C368);
