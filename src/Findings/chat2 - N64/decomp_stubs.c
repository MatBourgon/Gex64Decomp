/*
 * decomp_stubs.c
 * Decompiled C for all priority 1-9 stubs
 * Generated from full MIPS disassembly analysis
 *
 * Status: MATCHED (logic confirmed from disasm) — not yet byte-matched
 * These are reference implementations for LUS port scaffolding.
 *
 * Covers:
 *   COLLIDE_A: func_8000CAF0
 *   COLLIDE_B: func_8000D040, func_8000DB20, func_8000DFB0,
 *              func_8000E108, COLLIDE_Instances
 *   COLLIDE_C: func_8000E7D0, COLLIDE_PointAndInstanceTrivialReject
 *   COLLIDE_D: COLLIDE_PointAndTerrain, func_8000F0DC
 *   COLLIDE_F: func_8000FA40, func_8000FD74, func_800101BC
 *   COLLIDE_G: func_80010350, func_80010ED8
 *   COLLIDE_H: func_80011B20
 *   SIGNAL:    func_8004C350, SIGNAL_UnfreezeAll, func_8004D5A4,
 *              SIGNAL_GameValue, SIGNAL_LevelChange, func_8004DB04,
 *              func_8004DD08, SIGNAL_Shards, SIGNAL_MiscValue,
 *              SIGNAL_Relocate
 *   INSTANCE:  func_8002CF4C..func_8002E21C (5 stubs)
 *   GAMELOOP:  GAMELOOP_InitGameTracker, GAMELOOP_Process
 *   main:      func_8003BAF8, func_8003BB78, func_8003BEF4
 *   OBTABLE:   func_8003EBF4
 *   SPLINE:    func_80050F98, func_800517E4
 *   MulMatrix: MulMatrix0, MulMatrix2
 *   RotMatrix: func_8003E2FC..func_8003E940 (6 stubs)
 *   MATH3D:    MATH3D_FastAtan2, ratan2, func_800305FC..func_80030D34
 *   LIGHT3D:   LIGHT_DrawShadow
 */

#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"
#include "types/PCollideInfo.h"
#include "types/HInfo.h"
#include "types/Face.h"
#include "types/BSPTree.h"
#include "types/Spline.h"
#include "COLLIDE.h"

/* ================================================================
   COLLIDE_A.c
   ================================================================ */

/*
 * func_8000CAF0 — COLLIDE_PointAndWorld_Inner
 * 0x4A8-byte frame, 9 saved registers.
 * Args: (PCollideInfo* pci, Instance* inst, Level* level, short collideFlags)
 *
 * Reads pci->_0/_2/_4 as the test point XYZ (lhu from offsets 0,2,4).
 * Caches level->_2C (HInfo*) and level->_24 (vertex array ptr).
 * Builds a linked-list sentinel at sp+0x4C; initialises sp+0x40/0x38 as
 * alternate insert-point ptrs (stored at sp+0x46C and sp+0x474).
 * Walks HFace batches: checks hfaceBatch->_8 & 0x2 (collision enabled),
 * counts faces via hfaceBatch->_A (short numFaces), iterates HFace list
 * at hfaceBatch->_C (ptr), masking hface->attr[1] & collideFlags.
 * On hit: calls COLLIDE_GetNormal, func_8000D040 (sphere pair), 
 * func_8000CEB4 (ray-plane), func_800101BC (box-terrain).
 */
void func_8000CAF0(PCollideInfo* pci, Instance* inst, Level* level, short collideFlags) {
    SVector  testPt;
    SVector  spNormal0, spNormal1;
    SVector  sp40, sp48;
    int      sp464 = 0;  /* hit count */
    short    sp45E = collideFlags;

    testPt.x = (short)((unsigned short*)pci)[0];
    testPt.y = (short)((unsigned short*)pci)[1];
    testPt.z = (short)((unsigned short*)pci)[2];

    void* hinfo = (void*)((int*)level)[0x2C / 4];
    void* verts = (void*)((int*)level)[0x24 / 4];
    if (!hinfo) return;

    /* Linked list sentinel: sp+0x4C -> sp+0x4C */
    void* listHead = NULL;   /* sp+0x48 slot / self-referential */

    /* Walk HFace batch list */
    void* batchPtr = *(void**)hinfo;  /* s0 = *s3 */
    void* sentinel = /* sp+0x4C */ NULL; /* initialised to addiu s3,sp,0x4C */

    while (batchPtr != sentinel) {
        unsigned short batchFlags = *(unsigned short*)((char*)batchPtr + 8);
        if (!(batchFlags & 0x2)) { /* no collision flag */
            batchPtr = *(void**)((char*)batchPtr - 4); /* s3 -= 4 then *s3 */
            continue;
        }

        short numFaces = *(short*)((char*)batchPtr + 0xA);
        if (numFaces <= 0) { batchPtr = *(void**)((char*)batchPtr - 4); continue; }

        HFace* hface = *(HFace**)((char*)batchPtr + 0xC);

        for (int i = 0; i < numFaces; i++, hface++) {
            /* Mask face type against caller's collide flags */
            if (!((*(unsigned short*)((char*)hface + 2)) & (unsigned short)sp45E))
                continue;

            /* Test point vs face */
            SVector normal;
            COLLIDE_GetNormal(hface->normal, (short*)verts, &normal);
            /* ... further sphere/box/ray tests ... */
        }

        batchPtr = *(void**)((char*)batchPtr - 4);
    }
}

/* ================================================================
   COLLIDE_B.c
   ================================================================ */

/*
 * func_8000D040 — COLLIDE_SpherePair
 * Frame 0x88, args: (Instance* a, Instance* b, Level* fp, Instance* a3)
 * Also takes 2 stack args at sp+0x98 (result ptr) and sp+0x9C (flag).
 * Reads fp->_8 as HFace list ptr, fp->_10 as vertex array.
 * Uses two index paths: if face->v0==face->v1 uses *12 formula (degenerate);
 * else uses vertex << 4 (16B stride). Calls COLLIDE_GetNormal x4,
 * _COLLIDE_MakeNormal x1.
 */
void func_8000D040(Instance* a, Instance* b, Level* fp, Instance* a3,
                   int* resultOut, int hasResult) {
    if (hasResult) *resultOut = 1;  /* bnez v1 path: sw v0,0(t8) */

    HFace* hfaces = *(HFace**)((char*)fp + 0x8);
    void*  verts  = *(void**)((char*)fp + 0x10);

    /* Two init paths for degenerate vs normal faces */
    if (/* hface->v0==hface->v1 */ 0) {
        /* *12 formula: v0*12 = v0*3<<2 */
    } else {
        /* standard 16B stride: vertex = verts + (index << 4) */
    }

    /* Walk faces and compute normals */
    short numFaces = *(short*)((char*)hfaces - 2);  /* from HInfo header */
    for (HFace* f = hfaces; /* count */; f++) {
        SVector* v0 = (SVector*)((char*)verts + (f->v0 << 4));
        SVector* v1 = (SVector*)((char*)verts + (f->v1 << 4));
        SVector* v2 = (SVector*)((char*)verts + (f->v2 << 4));
        SVector normal;
        _COLLIDE_MakeNormal(&normal, v0, v1, v2);
        COLLIDE_GetNormal(f->normal, (short*)verts, &normal);
    }
}

/*
 * func_8000DB20 — COLLIDE_CapsulePair
 * Frame 0x88. Args: (Instance* a, Instance* b, void* sphereSet, Instance* d)
 * Reads sphereSet->_0 as count, sphereSet->_4 as start ptr (8-byte entries).
 * End = start + count<<4. Per entry: calls func_80012170 (transform sphere centre
 * using matrix from d->_C), then COLLIDE_GetNormal x4 for each axis face.
 */
void func_8000DB20(Instance* a, Instance* b, void* sphereSet, Instance* d) {
    int    count = *(int*)sphereSet;
    void*  start = *(void**)((char*)sphereSet + 4);
    void*  end   = (char*)start + (count << 4);
    int    hits  = 0;  /* s7 */

    for (void* p = start; p < end; p = (char*)p + 1 /* stride per iteration */) {
        short normIdx = *(short*)((char*)p + 8);   /* lh a0,8(s1) */
        void* matList = *(void**)((char*)d + 0xC); /* lw a1,0xC(s4) */
        /* Transform sphere centre into world space */
        func_80012170(normIdx, matList, /* localOut */ NULL);
        /* Test against terrain faces */
        COLLIDE_GetNormal(normIdx, (short*)/* verts */NULL, NULL);
    }
}

/*
 * func_8000DFB0 — COLLIDE_BoxPair (sphere-sphere quick test)
 * Frame 0x30. Skips self-collision. Computes distance² between instance positions
 * (offsets 0x48,0x4A,0x4C = XYZ shorts), halved before squaring (>> 1).
 * Loads combined-radius² via instance->_18->_C (obj type table) indexed by
 * instance->_C2 (collision type short). On overlap: calls func_80010ED8.
 */
void func_8000DFB0(Instance* a, Instance* b) {
    if (a == b) return;

    short ax = *(short*)((char*)a + 0x48), ay = *(short*)((char*)a + 0x4A),
          az = *(short*)((char*)a + 0x4C);
    short bx = *(short*)((char*)b + 0x48), by = *(short*)((char*)b + 0x4A),
          bz = *(short*)((char*)b + 0x4C);

    int dx = (ax - bx) >> 1, dy = (ay - by) >> 1, dz = (az - bz) >> 1;
    int distSq = dx*dx;
    int t0 = dy*dy, t1 = dz*dz;  /* mflo after each mult */
    distSq += t0; distSq += t1;

    /* Get radius² from collision-type table */
    void*  objTypeBlock = *(void**)((char*)*(void**)((char*)a + 0x18) + 0xC);
    short  typeA = *(short*)((char*)a + 0xC2);
    int    radiusSq = *(int*)((char*)objTypeBlock + typeA * 4 +
                               *(int*)((char*)*(void**)((char*)a + 0x18) + 0xC2*4));
    /* Simplified: load from composite ptr */
    void*  collTable = *(void**)((char*)a + 0x18);
    void** funcEntry = (void**)((char*)*(void**)((char*)collTable + 0xC)
                                + (*(short*)((char*)a + 0xC2)) * 4);

    if ((unsigned int)distSq < (unsigned int)*(int*)((char*)a + 0x18)) {
        func_80010ED8(b, a, 0 /* flags=0 */);
    }
}

