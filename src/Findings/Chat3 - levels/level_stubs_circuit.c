/*
 * level_stubs_circuit.c — Circuit Central
 * Level overlay: CIRCUIT
 * ROM base: 0x080900, VRAM base: 0x80159720
 * Stubs: 84
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/* circuit_plat_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_plat_OnCreate);

/*
 * circuit_plat_OnUpdate
 * VRAM 0x801599AC, ROM 0x00080B8C
 * Callees: none
 */
/*
 *  801599AC: addiu       $sp, $sp, -0x30
 *  801599B0: sw          $s0, 0x20($sp)
 *  801599B4: addu        $s0, $a0, $zero
 *  801599B8: sw          $s2, 0x28($sp)
 *  801599BC: sw          $ra, 0x2C($sp)
 *  801599C0: sw          $s1, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_plat_OnUpdate);

/*
 * circuit_plat_OnCollide
 * VRAM 0x80159DB8, ROM 0x00080F98
 * Callees: none
 */
/*
 *  80159DB8: addiu       $sp, $sp, -0x20
 *  80159DBC: sw          $s0, 0x10($sp)
 *  80159DC0: addu        $s0, $a0, $zero
 *  80159DC4: sw          $ra, 0x18($sp)
 *  80159DC8: sw          $s1, 0x14($sp)
 *  80159DCC: lw          $v0, 0x24($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_plat_OnCollide);

/*
 * circuit_bug_OnCreate
 * VRAM 0x80159E4C, ROM 0x0008102C
 * Callees: none
 */
/*
 *  80159E4C: addiu       $sp, $sp, -0x8
 *  80159E50: addiu       $v0, $zero, 0x18
 *  80159E54: lui         $v1, 0x10
 *  80159E58: sh          $v0, 0x102($a0)
 *  80159E5C: lw          $v0, 0x10($a0)
 *  80159E60: lw          $a1, 0x24($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_bug_OnCreate);

/*
 * circuit_bug_OnUpdate
 * VRAM 0x80159F28, ROM 0x00081108
 * Callees: none
 */
/*
 *  80159F28: addiu       $sp, $sp, -0x58
 *  80159F2C: sw          $s2, 0x50($sp)
 *  80159F30: addu        $s2, $a0, $zero
 *  80159F34: addiu       $a1, $zero, -0x1
 *  80159F38: sw          $ra, 0x54($sp)
 *  80159F3C: sw          $s1, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_bug_OnUpdate);

/*
 * circuit_bug_OnCollide
 * VRAM 0x8015A1BC, ROM 0x0008139C
 * Callees: none
 */
/*
 *  8015A1BC: addiu       $sp, $sp, -0x20
 *  8015A1C0: sw          $s0, 0x10($sp)
 *  8015A1C4: addu        $s0, $a0, $zero
 *  8015A1C8: sw          $ra, 0x18($sp)
 *  8015A1CC: sw          $s1, 0x14($sp)
 *  8015A1D0: lw          $a0, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_bug_OnCollide);

/*
 * circuit_bouncer_OnUpdate
 * VRAM 0x8015A33C, ROM 0x0008151C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015A33C: lui         $v1, 0x8007
 *  8015A340: lw          $v1, -0x3060($v1)
 *  8015A344: addiu       $sp, $sp, -0x68
 *  8015A348: sw          $s1, 0x44($sp)
 *  8015A34C: addu        $s1, $a0, $zero
 *  8015A350: sw          $ra, 0x64($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_bouncer_OnUpdate);

/* circuit_charger_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_charger_OnCreate);

/*
 * circuit_charger_OnUpdate
 * VRAM 0x8015B108, ROM 0x000822E8
 * Callees: 0x8002DAF8
 */
/*
 *  8015B108: addiu       $sp, $sp, -0x28
 *  8015B10C: sw          $s1, 0x1C($sp)
 *  8015B110: addu        $s1, $a0, $zero
 *  8015B114: sw          $ra, 0x20($sp)
 *  8015B118: sw          $s0, 0x18($sp)
 *  8015B11C: lw          $v0, 0x18($s1)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_charger_OnUpdate);

/*
 * circuit_charger_OnCollide
 * VRAM 0x8015B378, ROM 0x00082558
 * Callees: none
 */
/*
 *  8015B378: addiu       $sp, $sp, -0x20
 *  8015B37C: sw          $s0, 0x10($sp)
 *  8015B380: addu        $s0, $a0, $zero
 *  8015B384: sw          $ra, 0x18($sp)
 *  8015B388: sw          $s1, 0x14($sp)
 *  8015B38C: lw          $v0, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_charger_OnCollide);

/* circuit_chrganm_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_chrganm_OnCreate);

/*
 * circuit_chrganm_OnUpdate
 * VRAM 0x8015B478, ROM 0x00082658
 * Callees: none
 */
/*
 *  8015B478: addiu       $sp, $sp, -0x28
 *  8015B47C: sw          $s3, 0x1C($sp)
 *  8015B480: addu        $s3, $a1, $zero
 *  8015B484: sw          $ra, 0x20($sp)
 *  8015B488: sw          $s2, 0x18($sp)
 *  8015B48C: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_chrganm_OnUpdate);

/*
 * func_8015B548_82728
 * VRAM 0x8015B548, ROM 0x00082728
 * Callees: 0x8002E704
 */
