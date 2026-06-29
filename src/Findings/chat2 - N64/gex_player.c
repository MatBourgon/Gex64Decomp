/*
 * gex_player.c — Gex player object process/collide functions (ROM 0x1BA60–0x1F5F0)
 * VRAM 0x8001AE60–0x8001E9F0
 *
 * IDENTITY: This module is the Gex player (Instance object type 3) combined
 * processFunc and collideFunc. func_8001AE60 is registered in the object
 * function table for the "gex" actor as BOTH processFunc and collideFunc
 * (confirmed by the comment in 33230.c: "func_8001AE60: ([2, 3], 3)").
 *
 * STRUCTURE:
 *   func_8001AE60  — GEX_Process: main per-frame update. Reads GameTracker
 *                    state, dispatches to a per-mode handler via a function
 *                    pointer table at VRAM 0x8006D33C indexed by instance->_F4[0]
 *                    (the movement state: 0=air, 1=walk, 2=run, 3=slide, 4=swim…).
 *                    After dispatch it handles collectible counters, level completion
 *                    triggers, sound events, and calls the shared movement finalization
 *                    routines (func_80024A80, func_80023E9C, func_80024C30).
 *
 *   func_8001B760  — GEX_UpdateShadowFromCollide: called from LIGHT_CalcShadowPositions
 *                    (LIGHT3D.c) when instance == PlayerInstance. Copies the 28-byte
 *                    result block from a PCollideInfo back into PlayerInstance->matrix[1],
 *                    giving the shadow renderer the collision contact point/normal.
 *
 *   func_8001B7C0  — GEX_IntegrateVelocityZ: reads instance->{_D8, _E4, _F0},
 *                    adds _E4 (vertical acceleration/gravity delta) to _D8 (vertical
 *                    velocity), clamps it against -_F0 (terminal velocity), then
 *                    adds the result to instance->position.z (offset 0x4C).
 *
 *   func_8001B804  — GEX_MovementUpdate: the per-frame movement handler shared across
 *                    most states. Handles spline-following logic (when _F8 == 0x800),
 *                    platform surface detection, camera interaction, jump state transitions,
 *                    angular velocity integration (calls ratan2, MATH3D_FastSqrt,
 *                    func_8004AD5C), and fires scripted sound/animation events
 *                    (calls func_80050508 for sound, func_80025588 for animation).
 *
 *   func_8001BDB8  — GEX_HandlePlatformInteraction
 *   func_8001C260  — GEX_HandleJumpLand
 *   func_8001C438  — GEX_HandleSwim
 *   func_8001C4F8  — GEX_HandleWallSlide
 *   func_8001C650  — GEX_HandleTailWhip
 *   func_8001C738  — GEX_HandleTongueLatch
 *   func_8001C920  — GEX_HandleSurfaceType: dispatches on collision face surface type
 *                    to apply material effects (ice, conveyor, bounce, etc.)
 *   func_8001C978  — GEX_ApplySurfaceEffect
 *   func_8001CB9C  — GEX_HandleDeath
 *   func_8001CDFC  — GEX_HandleRespawn
 *   func_8001CE54  — GEX_HandleRemotePickup
 *   func_8001CF90  — GEX_HandleCheckpoint
 *   func_8001CFE8  — GEX_HandleTVEnter: triggers level-exit TV animation
 *   func_8001D180  — GEX_HandleFallDeath
 *   func_8001D29C  — GEX_UpdateCamera
 *   func_8001D950  — GEX_HandleCinematicTeleport: rabbit-hole / warp transitions
 *   func_8001DA8C  — GEX_HandleCostumeChange
 *   func_8001DC80  — GEX_HandleEnemyHit
 *   func_8001DDD8  — GEX_ApplyKnockback
 *   func_8001DE2C  — GEX_HandleInvincibility
 *   func_8001DE8C  — GEX_HandleIdle
 *   func_8001DFC0  — GEX_UpdateAnimFrame
 *   func_8001E064  — GEX_HandleTongueRetract
 *   func_8001E0C4  — GEX_HandleGrappleRelease
 *   func_8001E114  — GEX_HandleWallKick
 *   func_8001E154  — GEX_HandleLedgeGrab
 *   func_8001E1C0  — GEX_HandleCollisionResponse: main per-face collision response,
 *                    called 3× from func_8001AE60 for normal/floor/ceiling contacts
 *   func_8001E368  — GEX_ResolveOverlap
 *   func_8001E648  — GEX_HandleWaterEntry
 *   func_8001E6E0  — GEX_HandleWaterExit
 *   func_8001E838  — GEX_HandlePortalTransition
 *   func_8001E874  — GEX_HandleTailSwipe
 *   func_8001E980  — GEX_ResetAfterHit (already decompiled in decomp)
 *   func_8001E9AC  — GEX_HandleBounce
 *
 * KEY GLOBAL STATE (accessed via GameTracker* at 0x8007FCC8):
 *   gameTracker->level                 — Level*
 *   gameTracker->player                — PlayerInstance (also at 0x8006CFA0)
 *   gameTracker->_4BF4                 — Gex life/state timer
 *   gameTracker->_4C12 / _4C0C / _4CA1 — level/game mode flags
 *   gameTracker->_4C63                 — cinematic mode flag
 *   gameTracker->_4BF8                 — warp/zone state
 *
 * MOVEMENT STATE MACHINE (instance->_F4[0]):
 *   0 = airborne / falling
 *   1 = grounded (walking/idle)
 *   2 = running
 *   3 = sliding
 *   4 = climbing / swimming
 *   5 = dead / dying
 *   6 = cinematic / scripted (overworld map, end-TV cutscene)
 *  [7+] = level-specific special states (set by level overlay)
 *
 * DISPATCH TABLE at VRAM 0x8006D33C (indexed by _F4[0], 7 entries):
 *   [0] 0x80027BA0  — airborne movement handler
 *   [1] 0x80027E7C  — grounded movement handler
 *   [2] 0x800280A0  — run movement handler
 *   [3] 0x8002829C  — slide movement handler
 *   [4] 0x80028454  — climb/swim movement handler
 *   [5] 0x00000000  — (null / death state — no dispatch)
 *   [6] 0x8015E038  — scripted / cinematic (in level code overlay)
 */

