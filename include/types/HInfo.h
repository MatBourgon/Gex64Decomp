#ifndef THINFO_T_
#define THINFO_T_

#include "types/Face.h"
#include "types/HSphere.h"
#include "types/HBox.h"

typedef struct
{
    long numHFaces;
    HFace* hfaceList;
    long numHSpheres;
    HSphere* hsphereList;
    long numHBoxes;
    HBox* hboxList;
} HInfo;

#endif