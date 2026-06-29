/*
 * level_stubs_rezop.c — Decompiled stubs for REZOP level overlay
 * (Bugged Out / Rezopolis)
 *
 * 75 stubs documented. Same fragment pattern as LOONEY — many stubs are
 * continuations of larger functions split at branch targets.
 *
 * Key object types in Rezopolis:
 *   rrspark/rrgen/rrzap — electrical hazards on the railway
 *   rrdoor              — sliding doors
 *   rezrat              — robot rat enemy
 *   rezplat             — moving platform
 *   tbbttn/tbplat       — turntable button + platform
 *   rezfan              — fan platforms
 *   simontv/simon       — Simon-says puzzle TV
 *   rezbot              — robot enemy
 *   crnkplt/rezcrnk     — crank+platform mechanism
 *   snkplat             — snake platform
 *   rezbull             — bullet/projectile
 *   srchlit/spotlit     — searchlights
 *   spnplat             — spinning platform
 *   mutant              — mutant enemy (large boss-type)
 *   mtntsht             — mutant shot projectile
 *   rebggen/rbmastr/rebug — Rez robot bugs + master
 *   iris                — iris/portal object
 *   tvgen/tvgurny       — TV generator + gurney
 *   gas                 — gas hazard
 *   btimer              — boss timer
 *   markey              — Rez marquee display
 */

#include "common.h"
#include "level/REZOP.h"
#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/BSPTree.h"
#include "COLLIDE.h"

/* ── rezop_rrdoor ─────────────────────────────────────────────────────────── */

void rezop_rrdoor_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 2 instrs: addu a1,a0,zero; lw v1,0xF4(a1).
     * Tail-start — loading state machine state from _F4. Full update drives
     * door open/close animation (state 1=opening, 2=open, 3=closing). */
    int state = *(int*)((char*)instance + 0xF4);
    switch (state) {
    case 1: /* Opening */ func_8002DAF8(instance, 1);  break;
    case 2: /* Open — check close trigger */ break;
    case 3: /* Closing */ func_8002DAF8(instance, -1); break;
    }
}

/* ── rezop_rrspark ─────────────────────────────────────────────────────────── */

void rezop_rrspark_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instr: lw v0,0x10(a0). Loading flags before OR-ing in 0x100400. */
    int flags = *(int*)((char*)instance + 0x10);
    *(int*)((char*)instance + 0x10) = flags | 0x100400;  /* from rrgen_OnCreate pattern */
}

void rezop_rrspark_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 2 instrs: addiu sp,sp,-0x18; addu a1,a0,zero. Beginning of function. */
}

/* ── rezop_rezrat ──────────────────────────────────────────────────────────── */

void rezop_rezrat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x80159948. Sets up rezrat robot:
     * Loads flags 0x10400 | lui 0x10 | ori 0x400, addiu a1=0x18, a2=0.
     * Zeroes _F4. Then reads flags, ORs with 0x10400, stores back.
     */
    *(int*)((char*)instance + 0xF4) = 0;
    *(int*)((char*)instance + 0x10) |= 0x10400;
}

void rezop_rezrat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instr: addiu sp,sp,-0x28. Prologue-start only. 
     * Full update drives rezrat patrol and player-detection AI.
     * State: 0=patrol, 1=alert, 2=chase, 3=die. */
}

void rezop_rezrat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 2 instrs: addiu sp,sp,-0x28; sw s0,0x20(sp). Prologue-start. */
}

/* ── rezop_rrgen ───────────────────────────────────────────────────────────── */

void rezop_rrgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x80159D60. Railway generator:
     * Calls OBTABLE_FindObject at address 0x8016156C.
     * Sets _F4 = 2 (active state). ORs flags with 0x100080.
     */
    int obj = OBTABLE_FindObject((void*)0x8016156C);
    *(int*)((char*)instance + 0xF4) = 2;
    *(int*)((char*)instance + 0x10) |= 0x100080;
}

void rezop_rrgen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instr: addiu sp,sp,-0x20. Prologue-start only. */
}

/* ── rezop_rrzap ───────────────────────────────────────────────────────────── */

void rezop_rrzap_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instrs. ORs flags |= 0x100080, same as rrgen. */
    *(int*)((char*)instance + 0x10) |= 0x100080;
}

