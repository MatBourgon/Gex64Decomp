/*
 * bsp_collide.c — BSPTree scripted-movement collision system (ROM 0x1F5F0–0x231E0)
 * VRAM 0x8001E9F0–0x800231E0
 *
 * IDENTITY: This module handles collision detection and physical response for
 * instances that are following scripted paths (splines, cinematics, cutscene
 * triggers, rabbit-hole teleporters). It is the "dynamic collision" counterpart
 * to the static HFace/HInfo system in COLLIDE_A–I.
 *
 * The module operates on a BSPTree node (instance->bspTree, offset 0x78):
 *
 *   BSPTree {
 *     int   _00;               // node flags / type
 *     short _04;               // primary state / collision type
 *     short _06;               // secondary state / sub-type
 *     u8*   _08;               // pointer to first contact surface data
 *     u8*   _0C;               // pointer to second contact surface data
 *     int   _10;               // frame accumulator / distance
 *     Instance* instanceSpline;// linked spline instance (cinematics)
 *   }
 *
 * COLLISION TYPE DISPATCH (bspTree->_04 and bspTree->_06 values):
 *   _04 == 1: cinematic / cutscene movement (instanceSpline path)
 *   _04 == 2: conveyor / one-way surface contact
 *   _04 == 4: trigger volume entry (rabbit-hole, TV portal)
 *   _06 == 1: initial contact frame
 *   _06 == 2: sustained contact
 *   _06 == 3: contact with bounce/reflect
 *   _06 == 5: exit / release
 *
 * FUNCTION MAP:
 *
 *   func_8001E9F0  — BSP_ProcessCollision: top-level per-frame collision response
 *                    dispatcher. Checks instance->_F4[0] (movement state) and
 *                    _F4[2] (flags word) to determine if scripted movement is
 *                    active. Reads bspTree->_04/_06 and branches to the
 *                    appropriate sub-handler. Applies velocity deltas to
 *                    instance->position.{x,y,z} (offsets 0x48,0x4A,0x4C) and
 *                    calls COLLIDE_UpdateAllTransforms (func_80012BD0).
 *
 *   func_8001EF4C  — BSP_DispatchContactType: secondary dispatcher on
 *                    bspTree->_08->_04 (surface contact byte). Branches on
 *                    instance->_F8 (visual/physics mode flags) to apply
 *                    surface-specific responses:
 *                      0x10  = standard ground contact
 *                      0x20  = slope contact
 *                      0x80  = water surface
 *                      0x200 = ice
 *                      0x2000= bouncer
 *                      0x4000= conveyor
 *                      0x10000=trigger
 *                    Sets instance->_FC flags (physics state bits) accordingly.
 *                    For water entry (flag 0x2000 in bspTree->_0C->_02) calls
 *                    func_80018DC0 (water splash effect) and sets _FC |= 0x8.
 *
 *   func_8001F124  — BSP_ProcessScriptedInstance: per-frame update for instances
 *                    in scripted/cinematic movement. Calls func_80024C84
 *                    (COLLIDE_ClearFaceCache), then based on _F4[0] and _F8:
 *                    - If _F4[0]==1 and _FC has 0x1000: calls func_8000B054
 *                      (trigger level-complete event)
 *                    - If _F8 & 0x7000 (multi-axis movement): calls func_8000F7F0
 *                      with the instance's XYZ offsets to update the render
 *                      transform, then calls func_8001E9F0 (self-recurse for
 *                      collision), func_80021DAC (BSP_ApplyContact), and
 *                      func_80021C68 (BSP_FinalizeFrame)
 *                    - If _F4[0]==4: calls func_8000B054 (swim zone trigger)
 *                    - Otherwise: calls func_800215D4 → func_80021330 → 
 *                      func_80021C68 (standard scripted path update)
 *                    Manages instance->_8A (contact flags) and instance->_70
 *                    (current contact spline instance pointer).
 *
 *   func_8001F444  — BSP_ResolveNormal: computes the collision normal from a
 *                    face contact. Called after any face-hit in func_8001F124.
 *
 *   func_8001F6F4  — BSP_HandleSlope: handles slope/incline collision response,
 *                    projects velocity onto the slope plane.
 *
 *   func_80020164  — BSP_CheckGroundContact
 *   func_800201B4  — BSP_ApplyGroundFriction
 *   func_80020238  — BSP_HandleConveyor
 *   func_80020498  — BSP_HandleBouncer
 *   func_800205A8  — BSP_HandleIce
 *
 *   func_80020E04  — BSP_HandleCinematicPath: drives the instance along
 *                    bspTree->instanceSpline's spline track. Called when
 *                    _04 == 1. Reads SplineKey frames via SplineGetNextPoint /
 *                    SplineGetPreviousPoint, interpolates position using the
 *                    MultiSpline definition, and updates instance->position.
 *                    Controls the "rabbit hole" and "TV enter" transitions:
 *                    when the spline ends, fires the teleport event via
 *                    func_80033354 / func_8003335C.
 *
 *   func_800210B4  — BSP_StepSpline: advances one spline keyframe, updates
 *                    bspTree->_10 (frame accumulator) and _04 state.
 *
 *   func_80021330  — BSP_UpdateInstanceTransform: recomputes the instance world
 *                    matrix from current position + rotation. Called every frame
 *                    during scripted movement before rendering.
 *
 *   func_80021500  — BSP_ComputeContactNormal
 *
 *   func_800215D4  — BSP_ProjectVelocity: projects the instance's velocity
 *                    vector onto the current contact surface. Called from
 *                    func_8001F124 for standard (non-cinematic) scripted paths.
 *
 *   func_8002180C  — BSP_TestSphereVsWorld: sphere-vs-world collision test,
 *                    called 3× per frame from func_8001F124 (once for head,
 *                    once for body, once for feet). Updates bspTree->_08/_0C.
 *
 *   func_800218B0  — BSP_TestRayVsWorld: ray-cast collision test.
 *   func_800219D0  — BSP_TestBoxVsWorld: AABB collision test.
 *
 *   func_80021A78  — BSP_QueryHFaceList: walks the HFace list (collision mesh
 *                    triangles) for a candidate set. Inner loop of all three
 *                    shape tests above.
 *
 *   func_80021B1C  — BSP_SelectNearestFace: given multiple face hits from
 *                    BSP_QueryHFaceList, selects the nearest penetrating face.
 *
 *   func_80021C68  — BSP_FinalizeFrame: writes the resolved contact normal and
 *                    position delta back into the instance. Final step of the
 *                    per-frame scripted collision pipeline.
 *
 *   func_80021DAC  — BSP_ApplyContact: applies the contact response to the
 *                    instance's velocity. Called 4× from func_8001F124 (once
 *                    per active contact surface).
 *
 *   func_80021EE8  — BSP_HandleTriggerVolume: fires trigger-volume events
 *                    (remotes, checkpoints, teleporters) when bspTree->_04 == 4.
 *
 *   func_800222A4  — BSP_HandleWaterVolume: water-entry/exit detection.
 *
 *   func_800223F8  — BSP_HandleConveyorContact: per-contact conveyor belt
 *                    velocity addition. Called from func_8001E9F0.
 *
 *   func_800224CC  — BSP_SetContactState: sets bspTree->_04 and bspTree->_06
 *                    to the given (type, subtype) pair. Central state setter.
 *
 * The three wrappers already decompiled (retained from decomp):
 *
 *   func_80022714  — calls BSP_SetContactState(instance, gt, 0, 0) → clear
 *   func_80022738  — calls BSP_SetContactState(instance, gt, 1, 0) → cinematic
 *   func_8002275C  — calls BSP_SetContactState(instance, gt, 1, 1) → cinematic+sub1
 *
 *   func_80022780  — BSP_HandleSlideContact
 *   func_80022810  — BSP_HandleBouncerContact
 *   func_80022918  — BSP_HandlePortalContact: rabbit-hole / TV warp entry logic
 *   func_80022D54  — BSP_EvaluateSplineSegment
 *   func_80023150  — BSP_ComputeSplineVelocity
 */

