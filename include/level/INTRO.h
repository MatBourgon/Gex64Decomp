#ifndef LEVEL_INTRO_H_
#define LEVEL_INTRO_H_

#include "types/Instance.h"
#include "types/GameTracker.h"

void intro_rezzull_OnCreate(Instance* instance, GameTracker* gameTracker);
void intro_rezzull_OnUpdate(Instance* instance, GameTracker* gameTracker);
void intro_gexcopy_OnCreate(Instance* instance, GameTracker* gameTracker);
void intro_gexcopy_OnUpdate(Instance* instance, GameTracker* gameTracker);
void intro_gextext_OnCreate(Instance* instance, GameTracker* gameTracker);
void intro_gextext_OnUpdate(Instance* instance, GameTracker* gameTracker);
void intro_gectext_OnCreate(Instance* instance, GameTracker* gameTracker);
void intro_gectext_OnUpdate(Instance* instance, GameTracker* gameTracker);
void intro_remtext_OnCreate(Instance* instance, GameTracker* gameTracker);
void intro_remtext_OnUpdate(Instance* instance, GameTracker* gameTracker);
void intro_enttext_OnCreate(Instance* instance, GameTracker* gameTracker);
void intro_enttext_OnUpdate(Instance* instance, GameTracker* gameTracker);

#endif