void rezop_rrzap_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015A038. Electric zap object:
     * Checks _F4 (state). If 0: check distance to player (same VRAM as gt->player).
     * If player within range (lw v1,0x48(s0); lw v0,0x48(a2)):
     *   addiu sp,0x100 (some large threshold) → trigger zap.
     */
    int state = *(int*)((char*)instance + 0xF4);
    if (state != 0) return;

    GameTracker* player = gameTracker->player;
    int px = *(int*)((char*)player + 0x48);
    int ix = *(int*)((char*)instance + 0x48);
    if (px == ix) {
        /* zap fired */
        *(int*)((char*)instance + 0xF4) = 1;
    }
}

/* ── rezop_rezplat ─────────────────────────────────────────────────────────── */

void rezop_rezplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015A15C. Sets initial state for moving platform:
     * _56=1 (active), _104=7 (speed), flags|=0x80. Reads _62/_64 for range. */
    *(short*)((char*)instance + 0x56) = 1;
    *(int*)  ((char*)instance + 0x104) = 7;
    *(int*)  ((char*)instance + 0x10) |= 0x80;
    /* Cache _62/_64 as movement limits in _108 */
    short lo = *(short*)((char*)instance + 0x62);
    *(int*)((char*)instance + 0x108) = lo;
}

void rezop_rezplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instrs: addiu sp,-0x60; sw s1,0x54(sp); addu s1,a0,zero. Prologue. */
}

/* ── rezop_tbbttn ──────────────────────────────────────────────────────────── */

void rezop_tbbttn_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instrs: lw v1,0xF4(a0); addiu v0,zero,1; bne v1,v0 → skip.
     * Full update: if _F4==1 (button pressed), call GenericProcess or signal. */
    if (*(int*)((char*)instance + 0xF4) == 1) {
        /* Button pressed — fire signal */
    }
}

void rezop_tbbttn_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015A6B8. Turntable button collision:
     * Reads bsp->_6 (contact type). If 1 (player contact):
     *   checks bsp->_14 == gameTracker->player (it's the player).
     * Loads gameTracker (0x8007-0x3060), reads player position.
     * Sets _F4=2 (button pressed state), fires signal.
     */
    BSPTree* bsp = instance->bspTree;
    if (*(short*)((char*)bsp + 6) != 1) return;
    if (*(void**)((char*)bsp + 0x14) != gameTracker->player) return;

    *(int*)((char*)instance + 0xF4) = 2;
}

/* ── rezop_tbplat ──────────────────────────────────────────────────────────── */

void rezop_tbplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015A7B4. Turntable platform: sets flags|=0x10, returns. */
    *(int*)((char*)instance + 0x10) |= 0x10;
}

void rezop_tbplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015A7C8. State machine:
     * _F4==1: some check, _F4!=1: compare _1C->data. */
    int state = *(int*)((char*)instance + 0xF4);
    if (state == 1) {
        /* Moving — advance position */
    } else {
        /* Stopped — check button signal */
        void* data = *(void**)((char*)instance + 0x1C);
        if (data) {
            /* check data[2*4] == 2 to activate */
        }
    }
}

/* ── rezop_rezfan ──────────────────────────────────────────────────────────── */

void rezop_rezfan_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015AABC. Fan platform init:
     * Reads flags and _24 (object def ptr). */
}

void rezop_rezfan_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015ABB4. Large fan update (0x98-byte frame, many s-regs).
     * Starts with addiu a1=1 and reading s4->_F4. Full fan animation. */
}

/* ── rezop_simontv / rezop_simon ─────────────────────────────────────────────
 * Simon Says puzzle: rezop_simontv drives the TV display, rezop_simon is the
 * controller. Player must repeat the pattern shown.
 * ─────────────────────────────────────────────────────────────────────────── */

void rezop_simontv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015B45C. Reads _1C->_4->_4 (linked object's child ptr).
     * Returns immediately — just validates linked chain exists. */
}

void rezop_simontv_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015B47C. Simon TV display state machine:
     * _F4==1 → set _C2=1 (show first color), _F4=3, jump.
     * _F4==2 → check instance->_100->_24 chain (other TVs).
     * Drives the 4-color Simon pattern display.
     */
    int state = *(int*)((char*)instance + 0xF4);
    if (state == 1) {
        *(short*)((char*)instance + 0xC2) = 1;
        *(int*)((char*)instance + 0xF4) = 3;
    } else if (state == 2) {
        /* check linked TV states */
    }
}