/*
 *  8015B548: addiu       $sp, $sp, -0x18
 *  8015B54C: sw          $ra, 0x10($sp)
 *  8015B550: lw          $v0, 0xFC($a0)
 *  8015B554: nop
 *  8015B558: jal         func_8002E704
 *  8015B55C: sh          $v0, 0x6A($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015B548_82728);

/*
 * func_8015B570_82750
 * VRAM 0x8015B570, ROM 0x00082750
 * Callees: 0x80041FD0
 */
/*
 *  8015B570: addiu       $sp, $sp, -0x78
 *  8015B574: sw          $s1, 0x6C($sp)
 *  8015B578: addu        $s1, $a0, $zero
 *  8015B57C: sw          $ra, 0x70($sp)
 *  8015B580: sw          $s0, 0x68($sp)
 *  8015B584: lw          $s0, 0x2C($s1)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015B570_82750);

/*
 * circuit_ebridge_OnCreate
 * VRAM 0x8015B684, ROM 0x00082864
 * Callees: none
 */
/*
 *  8015B684: addiu       $sp, $sp, -0x20
 *  8015B688: sw          $s0, 0x10($sp)
 *  8015B68C: addu        $s0, $a0, $zero
 *  8015B690: lui         $v0, 0x2
 *  8015B694: sw          $ra, 0x1C($sp)
 *  8015B698: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ebridge_OnCreate);

/*
 * func_8015B780_82960
 * VRAM 0x8015B780, ROM 0x00082960
 * Callees: none
 */
/*
 *  8015B780: addiu       $sp, $sp, -0x18
 *  8015B784: addu        $v1, $a0, $zero
 *  8015B788: sw          $ra, 0x14($sp)
 *  8015B78C: sw          $s0, 0x10($sp)
 *  8015B790: lw          $a2, 0x120($v1)
 *  8015B794: lw          $s0, 0x8($a1)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015B780_82960);

/*
 * func_8015B7E0_829C0
 * VRAM 0x8015B7E0, ROM 0x000829C0
 * Callees: none
 */
/*
 *  8015B7E0: addiu       $sp, $sp, -0x90
 *  8015B7E4: sw          $s1, 0x74($sp)
 *  8015B7E8: addu        $s1, $a0, $zero
 *  8015B7EC: sw          $s4, 0x80($sp)
 *  8015B7F0: addu        $s4, $zero, $zero
 *  8015B7F4: addu        $a3, $zero, $zero
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015B7E0_829C0);

/*
 * func_8015BA9C_82C7C
 * VRAM 0x8015BA9C, ROM 0x00082C7C
 * Callees: 0x8015B570
 */
/*
 *  8015BA9C: addiu       $sp, $sp, -0x28
 *  8015BAA0: sw          $s0, 0x10($sp)
 *  8015BAA4: addu        $s0, $a0, $zero
 *  8015BAA8: sw          $s2, 0x18($sp)
 *  8015BAAC: addu        $s2, $a1, $zero
 *  8015BAB0: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015BA9C_82C7C);

/*
 * circuit_ebridge_OnUpdate
 * VRAM 0x8015BBC4, ROM 0x00082DA4
 * Callees: INSTANCE_InsertInstanceWithFlagsCleared
 */
/*
 *  8015BBC4: addiu       $sp, $sp, -0x38
 *  8015BBC8: sw          $s0, 0x28($sp)
 *  8015BBCC: addu        $s0, $a0, $zero
 *  8015BBD0: sw          $ra, 0x30($sp)
 *  8015BBD4: sw          $s1, 0x2C($sp)
 *  8015BBD8: lw          $v0, 0x118($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ebridge_OnUpdate);

/* circuit_ebridge_OnCollide — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ebridge_OnCollide);

/*
 * circuit_ebrijac_OnCreate
 * VRAM 0x8015BEC4, ROM 0x000830A4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015BEC4: lw          $v1, 0x24($a0)
 *  8015BEC8: addiu       $v0, $zero, -0x1
 *  8015BECC: beqz        $v1, . + 4 + (0x4 << 2)
 *  8015BED0: sw          $v0, 0xFC($a0)
 *  8015BED4: lw          $v0, 0x0($v1)
 *  8015BED8: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ebrijac_OnCreate);

/*
 * circuit_ebrijac_OnUpdate
 * VRAM 0x8015BEE8, ROM 0x000830C8
 * Callees: 0x8002E704
 */
/*
 *  8015BEE8: addiu       $sp, $sp, -0x18
 *  8015BEEC: sw          $ra, 0x10($sp)
 *  8015BEF0: lw          $v0, 0x104($a0)
 *  8015BEF4: nop
 *  8015BEF8: beqz        $v0, . + 4 + (0x7 << 2)
 *  8015BEFC: addiu       $v0, $zero, 0x1000
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ebrijac_OnUpdate);

/*
 * circuit_ebrijac_OnCollide
 * VRAM 0x8015BF40, ROM 0x00083120
 * Callees: none
 */
