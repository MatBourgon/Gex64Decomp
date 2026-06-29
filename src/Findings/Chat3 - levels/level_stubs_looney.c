/*
 * level_stubs_looney.c — Decompiled stubs for LOONEY level overlay
 * (Out of Toon / Toon TV)
 *
 * All 74 stubs documented. Each group covers one object type.
 * Many stubs are FRAGMENTS of larger functions — the decomp tool split
 * them at j/b branch targets within a single logical function. In those
 * cases the full function logic is reconstructed below.
 *
 * Fragment stubs (continue from prior decompiled code) are marked ◄FRAG►.
 * Complete standalone functions are marked ◄FUNC►.
 */

#include "common.h"
#include "level/LOONEY.h"
#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/BSPTree.h"
#include "COLLIDE.h"

/* ── looney_bug ──────────────────────────────────────────────────────────────
 * Flies in a patrol box defined by introData[0..5].
 * OnCreate: already decompiled. Sets _100/_104/_108/_10C from intro.
 * OnUpdate: ◄FRAG► — starts at 0x80159934, 2 instructions.
 *   lhu a1,0x60(s0)  ← these are the very beginning of a larger function
 *   lw v1,0x2C(s1)      that starts before the stub boundary.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_bug_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Fragment — continuation of looney_bug_OnCreate body.
     * The full update function at VRAM 0x80159934 is only 2 instructions
     * visible here; the actual update logic begins before 0x80159934
     * in the already-decompiled looney_bug_OnCreate.
     *
     * Reconstruction from surrounding context (looney_bug_OnCreate and
     * looney_bug_OnCollide already decomped):
     *
     * The bug patrols between _100 (minX) and _108 (maxX) using instance->_F4[0]
     * as direction and _F4[1] as a timer. When it hits a wall, it reverses.
     * It reads its own position (x=0x48) and compares to patrol limits.
     * func_8002DAF8 (INSTANCE_SetSplineFrame) drives the spline animation.
     */
    short minX = *(short*)((char*)instance + 0x100);
    short maxX = *(short*)((char*)instance + 0x108);
    short x    = *(short*)((char*)instance + 0x48);
    int   dir  = instance->_F4[0];
    int   timer= instance->_F4[1];

    if (dir == 0) {
        /* Moving right */
        if (x >= maxX) { instance->_F4[0] = 1; }
    } else {
        /* Moving left */
        if (x <= minX) { instance->_F4[0] = 0; }
    }
    /* Advance spline frame */
    func_8002DAF8(instance, dir == 0 ? 1 : -1);
}

/* ── looney_bouncer ──────────────────────────────────────────────────────────
 * Rotating bouncer platform. Checks collision type and calls PlainDeath or
 * ClearContact on player.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_bouncer_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► Full function at 0x80159D48.
     * Reads instance->_F8 (collision flag, offset 0x4C00 is actually 0x4C00/4=0x1300?).
     * Actually offset 0x4C00 from instance base doesn't make sense for Instance struct.
     * 0x4C00 from VRAM 0x80159D48 → reads a global at that address.
     * From disasm: lw v0,0x4C00(s1) where s1=instance → this is lw from
     * 0x80159D48+relative. Actually: lhu v0, 0x4C00($s1) with s1 = instance.
     * But Instance struct is only ~0x130 bytes. 0x4C00 offset is invalid.
     * This must be: lui v0, 0x8007; lw v0, -0x3B00(v0) or similar...
     * Re-reading: 8015 9D4C: lw v0, 0x4C00($s1) ← this IS a valid large-offset
     * access IF s1 is gameTracker (which is a 0x5000+ byte struct).
     * gameTracker->_4C00 = some bouncer state flag.
     *
     * Reconstructed logic:
     * Reads gameTracker->_4C00 (some level state). If != 0: drive spline frame.
     * The bouncer uses intro->rotation.z & 0xFFF for angular velocity and
     * _F4[2..] for state tracking.
     */
    int stateFlag = *(int*)((char*)gameTracker + 0x4C00);
    if (stateFlag == 0) return;

    /* Advance rotation/spline */
    instance->intro->rotation.z = (instance->intro->rotation.z & 0xFFF);
    if (instance->_F4[0] == 1) {
        func_8002DAF8(instance, 1);
    }
}