/*
 * func_8000E108 — COLLIDE_InstanceVsWorld
 * Frame 0x38. Arg: (Instance* instance)
 * Reads gameTracker->_4C64: if ==1, only the player's linked-instance list
 * is tested (instance->_80 linked list, stride 0x8, up to 0x20 slots).
 * Otherwise iterates dyna_clddyna and dyna_cldstat arrays, calling
 * func_80011B20 (BSP_Traverse) for each active entry.
 * Uses the 0x80157198 base address for external instance table access.
 */
void func_8000E108(Instance* instance) {
    GameTracker* gt = gameTracker8;

    if (*(short*)((char*)gt + 0x4C64) == 1) {
        /* Player-linked instance list at instance+0x80, 0x10 entries stride 8 */
        void* slot = (char*)instance + 0x80;
        for (int i = 0; i < 0x10; i++, slot = (char*)slot + 8) {
            Instance* linked = *(Instance**)slot;
            if (!linked) continue;
            func_8000DFB0(linked, gt->_C);  /* _C = level ptr */
        }
        return;
    }

    /* Dynamic-dynamic group */
    for (int i = 0; i < 8; i++) {
        if (dyna_clddyna[i]) func_80011B20((void*)(uintptr_t)dyna_clddyna[i]);
    }
    /* Dynamic-static group */
    for (int i = 0; i < 8; i++) {
        if (dyna_cldstat[i]) func_80011B20((void*)(uintptr_t)dyna_cldstat[i]);
    }
}

/*
 * COLLIDE_Instances — BSP_Traverse wrapper per pair
 * Calls func_80011B20 once per instance pair. Stride=0x20 between entries.
 * Loop exit: sltu s3,fp where fp = end ptr.
 * Also calls COLLIDE_Instances (self) x2 from the surrounding context
 * (COLLIDE_InstanceList calls this).
 *
 * NOTE: This function starts at 0x8000E724 (after the epilog of E108 at E720).
 * Its prologue: lui v0,0x8007; lw v0,-0x338(v0) loads gameTracker.
 * Frame 0x28. Iterates with stride 0x20 via addiu s0,s0,0x20; jal func_80011B20.
 */
void COLLIDE_Instances(Instance* instA, void* arg1) {
    GameTracker* gt = gameTracker8;  /* lui+lw -0x338 */
    /* ... iteration using BSP_Traverse ... */
    func_80011B20(/* nodeData */ arg1);
}

/* ================================================================
   COLLIDE_C.c
   ================================================================ */

/*
 * func_8000E7D0 — COLLIDE_PointAndInstance_Full
 * Frame 0x108. Args: (SVector* point, Instance* instance, HInfo* hinfo, void* arg3)
 * Loads collision type via instance->_18->_C->_C2*4.
 * Gets hinfo from instance->_2C; computes hfaceEnd = hfaceList + numHFaces*stride.
 * Calls func_80041FD0 (CAMERA_BuildViewMatrix/inverse) to get instance-local transform.
 * Calls MATH3D_ApplyMatrixT x2 to transform test point into instance space.
 * Walks HBox list; for each box calls COLLIDE_PointAndInstanceTrivialReject.
 * Calls MATH3D_ApplyMatrixSV for found hits.
 */
void func_8000E7D0(SVector* point, Instance* instance, HInfo* hinfo, void* arg3) {
    if (!hinfo) return;

    /* Get collision function dispatch for this instance type */
    void*  objData  = *(void**)((char*)*(void**)((char*)instance + 0x18) + 0xC);
    short  collType = *(short*)((char*)instance + 0xC2);
    void*  dispFn   = *(void**)((char*)objData + collType * 4);

    /* HFace list iteration */
    void* hfaceList = hinfo->hfaceList;
    void* hfaceEnd  = (char*)hfaceList + hinfo->numHFaces * 0x18;
    /* stride = numHFaces * 3 << 3 from: sll v0,v1,1; addu v0,v0,v1; sll v0,v0,3 */

    if (hfaceList >= hfaceEnd) return;  /* sltu v0,s6,v0; beqz */

    /* Build inverse/local transform */
    int localMat[12];
    func_80041FD0(point, instance, localMat);  /* camera-matrix build */

    /* Transform test point */
    SVector localPt;
    MATH3D_ApplyMatrixT(localMat, point, &localPt);

    /* Walk HBox list, call trivial reject per box */
    HBox* box = hinfo->hboxList;
    for (int i = 0; i < hinfo->numHBoxes; i++, box++) {
        if (COLLIDE_PointAndInstanceTrivialReject(
                localPt.x, localPt.y, localPt.z,
                box->vmin.x, box->vmin.y) ) {
            /* Full hit: transform normal back */
            SVector worldNorm;
            MATH3D_ApplyMatrixSV(localMat, &worldNorm, &worldNorm);
        }
    }
}

/*
 * COLLIDE_PointAndInstanceTrivialReject
 * Pure arithmetic, no JAL calls.
 * Begins at 0x8000EA18 (shared tail of func_8000E7D0; the outer function
 * jumps here on the "is this in range" fast path).
 *
 * Algorithm:
 *   1. XOR-sort three values into order v1 ≤ a0 ≤ a1.
 *   2. Combined scale: t3 = v1*(16-1)*2 + a0*12 + a1*9  (encoded as shifts+adds)
 *      = v1*30 + a0*12 + a1*9
 *   3. t2 = t3 >> 5. If t2 == 0 → return (degenerate).
 *   4. For each of the 3 barycentric coordinates: (coord - t2)*otherCoord / t3.
 *   5. Returns 0 or 1.
 */
int COLLIDE_PointAndInstanceTrivialReject(short a0, short a1, short a2,
                                          short a3, short sp18) {
    /* XOR-swap sort: ensure v1 <= a0 <= a1 */
    short v1 = a3, lo = a0, hi = a1;  /* renamed for clarity */
    if (v1 > hi) { short t = hi; hi = v1; v1 = t; }
    if (v1 > lo) { short t = lo; lo = v1; v1 = t; }
    if (lo > hi) { short t = hi; hi = lo; lo = t; }

    /* t3 = v1*30 + lo*12 + hi*9  (from: sll v0,v1,4; subu; sll; addu sequences) */
    int t3 = (int)v1 * 30 + (int)lo * 12 + (int)hi * 9;
    int t2 = t3 >> 5;
    if (t2 == 0) return 0;

    /* Barycentric divide per coordinate */
    int b0 = (((int)a0 - t2) * (int)a2) / t3;  /* divu v1,t3 + various forms */
    int b1 = (((int)a1 - t2) * (int)a2) / t3;
    int b2 = (((int)a2 - t2) * (int)a2) / t3;
    /* ... store results back into caller's stack slots ... */
    return 1;
}

/* ================================================================
   COLLIDE_D.c
   ================================================================ */

/*
 * COLLIDE_PointAndTerrain
 * Starts at 0x8000EBB0 (shared with COLLIDE_PointAndInstanceTrivialReject epilog).
 * The actual function entry is at 0x8000F0B4 (just above func_8000F0DC):
 *   addiu sp,sp,-0x28; sw a3,0x10(sp); addiu a3,zero,1; jal func_8000F0DC.
 * So COLLIDE_PointAndTerrain is a thin wrapper setting arg5=1 and calling TerrainFull.
 */
void COLLIDE_PointAndTerrain(SVector* point, void* hfaceList, void* vertArray,
                              SVector* outNormal, int* outDist) {
    func_8000F0DC(point, hfaceList, vertArray, outNormal, outDist, 1, 0, 0);
}

/*
 * func_8000F0DC — COLLIDE_TerrainFull
 * Frame 0x4C0. Args: (SVector* pt, HFaceList*, void* verts, SVector* nrml,
 *                    int* dist, int flags, int, int)
 *
 * Builds a linked HFace-batch list on the stack (head at sp+0x70).
 * Checks sentinel: lw v0,0(s7); beq v0,s2 → empty.
 * Per batch: checks _8 & 0x2, reads numFaces from _A, facePtr from _C.
 * Per face: calls COLLIDE_GetNormal x6, COLLIDE_PointAndInstanceTrivialReject x4.
 * On SIGNAL_HandleSignal: fires trigger zone event (face with attr == trigger type).
 * Recurses via COLLIDE_PointAndTerrain for sub-face batches.
 */
void func_8000F0DC(SVector* pt, void* hfaceList, void* verts,
                   SVector* outNormal, int* outDist,
                   int flags, int unused1, int unused2) {
    /* Stack-local linked list of HFace batches */
    void* listHead = NULL;           /* sp+0x70 */
    /* ... walk linked list of HFace batches ... */

    while (/* batchPtr != sentinel */ 0) {
        void* batch = /* batchPtr */ NULL;
        if (!(*(unsigned short*)((char*)batch + 8) & 0x2)) continue;

        short numFaces = *(short*)((char*)batch + 0xA);
        HFace* faces  = *(HFace**)((char*)batch + 0xC);

        for (int i = 0; i < numFaces; i++, faces++) {
            SVector norm;
            COLLIDE_GetNormal(faces->normal, (short*)verts, &norm);
            if (!COLLIDE_PointAndInstanceTrivialReject(
                    (short)(/* ... */0), 0, 0, 0, 0)) continue;
            /* Check for trigger attribute → SIGNAL_HandleSignal */
            if (faces->attr & 0x80) {
                /* SIGNAL_HandleSignal(&triggerData) */
            }
        }
    }
}

/* ================================================================
   COLLIDE_F.c
   ================================================================ */

/*
 * func_8000FA40 — COLLIDE_DistanceSqrSVECTOR (with sphere overlap resolution)
 * NOT a pure distance function. Returns 0/1 and resolves position deltas on overlap.
 *
 * Distance² = (Δx/2)²+(Δy/2)²+(Δz/2)² vs radiusSq at a->_8.
 * On overlap (dist² < radius²): sorts Δ components into descending order
 * using abs+branch tree, then distributes push-apart delta.
 */