/*
 *  8015BF40: addiu       $sp, $sp, -0x48
 *  8015BF44: sw          $s0, 0x20($sp)
 *  8015BF48: addu        $s0, $a0, $zero
 *  8015BF4C: sw          $s6, 0x38($sp)
 *  8015BF50: addu        $s6, $a1, $zero
 *  8015BF54: sw          $ra, 0x40($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ebrijac_OnCollide);

/*
 * func_8015C18C_8336C
 * VRAM 0x8015C18C, ROM 0x0008336C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C18C: lw          $v0, 0x1C($a0)
 *  8015C190: addiu       $sp, $sp, -0x8
 *  8015C194: lw          $v0, 0x4($v0)
 *  8015C198: addu        $a3, $zero, $zero
 *  8015C19C: lw          $t1, 0x0($v0)
 *  8015C1A0: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015C18C_8336C);

/*
 * circuit_orbplat_OnCreate
 * VRAM 0x8015C220, ROM 0x00083400
 * Callees: none
 */
/*
 *  8015C220: addiu       $sp, $sp, -0x18
 *  8015C224: sw          $s0, 0x10($sp)
 *  8015C228: addu        $s0, $a0, $zero
 *  8015C22C: sw          $ra, 0x14($sp)
 *  8015C230: lw          $v0, 0x18($s0)
 *  8015C234: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_orbplat_OnCreate);

/*
 * circuit_orbplat_OnUpdate
 * VRAM 0x8015C310, ROM 0x000834F0
 * Callees: none
 */
/*
 *  8015C310: addiu       $sp, $sp, -0x30
 *  8015C314: sw          $s0, 0x18($sp)
 *  8015C318: addu        $s0, $a0, $zero
 *  8015C31C: sw          $ra, 0x28($sp)
 *  8015C320: sw          $s3, 0x24($sp)
 *  8015C324: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_orbplat_OnUpdate);

/*
 * circuit_orbplat_OnCollide
 * VRAM 0x8015C758, ROM 0x00083938
 * Callees: none
 */
/*
 *  8015C758: addiu       $sp, $sp, -0x18
 *  8015C75C: sw          $ra, 0x10($sp)
 *  8015C760: lw          $v1, 0x78($a0)
 *  8015C764: nop
 *  8015C768: lh          $v0, 0x6($v1)
 *  8015C76C: addiu       $a1, $zero, 0x4
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_orbplat_OnCollide);

/*
 * circuit_orbpole_OnCreate
 * VRAM 0x8015C7F0, ROM 0x000839D0
 * Callees: none
 */
/*
 *  8015C7F0: addiu       $sp, $sp, -0x20
 *  8015C7F4: sw          $s0, 0x10($sp)
 *  8015C7F8: addu        $s0, $a0, $zero
 *  8015C7FC: sw          $ra, 0x18($sp)
 *  8015C800: sw          $s1, 0x14($sp)
 *  8015C804: lw          $v0, 0x1C($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_orbpole_OnCreate);

/* circuit_orbpole_OnUpdate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_orbpole_OnUpdate);

/*
 * func_8015C9CC_83BAC
 * VRAM 0x8015C9CC, ROM 0x00083BAC
 * Callees: none
 */
/*
 *  8015C9CC: addiu       $v0, $zero, 0x2
 *  8015C9D0: sw          $v0, 0xF4($a0)
 *  8015C9D4: addiu       $v0, $zero, 0x1
 *  8015C9D8: sw          $v0, 0xF8($a0)
 *  8015C9DC: addiu       $v0, $zero, 0x1
 *  8015C9E0: sb          $v0, 0x4E($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015C9CC_83BAC);

/*
 * circuit_orbpole_OnCollide
 * VRAM 0x8015C9FC, ROM 0x00083BDC
 * Callees: none
 */
/*
 *  8015C9FC: addiu       $sp, $sp, -0x70
 *  8015CA00: sw          $s0, 0x58($sp)
 *  8015CA04: addu        $s0, $a0, $zero
 *  8015CA08: sw          $ra, 0x6C($sp)
 *  8015CA0C: sw          $s4, 0x68($sp)
 *  8015CA10: sw          $s3, 0x64($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_orbpole_OnCollide);

/*
 * circuit_launch_OnUpdate
 * VRAM 0x8015CD40, ROM 0x00083F20
 * Callees: none
 */
/*
 *  8015CD40: addiu       $sp, $sp, -0x30
 *  8015CD44: sw          $s0, 0x18($sp)
 *  8015CD48: addu        $s0, $a0, $zero
 *  8015CD4C: sw          $s2, 0x20($sp)
 *  8015CD50: addu        $s2, $a1, $zero
 *  8015CD54: sw          $ra, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_launch_OnUpdate);

/*
 * func_8015D304_844E4
 * VRAM 0x8015D304, ROM 0x000844E4
 * Callees: none
 */
/*
 *  8015D304: addu        $a1, $a0, $zero
 *  8015D308: addiu       $v0, $zero, -0x801
 *  8015D30C: lw          $v1, 0x10($a1)
 *  8015D310: lw          $a0, 0x11C($a1)
 *  8015D314: and         $v1, $v1, $v0
 *  8015D318: andi        $a0, $a0, 0x8
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015D304_844E4);

/*
 * func_8015D354_84534
 * VRAM 0x8015D354, ROM 0x00084534
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015D354: lw          $v0, 0x1C($a0)
 *  8015D358: nop
 *  8015D35C: beqz        $v0, . + 4 + (0x30 << 2)
 *  8015D360: addiu       $sp, $sp, -0x8
 *  8015D364: lw          $v0, 0x4($v0)
 *  8015D368: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015D354_84534);

/*
 * func_8015D42C_8460C
 * VRAM 0x8015D42C, ROM 0x0008460C
 * Callees: none
 */
