/*
 * level_stubs_prehst.c — The Pre-History Channel
 * Level overlay: PREHST
 * ROM base: 0x0C6FA0, VRAM base: 0x80159720
 * Stubs: 72
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/* prehst_ttplat_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_ttplat_OnCreate);

/*
 * prehst_ttplat_OnUpdate
 * VRAM 0x80159754, ROM 0x000C6FD4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159754: lw          $v0, 0x1C($a0)
 *  80159758: nop
 *  8015975C: lw          $v1, 0x4($v0)
 *  80159760: nop
 *  80159764: lw          $v0, 0x8($v1)
 *  80159768: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_ttplat_OnUpdate);

/*
 * prehst_ttplat_OnCollide
 * VRAM 0x801599B0, ROM 0x000C7230
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  801599B0: lw          $a2, 0x78($a0)
 *  801599B4: nop
 *  801599B8: lh          $v1, 0x6($a2)
 *  801599BC: addiu       $v0, $zero, 0x4
 *  801599C0: bne         $v1, $v0, . + 4 + (0x2A << 2)
 *  801599C4: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_ttplat_OnCollide);

/*
 * prehst_bug_OnCreate
 * VRAM 0x80159A74, ROM 0x000C72F4
 * Callees: none
 */
/*
 *  80159A74: addiu       $sp, $sp, -0x8
 *  80159A78: addiu       $v0, $zero, 0x18
 *  80159A7C: lui         $v1, 0x10
 *  80159A80: sh          $v0, 0x102($a0)
 *  80159A84: lw          $v0, 0x10($a0)
 *  80159A88: lw          $a1, 0x24($a0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_bug_OnCreate);

/*
 * prehst_bug_OnUpdate
 * VRAM 0x80159B50, ROM 0x000C73D0
 * Callees: none
 */
/*
 *  80159B50: addiu       $sp, $sp, -0x58
 *  80159B54: sw          $s2, 0x50($sp)
 *  80159B58: addu        $s2, $a0, $zero
 *  80159B5C: addiu       $a1, $zero, -0x1
 *  80159B60: sw          $ra, 0x54($sp)
 *  80159B64: sw          $s1, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_bug_OnUpdate);

/*
 * prehst_bug_OnCollide
 * VRAM 0x80159DE4, ROM 0x000C7664
 * Callees: none
 */
/*
 *  80159DE4: addiu       $sp, $sp, -0x20
 *  80159DE8: sw          $s0, 0x10($sp)
 *  80159DEC: addu        $s0, $a0, $zero
 *  80159DF0: sw          $ra, 0x18($sp)
 *  80159DF4: sw          $s1, 0x14($sp)
 *  80159DF8: lw          $a0, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_bug_OnCollide);

/*
 * prehst_bouncer_OnUpdate
 * VRAM 0x80159F64, ROM 0x000C77E4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: ratan2
 */
/*
 *  80159F64: lui         $v1, 0x8007
 *  80159F68: lw          $v1, -0x3060($v1)
 *  80159F6C: addiu       $sp, $sp, -0x68
 *  80159F70: sw          $s1, 0x44($sp)
 *  80159F74: addu        $s1, $a0, $zero
 *  80159F78: sw          $ra, 0x64($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_bouncer_OnUpdate);

/*
 * func_8015AC20_C84A0
 * VRAM 0x8015AC20, ROM 0x000C84A0
 * Callees: none
 */
/*
 *  8015AC20: addiu       $sp, $sp, -0x30
 *  8015AC24: sw          $s0, 0x20($sp)
 *  8015AC28: addu        $s0, $a0, $zero
 *  8015AC2C: addu        $a3, $a1, $zero
 *  8015AC30: sw          $s1, 0x24($sp)
 *  8015AC34: addu        $s1, $a2, $zero
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015AC20_C84A0);

/*
 * func_8015ADA8_C8628
 * VRAM 0x8015ADA8, ROM 0x000C8628
 * Callees: 0x80047E64, 0x8015AC20
 */
/*
 *  8015ADA8: addiu       $sp, $sp, -0x48
 *  8015ADAC: sw          $s7, 0x3C($sp)
 *  8015ADB0: lw          $s7, 0x58($sp)
 *  8015ADB4: sw          $s0, 0x20($sp)
 *  8015ADB8: addu        $s0, $a0, $zero
 *  8015ADBC: sw          $s4, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015ADA8_C8628);

/*
 * prehst_eel_OnCreate
 * VRAM 0x8015AF54, ROM 0x000C87D4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015AF54: lw          $v0, 0x10($a0)
 *  8015AF58: lw          $v1, 0x18($a0)
 *  8015AF5C: sb          $zero, 0x4E($a0)
 *  8015AF60: sh          $zero, 0x5E($a0)
 *  8015AF64: sw          $zero, 0xDC($a0)
 *  8015AF68: sw          $zero, 0xF4($a0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_eel_OnCreate);

/*
 * prehst_eel_OnUpdate
 * VRAM 0x8015AF98, ROM 0x000C8818
 * Callees: none
 */
