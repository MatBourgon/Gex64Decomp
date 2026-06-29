#ifndef GEX2_TYPES_H
#define GEX2_TYPES_H

/*
 * gex2_types.h — Gex 2: Enter the Gecko (SLUS-00598)
 * Core type definitions and struct layouts.
 * Field offsets confirmed via disassembly unless marked [ESTIMATE].
 */

#include <stdint.h>
#include <stddef.h>

/* -----------------------------------------------------------------------
 * PS1 primitive integer types
 * ----------------------------------------------------------------------- */
typedef int8_t   s8;
typedef uint8_t  u8;
typedef int16_t  s16;
typedef uint16_t u16;
typedef int32_t  s32;
typedef uint32_t u32;

/* Fixed-point: Q12.4 (most GTE outputs) */
typedef s16  fixed12_t;
/* Fixed-point: Q0.16 (timing fractions) */
typedef u16  ufrac16_t;

/* -----------------------------------------------------------------------
 * Forward declarations
 * ----------------------------------------------------------------------- */
typedef struct GameCtx        GameCtx;
typedef struct EntityDesc     EntityDesc;
typedef struct ObjectClass    ObjectClass;
typedef struct GameObject     GameObject;
typedef struct ObjectPool     ObjectPool;
typedef struct CameraObj      CameraObj;
typedef struct CameraCtrl     CameraCtrl;
typedef struct CameraNode32   CameraNode32;
typedef struct CameraNode10   CameraNode10;
typedef struct BigFileTocEntry BigFileTocEntry;
typedef struct ScriptOpEntry  ScriptOpEntry;

/* -----------------------------------------------------------------------
 * BIGFILE.DAT TOC entry (24 bytes, confirmed from boot initialiser decode)
 * -----------------------------------------------------------------------
 *  Offset  Size  Description
 *  +0x00   4     name_hash — BigFile_hashName() result; lookup key
 *  +0x04   4     primary_stream_size  — bytes in first CD read
 *  +0x08   4     secondary_stream_size — bytes in second CD read
 *  +0x0C   4     bf_byte_offset — byte position within BIGFILE.DAT
 *  +0x10   4     checksum_A — content integrity check (algorithm unknown)
 *  +0x14   4     checksum_B — first 4 content bytes as LE u32 (for small
 *                             global files only; other files: content hash)
 * ----------------------------------------------------------------------- */
struct BigFileTocEntry {     /* total: 24 bytes */
    u32 name_hash;           /* +0x00 */
    u32 primary_size;        /* +0x04 */
    u32 secondary_size;      /* +0x08 */
    u32 bf_byte_offset;      /* +0x0C */
    u32 checksum_A;          /* +0x10 */
    u32 checksum_B;          /* +0x14 */
};

/* -----------------------------------------------------------------------
 * ScriptExec opcode table entry (12 bytes at 0x80085C00, 105 entries)
 * ----------------------------------------------------------------------- */
typedef int (*ScriptHandler)(void *world_obj, u32 *script_ptr);

struct ScriptOpEntry {       /* total: 12 bytes */
    u32          data_ptr;   /* +0x00  — misc data/name pointer */
    ScriptHandler fn;        /* +0x04  — handler called by ScriptExec */
    u32          arg_info;   /* +0x08  — lo16=arg_count, hi16=world_check */
};

/* -----------------------------------------------------------------------
 * GameObject (object instance, allocated from pool)
 * Known field offsets from Object_birth / Object_initFromClass disasm.
 * ----------------------------------------------------------------------- */
