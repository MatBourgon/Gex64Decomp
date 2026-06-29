/*
 * level_stubs_gillig.c — Giligex Isle
 * Level overlay: GILLIG
 * ROM base: 0x09BD00, VRAM base: 0x80159720
 * Stubs: 5
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/*
 * gillig_couldrn_OnUpdate
 * VRAM 0x80159734, ROM 0x0009BD14
 * Callees: none
 */
/*
 *  80159734: addiu       $sp, $sp, -0x30
 *  80159738: sw          $s2, 0x18($sp)
 *  8015973C: addu        $s2, $a0, $zero
 *  80159740: sw          $s5, 0x24($sp)
 *  80159744: sw          $ra, 0x28($sp)
 *  80159748: sw          $s4, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GILLIG", gillig_couldrn_OnUpdate);

/*
 * gillig_tikifb_OnUpdate
 * VRAM 0x80159C8C, ROM 0x0009C26C
 * Callees: none
 */
/*
 *  80159C8C: addiu       $sp, $sp, -0x20
 *  80159C90: sw          $s0, 0x18($sp)
 *  80159C94: addu        $s0, $a0, $zero
 *  80159C98: sw          $ra, 0x1C($sp)
 *  80159C9C: lw          $v1, 0xF4($s0)
 *  80159CA0: nop
 */
INCLUDE_ASM("asm/nonmatchings/GILLIG", gillig_tikifb_OnUpdate);

/*
 * gillig_tikifb_OnCollide
 * VRAM 0x80159ED8, ROM 0x0009C4B8
 * Callees: none
 */
/*
 *  80159ED8: addiu       $sp, $sp, -0x30
 *  80159EDC: sw          $s1, 0x24($sp)
 *  80159EE0: addu        $s1, $a0, $zero
 *  80159EE4: sw          $ra, 0x2C($sp)
 *  80159EE8: sw          $s2, 0x28($sp)
 *  80159EEC: sw          $s0, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GILLIG", gillig_tikifb_OnCollide);

/*
 * gillig_tikifir_OnUpdate
 * VRAM 0x8015A184, ROM 0x0009C764
 * Callees: none
 */
/*
 *  8015A184: addiu       $sp, $sp, -0x20
 *  8015A188: sw          $s0, 0x18($sp)
 *  8015A18C: addu        $s0, $a0, $zero
 *  8015A190: sw          $ra, 0x1C($sp)
 *  8015A194: lw          $v0, 0x104($s0)
 *  8015A198: nop
 */
INCLUDE_ASM("asm/nonmatchings/GILLIG", gillig_tikifir_OnUpdate);

/*
 * gillig_hedhntr_OnUpdate
 * VRAM 0x8015A45C, ROM 0x0009CA3C
 * Callees: none
 */
/*
 *  8015A45C: addiu       $sp, $sp, -0x20
 *  8015A460: sw          $s0, 0x10($sp)
 *  8015A464: addu        $s0, $a0, $zero
 *  8015A468: addiu       $v0, $zero, -0x1
 *  8015A46C: sw          $ra, 0x1C($sp)
 *  8015A470: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GILLIG", gillig_hedhntr_OnUpdate);