/*
 *  8015AF98: addiu       $sp, $sp, -0x20
 *  8015AF9C: sw          $s0, 0x10($sp)
 *  8015AFA0: addu        $s0, $a0, $zero
 *  8015AFA4: sw          $ra, 0x18($sp)
 *  8015AFA8: sw          $s1, 0x14($sp)
 *  8015AFAC: lw          $v1, 0xC($a1)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_eel_OnUpdate);

/*
 * prehst_eel_OnCollide
 * VRAM 0x8015B304, ROM 0x000C8B84
 * Callees: 0x80027500
 */
/*
 *  8015B304: addiu       $sp, $sp, -0x18
 *  8015B308: sw          $s0, 0x10($sp)
 *  8015B30C: addu        $s0, $a0, $zero
 *  8015B310: sw          $ra, 0x14($sp)
 *  8015B314: lw          $a0, 0x78($s0)
 *  8015B318: jal         func_80027500
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_eel_OnCollide);

/*
 * prehst_stmvent_OnCreate
 * VRAM 0x8015B348, ROM 0x000C8BC8
 * Callees: RotMatrix
 */
/*
 *  8015B348: addiu       $sp, $sp, -0x40
 *  8015B34C: sw          $s0, 0x30($sp)
 *  8015B350: addu        $s0, $a0, $zero
 *  8015B354: addiu       $a1, $sp, 0x10
 *  8015B358: sw          $ra, 0x38($sp)
 *  8015B35C: sw          $s1, 0x34($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_stmvent_OnCreate);

/*
 * func_8015B47C_C8CFC
 * VRAM 0x8015B47C, ROM 0x000C8CFC
 * Callees: none
 */
/*
 *  8015B47C: addiu       $sp, $sp, -0x18
 *  8015B480: sw          $s0, 0x10($sp)
 *  8015B484: addu        $s0, $a0, $zero
 *  8015B488: sw          $ra, 0x14($sp)
 *  8015B48C: lhu         $a2, 0x6C($s0)
 *  8015B490: lhu         $v0, 0x24($s0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015B47C_C8CFC);

/*
 * func_8015B5B0_C8E30
 * VRAM 0x8015B5B0, ROM 0x000C8E30
 * Callees: none
 */
/*
 *  8015B5B0: addiu       $sp, $sp, -0x48
 *  8015B5B4: sw          $s0, 0x38($sp)
 *  8015B5B8: addu        $s0, $a0, $zero
 *  8015B5BC: lui         $a0, 0x8016
 *  8015B5C0: addiu       $a0, $a0, 0x4490
 *  8015B5C4: sw          $ra, 0x40($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015B5B0_C8E30);

/*
 * prehst_stmvent_OnUpdate
 * VRAM 0x8015B798, ROM 0x000C9018
 * Callees: 0x8015B5B0
 */
/*
 *  8015B798: addiu       $sp, $sp, -0x20
 *  8015B79C: sw          $s0, 0x18($sp)
 *  8015B7A0: addu        $s0, $a0, $zero
 *  8015B7A4: sw          $ra, 0x1C($sp)
 *  8015B7A8: lw          $v0, 0xDC($s0)
 *  8015B7AC: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_stmvent_OnUpdate);

/*
 * prehst_sptball_OnCreate
 * VRAM 0x8015B8D4, ROM 0x000C9154
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B8D4: lw          $v1, 0x28($a0)
 *  8015B8D8: addiu       $v0, $zero, 0x10
 *  8015B8DC: sw          $v0, 0x100($a0)
 *  8015B8E0: addiu       $v0, $zero, 0x1E
 *  8015B8E4: sw          $v0, 0x104($a0)
 *  8015B8E8: lhu         $v0, 0x4C($a0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_sptball_OnCreate);

/*
 * prehst_sptball_OnUpdate
 * VRAM 0x8015B900, ROM 0x000C9180
 * Callees: none
 */
/*
 *  8015B900: addiu       $sp, $sp, -0x28
 *  8015B904: sw          $s0, 0x20($sp)
 *  8015B908: addu        $s0, $a0, $zero
 *  8015B90C: sw          $ra, 0x24($sp)
 *  8015B910: lw          $v1, 0xF4($s0)
 *  8015B914: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_sptball_OnUpdate);

/*
 * prehst_sptball_OnCollide
 * VRAM 0x8015BA30, ROM 0x000C92B0
 * Callees: none
 */
/*
 *  8015BA30: addiu       $sp, $sp, -0x18
 *  8015BA34: sw          $ra, 0x10($sp)
 *  8015BA38: lw          $a2, 0x78($a0)
 *  8015BA3C: nop
 *  8015BA40: lh          $v1, 0x6($a2)
 *  8015BA44: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_sptball_OnCollide);

/*
 * prehst_cavegex_OnCreate
 * VRAM 0x8015BA7C, ROM 0x000C92FC
 * Callees: none
 */