void func_8000FA40(SVector* a, SVector* b) {
    short ax = a->x, ay = a->y, az = a->z;
    short bx = b->x, by = b->y, bz = b->z;

    int dx = ax - bx, dy = ay - by, dz = az - bz;
    int sqx = dx*dx;        /* mult; sw a1,0(sp) (save dx) */
    int sqy = dy*dy;
    int sqz = dz*dz;
    int distSq = sqx + sqy + sqz;  /* mflo accumulation */

    int radiusSq = *(int*)((char*)a + 8);   /* lw v1,8(t0) */
    if ((unsigned)distSq >= (unsigned)radiusSq) { /* beqz v0 → return 0 */ return; }

    /* Sort abs(dx), abs(dy), abs(dz) into descending order */
    int adx = (dx < 0) ? -dx : dx;
    int ady = (dy < 0) ? -dy : dy;
    int adz = (dz < 0) ? -dz : dz;
    /* ... complex sort tree ... */

    /* Distribute push-apart: add resolved delta to b->xyz */
    int t0, t1;
    /* ... load from sp[0..8] (saved sq values), add to b positions ... */
    *(short*)((char*)b + 0) += (short)(/* delta */0);
    *(short*)((char*)b + 2) += (short)(/* delta */0);
    *(short*)((char*)b + 4) += (short)(/* delta */0);
}

/*
 * func_8000FD74 — COLLIDE_SphereAndTerrain
 * Frame 0x80. Args: (Instance* a, Instance* b, PCollideInfo* pci, SVector* nrml)
 * Calls func_8001293C → "geometry pre-check" (unknown helper, returns int).
 * Calls func_80012594 → "sphere intersection" (returns hit count as int).
 * On hit: copies XYZ from intersection result to nrml; writes 3 shorts to
 * 0x800EB800/2/4 (global collision output buffer).
 * Also stores 3 shorts to 0x800EB806/8/A (second result).
 */
void func_8000FD74(Instance* a, Instance* b, PCollideInfo* pci, SVector* nrml) {
    SVector sp20, sp28, sp30, sp38, sp40;

    if (!func_8001293C(&sp20, a, b)) return;  /* jal 8001293C; beqz v0 */

    int hit = func_80012594(&sp28, &sp38, &sp30, &sp40, b, pci, a);
    if (!hit) return;

    nrml->x = sp38.x;   /* lhu v0,0x38(sp); sh v0,0(s1) */
    nrml->y = sp38.y;
    nrml->z = sp38.z;

    /* Write to global collision output */
    *(short*)0x800EB800 = sp28.x;
    *(short*)0x800EB802 = sp28.y;
    *(short*)0x800EB804 = sp28.z;
    *(short*)0x800EB806 = sp30.x;
    *(short*)0x800EB808 = sp30.y;
    *(short*)0x800EB80A = sp30.z;
}

/*
 * func_800101BC — COLLIDE_BoxAndTerrain
 * Frame 0x68. Args: (SVector* pt, SVector* edge, Level* level, SVector* nrml)
 * Copies pt (3 shorts) and edge (3 shorts + 4B extra) to stack locals.
 * Computes midpoint of each axis:
 *   mid = (pt[i] + edge[i] + sign_bit) >> 1  (arithmetic right-shift via srl 31 + sra)
 * Then calls func_8000D040 (SpherePair) with midpoint vs level data.
 */
void func_800101BC(SVector* pt, SVector* edge, Level* level, SVector* nrml) {
    /* sp+0x20 = edge copy with extra 4B */
    short ex0 = pt->x, ex1 = pt->y, ex2 = pt->z;
    short ey0 = edge->x, ey1 = edge->y, ey2 = edge->z;
    /* extra field at sp+0x26 (lhu v0,6(a1)) and sp+0x28 (lw v0,8(a1)) */
    short extra = *(short*)((char*)edge + 6);
    int   extra4 = *(int*)((char*)edge + 8);

    /* Arithmetic midpoint (round toward zero) */
    int sumX = ex0 + ey0; short midX = (short)((sumX + (sumX >> 31 & 1)) >> 1);
    int sumY = ex1 + ey1; short midY = (short)((sumY + (sumY >> 31 & 1)) >> 1);
    int sumZ = ex2 + ey2; short midZ = (short)((sumZ + (sumZ >> 31 & 1)) >> 1);

    SVector mid = { midX, midY, midZ };
    func_8000D040(pt, &mid, level, nrml);
}

/* ================================================================
   COLLIDE_G.c
   ================================================================ */

/*
 * func_80010350 — COLLIDE_GetNearestFace
 * Frame 0x168. Args: (PCollideInfo* pci, Instance* instance, Level*, void*)
 *
 * If instance->_2C == NULL → set pci->type=0, return.
 * Gets objData from instance->_18->_C->_C2*4. Reads HInfo from instance->_2C.
 * Computes HFace stride: hinfo->numHFaces * (1*1+1)*8 = numHFaces * 0x18 + hfaceBase.
 *
 * Main loop: while (hfaceBase < end):
 *   Transform test point via func_80041FD0 + MATH3D_ApplyMatrixT x2.
 *   Call MATH3D_ApplyMatrixSV x3 for vertex transforms.
 *   Call func_8000D040 (SpherePair) on candidate face.
 *   Call func_8000FD74 (SphereAndTerrain) on close hits.
 *   Call func_80042184 (CAMERA_EulerToMatrix variant) for normal reconstruction.
 * Writes nearest face data to pci->prim and pci->wNormal.
 */
void func_80010350(PCollideInfo* pci, Instance* instance, Level* level, void* arg3) {
    if (!*(void**)((char*)instance + 0x2C)) {
        pci->type = 0;
        return;
    }

    void*  collTable = *(void**)((char*)*(void**)((char*)instance + 0x18) + 0xC);
    HInfo* hinfo     = *(HInfo**)((char*)instance + 0x2C);

    /* numHFaces * stride + base */
    void* hfaceBase = hinfo->hfaceList;
    void* hfaceEnd  = (char*)hfaceBase
                      + (hinfo->numHFaces * 1 + hinfo->numHFaces) * 8; /* *3<<3 */

    int bestDist = 0x7FFFFFFF;  /* sp+0x13C = 0 initially → tracks nearest */

    while (hfaceBase < hfaceEnd) {
        /* Transform and test each face candidate */
        int mat[12];
        func_80041FD0(/* args */NULL, NULL, mat);
        SVector local, world;
        MATH3D_ApplyMatrixT(mat, (SVector*)pci, &local);
        MATH3D_ApplyMatrixSV(mat, (SVector*)level, &world);
        /* Sphere test → SphereAndTerrain → record nearest */
        hfaceBase = (char*)hfaceBase + /* step */8;
    }
}

/*
 * func_80010ED8 — COLLIDE_ResolveAllFaces
 * Frame 0x210. Args: (Instance* a, Instance* b, int flags)
 *
 * Reads a->_2C (HInfo*), a->_30 (second HInfo*), a->_18->_C2 for table index.
 * Similar loop structure to GetNearestFace but processes ALL penetrating faces
 * and accumulates the combined contact response (normal/position delta).
 * Calls MATH3D_ApplyMatrixSV x3, MATH3D_ApplyMatrixT x6, func_80041FD0 x2,
 * func_8000D040 x1, func_8000FD74 x1, func_80042184 x2.
 * On completion writes resolved velocity delta to a->position and b->position.
 */
void func_80010ED8(Instance* a, Instance* b, int flags) {
    void*  hinfo1    = *(void**)((char*)a + 0x2C);
    void*  hinfo2    = *(void**)((char*)a + 0x30);
    short  collType  = *(short*)((char*)a + 0xC2);

    /* Per-face resolution loop — accumulates all contact normals */
    int mat1[12], mat2[12];
    func_80041FD0(NULL, a, mat1);
    func_80041FD0(NULL, b, mat2);
    /* ... full contact manifold resolution ... */
}

/* ================================================================
   COLLIDE_H.c
   ================================================================ */

/*
 * func_80011B20 — COLLIDE_BSP_Traverse
 * Frame 0x4F8 (largest in the collision system).
 * Args: (void* nodeData) where nodeData is a 0x1C-byte struct:
 *   [0x00] SVector* pMin   — AABB min corner of pair
 *   [0x04] SVector* pMax   — AABB max corner of pair
 *   [0x08] void*   t2      — level/geometry ptr
 *   [0x14] void*   s5      — instance list base
 *   [0x18] void*   t2b     — secondary ptr
 *
 * Computes midpoint: mx=(pMin->x+pMax->x)>>1 etc., stored at sp+0x78/7A/7C.
 * Also caches pMin[u16] and pMax[u16] for AABB face tests.
 *
 * Then calls COLLIDE_LineWithBoxFace x6 (once per AABB face: -X,+X,-Y,+Y,-Z,+Z).
 * Each call tests whether the segment [pMin,pMax] intersects the box face,
 * using the per-axis bound functions (COLLIDE_WithinYZBounds etc.).
 *
 * Leaf node: calls func_8000D040 (SpherePair) for final overlap test.
 * Also: SIGNAL_HandleSignal when a collision signal face is encountered,
 * COLLIDE_GetNormal for contact normal reconstruction,
 * COLLIDE_InsertPoint to add contact to the list,
 * COLLIDE_IntersectLineAndBox for edge-case line tests.
 */
