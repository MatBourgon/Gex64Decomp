#ifndef SPLINE_H_
#define SPLINE_H_

#include "types/Spline.h"
#include "types/G2EulerAngles.h"

void _SplineS2Pos(SVECTOR *p, long s, SplineKey *key, SplineKey *key2);

short func_80050E04(Spline* spline, short length);

void SplineSetDefDenom(Spline* spline, SplineDef* def, int denomFlag);

unsigned short SplineGetFrameNumber(Spline *spline, SplineDef *def);

short SplineSetDef2FrameNumber(Spline *spline, SplineDef *def, unsigned short frame_number);

int SplineIsWhere(Spline* spline, SplineDef* def);

short SplineMultiIsWhere(MultiSpline* multi);

int func_800515B4(Spline* spline, SplineDef* def);

G2Quat* SplineGetFirstRot(RSpline* rspline, SplineDef* def);

SVECTOR* SplineGetFirstPoint(Spline* spline, SplineDef* def);

SVECTOR* SplineGetNextPoint(Spline* spline, SplineDef* def);

SVECTOR *SplineGetPreviousPoint(Spline *spline, SplineDef *def);

int SplineGetData(Spline* spline, SplineDef* def, void* p);

int SplineGetQuatData(Spline* spline, SplineDef* def, void* p);

int SplineGetNext(Spline* spline, SplineDef* def);

#endif