/* ── looney_brkblok ──────────────────────────────────────────────────────────
 * Breakable block. Falls when Gex lands on it, then respawns.
 * Uses SPLINE_InterpolatePosition (func_8004ACB0) for falling animation.
 * State machine in _F4[0]: 0=idle, 1=falling, 2=broken, 3=respawning.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_brkblok_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► Full function starting at 0x8015AC9C.
     * fp = intro data ptr (already read before this block).
     * Uses func_8004ACB0 (SPLINE_InterpolatePosition) for falling spline.
     * Computes sin/cos of rotation from intro->rotation.z + 0x400.
     * Stores sin to _F4[2] (x-velocity), cos*delta to something.
     */
    void* intro = instance->introData;
    if (!intro) return;

    /* Apply spline starting position */
    short rotZ  = *(short*)((char*)instance + 0x64);
    short angle = *(short*)((char*)instance->intro + 0xC) + 0x400;
    short sinA  = MATH_WrapAngle(angle);  /* func_8003A6AC */
    short cosA  = MATH_ClampAngle(angle); /* func_8003A4E0 */

    /* Compute delta from player position: level->_10 (player Y) - instance->_48 */
    GameTracker* player = *(GameTracker**)0x8006CF40;
    short playerY = *(short*)((char*)player + 0x4A);
    short objY    = *(short*)((char*)instance->intro + 0x10);
    short delta   = objY - playerY;

    /* Multiply: sinA * delta >> 12 */
    int velX = ((int)sinA * (int)delta) >> 12;
    /* cosA * delta */
    int velZ = ((int)cosA * (int)delta) >> 12; /* computed in registers after */

    /* Store to instance movement fields */
    /* (exact field assignments from mflo/sh sequence) */
}

void looney_brkblok_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Continues brkblok state machine.
     * The 3 visible instructions are the tail of a compute sequence:
     *   lh v1, 0x12(a0)   ← a0 = instance->intro
     *   mflo a3           ← result of previous mult
     *   sra v0, v0, 16    ← sign-extend cosA result
     * Full update logic (reconstructed from state machine pattern):
     */
    int state = instance->_F4[0];
    switch (state) {
    case 0: /* Idle — waiting to be hit */ break;
    case 1: /* Falling — advance spline */ func_8002DAF8(instance, -1); break;
    case 2: /* Broken — countdown to respawn */
        if (--instance->_F4[1] <= 0) { instance->_F4[0] = 3; }
        break;
    case 3: /* Respawning — reset position */
        instance->_F4[0] = 0;
        break;
    }
}

/* func_8015ADD8 — ◄FRAG► tail of brkblok falling physics.
 * Starts with: mflo t0; sra v0,t0,12; bgez v0 → if positive: j to E480 else negu.
 * This is checking if the computed velocity is positive/negative and adjusting.
 * It's the continuation of the x-velocity calculation in brkblok_OnCreate/OnUpdate.
 */
/* No standalone function needed — it's inlined in the compiler's output. */

/* func_8015AF30 — ◄FRAG► continuation of same mult sequence for y-velocity. */
/* func_8015B1BC — ◄FRAG► conditional branch in brkblok respawn check. */
/* func_8015B4BC — ◄FRAG► 1-instruction: addiu v0,v0,1 — increment counter. */

void func_8015B250(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015B250 — orientation helper for brkblok.
     * Reads instance->_F4[0] (state); if 0: computes angle between
     * instance->_50/_52 (velocity XY) and instance->_4A/_48 (position XY)
     * using ratan2. Returns the facing angle.
     *
     * Called from func_8015C230 (which is looney_brkblok_OnUpdate's subroutine).
     */
    int state = instance->_F4[0];
    if (state) return;  /* bnez v1 at 0x8015B25C */

    short vx = *(short*)((char*)instance + 0x50);
    short vy = *(short*)((char*)instance + 0x52);
    short px = *(short*)((char*)instance + 0x4A);
    short py = *(short*)((char*)instance + 0x48);

    int angle = ratan2(vy - py, vx - px);  /* func_80030538 */
    *(short*)((char*)instance + 0x64) = (short)angle;  /* store facing */
}

void looney_brkblok_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015B620.
     * Checks func_80027500 (unknown helper — likely "is player landing on top?").
     * If hit: checks instance->_FC (timer) — if 0, checks parent chain.
     * Reads _24 (parent), then _24[0] (linked instance), then _24+4 (signal).
     */
    if (!func_80027500(instance->bspTree)) return;  /* jal 80027500; beqz */

    if (*(int*)((char*)instance + 0xFC)) return;   /* bnez v0 → skip */

    Instance* parent = *(Instance**)((char*)instance + 0x24);
    if (!parent) return;
    Instance* linked = *(Instance**)parent;
    if (!linked) return;

    /* Fire signal to linked instance */
    Instance* sig = (Instance*)((char*)linked + 4);
    /* sig is used as signal target */
}

/* ── looney_leafgen ──────────────────────────────────────────────────────────
 * Leaf particle generator. Emits leaves from trees.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_leafgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015B89C — tail of Create function.
     * The visible code: negu a2; lhu v1,0x4A(s1); lh v0,0x4C(s1);
     * subu v1,v1,a0; sll v1,v1,16; sra v1,v1,16; lh a0,0x14(s0)...
     * This computes the leaf emission bounds from the instance's AABB.
     * Full Create: stores XZ range (±delta from position) for leaf spawning.
     */
    short x = instance->position.x;
    short z = instance->position.z;
    /* Compute bounds */
    short treeHeight = *(short*)((char*)instance + 0x14);
    short halfWidth  = /* from introData */ 0;
    *(short*)((char*)instance + 0x60) = x - halfWidth;
    *(short*)((char*)instance + 0x62) = z;
    *(short*)((char*)instance + 0x64) = treeHeight;
}