void rezop_simontv_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015B5F0. Sets up collision check with state 4.
     * Reads ra from sp+0x18 (has its own frame). */
}

void rezop_simon_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instr: addiu sp,sp,-0x20. Prologue-start. */
}

/* func_8015B750 — ◄FUNC► Triangle centroid helper.
 * Same algorithm as LOONEY's func_8015B934 (0x55555556 multiply-high /3 trick).
 * Reads 3 vertex indices from sp[0x18] and sp[0x1C] (base ptr),
 * computes weighted average XYZ, stores to sp[0].
 * Used by simon platform for position calculation. */
static void rezop_ComputeCentroid(int* out, short* v0, short* v1, short* v2) {
    out[0] = ((int)v0[0] + v1[0] + v2[0]) / 3;
    out[1] = ((int)v0[2] + v1[2] + v2[2]) / 3;
    out[2] = ((int)v0[4] + v1[4] + v2[4]) / 3;
}

/* func_8015B9AC — ◄FUNC► Rotation matrix builder (XYZ, same as looney's func_8015BC04).
 * Calls func_800162C0, then RotMatrixX/Y/Z. Bounces velocity on frame 0x1D. */

/* func_8015BA40 — ◄FRAG► 1 instr: addiu sp,sp,-0x80. Prologue of simon_OnUpdate. */

void rezop_simon_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015BCAC. Simon controller state machine:
     * State 1: check _100 == -2+3 (≥ 3 hits). Process pattern input.
     * Reads linked TVs and verifies player's button sequence.
     * s4=2 (correct hits), s3=1 (step), fp=3 (max steps).
     */
    int state = *(int*)((char*)instance + 0xF4);
    if (state != 1) return;

    int progress = *(int*)((char*)instance + 0x100);
    if (progress + 2 < 3) return;  /* bgt check */
    /* Process simon sequence */
}

/* ── rezop_rezbot ──────────────────────────────────────────────────────────── */

void rezop_rezbot_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015C33C. Robot enemy init:
     * Reads gameTracker->player->_4C (Y), adds 0x282 (642) → stores to _FC.
     * Clears _4E (animation state).
     */
    short playerY = *(short*)((char*)gameTracker->player + 0x4C);
    *(int*)((char*)instance + 0xFC) = playerY + 0x282;
    *(char*)((char*)instance + 0x4E) = 0;
}

void rezop_rezbot_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015C35C. Pre-loads gameTracker->player (0x8007-0x3060).
     * Large 0x50-frame function. Robot patrol + attack AI. */
}

/* ── rezop_crnkplt / rezop_rezcrnk ──────────────────────────────────────────
 * Crank + platform mechanism: crank can be turned by Gex, platform moves.
 * ─────────────────────────────────────────────────────────────────────────── */

void rezop_crnkplt_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015CF50. Sets up crank platform bounds:
     * Reads instance->_48/4A/4C (XYZ), sets:
     *   _10[X]     = X, _18[X] = X (min = current pos)
     *   _10[X]     = X, _1C[X] = X + 0x100 (max)
     *   _14[X]     = X, _20[X] = X - 0x100 (other side)
     * Reads gameTracker->_4 (instance list), then player instance.
     */
    short x = *(short*)((char*)instance + 0x48);
    short y = *(short*)((char*)instance + 0x4A);
    short z = *(short*)((char*)instance + 0x4C);
    *(short*)((char*)instance + 0x10) = x;
    *(short*)((char*)instance + 0x12) = y;
    *(short*)((char*)instance + 0x14) = x;
    *(short*)((char*)instance + 0x18) = y;
    *(short*)((char*)instance + 0x1A) = y;
    *(short*)((char*)instance + 0x1C) = x + 0x100;
    *(short*)((char*)instance + 0x20) = z - 0x100;
    *(short*)((char*)instance + 0x24) = z + 0x100;
}

void rezop_crnkplt_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instr: addiu sp,sp,-0x38. Prologue-start. 
     * Full: drives platform movement based on crank rotation counter. */
}