struct GameObject {          /* size: at least 0x120 bytes */
    /* +0x00..+0x0F  — header / identity */
    u32  unk00;              /* +0x00 */
    u32  unk04;              /* +0x04 */
    u32  unk08;              /* +0x08 */
    u32  unk0C;              /* +0x0C */
    /* +0x10 object flags */
    u32  flags;              /* +0x10 */
    u32  flags2;             /* +0x14 */
    /* +0x18 class data pointer (to the A8AA class definition) */
    void *class_ptr;         /* +0x18  — set by Object_initFromClass */
    /* +0x1C pointer back to entity descriptor */
    void *entity_desc;       /* +0x1C  — set by Object_birth */
    /* +0x20 */
    void *unk20;             /* +0x20 */
    /* +0x24 */
    u32  unk24;              /* +0x24 */
    /* Zeroed region: 0x10..0x124 (0x114 bytes via memset in initFromClass) */
    /* +0x48..+0x4E  initial XYZ position (int16 × 3) */
    s16  pos_init_x;         /* +0x48 */
    s16  pos_init_y;         /* +0x4A */
    s16  pos_init_z;         /* +0x4C */
    u8   unk4E;              /* +0x4E */
    u8   entity_byte;        /* +0x4F  — copied from entity_desc[+0x0E] lo byte */
    /* +0x50..+0x55  second XYZ copy */
    s16  pos_b_x;            /* +0x50 */
    s16  pos_b_y;            /* +0x52 */
    s16  pos_b_z;            /* +0x54 */
    /* +0x58..+0x5E  third XYZ copy */
    s16  pos_c_x;            /* +0x58 */
    s16  pos_c_y;            /* +0x5A */
    s16  pos_c_z;            /* +0x5C */
    /* +0x68  scale (int16 × 3, initialised to 0x1000) */
    s16  scale_x;            /* +0x68 */
    s16  scale_y;            /* +0x6A */
    s16  scale_z;            /* +0x6C */
    /* ... remaining fields unknown */
};

/* -----------------------------------------------------------------------
 * EntityDesc — per-spawn descriptor (passed to Object_birth)
 * ----------------------------------------------------------------------- */
struct EntityDesc {          /* size: at least 0x28 bytes */
    void *class_ptr;         /* +0x00  — pointer to A8AA class definition */
    u32  unk04;              /* +0x04 */
    u32  unk08;              /* +0x08 */
    u32  unk0C;              /* +0x0C */
    u16  entity_id;          /* +0x0E */
    /* +0x10..+0x15  initial position (int16 × 3, loaded via lwl/lwr) */
    s16  pos_x;              /* +0x10 */
    s16  pos_y;              /* +0x12 */
    s16  pos_z;              /* +0x14 */
    u16  unk16;              /* +0x16 */
    u32  unk18;              /* +0x18 */
    u32  flags;              /* +0x1C  — bit8 = already-spawned guard */
    void *init_data;         /* +0x20 */
    void *instance;          /* +0x24  — OUTPUT: filled by Object_birth */
};

/* -----------------------------------------------------------------------
 * ObjectPool — free-list pool
 * Accessed by Object_alloc / Object_birth
 * ----------------------------------------------------------------------- */
struct ObjectPool {
    u32    count;            /* +0x00  — total slots */
    void  *free_head;        /* +0x04  — head of free list */
    /* ... */
};

/* -----------------------------------------------------------------------
 * CameraNode32 — full cubic hermite spline node (32 bytes, mode B)
 * Confirmed from Camera_applyNodeB (0x8005D7C8) disassembly.
 * Two adjacent nodes A and B are blended by the camera spline system.
 * ----------------------------------------------------------------------- */
struct CameraNode32 {        /* total: 32 bytes */
    s16  flags;              /* +0x00  — node flags / type */
    s16  pos_x;              /* +0x02  — world X position */
    s16  pos_y;              /* +0x04  — world Y position */
    s16  pos_z;              /* +0x06  — world Z position */
    s32  tangent_x;          /* +0x08  — start tangent X (from node A) */
    s32  tangent_y;          /* +0x0C  — start tangent Y */
    s32  tangent_z;          /* +0x10  — start tangent Z */
    s32  end_tangent_x;      /* +0x14  — end tangent X (from node B's persp) */
    s32  end_tangent_y;      /* +0x18  */
    s32  end_tangent_z;      /* +0x1C  */
};                           /* 2+2+2+2+4+4+4+4+4+4 = 32 bytes ✓ */

