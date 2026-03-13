#ifndef LEVEL_GILLIG_H_
#define LEVEL_GILLIG_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

void gillig_couldrn_OnCreate(Instance* instance, GameTracker* gameTracker);
void gillig_couldrn_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gillig_couldrn_OnCollide(Instance* instance, GameTracker* gameTracker);
void gillig_tikifb_OnCreate(Instance* instance, GameTracker* gameTracker);
void gillig_tikifb_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gillig_tikifb_OnCollide(Instance* instance, GameTracker* gameTracker);
void gillig_tikifir_OnCreate(Instance* instance, GameTracker* gameTracker);
void gillig_tikifir_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gillig_tikifir_OnCollide(Instance* instance, GameTracker* gameTracker);
void gillig_hedhntr_OnCreate(Instance* instance, GameTracker* gameTracker);
void gillig_hedhntr_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gillig_hedhntr_OnCollide(Instance* instance, GameTracker* gameTracker);

#endif