/*
 *  8015BA7C: addu        $a2, $a0, $zero
 *  8015BA80: lw          $a3, 0x24($a2)
 *  8015BA84: lh          $v1, 0x48($a2)
 *  8015BA88: lh          $a0, 0x4A($a2)
 *  8015BA8C: lh          $a1, 0x4C($a2)
 *  8015BA90: addiu       $v0, $zero, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_cavegex_OnCreate);

/*
 * func_8015BAFC_C937C
 * VRAM 0x8015BAFC, ROM 0x000C937C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015BAFC: lui         $v0, 0x8016
 *  8015BB00: lw          $v0, 0x4480($v0)
 *  8015BB04: nop
 *  8015BB08: xori        $v0, $v0, 0x1
 *  8015BB0C: lui         $at, 0x8016
 *  8015BB10: bnez        $a2, . + 4 + (0x8 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015BAFC_C937C);

/*
 * prehst_cavegex_OnUpdate
 * VRAM 0x8015BB48, ROM 0x000C93C8
 * Callees: none
 */
/*
 *  8015BB48: addiu       $sp, $sp, -0xA0
 *  8015BB4C: sw          $s1, 0x8C($sp)
 *  8015BB50: addu        $s1, $a0, $zero
 *  8015BB54: sw          $ra, 0x9C($sp)
 *  8015BB58: sw          $s4, 0x98($sp)
 *  8015BB5C: sw          $s3, 0x94($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_cavegex_OnUpdate);

/*
 * prehst_cavegex_OnCollide
 * VRAM 0x8015C55C, ROM 0x000C9DDC
 * Callees: none
 */
/*
 *  8015C55C: addiu       $sp, $sp, -0x18
 *  8015C560: addu        $a2, $a1, $zero
 *  8015C564: sw          $ra, 0x10($sp)
 *  8015C568: lw          $a1, 0x78($a0)
 *  8015C56C: nop
 *  8015C570: lh          $v1, 0x6($a1)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_cavegex_OnCollide);

/*
 * prehst_cavetl_OnCreate
 * VRAM 0x8015C714, ROM 0x000C9F94
 * Callees: none
 */
/*
 *  8015C714: addiu       $sp, $sp, -0x18
 *  8015C718: sw          $s0, 0x10($sp)
 *  8015C71C: addu        $s0, $a0, $zero
 *  8015C720: sw          $ra, 0x14($sp)
 *  8015C724: lh          $a0, 0x64($s0)
 *  8015C728: addiu       $v0, $zero, 0x4
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_cavetl_OnCreate);

/*
 * prehst_cavetl_OnUpdate
 * VRAM 0x8015C7B8, ROM 0x000CA038
 * Callees: none
 */
/*
 *  8015C7B8: addiu       $sp, $sp, -0x58
 *  8015C7BC: sw          $s0, 0x50($sp)
 *  8015C7C0: addu        $s0, $a0, $zero
 *  8015C7C4: sw          $ra, 0x54($sp)
 *  8015C7C8: lw          $v1, 0xF4($s0)
 *  8015C7CC: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_cavetl_OnUpdate);

/*
 * prehst_cavetl_OnCollide
 * VRAM 0x8015CBE0, ROM 0x000CA460
 * Callees: none
 */
/*
 *  8015CBE0: addiu       $sp, $sp, -0x18
 *  8015CBE4: addu        $a2, $a1, $zero
 *  8015CBE8: sw          $ra, 0x10($sp)
 *  8015CBEC: lw          $a1, 0x78($a0)
 *  8015CBF0: nop
 *  8015CBF4: lh          $v1, 0x6($a1)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_cavetl_OnCollide);

/*
 * prehst_tricer_OnCreate
 * VRAM 0x8015CD10, ROM 0x000CA590
 * Callees: none
 */
/*
 *  8015CD10: addiu       $sp, $sp, -0x28
 *  8015CD14: sw          $s0, 0x18($sp)
 *  8015CD18: addu        $s0, $a0, $zero
 *  8015CD1C: sw          $ra, 0x20($sp)
 *  8015CD20: sw          $s1, 0x1C($sp)
 *  8015CD24: lw          $s1, 0x20($s0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_tricer_OnCreate);

/*
 * prehst_tricer_OnUpdate
 * VRAM 0x8015CDE8, ROM 0x000CA668
 * Callees: ratan2, 0x80027578
 */
