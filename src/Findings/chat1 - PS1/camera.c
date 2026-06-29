/*
 * camera.c — Camera system
 * Gex 2: Enter the Gecko (SLUS-00598)
 *
 * Confirmed from disassembly of:
 *   0x8005D7C8  Camera_applyNodeB    (cubic hermite interpolation, mode B)
 *   0x8005E754  Camera_behaviorTraverse
 *   0x8005EAC4  Camera_behaviorGetPtr
 *   0x8005E1F4  Camera_behaviorStep
 *   0x80011C8C  Camera_update        (state dispatch + param copy)
 *   0x80015728  Camera_stateMachine  (main state machine)
 *
 * Camera spline config files (BIGFILE slots 8-11):
 *   slot[ 8]: 24 nodes — hub / outdoor camera
 *   slot[ 9]: 12 nodes — standard indoor follow
 *   slot[10]: 16 nodes — extended / boss
 *   slot[11]: 12 nodes — alternate indoor
 *
 * Node formats (confirmed from Camera_behaviorTraverse stride logic):
 *   Mode B (camera_obj.mode == 0): CameraNode32 — 32 bytes, cubic hermite
 *   Mode A (camera_obj.mode == 1): CameraNode10 — 10 bytes, compact
 */

#include "../../include/gex2_types.h"
#include "../../include/gex2_globals.h"
#include <string.h>

/* Fixed-point helpers matching PS1 GTE conventions */
static inline s32 fp_mul(s32 a, s32 b, int shift) {
    return (s32)(((s64)a * b) >> shift);
}

/* -----------------------------------------------------------------------
 * Camera_applyNodeB — 0x8005D7C8
 *
 * Cubic hermite interpolation between two adjacent 32-byte nodes.
 * Writes interpolated (x, y, z) to the camera control struct.
 *
 * Parameters (confirmed from disasm):
 *   cam    — camera object (a0 = t5)
 *   ctrl   — control struct, t parameter from [+0x?] (a1 = t3)
 *   nodeA  — pointer to current node (a2 = t2)
 *   nodeB  — pointer to next node, a3 = nodeA + 0x20 = nodeA + 32
 *
 * Hermite basis functions H0..H3 in terms of t ∈ [0,1]:
 *   H0(t) = 2t³ - 3t² + 1   (start position weight)
 *   H1(t) = -2t³ + 3t²      (end position weight)
 *   H2(t) = t³ - 2t² + t    (start tangent weight)
 *   H3(t) = t³ - t²          (end tangent weight)
 *
 * Output:
 *   cam→out_x = H0*A.pos_x + H1*B.pos_x + H2*A.tangent_x + H3*B.end_x
 *   cam→out_y = similar
 *   cam→out_z = similar
 *
 * The exact output fields within the camera object are not fully mapped;
 * confirmed only that int16 values are written via `sh` instructions.
 *
 * From disasm (confirmed field reads):
 *   nodeA[+0x02] → A.pos_x (s16)
 *   nodeA[+0x04] → A.pos_y (s16)
 *   nodeA[+0x06] → A.pos_z (s16)
 *   nodeA[+0x08] → A.tangent_x (s32)
 *   nodeA[+0x0C] → A.tangent_y (s32)
 *   nodeA[+0x10] → A.tangent_z (s32)
 *   nodeB[+0x02] → B.pos_x (s16)   [nodeB = nodeA + 0x20]
 *   nodeB[+0x04] → B.pos_y (s16)
 *   nodeB[+0x06] → B.pos_z (s16)
 *   nodeB[+0x14] → B.end_tangent_x (s32)
 *   nodeB[+0x18] → B.end_tangent_y (s32)
 *   nodeB[+0x1C] → B.end_tangent_z (s32)
 * ----------------------------------------------------------------------- */
void Camera_applyNodeB(void *cam, s32 t_param,
                       CameraNode32 *nodeA, CameraNode32 *nodeB) {
    if (nodeA == NULL || nodeB == NULL) return;

    /*
     * The t_param is a fixed-point value in some Q format (TBD from disasm).
     * The original multiplies by a0, a1, a2, t0 which are derived from
     * the timing parameter via the hermite basis functions.
     * STUB: proper hermite basis computation.
     */

    /* Read positions */
    s32 ax = nodeA->pos_x,  ay = nodeA->pos_y,  az = nodeA->pos_z;
    s32 bx = nodeB->pos_x,  by = nodeB->pos_y,  bz = nodeB->pos_z;

    /* Read tangents */
    s32 tax = nodeA->tangent_x,   tay = nodeA->tangent_y,   taz = nodeA->tangent_z;
    s32 tbx = nodeB->end_tangent_x, tby = nodeB->end_tangent_y, tbz = nodeB->end_tangent_z;

    /*
     * Hermite basis — STUB implementation.
     * The original uses `mult` (MIPS 32×32→64 multiply) and `srav` shifts.
     * Shift amount TBD from disasm; using 12 as a placeholder (Q12 format).
     */
    s32 t  = t_param;             /* t ∈ [0, 2^shift] */
    int sh = 12;                  /* STUB: actual shift from disasm */

    /* Simplified lerp until hermite basis shifts are confirmed */
    s32 out_x = (s32)(ax + fp_mul(bx - ax, t, sh));
    s32 out_y = (s32)(ay + fp_mul(by - ay, t, sh));
    s32 out_z = (s32)(az + fp_mul(bz - az, t, sh));

    /* STUB: write out_x/y/z to cam struct at confirmed offsets */
    /* From disasm: sh v0, (t5); sh v0, 2(t5); etc. */
    (void)cam;
    (void)out_x; (void)out_y; (void)out_z;
    (void)tax; (void)tay; (void)taz;
    (void)tbx; (void)tby; (void)tbz;
}

