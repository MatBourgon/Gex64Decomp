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
void HandleController(void*);
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

    osCreateThread(&D_800ABE10, 8, &HandleController, 0, &D_800AECC0, 12);
    osStartThread(&D_800ABE10);

    osCreateThread(&D_800ABC60, 7, &func_8003BFB8, 0, &D_800AE4C0, 9);
    osStartThread(&D_800ABC60);

    // Possibly main thread
    osCreateThread(&D_800AB900, 6, &func_8003B804, arg0, &D_800ADFC0, 10);
    osStartThread(&D_800AB900);

    osSetThreadPri(0, 0);

    while(1);
}

extern int D_800BFE24;
extern int D_80070130;
extern int D_80070138;
extern int D_8006FA50;
extern unsigned int D_80154690;
extern int D_800E5FD8;
extern int D_800E5CD8;
extern int D_80156BE0;
extern int D_800E5CD0;
extern int D_800B83B8;
extern int D_801539D8;

void func_8003B804(void* arg0) {
    OSMesg msgType;
    int var_s1;
    int temp_a0;
    int temp_a1;

    var_s1 = 0;
    msgType = NULL;
    func_8003BAF8();
    while(1)
    {
        osRecvMesg(&D_800E9748, &msgType, 1);

        switch(*(short*)msgType)
        {
            case 1:
                {
                    D_800BFE24++;
                    if (D_80070138 != 0)
                    {
                        func_80032BD0(gameTracker8->levelIdToLoad);
                    }
                    else
                    {
                        if ((D_80070130 < 2U) && (D_80154690 >= 2U)) {
                            if ((D_8006FA50 != 0) && (var_s1 == 0)) {
                                var_s1 = 1;
                                D_801539D8 += 1;
                                osSendMesg(&gGlobalMessageBuffer, 0, 0);
                            }
                            temp_a0 = D_800E5FD8;
                            temp_a1 = (D_80154690 >> 1);
                            D_800E5FD8 = temp_a1;
                            D_800E5CD8 += temp_a1;
                            D_80154690 &= 1;

                            D_80156BE0 = (temp_a0 == 1)
                                ? ((temp_a1 == 1) ? 0x1000 : 0x1400)
                                : ((temp_a1 == 1) ? 0x1400 : 0x1600)
                                ;
                            
                            func_8003BB78();
                        }
                        D_80154690++;
                    }
                }
            break;

            case 2:
                D_80070130--;
                break;
            
            case 5:
                D_800E5CD0++;
                var_s1 = 0;
                func_80035A3C();
                break;

            case 4:
                if (D_800B83B8 != 2) {
                    int x = 10;
                    ((short*)gameTracker8)[0x9C/2] = x;
                    x = 20;
                    ((short*)gameTracker8)[0x98/2] = x;
                    ((short*)gameTracker8)[0x9A/2] = x;
                    func_80039600();
                }
                D_80070138 = 1;
            break;
        }
    }
}

// Transfer data
void DMATransferData(unsigned int devAddr, void* dramAddr, unsigned int size) {
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
extern void* LevelDataPtr; // Likely to be uncompressed level data
extern int D_80070134;

void func_8003BFB8(void* arg0) {
    OSMesg mesg;

    while(1)
    {
        osRecvMesg(&D_800AF010, &mesg, 1);
        D_800EB7F4 = LEVEL_DATA_ADDRESS; // Where level data is stored
        LoadZlib();
        LevelDataPtr = LoadLevelData(gameTracker8->levelIdToLoad); // Unpack level
        LoadObjects(LevelDataPtr); // Unpack & prepare models
        LoadLevelCode(gameTracker8->levelIdToLoad); // Load level code
        func_80030BA0();
        PlayerInstance->object = (Object*)LoadGexObject();
        D_80070134 = 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/main", func_8003C070);

INCLUDE_ASM("asm/nonmatchings/main", MulMatrix2);