void rezop_crnkplt_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015D0F0. Just calls GenericCollide (func_8001AD48). */
    GenericCollide(instance, gameTracker);
}

void rezop_rezcrnk_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015D118. Crank handle rotation:
     * State 1: if _FC > 0, decrement by 0x10; if <= 0 clear; set _F4=0.
     * Reads _FC+_64 (position offset from crank), stores to _64.
     * Reads _100 (rotation limit), checks.
     */
    int state = *(int*)((char*)instance + 0xF4);
    if (state == 1) {
        int fc = *(int*)((char*)instance + 0xFC);
        if (fc > 0) {
            fc -= 0x10;
            if (fc < 0) fc = 0;
            *(int*)((char*)instance + 0xFC) = fc;
        } else {
            *(int*)((char*)instance + 0xF4) = 0;
        }
    }
    /* Update visual rotation */
    short angle = *(short*)((char*)instance + 0x64);
    angle += (short)*(int*)((char*)instance + 0xFC);
    *(short*)((char*)instance + 0x64) = angle;
}

void rezop_rezcrnk_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015D188. Reads bsp->_6 (contact type). If 1 (player):
     * Reads _24 (linked crank platform), checks bsp->_14 (signaller).
     * Fires signal to increment crank rotation. */
    BSPTree* bsp = instance->bspTree;
    if (*(short*)((char*)bsp + 6) != 1) return;
    void* linked = *(void**)((char*)instance + 0x24);
    if (!linked) return;
    /* check bsp->_14 against some ptr */
}

/* ── rezop_snkplat ─────────────────────────────────────────────────────────── */

void rezop_snkplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015D268. Snake platform init:
     * Frame 0x30, sets flags|=0x10 (from lui 0x10). */
    *(int*)((char*)instance + 0x10) |= 0x10;
}

void rezop_snkplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instrs: addiu sp,-0x30; sw s0,0x20(sp); addu s0,a0,zero. Prologue. */
}

void rezop_snkplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015D434. BSP contact type 4 (snake trigger):
     * Reads bsp->_14 (contact instance). If == gameTracker->player:
     * Calls GenericCollide (func_8001AD48).
     */
    BSPTree* bsp = *(BSPTree**)((char*)instance + 0x78);
    if (*(short*)((char*)bsp + 6) != 4) return;
    if (*(void**)((char*)bsp + 0x14) != gameTracker->player) return;
    GenericCollide(instance, gameTracker);
}

/* ── rezop_rezbull ─────────────────────────────────────────────────────────── */

void rezop_rezbull_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015D484. Bullet init: velocity -0xF, speed 0x3C (60).
     * Clears _F4, sets _D8=_108=0x3C.
     */
    *(int*)((char*)instance + 0xE4) = -0xF;
    *(int*)((char*)instance + 0xF4) = 0;
    *(int*)((char*)instance + 0xD8) = 0x3C;
    *(int*)((char*)instance + 0x108) = 0x3C;
}

void rezop_rezbull_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015D4A0. Reads _F4 (hit state). Full update drives bullet. */
}

void rezop_rezbull_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instr: addiu sp,-0x38. Prologue-start. */
}

/* ── rezop_srchlit / rezop_spotlit ───────────────────────────────────────────
 * Searchlight (rotates to track player) and spotlight (fixed cone light).
 * ─────────────────────────────────────────────────────────────────────────── */

void rezop_srchlit_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015D850. Reads _FC list (_4 ptr = sub-list base, _68 = count).
     * Iterates count × 12-byte entries in _6C table.
     * Each entry has a position pointer; reads _0 short from entry object. */
}

void rezop_srchlit_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instrs: addiu sp,-0x10; lh v1,0xFC(a0); lw a1,4(a1). */
}

void rezop_spotlit_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015E0CC. Reads gameTracker->player->_4F (costume byte).
     * Stores to instance->_FC (spotlight color/mode). Simple 1-line init. */
    *(short*)((char*)instance + 0xFC) = *(unsigned char*)((char*)gameTracker->player + 0x4F);
}