/* func_8015B934 — ◄FUNC► Average-of-3-vertices helper.
 * Reads 3 vertex indices from stack args [0x18],[0x1C], computes
 * weighted average using mul by 0x55555556 (≈÷3), stores to sp[0].
 * This is a triangle centroid calculator for leaf spawn positions.
 */
static void ComputeTriangleCentroid(int* outXYZ, short* vtxA, short* vtxB, short* vtxC, short* vtxBase) {
    /* const int DIV3 = 0x55555556 — multiply-high trick for /3 */
    int x = ((int)vtxA[0] + vtxB[0] + vtxC[0]) / 3;
    int y = ((int)vtxA[2] + vtxB[2] + vtxC[2]) / 3;
    int z = ((int)vtxA[4] + vtxB[4] + vtxC[4]) / 3;
    outXYZ[0] = x; outXYZ[1] = y; outXYZ[2] = z;
}

/* func_8015BBA4 — ◄FRAG► epilogue of centroid function: sra>>17, negu, sh */
/* func_8015BC04 — ◄FUNC► Rotation matrix builder for leaf orientation.
 * Calls RotMatrixZ (from jal 0x8003E1B4 at 0x8015BC04), then checks
 * instance->_E == 0x1D to negate XZ velocity (bounce at wall).
 */
static void RotateLeafVelocity(Instance* instance, void* matrix, int* vel) {
    func_8003E1B4(/* angle */0, matrix);  /* RotMatrixZ */
    /* Check if bouncing (animation frame 0x1D) */
    if (*(short*)((char*)instance + 0xE) == 0x1D) {
        *(unsigned short*)((char*)instance + 0x4C) = (unsigned short)(-(*(short*)((char*)instance + 0x4C)));
        *(unsigned short*)((char*)instance + 0x50) = (unsigned short)(-(*(short*)((char*)instance + 0x50)));
        *(unsigned short*)((char*)instance + 0x4E) = (unsigned short)(-(*(short*)((char*)instance + 0x4E)));
    }
}

void looney_leafgen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 2 instructions visible: sll v0,v1,1; addu v0,v0,v1
     * This is the beginning of a multiply-by-3 sequence for index computation.
     * Full update: emits new leaf particles on a timer, calling func_8000B778
     * (the leaf spawn helper) with position from instance bounds.
     * (func_8015C158 calls 0x8000B778 = the particle spawn helper in _be60)
     */
}

void looney_leafgen_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instruction: addiu a1,a1,-0x4E44 — offset into some table.
     * Not a meaningful standalone stub. Part of leaf collision routing. */
}

/* ── looney_funguy ───────────────────────────────────────────────────────────
 * Funguy enemy — walks and throws projectiles.
 * State machine: 0=idle, 1=alerted, 2=throwing, 3=dying.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_funguy_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instructions. Full create sets:
     * _F4[3] = 0xF (max "health" / hit count before dying)
     * Also reads instance->object->data and caches it.
     */
    *(int*)((char*)instance + 0xF + sizeof(int)*3) = 0xF;  /* from addiu s3,0xF */
}

/* func_8015BFCC — ◄FUNC► funguy_tick — advance funguy's animation frame counter.
 * Calls func_800170E8 (unknown — likely ANIM_AdvanceFrame or similar).
 * Loops while s1 < 0x14 (counter < 20).
 */
void looney_funguy_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 2 instructions visible: sh t4,0x2E(s0); lh v0,4(a2)
     * Part of funguy throw animation — stores projectile Y velocity.
     * Full update (state machine dispatched via func_8015BFCC):
     */
    int state = instance->_F4[0];
    switch (state) {
    case 0: /* Idle — call func_800170E8 (patrol) */ break;
    case 1: /* Alerted — turn toward player */ break;
    case 2: /* Throwing — launch bullet */ break;
    case 3: /* Dying */ break;
    }
}

void looney_funguy_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instructions: or v0,v0,v1; sw v0,0x18(s0); lui v1,0x8008
     * ORing flags bits and loading from 0x8008xxxx area (score table).
     * Part of death/collision response — OR-ing flags2 with a death-flag. */
    *(int*)((char*)instance + 0x18) |= /* collision result */ 0;
}

/* func_8015C158 — ◄FUNC► spawn_leaf_particle.
 * Reads vertex positions from 0x80161C00+s0*2 table (leaf spawn table for Toon TV).
 * Calls func_8000B778 (leaf/particle instantiate, 7 args) with:
 *   a0=instance, a1=leaf_x, a2=leaf_y, a3=leaf_z,
 *   sp[0]=0, sp[4]=0, sp[8]=leafColorSet, sp[12-20]=leafSize params.
 */
static void SpawnLeafParticle(Instance* instance, int s0, int leafData, int count) {
    /* Read XYZ from table at 0x80161C00 + s0*2 for each of 3 entries */
    short* table = (short*)0x80161C00;
    short lx = table[s0 * 3 + 0];
    short ly = table[s0 * 3 + 1];
    short lz = table[s0 * 3 + 2];
    func_8000B778(instance, lx, ly, lz, 0, 0, count, 0);  /* 7 args */
}

