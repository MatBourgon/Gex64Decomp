#ifndef SCRIPT_H_
#define SCRIPT_H_

#include "types/Instance.h"
#include "types/Spline.h"

MultiSpline* SCRIPT_GetMultiSpline(Instance *instance, int *isParent, int *isClass);

SplineDef *SCRIPT_GetPosSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);
SplineDef *SCRIPT_GetRotSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);
SplineDef *SCRIPT_GetScaleSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);

Spline *ScriptGetPosSpline(Instance *instance);
RSpline *ScriptGetRotSpline(Instance *instance);

short SCRIPT_CountFramesInSpline(Instance *instance);

int SCRIPT_GetSplineFrameNumber(Instance* arg0, SplineDef* arg1);

MultiSpline* SCRIPT_GetMultiSpline(Instance *instance, int *isParent, int *isClass);

SplineDef *SCRIPT_GetPosSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);

SplineDef *SCRIPT_GetRotSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);

SplineDef *SCRIPT_GetScaleSplineDef(Instance *instance, MultiSpline *multi, int isParent, int isClass);

void SCRIPT_RelativisticSpline(Instance *instance, SVECTOR *point);

void SCRIPT_InstanceSplineSet(Instance* instance, short frameNum, SplineDef* splineDef, SplineDef* rsplineDef, SplineDef* ssplineDef);

int SCRIPT_SplineProcess(Instance* instance, MultiSpline* multi, SplineDef* splineDef, SplineDef* rsplineDef, SplineDef* ssplineDef, int direction, int isClass);
int SCRIPT_InstanceSplineProcess(Instance* instance, SplineDef* splineDef, SplineDef* rsplineDef, SplineDef* ssplineDef, int direction);

#endif