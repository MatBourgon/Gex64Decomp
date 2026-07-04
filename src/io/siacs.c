#include "common.h"

#include "PRinternal/macros.h"
#include "PR/os_internal.h"

extern OSMesgQueue __osSiAccessQueue;

INCLUDE_ASM("asm/nonmatchings/io/siacs", __osSiCreateAccessQueue);

INCLUDE_ASM("asm/nonmatchings/io/siacs", __osSiGetAccess);

void __osSiRelAccess(void) {
    osSendMesg(&__osSiAccessQueue, NULL, OS_MESG_NOBLOCK);
}