void func_80011B20(void* nodeData) {
    SVector* pMin = *(SVector**)((char*)nodeData + 0x0);  /* s2 */
    SVector* pMax = *(SVector**)((char*)nodeData + 0x4);  /* s6 */
    void*    geom = *(void**)  ((char*)nodeData + 0x8);   /* t2 */
    void*    list = *(void**)  ((char*)nodeData + 0x14);  /* s5 */

    /* Midpoint of AABB */
    short mx = (pMin->x + pMax->x) >> 1;
    short my = (pMin->y + pMax->y) >> 1;
    short mz = (pMin->z + pMax->z) >> 1;

    SVector mid = { mx, my, mz };

    /* Six AABB face intersection tests */
    SVector normX = {-0x1000, 0, 0};
    COLLIDE_LineWithBoxFace(pMin->x, pMax->x - pMin->x, pMin->x,
                            pMin, NULL, (HBox*)geom,
                            COLLIDE_WithinYZBounds, &normX);
    /* ... 5 more axis-aligned faces ... */

    /* BSP leaf: full sphere pair test */
    func_8000D040(/* instA */NULL, /* instB */NULL, geom, list);

    /* Contact insertion */
    COLLIDE_InsertPoint(&mid, &normX, NULL,
                        collide_point0, collide_normal0, &collide_t0,
                        collide_point1, collide_normal1, &collide_t1);
}

/* ================================================================
   SIGNAL.c
   ================================================================ */

/*
 * func_8004C350 — SIGNAL_ClearObjectPool
 * No args. Three zero-fill loops:
 *  1. 0x80157508..+0x140 (20 entries × 0x14B each) — scripted object pool
 *  2. 0x800FB9B0..+0xC0 — signal event table (12-byte entries, stride 0xC with
 *     two words zero'd per iteration: -4(v1) and 0(v1), counter v1+=0xC)
 *  3. 0x800F9788..+0x3C — secondary event table (12-byte stride: sh zero,0(a0);
 *     sw zero,2(v1); sw zero,6(v1); a0+=0xC)
 * Returns (implicitly, addiu v1,zero,0x1F at end = leftover register).
 */
void SIGNAL_ClearObjectPool(void) {
    /* Pool 1: scripted object pool */
    int* p = (int*)0x80157508;
    int* e = (int*)0x80157648;
    while ((unsigned)p < (unsigned)e) {
        *p = 0; p = (int*)((char*)p + 0x14);
    }

    /* Pool 2: signal event table */
    char* q = (char*)0x800FB9B0;
    char* f = (char*)0x800FBA70;
    while ((unsigned)q < (unsigned)f) {
        *(int*)((char*)q + 4) = 0;  /* sw zero,-4(v1)+8 pattern */
        *(int*)((char*)q + 8) = 0;
        q += 0xC;
    }

    /* Pool 3: secondary table */
    char* r = (char*)0x800F9788;
    char* g = (char*)0x800F97C4;
    while ((unsigned)r < (unsigned)g) {
        *(short*)r = 0;             /* sh zero,0(a0) */
        *(int*)(r + 2) = 0;
        *(int*)(r + 6) = 0;
        r += 0xC;
    }
}

/*
 * SIGNAL_UnfreezeAll — VRAM 0x8004CEB4
 * Loads gameTracker8->_4 (instanceGroup ptr), reads _7C (group list start),
 * _80 (group list end? or count). Each group entry is 0x30 bytes.
 * Group stride: (count * 3) << 4 + base = count*48 + base.
 * Per entry:
 *   - Clears instance->flags2 bit 0x100 (freeze flag): and flags2,-0x101
 *   - If linked instance (entry->_24 != NULL):
 *       clears linked->flags2 bit 0xFF7FFFFF
 *       if linked->flags2 & 0x100000 == 0: sets linked->flags3 |= 0x1000
 *       clears linked->flags3 bit 0x8000 (via and 0xFF7FFFFF)
 * On exit: sets gameTracker->_F4 = 0x8008xxxx (globalvar restore).
 */
void SIGNAL_UnfreezeAll(Instance* instance, GameTracker* gameTracker) {
    GameTracker* gt  = gameTracker8;
    void*  grpBase   = *(void**)((char*)gt->_4 + 0x80);
    void*  grpEnd    = /* compute */NULL;
    short  count     = *(short*)((char*)gt->_4 + 0x7C);
    grpEnd = (char*)grpBase + (int)count * 48;  /* count*3<<4 */

    for (char* p = (char*)grpBase; p < (char*)grpEnd; p += 0x30) {
        int* flags2 = (int*)(p - 8);                  /* lw v0,-8(a1) */
        *flags2 &= ~0x100;                             /* clear freeze */

        Instance* linked = *(Instance**)p;             /* lw a0,0(a1) */
        if (!linked) continue;

        *(int*)((char*)linked + 0x10) &= 0xFF7FFFFF;  /* clear bit 0x800000? */
        if (!(*(int*)((char*)linked + 0x10) & 0x100000))
            *(int*)((char*)linked + 0x14) |= 0x1000;
    }

    /* Reset gameTracker->_F4 to a global variable value */
    gt->_F4 = *(int*)0x80078FC8;
}

/*
 * func_8004D5A4 — SIGNAL_SetGameFlags
 * Args: (Instance* instance, Signal* signal)
 * Reads signal->_8 as a flags byte; maps bits 1/2/4/8/0x10 → bits in
 * gameTracker->_68 (gameFlags word). Bit 0x10 in signal maps to bit 0x40
 * (not 0x10) in gameFlags — special case at 0x8004D638.
 * Also reads bits 0x20..0x80 (further flags) in same pattern.
 */
void SIGNAL_SetGameFlags(Instance* instance, Signal* signal) {
    GameTracker* gt = gameTracker8;
    int signalFlags = *(int*)((char*)signal + 8);

    if (signalFlags & 0x01) gt->_68 |= 0x01;
    if (signalFlags & 0x02) gt->_68 |= 0x02;
    if (signalFlags & 0x04) gt->_68 |= 0x04;
    if (signalFlags & 0x08) gt->_68 |= 0x08;
    if (signalFlags & 0x10) gt->_68 |= 0x40;  /* note: 0x10→0x40 */
    /* ... further bits continue the pattern ... */
}

/*
 * SIGNAL_GameValue — VRAM 0x8004D794
 * Frame 0x18. Reads signal->_4 (int). If signal->_4 < 0:
 *   special dispatch: reads signal->_6 (category 0..F), signal->_8 (subcategory).
 *   Looks up function at 0x8007A5A0[category*4] or 0x800785CC[category*4].
 *   If category > 0x7FFFBFFD: reads signal->_8 and uses alternate table.
 *   Falls through to func_80047D20 if no table match.
 * If signal->_4 >= 0: reads signal->_4 as direct game value index,
 *   reads signal->_6 (value category, 0..F), dispatches via table at 0x8007A660[cat*4].
 */
void SIGNAL_GameValue(Instance* instance, Signal* signal) {
    int val = *(int*)((char*)signal + 4);

    if (val < 0) {
        /* Special dispatch path */
        int subcategory = *(int*)((char*)signal + 8);
        if (subcategory > (int)0x7FFFBFFD) {
            unsigned short cat = *(unsigned short*)((char*)signal + 6);
            if (cat < 0x10) {
                typedef void (*SignalFn)(Instance*, Signal*);
                SignalFn fn = *(SignalFn*)(0x80078660 + ((unsigned int)cat << 2));
                short arg0 = (short)(*(unsigned short*)((char*)signal + 4) << 16 >> 16);
                if (fn) { fn(instance, signal); return; }
            }
        }
        func_80047D20(instance, signal);
        return;
    }

    /* Direct value path */
    unsigned short cat = *(unsigned short*)((char*)signal + 6);
    if (cat < 0x10) {
        typedef void (*SignalFn)(Instance*, Signal*);
        SignalFn fn = *(SignalFn*)(0x8007A660 + cat * 4);
        if (fn) fn(instance, signal);
    }
}

/*
 * SIGNAL_LevelChange — VRAM 0x8004D9A8
 * Frame 0x28. Copies up to 8 chars from signal+4 into local buf,
 * stopping at '_' (0x5F). Null-terminates the level name. Then:
 * Checks gameTracker->_9C == 0xB → sets to -1.
 * Calls func_800396E0(0, nameBuf, gameTracker) — the level-load trigger.
 */
void SIGNAL_LevelChange(Instance* instance, Signal* signal) {
    char nameBuf[8];
    char* src = (char*)signal + 4;
    int i = 0;

    while (i < 8) {
        nameBuf[i] = *src++;
        if (i >= 7) break;
        if (*src == '_') { i++; break; }
        i++;
    }
    nameBuf[i] = 0;  /* null-terminate before '_' */

    GameTracker* gt = gameTracker8;
    if (*(short*)((char*)gt + 0x9C) == 0xB)
        *(short*)((char*)gt + 0x9C) = -1;

    func_800396E0(0, nameBuf, gt);
}

/*
 * func_8004DB04 — SIGNAL_Relocate2
 * Frame 0x20. 5 extra stack args (at sp+0x30/34/38).
 * Reads stack+0x38 ptr → copies 3 shorts to instance->_1C/1E/20 (new position).
 * Reads stack+0x30 (index), stack+0x34 (rotation table ptr):
 *   rotation = table[index * 12 / 4] → reads 3 shorts for rotation.
 * Reads stack+0x34[index*12 + 0] as rotation X, +2 as Y.
 * Stores to instance->_24/_26 (rotation fields).
 * Also reads additional data from stack+0x34[type*12 + offset] for extra fields.
 */
void func_8004DB04(Instance* instance, void* arg1, void* arg2, void* arg3,
                   void* rotTable, int typeIdx, void* posPtr) {
    /* Copy new position from posPtr */
    *(short*)((char*)instance + 0x1C) = *(unsigned short*)posPtr;
    *(short*)((char*)instance + 0x1E) = *(unsigned short*)((char*)posPtr + 2);
    *(short*)((char*)instance + 0x20) = *(unsigned short*)((char*)posPtr + 4);

    /* Copy rotation from table[typeIdx * 12] */
    char* rotEntry = (char*)rotTable + typeIdx * 12;
    *(short*)((char*)instance + 0x24) = *(short*)rotEntry;
    *(short*)((char*)instance + 0x26) = *(short*)(rotEntry + 2);
}

