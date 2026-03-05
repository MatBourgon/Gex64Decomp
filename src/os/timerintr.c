#include "common.h"

INCLUDE_ASM("asm/nonmatchings/os/timerintr", __osTimerServicesInit);

INCLUDE_ASM("asm/nonmatchings/os/timerintr", __osTimerInterrupt);

INCLUDE_ASM("asm/nonmatchings/os/timerintr", __osSetTimerIntr);

INCLUDE_ASM("asm/nonmatchings/os/timerintr", __osInsertTimer);