/*
 *  8015CDE8: addiu       $sp, $sp, -0x88
 *  8015CDEC: sw          $s0, 0x60($sp)
 *  8015CDF0: addu        $s0, $a0, $zero
 *  8015CDF4: sw          $s7, 0x7C($sp)
 *  8015CDF8: addu        $s7, $a1, $zero
 *  8015CDFC: sw          $fp, 0x80($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_tricer_OnUpdate);

/*
 * prehst_tricer_OnCollide
 * VRAM 0x8015DE7C, ROM 0x000CB6FC
 * Callees: none
 */
/*
 *  8015DE7C: addiu       $sp, $sp, -0x50
 *  8015DE80: sw          $s1, 0x2C($sp)
 *  8015DE84: addu        $s1, $a0, $zero
 *  8015DE88: sw          $s4, 0x38($sp)
 *  8015DE8C: addu        $s4, $a1, $zero
 *  8015DE90: sw          $ra, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_tricer_OnCollide);

/*
 * prehst_raptor_OnCreate
 * VRAM 0x8015E340, ROM 0x000CBBC0
 * Callees: none
 */
/*
 *  8015E340: addiu       $sp, $sp, -0x20
 *  8015E344: sw          $s0, 0x10($sp)
 *  8015E348: addu        $s0, $a0, $zero
 *  8015E34C: sw          $ra, 0x1C($sp)
 *  8015E350: sw          $s2, 0x18($sp)
 *  8015E354: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_raptor_OnCreate);

/*
 * prehst_raptor_OnUpdate
 * VRAM 0x8015E468, ROM 0x000CBCE8
 * Callees: none
 */
/*
 *  8015E468: addiu       $sp, $sp, -0x60
 *  8015E46C: sw          $s3, 0x44($sp)
 *  8015E470: addu        $s3, $a0, $zero
 *  8015E474: sw          $s6, 0x50($sp)
 *  8015E478: addu        $s6, $a1, $zero
 *  8015E47C: sw          $s7, 0x54($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_raptor_OnUpdate);

/*
 * prehst_raptor_OnCollide
 * VRAM 0x8015EA48, ROM 0x000CC2C8
 * Callees: none
 */
/*
 *  8015EA48: addiu       $sp, $sp, -0x18
 *  8015EA4C: sw          $s0, 0x10($sp)
 *  8015EA50: addu        $s0, $a0, $zero
 *  8015EA54: addiu       $t0, $zero, 0x1
 *  8015EA58: sw          $ra, 0x14($sp)
 *  8015EA5C: lw          $a0, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_raptor_OnCollide);

/*
 * prehst_zviolet_OnCreate
 * VRAM 0x8015EB04, ROM 0x000CC384
 * Callees: 0x8004A7B8
 */
/*
 *  8015EB04: addiu       $sp, $sp, -0x18
 *  8015EB08: sw          $s0, 0x10($sp)
 *  8015EB0C: addu        $s0, $a0, $zero
 *  8015EB10: sw          $ra, 0x14($sp)
 *  8015EB14: lw          $v0, 0x20($s0)
 *  8015EB18: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_zviolet_OnCreate);

/*
 * prehst_zviolet_OnUpdate
 * VRAM 0x8015EB80, ROM 0x000CC400
 * Callees: none
 */
/*
 *  8015EB80: addiu       $sp, $sp, -0x30
 *  8015EB84: sw          $s3, 0x1C($sp)
 *  8015EB88: addu        $s3, $a0, $zero
 *  8015EB8C: sw          $s5, 0x24($sp)
 *  8015EB90: addu        $s5, $a1, $zero
 *  8015EB94: sw          $s0, 0x10($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_zviolet_OnUpdate);

/*
 * prehst_zviolet_OnCollide
 * VRAM 0x8015F028, ROM 0x000CC8A8
 * Callees: 0x80027578
 */
/*
 *  8015F028: addiu       $sp, $sp, -0x20
 *  8015F02C: sw          $s2, 0x18($sp)
 *  8015F030: addu        $s2, $a0, $zero
 *  8015F034: sw          $s1, 0x14($sp)
 *  8015F038: addu        $s1, $a1, $zero
 *  8015F03C: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_zviolet_OnCollide);

/*
 * func_8015F1F0_CCA70
 * VRAM 0x8015F1F0, ROM 0x000CCA70
 * Callees: none
 */
/*
 *  8015F1F0: addu        $a3, $a0, $zero
 *  8015F1F4: lw          $v0, 0x1C($a3)
 *  8015F1F8: nop
 *  8015F1FC: lw          $v0, 0x4($v0)
 *  8015F200: nop
 *  8015F204: beqz        $v0, . + 4 + (0x15 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015F1F0_CCA70);

/*
 * func_8015F290_CCB10
 * VRAM 0x8015F290, ROM 0x000CCB10
 * Callees: none
 */
