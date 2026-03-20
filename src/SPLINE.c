#include "common.h"

#include "SPLINE.h"

extern int D_8007EB00;

void _SplineS2Pos(SVECTOR *p, long s, SplineKey *key, SplineKey *key2)
{
    long s2;
    long s3;
    long h0;
    long h1;
    long h2;
    long h3;
    int temp, temp2; // not from decls.h

    if (s != 0)
    {
        s2 = (s * s) >> D_8007EB00;

        temp = s2 * 2;

        s3 = (s2 * s) >> D_8007EB00;

        temp2 = s3 * 2;

        h0 = (temp2 - (s2 * 3)) + (1 << D_8007EB00);

        h1 = (temp - temp2) + s2;

        h2 = (s3 - temp) + s;

        h3 = s3 - s2;

        p->x = (short)(((key->point.x * h0) + (key2->point.x * h1) + (key->dd.x * h2) + (key2->ds.x * h3)) >> D_8007EB00);
        p->y = (short)(((key->point.y * h0) + (key2->point.y * h1) + (key->dd.y * h2) + (key2->ds.y * h3)) >> D_8007EB00);
        p->z = (short)(((key->point.z * h0) + (key2->point.z * h1) + (key->dd.z * h2) + (key2->ds.z * h3)) >> D_8007EB00);
    }
    else
    {
        p->x = key->point.x;
        p->y = key->point.y;
        p->z = key->point.z;
    }
}

short func_80050E04(Spline* spline, short length) {
    short i;
    short count;
    int isRot;
    SplineKey* skey;
    SplineRotKey* srkey;

    i = 0;
    count = 0;
    skey = spline->key;
    srkey = (SplineRotKey*)spline->key;
    if (spline != NULL) {
        isRot = spline->type == 1;
        while (i < spline->numkeys && i < length) {
            
            if (isRot != 0) {
                count += srkey->count;
            } else {
                count += skey->count;
            }
            
            if (isRot != 0) {
                srkey++;
            } else {
                skey++;
            }
            i++;
        }
    }
    return count;
}

void SplineSetDefDenom(Spline* spline, SplineDef* def, int denomFlag) {
    unsigned int denom;

    if (def->denomFlag != denomFlag) {
        if (def->fracCurr != 0) {
            if (spline->type == 1) {
                denom = ((RSpline*)spline)->key[def->currkey].count;
            } else {
                denom = spline->key[def->currkey].count;
            }
            
            if (denom == 0) {
                denom = 1;
            }
            
            if (denomFlag != 0) {
                def->fracCurr = (def->fracCurr * denom) >> 15;
            } else {
                def->fracCurr = ((def->fracCurr << 15) / denom);
            }
        }
        
        def->denomFlag = denomFlag;
    }
}

INCLUDE_ASM("asm/nonmatchings/SPLINE", func_80050F98);

unsigned short SplineGetFrameNumber(Spline *spline, SplineDef *def)
{
    unsigned short frame;
    unsigned int i;
    unsigned int count;
    SplineKey *key;
    SplineDef temp;

    if ((spline == NULL) || (def == NULL))
    {
        frame = 0xFFFF;
    }
    else
    {
        key = spline->key;

        temp = *def;
        count = def->currkey;

        frame = 0;

        for (i = 0; i < count; i++, key++)
        {
            frame += key->count;
        }

        temp.currkey = i;

        SplineSetDefDenom(spline, &temp, 0);

        frame += (temp.fracCurr);
    }

    return frame & 0xFFFF;
}

short SplineSetDef2FrameNumber(Spline *spline, SplineDef *def, unsigned short frame_number)
{
    unsigned long isRot;
    short status;
    SplineKey *key;
    SplineRotKey *rkey;
    unsigned short frame;
    short deltaFrame;
    int temp; // not from decls.h

    status = 0;

    frame = 0;

    def->currkey = 0;

    def->fracCurr = 0;

    if ((spline == NULL) || (def == NULL))
    {
        status = -1;
    }
    else
    {
        rkey = (SplineRotKey *)spline->key;

        isRot = spline->type == 1;

        key = (SplineKey *)rkey;

        while (frame < frame_number)
        {
            if (def->currkey < spline->numkeys)
            {
                deltaFrame = frame_number - frame;

                if (deltaFrame < ((isRot != 0) ? rkey->count : key->count))
                {
                    def->fracCurr = deltaFrame;
                    break;
                }
                else
                {
                    temp = frame;

                    if (isRot != 0)
                    {
                        temp += rkey->count;

                        frame = temp;
                    }
                    else
                    {
                        temp += key->count;

                        frame = temp;
                    }

                    def->currkey = (def->currkey + 1) % spline->numkeys;

                    key += 1;

                    if (def->currkey != 0)
                    {
                        rkey += 1;
                    }
                    else
                    {
                        rkey = (SplineRotKey *)spline->key;

                        key = (SplineKey *)rkey;
                    }
                }
            }
            else
            {
                break;
            }
        }

        def->denomFlag = 0;
    }

    return status;
}

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