/*
 *  8015D42C: addiu       $sp, $sp, -0x20
 *  8015D430: sw          $s0, 0x10($sp)
 *  8015D434: addu        $s0, $a0, $zero
 *  8015D438: sw          $s1, 0x14($sp)
 *  8015D43C: addu        $s1, $a1, $zero
 *  8015D440: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015D42C_8460C);

/*
 * func_8015D4B0_84690
 * VRAM 0x8015D4B0, ROM 0x00084690
 * Callees: none
 */
/*
 *  8015D4B0: addiu       $sp, $sp, -0x20
 *  8015D4B4: sw          $s2, 0x18($sp)
 *  8015D4B8: addu        $s2, $a0, $zero
 *  8015D4BC: sw          $s1, 0x14($sp)
 *  8015D4C0: addu        $s1, $a1, $zero
 *  8015D4C4: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015D4B0_84690);

/*
 * circuit_follow_OnCreate
 * VRAM 0x8015D574, ROM 0x00084754
 * Callees: none
 */
/*
 *  8015D574: addu        $a1, $a0, $zero
 *  8015D578: lw          $v0, 0x1C($a1)
 *  8015D57C: nop
 *  8015D580: lw          $v0, 0x1C($v0)
 *  8015D584: nop
 *  8015D588: andi        $v0, $v0, 0x80
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_follow_OnCreate);

/*
 * circuit_follow_OnUpdate
 * VRAM 0x8015D5C4, ROM 0x000847A4
 * Callees: none
 */
/*
 *  8015D5C4: addiu       $sp, $sp, -0x20
 *  8015D5C8: sw          $s0, 0x10($sp)
 *  8015D5CC: addu        $s0, $a0, $zero
 *  8015D5D0: sw          $ra, 0x18($sp)
 *  8015D5D4: sw          $s1, 0x14($sp)
 *  8015D5D8: lw          $v0, 0x1C($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_follow_OnUpdate);

/*
 * circuit_follow_OnCollide
 * VRAM 0x8015D6E8, ROM 0x000848C8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: SIGNAL_HandleSignal
 */
/*
 *  8015D6E8: lw          $v0, 0xFC($a0)
 *  8015D6EC: nop
 *  8015D6F0: bnez        $v0, . + 4 + (0x21 << 2)
 *  8015D6F4: addiu       $v1, $zero, 0x1E
 *  8015D6F8: lw          $v0, 0x1C($a0)
 *  8015D6FC: sw          $v1, 0xFC($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_follow_OnCollide);

/*
 * func_8015D780_84960
 * VRAM 0x8015D780, ROM 0x00084960
 * Callees: SIGNAL_HandleSignal
 */
/*
 *  8015D780: addiu       $sp, $sp, -0x18
 *  8015D784: sw          $ra, 0x10($sp)
 *  8015D788: lw          $v1, 0x24($a0)
 *  8015D78C: nop
 *  8015D790: beqz        $v1, . + 4 + (0xE << 2)
 *  8015D794: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015D780_84960);

/*
 * func_8015D7F0_849D0
 * VRAM 0x8015D7F0, ROM 0x000849D0
 * Callees: INSTANCE_BirthCachedObject
 */
/*
 *  8015D7F0: addiu       $sp, $sp, -0x20
 *  8015D7F4: sw          $s1, 0x14($sp)
 *  8015D7F8: addu        $s1, $a0, $zero
 *  8015D7FC: sw          $ra, 0x1C($sp)
 *  8015D800: sw          $s2, 0x18($sp)
 *  8015D804: sw          $s0, 0x10($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015D7F0_849D0);

/*
 * circuit_pball_OnUpdate
 * VRAM 0x8015D958, ROM 0x00084B38
 * Callees: SplineGetNextPoint, 0x8015DD58, INSTANCE_KillInstance, 0x800515B4
 */
/*
 *  8015D958: addiu       $sp, $sp, -0x38
 *  8015D95C: sw          $s0, 0x18($sp)
 *  8015D960: addu        $s0, $a0, $zero
 *  8015D964: sw          $ra, 0x30($sp)
 *  8015D968: sw          $s5, 0x2C($sp)
 *  8015D96C: sw          $s4, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_pball_OnUpdate);

/*
 * circuit_pball_OnCollide
 * VRAM 0x8015DAF8, ROM 0x00084CD8
 * Callees: none
 */
/*
 *  8015DAF8: addiu       $sp, $sp, -0x18
 *  8015DAFC: sw          $s0, 0x10($sp)
 *  8015DB00: addu        $s0, $a0, $zero
 *  8015DB04: sw          $ra, 0x14($sp)
 *  8015DB08: lw          $a0, 0x78($s0)
 *  8015DB0C: lw          $v0, 0xC($a1)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_pball_OnCollide);

/*
 * func_8015DB80_84D60
 * VRAM 0x8015DB80, ROM 0x00084D60
 * Callees: none
 */
