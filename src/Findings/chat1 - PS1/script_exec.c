/*
 * script_exec.c — ScriptExec bytecode interpreter
 * Gex 2: Enter the Gecko (SLUS-00598)
 *
 * Original function: 0x80024D30
 *
 * ScriptExec processes a stream of 32-bit-word-aligned opcode records.
 * Each record: [opcode_u32] [arg0_u32] ... [argN_u32]
 * Stride per record: (arg_count + 1) × 4 bytes.
 * Dispatch via g_OpcodeTable[opcode].fn(world_obj, script_ptr).
 *
 * Script source: embedded in INDEX (.meta) files at env-specific offsets.
 * Script format: [u32 max_ops][u32 opcode0][u32 arg0]...[u32 opcodeN]...
 *   The first word is the MAX_OPS counter; actual opcodes start 4 bytes in.
 *   streaming_buf[0] = pointer to this header word.
 *   ScriptExec is called as: ScriptExec(world, buf[0]+4, *buf[0], flags)
 *                                                  ^^^       ^^^
 *                                              script start  max_ops
 */

#include "../../include/gex2_types.h"
#include "../../include/gex2_globals.h"

/* -----------------------------------------------------------------------
 * ScriptExec — 0x80024D30
 *
 * Parameters (confirmed from Remote_tick / 0x80064A44 call site):
 *   world_obj  — pointer to current world/level object (a0)
 *   script_ptr — pointer to first opcode word in stream (a1 = buf[0]+4)
 *   max_ops    — maximum opcodes to execute before returning (a2 = *buf[0])
 *   flags      — execution flags (a3, observed as 0 at call site)
 *                flag bit0 = 1 → s2 = 1 (world-check control)
 *                flag != 0 → also branches at 0x80024D68 for extra check
 *
 * Returns: (not used at observed call site)
 *
 * Exit conditions:
 *   - max_ops counter reaches 0
 *   - handler fn returns 0
 *   - GameCtx[+0x4C94] & 0x40 set AND opcode word has bit31 set
 *     (confirmed by `bltz` guard at 0x80024DF4)
 * ----------------------------------------------------------------------- */
int ScriptExec(void *world_obj, u32 *script_ptr, u32 max_ops, u32 flags) {
    if (max_ops == 0) {
        return 0;
    }

    /*
     * flags semantics (confirmed from 0x80024D50..0x80024D68):
     *   flags == 1 → s2 = 1 (used to gate world-check path)
     *   flags != 0 → reads g_GameCtxPtr->some_field for additional check
     *   flags == 0 → skip both checks
     */
    int s2 = (flags == 1) ? 1 : 0;

    /* Extra check when flags != 0: read g_GameCtxPtr field at +0x10 offset
     * within some sub-struct. If that meets a condition, also set s2=1.
     * STUB: leave as 0 for now — flags is always 0 at the one observed call. */

    u32 *s0 = script_ptr;    /* current position in script stream */
    u32  a2 = max_ops;       /* remaining iterations */

    while (a2 > 0) {
        /* Read opcode word; clear bit31 for dispatch
         * (bit31 set = still dispatches to opcode 0 but may be skipped
         *  by the GameCtx[0x4C94] & 0x40 guard) */
        u32 opcode_word = *s0;
        u32 opcode = opcode_word & 0x7FFFFFFFu;

        /* Guard: GameCtx[+0x4C94] & 0x40  + bit31 of opcode → skip */
        if (opcode_word & 0x80000000u) {
            GameCtx *ctx = g_GameCtxPtr;
            /* 0x80024DE0: lw v0, 0x4c94(v0); andi v0, v0, 0x40 */
            /* STUB: access ctx->saved_bss_ptr, check bit6 */
            /* if (*(u32*)ctx->saved_bss_ptr & 0x40) goto advance; */
        }

        if (opcode >= 105) {
            /* Out-of-range opcode: advance past it and its args (0 args assumed)
             * Original probably just advances by 4. */
            s0++;
            a2--;
            continue;
        }

        const ScriptOpEntry *entry = &g_OpcodeTable[opcode];

        /* World-check gate (confirmed at 0x80024DA0..0x80024DBC):
         *   entry->arg_info hi16 = world_check flag
         *   if world_check && current_world != g_WorldPtr → skip */
        u32 world_check = entry->arg_info >> 16;
        if (world_check) {
            /* 0x80024DB0: lw v0, g_WorldPtr; beq s1, v0 → continue to call */
            if (s2 != 0 && world_obj != g_WorldPtr) {
                /* Skip this opcode: advance script pointer */
                goto advance;
            }
        }

        /* Call the opcode handler:
         *   fn(a0 = world_obj, a1 = s0 = current script_ptr)
         *   Handler accesses args via: arg = script_ptr[1], script_ptr[2], etc.
         * Return value: 0 → exit ScriptExec, non-zero → continue */
        int ret = entry->fn(world_obj, s0);
        if (ret == 0) {
            return 0;
        }

advance:
        /* Advance s0 past this record: (arg_count + 1) × 4 bytes */
        {
            u32 arg_count = entry->arg_info & 0xFFFFu;
            s0 += (arg_count + 1);
        }
        a2--;
    }

    return 1;
}