INCLUDE_ASM("asm/nonmatchings/SPLINE", func_8005167C);

INCLUDE_ASM("asm/nonmatchings/SPLINE", func_800516E0);


extern SVECTOR D_800AF070; // static in SplineGetNextPoint

SVECTOR* SplineGetNextPoint(Spline* spline, SplineDef* def) {

    if ((SplineGetNext(spline, def) != 0) && ((SplineGetData(spline, def, &D_800AF070) != 0))) {
        return &D_800AF070;
    }
    return NULL;
}

extern SVECTOR D_800AF078; // static in SplineGetPreviousPoint

SVECTOR *SplineGetPreviousPoint(Spline *spline, SplineDef *def)
{
    if ((SplineGetPrev(spline, def) != 0) && (SplineGetData(spline, def, &D_800AF078) != 0))
    {
        return &D_800AF078;
    }

    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/SPLINE", func_800517E4);

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

int SplineGetQuatData(Spline* spline, SplineDef* def, void* p) {
    G2Quat quat;
    int count;
    int gotDataOk;

    gotDataOk = 0;
    count = 0x8000;
    if (spline != NULL) {
        if (def != NULL) {
            if (def->currkey < spline->numkeys && def->currkey >= 0) {
                gotDataOk = 1;
                if (!(def->denomFlag)) {
                    count = ((RSpline*)spline)->key[def->currkey].count;
                }
                if ((count != 0) && (def->fracCurr != 0)) {
                    G2Quat_Slerp_VM((def->fracCurr << 0xC) / count, &((RSpline*)spline)->key[def->currkey].q, (G2Quat*)((&((RSpline*)spline)->key[def->currkey].q.z) + 3), &quat, 0);
                } else {
                    quat = ((RSpline*)spline)->key[def->currkey].q;
                }
                *((G2Quat*)p) = quat;
            }
        }
    }
    return gotDataOk;
}

int SplineGetNext(Spline* spline, SplineDef* def) {
    int count;
    int movedSplineOk;
    int isRot;
    
    movedSplineOk = 0;
    if (spline != NULL && def != NULL) {
        isRot = spline->type == 1;
        if (def->currkey < spline->numkeys) {
            movedSplineOk = 1;
            
            if (isRot != 0) {
                count = ((RSpline*)spline)->key[def->currkey].count;
            } else {
                count = spline->key[def->currkey].count;
            }
            
            SplineSetDefDenom(spline, def, 0);
            
            def->fracCurr++;
            
            if (def->fracCurr >= count) {
                def->currkey++;
                def->fracCurr = 0;
                
                if (def->currkey >= (spline->numkeys - 1)) {
                    if ((spline->numkeys - 1) < def->currkey) {
                        movedSplineOk = 0;
                    }
                    if ((spline->flags & 4) || (spline->flags & 6)) {
                        def->currkey = 0;
                    } else {
                        def->currkey = spline->numkeys - 1;
                    }
                }
            }
        }
    }
    return movedSplineOk;
}

int SplineGetPrev(Spline* spline, SplineDef* def) {
    int movedSplineOk;
    int isRot;
    int count;

    movedSplineOk = 0;
    if (spline != NULL && def != NULL) {
        SplineSetDefDenom(spline, def, 0);
        isRot = spline->type == 1;
        
        if (def->currkey < spline->numkeys) {
            
            
            if (def->fracCurr) {
                movedSplineOk = 1;
                def->fracCurr--;
                __asm("j .+0xC4"); // Hack
            } else
                movedSplineOk = 1;
            
            if (def->currkey <= 0) {
                if ((spline->flags & 4) || (spline->flags & 2)) {
                    def->currkey = spline->numkeys - 2;
                    if (isRot != 0) {
                        count = ((RSpline*)spline)->key[def->currkey].count;
                    }
                    else
                    {
                        count = spline->key[def->currkey].count;
                    }
                    def->fracCurr = count - 1;
                }
                else
                {
                    movedSplineOk = 0;
                    def->currkey = 0;
                    def->fracCurr = 0;
                }
            } else {
                def->currkey--;
                
                if (isRot != 0) {
                    count = ((RSpline*)spline)->key[def->currkey].count;
                } else {
                    count = spline->key[def->currkey].count;
                }
                def->fracCurr = count - 1;
            }
        }
    }
    return movedSplineOk;
}