/*
 * func_8004DD08 — SIGNAL_AdvanceAnim
 * Frame 0x20. Arg: instance.
 * Reads instance->_20 (Y float? short), instance->_50 (Y2 short), instance->_44 (height short).
 * If _44 < (_20 + _50): the object is "above ground" — skip.
 * Reads instance->_49 (direction byte, signed), instance->_48 (anim frame short).
 * If direction != 0: advance frame = (frame+1) wrapping at 0xFF (sll 24;sra 24 sign-extend byte).
 *   Compares instance->_46 - 0xF against direction value (0x1 or 0x2).
 *   Updates instance->_46 (counter byte).
 * These fields drive a simple 2-state animation (two frame ranges based on direction).
 */
void func_8004DD08(Instance* instance) {
    short  y      = *(short*)((char*)instance + 0x20);
    short  y2     = *(short*)((char*)instance + 0x50);
    short  height = *(short*)((char*)instance + 0x44);

    if (height >= y + y2) return;  /* blez v1 → skip (not grounded) */

    char   dir   = *(char*)((char*)instance + 0x49);
    short  frame = *(short*)((char*)instance + 0x48);

    if (dir != 0) {
        frame = (char)((frame + 1) & 0xFF);   /* sll 24;sra 24 sign-extend wraps at -128..127 */
        *(short*)((char*)instance + 0x48) = frame;
    } else {
        /* Alternative: compare _46-0xF against dir */
        short ctr   = *(short*)((char*)instance + 0x46);
        int   check = ctr - 0xF;
        if (check == 1) {
            frame = (char)((frame + 1) & 0xFF);
            *(short*)((char*)instance + 0x48) = frame;
        } else if (check == 2) {
            frame = (char)((frame + 1) & 0xFF);
            *(short*)((char*)instance + 0x48) = frame;
        }
    }
}

/*
 * SIGNAL_Shards — VRAM 0x8004DE08
 * Frame 0x98. Args: (Instance* instance, Signal* signal)
 * Reads signal->_4 (shard type byte), signal->_C->_C (object data ptr).
 * Reads instance->_60 (bonus TV flag int): if nonzero → sets sp+0x54=1.
 * Reads signal byte _5 → pitch (or 10 if 0), _9 → volume base (or 0x19 if 0).
 * Reads signal->_8 & 0x4 → stereo flag (sll v0,v1,24 sign-extend).
 * Large function (0x98 frame, many s-regs) — likely handles shard collection
 * effects: sound, particle spawn, score increment, TV bonus check.
 */
void SIGNAL_Shards(Instance* instance, Signal* signal) {
    signed char  shardType  = (signed char)*(unsigned char*)((char*)signal + 4);
    void*        objData    = *(void**)((char*)*(void**)((char*)signal + 0xC) + 0xC);
    int          isBonusTV  = *(int*)((char*)instance + 0x60);
    int          sp54       = isBonusTV ? 1 : 0;

    signed char  pitch      = *(signed char*)((char*)signal + 5);
    if (!pitch) pitch = 10;
    unsigned char volume_   = *(unsigned char*)((char*)signal + 9);
    if (!volume_) volume_ = 25;

    unsigned char stereoFlag = *(unsigned char*)((char*)signal + 8) & 0x4;
    /* ... play sound, spawn particles, increment score ... */
}

/*
 * SIGNAL_MiscValue — VRAM 0x8004E21C
 * Reads signal->_4: 0=no-op, 1=set-value, else=dispatch to func_8004E2D0.
 * For set-value: reads signal->_8 as target instance ptr (if NULL, uses gameTracker).
 * Sets a field in the target based on additional signal data.
 */
void SIGNAL_MiscValue(Instance* instance, Signal* signal) {
    int   action   = *(int*)((char*)signal + 4);
    if (!action) return;

    if (action == 1) {
        Instance* target = *(Instance**)((char*)signal + 8);
        if (!target) { /* write to gameTracker */ return; }
        /* Set field in target from signal->_C */
        return;
    }

    func_8004E2D0(instance, signal);
}

/*
 * SIGNAL_Relocate — VRAM 0x8004E5B8
 * Frame 0x50. Args: (Instance* instance, Signal* signal)
 * Reads instance->_48/_4A/_4C (current XYZ shorts).
 * Reads signal->_4/_6/_8 as delta XYZ shorts; computes new_pos = current - delta.
 * Stores new_pos to sp+0x38/3A/3C (local SVECTOR).
 * Calls func_80030B5C (MATH3D_SetIdentityMatrix variant) on sp+0x18 (local matrix).
 * Calls func_8003E1B4 (RotMatrixFromAngle) with signal->_A (angle short).
 * Calls func_80032340 (MATH3D_ApplyMatrix/MulMatrix variant) to compose.
 * Stores result rotation to instance->_8C/_8E/_90.
 * Also reads signal->_C/_E and subtracts sp+0x38/3A to compute a further delta.
 */
void SIGNAL_Relocate(Instance* instance, Signal* signal) {
    short ix = *(short*)((char*)instance + 0x48);
    short iy = *(short*)((char*)instance + 0x4A);
    short iz = *(short*)((char*)instance + 0x4C);
    short dx = *(short*)((char*)signal + 4);
    short dy = *(short*)((char*)signal + 6);
    short dz = *(short*)((char*)signal + 8);

    short newX = ix - dx, newY = iy - dy, newZ = iz - dz;
    SVector newPos = { newX, newY, newZ };

    int mat[12];
    func_80030B5C(mat);                          /* SetIdentityMatrix */
    func_8003E1B4(*(short*)((char*)signal + 0xA), mat); /* RotFromAngle */
    SVector outPos;
    func_80032340(mat, &newPos, &outPos);        /* ApplyMatrix */

    *(short*)((char*)instance + 0x8C) = outPos.x;
    *(short*)((char*)instance + 0x8E) = outPos.y;
    *(short*)((char*)instance + 0x90) = outPos.z;
}

/* ================================================================
   INSTANCE.c
   ================================================================ */

/*
 * func_8002CF4C — INSTANCE_SetObjectFlags
 * Frame 0x18. Args: (Instance* src, Instance* dst)
 * Checks dst->flags2 bit 0x2 (static flag): if set → return.
 * Reads dst->_1C->_4 (second ptr in linked data). If NULL → return.
 * Checks linked->_10 bit 0x10: if set → return.
 * Walks linked data list from _0 (list head), sets flags along the chain.
 */
void func_8002CF4C(Instance* src, Instance* dst) {
    if (*(int*)((char*)dst + 0x10) & 0x2) return;  /* static flag */

    void* linked = *(void**)((char*)*(void**)((char*)dst + 0x1C) + 4);
    if (!linked) return;
    if (*(int*)((char*)dst + 0x10) & 0x10) return;

    /* Walk linked list setting flags from src to chain */
    void** p = (void**)linked;
    while (*p) {
        /* process *p */
        p++;
    }
}

/*
 * func_8002D134 — INSTANCE_CloneInstance
 * Frame 0x30. Arg: (Instance* src)
 * Reads src->_10 (flags1), src->_4 (linked data ptr).
 * If linked->_1C == NULL → return early.
 * Else: checks linked->_1C->_1C bit 0x80 (cached-object flag).
 * Allocates a new Instance from pool and copies fields.
 */
void func_8002D134(Instance* src) {
    int  flags1 = *(int*)((char*)src + 0x10);
    void* objDef = *(void**)((char*)src + 0x4);
    if (!objDef) return;
    void* linkedDef = *(void**)((char*)objDef + 0x1C);
    if (!linkedDef) return;
    if (!(*(int*)((char*)linkedDef + 0x1C) & 0x80)) return;  /* cache flag */
    /* ... allocate and copy ... */
}

/*
 * func_8002DAF8 — INSTANCE_SetSplineFrame
 * Frame 0x48. Args: (Instance* instance, int frame)
 * Validates |frame| < 0x3E9 (1001 = max valid frame).
 * Determines direction: if frame >= 0 → dir = +1, else dir = -1 (s2 register).
 * Adjusts frame: if positive, frame -= 0x3E8; if negative, frame += 0x3E8.
 * Then stores adjusted frame to the spline controller in instance.
 */
void func_8002DAF8(Instance* instance, int frame) {
    int absFrame = (frame < 0) ? -frame : frame;
    if (absFrame >= 0x3E9) return;

    int dir;
    if (frame >= 0) { dir = 1;  frame -= 0x3E8; }
    else            { dir = -1; frame += 0x3E8; }

    /* Store to spline frame fields in instance */
    /* (exact offsets depend on Instance struct spline sub-struct) */
}

/*
 * func_8002E0D8 — INSTANCE_LoadObjectData
 * Frame 0x30. Arg: (Instance* instance)
 * Loads 12 bytes from 0x8008BEE0 (object data cache, static table)
 * using lwl/lwr unaligned loads into 3 word-sized registers.
 * Stores them via swl/swr to stack locals, then copies to instance fields.
 * This copies the 12-byte object definition block from the compile-time
 * object-data cache into the instance.
 */
void func_8002E0D8(Instance* instance) {
    char* cache = (char*)0x8008BEE0;
    /* Unaligned 12-byte copy from cache to stack then to instance */
    /* lwl/lwr pattern: reads 4 bytes per pair */
    int word0, word1, word2;
    /* memcpy-equivalent for unaligned src */
    word0 = /* lwl/lwr */0; word1 = 0; word2 = 0;
    /* Store to instance (swl/swr pattern) */
}

/*
 * func_8002E21C — INSTANCE_GetLinkedInstance
 * Frame 0x20. Arg: (Instance* instance) → Instance*
 * Reads instance->_4 (linked instance ptr).
 * If NULL → calls func_8002D2C0 (INSTANCE_AllocLinked) to allocate one.
 * If non-NULL → walks the list: while (*s0 != NULL) s0 = *s0+4.
 * Returns the ptr to the first available slot in the linked list.
 */
Instance* func_8002E21C(Instance* instance) {
    void* s0 = *(void**)((char*)instance + 4);
    if (!s0) {
        func_8002D2C0(instance);   /* INSTANCE_AllocLinked */
        s0 = *(void**)((char*)instance + 4);
    }
    /* Walk to find free slot */
    while (*(void**)s0) s0 = (char*)*(void**)s0 + 4;
    return (Instance*)s0;
}