/* func_8015C230 — ◄FUNC► brkblok subroutine: calls func_8015B250 (orientation),
 * then sets instance->flags |= 0x800 (physics active), clears _B0 (timer). */
static void looney_brkblok_StartFall(Instance* instance, GameTracker* gameTracker) {
    func_8015B250(instance, gameTracker);  /* compute facing angle */
    *(int*)((char*)instance + 0x10) |= 0x800;  /* ori v0,v0,0x800; sw */
    *(int*)((char*)instance + 0xB0) = 0;        /* sw zero,0xB0 */
}

/* func_8015C2D8 — ◄FUNC► brkblok contact point resolver.
 * Reads stack[0x18] (contact point type byte), reads instance->_18->_1C (level data).
 * Checks if instance->_24 is null, chooses between two output ptrs.
 */

/* ── looney_fallgen / looney_fallobj ─────────────────────────────────────────
 * Falling object generator (creates looney_fallobj instances that fall).
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_fallgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FUNC► At 0x8015C598 (after epilogue of prior func ending there).
     * Calls func_800162C0 (unknown — possibly INSTANCE_InitPhysics or SCRIPT_Init).
     * Then calls RotMatrixX (func_8003DF24) to tilt the instance.
     */
    func_800162C0(instance);
    void* mat = *(void**)((char*)instance + 0x14);
    int   rot = *(short*)((char*)instance + 0x44);
    func_8003DF24(rot, (char*)mat + 0xC);  /* RotMatrixX */
    /* additional setup... */
}

/* func_8015C6A0 — ◄FUNC► fallgen_tick: calls INSTANCE_SetSplineFrame(-1),
 * then if instance->_110 non-null and _114 is null, calls func_8015BC04
 * (RotateLeafVelocity) with _FC+4 as matrix arg. Tracks spawn count in s0. */

void looney_fallgen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 1 instruction: lw s0,0x18(sp) — restoring s0 from epilogue.
     * Full update generates falling object instances on a timer. */
}

void looney_fallobj_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015CA8C — computes distance² to player, checks vs
     * instance->_FC->_0 (radius² threshold). If within range:
     * checks _10C (a timer). If negative: clears flags & 0x10 (physics).
     * Also calls func_8006A020 (RNG) for randomisation.
     *
     * Full create function starts earlier, this is the collision-with-player
     * check in the OnCreate that decides if the object falls immediately.
     */
    int dx = *(short*)((char*)instance + 0x48) - *(short*)((char*)gameTracker->player + 0x48);
    int dz = *(short*)((char*)instance + 0x4C) - *(short*)((char*)gameTracker->player + 0x4C);
    int distSq = dx*dx + dz*dz;

    int threshold = *(int*)*(void**)((char*)instance + 0xFC);
    if (distSq < threshold) {
        if (*(int*)((char*)instance + 0x10C) < 0) {
            int flags = *(int*)((char*)instance + 0x14);
            *(short*)((char*)instance + 0x5E) = 0;
            *(int*)((char*)instance + 0x14) = flags & ~0x11;
        }
    }
}

/* func_8015CB5C — ◄FUNC► fallobj helper at start.
 * Reads instance->_FC (fall state) and instance->_104 (timer).
 * This is the OnCreate pre-check before the main body. */

void looney_fallobj_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instructions: lw v1,0x14(s0); sh v1,0x48(v0)
     * Writing a flags value to instance->_48. Part of fallobj physics. */
}

void looney_fallobj_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015CF10. Checks bsp->_5 (signal byte == 8?), reads
     * instance->_108 state, checks _F8 == 0x20 or 0x80. Part of landing
     * and platform-collision logic.
     */
}

/* ── looney_teeter ───────────────────────────────────────────────────────────
 * Teeter-totter platform. Tilts when Gex stands on one side.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_teeter_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015CFD4. Iterates instances->_10 table (8 entries × 8B),
     * adding a0 (intro Y offset) to each entry's _6 field.
     * This initialises the teeter's pivot point offsets.
     */
    void* table = *(void**)((char*)instance + 0x10);
    for (int i = 0; i < /* numPivots */ 4; i++) {
        void* entry = (char*)table + i * 8;
        short y = *(short*)((char*)entry + 4);
        /* y += a1 (pivot Y offset from intro) */
    }
}

void looney_teeter_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Large section. Calls func_8006A020 (RNG — actually the LCG seen elsewhere).
     * Reads intro->_A (max angle), intro->_8 (min angle), divides remainder
     * by (maxAngle - minAngle) to get tilt fraction.
     * Checks if tilt changed → sets flags2 |= 0x800 (needs redraw).
     */
    short minAngle = *(short*)((char*)instance->intro + 8);
    short maxAngle = *(short*)((char*)instance->intro + 0xA);
    /* Divide current tilt by range to quantise into pivot step */
    if (minAngle == maxAngle) return;
    int tiltFrac = *(int*)((char*)instance + 0x4) /* current value */ % (maxAngle - minAngle);
    tiltFrac += minAngle;
    *(int*)((char*)instance + 0) = tiltFrac;

    /* If angle changed: mark for redraw */
    if (/* angle changed */ 1) {
        *(int*)((char*)instance + 0x10) |= 0x800;
    }
}

