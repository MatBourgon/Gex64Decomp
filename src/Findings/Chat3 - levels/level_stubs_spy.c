/*
 * level_stubs_spy.c — The Spy Who Loved Himself
 * Level overlay: SPY
 * ROM base: 0x0EADF0, VRAM base: 0x80159720
 * Stubs: 11
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/*
 * spy_qsofa_OnUpdate
 * VRAM 0x80159728, ROM 0x000EADF8
 * Callees: none
 */
/*
 *  80159728: addiu       $sp, $sp, -0x20
 *  8015972C: sw          $s0, 0x18($sp)
 *  80159730: addu        $s0, $a0, $zero
 *  80159734: sw          $ra, 0x1C($sp)
 *  80159738: lw          $v1, 0xF4($s0)
 *  8015973C: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/SPY", spy_qsofa_OnUpdate);

/*
 * spy_qsofa_OnCollide
 * VRAM 0x801597E8, ROM 0x000EAEB8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  801597E8: lw          $a1, 0x78($a0)
 *  801597EC: nop
 *  801597F0: lh          $v1, 0x6($a1)
 *  801597F4: addiu       $v0, $zero, 0x4
 *  801597F8: bne         $v1, $v0, . + 4 + (0xC << 2)
 *  801597FC: nop
 */
INCLUDE_ASM("asm/nonmatchings/SPY", spy_qsofa_OnCollide);

/*
 * spy_launch_OnUpdate
 * VRAM 0x80159928, ROM 0x000EAFF8
 * Callees: none
 */
/*
 *  80159928: addiu       $sp, $sp, -0x30
 *  8015992C: sw          $s0, 0x18($sp)
 *  80159930: addu        $s0, $a0, $zero
 *  80159934: sw          $s2, 0x20($sp)
 *  80159938: addu        $s2, $a1, $zero
 *  8015993C: sw          $ra, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SPY", spy_launch_OnUpdate);

/*
 * func_80159EEC_EB5BC
 * VRAM 0x80159EEC, ROM 0x000EB5BC
 * Callees: none
 */
/*
 *  80159EEC: addu        $a1, $a0, $zero
 *  80159EF0: addiu       $v0, $zero, -0x801
 *  80159EF4: lw          $v1, 0x10($a1)
 *  80159EF8: lw          $a0, 0x11C($a1)
 *  80159EFC: and         $v1, $v1, $v0
 *  80159F00: andi        $a0, $a0, 0x8
 */
INCLUDE_ASM("asm/nonmatchings/SPY", func_80159EEC_EB5BC);

/*
 * func_80159F3C_EB60C
 * VRAM 0x80159F3C, ROM 0x000EB60C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159F3C: lw          $v0, 0x1C($a0)
 *  80159F40: nop
 *  80159F44: beqz        $v0, . + 4 + (0x30 << 2)
 *  80159F48: addiu       $sp, $sp, -0x8
 *  80159F4C: lw          $v0, 0x4($v0)
 *  80159F50: nop
 */
INCLUDE_ASM("asm/nonmatchings/SPY", func_80159F3C_EB60C);

/*
 * func_8015A014_EB6E4
 * VRAM 0x8015A014, ROM 0x000EB6E4
 * Callees: none
 */
/*
 *  8015A014: addiu       $sp, $sp, -0x20
 *  8015A018: sw          $s0, 0x10($sp)
 *  8015A01C: addu        $s0, $a0, $zero
 *  8015A020: sw          $s1, 0x14($sp)
 *  8015A024: addu        $s1, $a1, $zero
 *  8015A028: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SPY", func_8015A014_EB6E4);

/*
 * func_8015A098_EB768
 * VRAM 0x8015A098, ROM 0x000EB768
 * Callees: 0x80159EEC
 */
/*
 *  8015A098: addiu       $sp, $sp, -0x20
 *  8015A09C: sw          $s2, 0x18($sp)
 *  8015A0A0: addu        $s2, $a0, $zero
 *  8015A0A4: sw          $s1, 0x14($sp)
 *  8015A0A8: addu        $s1, $a1, $zero
 *  8015A0AC: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SPY", func_8015A098_EB768);

/*
 * spy_onoff_OnCollide
 * VRAM 0x8015A364, ROM 0x000EBA34
 * Callees: none
 */
/*
 *  8015A364: addiu       $sp, $sp, -0x18
 *  8015A368: addu        $t2, $zero, $zero
 *  8015A36C: addu        $t6, $zero, $zero
 *  8015A370: addu        $t3, $zero, $zero
 *  8015A374: sw          $ra, 0x10($sp)
 *  8015A378: lw          $a3, 0x24($a0)
 */
INCLUDE_ASM("asm/nonmatchings/SPY", spy_onoff_OnCollide);

/*
 * spy_gnrobot_OnCreate
 * VRAM 0x8015A5E4, ROM 0x000EBCB4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015A5E4: lw          $v0, 0x24($a0)
 *  8015A5E8: nop
 *  8015A5EC: bnez        $v0, . + 4 + (0x6 << 2)
 *  8015A5F0: nop
 *  8015A5F4: lui         $v0, 0x8016
 *  8015A5F8: addiu       $v0, $v0, -0x5290
 */
INCLUDE_ASM("asm/nonmatchings/SPY", spy_gnrobot_OnCreate);

/*
 * spy_gnrobot_OnUpdate
 * VRAM 0x8015A618, ROM 0x000EBCE8
 * Callees: none
 */
/*
 *  8015A618: addiu       $sp, $sp, -0x28
 *  8015A61C: sw          $s0, 0x18($sp)
 *  8015A620: addu        $s0, $a0, $zero
 *  8015A624: addu        $a1, $zero, $zero
 *  8015A628: sw          $ra, 0x20($sp)
 *  8015A62C: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SPY", spy_gnrobot_OnUpdate);

/*
 * spy_gnrobot_OnCollide
 * VRAM 0x8015A704, ROM 0x000EBDD4
 * Callees: none
 */
/*
 *  8015A704: addiu       $sp, $sp, -0x18
 *  8015A708: sw          $ra, 0x10($sp)
 *  8015A70C: lw          $a2, 0x78($a0)
 *  8015A710: lui         $v0, 0x8007
 *  8015A714: lw          $v0, -0x3060($v0)
 *  8015A718: lw          $v1, 0x14($a2)
 */
INCLUDE_ASM("asm/nonmatchings/SPY", spy_gnrobot_OnCollide);
