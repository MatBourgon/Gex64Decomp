#ifndef LEVEL_SPY_H_
#define LEVEL_SPY_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

void spy_qsofa_OnCreate(Instance* instance, GameTracker* gameTracker);
void spy_qsofa_OnUpdate(Instance* instance, GameTracker* gameTracker);
void spy_qsofa_OnCollide(Instance* instance, GameTracker* gameTracker);
void spy_launch_OnCreate(Instance* instance, GameTracker* gameTracker);
void spy_launch_OnUpdate(Instance* instance, GameTracker* gameTracker);
void spy_launch_OnCollide(Instance* instance, GameTracker* gameTracker);
void spy_onoff_OnCreate(Instance* instance, GameTracker* gameTracker);
void spy_onoff_OnUpdate(Instance* instance, GameTracker* gameTracker);
void spy_onoff_OnCollide(Instance* instance, GameTracker* gameTracker);
void spy_gnrobot_OnCreate(Instance* instance, GameTracker* gameTracker);
void spy_gnrobot_OnUpdate(Instance* instance, GameTracker* gameTracker);
void spy_gnrobot_OnCollide(Instance* instance, GameTracker* gameTracker);
void spy_btimer_OnCreate(Instance* instance, GameTracker* gameTracker);
void spy_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker);

#endif