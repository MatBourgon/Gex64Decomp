#include "common.h"

#include "PRinternal/macros.h"
#include "PR/os_internal.h"

void __osPiCreateAccessQueue(void) {
    extern OSMesgQueue __osPiAccessQueue;
    extern u32 __osPiAccessQueueEnabled;
    extern OSMesg piAccessBuf;

    __osPiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osPiAccessQueue, &piAccessBuf, 1);
    osSendMesg(&__osPiAccessQueue, NULL, 0);
}

INCLUDE_ASM("asm/nonmatchings/io/piacs", __osPiGetAccess);

void __osPiRelAccess(void) {
    extern OSMesgQueue __osPiAccessQueue;
    osSendMesg(&__osPiAccessQueue, NULL, OS_MESG_NOBLOCK);
}
