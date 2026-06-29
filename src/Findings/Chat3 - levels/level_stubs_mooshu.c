/*
 * level_stubs_mooshu.c — Mooshoo Pork
 * Level overlay: MOOSHU
 * ROM base: 0x0C20A0, VRAM base: 0x80159720
 * Stubs: 53
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/*
 * func_80159720_C20A0
 * VRAM 0x80159720, ROM 0x000C20A0
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159720: lh          $v1, 0x0($a2)
 *  80159724: nop
 *  80159728: slti        $v0, $v1, 0x201
 *  8015972C: bnez        $v0, . + 4 + (0xC << 2)
 *  80159730: slti        $v0, $v1, -0x480
 *  80159734: lh          $a2, 0x2($a2)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_80159720_C20A0);

/*
 * func_80159798_C2118
 * VRAM 0x80159798, ROM 0x000C2118
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159798: lui         $t2, 0x8007
 *  8015979C: lw          $t2, -0x338($t2)
 *  801597A0: addiu       $sp, $sp, -0x30
 *  801597A4: sw          $s0, 0x20($sp)
 *  801597A8: addu        $s0, $a0, $zero
 *  801597AC: sw          $s1, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_80159798_C2118);

/*
 * func_801599E8_C2368
 * VRAM 0x801599E8, ROM 0x000C2368
 * Callees: none
 */
/*
 *  801599E8: addiu       $sp, $sp, -0x30
 *  801599EC: sw          $s0, 0x18($sp)
 *  801599F0: addu        $s0, $a0, $zero
 *  801599F4: sw          $s2, 0x20($sp)
 *  801599F8: addu        $s2, $a1, $zero
 *  801599FC: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_801599E8_C2368);

/*
 * func_80159B78_C24F8
 * VRAM 0x80159B78, ROM 0x000C24F8
 * Callees: none
 */
/*
 *  80159B78: addiu       $sp, $sp, -0x38
 *  80159B7C: sw          $s5, 0x2C($sp)
 *  80159B80: addu        $s5, $a1, $zero
 *  80159B84: lui         $a1, 0x8007
 *  80159B88: lw          $a1, -0x338($a1)
 *  80159B8C: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_80159B78_C24F8);

/*
 * func_80159D0C_C268C
 * VRAM 0x80159D0C, ROM 0x000C268C
 * Callees: none
 */
/*
 *  80159D0C: addiu       $sp, $sp, -0x20
 *  80159D10: sw          $s1, 0x14($sp)
 *  80159D14: addu        $s1, $a0, $zero
 *  80159D18: lui         $a0, 0x5555
 *  80159D1C: sw          $s0, 0x10($sp)
 *  80159D20: addu        $s0, $a3, $zero
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_80159D0C_C268C);

/*
 * func_80159EC4_C2844
 * VRAM 0x80159EC4, ROM 0x000C2844
 * Callees: none
 */
/*
 *  80159EC4: addiu       $sp, $sp, -0x20
 *  80159EC8: sw          $s1, 0x14($sp)
 *  80159ECC: addu        $s1, $a0, $zero
 *  80159ED0: sw          $s0, 0x10($sp)
 *  80159ED4: sw          $ra, 0x1C($sp)
 *  80159ED8: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_80159EC4_C2844);

/*
 * func_8015A084_C2A04
 * VRAM 0x8015A084, ROM 0x000C2A04
 * Callees: none
 */
/*
 *  8015A084: addiu       $sp, $sp, -0x20
 *  8015A088: sw          $s0, 0x10($sp)
 *  8015A08C: addu        $s0, $a0, $zero
 *  8015A090: addu        $t0, $a1, $zero
 *  8015A094: sw          $s1, 0x14($sp)
 *  8015A098: sw          $ra, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015A084_C2A04);

/*
 * func_8015A150_C2AD0
 * VRAM 0x8015A150, ROM 0x000C2AD0
 * Callees: none
 */
