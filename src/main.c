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
extern OSMesg HandleControllerStack[0xC8];
extern OSMesgQueue DMAMessageQueue;
extern OSMesg D_800AF028[1];
extern OSMesgQueue gSchedulerFinishedMessageQueue;
extern OSMesg D_800E8188[0x10];
extern OSMesgQueue LoadLevelMessageQueue;
extern OSMesg D_800AF02C[1];
extern OSMesg D_800AF030[2];
extern OSMesgQueue D_800E5FE8;
extern OSMesg D_800E8EF0[8];

extern int HandleMainStack[1];

extern OSMesgQueue* gSchedulerCommandQueue;
extern OSThread HandleMainThread;

extern OSSched gScheduler;
extern OSScClient gSchedulerClient;

extern OSThread HandleControllerThread;
extern char gSchedulerStack[]; // stack memory

extern int HandleLoadLevelStack[1];
extern OSThread HandleLoadLevelThread;

void HandleLoadLevel(void*);
void HandleController(void*);
void HandleMain(void*);

void func_8003B5F8(void* arg0) {

    osCreatePiManager(OS_PRIORITY_PIMGR, &D_800AEFE0, HandleControllerStack, ARRAY_COUNT(HandleControllerStack));
    osCreateMesgQueue(&DMAMessageQueue, D_800AF028, ARRAY_COUNT(D_800AF028));
    osCreateMesgQueue(&gSchedulerFinishedMessageQueue, D_800E8188, ARRAY_COUNT(D_800E8188));
    osCreateMesgQueue(&LoadLevelMessageQueue, D_800AF02C, ARRAY_COUNT(D_800AF02C));
    osCreateMesgQueue(&gGlobalMessageBuffer, D_800AF030, ARRAY_COUNT(D_800AF030));
    osCreateMesgQueue(&D_800E5FE8, D_800E8EF0, ARRAY_COUNT(D_800E8EF0));

    if (osTvType == OS_TV_MPAL) {
        osCreateScheduler(&gScheduler, gSchedulerStack, 15, OS_VI_MPAL_LAN1, 1);
    } else {
        osCreateScheduler(&gScheduler, gSchedulerStack, 15, OS_VI_NTSC_LAN1, 1);
    }

    osScAddClient(&gScheduler, &gSchedulerClient, &gSchedulerFinishedMessageQueue);
    gSchedulerCommandQueue = osScGetCmdQ(&gScheduler);

    osCreateThread(&HandleControllerThread, 8, HandleController,   0,      HandleControllerStack, 12);
    osStartThread(&HandleControllerThread);

    osCreateThread(&HandleLoadLevelThread,  7, HandleLoadLevel,    0,      HandleLoadLevelStack, 9);
    osStartThread(&HandleLoadLevelThread);

    osCreateThread(&HandleMainThread,       6, HandleMain,         arg0,   HandleMainStack, 10);
    osStartThread(&HandleMainThread);

    osSetThreadPri(NULL, OS_PRIORITY_IDLE);

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

void HandleMain(void* arg0) {
    OSMesg msgType;
    int var_s1;
    int temp_a0;
    int temp_a1;

    var_s1 = 0;
    msgType = NULL;
    func_8003BAF8();
    while(1)
    {
        osRecvMesg(&gSchedulerFinishedMessageQueue, &msgType, 1);

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
    osPiStartDma(&ioMesg, OS_MESG_PRI_NORMAL, OS_READ, devAddr, dramAddr, size, &DMAMessageQueue);
    osRecvMesg(&DMAMessageQueue, &mesg, 1);
}

INCLUDE_ASM("asm/nonmatchings/main", func_8003BAF8);

INCLUDE_ASM("asm/nonmatchings/main", func_8003BB78);

INCLUDE_ASM("asm/nonmatchings/main", func_8003BEF4);

extern void* D_800EB7F4;
extern void* LevelDataPtr; // Likely to be uncompressed level data
extern int D_80070134;

void HandleLoadLevel(void* arg0) {
    OSMesg mesg;

    while(1)
    {
        osRecvMesg(&LoadLevelMessageQueue, &mesg, OS_MESG_BLOCK);
        D_800EB7F4 = LEVEL_DATA_ADDRESS; // Where level data is stored
        LoadZlib();
        LevelDataPtr = (void*)LoadLevelData(gameTracker8->levelIdToLoad); // Unpack level
        LoadObjects(LevelDataPtr); // Unpack & prepare models
        LoadLevelCode(gameTracker8->levelIdToLoad); // Load level code
        func_80030BA0();
        PlayerInstance->object = (Object*)LoadGexObject();
        D_80070134 = 2;
    }
}
