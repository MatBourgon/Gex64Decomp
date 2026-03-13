#ifndef LEVEL_NYPD_H_
#define LEVEL_NYPD_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

void nypd_slider_OnCreate(Instance* instance, GameTracker* gameTracker);
void nypd_slider_OnUpdate(Instance* instance, GameTracker* gameTracker);
void nypd_slider_OnCollide(Instance* instance, GameTracker* gameTracker);
void nypd_btimer_OnCreate(Instance* instance, GameTracker* gameTracker);
void nypd_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker);

#endif