/*
 *  8015DB80: addiu       $sp, $sp, -0x8
 *  8015DB84: lw          $v0, 0x1C($a0)
 *  8015DB88: addu        $t0, $zero, $zero
 *  8015DB8C: lw          $a0, 0x4($v0)
 *  8015DB90: addu        $a2, $zero, $zero
 *  8015DB94: lw          $v0, 0x4($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015DB80_84D60);

/*
 * circuit_ppath_OnCreate
 * VRAM 0x8015DC8C, ROM 0x00084E6C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015DC8C: lw          $v1, 0x18($a0)
 *  8015DC90: lh          $v0, 0xC2($a0)
 *  8015DC94: sh          $zero, 0x56($a0)
 *  8015DC98: lw          $v1, 0xC($v1)
 *  8015DC9C: sll         $v0, $v0, 2
 *  8015DCA0: addu        $v0, $v0, $v1
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ppath_OnCreate);

/*
 * func_8015DD58_84F38
 * VRAM 0x8015DD58, ROM 0x00084F38
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015DD58: lw          $v0, 0xF4($a0)
 *  8015DD5C: addiu       $v1, $zero, 0x2
 *  8015DD60: beq         $v0, $v1, . + 4 + (0x3 << 2)
 *  8015DD64: nop
 *  8015DD68: j           func_8015DDB0
 *  8015DD6C: sw          $v1, 0xF4($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015DD58_84F38);

/*
 * circuit_ppath_OnUpdate
 * VRAM 0x8015DDB8, ROM 0x00084F98
 * Callees: none
 */
/*
 *  8015DDB8: addiu       $sp, $sp, -0x28
 *  8015DDBC: sw          $s0, 0x10($sp)
 *  8015DDC0: addu        $s0, $a0, $zero
 *  8015DDC4: sw          $s4, 0x20($sp)
 *  8015DDC8: sw          $ra, 0x24($sp)
 *  8015DDCC: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ppath_OnUpdate);

/*
 * circuit_ppath_OnCollide
 * VRAM 0x8015DF40, ROM 0x00085120
 * Callees: GenericCollide
 */
/*
 *  8015DF40: addiu       $sp, $sp, -0x18
 *  8015DF44: sw          $ra, 0x10($sp)
 *  8015DF48: lw          $v0, 0x18($a0)
 *  8015DF4C: nop
 *  8015DF50: lw          $v0, 0x0($v0)
 *  8015DF54: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_ppath_OnCollide);

/*
 * circuit_fxgen_OnCreate
 * VRAM 0x8015DF7C, ROM 0x0008515C
 * Callees: 0x8006A020, 0x800331BC, OBTABLE_FindObject
 */
/*
 *  8015DF7C: addiu       $sp, $sp, -0x20
 *  8015DF80: sw          $s0, 0x10($sp)
 *  8015DF84: addu        $s0, $a0, $zero
 *  8015DF88: sw          $s2, 0x18($sp)
 *  8015DF8C: sw          $ra, 0x1C($sp)
 *  8015DF90: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_fxgen_OnCreate);

/*
 * func_8015E084_85264
 * VRAM 0x8015E084, ROM 0x00085264
 * Callees: none
 */
/*
 *  8015E084: addiu       $sp, $sp, -0x20
 *  8015E088: sw          $s0, 0x10($sp)
 *  8015E08C: addu        $s0, $a0, $zero
 *  8015E090: sw          $ra, 0x18($sp)
 *  8015E094: sw          $s1, 0x14($sp)
 *  8015E098: lhu         $v0, 0x46($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015E084_85264);

/*
 * func_8015E140_85320
 * VRAM 0x8015E140, ROM 0x00085320
 * Callees: 0x8006A020
 */
/*
 *  8015E140: addiu       $sp, $sp, -0x88
 *  8015E144: sw          $s4, 0x78($sp)
 *  8015E148: addu        $s4, $a0, $zero
 *  8015E14C: sw          $ra, 0x80($sp)
 *  8015E150: sw          $s5, 0x7C($sp)
 *  8015E154: sw          $s3, 0x74($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015E140_85320);

/*
 * circuit_fxgen_OnUpdate
 * VRAM 0x8015E764, ROM 0x00085944
 * Callees: none
 */
/*
 *  8015E764: addiu       $sp, $sp, -0x48
 *  8015E768: sw          $s3, 0x34($sp)
 *  8015E76C: addu        $s3, $a0, $zero
 *  8015E770: sw          $ra, 0x40($sp)
 *  8015E774: sw          $s5, 0x3C($sp)
 *  8015E778: sw          $s4, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_fxgen_OnUpdate);

/*
 * func_8015EC00_85DE0
 * VRAM 0x8015EC00, ROM 0x00085DE0
 * Callees: none
 */
/*
 *  8015EC00: addiu       $sp, $sp, -0x38
 *  8015EC04: sw          $s0, 0x18($sp)
 *  8015EC08: addu        $s0, $a0, $zero
 *  8015EC0C: addiu       $a1, $sp, 0x10
 *  8015EC10: sw          $ra, 0x34($sp)
 *  8015EC14: sw          $s6, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015EC00_85DE0);

/*
 * circuit_reza_OnCreate
 * VRAM 0x8015EE58, ROM 0x00086038
 * Callees: none
 */
/*
 *  8015EE58: addiu       $sp, $sp, -0x20
 *  8015EE5C: sw          $s0, 0x10($sp)
 *  8015EE60: addu        $s0, $a0, $zero
 *  8015EE64: lui         $v1, 0x10
 *  8015EE68: sw          $ra, 0x1C($sp)
 *  8015EE6C: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_reza_OnCreate);

/*
 * circuit_reza_OnUpdate
 * VRAM 0x8015EFD0, ROM 0x000861B0
 * Callees: strcmp
 */