void rezop_spotlit_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015E0E8. Spotlight tracking:
     * Increments _FE (frame counter). Computes delta to player:
     *   dX = player->_4A - instance->_4A (Y diff → use for angle)
     *   dZ = player->_48 - instance->_48 (X diff)
     * Calls ratan2 3x for angle computation and smoothing.
     * Calls func_8004AD5C (MATH_AngularDelta) for rotation speed limiting.
     * Also osSyncPrintf (debug print). */
    *(short*)((char*)instance + 0xFE) += 1;
    short dy = *(short*)((char*)gameTracker->player + 0x4A)
             - *(short*)((char*)instance + 0x4A);
    short dx = *(short*)((char*)gameTracker->player + 0x48)
             - *(short*)((char*)instance + 0x48);
    int angle = ratan2(dy, dx);
    /* angular velocity limiting via func_8004AD5C */
}

/* ── rezop_spnplat ─────────────────────────────────────────────────────────── */

void rezop_spnplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015E41C. Spinning platform init:
     * Reads _24->_0 (flags), checks bit 0x2. If clear: ORs 0x1 into flags.
     * Reads _24->_4->_1C, ORs 0x10 into it. */
    void* def = *(void**)((char*)instance + 0x24);
    int   flags = *(int*)def;
    if (!(flags & 0x2)) {
        *(int*)def = flags | 0x1;
        void* inner = *(void**)((char*)*(void**)((char*)def + 4) + 0x1C);
        if (inner) *(int*)inner |= 0x10;
    }
}

void rezop_spnplat_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015E4C4. Spinning platform update:
     * Reads _20->_0/_4 and _1C->_2C (parent HInfo ptr).
     * If _2C null → return (no collision). Reads _F4 state (0,1,2,3).
     * Checks instance->_48==parent->_10 and instance->_4A==parent->_12 (at-waypoint).
     * Calls ratan2 for rotation. */
    void* parent = *(void**)((char*)instance + 0x1C);
    if (!*(void**)((char*)parent + 0x2C)) return;

    int state = *(int*)((char*)instance + 0xF4);
    if (state == 3) { /* Rotating */ }
}

void rezop_spnplat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015E7A8. Checks _F4-3 in range 0..1 (states 3 or 4 valid).
     * If not in range: check bsp->_14 (contact instance). */
    int state = *(int*)((char*)instance + 0xF4);
    if ((unsigned)(state - 3) > 1) {
        /* check contact */ return;
    }
    BSPTree* bsp = instance->bspTree;
    /* signal the linked crank */
}

/* ── rezop_mutant ──────────────────────────────────────────────────────────── */

void rezop_mutant_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015E8B4. Boss mutant init:
     * Checks flags & 0x200000 (large instance flag). If set:
     *   if _4E (anim state) nonzero: set _1C->_1C |= 0x8, jump.
     *   else: read _1C->_1C (linked def), set bit 0x8.
     * If flag clear: set flags|=0x100000 (physics flag).
     */
    int flags = *(int*)((char*)instance + 0x10);
    if (flags & 0x200000) {
        if (*(char*)((char*)instance + 0x4E)) {
            *(int*)((char*)*(void**)((char*)instance + 0x1C) + 0x1C) |= 0x8;
        }
    } else {
        *(int*)((char*)instance + 0x10) = flags | 0x100000;
    }
}

/* func_8015E950 — ◄FUNC► mutant_spawn_phase.
 * Large (0x60-frame, 8 s-regs). Reads extra stack args at sp[0x74],[0x7C],[0x80].
 * Calls func_80015F14 (SplineGetFirstPoint?) with s3 (spline ptr).
 * s0=result, s2=instance->_4. Iterates phase spawning.
 */
static void rezop_mutant_SpawnPhase(void* s3, void* s5, void* s4, void* fp, int s7,
                                     void* v1extra, void* sp34) {
    void* splinePoint = func_80015F14(s3);
    if (!splinePoint) return;
    /* iterate spawn sequence */
}

/* func_8015EAB0 — ◄FUNC► mutant_matrix_setup.
 * Reads 4 extra stack args (s0,s1,s3 from sp[0x44/48/4C]).
 * Calls MATH3D_SetUnityMatrix (func_80030B5C) on s5+0xC.
 * Copies _1C shorts from s1[0..5] to s2[0x1C..0x26] (rotation fields).
 */

/* func_8015ECB8 — ◄FUNC► mutant_vertex_oscillate.
 * Calls func_80016894 (animation step). Checks _E < 0xB.
 * Oscillates _24/_28/_2C/_30/_34/_38 (6 shorts) by ±4. Walks _4 chain.
 */
