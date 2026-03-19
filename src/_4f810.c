#include "common.h"

#include "types/Spline.h"

// Hint: Partially probably SPLINE.c

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAC0);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAC8);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAD8);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAE4);

INCLUDE_RODATA("asm/nonmatchings/_4f810", D_8007EAF0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004EC10);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004EF70);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004EFD0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F020);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F124);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F25C);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F398);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F4D0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F60C);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F784);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004F920);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004FBBC);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8004FE44);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8005011C);

void func_800503F8(void) {
}

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050400);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050508);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800506B8);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050854);

void func_800508CC(void) {
}

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800508D4);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050930);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050980);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800509E0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050A80);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050B64);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050BC4);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050C80);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050E04);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050EA0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050F98);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800512BC);

INCLUDE_ASM("asm/nonmatchings/_4f810", SplineSetDef2FrameNumber);


int SplineIsWhere(Spline* spline, SplineDef* def) {

    if (!(def->fracCurr & 0x7FFF) && def->currKey == 0)
    {
        return -1;
    }
    
    if ((def->fracCurr & 0x7FFF) == (spline->numkeys - 1) && (def->currKey == 0))
    {
        return 1;
    }
    
    return 0;
}

short SplineMultiIsWhere(MultiSpline* multi) {
    short where;

    where = 0;

    if (multi->positional != NULL)
    {
        where = SplineIsWhere(multi->positional, &multi->curPositional);
    }

    if ((multi->rotational != NULL) && (where == 0))
    {
        where = SplineIsWhere((Spline *)multi->rotational, &multi->curRotational);
    }

    if ((multi->scaling != NULL) && (where == 0))
    {
        where = SplineIsWhere(multi->scaling, &multi->curScaling);
    }

    return where;
}

int func_800515B4(Spline* spline, SplineDef* def) {

    if (def == NULL || spline == NULL)
        return 0;
    
    if (((spline->numkeys - 1) >= def->currKey) && !(def->fracCurr & 0x7FFF)) {
        return 1;
    }
    
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800515F4);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80051638);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8005167C);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800516E0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80051734);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8005178C);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800517E4);

INCLUDE_ASM("asm/nonmatchings/_4f810", SplineGetData);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80051ED8);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80052038);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80052178);