/*
 *  8015F290: addu        $a1, $a0, $zero
 *  8015F294: lw          $a2, 0x10($a1)
 *  8015F298: nop
 *  8015F29C: andi        $v0, $a2, 0x400
 *  8015F2A0: beqz        $v0, . + 4 + (0xA << 2)
 *  8015F2A4: lui         $a0, 0xFFBF
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015F290_CCB10);

/*
 * prehst_gas_OnCreate
 * VRAM 0x8015F2D8, ROM 0x000CCB58
 * Callees: 0x800331BC, 0x8006A020
 */
/*
 *  8015F2D8: addiu       $sp, $sp, -0x28
 *  8015F2DC: sw          $s0, 0x10($sp)
 *  8015F2E0: addu        $s0, $a0, $zero
 *  8015F2E4: sw          $s1, 0x14($sp)
 *  8015F2E8: addu        $s1, $zero, $zero
 *  8015F2EC: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_gas_OnCreate);

/*
 * prehst_gas_OnUpdate
 * VRAM 0x8015F51C, ROM 0x000CCD9C
 * Callees: none
 */
/*
 *  8015F51C: addiu       $sp, $sp, -0x20
 *  8015F520: sw          $s0, 0x10($sp)
 *  8015F524: addu        $s0, $a0, $zero
 *  8015F528: sw          $s1, 0x14($sp)
 *  8015F52C: addiu       $s1, $s0, 0xFC
 *  8015F530: sw          $ra, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_gas_OnUpdate);

/*
 * prehst_gas_OnCollide
 * VRAM 0x8015F760, ROM 0x000CCFE0
 * Callees: none
 */
/*
 *  8015F760: addiu       $sp, $sp, -0x18
 *  8015F764: sw          $ra, 0x10($sp)
 *  8015F768: lw          $v0, 0x78($a0)
 *  8015F76C: nop
 *  8015F770: lw          $a2, 0x14($v0)
 *  8015F774: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_gas_OnCollide);

/*
 * prehst_brkbone_OnCollide
 * VRAM 0x8015F814, ROM 0x000CD094
 * Callees: 0x80027500, INSTANCE_PlainDeath
 */
/*
 *  8015F814: addiu       $sp, $sp, -0x18
 *  8015F818: sw          $s0, 0x10($sp)
 *  8015F81C: addu        $s0, $a0, $zero
 *  8015F820: sw          $ra, 0x14($sp)
 *  8015F824: lw          $a0, 0x78($s0)
 *  8015F828: jal         func_80027500
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_brkbone_OnCollide);

/*
 * prehst_bldrgen_OnCreate
 * VRAM 0x8015F87C, ROM 0x000CD0FC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F87C: lw          $v1, 0x10($a0)
 *  8015F880: lw          $a1, 0x24($a0)
 *  8015F884: lui         $v0, 0x10
 *  8015F888: sw          $zero, 0xF4($a0)
 *  8015F88C: or          $v1, $v1, $v0
 *  8015F890: sw          $v1, 0x10($a0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_bldrgen_OnCreate);

/*
 * prehst_bldrgen_OnUpdate
 * VRAM 0x8015F8C0, ROM 0x000CD140
 * Callees: none
 */
/*
 *  8015F8C0: addiu       $sp, $sp, -0x18
 *  8015F8C4: sw          $s0, 0x10($sp)
 *  8015F8C8: addu        $s0, $a0, $zero
 *  8015F8CC: addiu       $v1, $zero, 0x1
 *  8015F8D0: sw          $ra, 0x14($sp)
 *  8015F8D4: lw          $v0, 0xF4($s0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_bldrgen_OnUpdate);

/*
 * prehst_boulder_OnCreate
 * VRAM 0x8015F960, ROM 0x000CD1E0
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F960: lui         $a1, 0x10
 *  8015F964: lw          $v0, 0x10($a0)
 *  8015F968: lw          $v1, 0x28($a0)
 *  8015F96C: ori         $a1, $a1, 0x400
 *  8015F970: sw          $zero, 0xF4($a0)
 *  8015F974: sw          $zero, 0x10C($a0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_boulder_OnCreate);

/*
 * func_8015F9A4_CD224
 * VRAM 0x8015F9A4, ROM 0x000CD224
 * Callees: none
 */
/*
 *  8015F9A4: addiu       $sp, $sp, -0x20
 *  8015F9A8: sw          $s0, 0x10($sp)
 *  8015F9AC: addu        $s0, $a0, $zero
 *  8015F9B0: addu        $t0, $a1, $zero
 *  8015F9B4: lw          $v1, 0x38($sp)
 *  8015F9B8: lw          $a3, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015F9A4_CD224);

/*
 * func_8015FC2C_CD4AC
 * VRAM 0x8015FC2C, ROM 0x000CD4AC
 * Callees: none
 */