/* -----------------------------------------------------------------------
 * Opcode handler implementations
 * Call signatures: int handler(void *world_obj, u32 *script_ptr)
 *   script_ptr[0] = opcode word (already dispatched on, still accessible)
 *   script_ptr[1] = first arg (a POINTER in handlers that take object ptrs)
 *   Returns 0 to stop ScriptExec, non-zero to continue.
 * ----------------------------------------------------------------------- */

/* op00_hideObject — 0x80022A08
 *
 * arg (script_ptr[1]) is a POINTER to an entity struct.
 * Sets bit7 of entity_struct[+0x1C] (marks object as hidden).
 *
 * When called with null arg (0): reads from address 0x1C in PS1 RAM
 * (harmless no-op on original hardware; on PC needs null check).
 *
 * NOTE: NEVER returns 0 — always returns (flags | 0x80) which is ≥ 0x80.
 */
int op00_hideObject(void *world_obj, u32 *script_ptr) {
    void *entity = (void *)(uintptr_t)script_ptr[1];

    /* On PS1: no null check — reads from address 0x1C if entity == NULL.
     * On PC: add null guard to prevent crash. */
    if (entity == NULL) {
        /* Mimic PS1 behaviour: would OR into PS1 RAM[0x1C].
         * On PC: no-op but return non-zero to continue. */
        return 0x80;
    }

    /* entity_struct->flags (at +0x1C): set bit7 = "hidden" */
    u32 *flags_ptr = (u32 *)((u8 *)entity + 0x1C);
    u32 flags = *flags_ptr;
    flags |= 0x80u;
    *flags_ptr = flags;

    return (int)flags;   /* always non-zero due to 0x80 */
}

/* op01_unhideObject — 0x80022A28
 *
 * Symmetric to hideObject. Clears the hidden flag bit.
 * STUB: implemented by analogy; verify against actual disasm of 0x80022A28.
 */
int op01_unhideObject(void *world_obj, u32 *script_ptr) {
    void *entity = (void *)(uintptr_t)script_ptr[1];
    if (entity == NULL) {
        return 1;
    }
    u32 *flags_ptr = (u32 *)((u8 *)entity + 0x1C);
    *flags_ptr &= ~0x80u;
    return 1;
}

/* op91_birthObject — 0x8002349C
 *
 * arg = entity descriptor POINTER.
 * Spawns the game object if not already spawned.
 * Confirmed from disasm:
 *   a0 = script_ptr[+4] (the arg)
 *   if a0 == 0: skip (return 1)
 *   if a0[+0x1C] & 0x08: skip (already spawned bit)
 *   jal Object_birth(a0)
 *   return 1 always
 */
int op91_birthObject(void *world_obj, u32 *script_ptr) {
    EntityDesc *entity = (EntityDesc *)(uintptr_t)script_ptr[1];

    if (entity == NULL) {
        return 1;
    }

    /* Check "already spawned" bit (bit3 of flags at +0x1C) */
    if (entity->flags & 0x08u) {
        return 1;
    }

    /* Spawn the object */
    extern void Object_birth(EntityDesc *entity);
    Object_birth(entity);

    return 1;
}

/* op95_hubWorldInit — 0x800247B4
 *
 * World-specific hub initialisation (world_check=1 means only fires in hub).
 * Calls HubWorld_init (0x80053D48) and returns 1.
 */
int op95_hubWorldInit(void *world_obj, u32 *script_ptr) {
    extern void HubWorld_init(void);
    HubWorld_init();
    return 1;
}

/* op72_levelChange — 0x80023EF8   (1 arg, world_check=1)   STUB */
int op72_levelChange(void *world_obj, u32 *script_ptr) {
    /* STUB */ return 1;
}

/* op76_hideObjectGroup — 0x80023F18  (1 arg, world_check=1)  STUB */
int op76_hideObjectGroup(void *world_obj, u32 *script_ptr) {
    /* STUB */ return 1;
}

/* op81_voiceQueue — 0x800246E4  (1 arg, world_check=1)  STUB */
int op81_voiceQueue(void *world_obj, u32 *script_ptr) {
    /* STUB */ return 1;
}