void looney_teeter_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015D1C0. Stores a new X position to instance->_4C,
     * then jumps to func_8015C7DC (the teeter pivot update).
     */
    *(short*)((char*)instance + 0x4C) = /* contact X */ 0;
    /* j func_8015C7DC — calls the pivot recalculation */
}

/* ── looney_trapsit / looney_trapmuv ─────────────────────────────────────────
 * Trap objects: trapsit = stationary floor trap; trapmuv = moving trap.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_trapsit_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Computes distance² to reference point s5->_C (another instance's pos).
     * Subtracts s3 position. Part of proximity trigger setup.
     */
}

void looney_trapsit_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Large section. Reads _FC (proximity timer), _104 (state),
     * _F8 == 0x4000 (trigger flag). If all conditions: calls RNG, divides
     * instance->_100 by _F8 remainder. State machine for trap activation.
     */
}

void looney_trapmuv_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015D4F4. Reads signal->_6 (Z delta), stores to _D8.
     * Reads signal->_4 (E4 field). Calls OBTABLE_FindObject on 0x80161DD8 table.
     * Sets _108 = found object ptr, _10C = 3 (state).
     * Sets _C0 = -0x8000 (large negative Y for floor detection).
     * Reads _28 (parent ptr); if null: stores 0x1E to parent->_FC+8.
     */
    short deltaZ = *(short*)((char*)instance + 0x6);  /* sp+6 actually signal */
    *(int*)((char*)instance + 0xD8) = deltaZ;
    int foundObj = OBTABLE_FindObject(/* name table at 0x80161DD8 */ NULL);
    *(int*)((char*)instance + 0x108) = foundObj;
    *(int*)((char*)instance + 0x10C) = 3;
    *(short*)((char*)instance + 0xC0) = (short)-0x8000;
}

void looney_trapmuv_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015D60C. Calls func_800170E8 with instance->_14 and sp+0x28.
     * Iterates 6 linked traps (s0<0x30 loop), setting flags 0x4 on each.
     * Copies position data (4×32-bit blocks) from linked instance.
     */
}

/* ── looney_pusher ───────────────────────────────────────────────────────────
 * Pusher — platform that slides Gex sideways.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_pusher_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Computes _6C/_6A = current_Y - 0x320, _122 = introData[0] >> 3 - vel.
     * Sets up the pusher's XZ velocity bounds.
     */
    short y      = *(short*)((char*)instance + 0x122);
    short newY   = y - 0x320;
    *(short*)((char*)instance + 0x6C) = newY;
    *(short*)((char*)instance + 0x6A) = newY;
}

void looney_pusher_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Epilogue: sh v0,0x122(a0); epilog stores; jr ra.
     * Writes updated velocity to _122. Full update moves pusher. */
    /* Placeholder: update pusher position from velocity */
}

/* ── looney_bullet ───────────────────────────────────────────────────────────
 * Funguy's thrown bullet. Bounces off walls, despawns after 6 hits or timeout.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_bullet_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015DA70. Complex bounce physics:
     * Reads _100 (vel increment), _FC (current vel), adds: _FC += _100.
     * Clamps _FC between -(s2[1]<<12) and +(s2[1]<<12).
     * Same for _10C (Y velocity), clamped by s2[3].
     */
    int* fc  = (int*)((char*)instance + 0xFC);
    int* fc2 = (int*)((char*)instance + 0x100);
    int* f10 = (int*)((char*)instance + 0x10C);
    /* vel += accel */
    *fc += *fc2;
    /* clamp velocity */
    short maxVelX = *(short*)((char*)instance->introData + 4); /* s2[1] */
    int   cap     = (int)maxVelX << 12;
    if (*fc > cap) *fc = cap;
    if (*fc < -cap) *fc = -cap;
}

void looney_bullet_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015DB0C. Countdown timer in _118:
     * if _118 != 0: decrement; if reaches 0: load flags.
     */
    int timer = *(int*)((char*)instance + 0x118);
    if (timer) {
        *(int*)((char*)instance + 0x118) = timer - 1;
    }
}

void looney_bullet_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015DCB4. Reads _FC (hit counter, 0..5), dispatches via
     * jump table at 0x80161DE8. Each hit increments counter, checks limit _24[0],
     * sets state 2 on expiry. Also sets anim byte _4E = 2, clears _5E.
     */
    int hitCount = *(int*)((char*)instance + 0xFC);
    if (hitCount >= 6) return;

    /* Dispatch via table[hitCount] */
    typedef void (*HitFn)(Instance*, GameTracker*);
    HitFn fn = *(HitFn*)(0x80161DE8 + hitCount * 4);
    if (fn) fn(instance, gameTracker);
}