/*
 *  8015FC2C: addiu       $sp, $sp, -0x20
 *  8015FC30: addu        $a2, $a0, $zero
 *  8015FC34: sw          $ra, 0x18($sp)
 *  8015FC38: lh          $v0, 0x20($a2)
 *  8015FC3C: lh          $a0, 0x50($a2)
 *  8015FC40: lh          $v1, 0x44($a2)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_8015FC2C_CD4AC);

/*
 * prehst_boulder_OnUpdate
 * VRAM 0x8015FD1C, ROM 0x000CD59C
 * Callees: none
 */
/*
 *  8015FD1C: addiu       $sp, $sp, -0x60
 *  8015FD20: sw          $s2, 0x48($sp)
 *  8015FD24: addu        $s2, $a0, $zero
 *  8015FD28: addiu       $a1, $s2, 0xFC
 *  8015FD2C: addiu       $a2, $s2, 0x104
 *  8015FD30: addu        $a3, $zero, $zero
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_boulder_OnUpdate);

/*
 * prehst_boulder_OnCollide
 * VRAM 0x8016003C, ROM 0x000CD8BC
 * Callees: none
 */
/*
 *  8016003C: addiu       $sp, $sp, -0x20
 *  80160040: sw          $s0, 0x10($sp)
 *  80160044: addu        $s0, $a0, $zero
 *  80160048: sw          $ra, 0x18($sp)
 *  8016004C: sw          $s1, 0x14($sp)
 *  80160050: lw          $a0, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_boulder_OnCollide);

/*
 * prehst_spitplt_OnCreate
 * VRAM 0x801600C8, ROM 0x000CD948
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  801600C8: lw          $a3, 0x24($a0)
 *  801600CC: nop
 *  801600D0: beqz        $a3, . + 4 + (0x10 << 2)
 *  801600D4: addu        $a1, $zero, $zero
 *  801600D8: lw          $v0, 0x4($a3)
 *  801600DC: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_spitplt_OnCreate);

/*
 * prehst_spitplt_OnUpdate
 * VRAM 0x80160120, ROM 0x000CD9A0
 * Callees: 0x8002DAF8, OBTABLE_FindObject, INSTANCE_BirthObject
 */
/*
 *  80160120: addiu       $sp, $sp, -0x30
 *  80160124: sw          $s0, 0x18($sp)
 *  80160128: addu        $s0, $a0, $zero
 *  8016012C: sw          $ra, 0x28($sp)
 *  80160130: sw          $s3, 0x24($sp)
 *  80160134: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_spitplt_OnUpdate);

/*
 * prehst_spitplt_OnCollide
 * VRAM 0x80160584, ROM 0x000CDE04
 * Callees: 0x80027500
 */
/*
 *  80160584: addiu       $sp, $sp, -0x18
 *  80160588: sw          $s0, 0x10($sp)
 *  8016058C: addu        $s0, $a0, $zero
 *  80160590: sw          $ra, 0x14($sp)
 *  80160594: lw          $a0, 0x78($s0)
 *  80160598: jal         func_80027500
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_spitplt_OnCollide);

/*
 * prehst_ptera_OnCreate
 * VRAM 0x801605C8, ROM 0x000CDE48
 * Callees: none
 */
/*
 *  801605C8: addiu       $sp, $sp, -0x58
 *  801605CC: sw          $s0, 0x48($sp)
 *  801605D0: addu        $s0, $a0, $zero
 *  801605D4: lui         $a0, 0x10
 *  801605D8: sw          $ra, 0x54($sp)
 *  801605DC: sw          $s2, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_ptera_OnCreate);

/*
 * func_80160840_CE0C0
 * VRAM 0x80160840, ROM 0x000CE0C0
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80160840: lw          $a1, 0x78($a0)
 *  80160844: nop
 *  80160848: lh          $v1, 0x6($a1)
 *  8016084C: addiu       $v0, $zero, 0x3
 *  80160850: bne         $v1, $v0, . + 4 + (0x10 << 2)
 *  80160854: nop
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80160840_CE0C0);

/*
 * prehst_ptera_OnCollide
 * VRAM 0x8016089C, ROM 0x000CE11C
 * Callees: 0x80027500
 */
/*
 *  8016089C: addiu       $sp, $sp, -0x38
 *  801608A0: sw          $s1, 0x14($sp)
 *  801608A4: addu        $s1, $a0, $zero
 *  801608A8: sw          $s5, 0x24($sp)
 *  801608AC: addu        $s5, $a1, $zero
 *  801608B0: sw          $s4, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_ptera_OnCollide);

/*
 * prehst_ptera_OnUpdate
 * VRAM 0x80160DB4, ROM 0x000CE634
 * Callees: none
 */
/*
 *  80160DB4: addiu       $sp, $sp, -0x1A8
 *  80160DB8: sw          $s4, 0x190($sp)
 *  80160DBC: addu        $s4, $a0, $zero
 *  80160DC0: sw          $ra, 0x1A4($sp)
 *  80160DC4: sw          $fp, 0x1A0($sp)
 *  80160DC8: sw          $s7, 0x19C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_ptera_OnUpdate);

/*
 * func_801630A0_D0920
 * VRAM 0x801630A0, ROM 0x000D0920
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ, RotMatrixX, RotMatrix
 */