/* -----------------------------------------------------------------------
 * CameraNode10 — compact node (10 bytes, mode A)
 * Used for simpler camera behaviours.
 * ----------------------------------------------------------------------- */
struct CameraNode10 {        /* total: 10 bytes */
    s16  id_flags;           /* +0x00 */
    s16  val1;               /* +0x02 */
    s16  val2;               /* +0x04 */
    s16  val3;               /* +0x06 */
    s16  val4;               /* +0x08 */
};

/* -----------------------------------------------------------------------
 * CameraCtrl — control struct threaded through camera behaviour traversal
 * ----------------------------------------------------------------------- */
struct CameraCtrl {
    s16  current_index;      /* +0x00  — current node index (signed) */
    u16  state_flags;        /* +0x02  — bit0 = some mode flag */
    /* ... */
};

/* -----------------------------------------------------------------------
 * CameraObj — runtime camera behaviour object
 * Confirmed offsets from Camera_behaviorTraverse (0x8005E754) disasm.
 * ----------------------------------------------------------------------- */
struct CameraObj {
    void  *node_base;        /* +0x00  — pointer to node array in RAM */
    u32    unk04;            /* +0x04  — padding / alignment */
    s16    max_count;        /* +0x04 (alt layout) — total node count */
    s16    pad06;            /* +0x06 */
    u8     mode;             /* +0x06 (alt)  0=mode_B(32B/node) 1=mode_A(10B) */
    /* ... large struct, many more fields ... */
    /* Confirmed offsets from Camera_update (0x80011C8C): */
    u16    type_flags;       /* +0x120 */
    u16    node_count;       /* +0x122 */
    u16    primary_param;    /* +0x124 */
    u16    pad126;           /* +0x126 */
    u16    range_limit_A;    /* +0x128 */
    u16    range_limit_B;    /* +0x12A */
    u16    range_limit_C;    /* +0x12C */
    /* ... */
    void  *behavior_data;    /* +0x148  — pointer to camera config file */
    s16    camera_state;     /* +0x14C  — current state (0,2,5,6,C,D,F) */
    s16    next_state;       /* +0x150 */
    /* ... */
    /* Confirmed offsets from Camera_stateMachine (0x80015728): */
    s16    field_3B6;        /* +0x3B6 */
    u16    type_flags_copy;  /* +0x3B8 */
    u16    count_copy;       /* +0x3BA */
    u16    field_3BC;        /* +0x3BC */
    u16    clamped_val;      /* +0x3BE  — max(buf[4], buf[0x14]) */
    /* ... */
    s32    frame_counter;    /* +0x43C */
    void  *sub_obj_A;        /* +0x480 */
    void  *sub_obj_B;        /* +0x484 */
    /* ... */
    u8     mode_byte;        /* +0x4DEE — dispatched on by Camera_update */
    /* ... */
};

/* -----------------------------------------------------------------------
 * GameCtx — main game context struct (at *g_GameCtxPtr = 0x80086EA8)
 * Confirmed field offsets from Level_remoteInit, Remote_tick, etc.
 * ----------------------------------------------------------------------- */
