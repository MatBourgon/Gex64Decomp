#include "common.h"

INCLUDE_ASM("asm/nonmatchings/sched/sched", osCreateScheduler);

INCLUDE_ASM("asm/nonmatchings/sched/sched", osScAddClient);

INCLUDE_ASM("asm/nonmatchings/sched/sched", osScRemoveClient);

INCLUDE_ASM("asm/nonmatchings/sched/sched", osScGetCmdQ);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scMain);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scHandleRetrace);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scHandleRSP);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scHandleRDP);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scTaskReady);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scTaskComplete);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scAppendList);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scExec);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scYield);

INCLUDE_ASM("asm/nonmatchings/sched/sched", __scSchedule);