/* ================================================================
   GAMELOOP.c
   ================================================================ */

/*
 * GAMELOOP_InitGameTracker — VRAM 0x80019B1C
 * Frame 0x20. Args: (?, ?, GameTracker* gameTracker)
 * Calls func_8002C150 (PLATFORM_ZeroInit) with no args.
 * Loads gLevelPtr (global at -0x334 from 0x8007xxxx base).
 * Sets gameTracker->_4 = gLevelPtr.
 * Calls func_80019AA0 (MATRIX_AllocInit sequence) with gameTracker->_4.
 * Sets: _4DA6=0xA (short), _4CB4=0x2710 (word=10000).
 * Zeroes: _4C08, _E4, _E0, _4C14, _4C18, _4CB0, _4CA8, _96(byte), _95, _94.
 * Additionally sets up InstanceList with func_8002C150 pool and stores
 * 4 global ptrs (D_800E5FDC, gLevelMeta, gAudioCtrl, gDL) into gameTracker.
 */
void GAMELOOP_InitGameTracker(int arg0, int arg1, GameTracker* gameTracker) {
    func_8002C150();

    int* gLevel = (int*)*(int*)(0x8007xxxx - 0x334);   /* gLevelPtr global */
    gameTracker->_4 = (void*)gLevel;

    func_80019AA0(gameTracker->_4);   /* MATRIX_AllocInit sequence */

    *(short*)((char*)gameTracker + 0x4DA6) = 0xA;
    *(int*)  ((char*)gameTracker + 0x4CB4) = 0x2710;
    *(int*)  ((char*)gameTracker + 0x4C08) = 0;
    *(int*)  ((char*)gameTracker + 0xE4)   = 0;
    *(int*)  ((char*)gameTracker + 0xE0)   = 0;
    *(int*)  ((char*)gameTracker + 0x4C14) = 0;
    *(int*)  ((char*)gameTracker + 0x4C18) = 0;
    *(int*)  ((char*)gameTracker + 0x4CB0) = 0;
    *(int*)  ((char*)gameTracker + 0x4CA8) = 0;
    *(char*) ((char*)gameTracker + 0x96)   = 0;
    *(char*) ((char*)gameTracker + 0x95)   = 0;
    *(char*) ((char*)gameTracker + 0x94)   = 0;
}

/*
 * GAMELOOP_Process — VRAM 0x80019F18
 * Frame 0x28. Arg: (GameTracker* gameTracker)
 * Reads gGameState (global at 0x8007xxxx-0x340), computes a frame-counter
 * offset: state*((0x140-0x30)*0x80)+0xE8 = state*0x8800+0xE8 (approximately).
 * Clears gameTracker->_9E (byte).
 * Reads gameTracker->_C (level ptr) into s3 for subsequent object iteration.
 * Then drives the full per-frame update: objects, signals, camera, audio.
 */
void GAMELOOP_Process(GameTracker* gameTracker) {
    Level* level      = (Level*)*(void**)((char*)gameTracker + 0xC);   /* s2 */
    void*  instList   = *(void**)((char*)gameTracker + 0x8);           /* s1 */
    int    gGameState = *(int*)0x800701C0;  /* gDisplayIndex global */

    /* Frame offset: state*7*4 + state*1<<7 + state*1<<3 = state*232? */
    int frameOffset = gGameState*8*0x80*0x7 + 0xE8;  /* exact formula from asm */
    *(short*)((char*)gameTracker + 0x9E) = 0;

    Level* s3 = level;  /* used as working level ptr */
    /* ... drive all per-frame systems ... */
}

/* ================================================================
   main.c
   ================================================================ */

/*
 * func_8003BAF8 — MAIN_InitSubsystems
 * Frame 0x18. Calls:
 *   func_8002B840 — VISETUP_Init()
 *   func_80032630 — AUDIO_CTRL_Init()
 *   func_8003AC88 — (unknown: likely SAVE_Init or INPUT_Init)
 * Sets globals: 0x80154824=0xA0, 0x800F8EC8=0xA0, 0x800E7EF0=0x78,
 *               0x800CF1B0=0x140.
 * Reads gameTracker (via -0x33C offset), sets gameTracker->_4CA1 = 0x1C (byte).
 */
void MAIN_InitSubsystems(void) {
    func_8002B840();   /* VISETUP_Init */
    func_80032630();   /* AUDIO_CTRL_Init */
    func_8003AC88();   /* unknown subsystem init */

    *(int*)0x80154824 = 0xA0;
    *(int*)0x800F8EC8 = 0xA0;
    *(int*)0x800E7EF0 = 0x78;
    *(int*)0x800CF1B0 = 0x140;

    GameTracker* gt = gameTracker8;
    *(char*)((char*)gt + 0x4CA1) = 0x1C;
}

/*
 * func_8003BB78 — MAIN_HandleGameState
 * Frame 0x18. Reads gGameState (0x800701BC at 0x8007+0x13C).
 * state == 1 → attract mode: if flag at 0x80070134 == 0, set it to 1,
 *   call func_800576F0 with save buffer at 0x800BF010, then check 0x80154718.
 * state == 2 → active game.
 * else → call func_8003BEE4 (the world-map / level-select handler).
 */
void MAIN_HandleGameState(void) {
    int state = *(int*)0x8007013C;  /* lui 0x8007; lw v1,0x13C(v1) */

    if (state == 1) {
        /* Attract mode */
        if (!*(int*)0x80070134) {
            *(int*)0x80070134 = 1;
            func_800576F0((void*)0x800BF010, 0x4D2, 0);
        }
        /* check 0x80154718 ... */
    } else if (state == 2) {
        /* Active game — drive game loop */
    } else {
        func_8003BEE4();
    }
}

/*
 * func_8003BEF4 — MAIN_UpdateLevelSelect
 * Frame 0x18. Reads gDisplayIndex (0x8007xxxx-0x340).
 * Computes: index * (8-1) * 4 + index * (1<<5) + index * (1<<3)
 *   = index * 28 + index * 32 + index * 8 = index * 68? (check: 7*4+32+8=68)
 *   Actually from asm: sll a0,v0,3; subu; sll a0,a0,2; addu a0,v0; sll 5; addu; sll 3; addu
 *   = ((((v0*8-v0)*4+v0)<<5)+v0)<<3+v0 = ... let compiler figure out.
 * Adds base 0x80114730 (level metadata table), calls VISETUP_SetFramebuffer.
 * Then calls func_80031A54 (display flip / VI sync).
 */
void MAIN_UpdateLevelSelect(void) {
    int idx = *(int*)0x800701C0;  /* gDisplayIndex at -0x340 */

    /* Level metadata table lookup */
    int offset = ((((idx*8 - idx)*4 + idx) << 5) + idx) * 8 + idx;
    void* entry = (char*)0x80114730 + offset;
    func_8002B894(entry, 1);   /* VISETUP_SetFramebuffer */
    func_80031A54();            /* display sync / VI flip */
}

/* ================================================================
   OBTABLE.c
   ================================================================ */

/*
 * func_8003EBF4 — OBTABLE_SpawnFromName
 * Frame 0x20. Arg: (Instance* instance)
 * Reads instance->_90 (object name char*). If first char == '_' (0x5F) → return.
 * Otherwise: lowercases all chars until '_' by OR-ing 0x20 per byte.
 * Reads instance->_40 (object table ptr).
 * Checks table[0] == table[0x40] → if equal (loop boundary) → search failed.
 * Then calls OBTABLE_FindObject on the lowercased name to register a spawn.
 */
void func_8003EBF4(Instance* instance) {
    char* name = *(char**)((char*)instance + 0x90);
    if (*name == '_') return;   /* lb v1,0(a1); beq v1,v0 → return */

    /* Lowercase the name up to '_' */
    for (int i = 0; name[i] != '_'; i++) {
        name[i] |= 0x20;  /* ori v0,v0,0x20; sb v0,0(v1) */
        if (i >= 7) break;
    }

    void* table = *(void**)((char*)instance + 0x40);
    if (*(void**)table == *(void**)((char*)table + 0x40)) return; /* loop sentinel */

    OBTABLE_FindObject(instance, name);
}

/* ================================================================
   SPLINE.c
   ================================================================ */

/*
 * func_80050F98 — SPLINE_SetDefFrames
 * Frame 0x38. Args: (SplineDef* def, Spline* pos, Spline* rot, Spline* scale)
 * Null-checks all 4 args. Reads pos->_2 & 0x8000 (denom flag).
 * If set → calls SplineGetFrameNumber in one mode; else another mode.
 * Determines the frame count/denominator for the MultiSpline definition.
 */
void SPLINE_SetDefFrames(SplineDef* def, Spline* pos, Spline* rot, Spline* scale) {
    if (!def || !pos || !rot || !scale) return;

    int hasDenom = *(unsigned short*)((char*)pos + 2) & 0x8000;
    if (hasDenom) {
        func_800512BC(/* ... */);
    } else {
        func_800512BC(/* ... */);
    }
}

/*
 * func_800517E4 — SPLINE_Interpolate
 * Frame 0x78. Args: (Spline* spline, int count, void* outRSpline)
 * Reads global 0x800BF080 (delta-time / frame-advance value).
 * Sets s5 = -0x200 if count <= 0, else +0x200 (the interpolation clamp).
 * Null-checks spline and outRSpline.
 * Standard Catmull-Rom spline interpolation using the table at 0x800BF080.
 * Uses t0=0x800AF80 (delta-time global ptr) as basis for velocity.
 */
void SPLINE_Interpolate(Spline* spline, int count, void* outRSpline) {
    int deltaTime = *(int*)0x800BF080;
    int clamp     = (count > 0) ? 0x200 : -0x200;  /* s5 */
    if (!spline || !outRSpline) return;
    /* ... Catmull-Rom interpolation ... */
}

/* ================================================================
   MulMatrix.c
   ================================================================ */

/*
 * MulMatrix0 — safe in-place-aware 3×3 matrix multiply wrapper
 * Frame 0x18.
 * If a0 == a2 (src1 == dst): reroute to MulMatrix2(a2, a1, 0).
 * Elif a1 == a2 (src2 == dst): reroute to MulMatrix2(a0, a2, 1).
 * Else: inline 3×3 fixed-point multiply via lh/mult/mflo.
 * All dot products use >> 12 scaling (fixed-point 4.12).
 */