#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/PCollideInfo.h"
#include "types/BSPTree.h"

/* Forward declarations within this module */
void GEX_HandleSurfaceType(Instance* instance, GameTracker* gameTracker,
                            void* level, void* levelData);
void GEX_HandleCollisionResponse(Instance* instance, GameTracker* gameTracker,
                                  void* level, void* levelData);
void GEX_HandleFallDeath(Instance* instance, GameTracker* gameTracker);
void GEX_HandleCinematicTeleport(Instance* instance, GameTracker* gameTracker);
void GEX_HandleEnemyHit(void* instance, GameTracker* gameTracker, void* hitData);
void GEX_HandleCollisionResponse(Instance* instance, GameTracker* gameTracker,
                                   void* level, void* levelData);

INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_Process);           /* func_8001AE60 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_UpdateShadowFromCollide); /* func_8001B760 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_IntegrateVelocityZ);  /* func_8001B7C0 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_MovementUpdate);    /* func_8001B804 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandlePlatformInteraction); /* func_8001BDB8 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleJumpLand);    /* func_8001C260 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleSwim);        /* func_8001C438 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleWallSlide);   /* func_8001C4F8 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleTailWhip);    /* func_8001C650 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleTongueLatch); /* func_8001C738 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleSurfaceType); /* func_8001C920 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_ApplySurfaceEffect);/* func_8001C978 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleDeath);       /* func_8001CB9C */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleRespawn);     /* func_8001CDFC */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleRemotePickup);/* func_8001CE54 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleCheckpoint);  /* func_8001CF90 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleTVEnter);     /* func_8001CFE8 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleFallDeath);   /* func_8001D180 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_UpdateCamera);      /* func_8001D29C */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleCinematicTeleport); /* func_8001D950 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleCostumeChange);/* func_8001DA8C */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleEnemyHit);    /* func_8001DC80 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_ApplyKnockback);    /* func_8001DDD8 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleInvincibility);/* func_8001DE2C */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleIdle);        /* func_8001DE8C */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_UpdateAnimFrame);   /* func_8001DFC0 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleTongueRetract);/* func_8001E064 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleGrappleRelease);/* func_8001E0C4 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleWallKick);    /* func_8001E114 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleLedgeGrab);   /* func_8001E154 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleCollisionResponse); /* func_8001E1C0 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_ResolveOverlap);    /* func_8001E368 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleWaterEntry);  /* func_8001E648 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleWaterExit);   /* func_8001E6E0 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandlePortalTransition); /* func_8001E838 */
INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleTailSwipe);   /* func_8001E874 */

/*
 * GEX_ResetAfterHit — already decompiled in decomp
 * Called when Gex takes damage and the hit-stun animation has completed.
 * Clears the invincibility frame counter and resets the animation byte.
 */
void GEX_ResetAfterHit(int* instance, int arg1, unsigned short* levelData) {
    if (!(levelData[0x45] & 0x10)) {
        instance[0x3E] = 0x80000;      /* reset velocity/momentum field */
        ((short*)instance)[0x2F] = 0;  /* clear knockback counter */
        ((char*)instance)[0x4E] = 0x21;/* restore normal animation state */
    }
}

INCLUDE_ASM("asm/nonmatchings/1BA60", GEX_HandleBounce);      /* func_8001E9AC */