/*
 *  8015A150: addiu       $sp, $sp, -0x18
 *  8015A154: sw          $ra, 0x10($sp)
 *  8015A158: lw          $v0, 0x14($a0)
 *  8015A15C: nop
 *  8015A160: andi        $v0, $v0, 0x10
 *  8015A164: beqz        $v0, . + 4 + (0x5 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015A150_C2AD0);

/*
 * func_8015A18C_C2B0C
 * VRAM 0x8015A18C, ROM 0x000C2B0C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015A18C: lw          $v0, 0x14($a0)
 *  8015A190: nop
 *  8015A194: andi        $v0, $v0, 0x10
 *  8015A198: bnez        $v0, . + 4 + (0x3 << 2)
 *  8015A19C: lui         $a1, 0xFEFF
 *  8015A1A0: j           func_8015A1D8
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015A18C_C2B0C);

/*
 * func_8015A1E0_C2B60
 * VRAM 0x8015A1E0, ROM 0x000C2B60
 * Callees: 0x8015B9D0, 0x8015BB44, 0x8004ACB0
 */
/*
 *  8015A1E0: addiu       $sp, $sp, -0x28
 *  8015A1E4: sw          $s0, 0x18($sp)
 *  8015A1E8: addu        $s0, $a0, $zero
 *  8015A1EC: sw          $s1, 0x1C($sp)
 *  8015A1F0: addu        $s1, $a3, $zero
 *  8015A1F4: addu        $a1, $s1, $zero
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015A1E0_C2B60);

/*
 * func_8015A258_C2BD8
 * VRAM 0x8015A258, ROM 0x000C2BD8
 * Callees: none
 */
/*
 *  8015A258: addiu       $sp, $sp, -0x18
 *  8015A25C: sw          $ra, 0x14($sp)
 *  8015A260: sw          $s0, 0x10($sp)
 *  8015A264: lw          $s0, 0x8($a2)
 *  8015A268: lhu         $v0, 0x0($a0)
 *  8015A26C: nop
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015A258_C2BD8);

/*
 * func_8015A2E0_C2C60
 * VRAM 0x8015A2E0, ROM 0x000C2C60
 * Callees: none
 */
/*
 *  8015A2E0: addiu       $sp, $sp, -0x18
 *  8015A2E4: sw          $ra, 0x10($sp)
 *  8015A2E8: lwl         $v0, 0x0($a1)
 *  8015A2EC: lwr         $v0, 0x3($a1)
 *  8015A2F0: lh          $v1, 0x4($a1)
 *  8015A2F4: swl         $v0, 0x0($a0)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015A2E0_C2C60);

/*
 * mooshu_moo_OnCreate
 * VRAM 0x8015A3A4, ROM 0x000C2D24
 * Callees: none
 */
/*
 *  8015A3A4: addiu       $sp, $sp, -0x28
 *  8015A3A8: sw          $s2, 0x18($sp)
 *  8015A3AC: addu        $s2, $a0, $zero
 *  8015A3B0: sw          $s3, 0x1C($sp)
 *  8015A3B4: addu        $s3, $a1, $zero
 *  8015A3B8: lui         $v0, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moo_OnCreate);

/*
 * mooshu_moo_OnUpdate
 * VRAM 0x8015A5C0, ROM 0x000C2F40
 * Callees: none
 */
/*
 *  8015A5C0: addiu       $sp, $sp, -0xA8
 *  8015A5C4: sw          $s4, 0x90($sp)
 *  8015A5C8: addu        $s4, $a0, $zero
 *  8015A5CC: sw          $ra, 0xA4($sp)
 *  8015A5D0: sw          $fp, 0xA0($sp)
 *  8015A5D4: sw          $s7, 0x9C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moo_OnUpdate);

/*
 * mooshu_moobar_OnCreate
 * VRAM 0x8015B13C, ROM 0x000C3ABC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B13C: lui         $v1, 0x10
 *  8015B140: lw          $v0, 0x10($a0)
 *  8015B144: ori         $v1, $v1, 0xC00
 *  8015B148: sw          $zero, 0x1C($a0)
 *  8015B14C: or          $v0, $v0, $v1
 *  8015B150: addiu       $v1, $zero, -0x2
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moobar_OnCreate);

/*
 * mooshu_moobar_OnCollide
 * VRAM 0x8015B160, ROM 0x000C3AE0
 * Callees: none
 */