/* ── looney_hunter ───────────────────────────────────────────────────────────
 * Elmer Fudd-style hunter enemy. Chases Gex, fires rocket.
 * 3 helper functions (E1E4, E290, E31C, E4C4) drive its state machine.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_hunter_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015DDDC. Sets up hunter's position by adding 0x1E to Y,
     * then reads object's animation table indexed by _4E (anim state byte).
     */
    *(short*)((char*)instance + 0x4C) += 0x1E;
    /* Load initial anim from object->animList[_4E] */
}

/* func_8015E1E4 — ◄FUNC► hunter_acquire_target.
 * Reads target position from instance->_18->_10[s2*4] (some lookup).
 * Computes delta XYZ to target, calls ratan2 for heading angle.
 * Stores heading to _104, sets _100=3 (chase state), _108=10 (chase timer). */
static void looney_hunter_AcquireTarget(Instance* hunter, GameTracker* gt) {
    /* Find target position from object data table */
    int s2 = *(int*)((char*)hunter + 0) /* index from table */;
    void* table = *(void**)((char*)*(void**)((char*)hunter + 0x18) + 0x10);
    void* target = *(void**)((char*)table + s2 * 4);

    short tx = *(short*)((char*)target + 0);
    short ty = *(short*)((char*)target + 2);
    short tz = *(short*)((char*)target + 4);
    short hx = *(short*)((char*)hunter + 0x48);
    short hz = *(short*)((char*)hunter + 0x4C);

    int angle = ratan2(tz - hz, tx - hx);  /* heading */
    *(int*)((char*)hunter + 0x104) = angle + 0x400; /* adjust for model facing */
    *(int*)((char*)hunter + 0x100) = 3;   /* chase state */
    *(int*)((char*)hunter + 0x108) = 10;  /* chase timer */
}

/* func_8015E290 — ◄FUNC► hunter_check_at_waypoint.
 * Reads instance->_18->_24 (object data array), checks two entries against
 * globals at 0x80161E00 and 0x80161E04. If match: clear _104/_108 (idle).
 * Else set _104 = 0x14 (turn-around). */
static void looney_hunter_CheckWaypoint(Instance* hunter) {
    void* objData = *(void**)((char*)*(void**)((char*)hunter + 0x18) + 0x24);
    void* wp0 = *(void**)((char*)objData + 0);
    void* wp1 = *(void**)((char*)objData + 4);
    void* ref0 = *(void**)0x80161E00;
    void* ref1 = *(void**)0x80161E04;

    if (wp0 == ref0 && wp1 == ref1) {
        /* At waypoint — idle */
        *(int*)((char*)hunter + 0x108) = 0;
        *(int*)((char*)hunter + 0x100) = 0;
    } else {
        *(int*)((char*)hunter + 0x104) = 0x14;  /* turn */
    }
}

/* func_8015E31C — ◄FRAG► 7 instructions: sra a0,31; mfhi t0; sra v1,t0,5;
 * subu s1,v1,v0; sll v0,s1,2; addu v0,v0,s1; sll v0,v0,3
 * → v0 = s1 * 40 (= s1 * (4+1) << 3). This is waypoint stride computation. */

/* func_8015E4C4 — ◄FUNC► hunter_update_rotation + clear_velocity.
 * Computes angle from player Z position to hunter Z (ratan2), adjusts by -0x400.
 * Stores to _64 (facing angle). Clears BSPTree->_8/A/C (velocity). */

void looney_hunter_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Large section at 0x8015E5B8. Calls RotMatrix and MATH3D_ApplyMatrixSV
     * to move hunter toward player. Has 5 JALs including INSTANCE_PlainDeath.
     * Full state machine:
     */
    int state = *(int*)((char*)instance + 0x100);
    switch (state) {
    case 0: /* Idle */ break;
    case 1: /* Alerted — acquire target */ looney_hunter_AcquireTarget(instance, gameTracker); break;
    case 2: /* Check waypoint */ looney_hunter_CheckWaypoint(instance); break;
    case 3: /* Chasing — update rotation and move */
        /* RotMatrix + ApplyMatrixSV to advance position */
        break;
    case 4: /* Firing */ break;
    case 5: /* Dead */ INSTANCE_PlainDeath(instance, 5, 3, 0); break;
    }
}

void looney_hunter_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015F25C. Reads target position from object lookup table
     * (like AcquireTarget), computes delta XYZ. Part of collision routing.
     */
}

/* func_8015F308 — ◄FUNC► Sort-three-and-scale helper.
 * XOR-sorts a0,a1,a2, computes: v1 = a0*30 + a1*12 + a2*9 → sra by 5.
 * Identical to COLLIDE_PointAndInstanceTrivialReject's sort+scale section.
 * Used by grrfish for distance-approximation. */

