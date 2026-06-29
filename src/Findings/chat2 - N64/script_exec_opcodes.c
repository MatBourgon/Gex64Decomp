/*
 * Gex 64 – ScriptExec Opcode Table
 * Reverse-engineered from ROM+0x06DEC0 dispatch table
 * RDRAM mapping: rdram_addr - 0x80000000 = rom_offset
 *
 * The dispatch table has 18 entries × 8B each:
 *   [exec_fn:u32][init_fn:u32]
 * Entry 18 = {0x00000000, 0x8015E038}  (null = end)
 * Entry 19 = {0xFFFFFFFF, 0x00000000}  (sentinel)
 *
 * Calling convention: all handlers receive (s0, s1, s2, s3)
 *   s0 = ScriptState*  (script execution state)
 *   s1 = Entity*       (entity/actor that owns this script)
 *   s2 = World*        (level/world context)
 *   s3 = extra arg / entity descriptor
 */

#include "gex2_types.h"

/* ------------------------------------------------------------------ */
/* ScriptState struct layout (confirmed from disassembly)              */
/* ------------------------------------------------------------------ */
typedef struct ScriptState {
    /* +0  */ u32  type_tag;       /* magic; compared against global registry entries  */
    /* +4  */ u8   pad0[12];
    /* +16 */ u32  state_a;
    /* +20 */ u32  pc;             /* instruction / data pointer; updated by DISPATCH   */
    /* +24 */ void *parent_ptr;    /* → entity/object that owns this script             */
    /* +28 */ u8   pad1[48];
    /* +76 */ u16  entity_subtype; /* copied to *entity+8 at offset 322 in op01        */
    /* +78 */ u8   opcode;         /* current script opcode; ×4 = parent vtable index  */
    /* +79 */ u8   pad2;
    /* +80 */ u8   pad3[14];
    /* +94 */ u16  tick_counter;   /* decremented in WAIT / DISPATCH; triggers callback when <0 */
    /* +96 */ u8   pad4[120];
    /* +216*/ s32  timer;          /* negative → fire callback; <32 used for WAIT_FRAME */
    /* +220*/ u8   pad5[28];
    /* +248*/ u32  flags;          /* 0x00268088 = active; 0x72018000 = render; 0x8000 = link */
    /* +252*/ u32  extra_flags;
} ScriptState;

/* ------------------------------------------------------------------ */
/* Entity struct (partial, from field accesses in handlers)            */
/* ------------------------------------------------------------------ */
typedef struct Entity {
    /* +0  */ u8   pad0[8];
    /* +8  */ void *sub_struct;    /* → struct with field 322 (written entity_subtype) */
    /* +10 */ u8   pad1[22];
    /* +32 */ s16  counter;        /* used in op06: check entity limit                 */
    /* +34 */ u8   pad2[104];
    /* +138*/ u16  entity_flags;   /* bit 0 = update_active; bit 1 = alloc_done       */
    /* +140*/ u8   pad3[16];
    /* +156*/ s16  entity_limit;   /* compared against counter in op06                 */
    /* +158*/ u8   pad4[...];
    /* +128*/ u16  some_id;        /* written in op06                                  */
} Entity;

/* ------------------------------------------------------------------ */
/* Core subsystem functions (identified from handler call sites)       */
/* ------------------------------------------------------------------ */
extern void ScriptState_Setup(ScriptState *s, void *world, Entity *e, void *arg);
                                        /* 0x8001DE2C — called from op12                */
extern void ScriptState_Init(ScriptState *s, void *world, Entity *e, void *arg);
                                        /* 0x8001DC80 — called from op12/13/op02 init  */
extern void ScriptState_Step(ScriptState *s, void *world, Entity *e, void *arg);
                                        /* 0x8001DFC0 — called from op09/12            */
extern void ScriptState_Update(ScriptState *s, void *world, Entity *e, void *arg);
                                        /* 0x8001DDD8 — called from op05/07            */
extern void ScriptState_Render(ScriptState *s, void *world, Entity *e, void *arg);
                                        /* 0x8001E838 — called from op05               */
extern void Entity_Render_Update(void *a0, void *a1, void *a2, void *a3);
                                        /* 0x8001E874 — called from op07               */
extern void Entity_Callback_A(ScriptState *s, void *world, Entity *e, void *arg);
                                        /* 0x8001C438 — called from op01               */
extern void Entity_Callback_B(ScriptState *s, void *world, Entity *e, void *arg);
                                        /* 0x8001C260 — called from op01               */
extern void Entity_Callback_C(ScriptState *s, void *world, Entity *e, void *arg);
                                        /* 0x8001CFE8 — called from op08               */
extern void ScriptExec_ObjectDispatch(Entity *e, void *world, void *ctx, void *arg);
                                        /* 0x80023E9C — object vtable dispatch          */