/*
 *  801630A0: addiu       $sp, $sp, -0x48
 *  801630A4: sw          $s0, 0x40($sp)
 *  801630A8: addu        $s0, $a0, $zero
 *  801630AC: sw          $ra, 0x44($sp)
 *  801630B0: jal         func_80030B5C
 *  801630B4: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_801630A0_D0920);

/*
 * func_80163138_D09B8
 * VRAM 0x80163138, ROM 0x000D09B8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ, RotMatrix, RotMatrixX
 */
/*
 *  80163138: lhu         $v0, 0x60($a0)
 *  8016313C: lhu         $v1, 0x62($a0)
 *  80163140: andi        $v0, $v0, 0xFFF
 *  80163144: andi        $v1, $v1, 0xFFF
 *  80163148: sh          $v0, 0x60($a0)
 *  8016314C: sh          $v1, 0x62($a0)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163138_D09B8);

/*
 * func_80163160_D09E0
 * VRAM 0x80163160, ROM 0x000D09E0
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ, RotMatrix, RotMatrixX
 */
/*
 *  80163160: addiu       $sp, $sp, -0x58
 *  80163164: sw          $s1, 0x4C($sp)
 *  80163168: addu        $s1, $a0, $zero
 *  8016316C: sw          $s0, 0x48($sp)
 *  80163170: addu        $s0, $a1, $zero
 *  80163174: sw          $ra, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163160_D09E0);

/*
 * func_80163264_D0AE4
 * VRAM 0x80163264, ROM 0x000D0AE4
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ, RotMatrix, RotMatrixX
 */
/*
 *  80163264: addiu       $sp, $sp, -0x60
 *  80163268: sw          $s0, 0x48($sp)
 *  8016326C: addu        $s0, $a0, $zero
 *  80163270: sw          $s2, 0x50($sp)
 *  80163274: addu        $s2, $a1, $zero
 *  80163278: sw          $s3, 0x54($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163264_D0AE4);

/*
 * func_801633DC_D0C5C
 * VRAM 0x801633DC, ROM 0x000D0C5C
 * Callees: MATH3D_SetUnityMatrix, RotMatrix, RotMatrixX, RotMatrixZ
 */
/*
 *  801633DC: addiu       $sp, $sp, -0x58
 *  801633E0: sw          $s0, 0x48($sp)
 *  801633E4: addu        $s0, $a0, $zero
 *  801633E8: sw          $s1, 0x4C($sp)
 *  801633EC: addu        $s1, $a1, $zero
 *  801633F0: sw          $ra, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_801633DC_D0C5C);

/*
 * func_80163500_D0D80
 * VRAM 0x80163500, ROM 0x000D0D80
 * Callees: MATH3D_SetUnityMatrix, RotMatrix, RotMatrixZ, RotMatrixX
 */
/*
 *  80163500: addiu       $sp, $sp, -0x58
 *  80163504: sw          $s1, 0x4C($sp)
 *  80163508: addu        $s1, $a0, $zero
 *  8016350C: sw          $s0, 0x48($sp)
 *  80163510: addu        $s0, $a1, $zero
 *  80163514: sw          $ra, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163500_D0D80);

/*
 * func_80163604_D0E84
 * VRAM 0x80163604, ROM 0x000D0E84
 * Callees: RotMatrix, MATH3D_SetUnityMatrix, RotMatrixX, MulMatrix0
 */
/*
 *  80163604: addiu       $sp, $sp, -0x58
 *  80163608: sw          $s2, 0x50($sp)
 *  8016360C: addu        $s2, $a0, $zero
 *  80163610: sw          $s1, 0x4C($sp)
 *  80163614: addu        $s1, $a1, $zero
 *  80163618: sw          $s0, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163604_D0E84);

/*
 * func_801636E8_D0F68
 * VRAM 0x801636E8, ROM 0x000D0F68
 * Callees: MATH3D_SetUnityMatrix, RotMatrix, RotMatrixX, MulMatrix0
 */
/*
 *  801636E8: addiu       $sp, $sp, -0x58
 *  801636EC: sw          $s2, 0x50($sp)
 *  801636F0: addu        $s2, $a0, $zero
 *  801636F4: sw          $s1, 0x4C($sp)
 *  801636F8: addu        $s1, $a1, $zero
 *  801636FC: sw          $s0, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_801636E8_D0F68);

/*
 * func_801637D0_D1050
 * VRAM 0x801637D0, ROM 0x000D1050
 * Callees: MATH3D_SetUnityMatrix, RotMatrixX, RotMatrix, MulMatrix0
 */
