#ifndef COLLIDE_H_
#define COLLIDE_H_

#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/Vector.h"
#include "types/HBox.h"
#include "types/HInfo.h"
#include "types/PCollideInfo.h"

extern int D_8006CEF0;

extern int stat_clddyna[8];
extern int dyna_clddyna[8];
extern int dyna_cldstat[8];

typedef int(*CollisionFunction)(SVector*, HBox*);

extern int collide_t1; // collide_t0?
extern int collide_t0; // collide_t1?
extern SVector* collide_normal1;
extern SVector* collide_point0;
extern SVector* collide_point1;
extern SVector* collide_normal0;

int func_8000CEB4(SVector* arg0, SVector* arg1, SVector* arg2, SVector* arg3, int arg4);
void COLLIDE_InstanceList(InstanceList* instanceList, void* arg1 /*supposedly player instance*/);
void COLLIDE_PointAndWorld(PCollideInfo* pcollideInfo, GameTracker* gameTracker);
void COLLIDE_GetNormal(short nNum, short* nrmlArray, SVECTOR* nrml);
void COLLIDE_InsertPoint( SVector* point, SVector* normal, int* dist,
                    SVector* collidePoint0, SVector* normal0, int* collideT0,
                    SVector* collidePoint1, SVector* normal1, int* collideT1);
int COLLIDE_WithinYZBounds(SVector* point, HBox* hbox);
int COLLIDE_WithinXZBounds(SVector* point, HBox* hbox);
int COLLIDE_WithinXYBounds(SVector* point, HBox* hbox);
void COLLIDE_LineWithBoxFace(short startDist, long lineDist, short planeDist, SVector* start, LVECTOR* line, HBox* hbox, CollisionFunction collideBoundFunc, SVector* normal);
int COLLIDE_IntersectLineAndBox(SVector* point0, SVector* normal0, SVector* point1, SVector* normal1, SVector* end, SVector* start, HBox* hbox);
HBox* _COLLIDE_IntersectLineAndBoxList(SVector* end, SVector* start, HInfo* hinfo, SVector* normal);
int COLLIDE_ClosestPointInBoxToPoint(SVector* outPoint, HBox* box, SVector* point);
void _COLLIDE_MakeNormal(SVector* pNormal, SVector* point0, SVector* point1, SVector* point2);
void COLLIDE_UpdateAllTransforms(Instance* instance, SVECTOR* arg1, GameTracker* gameTracker);
void COLLIDE_UpdateAllOldTransforms(Instance* instance, SVECTOR* arg1, GameTracker* gameTracker);


#endif