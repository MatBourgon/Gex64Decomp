#include "common.h"

#include "PRinternal/macros.h"
#include "PR/os_internal.h"

extern OSMesgQueue __osSiAccessQueue;

void __osSiCreateAccessQueue(void) {
    extern u32 __osSiAccessQueueEnabled;
    extern OSMesg D_800B3BB0;

    __osSiAccessQueueEnabled = 1;
    osCreateMesgQueue(&__osSiAccessQueue, &D_800B3BB0, 1);
    osSendMesg(&__osSiAccessQueue, NULL, 0);
}

INCLUDE_ASM("asm/nonmatchings/io/siacs", __osSiGetAccess);

void __osSiRelAccess(void) {
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