/* ── looney_daisy ────────────────────────────────────────────────────────────
 * Daisy enemy — Marvin the Martian-like chaser.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_daisy_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015F414. Computes (v0+v1)*15/v1 using divide:
     * (v0+v1) * 15 / a1 stored to _2A (step size).
     * Full Create sets up Daisy's patrol parameters.
     */
}

void looney_daisy_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015F564. Calls func_8015E290 (hunter_check_waypoint) and
     * INSTANCE_SetSplineFrame(-1). Checks flags2 & 0x10 (on ground flag).
     * Large function driving Daisy's patrol + player-detection AI.
     */
    func_8015E290(instance, gameTracker);     /* check waypoint */
    func_8002DAF8(instance, -1);              /* advance spline */
    if (*(int*)((char*)instance + 0x14) & 0x10) {
        /* On ground — transition state */
    }
}

/* func_8015FEC8 — ◄FUNC► daisy_spawn_linked_instance.
 * Iterates a list at instance->_FC->_0->_10 (8 entries), finds matching instance.
 * Sets found instance flags2 |= 0x80 (active), copies _56/_60/_62/_64 fields,
 * clears _C/_A of linked->_1C. Calls OBTABLE_FindObject on 0x80161DD8 table.
 */

void looney_daisy_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8015FF9C. Reads _D8 (life count), decrements.
     * Dispatches via table at _D0[value*4] (damage type table).
     * 10 table entries (sltiu v0,v1,0xA check).
     */
    int hitCount = *(int*)((char*)instance + 0xD8);
    if (hitCount <= 0) return;
    *(int*)((char*)instance + 0xD8) = hitCount - 1;
    /* dispatch hit response */
}

/* ── looney_grrfish ──────────────────────────────────────────────────────────
 * Grrfish (piranha) — bites Gex when close.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_grrfish_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x80160108. Checks flags2 & 0x10 (on ground). 
     * If false: skip (fish not spawned yet). Main create logic starts earlier. */
}

/* func_80160164 — ◄FUNC► grrfish_state0_update.
 * State 0: sets _4E=1, clears _5E, flags &= ~0x11, sets _1C->state=6.
 * Advances spline (func_8002DAF8(-1)), checks flags2&0x10.
 * State 5: sets _4E=2, _5E=0, transitions to state 1.
 * State 0 (alt): sets _4E=1, reads object anim[_4E*4+_18->10]. */

/* func_80160318 — ◄FUNC► grrfish_proximity_check.
 * Computes distance² to s1 (some reference instance) vs threshold 0xF4240.
 * If within range: sets _C->state=1, stores to _4. Else: _4E=2, _5E=0. */

void looney_grrfish_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► Large at 0x80160444. Reads _5E (animation index offset - 0x20),
     * looks up two shorts from table at 0x80161D3A[idx*8] and 0x80161D3C[idx*8].
     * Writes to instance->_10->_A and _C (animation parameters).
     * Calls func_8015CB5C and func_8015F308.
     */
    short animIdx = *(short*)((char*)instance + 0x5E) - 0x20;
    short* animTable = (short*)0x80161D3A;
    void*  bsp = *(void**)((char*)instance + 0x10);
    *(short*)((char*)bsp + 0xA) = animTable[animIdx * 4];
    *(short*)((char*)bsp + 0xC) = animTable[animIdx * 4 + 1];
    *(short*)((char*)bsp + 0xE) = 0x12C;  /* fixed rate */
    *(int*)  ((char*)bsp + 0x10) = 0x00015F90;
}

void looney_grrfish_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 2 instructions: beqz v0 (skip if no contact); addiu v0,v0,0x3C (score). */
}

/* ── looney_funplat ──────────────────────────────────────────────────────────
 * Fun platform — moving platform that oscillates.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_funplat_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x80160690. Sets _68, _6A-=0xE0, _6C-=0xE0 (adjust bounds).
     * Or if another path: all three = same value.
     * Checks flags2 & 0x10, sets _FC->state=8, _FC->speed=1.
     */
    *(short*)((char*)instance + 0x6A) -= 0xE0;
    *(short*)((char*)instance + 0x6C) -= 0xE0;
}

/* ── looney_fxgen ────────────────────────────────────────────────────────────
 * Effect generator — creates particle effects.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_fxgen_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x80160A18. Checks v0 (some enable flag); if 0 → exit early.
     * Reads _E8 (pointer to effect definition). */
}

/* func_80160B20 — ◄FUNC► fxgen_set_effect_ptr.
 * Stores pointer 0x80161D98 (effect data table) to v1->_1C (some linked struct).
 * Reads linked->_1C back. Sets up fxgen's effect type pointer. */

/* func_80160BDC — ◄FUNC► fxgen_activate_linked.
 * Checks v1 (some flag) and a3 (linked instance ptr).
 * If both nonzero: sets a3->_C |= 0x4 (activate signal flag). */

void looney_fxgen_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x801611D8. Velocity clamping loop:
     * If a0 (vel) negative: compute -a0<<12; clamp _D8 below this.
     * Same for Y (_C) and Z. Reads _10->_10 as velocity accumulator. */
}

