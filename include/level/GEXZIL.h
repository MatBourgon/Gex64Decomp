#ifndef LEVEL_GEXZIL_H_
#define LEVEL_GEXZIL_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

void gexzil_bug_OnCreate(Instance* instance, GameTracker* gameTracker);
void gexzil_bug_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gexzil_bug_OnCollide(Instance* instance, GameTracker* gameTracker);
void gexzil_ebolt_OnCreate(Instance* instance, GameTracker* gameTracker);
void gexzil_ebolt_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gexzil_bldg_OnCreate(Instance* instance, GameTracker* gameTracker);
void gexzil_bldg_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gexzil_bldg_OnCollide(Instance* instance, GameTracker* gameTracker);
void gexzil_mecha_OnCreate(Instance* instance, GameTracker* gameTracker);
void gexzil_mecha_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gexzil_mecha_OnCollide(Instance* instance, GameTracker* gameTracker);
void gexzil_mekblst_OnCreate(Instance* instance, GameTracker* gameTracker);
void gexzil_mekblst_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gexzil_mechjet_OnCreate(Instance* instance, GameTracker* gameTracker);
void gexzil_mechjet_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gexzil_mechjet_OnCollide(Instance* instance, GameTracker* gameTracker);
void gexzil_gas_OnCreate(Instance* instance, GameTracker* gameTracker);
void gexzil_gas_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gexzil_gas_OnCollide(Instance* instance, GameTracker* gameTracker);
void gexzil_explode_OnCreate(Instance* instance, GameTracker* gameTracker);
void gexzil_explode_OnUpdate(Instance* instance, GameTracker* gameTracker);
void gexzil_explode_OnCollide(Instance* instance, GameTracker* gameTracker);

#endif