static void rezop_mutant_OscillateVerts(Instance* instance) {
    func_80016894(instance);  /* advance animation */
    if (*(short*)((char*)instance + 0xE) >= 0xB) return;

    *(short*)((char*)instance + 0x24) -= 4;
    *(short*)((char*)instance + 0x28) += 4;
    *(short*)((char*)instance + 0x2C) += 4;
    *(short*)((char*)instance + 0x30) -= 4;
    *(short*)((char*)instance + 0x34) += 4;
    *(short*)((char*)instance + 0x38) += 4;
    /* Continue with _4 (next in chain) */
    Instance* next = *(Instance**)((char*)instance + 4);
    if (next) rezop_mutant_OscillateVerts(next);
}

void rezop_mutant_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015EE04. Loads player, computes distance² to player.
     * Large (0x68-frame). Boss AI: chase player when within range,
     * fire shots via mtntsht, oscillate body via func_8015ECB8. */
    GameTracker* player = gameTracker->player;
    short dx = *(short*)((char*)instance + 0x48) - *(short*)((char*)player + 0x48);
    short dy = *(short*)((char*)instance + 0x4A) - *(short*)((char*)player + 0x4A);
    int distSq = (int)dx*dx + (int)dy*dy;
    /* AI dispatch based on distSq vs threshold */
}

void rezop_mutant_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015F698. Reads bsp->_6==1, bsp->_14 contact, _C gameTracker.
     * Same contact-check pattern as other enemies. */
    BSPTree* bsp = instance->bspTree;
    if (*(short*)((char*)bsp + 6) != 1) return;
    /* handle hit */
}

/* ── rezop_mtntsht ─────────────────────────────────────────────────────────── */

void rezop_mtntsht_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015F798. Copies position XY from _48 to _58 (backup pos).
     * lwl/lwr unaligned copy of 4 bytes at +0x48. Separate sh for _4C→_5C. */
    *(int*)((char*)instance + 0x58) = *(int*)((char*)instance + 0x48);
    *(short*)((char*)instance + 0x5C) = *(short*)((char*)instance + 0x4C);
}

void rezop_mtntsht_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015F7E8. Reads _48/_58 (current vs backup X position).
     * Checks delta — if shot has traveled far enough, despawn. */
    short curX = *(short*)((char*)instance + 0x48);
    short origX = *(short*)((char*)instance + 0x58);
    /* check distance traveled */
}

void rezop_mtntsht_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015F88C. Reads bsp->_6==1, bsp->_14, _C check.
     * Shot hits player → INSTANCE_PlainDeath. */
    BSPTree* bsp = *(BSPTree**)((char*)instance + 0x78);
    if (*(short*)((char*)bsp + 6) != 1) return;
    /* check player contact, apply damage */
}

/* ── rezop_rebggen / rezop_rbmastr / rezop_rebug ─────────────────────────────
 * Rez robot bug system: generator spawns bugs, master controls swarm.
 * ─────────────────────────────────────────────────────────────────────────── */

void rezop_rebggen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instr: lw v0,0x10(a0). Loading flags. */
}

void rezop_rebggen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015F970. State 1: calls OBTABLE_FindObject at 0x801615B8.
     * Spawns bug instances while count < max. */
    if (*(int*)((char*)instance + 0xF4) == 1) {
        int spawned = OBTABLE_FindObject((void*)0x801615B8);
        /* iterate spawning */
    }
}

void rezop_rbmastr_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015FA08. Master robot bug controller. Large (0x38-frame). */
}

void rezop_rebug_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015FC1C. Sets flags |= 0x400 (physics enabled). */
    *(int*)((char*)instance + 0x10) |= 0x400;
}

void rezop_rebug_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instr: addiu sp,-0x18. Prologue. */
}

void rezop_rebug_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015FCE8. Reads bsp->_6 (contact type 1), large frame. */
    BSPTree* bsp = *(BSPTree**)((char*)instance + 0x78);
    if (*(short*)((char*)bsp + 6) != 1) return;
    /* bug-player collision handler */
}

/* ── rezop_iris ─────────────────────────────────────────────────────────────── */

