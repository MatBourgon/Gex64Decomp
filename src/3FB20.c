#include "common.h"

#include "types/intro/QMark.h"
#include "types/GameTracker.h"

INCLUDE_ASM("asm/nonmatchings/3FB20", func_8003EF20);

INCLUDE_ASM("asm/nonmatchings/3FB20", func_8003F334);

INCLUDE_ASM("asm/nonmatchings/3FB20", func_8003F458);

INCLUDE_ASM("asm/nonmatchings/3FB20", func_8003F614);

INCLUDE_ASM("asm/nonmatchings/3FB20", func_8003F678);

extern short D_80078110;
extern short D_80078112;
extern short D_80078114;
extern short D_80078116;
extern short D_8007811E[];
extern QMarkIntroMessage* D_80078124;
extern short* D_800EB7F8;

void func_8003F6CC(short x, short y, short w, short h, short numMessages, QMarkIntroMessage* messages) {
    
    if ((D_800EB7F8 == NULL) && (((short*)gameTracker4)[0x4C12/2] != 6))
    {
        short* ptr = D_8007811E;
        D_80078110 = x;
        D_80078112 = y;
        D_80078114 = w;
        D_80078116 = h;
        (ptr--)[0] = numMessages;
        D_80078124 = messages;
        D_800EB7F8 = ptr;
    }
}

INCLUDE_ASM("asm/nonmatchings/3FB20", func_8003F748);

INCLUDE_ASM("asm/nonmatchings/3FB20", func_8003F7B4);

INCLUDE_ASM("asm/nonmatchings/3FB20", func_8003F850);