/*
 *  8015EFD0: addiu       $sp, $sp, -0x88
 *  8015EFD4: sw          $s1, 0x6C($sp)
 *  8015EFD8: addu        $s1, $a0, $zero
 *  8015EFDC: sw          $s4, 0x78($sp)
 *  8015EFE0: addu        $s4, $a1, $zero
 *  8015EFE4: lui         $a1, 0x8016
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_reza_OnUpdate);

/*
 * circuit_reza_OnCollide
 * VRAM 0x8015F628, ROM 0x00086808
 * Callees: 0x8004A7B8
 */
/*
 *  8015F628: addiu       $sp, $sp, -0x20
 *  8015F62C: sw          $ra, 0x18($sp)
 *  8015F630: lw          $a2, 0x78($a0)
 *  8015F634: lw          $v0, 0xC($a1)
 *  8015F638: lw          $v1, 0x14($a2)
 *  8015F63C: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_reza_OnCollide);

/*
 * func_8015F6B8_86898
 * VRAM 0x8015F6B8, ROM 0x00086898
 * Callees: none
 */
/*
 *  8015F6B8: addiu       $sp, $sp, -0x18
 *  8015F6BC: addiu       $v0, $zero, 0x1
 *  8015F6C0: sw          $ra, 0x10($sp)
 *  8015F6C4: sw          $v0, 0xF4($a0)
 *  8015F6C8: addiu       $v0, $zero, 0x2
 *  8015F6CC: sw          $v0, 0xF8($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015F6B8_86898);

/*
 * func_8015F708_868E8
 * VRAM 0x8015F708, ROM 0x000868E8
 * Callees: none
 */
/*
 *  8015F708: addiu       $v0, $zero, 0x5
 *  8015F70C: sw          $v0, 0xF4($a0)
 *  8015F710: addiu       $v0, $zero, 0x7
 *  8015F714: sb          $v0, 0x4E($a0)
 *  8015F718: jr          $ra
 *  8015F71C: sh          $zero, 0x5E($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015F708_868E8);

/*
 * func_8015F720_86900
 * VRAM 0x8015F720, ROM 0x00086900
 * Callees: none
 */
/*
 *  8015F720: addu        $a1, $a0, $zero
 *  8015F724: lw          $v0, 0xFC($a1)
 *  8015F728: nop
 *  8015F72C: bnez        $v0, . + 4 + (0x9 << 2)
 *  8015F730: nop
 *  8015F734: lw          $a0, 0xF8($a1)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015F720_86900);

/*
 * func_8015F75C_8693C
 * VRAM 0x8015F75C, ROM 0x0008693C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F75C: lhu         $v0, 0xFE($a0)
 *  8015F760: lbu         $v1, 0xFD($a0)
 *  8015F764: lb          $a1, 0xFC($a0)
 *  8015F768: sh          $zero, 0x5E($a0)
 *  8015F76C: sw          $zero, 0xFC($a0)
 *  8015F770: sw          $v0, 0xF4($a0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015F75C_8693C);

/*
 * func_8015F780_86960
 * VRAM 0x8015F780, ROM 0x00086960
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F780: bltz        $a1, . + 4 + (0x9 << 2)
 *  8015F784: addu        $v1, $zero, $zero
 *  8015F788: lw          $v0, 0x0($a0)
 *  8015F78C: nop
 *  8015F790: addu        $v1, $v1, $v0
 *  8015F794: slt         $v0, $a1, $v1
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015F780_86960);

/*
 * circuit_robo_OnCreate
 * VRAM 0x8015F7B0, ROM 0x00086990
 * Callees: none
 */
/*
 *  8015F7B0: addiu       $sp, $sp, -0x38
 *  8015F7B4: sw          $s0, 0x18($sp)
 *  8015F7B8: addu        $s0, $a0, $zero
 *  8015F7BC: sw          $s4, 0x28($sp)
 *  8015F7C0: addu        $s4, $zero, $zero
 *  8015F7C4: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_robo_OnCreate);

/*
 * func_8015F930_86B10
 * VRAM 0x8015F930, ROM 0x00086B10
 * Callees: none
 */
/*
 *  8015F930: addiu       $sp, $sp, -0x18
 *  8015F934: sw          $s0, 0x10($sp)
 *  8015F938: addu        $s0, $a2, $zero
 *  8015F93C: sw          $ra, 0x14($sp)
 *  8015F940: lw          $v1, 0x4($a1)
 *  8015F944: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015F930_86B10);

/*
 * func_8015FA1C_86BFC
 * VRAM 0x8015FA1C, ROM 0x00086BFC
 * Callees: none
 */
/*
 *  8015FA1C: addiu       $sp, $sp, -0x28
 *  8015FA20: sw          $s1, 0x1C($sp)
 *  8015FA24: addu        $s1, $a0, $zero
 *  8015FA28: sw          $ra, 0x24($sp)
 *  8015FA2C: sw          $s2, 0x20($sp)
 *  8015FA30: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015FA1C_86BFC);

/*
 * func_8015FAC4_86CA4
 * VRAM 0x8015FAC4, ROM 0x00086CA4
 * Callees: 0x8015F780
 */
