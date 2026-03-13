#ifndef LEVEL_AZTEC_H_
#define LEVEL_AZTEC_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

void aztec_funplat_OnCreate(Instance* instance, GameTracker* gameTracker);
void aztec_funplat_OnUpdate(Instance* instance, GameTracker* gameTracker);
void aztec_funplat_OnCollide(Instance* instance, GameTracker* gameTracker);
void aztec_btimer_OnCreate(Instance* instance, GameTracker* gameTracker);
void aztec_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker);

#endif