#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/BSPTree.h"
#include "types/Spline.h"

INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_ProcessCollision);       /* func_8001E9F0 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_DispatchContactType);    /* func_8001EF4C */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_ProcessScriptedInstance);/* func_8001F124 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_ResolveNormal);          /* func_8001F444 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleSlope);            /* func_8001F6F4 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_CheckGroundContact);     /* func_80020164 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_ApplyGroundFriction);    /* func_800201B4 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleConveyor);         /* func_80020238 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleBouncer);          /* func_80020498 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleIce);              /* func_800205A8 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleCinematicPath);    /* func_80020E04 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_StepSpline);             /* func_800210B4 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_UpdateInstanceTransform);/* func_80021330 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_ComputeContactNormal);   /* func_80021500 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_ProjectVelocity);        /* func_800215D4 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_TestSphereVsWorld);      /* func_8002180C */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_TestRayVsWorld);         /* func_800218B0 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_TestBoxVsWorld);         /* func_800219D0 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_QueryHFaceList);         /* func_80021A78 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_SelectNearestFace);      /* func_80021B1C */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_FinalizeFrame);          /* func_80021C68 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_ApplyContact);           /* func_80021DAC */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleTriggerVolume);    /* func_80021EE8 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleWaterVolume);      /* func_800222A4 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleConveyorContact);  /* func_800223F8 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_SetContactState);        /* func_800224CC */

/*
 * BSP_ClearContact — clears the BSPTree contact state for this instance.
 * Calls BSP_SetContactState(instance, gameTracker, 0, 0).
 */
void BSP_ClearContact(Instance* instance, GameTracker* gameTracker) {
    BSP_SetContactState(instance, gameTracker, 0, 0);
}

/*
 * BSP_SetCinematicContact — enters cinematic scripted movement mode.
 * Calls BSP_SetContactState(instance, gameTracker, 1, 0).
 */
void BSP_SetCinematicContact(Instance* instance, GameTracker* gameTracker) {
    BSP_SetContactState(instance, gameTracker, 1, 0);
}

/*
 * BSP_SetCinematicContactSub — enters cinematic mode with sub-state 1.
 * Calls BSP_SetContactState(instance, gameTracker, 1, 1).
 */
void BSP_SetCinematicContactSub(Instance* instance, GameTracker* gameTracker) {
    BSP_SetContactState(instance, gameTracker, 1, 1);
}

INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleSlideContact);     /* func_80022780 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandleBouncerContact);   /* func_80022810 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_HandlePortalContact);    /* func_80022918 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_EvaluateSplineSegment);  /* func_80022D54 */
INCLUDE_ASM("asm/nonmatchings/1F5F0", BSP_ComputeSplineVelocity);  /* func_80023150 */
