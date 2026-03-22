#include "common.h"

#include "COLLIDE.h"

INCLUDE_ASM("asm/nonmatchings/COLLIDE_A", func_8000CAF0);

int func_8000CEB4(SVector* arg0, SVector* arg1, SVector* arg2, SVector* arg3, int arg4) {
    SVector sp0;
    int temp_lo;
    int length;

    sp0.x = arg2->x - arg1->x;
    sp0.y = arg2->y - arg1->y;
    sp0.z = arg2->z - arg1->z;
    D_8006CEF0 = 0;
    length =  ((sp0.x * arg3->x) + (sp0.y * arg3->y) + (sp0.z * arg3->z)) >> 0xC;
    
    if (length != 0) {
        D_8006CEF0 = -((( ((arg1->x * arg3->x) + (arg1->y * arg3->y) + (arg1->z * arg3->z)) >> 0xC) - arg4) << 0xC) / length;
        if (0 <= D_8006CEF0 && D_8006CEF0 <= 0x1000) {
            arg0->x =  (arg1->x + ( (sp0.x * D_8006CEF0) >> 0xC));
            arg0->y =  (arg1->y + ( (sp0.y * D_8006CEF0) >> 0xC));
            arg0->z =  (arg1->z + ( (sp0.z * D_8006CEF0) >> 0xC));
            return 1;
        }
    }
    
    return 0;
}
