/*
 * object.c — Game object system
 * Gex 2: Enter the Gecko (SLUS-00598)
 *
 * Confirmed from disassembly of:
 *   0x800380B8  Object_alloc
 *   0x80039698  Object_initFromClass
 *   0x80038810  Object_birth
 *   0x800537A0  ObjectPool_init
 *   0x80063224  ObjectSlot_init
 */

#include "../../include/gex2_types.h"
#include "../../include/gex2_globals.h"
#include <string.h>

/*
 * Object pool layout (confirmed from ObjectPool_init disasm):
 *   Two parallel arrays, each with 32 slots × 12 bytes.
 *   Base A: 0x8009FEE0  (s3 in ObjectPool_init loop)
 *   Base B: 0x8009FEF0  (s1 in ObjectPool_init loop)
 *   Stride: 12 bytes per slot (0xC)
 *   Capacity constant at 0x8009FEC8: 0x1C2 = 450
 *
 *   Per-slot pair (from ObjectSlot_init 0x80063224):
 *     slot_a[+0] = 0 (u32 cleared)
 *     slot_a[+4] = 0 (u32 cleared)
 *     slot_b[+0] = 0
 *     slot_b[+4] = 0
 *     ... then linked together
 */

/* -----------------------------------------------------------------------
 * ObjectPool_init — 0x800537A0
 *
 * Initialises the global object pool (32 slot pairs × 12 bytes each).
 * Sets up counters and calls ObjectSlot_init for each pair.
 * ----------------------------------------------------------------------- */
void ObjectPool_init(void) {
    /* Clear control fields */
    g_ObjectPoolCapacity = 0x1C2;   /* 450 */

    /* Clear the pool arrays */
    memset(g_ObjectPoolA, 0, sizeof(g_ObjectPoolA));
    memset(g_ObjectPoolB, 0, sizeof(g_ObjectPoolB));

    /* Initialise each of the 32 slot pairs.
     * ObjectSlot_init(slot_a_ptr, slot_b_ptr) links them together. */
    for (int i = 0; i < 32; i++) {
        extern void ObjectSlot_init(void *slot_a, void *slot_b);
        u8 *a = g_ObjectPoolA + i * 12;
        u8 *b = g_ObjectPoolB + i * 12;
        ObjectSlot_init(a, b);
    }

    /* Zero various counters confirmed from disasm */
    extern u32 g_ObjectPoolFreeCount;
    extern u32 g_ObjectPoolActiveCount;
    extern u32 g_ObjectPoolCounterA;
    extern u32 g_ObjectPoolCounterB;
    g_ObjectPoolFreeCount   = 0;
    g_ObjectPoolActiveCount = 0;
}

/* -----------------------------------------------------------------------
 * ObjectSlot_init — 0x80063224
 *
 * Initialises one pool slot pair.
 * Exact behaviour: clears first 8 bytes of each, then links them.
 * STUB — full implementation requires more disasm of 0x80063224.
 * ----------------------------------------------------------------------- */
void ObjectSlot_init(void *slot_a, void *slot_b) {
    memset(slot_a, 0, 8);
    memset(slot_b, 0, 8);
    /* STUB: linking logic */
}

/* -----------------------------------------------------------------------
 * Object_alloc — 0x800380B8
 *
 * Allocates one game object from the free-list pool.
 * Takes a pool handle as argument; dequeues the head of the free list.
 *
 * Returns: pointer to allocated GameObject, or NULL if pool exhausted.
 *
 * From disasm:
 *   Reads pool->free_head
 *   If null: STUB (logs error? returns null?)
 *   Else: advances free_head to next free slot, returns dequeued slot.
 * ----------------------------------------------------------------------- */
GameObject *Object_alloc(ObjectPool *pool) {
    if (pool == NULL) {
        return NULL;
    }

    GameObject *obj = (GameObject *)pool->free_head;
    if (obj == NULL) {
        /* Pool exhausted — original may log or assert */
        return NULL;
    }

    /* Advance free list head.
     * The "next" pointer in a free slot is at some offset within the slot.
     * STUB: exact offset of next-pointer TBD from full Object_alloc disasm. */
    /* pool->free_head = *(void **)((u8*)obj + NEXT_PTR_OFFSET); */
    pool->count--;

    return obj;
}

