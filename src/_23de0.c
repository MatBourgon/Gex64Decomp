#include "common.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/_23de0", func_800231E0);

INCLUDE_ASM("asm/nonmatchings/_23de0", func_80023828);

void func_80023B2C(int* arg0, GameTracker* gameTracker) {
    int* temp_s1 = (int*)arg0[8];
    

    if (temp_s1[78] != 0) {
        func_8002569C(temp_s1[78]);
        temp_s1[78] = 0;

        if (++((int*)gameTracker)[0x12FE] == 5) {
            ((int*)gameTracker)[0x12FE] = 4;
        }

        func_8002780C(gameTracker);
    }

    if (temp_s1[76] != 0) {
        func_80025588(arg0, gameTracker);
        func_8002780C(gameTracker);
    }
}

INCLUDE_ASM("asm/nonmatchings/_23de0", func_80023BC4);

INCLUDE_ASM("asm/nonmatchings/_23de0", func_80023E9C);

INCLUDE_ASM("asm/nonmatchings/_23de0", func_80023F80);

extern int* D_8007681C;

void* func_8002404C(int arg0) {
    if (D_8007681C != 0) {
        char* temp_a2 = (char*)D_8007681C[7]; 

        if (temp_a2 != 0) {
            short* s_ptr = (short*)temp_a2;
            short* t0;
            short* t1;

            s_ptr[12] = arg0;
            s_ptr[13] = 0;

            t0 = ((s_ptr[12] * 4)) + s_ptr;
            s_ptr[14] = t0[1];

            t1 =  ((s_ptr[12] * 4)) + s_ptr;
            s_ptr[15] = t1[0] * 30;

            func_80023F80(s_ptr[12], s_ptr[13]);
        }
    }
}

void func_800240C8(void) {
    func_8002404C(0);
}