/*
 *  8015B160: addiu       $sp, $sp, -0x18
 *  8015B164: sw          $ra, 0x14($sp)
 *  8015B168: sw          $s0, 0x10($sp)
 *  8015B16C: lw          $v0, 0x28($a0)
 *  8015B170: nop
 *  8015B174: beqz        $v0, . + 4 + (0x10 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moobar_OnCollide);

/*
 * mooshu_moo_OnCollide
 * VRAM 0x8015B1C8, ROM 0x000C3B48
 * Callees: 0x80022714, 0x80022780
 */
/*
 *  8015B1C8: addiu       $sp, $sp, -0x20
 *  8015B1CC: sw          $s2, 0x18($sp)
 *  8015B1D0: addu        $s2, $a1, $zero
 *  8015B1D4: sw          $ra, 0x1C($sp)
 *  8015B1D8: sw          $s1, 0x14($sp)
 *  8015B1DC: sw          $s0, 0x10($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moo_OnCollide);

/*
 * func_8015B2FC_C3C7C
 * VRAM 0x8015B2FC, ROM 0x000C3C7C
 * Callees: none
 */
/*
 *  8015B2FC: addiu       $sp, $sp, -0x20
 *  8015B300: sw          $ra, 0x18($sp)
 *  8015B304: lbu         $v0, 0x4E($a0)
 *  8015B308: nop
 *  8015B30C: bnez        $v0, . + 4 + (0x1F << 2)
 *  8015B310: addu        $a3, $a2, $zero
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B2FC_C3C7C);

/*
 * func_8015B39C_C3D1C
 * VRAM 0x8015B39C, ROM 0x000C3D1C
 * Callees: none
 */
/*
 *  8015B39C: addiu       $sp, $sp, -0x28
 *  8015B3A0: sw          $s2, 0x20($sp)
 *  8015B3A4: addu        $s2, $a0, $zero
 *  8015B3A8: sw          $s1, 0x1C($sp)
 *  8015B3AC: addu        $s1, $a3, $zero
 *  8015B3B0: addiu       $a1, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B39C_C3D1C);

/*
 * func_8015B4D4_C3E54
 * VRAM 0x8015B4D4, ROM 0x000C3E54
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B4D4: lhu         $v0, 0x40($a1)
 *  8015B4D8: nop
 *  8015B4DC: addiu       $v0, $v0, -0x1
 *  8015B4E0: sh          $v0, 0x40($a1)
 *  8015B4E4: addiu       $v0, $zero, 0x2
 *  8015B4E8: sb          $v0, 0x4E($a0)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B4D4_C3E54);

/*
 * func_8015B510_C3E90
 * VRAM 0x8015B510, ROM 0x000C3E90
 * Callees: 0x8015B9D0
 */
/*
 *  8015B510: addiu       $sp, $sp, -0x28
 *  8015B514: sw          $s1, 0x1C($sp)
 *  8015B518: addu        $s1, $a0, $zero
 *  8015B51C: sw          $s0, 0x18($sp)
 *  8015B520: addu        $s0, $a1, $zero
 *  8015B524: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B510_C3E90);

/*
 * func_8015B5C0_C3F40
 * VRAM 0x8015B5C0, ROM 0x000C3F40
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B5C0: lui         $v0, 0x8007
 *  8015B5C4: lw          $v0, -0x338($v0)
 *  8015B5C8: nop
 *  8015B5CC: lw          $v0, 0xC($v0)
 *  8015B5D0: nop
 *  8015B5D4: lh          $v0, 0x4A($v0)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B5C0_C3F40);

/*
 * func_8015B5F0_C3F70
 * VRAM 0x8015B5F0, ROM 0x000C3F70
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B5F0: lw          $v0, 0x14($a0)
 *  8015B5F4: addiu       $v1, $zero, -0x11
 *  8015B5F8: sb          $zero, 0x4E($a0)
 *  8015B5FC: sh          $zero, 0x5E($a0)
 *  8015B600: and         $v0, $v0, $v1
 *  8015B604: sw          $v0, 0x14($a0)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B5F0_C3F70);

/*
 * func_8015B614_C3F94
 * VRAM 0x8015B614, ROM 0x000C3F94
 * Callees: none
 */
