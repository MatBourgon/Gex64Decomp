#ifndef LEVEL_MOOSHU_H_
#define LEVEL_MOOSHU_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

void mooshu_moo_OnCreate(Instance* instance, GameTracker* gameTracker);
void mooshu_moo_OnUpdate(Instance* instance, GameTracker* gameTracker);
void mooshu_moo_OnCollide(Instance* instance, GameTracker* gameTracker);
void mooshu_moobar_OnCreate(Instance* instance, GameTracker* gameTracker);
void mooshu_moobar_OnCollide(Instance* instance, GameTracker* gameTracker);
void mooshu_moolevr_OnCreate(Instance* instance, GameTracker* gameTracker);
void mooshu_moolevr_OnUpdate(Instance* instance, GameTracker* gameTracker);
void mooshu_moolevr_OnCollide(Instance* instance, GameTracker* gameTracker);
void mooshu_moosprk_OnCreate(Instance* instance, GameTracker* gameTracker);
void mooshu_moosprk_OnUpdate(Instance* instance, GameTracker* gameTracker);
void mooshu_moosprk_OnCollide(Instance* instance, GameTracker* gameTracker);
void mooshu_jacob_OnCreate(Instance* instance, GameTracker* gameTracker);
void mooshu_jacob_OnUpdate(Instance* instance, GameTracker* gameTracker);
void mooshu_ebolt_OnCreate(Instance* instance, GameTracker* gameTracker);
void mooshu_ebolt_OnUpdate(Instance* instance, GameTracker* gameTracker);
void mooshu_vandb_OnCreate(Instance* instance, GameTracker* gameTracker);
void mooshu_vandb_OnUpdate(Instance* instance, GameTracker* gameTracker);

#endif