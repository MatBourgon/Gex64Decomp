#include "common.h"

#include "COLLIDE.h"

int func_8000F0DC(void* segmentAddress, SVECTOR* newPoint, SVECTOR* oldPoint, int arg3, Instance* instance, int arg5, int arg6);

int COLLIDE_PointAndTerrain(void* segmentAddress, SVECTOR* newPoint, SVECTOR* oldPoint, Instance* instance) {
    return func_8000F0DC(segmentAddress, newPoint, oldPoint, 1, instance, 0, 0);
}

INCLUDE_ASM("asm/nonmatchings/COLLIDE_D", func_8000F0DC);