/*
 *  8015B614: addiu       $sp, $sp, -0x18
 *  8015B618: addiu       $v0, $zero, 0x4
 *  8015B61C: sw          $ra, 0x10($sp)
 *  8015B620: sb          $v0, 0x4E($a0)
 *  8015B624: lw          $v0, 0x14($a0)
 *  8015B628: addiu       $v1, $zero, -0x11
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B614_C3F94);

/*
 * func_8015B674_C3FF4
 * VRAM 0x8015B674, ROM 0x000C3FF4
 * Callees: none
 */
/*
 *  8015B674: addiu       $sp, $sp, -0x20
 *  8015B678: sw          $s0, 0x10($sp)
 *  8015B67C: addu        $s0, $a0, $zero
 *  8015B680: sw          $s1, 0x14($sp)
 *  8015B684: addu        $s1, $a1, $zero
 *  8015B688: sw          $ra, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B674_C3FF4);

/*
 * func_8015B6D4_C4054
 * VRAM 0x8015B6D4, ROM 0x000C4054
 * Callees: 0x8006A020
 */
/*
 *  8015B6D4: addiu       $sp, $sp, -0x20
 *  8015B6D8: sw          $s0, 0x10($sp)
 *  8015B6DC: addu        $s0, $a0, $zero
 *  8015B6E0: sw          $s1, 0x14($sp)
 *  8015B6E4: addu        $s1, $a1, $zero
 *  8015B6E8: sw          $ra, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B6D4_C4054);

/*
 * func_8015B734_C40B4
 * VRAM 0x8015B734, ROM 0x000C40B4
 * Callees: none
 */
/*
 *  8015B734: addiu       $v0, $zero, 0x7
 *  8015B738: sb          $v0, 0x4E($a0)
 *  8015B73C: lw          $v0, 0x14($a0)
 *  8015B740: addiu       $v1, $zero, -0x11
 *  8015B744: sh          $zero, 0x5E($a0)
 *  8015B748: and         $v0, $v0, $v1
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B734_C40B4);

/*
 * func_8015B75C_C40DC
 * VRAM 0x8015B75C, ROM 0x000C40DC
 * Callees: none
 */
/*
 *  8015B75C: addiu       $sp, $sp, -0x28
 *  8015B760: sw          $s0, 0x18($sp)
 *  8015B764: addu        $s0, $a0, $zero
 *  8015B768: sw          $ra, 0x24($sp)
 *  8015B76C: sw          $s2, 0x20($sp)
 *  8015B770: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B75C_C40DC);

/*
 * func_8015B8B0_C4230
 * VRAM 0x8015B8B0, ROM 0x000C4230
 * Callees: none
 */
/*
 *  8015B8B0: addiu       $sp, $sp, -0x28
 *  8015B8B4: sw          $s1, 0x1C($sp)
 *  8015B8B8: addu        $s1, $a0, $zero
 *  8015B8BC: sw          $ra, 0x20($sp)
 *  8015B8C0: sw          $s0, 0x18($sp)
 *  8015B8C4: lw          $v0, 0x18($s1)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B8B0_C4230);

/*
 * func_8015B9D0_C4350
 * VRAM 0x8015B9D0, ROM 0x000C4350
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B9D0: lui         $v1, 0x8007
 *  8015B9D4: lw          $v1, -0x338($v1)
 *  8015B9D8: addiu       $sp, $sp, -0x30
 *  8015B9DC: sw          $s0, 0x18($sp)
 *  8015B9E0: addu        $s0, $a0, $zero
 *  8015B9E4: sw          $ra, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015B9D0_C4350);

/*
 * func_8015BB44_C44C4
 * VRAM 0x8015BB44, ROM 0x000C44C4
 * Callees: none
 */