extern void ScriptExec_Execute(void *a0, void *a1);
                                        /* 0x8002CA2C — top-level script executor       */
extern Entity *Entity_Spawn(void);      /* 0x800247B4 — allocate new entity             */

/* ------------------------------------------------------------------ */
/* ScriptExec opcode handler stubs                                     */
/* Dispatch table ROM+0x06DEC0; each entry = {exec_fn, init_fn}       */
/* ------------------------------------------------------------------ */

/* op00  ASSERT — error check; breaks if a1 != at (mismatched script version) */
void ScriptExec_Op00_Assert(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x800284C4:
     *   BNE a1, at, +12  ; if arg != expected_value, skip BREAK
     *   NOP
     *   BREAK            ; trigger debugger/exception
     *   MFHI a1          ; read hi-register as new arg
     *   JAL 0x8002CA2C   ; call ScriptExec_Execute(?, a1)
     */
}

/* op01  TICK — per-frame update; fires entity callbacks based on flags */
void ScriptExec_Op01_Tick(ScriptState *s0, Entity *s1, void *s2, void *s3) {
    /* Checks s0->flags bits 0x00268088 and clears s0->timer if set.
     * Checks s0->flags bits 0x72018000:
     *   if 0x8000: skip to entity link check
     *   otherwise: call Entity_Callback_A(s0,s2,s1,s3)
     * Checks s1+138 bit 0 → if set: call Entity_Callback_B(s0,s2,s1,s3)
     * Reads s1+8 → sub_struct; writes s0+76 to sub_struct+322.
     */
}

/* op02  CALL_OBJECT — spawn child script / call sub-object */
void ScriptExec_Op02_CallObject(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x80028AD4:
     *   BNE v0, s4, → call ScriptExec_Op12_InitSequence
     * Conditional spawn or call path.
     */
}

/* op03 / op11  DISPATCH — execute method from parent object's vtable */
void ScriptExec_Op03_Dispatch(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x80028F84:
     *   v1 = s0->parent_ptr            // +24
     *   s0->pc = v0                    // writes back pc
     *   v0 = *(u8*)(s0+78)            // opcode byte
     *   v1 = *(v1+16)                 // parent vtable ptr
     *   v0 = v1[v0]                   // vtable[opcode]
     *   s0+94 -= 1                    // decrement tick counter
     *   call 0x80023E9C(s0,s1,ctx,s3) // dispatch through object system
     * Then accesses global counter at 0x8007BDA0, decrements, fires callback.
     */
}

/* op04  NOP — immediate return */
void ScriptExec_Op04_Nop(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x800290BC: JR ra (single instruction) */
    return;
}

/* op05  UPDATE — call the three main update functions */
void ScriptExec_Op05_Update(ScriptState *s0, Entity *s1, void *s2, void *s3) {
    /* 0x80029390:
     *   ScriptState_Render (s1, s2, s0, s3)    // 0x8001E838 — args: entity, world, state, arg
     *   ScriptState_Update (s1, s2, s0, s3)    // 0x8001DDD8
     *   ScriptState_Init   (s1, s2, s0, s3)    // 0x8001DC80
     */
    ScriptState_Render(s0, s2, s1, s3);   /* note: entity/state arg order swapped */
    ScriptState_Update(s0, s2, s1, s3);
    ScriptState_Init(s0, s2, s1, s3);
}

/* op06  SPAWN_ENTITY — create a new entity; check entity limit */
void ScriptExec_Op06_SpawnEntity(ScriptState *s0, Entity *s1, void *s2, void *s3) {
    /* 0x8002948C:
     *   if v1 != 0: s1+128 = v0; call Entity_Spawn(); setup sp+16=0
     *   v0 = s1+32; v1 = s1+156
     *   if (s1->counter - 1) < s1->entity_limit:
     *     s0->flags = 2; opcode (s0+78) = 8 → WAIT_FRAME; counter = 0
     *   else: continue with spawn
     */
}

/* op07  WAIT — decrement counter; trigger callbacks when it expires */
void ScriptExec_Op07_Wait(ScriptState *s0, Entity *s1, void *s2, void *s3) {
    /* 0x80029600:
     *   v0 = *(u16*)(s0+2) - 1; s0+94 = v0   // tick_counter--
     *   if s0->timer >= 0: call Entity_Render_Update
     *   call ScriptState_Update (s1, s2, s0, s3)    // 0x8001DDD8
     *   call Entity_Render_Update (s1, s2, s0, s3)  // 0x8001E874
     */
}

/* op08  WAIT_FRAME — wait for a specific frame condition */
void ScriptExec_Op08_WaitFrame(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x80029914:
     *   if s0->timer < 32 AND *(s2+4) & 0x10:
     *     s0->flags = 32; opcode = 25; s0+94 = 0
     *     s0->extra_flags &= ~9
     *   else:
     *     check s0->pc & 0x10 for alternate opcode (19)
     */
}