/*
 *  801637D0: addiu       $sp, $sp, -0xA8
 *  801637D4: sw          $s3, 0x9C($sp)
 *  801637D8: addu        $s3, $a0, $zero
 *  801637DC: sw          $s0, 0x90($sp)
 *  801637E0: addu        $s0, $a3, $zero
 *  801637E4: sw          $s1, 0x94($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_801637D0_D1050);

/*
 * func_801639D0_D1250
 * VRAM 0x801639D0, ROM 0x000D1250
 * Callees: MATH3D_SetUnityMatrix, RotMatrixX, RotMatrix, MulMatrix0
 */
/*
 *  801639D0: addiu       $sp, $sp, -0xA8
 *  801639D4: sw          $s3, 0x9C($sp)
 *  801639D8: addu        $s3, $a0, $zero
 *  801639DC: sw          $s0, 0x90($sp)
 *  801639E0: lw          $s0, 0xB8($sp)
 *  801639E4: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_801639D0_D1250);

/*
 * func_80163BC8_D1448
 * VRAM 0x80163BC8, ROM 0x000D1448
 * Callees: none
 */
/*
 *  80163BC8: addiu       $sp, $sp, -0x8
 *  80163BCC: addu        $t0, $a1, $zero
 *  80163BD0: addu        $t1, $a2, $zero
 *  80163BD4: sll         $a2, $a2, 16
 *  80163BD8: lh          $a3, 0x4C($a0)
 *  80163BDC: sll         $a1, $a1, 16
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163BC8_D1448);

/*
 * func_80163C4C_D14CC
 * VRAM 0x80163C4C, ROM 0x000D14CC
 * Callees: none
 */
/*
 *  80163C4C: addiu       $sp, $sp, -0x20
 *  80163C50: sw          $s0, 0x10($sp)
 *  80163C54: addu        $s0, $a0, $zero
 *  80163C58: addu        $t0, $a1, $zero
 *  80163C5C: lw          $v1, 0x38($sp)
 *  80163C60: lw          $a3, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163C4C_D14CC);

/*
 * func_80163EE0_D1760
 * VRAM 0x80163EE0, ROM 0x000D1760
 * Callees: none
 */
/*
 *  80163EE0: addiu       $sp, $sp, -0x20
 *  80163EE4: addu        $a2, $a0, $zero
 *  80163EE8: sw          $ra, 0x18($sp)
 *  80163EEC: lh          $v0, 0x20($a2)
 *  80163EF0: lh          $a0, 0x50($a2)
 *  80163EF4: lh          $v1, 0x44($a2)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163EE0_D1760);

/*
 * func_80163F94_D1814
 * VRAM 0x80163F94, ROM 0x000D1814
 * Callees: 0x8006A020, 0x8003A6AC, 0x8003A4E0, 0x800170E8
 */
/*
 *  80163F94: addiu       $sp, $sp, -0x58
 *  80163F98: sw          $s2, 0x48($sp)
 *  80163F9C: addu        $s2, $a0, $zero
 *  80163FA0: sw          $ra, 0x54($sp)
 *  80163FA4: sw          $s4, 0x50($sp)
 *  80163FA8: sw          $s3, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", func_80163F94_D1814);

/*
 * prehst_lavadrp_OnCreate
 * VRAM 0x801641A8, ROM 0x000D1A28
 * Callees: 0x80048DE4, 0x80047DD4
 */
/*
 *  801641A8: addiu       $sp, $sp, -0x20
 *  801641AC: sw          $s0, 0x10($sp)
 *  801641B0: addu        $s0, $a0, $zero
 *  801641B4: lui         $v1, 0x10
 *  801641B8: ori         $v1, $v1, 0x400
 *  801641BC: addiu       $a1, $s0, 0x10C
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_lavadrp_OnCreate);

/*
 * prehst_lavadrp_OnUpdate
 * VRAM 0x8016427C, ROM 0x000D1AFC
 * Callees: SCRIPT_SplineProcess, 0x80048DE4, 0x80163F94, INSTANCE_PlainDeath
 */
/*
 *  8016427C: addiu       $sp, $sp, -0x48
 *  80164280: sw          $s1, 0x2C($sp)
 *  80164284: addu        $s1, $a0, $zero
 *  80164288: addu        $v1, $zero, $zero
 *  8016428C: sw          $ra, 0x44($sp)
 *  80164290: sw          $s6, 0x40($sp)
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_lavadrp_OnUpdate);

/*
 * prehst_lavadrp_OnCollide
 * VRAM 0x80164418, ROM 0x000D1C98
 * Callees: 0x8002275C
 */
/*
 *  80164418: addiu       $sp, $sp, -0x18
 *  8016441C: sw          $ra, 0x10($sp)
 *  80164420: lw          $a2, 0x78($a0)
 *  80164424: nop
 *  80164428: lh          $v1, 0x6($a2)
 *  8016442C: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/PREHST", prehst_lavadrp_OnCollide);
