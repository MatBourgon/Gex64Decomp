#include "common.h"

#include "types/Spline.h"
#include "types/G2EulerAngles.h"

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

INCLUDE_ASM("asm/nonmatchings/_4f810", _SplineS2Pos);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050E04);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050EA0);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_80050F98);

INCLUDE_ASM("asm/nonmatchings/_4f810", SplineGetFrameNumber);

INCLUDE_ASM("asm/nonmatchings/_4f810", SplineSetDef2FrameNumber);

int SplineIsWhere(Spline* spline, SplineDef* def) {

    if (!(def->fracCurr) && def->currkey == 0)
    {
        return -1;
    }
    
    if ((def->fracCurr) == (spline->numkeys - 1) && (def->currkey == 0))
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
    
    if (((spline->numkeys - 1) >= def->currkey) && !(def->fracCurr)) {
        return 1;
    }
    
    return 0;
}

G2Quat* SplineGetFirstRot(RSpline* rspline, SplineDef* def) {
    if (rspline == NULL) return NULL;
    
    def->fracCurr = 0;
    def->currkey = 0;
    def->denomFlag = 0;
    return &rspline->key->q;
}

SVECTOR* SplineGetFirstPoint(Spline* spline, SplineDef* def) {
    if (spline == NULL) return NULL;
    
    def->fracCurr = 0;
    def->currkey = 0;
    def->denomFlag = 0;
    return &spline->key->point;
}

INCLUDE_ASM("asm/nonmatchings/_4f810", func_8005167C);

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800516E0);


extern SVECTOR D_800AF070; // static in SplineGetNextPoint

SVECTOR* SplineGetNextPoint(Spline* spline, SplineDef* def) {

    if ((SplineGetOffsetNext(spline, def) != 0) && ((SplineGetData(spline, def, &D_800AF070) != 0))) {
        return &D_800AF070;
    }
    return NULL;
}

extern SVECTOR D_800AF078; // static in SplineGetPreviousPoint

SVECTOR *SplineGetPreviousPoint(Spline *spline, SplineDef *def)
{
    if ((SplineGetOffsetPrev(spline, def) != 0) && (SplineGetData(spline, def, &D_800AF078) != 0))
    {
        return &D_800AF078;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/_4f810", func_800517E4);

extern int D_8007EB00;
int SplineGetData(Spline* spline, SplineDef* def, void* p) {
    G2Quat quat;
    G2EulerAngles ea;
    int count;
    int isRot;
    int gotDataOk;

    gotDataOk = 0;
    count = 0x8000;
    if (spline != NULL && def != NULL) {
        isRot = spline->type == 1;
        if (def->currkey < spline->numkeys && def->currkey >= 0) {
            gotDataOk = 1;
            
            if (!(def->denomFlag)) {
                if (spline->type == 1) {
                    count = ((RSpline*)spline)->key[def->currkey].count;
                } else {
                    count = spline->key[def->currkey].count;
                }
            }
            
            if ((count != 0) && (def->fracCurr) != 0) {
                if (isRot != 0)
                {
                    G2Quat_Slerp_VM((def->fracCurr << 12) / count, &((RSpline *)spline)->key[def->currkey].q, &((RSpline *)spline)->key[def->currkey + 1].q, &quat, 0);
                }
                else
                {
                    _SplineS2Pos((SVECTOR *)p, (def->fracCurr << D_8007EB00) / count, &spline->key[def->currkey], &spline->key[def->currkey] + 1);
                }
            } else if (isRot != 0) {
                quat = ((RSpline*)spline)->key[def->currkey].q;
            } else {
                ((SVECTOR*)p)->x = spline->key[def->currkey].point.x;
                ((SVECTOR*)p)->y = spline->key[def->currkey].point.y;
                ((SVECTOR*)p)->z = spline->key[def->currkey].point.z;
            }
            if (isRot != 0) {
                G2Quat_ToEuler(&quat, &ea);
                *(G2EulerAngles*)p = ea;
            }
        }
    }
    return gotDataOk;
}

INCLUDE_ASM("asm/nonmatchings/_4f810", SplineGetQuatData);

INCLUDE_ASM("asm/nonmatchings/_4f810", SplineGetOffsetNext);

INCLUDE_ASM("asm/nonmatchings/_4f810", SplineGetOffsetPrev);