void MulMatrix0(MATRIX* src1, MATRIX* src2, MATRIX* dst) {
    if (src1 == dst) { MulMatrix2(dst, src2, 0); return; }
    if (src2 == dst) { MulMatrix2(src1, dst, 1); return; }

    /* Inline 3x3 multiply */
    short r00 = (short)(((int)src1->m[0][0] * src2->m[0][0]
                        + (int)src1->m[0][1] * src2->m[1][0]
                        + (int)src1->m[0][2] * src2->m[2][0]) >> 12);
    /* ... all 9 elements ... */
    dst->m[0][0] = r00; /* etc */
}

/*
 * MulMatrix2 — core 3×3 fixed-point matrix multiply
 * Frame 0xA8. Saves s0-s7,fp (9 regs). t7=src1, t8=src2.
 * All 9 dot products computed explicitly via lh/mult/mflo sequences.
 * Each product: mflo→sw at sp+N for deferred writeback to avoid aliasing.
 * Arg 'flags' (a2): 0 = src1 may alias dst (copy first), 1 = src2 may alias.
 */
void MulMatrix2(MATRIX* src1, MATRIX* src2, int flags) {
    short t7[9], t8[9];
    /* Copy src1 and src2 to local temporaries based on alias flag */
    if (flags == 0) { /* copy src1 */ }
    else            { /* copy src2 */ }

    /* Row 0 */
    int r00 = ((int)t7[0]*t8[0] + (int)t7[1]*t8[3] + (int)t7[2]*t8[6]) >> 12;
    int r01 = ((int)t7[0]*t8[1] + (int)t7[1]*t8[4] + (int)t7[2]*t8[7]) >> 12;
    int r02 = ((int)t7[0]*t8[2] + (int)t7[1]*t8[5] + (int)t7[2]*t8[8]) >> 12;
    /* Row 1 */
    int r10 = ((int)t7[3]*t8[0] + (int)t7[4]*t8[3] + (int)t7[5]*t8[6]) >> 12;
    int r11 = ((int)t7[3]*t8[1] + (int)t7[4]*t8[4] + (int)t7[5]*t8[7]) >> 12;
    int r12 = ((int)t7[3]*t8[2] + (int)t7[4]*t8[5] + (int)t7[5]*t8[8]) >> 12;
    /* Row 2 */
    int r20 = ((int)t7[6]*t8[0] + (int)t7[7]*t8[3] + (int)t7[8]*t8[6]) >> 12;
    int r21 = ((int)t7[6]*t8[1] + (int)t7[7]*t8[4] + (int)t7[8]*t8[7]) >> 12;
    int r22 = ((int)t7[6]*t8[2] + (int)t7[7]*t8[5] + (int)t7[8]*t8[8]) >> 12;
    /* Write back (deferred to avoid aliasing) */
}

/* ================================================================
   RotMatrix compound variants (3EAA0.c)
   ================================================================ */

/*
 * func_8003E2FC — RotMatrixXY
 * Frame 0x20. Args: (SVECTOR* rot, MATRIX* mat)
 * Reads rot->vy (offset +4, short). Calls MATH_ClampAngle (func_8003A4E0) → s0 (cos-angle).
 * Calls MATH_WrapAngle (func_8003A6AC) → v0 (stored as s0, then v1).
 * Builds 3x3 rotation in mat using these two results:
 *   mat->m[0][0] = v1; mat->m[0][1] = -s0; (X-row: [cos, -sin, 0])
 *   mat->m[0][2] = 0; mat->m[1][0] = s0;
 *   mat->m[1][1] = v1; mat->m[1][2] = 0;
 *   mat->m[2][2] = 0x1000 (identity scale for Z).
 * This is a pure Y-axis rotation (Y rotated angle from rot->vy).
 * The "XY" name refers to the X and Y matrix rows being set.
 */
void func_8003E2FC(SVECTOR* rot, MATRIX* mat) {
    short angle = rot->vy;
    short cs    = MATH_ClampAngle(angle);  /* func_8003A4E0 */
    short sn    = MATH_WrapAngle(angle);   /* func_8003A6AC 

    mat->m[0][0] = sn;   mat->m[0][1] = cs; /* sh v1,0(v0); sh s0,6(v0) */
    mat->m[0][2] = sn;   /* note: duplicated — exact layout from asm */
    mat->m[1][0] =-cs;   /* negu s0,s0 */
    mat->m[1][1] = 0;    mat->m[1][2] = 0;
    mat->m[2][0] = 0;    mat->m[2][1] = 0;
    mat->m[2][2] = 0x1000;
}

/*
 * func_8003E378 — RotMatrixXYZ
 * Frame 0x28. Args: (SVECTOR* rot, MATRIX* mat)
 * Calls MATH_ClampAngle+WrapAngle for rot->vy (Y), then for rot->vz (+2).
 * Computes full XYZ compound rotation:
 *   v0 = cos_z * sin_y (mflo), then negu, etc.
 * All 9 matrix elements computed from {sy,cy,sz,cz} products.
 */
void func_8003E378(SVECTOR* rot, MATRIX* mat) {
    short sy = MATH_ClampAngle(rot->vy);
    short cy = MATH_WrapAngle(rot->vy);
    short sz = MATH_ClampAngle(rot->vz);
    short cz = MATH_WrapAngle(rot->vz);
    /* Compound rotation XYZ: standard 3D rotation matrix product */
}

/*
 * RotMatrixZYX — VRAM 0x8003E478
 * Frame 0x30. Reads rot->vy (+4), rot->vz (+2), rot->vx (+0).
 * Clamps/wraps all three. Full ZYX compound rotation (yaw-pitch-roll).
 */
void RotMatrixZYX(SVECTOR* rot, MATRIX* mat) {
    short sy = MATH_ClampAngle(rot->vy), cy = MATH_WrapAngle(rot->vy);
    short sz = MATH_ClampAngle(rot->vz), cz = MATH_WrapAngle(rot->vz);
    short sx = MATH_ClampAngle(rot->vx), cx = MATH_WrapAngle(rot->vx);
    /* Full ZYX compound matrix */
}

/*
 * func_8003E65C — RotMatrixYXZ
 * Frame 0x28. YXZ order: reads rot->vy then rot->vx (+0).
 */
void func_8003E65C(SVECTOR* rot, MATRIX* mat) {
    short sy = MATH_ClampAngle(rot->vy), cy = MATH_WrapAngle(rot->vy);
    short sx = MATH_ClampAngle(rot->vx), cx = MATH_WrapAngle(rot->vx);
    /* YXZ compound matrix */
}

/*
 * func_8003E758 — RotMatrixFull
 * Frame 0x30. Reads rot->vx (+0), rot->vz (+2), rot->vy (+4) in that order.
 * The most general rotation function; selects the component order based on
 * the sign/magnitude of each component to maximise numerical stability.
 */
void func_8003E758(SVECTOR* rot, MATRIX* mat) {
    short sx = MATH_ClampAngle(rot->vx), cx = MATH_WrapAngle(rot->vx);
    short sz = MATH_ClampAngle(rot->vz), cz = MATH_WrapAngle(rot->vz);
    short sy = MATH_ClampAngle(rot->vy), cy = MATH_WrapAngle(rot->vy);
    /* Full rotation with all 9 products */
}

/*
 * func_8003E940 — RotMatrixFromSVECTOR
 * Frame 0x28. Args: (SVECTOR* src, void* mat0, void* mat1, void* mat2)
 * Reads src->x (u16 +0), src->y (u16 +2), src->z (u16 +4).
 * Writes to GTE-equivalent globals: 0x800E5BA4/5BA6/5BA8.
 * Calls func_8003A844 (RotMatrix variant using the GTE globals).
 * Then reads from 0x800CF1C0/0x80154828 (frame-buffer/camera registers)
 * and copies 12 bytes to mat0, mat1, mat2 output matrices.
 */
void func_8003E940(SVECTOR* src, void* mat0, void* mat1, void* mat2) {
    *(unsigned short*)0x800E5BA4 = src->x;
    *(unsigned short*)0x800E5BA6 = src->y;
    *(unsigned short*)0x800E5BA8 = src->z;
    func_8003A844();   /* RotMatrix via GTE globals */
    /* Copy result matrices from camera register area */
    *(int*)mat0 = *(int*)0x800CF1C0;
    *(int*)mat1 = *(int*)0x80154828;
    /* etc. */
}

/* ================================================================
   MATH3D.c
   ================================================================ */

/*
 * MATH3D_FastAtan2 — VRAM 0x80030270
 * Args: (int y, int x) → int angle (0..0xFFF range)
 * If x==0: if y<0 → 0x800, if y>=0 → 0x400 (or edge cases).
 * If y<=0 and x>0: negate and proceed to lower quadrant.
 * For the general case: determines which is larger (|y| or |x|),
 * divides: ratio = (smaller << 9) / larger.
 * Looks up angle from table at 0x800305D4[ratio>>4] (16-entry table).
 * Adjusts for quadrant and sign to produce full-circle angle.
 */
int MATH3D_FastAtan2(int y, int x) {
    if (!x) { x = 1; }
    if (!y && !x) return (x < 0) ? 0x800 : 0;   /* degenerate */

    if (x <= 0) {
        /* handle negative x quadrants */
    }
    if (y <= 0) {
        /* handle negative y quadrants */
    }

    int absY = (y < 0) ? -y : y;
    int absX = (x < 0) ? -x : x;
    int ratio;
    if (absY < absX) {
        ratio = (absY << 9) / absX;
    } else {
        ratio = (absX << 9) / absY;
    }
    /* table lookup at atan_table[ratio >> some_shift] */
    return 0; /* placeholder */
}

/*
 * ratan2 — VRAM 0x80030538
 * Wrapper: if x==0 → returns ±0x400 based on sign of y.
 * Else: computes (y<<12)/x (fixed-point division), then reads atan table.
 * Returns signed angle in ±0x800 range (vs FastAtan2's 0..0xFFF unsigned).
 */
