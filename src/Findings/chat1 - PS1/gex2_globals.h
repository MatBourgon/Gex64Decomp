#ifndef GEX2_GLOBALS_H
#define GEX2_GLOBALS_H

/*
 * gex2_globals.h — Gex 2 SLUS-00598 confirmed BSS/DATA globals
 * Original addresses noted for cross-reference during decompilation.
 * On PC these become ordinary C globals (no fixed addresses).
 */

#include "gex2_types.h"

/* -----------------------------------------------------------------------
 * Core game state
 * ----------------------------------------------------------------------- */

/* 0x80086EA8 — pointer to the heap-allocated GameCtx struct */
extern GameCtx *g_GameCtxPtr;

/* 0x80085270 — pointer to the current world/level object */
extern void    *g_WorldPtr;

/* -----------------------------------------------------------------------
 * BIGFILE / streaming table
 * ----------------------------------------------------------------------- */

/* 0x8008E65C — number of entries in g_StreamSlotTable (= 192 at boot) */
extern u32              g_StreamSlotCount;

/* 0x8008E664 — array of 192 × 24-byte TOC entries (populated at boot) */
extern BigFileTocEntry  g_StreamSlotTable[192];

/* 0x8008E618 — pointer to current active CD read slot */
extern CdReadSlot      *g_CD_statePtr;

/* 0x8008FF68 — 4-slot circular CD read ring (36 bytes per slot) */
extern CdReadSlot       g_CD_readSlots[4];

/* 0x8008A268 — StreamQueue base (6-byte entries) */
extern u8               g_StreamQueue[/* dynamic size */1];

/* 0x8008A888 — count of pending StreamQueue entries */
extern u32              g_StreamCounter;

/* 0x9009D6AC — streaming semaphore; Level_streamLoad polls until 0 */
extern volatile u32     g_StreamSemaphore;

/* 0x80086750 — base address of currently-loaded geometry block */
extern void            *g_geomLoadedBase;

/* -----------------------------------------------------------------------
 * Remote table — streaming buffer pointers per remote (TV channel)
 * 0x8008AAE8: g_RemoteTable[0] = 0x801F4000, [1] = 0x801EC000, etc.
 * On PC these become malloc'd buffers.
 * ----------------------------------------------------------------------- */
extern void *g_RemoteTable[4];    /* original PS1: pointers into PS1 RAM */

/* -----------------------------------------------------------------------
 * Remote state & level data tables
 * ----------------------------------------------------------------------- */

/* 0x8008E59C — 26 × 36-byte remote state entries */
extern RemoteStateEntry g_RemoteStateTable[26];

/* 0x8008B460 — rendering draw-environment table (92 bytes × remote_id) */
extern u8 g_RenderTable[192 * 92];   /* [ESTIMATE] actual stride TBD */

/* 0x8007B204 — 92-byte entries per remote: level music/streaming resources */
extern u8 g_RemoteLevelTable[/* 26+ entries × 92B */1];

/* 0x8007C2E8 — pointer table indexed by remote_id (5 ptrs × 4B each) */
extern void *g_RemoteResourceTable[/* 26+ */1];

/* -----------------------------------------------------------------------
 * ScriptExec opcode dispatch table  (0x80085C00, 105 × 12 bytes)
 * ----------------------------------------------------------------------- */
extern ScriptOpEntry g_OpcodeTable[105];

/* -----------------------------------------------------------------------
 * Camera globals
 * ----------------------------------------------------------------------- */

/* 0x800893B0 — global camera behaviour dispatch table */
extern void *g_CameraBehaviorTable;

/* 0x80086748 — saved camera event */
extern u32   g_CameraEventStore;

/* -----------------------------------------------------------------------
 * Audio globals
 * ----------------------------------------------------------------------- */

/* 0x8007E634 — audio object table (8 entries per SPU channel group) */
extern void *g_AudioObjectTable[/* N */1];

/* -----------------------------------------------------------------------
 * Streaming configuration strings (in original exe data segment)
 * On PC these become const char* in a .c file.
 * ----------------------------------------------------------------------- */

/* 0x80086E34 — "$#2\n\n\n GAME OVER"   streaming config for game-over screen */
extern const char g_StreamConfig_GameOver[];

/* 0x80086E48 — "$#2\n\n\n LOADING...\n" streaming config for loading screen */
extern const char g_StreamConfig_Loading[];

/* 0x8007BFE6 — "@\nY\nj\ns\n" sector-read config */
extern const char g_StreamConfig_SectorA[];

/* -----------------------------------------------------------------------
 * Object pool globals
 * ----------------------------------------------------------------------- */

/* 0x8009FEE0 — 32-slot game-object pool (12 bytes × 32 × 2 = 768B) */
extern u8 g_ObjectPoolA[32 * 12];
extern u8 g_ObjectPoolB[32 * 12];

/* 0x8009FEC8 — pool capacity constant (0x1C2 = 450) */
extern u32 g_ObjectPoolCapacity;

/* 0x8009D6AC — streaming semaphore (also used by Level_streamLoad poll) */
/* Already declared above as g_StreamSemaphore */

/* 0x8009D6AA — some byte flag for streaming system */
extern u8  g_StreamFlag;

#endif /* GEX2_GLOBALS_H */