/* -----------------------------------------------------------------------
 * Camera_behaviorGetPtr — 0x8005EAC4
 *
 * Resolves a camera control struct index into a pointer within the node
 * array, using stride appropriate for the mode (10 or 32 bytes).
 *
 * Parameters:
 *   cam  — camera object (a0) with fields: node_base[+0], max_count[+4], mode[+6]
 *   ctrl — control struct (a1) with current_index at [+0]
 *
 * Returns: pointer to the node at ctrl->current_index, or NULL if out-of-range.
 * Side effect: some flag byte in cam[+6] gates the stride choice.
 *
 * From disasm (confirmed):
 *   lhu v0, 2(a0)        ; v0 = cam->max_count  (at+4? re-check)
 *   lh  a0, (a1)         ; a0 = ctrl->current_index
 *   slt v0, a0, v0       ; if index < max_count
 *   lbu v1, 6(cam)       ; v1 = mode byte
 *   if v1 == 1: stride = 10, v0 = idx*5*2 = idx*10
 *   else:       stride = 32, v0 = idx<<5  = idx*32
 *   lw v1, (cam)         ; v1 = cam->node_base
 *   addu v0, v0, v1      ; node_ptr = base + offset
 * ----------------------------------------------------------------------- */
void *Camera_behaviorGetPtr(CameraObj *cam, CameraCtrl *ctrl) {
    if (cam == NULL || ctrl == NULL) return NULL;

    s16  index     = ctrl->current_index;
    s16  max_count = cam->max_count;
    u8   mode      = cam->mode;

    if (index < 0 || index >= max_count) {
        return NULL;
    }

    u8 *base = (u8 *)cam->node_base;
    if (base == NULL) return NULL;

    if (mode == 1) {
        /* Mode A: 10-byte stride */
        return base + (index * 10);
    } else {
        /* Mode B: 32-byte stride */
        return base + (index * 32);
    }
}

/* -----------------------------------------------------------------------
 * Camera_behaviorStep — 0x8005E1F4
 *
 * One step of camera behaviour traversal.
 * Gets node pointer and dispatches to the traversal function.
 *
 * Returns 0 if end-of-sequence, 1 if still active.
 * ----------------------------------------------------------------------- */
int Camera_behaviorStep(CameraObj *cam, CameraCtrl *ctrl) {
    void *node_ptr = Camera_behaviorGetPtr(cam, ctrl);
    if (node_ptr == NULL) {
        return 0;
    }

    extern int Camera_behaviorTraverse(CameraObj *cam, CameraCtrl *ctrl,
                                        void *behavior_table);
    return Camera_behaviorTraverse(cam, ctrl, g_CameraBehaviorTable);
}

/* -----------------------------------------------------------------------
 * Camera_behaviorTraverse — 0x8005E754
 *
 * Walks the node array using the appropriate stride (10B or 32B mode).
 * Reads node fields and writes to camera output.
 * Confirmed: stride is selected by cam->mode (lbu $a1, 6($t0)).
 *
 * STUB — full implementation requires completing the field-copy logic
 * and the interaction with the global behaviour table at 0x800893B0.
 * ----------------------------------------------------------------------- */
int Camera_behaviorTraverse(CameraObj *cam, CameraCtrl *ctrl,
                             void *behavior_table) {
    if (cam == NULL || ctrl == NULL) return 0;

    void *node = Camera_behaviorGetPtr(cam, ctrl);
    if (node == NULL) return 0;

    if (cam->mode == 1) {
        /* Mode A: CameraNode10 */
        extern void Camera_applyNodeA(CameraObj *cam, CameraCtrl *ctrl);
        Camera_applyNodeA(cam, ctrl);
    } else {
        /* Mode B: CameraNode32 */
        CameraNode32 *nodeA = (CameraNode32 *)node;
        /* nodeB = nodeA + 1 (stride 32 = sizeof CameraNode32) */
        CameraNode32 *nodeB = nodeA + 1;
        /* t parameter from ctrl state — STUB: t_param source TBD */
        s32 t_param = 0;  /* STUB */
        Camera_applyNodeB(cam, t_param, nodeA, nodeB);
    }

    /* Advance ctrl->current_index */
    ctrl->current_index++;

    return (ctrl->current_index < cam->max_count) ? 1 : 0;
}

/* -----------------------------------------------------------------------
 * Camera_applyNodeA — 0x8005D9D4
 * Compact 10-byte node application.  STUB.
 * ----------------------------------------------------------------------- */