/*
 *  8015BB44: addiu       $sp, $sp, -0x18
 *  8015BB48: sw          $ra, 0x10($sp)
 *  8015BB4C: lhu         $v0, 0x14($a1)
 *  8015BB50: nop
 *  8015BB54: addiu       $v0, $v0, -0x1
 *  8015BB58: sll         $v0, $v0, 16
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015BB44_C44C4);

/*
 * func_8015BC00_C4580
 * VRAM 0x8015BC00, ROM 0x000C4580
 * Callees: none
 */
/*
 *  8015BC00: addiu       $sp, $sp, -0x58
 *  8015BC04: sw          $s4, 0x48($sp)
 *  8015BC08: addu        $s4, $a0, $zero
 *  8015BC0C: sw          $ra, 0x50($sp)
 *  8015BC10: sw          $s5, 0x4C($sp)
 *  8015BC14: sw          $s3, 0x44($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015BC00_C4580);

/*
 * func_8015BDB4_C4734
 * VRAM 0x8015BDB4, ROM 0x000C4734
 * Callees: none
 */
/*
 *  8015BDB4: addiu       $sp, $sp, -0x30
 *  8015BDB8: addu        $a2, $a0, $zero
 *  8015BDBC: lwl         $v0, 0x18($a2)
 *  8015BDC0: lwr         $v0, 0x1B($a2)
 *  8015BDC4: lh          $v1, 0x1C($a2)
 *  8015BDC8: swl         $v0, 0x8($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015BDB4_C4734);

/*
 * func_8015C2E0_C4C60
 * VRAM 0x8015C2E0, ROM 0x000C4C60
 * Callees: none
 */
/*
 *  8015C2E0: addiu       $sp, $sp, -0x58
 *  8015C2E4: sw          $s1, 0x44($sp)
 *  8015C2E8: addu        $s1, $a0, $zero
 *  8015C2EC: sw          $s0, 0x40($sp)
 *  8015C2F0: addu        $s0, $a1, $zero
 *  8015C2F4: sw          $s3, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015C2E0_C4C60);

/*
 * mooshu_moolevr_OnUpdate
 * VRAM 0x8015C3E0, ROM 0x000C4D60
 * Callees: none
 */
/*
 *  8015C3E0: addiu       $sp, $sp, -0x30
 *  8015C3E4: sw          $s0, 0x28($sp)
 *  8015C3E8: addu        $s0, $a0, $zero
 *  8015C3EC: sw          $ra, 0x2C($sp)
 *  8015C3F0: lw          $v1, 0xF4($s0)
 *  8015C3F4: addiu       $v0, $zero, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moolevr_OnUpdate);

/*
 * mooshu_moolevr_OnCollide
 * VRAM 0x8015C5D0, ROM 0x000C4F50
 * Callees: 0x80027500
 */
/*
 *  8015C5D0: addiu       $sp, $sp, -0x30
 *  8015C5D4: sw          $s1, 0x24($sp)
 *  8015C5D8: addu        $s1, $a0, $zero
 *  8015C5DC: sw          $s2, 0x28($sp)
 *  8015C5E0: sw          $ra, 0x2C($sp)
 *  8015C5E4: sw          $s0, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moolevr_OnCollide);

/*
 * func_8015C6D0_C5050
 * VRAM 0x8015C6D0, ROM 0x000C5050
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C6D0: lh          $a1, 0x60($a0)
 *  8015C6D4: nop
 *  8015C6D8: beqz        $a1, . + 4 + (0x8 << 2)
 *  8015C6DC: addiu       $v0, $zero, 0x3
 *  8015C6E0: lw          $v1, 0xF4($a0)
 *  8015C6E4: nop
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015C6D0_C5050);

/*
 * func_8015C710_C5090
 * VRAM 0x8015C710, ROM 0x000C5090
 * Callees: none
 */
/*
 *  8015C710: addiu       $sp, $sp, -0x20
 *  8015C714: sw          $s0, 0x18($sp)
 *  8015C718: addu        $s0, $a0, $zero
 *  8015C71C: sw          $ra, 0x1C($sp)
 *  8015C720: lw          $v1, 0xF4($s0)
 *  8015C724: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015C710_C5090);

/*
 * func_8015C780_C5100
 * VRAM 0x8015C780, ROM 0x000C5100
 * Callees: none
 */