/* op62_stopPlayerCtrl — 0x80023AA0  (0 args, world_check=1)  STUB */
int op62_stopPlayerCtrl(void *world_obj, u32 *script_ptr) {
    /* STUB */ return 1;
}

/* op23_teleport — 0x80022E7C  (4 args, world_check=1)  STUB */
int op23_teleport(void *world_obj, u32 *script_ptr) {
    /* STUB */ return 1;
}

/* Remaining 96 opcode handlers — STUB */
int op_stub(void *world_obj, u32 *script_ptr) {
    /* STUB: handler not yet decompiled */
    return 1;
}

/* -----------------------------------------------------------------------
 * g_OpcodeTable initialisation
 * Matches original 0x80085C00 layout: {data_ptr, fn, arg_info}
 * Only the confirmed entries are populated; rest use op_stub.
 * ----------------------------------------------------------------------- */
ScriptOpEntry g_OpcodeTable[105] = {
    /* [  0] hideObject       */ { 0, op00_hideObject,    0x00000001 },
    /* [  1] unhideObject     */ { 0, op01_unhideObject,  0x00000001 },
    /* [  2] STUB             */ { 0, op_stub,            0x00000001 },
    /* [  3] STUB             */ { 0, op_stub,            0x00000001 },
    /* ...entries 4-22 STUB... */
    /* [  4] */ { 0, op_stub, 0x00000001 },
    /* [  5] */ { 0, op_stub, 0x00000001 },
    /* [  6] */ { 0, op_stub, 0x00000001 },
    /* [  7] */ { 0, op_stub, 0x00000001 },
    /* [  8] */ { 0, op_stub, 0x00000001 },
    /* [  9] */ { 0, op_stub, 0x00000001 },
    /* [ 10] */ { 0, op_stub, 0x00000001 },
    /* [ 11] */ { 0, op_stub, 0x00000001 },
    /* [ 12] */ { 0, op_stub, 0x00000001 },
    /* [ 13] */ { 0, op_stub, 0x00010001 }, /* camera_A */
    /* [ 14] */ { 0, op_stub, 0x00010001 }, /* camera_B */
    /* [ 15] */ { 0, op_stub, 0x00010001 }, /* camera_C */
    /* [ 16] */ { 0, op_stub, 0x00010001 }, /* camera_D */
    /* [ 17] */ { 0, op_stub, 0x00010001 }, /* camera_E */
    /* [ 18] */ { 0, op_stub, 0x00010001 }, /* camera_F */
    /* [ 19] */ { 0, op_stub, 0x00010001 }, /* camera_G */
    /* [ 20] */ { 0, op_stub, 0x00010001 }, /* camera_H */
    /* [ 21] */ { 0, op_stub, 0x00010001 }, /* camera_I */
    /* [ 22] */ { 0, op_stub, 0x00010001 }, /* camera_J */
    /* [ 23] teleport         */ { 0, op23_teleport,       0x00010004 },
    /* [ 24] */ { 0, op_stub, 0x00000001 },
    /* [ 25] */ { 0, op_stub, 0x00010001 }, /* sfxA */
    /* [ 26] */ { 0, op_stub, 0x00010001 }, /* sfxB */
    /* [ 27] */ { 0, op_stub, 0x00010001 }, /* sfxC */
    /* [ 28] */ { 0, op_stub, 0x00010001 }, /* sfxD */
    /* [ 29] */ { 0, op_stub, 0x00010001 }, /* sfxE */
    /* [ 30] */ { 0, op_stub, 0x00010001 }, /* sfxF */
    /* [ 31] */ { 0, op_stub, 0x00000001 },
    /* [ 32] freeze           */ { 0, op_stub,            0x00010000 },
    /* [ 33] */ { 0, op_stub, 0x00000001 },
    /* [ 34] freezeAll        */ { 0, op_stub,            0x00010000 },
    /* entries 35-61 STUB */
    /* [ 35] */ { 0, op_stub, 0x00000001 },
    /* [ 36] */ { 0, op_stub, 0x00000001 },
    /* [ 37] */ { 0, op_stub, 0x00000001 },
    /* [ 38] */ { 0, op_stub, 0x00000001 },
    /* [ 39] */ { 0, op_stub, 0x00000001 },
    /* [ 40] */ { 0, op_stub, 0x00000001 },
    /* [ 41] */ { 0, op_stub, 0x00000001 },
    /* [ 42] */ { 0, op_stub, 0x00000001 },
    /* [ 43] */ { 0, op_stub, 0x00000001 },
    /* [ 44] */ { 0, op_stub, 0x00000001 },
    /* [ 45] */ { 0, op_stub, 0x00000001 },
    /* [ 46] */ { 0, op_stub, 0x00000001 },
    /* [ 47] */ { 0, op_stub, 0x00000001 },
    /* [ 48] */ { 0, op_stub, 0x00000001 },
    /* [ 49] */ { 0, op_stub, 0x00000001 },
    /* [ 50] */ { 0, op_stub, 0x00000001 },
    /* [ 51] */ { 0, op_stub, 0x00000001 },
    /* [ 52] */ { 0, op_stub, 0x00000001 },
    /* [ 53] */ { 0, op_stub, 0x00000001 },
    /* [ 54] */ { 0, op_stub, 0x00000001 },
    /* [ 55] */ { 0, op_stub, 0x00000001 },
    /* [ 56] */ { 0, op_stub, 0x00000001 },
    /* [ 57] */ { 0, op_stub, 0x00000001 },
    /* [ 58] */ { 0, op_stub, 0x00000001 },
    /* [ 59] */ { 0, op_stub, 0x00000001 },
    /* [ 60] */ { 0, op_stub, 0x00000001 },
    /* [ 61] */ { 0, op_stub, 0x00000001 },
    /* [ 62] stopPlayerCtrl   */ { 0, op62_stopPlayerCtrl, 0x00010000 },
    /* entries 63-71 STUB */
    /* [ 63] */ { 0, op_stub, 0x00010000 },
    /* [ 64] */ { 0, op_stub, 0x00000001 },
    /* [ 65] */ { 0, op_stub, 0x00000001 },
    /* [ 66] */ { 0, op_stub, 0x00000001 },
    /* [ 67] */ { 0, op_stub, 0x00000001 },
    /* [ 68] */ { 0, op_stub, 0x00000001 },
    /* [ 69] */ { 0, op_stub, 0x00000001 },
    /* [ 70] */ { 0, op_stub, 0x00000001 },
    /* [ 71] */ { 0, op_stub, 0x00000001 },
    /* [ 72] levelChange      */ { 0, op72_levelChange,   0x00010001 },
    /* entries 73-75 STUB */
    /* [ 73] */ { 0, op_stub, 0x00010001 },
    /* [ 74] */ { 0, op_stub, 0x00010001 },
    /* [ 75] */ { 0, op_stub, 0x00010001 },
    /* [ 76] hideObjectGroup  */ { 0, op76_hideObjectGroup, 0x00010001 },
    /* entries 77-80 STUB */
    /* [ 77] */ { 0, op_stub, 0x00010001 },
    /* [ 78] */ { 0, op_stub, 0x00010001 },
    /* [ 79] */ { 0, op_stub, 0x00010001 },
    /* [ 80] */ { 0, op_stub, 0x00010001 },
    /* [ 81] voiceQueue       */ { 0, op81_voiceQueue,    0x00010001 },
    /* entries 82-90 STUB */
    /* [ 82] */ { 0, op_stub, 0x00010001 },
    /* [ 83] */ { 0, op_stub, 0x00010001 },
    /* [ 84] */ { 0, op_stub, 0x00010001 },
    /* [ 85] */ { 0, op_stub, 0x00010001 },
    /* [ 86] */ { 0, op_stub, 0x00010001 },
    /* [ 87] */ { 0, op_stub, 0x00010001 },
    /* [ 88] */ { 0, op_stub, 0x00010001 },
    /* [ 89] */ { 0, op_stub, 0x00010001 },
    /* [ 90] */ { 0, op_stub, 0x00010001 },
    /* [ 91] birthObject      */ { 0, op91_birthObject,   0x00010001 },
    /* entries 92-94 STUB */
    /* [ 92] */ { 0, op_stub, 0x00010001 },
    /* [ 93] */ { 0, op_stub, 0x00010001 },
    /* [ 94] */ { 0, op_stub, 0x00010001 },
    /* [ 95] hubWorldInit     */ { 0, op95_hubWorldInit,  0x00010000 },
    /* entries 96-104 STUB */
    /* [ 96] */ { 0, op_stub, 0x00010001 },
    /* [ 97] */ { 0, op_stub, 0x00010001 },
    /* [ 98] */ { 0, op_stub, 0x00010001 },
    /* [ 99] */ { 0, op_stub, 0x00010001 },
    /* [100] */ { 0, op_stub, 0x00010001 },
    /* [101] */ { 0, op_stub, 0x00010001 },
    /* [102] */ { 0, op_stub, 0x00010001 },
    /* [103] */ { 0, op_stub, 0x00010001 },
    /* [104] */ { 0, op_stub, 0x00010001 },
};