void Camera_applyNodeA(CameraObj *cam, CameraCtrl *ctrl) {
    /* STUB: read CameraNode10 fields and apply to camera */
    (void)cam; (void)ctrl;
}

/* -----------------------------------------------------------------------
 * Camera_update — 0x80011C8C
 *
 * Reads camera config file parameters into camera object fields.
 * Dispatches to sub-handlers based on cam->mode_byte (at +0x4DEE).
 *
 * Confirmed parameter copies (from disasm):
 *   buf = cam[+8]   ← pointer to CamConfigHeader within loaded file
 *   cam[+0x120] = buf[+0x00]   (type_flags)
 *   cam[+0x122] = buf[+0x02]   (node_count)
 *   cam[+0x124] = buf[+0x04]   (primary_param)
 *   cam[+0x128] = buf[+0x30]   (range_limit_A)
 *   cam[+0x12A] = buf[+0x32]   (range_limit_B)
 *   cam[+0x12C] = buf[+0x34]   (range_limit_C)
 *
 * Mode dispatch (confirmed from disasm branch targets):
 *   mode == 1 → Camera_modeHandler_1 (0x80012504)
 *   mode == 4 → Camera_modeHandler_4 (0x80011F48)
 *   mode == 6 → Camera_modeHandler_6 (0x80013E28)
 *   mode == 7 → Camera_modeHandler_7 (0x80013578)
 * ----------------------------------------------------------------------- */
void Camera_update(void *cam_outer, void *world) {
    if (cam_outer == NULL) return;

    /* cam_outer[+8] = pointer to camera config (inner struct / file data) */
    void **cam_inner_ptr = (void **)((u8 *)cam_outer + 8);
    u8 *buf = (u8 *)*cam_inner_ptr;
    if (buf == NULL) return;

    /* Copy parameters at fixed offsets from config buffer */
    u16 *dst_flags   = (u16 *)(buf + 0x120);
    u16 *dst_count   = (u16 *)(buf + 0x122);
    u16 *dst_param   = (u16 *)(buf + 0x124);
    u16 *dst_rangeA  = (u16 *)(buf + 0x128);
    u16 *dst_rangeB  = (u16 *)(buf + 0x12A);
    u16 *dst_rangeC  = (u16 *)(buf + 0x12C);

    *dst_flags  = *(u16 *)(buf + 0x00);
    *dst_count  = *(u16 *)(buf + 0x02);
    *dst_param  = *(u16 *)(buf + 0x04);
    *dst_rangeA = *(u16 *)(buf + 0x30);
    *dst_rangeB = *(u16 *)(buf + 0x32);
    *dst_rangeC = *(u16 *)(buf + 0x34);

    /* Dispatch based on mode byte at cam_outer[+0x4DEE] */
    u8 mode = *((u8 *)cam_outer + 0x4DEE);

    extern void Camera_modeHandler_1(void *cam, void *world);
    extern void Camera_modeHandler_4(void *cam, void *world);
    extern void Camera_modeHandler_6(void *cam, void *world);
    extern void Camera_modeHandler_7(void *cam, void *world);

    switch (mode) {
        case 1: Camera_modeHandler_1(cam_outer, world); break;
        case 4: Camera_modeHandler_4(cam_outer, world); break;
        case 6: Camera_modeHandler_6(cam_outer, world); break;
        case 7: Camera_modeHandler_7(cam_outer, world); break;
        default: break;
    }
}

/* -----------------------------------------------------------------------
 * Camera_stateMachine — 0x80015728
 *
 * Main camera behaviour state machine.
 * State stored at cam[+0x14C] (s16).
 *
 * Confirmed states (from disasm branch targets):
 *   0x02: two sub-modes depending on some condition
 *   0x05: transition with frame counter
 *   0x06: active follow camera (calls 0x8001F1F0 / Camera_followMode)
 *   0x0C: sub-mode of state 0x02
 *   0x0D: state-D transitions
 *   0x0F: terminal state
 *
 * STUB — large function (~0x500 bytes), needs systematic decompilation.
 * ----------------------------------------------------------------------- */
void Camera_stateMachine(void *cam, s32 event) {
    if (cam == NULL) return;

    s16 state = *(s16 *)((u8 *)cam + 0x14C);

    switch (state) {
        case 0x02:
        case 0x0C:
        case 0x0D:
            /* STUB */ break;
        case 0x05:
            /* Transition with frame counter — STUB */ break;
        case 0x06:
        {
            extern void Camera_followMode(void *cam);
            Camera_followMode(cam);
            break;
        }
        case 0x0F:
            /* Terminal state — STUB */ break;
        default:
            break;
    }
}

/* Sub-handler stubs */
void Camera_modeHandler_1(void *cam, void *world) { /* STUB */ }
void Camera_modeHandler_4(void *cam, void *world) { /* STUB */ }
void Camera_modeHandler_6(void *cam, void *world) { /* STUB */ }
void Camera_modeHandler_7(void *cam, void *world) { /* STUB */ }
void Camera_followMode(void *cam)                  { /* STUB */ }
