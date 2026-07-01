#include "common.h"

#include "PRinternal/macros.h"
#include "PR/os_internal.h"

void __osPiCreateAccessQueue(void) {
    extern OSMesgQueue __osPiAccessQueue;
    extern u32 D_800795F0;
    extern OSMesg D_800B2910;

    D_800795F0 = 1;
    osCreateMesgQueue(&__osPiAccessQueue, &D_800B2910, 1);
    osSendMesg(&__osPiAccessQueue, NULL, 0);
}

INCLUDE_ASM("asm/nonmatchings/io/piacs", __osPiGetAccess);

void __osPiRelAccess(void) {
    extern OSMesgQueue __osPiAccessQueue;
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