void rezop_iris_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015FE70. Iris portal init:
     * Reads instance->_18->_1C (obj type flags). Reads first short, sign-extends.
     * Stores (value+1)/2 → _102 (mid-point of iris range).
     * Also stores signed arithmetic shift: (v1 >> 1) to _102.
     */
    void* typeFlags = *(void**)((char*)*(void**)((char*)instance + 0x18) + 0x1C);
    short v = *(short*)typeFlags;
    *(short*)((char*)instance + 0x102) = (v >> 1);  /* arithmetic half */
}

void rezop_iris_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015FF3C. Large (0x78-frame). Reads player distance.
     * Controls iris opening/closing based on player proximity. */
    GameTracker* player = gameTracker->player;
    short dx = *(short*)((char*)instance + 0x48) - *(short*)((char*)player + 0x48);
    short dy = *(short*)((char*)instance + 0x4A) - *(short*)((char*)player + 0x4A);
    int distSq = (int)dx*dx + (int)dy*dy;
    /* threshold check → open/close iris animation */
}

/* ── rezop_tvgen / rezop_tvgurny ─────────────────────────────────────────────
 * TV generator spawns TV objects; TV gurney transports them.
 * ─────────────────────────────────────────────────────────────────────────── */

void rezop_tvgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x801605FC. Sets flags |= 0x10800, clears _F4. */
    *(int*)((char*)instance + 0x10) |= 0x10800;
    *(int*)((char*)instance + 0xF4) = 0;
}

void rezop_tvgen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x80160618. Calls OBTABLE_FindObject at _24+8.
     * If found: s2=result. If _24 null: set s3=1. */
    void* def = *(void**)((char*)instance + 0x24);
    int found = OBTABLE_FindObject((char*)def + 8);
}

void rezop_tvgurny_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 2 instrs: addiu sp,-0x28; sw s0,0x20(sp). Prologue-start. */
}

void rezop_tvgurny_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8016087C. Reads _11C (gurney state counter).
     * Frame 0x38, moves gurney along rail. */
}

void rezop_tvgurny_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8016099C. Just calls GenericCollide (func_8001AD48). */
    GenericCollide(instance, gameTracker);
}

/* ── rezop_gas ─────────────────────────────────────────────────────────────── */

void rezop_gas_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x801609BC. Checks flags & 0x200000 (active from parent).
     * If _F4==5: calls func_800331BC (SOUND_StopHandle) on _104 (sound handle).
     * Jumps to func_80160BE4 (exit). Complex gas cloud init. */
    int flags = *(int*)((char*)instance + 0x10);
    if (flags & 0x200000) {
        if (*(int*)((char*)instance + 0xF4) == 5) {
            func_800331BC(*(int*)((char*)instance + 0x104));
        }
    }
}

void rezop_gas_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x80160C00. Increments _108 (frame counter) and _56.
     * Checks _108 & 0x8000 (high bit = wraparound).
     * Advances _64 (rotation) by 0x2200 & 0xFFF.
     * Dispatches via table at 0x801615C8[_F4*4] (6 states). */
    *(short*)((char*)instance + 0x108) += 1;
    *(short*)((char*)instance + 0x56) += 1;
    short rot = *(short*)((char*)instance + 0x64);
    *(short*)((char*)instance + 0x64) = (rot + 0x2200) & 0xFFF;
    /* state dispatch */
}

void rezop_gas_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x80160E44. Reads bsp->_14 (contact). Checks gameTracker->player.
     * Checks _F4 >= 2 (gas has materialised). Calls func_80027578 (player-hit check).
     * Dispatches based on player state (0x20=walk, 0x10=idle, 0x2000=swim). */
}

/* ── rezop_btimer ──────────────────────────────────────────────────────────── */

void rezop_btimer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 2 instrs: addiu sp,-0x80; sw s0,0x60(sp). Large frame prologue. 
     * Full: boss timer countdown, fires level-completion event on zero. */
}

/* ── rezop_markey ──────────────────────────────────────────────────────────── */

void rezop_markey_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 5 instrs: reads instance->_18->_C->_0 (object table first entry).
     * This is a scrolling marquee display update — advances the text offset. */
    void* objType = *(void**)((char*)*(void**)((char*)instance + 0x18) + 0xC);
    void* firstEntry = *(void**)objType;  /* first object type entry */
    /* update marquee scroll position */
}