/*
 *  8015C780: addiu       $sp, $sp, -0x20
 *  8015C784: sw          $s0, 0x18($sp)
 *  8015C788: addu        $s0, $a0, $zero
 *  8015C78C: sw          $ra, 0x1C($sp)
 *  8015C790: lw          $v0, 0xFC($s0)
 *  8015C794: nop
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015C780_C5100);

/*
 * mooshu_moosprk_OnUpdate
 * VRAM 0x8015C82C, ROM 0x000C51AC
 * Callees: none
 */
/*
 *  8015C82C: addiu       $sp, $sp, -0x40
 *  8015C830: sw          $s0, 0x38($sp)
 *  8015C834: addu        $s0, $a0, $zero
 *  8015C838: sw          $ra, 0x3C($sp)
 *  8015C83C: lw          $v1, 0xF4($s0)
 *  8015C840: nop
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moosprk_OnUpdate);

/*
 * mooshu_moosprk_OnCollide
 * VRAM 0x8015C994, ROM 0x000C5314
 * Callees: 0x80022714
 */
/*
 *  8015C994: addiu       $sp, $sp, -0x18
 *  8015C998: addu        $a2, $a1, $zero
 *  8015C99C: sw          $ra, 0x10($sp)
 *  8015C9A0: lw          $a1, 0x78($a0)
 *  8015C9A4: nop
 *  8015C9A8: lh          $v1, 0x6($a1)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_moosprk_OnCollide);

/*
 * mooshu_jacob_OnCreate
 * VRAM 0x8015CA74, ROM 0x000C53F4
 * Callees: none
 */
/*
 *  8015CA74: addiu       $sp, $sp, -0x48
 *  8015CA78: sw          $s1, 0x3C($sp)
 *  8015CA7C: addu        $s1, $a0, $zero
 *  8015CA80: sw          $ra, 0x40($sp)
 *  8015CA84: sw          $s0, 0x38($sp)
 *  8015CA88: lw          $v0, 0x10($s1)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_jacob_OnCreate);

/*
 * mooshu_jacob_OnUpdate
 * VRAM 0x8015CD88, ROM 0x000C5708
 * Callees: none
 */
/*
 *  8015CD88: addiu       $sp, $sp, -0x48
 *  8015CD8C: sw          $s1, 0x3C($sp)
 *  8015CD90: addu        $s1, $a0, $zero
 *  8015CD94: sw          $s2, 0x40($sp)
 *  8015CD98: addu        $s2, $a1, $zero
 *  8015CD9C: sw          $s0, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_jacob_OnUpdate);

/*
 * func_8015D084_C5A04
 * VRAM 0x8015D084, ROM 0x000C5A04
 * Callees: none
 */
/*
 *  8015D084: addiu       $sp, $sp, -0x10
 *  8015D088: addu        $t0, $zero, $zero
 *  8015D08C: lh          $a2, 0x106($a0)
 *  8015D090: lw          $v1, 0x4($a1)
 *  8015D094: sll         $v0, $a2, 1
 *  8015D098: addu        $v0, $v0, $a2
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015D084_C5A04);

/*
 * func_8015D190_C5B10
 * VRAM 0x8015D190, ROM 0x000C5B10
 * Callees: OBTABLE_FindObject
 */
/*
 *  8015D190: addiu       $sp, $sp, -0x28
 *  8015D194: sw          $ra, 0x20($sp)
 *  8015D198: sw          $s3, 0x1C($sp)
 *  8015D19C: sw          $s2, 0x18($sp)
 *  8015D1A0: sw          $s1, 0x14($sp)
 *  8015D1A4: sw          $s0, 0x10($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015D190_C5B10);

/*
 * func_8015D240_C5BC0
 * VRAM 0x8015D240, ROM 0x000C5BC0
 * Callees: none
 */