/* op09  INIT_ENTITY */
void ScriptExec_Op09_InitEntity(ScriptState *s0, Entity *s1, void *s2, void *s3) {
    /* 0x80029B1C: JAL ScriptState_Step(s0,s2,s1,s3) */
    ScriptState_Step(s0, s2, s1, s3);
}

/* op10  COMPLEX_OP — large handler with register saves */
void ScriptExec_Op10_Complex(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x80029CC8: SW s3,36(sp); SW s2,32(sp); SW ra,48(sp) — large function */
}

/* op11 = same fn as op03 (ScriptExec_Op03_Dispatch) */

/* op12  INIT_SEQUENCE — initialise script call state, run three setup passes */
void ScriptExec_Op12_InitSequence(ScriptState *s0, Entity *s1, void *s2, void *s3) {
    /* 0x80029FA4:
     *   if !(s1->entity_flags & 0x0002):
     *     s0->flags = 2; s0->opcode = 8; s0->tick_counter = 0
     *   ScriptState_Setup (s0, s2, s1, s3)     // 0x8001DE2C
     *   ScriptState_Init  (s0, s2, s1, s3)     // 0x8001DC80
     *   ScriptState_Step  (s0, s2, s1, s3)     // 0x8001DFC0
     */
    if (!(s1->entity_flags & 0x0002)) {
        s0->flags        = 2;
        s0->opcode       = 8;   /* OP_WAIT_FRAME */
        s0->tick_counter = 0;
    }
    ScriptState_Setup(s0, s2, s1, s3);
    ScriptState_Init(s0, s2, s1, s3);
    ScriptState_Step(s0, s2, s1, s3);
}

/* op13  ENTITY_INIT2 */
void ScriptExec_Op13_EntityInit2(ScriptState *s0, Entity *s1, void *s2, void *s3) {
    /* 0x8002A140: JAL ScriptState_Init(s0,s2,s1,s3) */
    ScriptState_Init(s0, s2, s1, s3);
}

/* op14  SET_ENTITY_STATE — write multiple fields to entity struct s2 */
void ScriptExec_Op14_SetState(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x8002A274:
     *   s2+94 = 0; s2+16 &= (some mask)
     *   s2+72  = *(a0+52)
     *   s2+74  = *(s2+44)->56
     *   s2+76  = *(s2+44)->60 - 114
     *   reads a2+412 for further conditional setup
     */
}

/* op15  GET_FIELD — read value from struct chain */
void ScriptExec_Op15_GetField(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x8002ADB4:
     *   v1 = *(v1+16)   — pointer deref
     *   v0 = *(v0+0)    — another deref
     */
}

/* op16  GET_OPCOUNT — return the total opcode count constant (11) */
int ScriptExec_Op16_GetOpCount(void) {
    /* 0x80027E7C: ADDIU v0,zero,11 → returns 11 */
    return 11;
}

/* op17  CHECK_ENTITY — verify entity in linked list */
void ScriptExec_Op17_CheckEntity(ScriptState *s0, void *s1, void *s2, void *s3) {
    /* 0x8002829C: walks linked list (LW v1,32(v0)), checks a0==v0, etc. */
}

/*
 * Dispatch table (ROM+0x06DEC0):
 *
 *  idx  exec_fn       init_fn       name
 *  00   0x800284C4    0x80028714    ASSERT
 *  01   0x80028844    0x800289A4    TICK
 *  02   0x80028AD4    0x80028C68    CALL_OBJECT
 *  03   0x80028F84    0x80028C68    DISPATCH          (shares init with op02)
 *  04   0x800290BC    0x800292D4    NOP
 *  05   0x80029390    0x80029434    UPDATE
 *  06   0x8002948C    0x800295A0    SPAWN_ENTITY
 *  07   0x80029600    0x80029630    WAIT
 *  08   0x80029914    0x80029A10    WAIT_FRAME
 *  09   0x80029B1C    0x80029C28    INIT_ENTITY
 *  10   0x80029CC8    0x80029A10    COMPLEX_OP        (shares init with op08)
 *  11   0x80028F84    0x80029E74    DISPATCH_ALT      (same exec as op03)
 *  12   0x80029FA4    0x8002A0AC    INIT_SEQUENCE
 *  13   0x8002A140    0x8002A178    ENTITY_INIT2
 *  14   0x8002A274    0x8002A488    SET_ENTITY_STATE
 *  15   0x8002ADB4    0x80027BA0    GET_FIELD
 *  16   0x80027E7C    0x800280A0    GET_OPCOUNT
 *  17   0x8002829C    0x80028454    CHECK_ENTITY
 *  18   0x00000000    0x8015E038    <null / end marker>
 *  19   0xFFFFFFFF    0x00000000    <sentinel>
 */
