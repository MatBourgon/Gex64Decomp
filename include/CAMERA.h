#ifndef CAMERA_H_
#define CAMERA_H_

#include "types/Vector.h"
#include "types/Camera.h"

int CAMERA_LengthSVector(SVECTOR* sv);
short CAMERA_AngleDifference(short angle0, short angle1);
int CAMERA_CameraLock(Camera* camera, int arg1);
int CAMERA_CameraUnlock(Camera* camera, int arg1);
int CAMERA_SetSmoothValue(Camera* camera, int arg1);
void CAMERA_Save(Camera* camera, int save) ;
void CAMERA_SetTimer(Camera* camera, int arg1);
void CAMERA_ChangeTo(CameraKey* key);

#endif