/*
 *  8015D240: addiu       $sp, $sp, -0x38
 *  8015D244: sw          $s0, 0x30($sp)
 *  8015D248: addu        $s0, $a0, $zero
 *  8015D24C: sw          $ra, 0x34($sp)
 *  8015D250: lh          $v0, 0xE($s0)
 *  8015D254: addu        $a2, $a1, $zero
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015D240_C5BC0);

/*
 * func_8015D544_C5EC4
 * VRAM 0x8015D544, ROM 0x000C5EC4
 * Callees: none
 */
/*
 *  8015D544: addiu       $sp, $sp, -0x40
 *  8015D548: sw          $s0, 0x18($sp)
 *  8015D54C: addu        $s0, $a0, $zero
 *  8015D550: sw          $s1, 0x1C($sp)
 *  8015D554: addu        $s1, $a1, $zero
 *  8015D558: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015D544_C5EC4);

/*
 * func_8015D6B0_C6030
 * VRAM 0x8015D6B0, ROM 0x000C6030
 * Callees: none
 */
/*
 *  8015D6B0: addiu       $sp, $sp, -0x10
 *  8015D6B4: addu        $t0, $zero, $zero
 *  8015D6B8: lh          $a2, 0xFE($a0)
 *  8015D6BC: lw          $v1, 0x4($a1)
 *  8015D6C0: sll         $v0, $a2, 1
 *  8015D6C4: addu        $v0, $v0, $a2
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015D6B0_C6030);

/*
 * func_8015D7C8_C6148
 * VRAM 0x8015D7C8, ROM 0x000C6148
 * Callees: none
 */
/*
 *  8015D7C8: addiu       $sp, $sp, -0x80
 *  8015D7CC: sw          $s6, 0x70($sp)
 *  8015D7D0: addu        $s6, $a0, $zero
 *  8015D7D4: sw          $ra, 0x78($sp)
 *  8015D7D8: sw          $s7, 0x74($sp)
 *  8015D7DC: sw          $s5, 0x6C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015D7C8_C6148);

/*
 * func_8015DA78_C63F8
 * VRAM 0x8015DA78, ROM 0x000C63F8
 * Callees: OBTABLE_FindObject, INSTANCE_BirthObject
 */
/*
 *  8015DA78: addiu       $sp, $sp, -0x38
 *  8015DA7C: sw          $s3, 0x1C($sp)
 *  8015DA80: addu        $s3, $a0, $zero
 *  8015DA84: sw          $s2, 0x18($sp)
 *  8015DA88: addu        $s2, $a1, $zero
 *  8015DA8C: sw          $s7, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", func_8015DA78_C63F8);

/*
 * mooshu_ebolt_OnCreate
 * VRAM 0x8015DBB0, ROM 0x000C6530
 * Callees: 0x80017AB8
 */
/*
 *  8015DBB0: addiu       $sp, $sp, -0x18
 *  8015DBB4: sw          $s0, 0x10($sp)
 *  8015DBB8: addu        $s0, $a0, $zero
 *  8015DBBC: sw          $ra, 0x14($sp)
 *  8015DBC0: lw          $v1, 0x10($s0)
 *  8015DBC4: lui         $v0, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_ebolt_OnCreate);

/*
 * mooshu_ebolt_OnUpdate
 * VRAM 0x8015DC2C, ROM 0x000C65AC
 * Callees: none
 */
/*
 *  8015DC2C: addiu       $sp, $sp, -0x18
 *  8015DC30: sw          $s0, 0x10($sp)
 *  8015DC34: addu        $s0, $a0, $zero
 *  8015DC38: sw          $ra, 0x14($sp)
 *  8015DC3C: lw          $a1, 0x100($s0)
 *  8015DC40: jal         func_8015D7C8
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_ebolt_OnUpdate);

/*
 * mooshu_vandb_OnUpdate
 * VRAM 0x8015DC98, ROM 0x000C6618
 * Callees: none
 */
/*
 *  8015DC98: addiu       $sp, $sp, -0x28
 *  8015DC9C: sw          $s0, 0x18($sp)
 *  8015DCA0: addu        $s0, $a0, $zero
 *  8015DCA4: sw          $s1, 0x1C($sp)
 *  8015DCA8: addu        $s1, $a1, $zero
 *  8015DCAC: sw          $ra, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MOOSHU", mooshu_vandb_OnUpdate);