/* -----------------------------------------------------------------------
 * Object_initFromClass — 0x80039698
 *
 * Links a newly-allocated object to its class definition.
 * Zeroes the object's data area (0x114 bytes from offset +0x10).
 *
 * Parameters (confirmed from disasm):
 *   obj       — newly allocated GameObject (a0)
 *   class_ptr — A8AA class definition pointer (a1)
 *
 * From disasm:
 *   jal memset(obj+0x10, 0, 0x114)   ; zero data region
 *   Then reads obj->unk00 (some field)
 *   Reads class_ptr[+0x1C]           ; class flags
 *   Sets flags in obj based on class data
 *   Links obj to class
 * ----------------------------------------------------------------------- */
void Object_initFromClass(GameObject *obj, void *class_ptr) {
    if (obj == NULL) {
        return;
    }

    /* Zero the main data area (confirmed: memset at +0x10, size 0x114) */
    memset((u8 *)obj + 0x10, 0, 0x114);

    /* Link object to class definition */
    obj->class_ptr = class_ptr;

    if (class_ptr != NULL) {
        /* Read class flags from class_ptr[+0x1C]
         * STUB: exact field read and flag propagation TBD */
        u32 *class_flags = (u32 *)((u8 *)class_ptr + 0x1C);
        (void)class_flags; /* STUB */
    }
}

/* -----------------------------------------------------------------------
 * Object_birth — 0x80038810
 *
 * Main entry point to spawn a game object from an entity descriptor.
 * This is called by op91_birthObject (ScriptExec opcode 91).
 *
 * Parameters:
 *   entity — EntityDesc pointer (a0)
 *
 * From disasm (0x80038810):
 *   1. Guard: if entity->flags & 0x08 → already spawned, return
 *   2. s2 = entity->class_ptr        (entity[+0x00])
 *   3. s0 = Object_alloc(pool_handle)
 *   4. Object_initFromClass(s0, s2)
 *   5. s0[+0x1C] = entity            ; link back to entity_desc
 *   6. Copy initial position: entity[+0x10..+0x15] → s0[+0x48..+0x4D]
 *      (uses lwl/lwr for unaligned read — 6 bytes XYZ as int16×3)
 *   7. Second position copy → s0[+0x50..+0x55]
 *   8. Third copy → s0[+0x58..+0x5E]
 *   9. Set scale: s0[+0x68] = s0[+0x6A] = s0[+0x6C] = 0x1000
 *  10. Set flags in s0[+0x10], s0[+0x14]
 *  11. Copy entity[+0x0E] low byte → s0[+0x4F]
 *  12. Link: entity->instance = s0    (entity[+0x24] = s0)
 *  13. Reads g_GameCtxPtr→some_field  (linked-list insertion)
 *  14. Calls several more setup functions (STUB)
 * ----------------------------------------------------------------------- */
void Object_birth(EntityDesc *entity) {
    if (entity == NULL) {
        return;
    }

    /* Guard: bit3 = "already spawned" */
    if (entity->flags & 0x08u) {
        return;
    }

    void *class_ptr = entity->class_ptr;

    /* Allocate object slot from pool
     * STUB: pool handle location TBD */
    extern ObjectPool *g_MainObjectPool;
    GameObject *obj = Object_alloc(g_MainObjectPool);
    if (obj == NULL) {
        return;
    }

    /* Initialise from class data */
    Object_initFromClass(obj, class_ptr);

    /* Link back to entity descriptor */
    obj->entity_desc = entity;

    /* Copy initial XYZ position (3 × int16) */
    s16 px = entity->pos_x;
    s16 py = entity->pos_y;
    s16 pz = entity->pos_z;

    obj->pos_init_x = px;   /* +0x48 */
    obj->pos_init_y = py;   /* +0x4A */
    obj->pos_init_z = pz;   /* +0x4C */

    obj->pos_b_x = px;      /* +0x50 */
    obj->pos_b_y = py;      /* +0x52 */
    obj->pos_b_z = pz;      /* +0x54 */

    obj->pos_c_x = px;      /* +0x58 */
    obj->pos_c_y = py;      /* +0x5A */
    obj->pos_c_z = pz;      /* +0x5C */

    /* Initialise scale to 1.0 in Q12 fixed-point (0x1000 = 4096 = 1.0) */
    obj->scale_x = 0x1000;  /* +0x68 */
    obj->scale_y = 0x1000;  /* +0x6A */
    obj->scale_z = 0x1000;  /* +0x6C */

    /* Copy entity ID byte */
    obj->entity_byte = (u8)(entity->entity_id & 0xFFu);  /* +0x4F */

    /* Write output: entity->instance = obj */
    entity->instance = obj;

    /* Mark as spawned */
    entity->flags |= 0x08u;

    /* STUB: additional setup calls (linked-list insertion into world,
     *       audio/visual initialisation, etc.) */
}