/*
 *  8015FAC4: addiu       $sp, $sp, -0x38
 *  8015FAC8: sw          $s2, 0x30($sp)
 *  8015FACC: addu        $s2, $a0, $zero
 *  8015FAD0: sw          $ra, 0x34($sp)
 *  8015FAD4: sw          $s1, 0x2C($sp)
 *  8015FAD8: sw          $s0, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015FAC4_86CA4);

/*
 * func_8015FC70_86E50
 * VRAM 0x8015FC70, ROM 0x00086E50
 * Callees: none
 */
/*
 *  8015FC70: addiu       $sp, $sp, -0x18
 *  8015FC74: sw          $s0, 0x10($sp)
 *  8015FC78: addu        $s0, $a0, $zero
 *  8015FC7C: sw          $ra, 0x14($sp)
 *  8015FC80: lw          $t0, 0x1C($s0)
 *  8015FC84: lh          $v1, 0x110($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_8015FC70_86E50);

/*
 * circuit_robo_OnUpdate
 * VRAM 0x8015FD38, ROM 0x00086F18
 * Callees: 0x8015F75C, 0x8002DAF8, INSTANCE_BirthCachedObject, 0x8004A820
 */
/*
 *  8015FD38: addiu       $sp, $sp, -0x48
 *  8015FD3C: sw          $s0, 0x28($sp)
 *  8015FD40: addu        $s0, $a0, $zero
 *  8015FD44: sw          $s5, 0x3C($sp)
 *  8015FD48: addu        $s5, $a1, $zero
 *  8015FD4C: sw          $s1, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_robo_OnUpdate);

/*
 * circuit_robo_OnCollide
 * VRAM 0x8016025C, ROM 0x0008743C
 * Callees: 0x8015F720, 0x80025798, 0x80027500, 0x80027578
 */
/*
 *  8016025C: addiu       $sp, $sp, -0x28
 *  80160260: sw          $s0, 0x10($sp)
 *  80160264: addu        $s0, $a0, $zero
 *  80160268: sw          $s2, 0x18($sp)
 *  8016026C: addu        $s2, $a1, $zero
 *  80160270: sw          $ra, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_robo_OnCollide);

/*
 * circuit_bomb_OnCreate
 * VRAM 0x80160404, ROM 0x000875E4
 * Callees: none
 */
/*
 *  80160404: addiu       $sp, $sp, -0x30
 *  80160408: sw          $s0, 0x20($sp)
 *  8016040C: addu        $s0, $a0, $zero
 *  80160410: sw          $ra, 0x2C($sp)
 *  80160414: sw          $s2, 0x28($sp)
 *  80160418: sw          $s1, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_bomb_OnCreate);

/*
 * circuit_bomb_OnUpdate
 * VRAM 0x80160554, ROM 0x00087734
 * Callees: none
 */
/*
 *  80160554: addiu       $sp, $sp, -0x30
 *  80160558: sw          $s0, 0x18($sp)
 *  8016055C: addu        $s0, $a0, $zero
 *  80160560: addu        $a2, $a1, $zero
 *  80160564: sw          $s1, 0x1C($sp)
 *  80160568: sw          $ra, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_bomb_OnUpdate);

/*
 * circuit_explode_OnCreate
 * VRAM 0x8016094C, ROM 0x00087B2C
 * Callees: none
 */
/*
 *  8016094C: addiu       $sp, $sp, -0x38
 *  80160950: sw          $s0, 0x28($sp)
 *  80160954: addu        $s0, $a0, $zero
 *  80160958: sw          $ra, 0x30($sp)
 *  8016095C: sw          $s1, 0x2C($sp)
 *  80160960: lw          $v1, 0x18($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_explode_OnCreate);

/*
 * circuit_explode_OnUpdate
 * VRAM 0x80160A80, ROM 0x00087C60
 * Callees: 0x80033200, 0x800506B8, INSTANCE_KillInstance
 */
/*
 *  80160A80: addiu       $sp, $sp, -0x28
 *  80160A84: sw          $s0, 0x18($sp)
 *  80160A88: addu        $s0, $a0, $zero
 *  80160A8C: sw          $ra, 0x20($sp)
 *  80160A90: sw          $s1, 0x1C($sp)
 *  80160A94: lw          $a0, 0x100($s0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_explode_OnUpdate);

/*
 * circuit_explode_OnCollide
 * VRAM 0x80160B30, ROM 0x00087D10
 * Callees: none
 */
/*
 *  80160B30: addiu       $sp, $sp, -0x18
 *  80160B34: sw          $ra, 0x10($sp)
 *  80160B38: lw          $a2, 0x78($a0)
 *  80160B3C: lw          $v0, 0xC($a1)
 *  80160B40: lw          $v1, 0x14($a2)
 *  80160B44: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_explode_OnCollide);

/*
 * circuit_pulse_OnCreate
 * VRAM 0x80160B78, ROM 0x00087D58
 * Callees: none
 */
/*
 *  80160B78: addiu       $sp, $sp, -0x20
 *  80160B7C: addu        $t1, $a0, $zero
 *  80160B80: lw          $a0, 0x24($t1)
 *  80160B84: addu        $v1, $zero, $zero
 *  80160B88: lw          $v0, 0x0($a0)
 *  80160B8C: nop
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_pulse_OnCreate);

/*
 * func_80160D80_87F60
 * VRAM 0x80160D80, ROM 0x00087F60
 * Callees: none
 */
