#include "common.h"

INCLUDE_ASM("asm/nonmatchings/rmon/rmoncmds", __rmonExecute);

int NotImplemented(void* unused)
{
    return -1;
}