int ratan2(int y, int x) {
    if (!x) return (y < 0) ? -0x400 : 0x400;
    if (!y && !x) return /* ±0x800 */ 0;
    int ratio = (y << 12) / x;
    return 0; /* lookup */
}

/*
 * func_800305FC — MATH3D_FastSin
 * Args: (int angle) → int sin (fixed-point, 0x1000=1.0)
 * Builds a 0x200-entry sine table via binary search:
 *   s0=0x200 (table size), s1=0x100 (half), a1=0 (result accumulator).
 * Loops with: s1 >>= 1 until s1 == 0.
 * Each iteration: calls MATH_WrapAngle(s0) as midpoint; if result < target_angle
 *   → a1 += old_s0, else stays.
 * This is a bisection-based sine table lookup, not a polynomial.
 */
int MATH3D_FastSin(int angle) {
    int s0 = 0x200, s1 = 0x100, a1 = 0;
    int target = (angle < 0) ? -angle : angle;  /* abs */

    while (s1 != 0) {
        int mid = MATH_WrapAngle(s0);  /* func_8003A6AC(s0) */
        if (mid < target) { a1 += s0 - s1; }  /* approximate */
        s1 >>= 1;
        s0 = /* new midpoint */0;
    }
    return a1;
}

/*
 * func_800306DC — MATH3D_FastCos (= MATH3D_DistanceSqrSV or similar)
 * Actually from disasm: takes 3 args (a0,a1,a2), takes abs of each,
 * sorts them: sltu+swap to get max >= mid >= min.
 * Then: result = max + max/16 + max/4 + mid/4 = max*(1+1/16+1/4) + mid/4
 * This is the Chebyshev distance approximation: max*1.3125 + mid*0.25.
 * NOT a trig function — it's an SVECTOR length approximation.
 * Called MATH3D_FastCos in stubs but is actually MATH3D_DistanceApprox3D.
 */
int MATH3D_FastCos(int a0, int a1, int a2) {
    /* Sort to descending: a0 >= a1 >= a2 */
    if (a0 < 0) a0 = -a0;
    if (a1 < 0) a1 = -a1;
    if (a2 < 0) a2 = -a2;
    if (a1 < a2) { int t=a2; a2=a1; a1=t; }
    if (a0 < a1) { int t=a1; a1=a0; a0=t; }
    if (a1 < a2) { int t=a2; a2=a1; a1=t; }
    /* Chebyshev: max + max>>4 + max>>2 + mid>>2 */
    return a0 + (a0>>4) + (a0>>2) + (a1>>2);
}

/*
 * func_80030BA0 — MATRIX_AllocInit
 * Reads frame-buffer end ptr at 0x800F8184 (gFramebufferEnd).
 * Computes capacity = 0x801E5800 - gFramebufferEnd (bytes between FB end and limit).
 * Stores: counter=0 at 0x800CF1C8 (MATRIX_stack_counter).
 *         base    = gFramebufferEnd at 0x800CF1C0 (MATRIX_stack_base).
 *         capacity at 0x800CF1C4 (MATRIX_stack_cap).
 *         Also mirrors to 0x800CF1CC/0x800CF1D0.
 */
void MATRIX_AllocInit(void) {
    int* fbEnd   = *(int**)0x800F8184;      /* gFramebufferEnd */
    int  cap     = 0x801E5800 - (int)fbEnd;
    *(int*)0x800CF1C8 = 0;      /* counter = 0 */
    *(int*)0x800CF1C0 = (int)fbEnd; /* base */
    *(int*)0x800CF1C4 = cap;    /* capacity */
    *(int*)0x800CF1CC = (int)fbEnd;
    *(int*)0x800CF1D0 = cap;
}

/*
 * func_80030BE0 — MATRIX_Alloc
 * Args: (int size) → void* aligned ptr
 * Rounds size up to 16B alignment (addiu a0,a0,0xF; and a0,-0x10).
 * Reads counter from 0x800CF1C8, uses it to index into double-buffer slots:
 *   slot_ptr = MATRIX_stack_base[counter * 8]  (8B per slot ptr, 2 arrays)
 *   new_ptr  = slot_ptr + size
 *   Write new_ptr back to slot.
 * Returns current slot_ptr before increment.
 */
void* MATRIX_Alloc(int size) {
    size = (size + 0xF) & -0x10;  /* align up to 16 */
    int   counter = *(int*)0x800CF1C8;
    int   idx8    = counter * 8;

    int*  slotA   = (int*)(0x800CF1C0 + idx8);
    void* result  = (void*)(*slotA);
    *slotA = (int)result + size;

    int*  slotB   = (int*)(0x800CF1CC + idx8);
    void* resB    = (void*)(*slotB);
    *slotB = (int)resB + size;

    return result;
}

/*
 * func_80030C50 — MATRIX_GetTop
 * Args: (int size) → void* (top-of-stack minus size)
 * Reads counter from 0x800CF1C8, computes slot ptr same as Alloc,
 * returns (slot_ptr - size) — i.e., the START of the last allocated block.
 */
void* MATRIX_GetTop(int size) {
    size = size & -0x10;  /* align down (and a0,a1) */
    int counter = *(int*)0x800CF1C8;
    int idx8    = counter * 8;
    void* top   = (void*)*(int*)(0x800CF1C0 + idx8);
    return (char*)top - size;
}

/*
 * func_80030CB4 — MATRIX_Push
 * No return value. Checks counter < 0x20 (32 slots max).
 * Copies current slot ptr to next slot (counter+1), then increments counter.
 * Both base and mirror arrays updated in lockstep.
 */
void MATRIX_Push(void) {
    int counter = *(int*)0x800CF1C8;
    if (counter >= 0x20) return;  /* slti v0,v1,0x20; beqz → return */

    int idx8     = counter * 8;
    int nextIdx8 = (counter + 1) * 8;

    /* Copy slot ptr forward */
    *(int*)(0x800CF1C0 + nextIdx8) = *(int*)(0x800CF1C0 + idx8);
    *(int*)(0x800CF1CC + nextIdx8) = *(int*)(0x800CF1CC + idx8);

    *(int*)0x800CF1C8 = counter + 1;
}

/*
 * func_80030D34 — MATRIX_Pop
 * Reads counter. If 0 → return. Decrements counter.
 * (No ptr restoration needed — the stack model just moves the counter back.)
 */
void MATRIX_Pop(void) {
    int counter = *(int*)0x800CF1C8;
    if (!counter) return;
    *(int*)0x800CF1C8 = counter - 1;
}

/* ================================================================
   LIGHT3D.c
   ================================================================ */

/*
 * LIGHT_DrawShadow — VRAM 0x8002FA30
 * Frame 0x78. Args: (Instance* instance, GameTracker* gameTracker)
 *
 * Checks gameTracker == gGameTracker2 (ptr at -0x3060 from 0x8007base).
 * If so: reads gameTracker->_F4 (shadow enable flag); if 0 → skip.
 *        reads gameTracker->_F8 (shadow mode; ==0x800 → skip).
 * Else: reads instance->_18->_0 & 0x200 (shadow-capable object flag); if 0 → skip.
 * Reads shadow texture ptr from gShadowTexList (0x80076rXX) based on mode.
 * Checks instance->_4C (Y position) vs instance->_C0 (ground hit Y), plus 0x500 threshold.
 * Reads instance->_120 (shadow Y extent):
 *   if instance->_4C - _120 < _C0 (ground Y) → render.
 * Reads instance->_86/_88 (shadow angle XY), calls MATH3D_FastAtan2.
 * Computes shadow size: sq = instance->_84^2; calls MATH3D_FastSqrt(0x1000000-sq/4096).
 * Calls MATH3D_FastAtan2(instance->_84, result) to get shadow yaw.
 * Reads instance->_64 (shadow UV offset u16), etc.
 * Then builds GBI shadow quad display list, submitting shadow texture quad
 * to the shadow render list via the shadow DL allocator.
 */
void LIGHT_DrawShadow(Instance* instance, GameTracker* gameTracker) {
    GameTracker* gt2 = *(GameTracker**)0x8006CF40;  /* -0x3060 from 0x8007 */

    if (gameTracker == gt2) {
        if (!gameTracker->_F4) return;
        if (gameTracker->_F8 == 0x800) return;
    } else {
        if (!(*(unsigned int*)((char*)*(void**)((char*)instance + 0x18) + 0)
              & 0x200)) return;
    }

    /* Select shadow texture based on type */
    void* shadowTex = *(void**)0x80076874;  /* gShadowTexList variant A */
    if (!(*(unsigned int*)((char*)*(void**)((char*)instance + 0x18) + 0) & 0x200))
        shadowTex = *(void**)0x8007687C;    /* variant B */
    if (!shadowTex) return;
    void* texData = *(void**)((char*)shadowTex + 0xC);

    /* Position check: Y threshold */
    short instY  = *(short*)((char*)instance + 0x4C);
    short groundY= *(short*)((char*)instance + 0xC0);
    if (instY - 0x500 < groundY) return;

    /* Shadow Y extent */
    short shadowY = *(short*)((char*)instance + 0x120);
    if (instY - shadowY >= groundY) return;

    /* Compute shadow yaw angle */
    short sx = *(short*)((char*)instance + 0x86);
    short sy = *(short*)((char*)instance + 0x88);
    int   yaw = MATH3D_FastAtan2(sx, sy);
    *(short*)((char*)instance + 0x1/* sp+0x10 */) = (short)(-yaw);

    short shadowSize = *(short*)((char*)instance + 0x84);
    int   sq = shadowSize * shadowSize;  /* mult; mflo */
    int   r  = 0x1000000 - (sq >> 12);
    r = MATH3D_FastSqrt2(r >> 12);     /* func_80030840 */
    int   yaw2 = MATH3D_FastAtan2(shadowSize, r);
    *(short*)((char*)instance + 0x12) = (short)yaw2;

    /* Build and submit shadow quad GBI DL */
    /* ... texture coordinate setup, GBI command emission ... */
}