/*
 *  80160D80: addiu       $sp, $sp, -0x8
 *  80160D84: addu        $t6, $a0, $zero
 *  80160D88: addiu       $t3, $zero, -0x1
 *  80160D8C: addiu       $t2, $zero, 0x2
 *  80160D90: lw          $t4, 0x18($sp)
 *  80160D94: addiu       $a1, $a1, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_80160D80_87F60);

/*
 * circuit_pulse_OnUpdate
 * VRAM 0x80160EE0, ROM 0x000880C0
 * Callees: none
 */
/*
 *  80160EE0: addiu       $sp, $sp, -0x60
 *  80160EE4: sw          $s2, 0x58($sp)
 *  80160EE8: addu        $s2, $a0, $zero
 *  80160EEC: sw          $s0, 0x50($sp)
 *  80160EF0: addu        $s0, $a1, $zero
 *  80160EF4: sw          $ra, 0x5C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_pulse_OnUpdate);

/*
 * circuit_pulse_OnCollide
 * VRAM 0x80161434, ROM 0x00088614
 * Callees: none
 */
/*
 *  80161434: addiu       $sp, $sp, -0x48
 *  80161438: sw          $s0, 0x30($sp)
 *  8016143C: addu        $s0, $a0, $zero
 *  80161440: sw          $s2, 0x38($sp)
 *  80161444: sw          $ra, 0x40($sp)
 *  80161448: sw          $s3, 0x3C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_pulse_OnCollide);

/*
 * circuit_resist_OnCreate
 * VRAM 0x80161628, ROM 0x00088808
 * Callees: none
 */
/*
 *  80161628: addiu       $sp, $sp, -0x20
 *  8016162C: addu        $t1, $a0, $zero
 *  80161630: addu        $a3, $zero, $zero
 *  80161634: sw          $ra, 0x1C($sp)
 *  80161638: sw          $s0, 0x18($sp)
 *  8016163C: lw          $v0, 0x20($t1)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_resist_OnCreate);

/*
 * func_801618BC_88A9C
 * VRAM 0x801618BC, ROM 0x00088A9C
 * Callees: 0x80049B80
 */
/*
 *  801618BC: addiu       $sp, $sp, -0x58
 *  801618C0: sw          $s0, 0x48($sp)
 *  801618C4: addu        $s0, $a0, $zero
 *  801618C8: addiu       $v0, $zero, 0xA
 *  801618CC: sw          $ra, 0x50($sp)
 *  801618D0: sw          $s1, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", func_801618BC_88A9C);

/*
 * circuit_resist_OnUpdate
 * VRAM 0x80161E4C, ROM 0x0008902C
 * Callees: 0x80047DF4, 0x8004A820
 */
/*
 *  80161E4C: addiu       $sp, $sp, -0x38
 *  80161E50: sw          $s0, 0x28($sp)
 *  80161E54: addu        $s0, $a0, $zero
 *  80161E58: sw          $s2, 0x30($sp)
 *  80161E5C: addu        $s2, $a1, $zero
 *  80161E60: sw          $ra, 0x34($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_resist_OnUpdate);

/*
 * circuit_resist_OnCollide
 * VRAM 0x80162360, ROM 0x00089540
 * Callees: none
 */
/*
 *  80162360: addiu       $sp, $sp, -0x40
 *  80162364: sw          $s0, 0x20($sp)
 *  80162368: addu        $s0, $a0, $zero
 *  8016236C: sw          $s4, 0x30($sp)
 *  80162370: addu        $s4, $a1, $zero
 *  80162374: sw          $ra, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_resist_OnCollide);

/*
 * circuit_babyres_OnCreate
 * VRAM 0x8016279C, ROM 0x0008997C
 * Callees: none
 */
/*
 *  8016279C: addiu       $sp, $sp, -0x8
 *  801627A0: addu        $a3, $a0, $zero
 *  801627A4: addu        $t0, $zero, $zero
 *  801627A8: lw          $v0, 0x20($a3)
 *  801627AC: lw          $t1, 0x24($a3)
 *  801627B0: lwl         $v1, 0x0($v0)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_babyres_OnCreate);

/*
 * circuit_babyres_OnUpdate
 * VRAM 0x8016294C, ROM 0x00089B2C
 * Callees: none
 */
/*
 *  8016294C: addiu       $sp, $sp, -0x30
 *  80162950: sw          $s0, 0x20($sp)
 *  80162954: addu        $s0, $a0, $zero
 *  80162958: sw          $s2, 0x28($sp)
 *  8016295C: addu        $s2, $a1, $zero
 *  80162960: sw          $ra, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_babyres_OnUpdate);

/*
 * circuit_babyres_OnCollide
 * VRAM 0x80162B2C, ROM 0x00089D0C
 * Callees: 0x8004A7B8, 0x80022714, 0x80049B80, 0x800305FC
 */
/*
 *  80162B2C: addiu       $sp, $sp, -0x60
 *  80162B30: sw          $s0, 0x40($sp)
 *  80162B34: addu        $s0, $a0, $zero
 *  80162B38: sw          $s4, 0x50($sp)
 *  80162B3C: addu        $s4, $a1, $zero
 *  80162B40: sw          $ra, 0x58($sp)
 */
INCLUDE_ASM("asm/nonmatchings/CIRCUIT", circuit_babyres_OnCollide);