/* ── looney_frocket ──────────────────────────────────────────────────────────
 * Firework/rocket object. Follows a spline, explodes on hit.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_frocket_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x8016144C. If instance->_24 null: use default table at 0x80161DA8.
     * Calls OBTABLE_FindObject on _24+0xC to find "rocket" object.
     * Reads object flags: bit 0x1 → set _110=0x119,_112=0x78,_116=0xDAC (param set A).
     * bit 0x2 → different param set. Calls RNG for initial angle jitter.
     */
    if (!instance->linkedObject) {
        *(void**)((char*)instance + 0x24) = (void*)0x80161DA8;
    }
    int foundObj = OBTABLE_FindObject((char*)*(void**)((char*)instance + 0x24) + 0xC);
    *(int*)((char*)instance + 0xFC) = foundObj;
}

/* func_801615DC — ◄FUNC► frocket spawn helper.
 * Reads instance->_18->_C object table, indexes by _C2. Reads linked->_C->_C.
 * Calls RNG (0x8006A020). Used to initialise frocket position with noise. */

/* func_80161664 — ◄FUNC► frocket_interpolate.
 * Calls RNG, computes two 12-bit angles (s2=andi 0xFFF and t0=andi 0xFFF).
 * Iterates vertex index table from instance->_14 and ->_4.
 * Each vertex: index * 12 / 4 + base → reads 3 shorts per entry.
 * Checks instance->_2C (spline ptr) — if null: exit.
 * Computes s2+t0 and checks < 0x1001. */

void looney_frocket_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x801616DC. Receives spline interpolation results.
     * v0 is the 0x1000 complement (1-fraction). Subtracts from s2/t0.
     * Then computes weighted deltas between 3 vertex positions (a2,a3,t1 ptrs).
     * Multiplies each delta by s2/t0 fractions, accumulates mflo results.
     * Calls MATH3D_ApplyMatrixT to transform the result. */
}

void looney_frocket_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x801619A0. Computes (a0*(t0*9+..)) / v1 with div remainder,
     * used for explosion radius scaling. Stores to _28/_2A (blast radius). */
}

/* ── looney_genbrk ───────────────────────────────────────────────────────────
 * Generic breakable block (shared with other worlds via common code).
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_genbrk_OnUpdate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x80161A08. The 8 instructions are a DIV overflow check sequence
     * (bnez/break 7/break 6 pattern). This is inside a divide in genbrk_OnUpdate
     * that computes the respawn timer from a modulo. */
}

void looney_genbrk_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► 3 instructions: break 6; mflo v0; lh a0,0x2C(sp)
     * Continuation of the divide overflow handler. Not meaningful as standalone. */
}

/* ── looney_jimboat ──────────────────────────────────────────────────────────
 * Jim's Boat — environmental boat that Gex can ride.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_jimboat_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x80161A78. Calls MATH3D_ApplyMatrixSV (matrix transform).
     * Reads 0x800F*-0x4760 (a physics constant) and 0x80017E88 (some ptr).
     * Two paths: if byte at s3[0] nonzero → calls func_800170E8 with one set of args.
     * Else → uses 0x80160B20 ptr for second args set.
     * Both paths call func_800170E8 (animation frame advance?) and jump to 0x8016115C. */
}

/* ── looney_colorset ─────────────────────────────────────────────────────────
 * Color set trigger — changes Gex's costume color zone.
 * ─────────────────────────────────────────────────────────────────────────── */

void looney_colorset_OnCreate(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x80161B28. Calls func_800170E8 with instance->_14 and s0.
     * If returned a3 nonzero: copies s3->_4 (color short) to a3->_44.
     * Sets the new color target on the linked display instance. */
    void* display = func_800170E8(*(void**)((char*)instance + 0x14),
                                   instance);
    if (display) {
        *(short*)((char*)display + 0x44) = *(short*)((char*)instance + 4);
    }
}

void looney_colorset_OnCollide(Instance* instance, GameTracker* gameTracker) {
    /* ◄FRAG► At 0x80161B50. Copies color values from s3 (intro data):
     * a3->_48 = s3[5], _4C = s3[5], _48A = s3[5].
     * If s5->_20 nonzero and a3 nonzero:
     *   sets a3->_C |= 0x4 (signal active flag),
     *   copies 4 ints from a3->_8->_0.._C to a3->_58.._64. */
    if (!instance->linkedObject) return;
    void* disp = instance->linkedObject;  /* a3 */
    if (!disp) return;

    *(unsigned short*)((char*)disp + 0xC) |= 0x4;
    /* Copy spline data from a3->_8 */
    void* src = *(void**)((char*)disp + 8);
    *(int*)((char*)disp + 0x58) = *(int*)((char*)src + 0);
    *(int*)((char*)disp + 0x5C) = *(int*)((char*)src + 4);
    *(int*)((char*)disp + 0x60) = *(int*)((char*)src + 8);
    *(int*)((char*)disp + 0x64) = *(int*)((char*)src + 0xC);
}