struct GameCtx {
    /* +0x000..+0x007  — header */
    u32   magic;             /* +0x000  [ESTIMATE] */
    void *render_ctx;        /* +0x008  — rendering sub-struct */
    void *world_ptr;         /* +0x00C  — g_WorldPtr copy */
    u32   double_buf_select; /* +0x010  — 0 or 1, toggles each frame */
    u32   remote_id;         /* +0x014  — current level/remote number */
    u32   unk018;            /* +0x018 */
    u32   unk01C;            /* +0x01C */
    void *stream_buf;        /* +0x024  — streaming buffer ptr (g_RemoteTable[id]) */
    u32   stream_flags;      /* +0x02C  — bit0, bit1 streaming conditions */
    /* ... */
    void *stream_A_handle;   /* +0x0F4 */
    void *stream_B_handle;   /* +0x0F8 */
    u32   load_phase;        /* +0x104  — Level_remoteInit phase counter */
    /* ... */
    void *stream_A_base;     /* +0x4C24 — stream handle A base */
    u32   level_res_ptr;     /* +0x4C80 — active remote_id for resource lookup */
    void *saved_bss_ptr;     /* +0x4C94 */
    /* ... */
    u8    remote_state[26];  /* +0x6ECC — per-remote state bytes */
    u8    _pad6EE6[10];
    u32   remote_completion; /* +0x6EF4 — SAVE: bitN=1 means remote N beaten */
    u8    active_remote;     /* +0x6EFD — 0xFF=hub/none, 0-25=valid */
    u8    level_type;        /* +0x6EFE — 0x1E=hub/boss/special, else normal */
    /* ... */
    void *level_data_ptr;    /* +0x6F08 — per-remote BSS block ptr */
    u32   load_state;        /* +0x6F3C — 0=idle, -1=active, >0=frame count */
    /* ... */
    u32   countdown_timer;   /* +0x6F18 — 0x2710=10000 */
    u16   unk7008;           /* +0x7008 — 10 */
};

/* -----------------------------------------------------------------------
 * Remote state table entry (36 bytes each, 26 entries at 0x8008E59C)
 * ----------------------------------------------------------------------- */
typedef struct RemoteStateEntry {
    u8   data[36];           /* layout within TBD */
} RemoteStateEntry;

/* -----------------------------------------------------------------------
 * CD streaming ring slot (36 bytes each, 4 slots at 0x8008FF68)
 * ----------------------------------------------------------------------- */
typedef struct CdReadSlot {
    u32  field_00;           /* +0x00 */
    void *buf_ptr;           /* +0x04 — destination buffer */
    void *base_ptr;          /* +0x08 — base pointer */
    u32  lba_start;          /* +0x0C — starting LBA */
    u32  sector_count;       /* +0x10 — sectors to read */
    u32  status;             /* +0x14 — 0=free, 1=active */
    u32  checksum_data;      /* +0x18 — BigFile TOC w[4] (integrity check) */
    u32  sec_size;           /* +0x1C — secondary size in bytes */
    u32  field_20;           /* +0x20 */
} CdReadSlot;

/* -----------------------------------------------------------------------
 * Stream slot table entry (at g_StreamSlotTable = 0x8008E664)
 * Populated from BIGFILE TOC at boot; 24 bytes × 192 entries.
 * ----------------------------------------------------------------------- */
/* BigFileTocEntry defined above */

/* -----------------------------------------------------------------------
 * Camera config file header (entries 8-11 in BIGFILE)
 * ----------------------------------------------------------------------- */
typedef struct CamConfigHeader {
    u16  type_flags;         /* +0x00  always 0x0000 */
    u16  node_count;         /* +0x02  number of spline nodes */
    s16  primary_param;      /* +0x04  0xFFFF = unlimited */
    /* data continues at +0x06... */
    s16  clamp_value;        /* +0x14 */
    /* fixed-offset params: */
    s16  range_limit_A;      /* +0x30 */
    s16  range_limit_B;      /* +0x32 */
    s16  range_limit_C;      /* +0x34 */
    /* node data (variable-length delta/keyframe stream) follows */
} CamConfigHeader;

/* -----------------------------------------------------------------------
 * INDEX file (.meta) ScriptExec buffer header
 * Located at environment-specific offsets within each INDEX file.
 * ----------------------------------------------------------------------- */
typedef struct ScriptBufHeader {
    u32  max_ops;            /* +0x00  max ScriptExec iterations (0=disabled) */
    u32  opcodes[1];         /* +0x04  variable-length 32-bit word stream */
} ScriptBufHeader;

#endif /* GEX2_TYPES_H */
