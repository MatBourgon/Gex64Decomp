/*
 * level_stubs_kungfu.c — Kung-Fu Theater
 * Level overlay: KUNGFU
 * ROM base: 0x0A8940, VRAM base: 0x80159720
 * Stubs: 79
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/* kungfu_kboat_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_kboat_OnCreate);

/*
 * kungfu_kboat_OnUpdate
 * VRAM 0x801597A8, ROM 0x000A89C8
 * Callees: none
 */
/*
 *  801597A8: addiu       $sp, $sp, -0x30
 *  801597AC: sw          $s0, 0x20($sp)
 *  801597B0: addu        $s0, $a0, $zero
 *  801597B4: sw          $s1, 0x24($sp)
 *  801597B8: addu        $s1, $a1, $zero
 *  801597BC: sw          $ra, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_kboat_OnUpdate);

/* kungfu_kboat_OnCollide — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_kboat_OnCollide);

/*
 * kungfu_kbgen_OnCreate
 * VRAM 0x80159968, ROM 0x000A8B88
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159968: lui         $v1, 0x10
 *  8015996C: lw          $v0, 0x10($a0)
 *  80159970: lw          $a1, 0x24($a0)
 *  80159974: ori         $v1, $v1, 0xC00
 *  80159978: sw          $zero, 0xF4($a0)
 *  8015997C: or          $v0, $v0, $v1
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_kbgen_OnCreate);

/*
 * kungfu_kbgen_OnUpdate
 * VRAM 0x801599C8, ROM 0x000A8BE8
 * Callees: none
 */
/*
 *  801599C8: addiu       $sp, $sp, -0x30
 *  801599CC: sw          $s0, 0x18($sp)
 *  801599D0: addu        $s0, $a0, $zero
 *  801599D4: sw          $ra, 0x28($sp)
 *  801599D8: sw          $s3, 0x24($sp)
 *  801599DC: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_kbgen_OnUpdate);

/*
 * func_80159B1C_A8D3C
 * VRAM 0x80159B1C, ROM 0x000A8D3C
 * Callees: none
 */
/*
 *  80159B1C: addiu       $sp, $sp, -0x18
 *  80159B20: sw          $s0, 0x10($sp)
 *  80159B24: addu        $s0, $a0, $zero
 *  80159B28: sw          $ra, 0x14($sp)
 *  80159B2C: lhu         $a2, 0x6C($s0)
 *  80159B30: lhu         $v0, 0x24($s0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_80159B1C_A8D3C);

/*
 * kungfu_spray_OnUpdate
 * VRAM 0x80159C40, ROM 0x000A8E60
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159C40: lui         $v0, 0x8007
 *  80159C44: lw          $v0, -0x3060($v0)
 *  80159C48: addiu       $sp, $sp, -0x48
 *  80159C4C: sw          $s0, 0x38($sp)
 *  80159C50: addu        $s0, $a0, $zero
 *  80159C54: sw          $ra, 0x44($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_spray_OnUpdate);

/*
 * kungfu_spray_OnCollide
 * VRAM 0x80159EA4, ROM 0x000A90C4
 * Callees: none
 */
/*
 *  80159EA4: addiu       $sp, $sp, -0x18
 *  80159EA8: sw          $s0, 0x10($sp)
 *  80159EAC: addu        $s0, $a0, $zero
 *  80159EB0: sw          $ra, 0x14($sp)
 *  80159EB4: lw          $a0, 0x78($s0)
 *  80159EB8: nop
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_spray_OnCollide);

/*
 * kungfu_bug_OnCreate
 * VRAM 0x80159F2C, ROM 0x000A914C
 * Callees: none
 */
/*
 *  80159F2C: addiu       $sp, $sp, -0x8
 *  80159F30: addiu       $v0, $zero, 0x18
 *  80159F34: lui         $v1, 0x10
 *  80159F38: sh          $v0, 0x102($a0)
 *  80159F3C: lw          $v0, 0x10($a0)
 *  80159F40: lw          $a1, 0x24($a0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_bug_OnCreate);

/*
 * kungfu_bug_OnUpdate
 * VRAM 0x8015A008, ROM 0x000A9228
 * Callees: none
 */
/*
 *  8015A008: addiu       $sp, $sp, -0x58
 *  8015A00C: sw          $s2, 0x50($sp)
 *  8015A010: addu        $s2, $a0, $zero
 *  8015A014: addiu       $a1, $zero, -0x1
 *  8015A018: sw          $ra, 0x54($sp)
 *  8015A01C: sw          $s1, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_bug_OnUpdate);

/* kungfu_bug_OnCollide — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_bug_OnCollide);

/*
 * kungfu_launch_OnUpdate
 * VRAM 0x8015A658, ROM 0x000A9878
 * Callees: none
 */
/*
 *  8015A658: addiu       $sp, $sp, -0x30
 *  8015A65C: sw          $s0, 0x18($sp)
 *  8015A660: addu        $s0, $a0, $zero
 *  8015A664: sw          $s2, 0x20($sp)
 *  8015A668: addu        $s2, $a1, $zero
 *  8015A66C: sw          $ra, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_launch_OnUpdate);

/*
 * func_8015AC1C_A9E3C
 * VRAM 0x8015AC1C, ROM 0x000A9E3C
 * Callees: none
 */
/*
 *  8015AC1C: addu        $a1, $a0, $zero
 *  8015AC20: addiu       $v0, $zero, -0x801
 *  8015AC24: lw          $v1, 0x10($a1)
 *  8015AC28: lw          $a0, 0x11C($a1)
 *  8015AC2C: and         $v1, $v1, $v0
 *  8015AC30: andi        $a0, $a0, 0x8
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015AC1C_A9E3C);

/*
 * func_8015AC6C_A9E8C
 * VRAM 0x8015AC6C, ROM 0x000A9E8C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015AC6C: lw          $v0, 0x1C($a0)
 *  8015AC70: nop
 *  8015AC74: beqz        $v0, . + 4 + (0x30 << 2)
 *  8015AC78: addiu       $sp, $sp, -0x8
 *  8015AC7C: lw          $v0, 0x4($v0)
 *  8015AC80: nop
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015AC6C_A9E8C);

/*
 * func_8015AD44_A9F64
 * VRAM 0x8015AD44, ROM 0x000A9F64
 * Callees: none
 */
/*
 *  8015AD44: addiu       $sp, $sp, -0x20
 *  8015AD48: sw          $s0, 0x10($sp)
 *  8015AD4C: addu        $s0, $a0, $zero
 *  8015AD50: sw          $s1, 0x14($sp)
 *  8015AD54: addu        $s1, $a1, $zero
 *  8015AD58: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015AD44_A9F64);

/*
 * func_8015ADC8_A9FE8
 * VRAM 0x8015ADC8, ROM 0x000A9FE8
 * Callees: 0x8015AC1C
 */
/*
 *  8015ADC8: addiu       $sp, $sp, -0x20
 *  8015ADCC: sw          $s2, 0x18($sp)
 *  8015ADD0: addu        $s2, $a0, $zero
 *  8015ADD4: sw          $s1, 0x14($sp)
 *  8015ADD8: addu        $s1, $a1, $zero
 *  8015ADDC: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015ADC8_A9FE8);

/*
 * kungfu_onoff_OnCollide
 * VRAM 0x8015B0F0, ROM 0x000AA310
 * Callees: none
 */
/*
 *  8015B0F0: addiu       $sp, $sp, -0x18
 *  8015B0F4: addu        $t2, $zero, $zero
 *  8015B0F8: addu        $t6, $zero, $zero
 *  8015B0FC: addu        $t3, $zero, $zero
 *  8015B100: sw          $ra, 0x10($sp)
 *  8015B104: lw          $a3, 0x24($a0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_onoff_OnCollide);

/*
 * kungfu_spike_OnCreate
 * VRAM 0x8015B370, ROM 0x000AA590
 * Callees: none
 */
/*
 *  8015B370: addu        $a2, $a0, $zero
 *  8015B374: addiu       $v0, $zero, 0x1E
 *  8015B378: lw          $a3, 0x24($a2)
 *  8015B37C: addiu       $t0, $a2, 0xFC
 *  8015B380: sh          $zero, 0xFC($a2)
 *  8015B384: sh          $v0, 0x100($a2)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_spike_OnCreate);

/*
 * kungfu_spike_OnUpdate
 * VRAM 0x8015B410, ROM 0x000AA630
 * Callees: none
 */
/*
 *  8015B410: addiu       $sp, $sp, -0x28
 *  8015B414: sw          $s0, 0x18($sp)
 *  8015B418: addu        $s0, $a0, $zero
 *  8015B41C: sw          $ra, 0x20($sp)
 *  8015B420: sw          $s1, 0x1C($sp)
 *  8015B424: lw          $v0, 0x104($s0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_spike_OnUpdate);

/*
 * kungfu_spike_OnCollide
 * VRAM 0x8015B564, ROM 0x000AA784
 * Callees: 0x80022714
 */
/*
 *  8015B564: addiu       $sp, $sp, -0x18
 *  8015B568: sw          $ra, 0x10($sp)
 *  8015B56C: lh          $v0, 0x5E($a0)
 *  8015B570: lw          $v1, 0x78($a0)
 *  8015B574: beqz        $v0, . + 4 + (0x8 << 2)
 *  8015B578: nop
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_spike_OnCollide);

/*
 * func_8015B5A8_AA7C8
 * VRAM 0x8015B5A8, ROM 0x000AA7C8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B5A8: lui         $t1, 0x8007
 *  8015B5AC: lw          $t1, -0x338($t1)
 *  8015B5B0: addiu       $sp, $sp, -0x40
 *  8015B5B4: sw          $s4, 0x28($sp)
 *  8015B5B8: lw          $s4, 0x50($sp)
 *  8015B5BC: sw          $s6, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015B5A8_AA7C8);

/*
 * kungfu_dragon_OnCreate
 * VRAM 0x8015B808, ROM 0x000AAA28
 * Callees: none
 */
/*
 *  8015B808: addiu       $sp, $sp, -0x30
 *  8015B80C: sw          $s0, 0x20($sp)
 *  8015B810: addu        $s0, $a0, $zero
 *  8015B814: addu        $a3, $a1, $zero
 *  8015B818: sw          $s2, 0x28($sp)
 *  8015B81C: sw          $ra, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_dragon_OnCreate);

/*
 * kungfu_dragon_OnUpdate
 * VRAM 0x8015BA84, ROM 0x000AACA4
 * Callees: 0x80050508, 0x800331BC, INSTANCE_KillInstance
 */
/*
 *  8015BA84: addiu       $sp, $sp, -0x90
 *  8015BA88: sw          $s3, 0x74($sp)
 *  8015BA8C: addu        $s3, $a0, $zero
 *  8015BA90: sw          $s2, 0x70($sp)
 *  8015BA94: addiu       $s2, $s3, 0xE8
 *  8015BA98: sw          $s7, 0x84($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_dragon_OnUpdate);

/*
 * kungfu_dragflm_OnCreate
 * VRAM 0x8015C404, ROM 0x000AB624
 * Callees: none
 */
/*
 *  8015C404: addiu       $sp, $sp, -0x18
 *  8015C408: sw          $s0, 0x10($sp)
 *  8015C40C: addu        $s0, $a0, $zero
 *  8015C410: lui         $v1, 0x10
 *  8015C414: sw          $ra, 0x14($sp)
 *  8015C418: lw          $v0, 0x10($s0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_dragflm_OnCreate);

/*
 * kungfu_dragflm_OnUpdate
 * VRAM 0x8015C550, ROM 0x000AB770
 * Callees: none
 */
/*
 *  8015C550: addiu       $sp, $sp, -0x20
 *  8015C554: sw          $s0, 0x18($sp)
 *  8015C558: addu        $s0, $a0, $zero
 *  8015C55C: sw          $ra, 0x1C($sp)
 *  8015C560: lw          $v0, 0x11C($s0)
 *  8015C564: nop
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_dragflm_OnUpdate);

/*
 * kungfu_dragflm_OnCollide
 * VRAM 0x8015C680, ROM 0x000AB8A0
 * Callees: none
 */
/*
 *  8015C680: addiu       $sp, $sp, -0x38
 *  8015C684: sw          $s3, 0x2C($sp)
 *  8015C688: addu        $s3, $a0, $zero
 *  8015C68C: addu        $a0, $a1, $zero
 *  8015C690: sw          $ra, 0x34($sp)
 *  8015C694: sw          $s4, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_dragflm_OnCollide);

/*
 * func_8015C884_ABAA4
 * VRAM 0x8015C884, ROM 0x000ABAA4
 * Callees: none
 */
/*
 *  8015C884: addiu       $sp, $sp, -0x38
 *  8015C888: sw          $s2, 0x28($sp)
 *  8015C88C: addu        $s2, $a0, $zero
 *  8015C890: sw          $s0, 0x20($sp)
 *  8015C894: addiu       $s0, $a1, 0xE8
 *  8015C898: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015C884_ABAA4);

/*
 * kungfu_dragbod_OnCreate
 * VRAM 0x8015CB58, ROM 0x000ABD78
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015CB58: lui         $v1, 0x10
 *  8015CB5C: lw          $v0, 0x10($a0)
 *  8015CB60: ori         $v1, $v1, 0x400
 *  8015CB64: or          $v0, $v0, $v1
 *  8015CB68: jr          $ra
 *  8015CB6C: sw          $v0, 0x10($a0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_dragbod_OnCreate);

/*
 * kungfu_dragbod_OnCollide
 * VRAM 0x8015CB70, ROM 0x000ABD90
 * Callees: none
 */
/*
 *  8015CB70: addiu       $sp, $sp, -0x20
 *  8015CB74: sw          $ra, 0x18($sp)
 *  8015CB78: lw          $v0, 0x1C($a0)
 *  8015CB7C: addu        $a2, $a1, $zero
 *  8015CB80: lw          $a3, 0x4($v0)
 *  8015CB84: addu        $t0, $zero, $zero
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_dragbod_OnCollide);

/*
 * kungfu_dragon_OnCollide
 * VRAM 0x8015CC10, ROM 0x000ABE30
 * Callees: none
 */
/*
 *  8015CC10: addiu       $sp, $sp, -0x18
 *  8015CC14: addu        $a2, $a1, $zero
 *  8015CC18: addiu       $a1, $zero, -0x1
 *  8015CC1C: sw          $ra, 0x10($sp)
 *  8015CC20: lw          $v1, 0x78($a0)
 *  8015CC24: nop
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_dragon_OnCollide);

/*
 * kungfu_cannon_OnCreate
 * VRAM 0x8015CCAC, ROM 0x000ABECC
 * Callees: none
 */
/*
 *  8015CCAC: addiu       $sp, $sp, -0x20
 *  8015CCB0: sw          $s1, 0x14($sp)
 *  8015CCB4: addu        $s1, $a0, $zero
 *  8015CCB8: sw          $ra, 0x1C($sp)
 *  8015CCBC: sw          $s2, 0x18($sp)
 *  8015CCC0: sw          $s0, 0x10($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_cannon_OnCreate);

/*
 * kungfu_cannon_OnUpdate
 * VRAM 0x8015CDD4, ROM 0x000ABFF4
 * Callees: none
 */
/*
 *  8015CDD4: addiu       $sp, $sp, -0x38
 *  8015CDD8: sw          $s0, 0x28($sp)
 *  8015CDDC: addu        $s0, $a0, $zero
 *  8015CDE0: sw          $ra, 0x34($sp)
 *  8015CDE4: sw          $s2, 0x30($sp)
 *  8015CDE8: sw          $s1, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_cannon_OnUpdate);

/*
 * kungfu_canball_OnCreate
 * VRAM 0x8015D0BC, ROM 0x000AC2DC
 * Callees: none
 */
/*
 *  8015D0BC: addiu       $sp, $sp, -0x20
 *  8015D0C0: sw          $s0, 0x10($sp)
 *  8015D0C4: addu        $s0, $a0, $zero
 *  8015D0C8: lui         $v0, 0x2
 *  8015D0CC: sw          $ra, 0x18($sp)
 *  8015D0D0: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_canball_OnCreate);

/*
 * kungfu_canball_OnUpdate
 * VRAM 0x8015D174, ROM 0x000AC394
 * Callees: none
 */
/*
 *  8015D174: addiu       $sp, $sp, -0x40
 *  8015D178: sw          $s0, 0x38($sp)
 *  8015D17C: addu        $s0, $a0, $zero
 *  8015D180: sw          $ra, 0x3C($sp)
 *  8015D184: lw          $v1, 0xD0($s0)
 *  8015D188: lhu         $v0, 0x48($s0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_canball_OnUpdate);

/*
 * kungfu_canball_OnCollide
 * VRAM 0x8015D250, ROM 0x000AC470
 * Callees: none
 */
/*
 *  8015D250: addiu       $sp, $sp, -0x20
 *  8015D254: sw          $s1, 0x14($sp)
 *  8015D258: addu        $s1, $a0, $zero
 *  8015D25C: addiu       $a0, $zero, -0x1
 *  8015D260: addiu       $a2, $zero, -0x1
 *  8015D264: sw          $ra, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_canball_OnCollide);

/*
 * kungfu_cannon_OnCollide
 * VRAM 0x8015D37C, ROM 0x000AC59C
 * Callees: none
 */
/*
 *  8015D37C: addiu       $sp, $sp, -0x40
 *  8015D380: sw          $s1, 0x24($sp)
 *  8015D384: addu        $s1, $a0, $zero
 *  8015D388: sw          $s3, 0x2C($sp)
 *  8015D38C: addu        $s3, $a1, $zero
 *  8015D390: sw          $ra, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_cannon_OnCollide);

/*
 * func_8015D5E8_AC808
 * VRAM 0x8015D5E8, ROM 0x000AC808
 * Callees: none
 */
/*
 *  8015D5E8: addiu       $sp, $sp, -0x30
 *  8015D5EC: sw          $s0, 0x20($sp)
 *  8015D5F0: addu        $s0, $a0, $zero
 *  8015D5F4: addu        $a3, $a1, $zero
 *  8015D5F8: sw          $s1, 0x24($sp)
 *  8015D5FC: addu        $s1, $a2, $zero
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015D5E8_AC808);

/*
 * func_8015D770_AC990
 * VRAM 0x8015D770, ROM 0x000AC990
 * Callees: none
 */
/*
 *  8015D770: addiu       $sp, $sp, -0x48
 *  8015D774: sw          $s7, 0x3C($sp)
 *  8015D778: lw          $s7, 0x58($sp)
 *  8015D77C: sw          $s0, 0x20($sp)
 *  8015D780: addu        $s0, $a0, $zero
 *  8015D784: sw          $s4, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015D770_AC990);

/*
 * kungfu_samuri_OnCreate
 * VRAM 0x8015D91C, ROM 0x000ACB3C
 * Callees: none
 */
/*
 *  8015D91C: addiu       $sp, $sp, -0x28
 *  8015D920: sw          $s0, 0x18($sp)
 *  8015D924: addu        $s0, $a0, $zero
 *  8015D928: sw          $s2, 0x20($sp)
 *  8015D92C: lui         $v0, 0x2
 *  8015D930: sw          $ra, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_samuri_OnCreate);

/*
 * func_8015DB1C_ACD3C
 * VRAM 0x8015DB1C, ROM 0x000ACD3C
 * Callees: none
 */
/*
 *  8015DB1C: addiu       $a2, $zero, 0x6
 *  8015DB20: lw          $v0, 0x14($a0)
 *  8015DB24: addiu       $v1, $zero, -0x11
 *  8015DB28: and         $v0, $v0, $v1
 *  8015DB2C: sw          $v0, 0x14($a0)
 *  8015DB30: lh          $v1, 0x10($a1)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015DB1C_ACD3C);

/*
 * func_8015DB50_ACD70
 * VRAM 0x8015DB50, ROM 0x000ACD70
 * Callees: none
 */
/*
 *  8015DB50: addu        $a2, $a0, $zero
 *  8015DB54: lw          $v0, 0x14($a2)
 *  8015DB58: addiu       $v1, $zero, -0x11
 *  8015DB5C: and         $v0, $v0, $v1
 *  8015DB60: sw          $v0, 0x14($a2)
 *  8015DB64: lh          $v0, 0x10($a1)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015DB50_ACD70);

/*
 * func_8015DBB0_ACDD0
 * VRAM 0x8015DBB0, ROM 0x000ACDD0
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015DBB0: lw          $v0, 0x14($a0)
 *  8015DBB4: addiu       $v1, $zero, -0x11
 *  8015DBB8: and         $v0, $v0, $v1
 *  8015DBBC: sw          $v0, 0x14($a0)
 *  8015DBC0: addiu       $v0, $zero, 0x1
 *  8015DBC4: sh          $v0, 0x18($a1)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015DBB0_ACDD0);

/*
 * func_8015DC00_ACE20
 * VRAM 0x8015DC00, ROM 0x000ACE20
 * Callees: none
 */
/*
 *  8015DC00: addiu       $sp, $sp, -0x18
 *  8015DC04: addu        $a2, $a0, $zero
 *  8015DC08: sw          $s0, 0x10($sp)
 *  8015DC0C: addu        $s0, $a1, $zero
 *  8015DC10: sw          $ra, 0x14($sp)
 *  8015DC14: lw          $v0, 0x14($a2)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015DC00_ACE20);

/*
 * kungfu_samuri_OnUpdate
 * VRAM 0x8015DCAC, ROM 0x000ACECC
 * Callees: none
 */
/*
 *  8015DCAC: addiu       $sp, $sp, -0x50
 *  8015DCB0: sw          $s1, 0x34($sp)
 *  8015DCB4: addu        $s1, $a0, $zero
 *  8015DCB8: sw          $s5, 0x44($sp)
 *  8015DCBC: addiu       $s5, $zero, 0x1
 *  8015DCC0: sw          $s4, 0x40($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_samuri_OnUpdate);

/*
 * kungfu_samuri_OnCollide
 * VRAM 0x8015E49C, ROM 0x000AD6BC
 * Callees: none
 */
/*
 *  8015E49C: addiu       $sp, $sp, -0x38
 *  8015E4A0: sw          $s0, 0x18($sp)
 *  8015E4A4: addu        $s0, $a0, $zero
 *  8015E4A8: sw          $s3, 0x24($sp)
 *  8015E4AC: addu        $s3, $a1, $zero
 *  8015E4B0: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_samuri_OnCollide);

/*
 * kungfu_boat_OnCreate
 * VRAM 0x8015E7DC, ROM 0x000AD9FC
 * Callees: none
 */
/*
 *  8015E7DC: addiu       $sp, $sp, -0x18
 *  8015E7E0: sw          $s0, 0x10($sp)
 *  8015E7E4: addu        $s0, $a0, $zero
 *  8015E7E8: lui         $a0, 0x10
 *  8015E7EC: sw          $ra, 0x14($sp)
 *  8015E7F0: lw          $v1, 0x1C($s0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_boat_OnCreate);

/*
 * kungfu_boat_OnUpdate
 * VRAM 0x8015E87C, ROM 0x000ADA9C
 * Callees: 0x800517E4
 */
/*
 *  8015E87C: addiu       $sp, $sp, -0x18
 *  8015E880: sw          $s0, 0x10($sp)
 *  8015E884: addu        $s0, $a0, $zero
 *  8015E888: sw          $ra, 0x14($sp)
 *  8015E88C: lw          $v0, 0x1C($s0)
 *  8015E890: nop
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_boat_OnUpdate);

/*
 * kungfu_pend_OnCreate
 * VRAM 0x8015E9F8, ROM 0x000ADC18
 * Callees: none
 */
/*
 *  8015E9F8: addu        $a1, $a0, $zero
 *  8015E9FC: lw          $v0, 0x18($a1)
 *  8015EA00: lw          $a3, 0x24($a1)
 *  8015EA04: lw          $v1, 0x1C($v0)
 *  8015EA08: addiu       $v0, $zero, 0x40
 *  8015EA0C: sw          $v0, 0xFC($a1)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_pend_OnCreate);

/*
 * kungfu_pend_OnUpdate
 * VRAM 0x8015EBAC, ROM 0x000ADDCC
 * Callees: none
 */
/*
 *  8015EBAC: addiu       $sp, $sp, -0x80
 *  8015EBB0: sw          $s2, 0x60($sp)
 *  8015EBB4: addu        $s2, $a0, $zero
 *  8015EBB8: sw          $ra, 0x7C($sp)
 *  8015EBBC: sw          $fp, 0x78($sp)
 *  8015EBC0: sw          $s7, 0x74($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_pend_OnUpdate);

/*
 * kungfu_pend_OnCollide
 * VRAM 0x8015F198, ROM 0x000AE3B8
 * Callees: GenericCollide
 */
/*
 *  8015F198: addiu       $sp, $sp, -0x18
 *  8015F19C: sw          $ra, 0x10($sp)
 *  8015F1A0: jal         func_8001AD48
 *  8015F1A4: nop
 *  8015F1A8: lw          $ra, 0x10($sp)
 *  8015F1AC: addiu       $sp, $sp, 0x18
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_pend_OnCollide);

/*
 * kungfu_ninja_OnCreate
 * VRAM 0x8015F1B8, ROM 0x000AE3D8
 * Callees: none
 */
/*
 *  8015F1B8: addiu       $sp, $sp, -0x30
 *  8015F1BC: sw          $s0, 0x20($sp)
 *  8015F1C0: addu        $s0, $a0, $zero
 *  8015F1C4: addu        $a3, $a1, $zero
 *  8015F1C8: sw          $s1, 0x24($sp)
 *  8015F1CC: lui         $v0, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_ninja_OnCreate);

/*
 * func_8015F570_AE790
 * VRAM 0x8015F570, ROM 0x000AE790
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F570: lw          $v0, 0x14($a0)
 *  8015F574: addiu       $v1, $zero, -0x11
 *  8015F578: and         $v0, $v0, $v1
 *  8015F57C: sw          $v0, 0x14($a0)
 *  8015F580: addiu       $v0, $zero, 0x5
 *  8015F584: sh          $v0, 0x10($a1)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015F570_AE790);

/*
 * func_8015F598_AE7B8
 * VRAM 0x8015F598, ROM 0x000AE7B8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F598: lw          $v0, 0x14($a0)
 *  8015F59C: addiu       $v1, $zero, -0x11
 *  8015F5A0: and         $v0, $v0, $v1
 *  8015F5A4: sw          $v0, 0x14($a0)
 *  8015F5A8: addiu       $v0, $zero, 0x1
 *  8015F5AC: sh          $v0, 0x10($a1)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015F598_AE7B8);

/*
 * func_8015F5D0_AE7F0
 * VRAM 0x8015F5D0, ROM 0x000AE7F0
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F5D0: lw          $v0, 0x14($a0)
 *  8015F5D4: addiu       $v1, $zero, -0x11
 *  8015F5D8: sb          $zero, 0x4E($a0)
 *  8015F5DC: sh          $zero, 0x5E($a0)
 *  8015F5E0: and         $v0, $v0, $v1
 *  8015F5E4: sw          $v0, 0x14($a0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015F5D0_AE7F0);

/*
 * func_8015F5F4_AE814
 * VRAM 0x8015F5F4, ROM 0x000AE814
 * Callees: none
 */
/*
 *  8015F5F4: addiu       $v0, $zero, 0x6
 *  8015F5F8: sb          $v0, 0x4E($a0)
 *  8015F5FC: lw          $v0, 0x14($a0)
 *  8015F600: addiu       $v1, $zero, -0x11
 *  8015F604: sh          $zero, 0x5E($a0)
 *  8015F608: and         $v0, $v0, $v1
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015F5F4_AE814);

/*
 * func_8015F61C_AE83C
 * VRAM 0x8015F61C, ROM 0x000AE83C
 * Callees: none
 */
/*
 *  8015F61C: addiu       $sp, $sp, -0x18
 *  8015F620: sw          $s0, 0x10($sp)
 *  8015F624: addu        $s0, $a0, $zero
 *  8015F628: sw          $ra, 0x14($sp)
 *  8015F62C: lw          $v1, 0x14($s0)
 *  8015F630: nop
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8015F61C_AE83C);

/*
 * kungfu_ninja_OnUpdate
 * VRAM 0x8015F6C0, ROM 0x000AE8E0
 * Callees: none
 */
/*
 *  8015F6C0: addiu       $sp, $sp, -0x70
 *  8015F6C4: sw          $s1, 0x4C($sp)
 *  8015F6C8: addu        $s1, $a0, $zero
 *  8015F6CC: sw          $s3, 0x54($sp)
 *  8015F6D0: addu        $s3, $a1, $zero
 *  8015F6D4: sw          $s7, 0x64($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_ninja_OnUpdate);

/*
 * kungfu_ninja_OnCollide
 * VRAM 0x80160218, ROM 0x000AF438
 * Callees: none
 */
/*
 *  80160218: addiu       $sp, $sp, -0x38
 *  8016021C: sw          $s0, 0x20($sp)
 *  80160220: addu        $s0, $a0, $zero
 *  80160224: sw          $ra, 0x34($sp)
 *  80160228: sw          $s4, 0x30($sp)
 *  8016022C: sw          $s3, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_ninja_OnCollide);

/*
 * kungfu_swing_OnCreate
 * VRAM 0x80160654, ROM 0x000AF874
 * Callees: 0x8006A020
 */
/*
 *  80160654: addiu       $sp, $sp, -0x20
 *  80160658: sw          $s0, 0x10($sp)
 *  8016065C: addu        $s0, $a0, $zero
 *  80160660: sw          $ra, 0x18($sp)
 *  80160664: sw          $s1, 0x14($sp)
 *  80160668: lw          $v0, 0x18($s0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_swing_OnCreate);

/*
 * kungfu_swing_OnUpdate
 * VRAM 0x8016078C, ROM 0x000AF9AC
 * Callees: none
 */
/*
 *  8016078C: addiu       $sp, $sp, -0x30
 *  80160790: sw          $s1, 0x1C($sp)
 *  80160794: addu        $s1, $a0, $zero
 *  80160798: sw          $s3, 0x24($sp)
 *  8016079C: addu        $s3, $a1, $zero
 *  801607A0: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_swing_OnUpdate);

/*
 * kungfu_swing_OnCollide
 * VRAM 0x80160A54, ROM 0x000AFC74
 * Callees: 0x80022D54
 */
/*
 *  80160A54: addiu       $sp, $sp, -0x18
 *  80160A58: sw          $ra, 0x10($sp)
 *  80160A5C: jal         func_80022D54
 *  80160A60: nop
 *  80160A64: lw          $ra, 0x10($sp)
 *  80160A68: addiu       $sp, $sp, 0x18
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_swing_OnCollide);

/*
 * kungfu_oneway_OnCreate
 * VRAM 0x80160A74, ROM 0x000AFC94
 * Callees: none
 */
/*
 *  80160A74: addiu       $sp, $sp, -0x20
 *  80160A78: sw          $s0, 0x10($sp)
 *  80160A7C: addu        $s0, $a0, $zero
 *  80160A80: sw          $s2, 0x18($sp)
 *  80160A84: addu        $s2, $a1, $zero
 *  80160A88: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_oneway_OnCreate);

/*
 * kungfu_oneway_OnUpdate
 * VRAM 0x80160B1C, ROM 0x000AFD3C
 * Callees: none
 */
/*
 *  80160B1C: addiu       $sp, $sp, -0x50
 *  80160B20: sw          $s0, 0x38($sp)
 *  80160B24: addu        $s0, $a0, $zero
 *  80160B28: sw          $ra, 0x48($sp)
 *  80160B2C: sw          $s3, 0x44($sp)
 *  80160B30: sw          $s2, 0x40($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_oneway_OnUpdate);

/*
 * kungfu_oneway_OnCollide
 * VRAM 0x80160D2C, ROM 0x000AFF4C
 * Callees: 0x80022D54, SCRIPT_GetMultiSpline, SCRIPT_GetRotSplineDef, SplineGetLastRot
 */
/*
 *  80160D2C: addiu       $sp, $sp, -0x18
 *  80160D30: sw          $ra, 0x10($sp)
 *  80160D34: jal         func_80022D54
 *  80160D38: nop
 *  80160D3C: lw          $ra, 0x10($sp)
 *  80160D40: addiu       $sp, $sp, 0x18
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_oneway_OnCollide);

/*
 * func_80160D4C_AFF6C
 * VRAM 0x80160D4C, ROM 0x000AFF6C
 * Callees: SCRIPT_GetMultiSpline, SCRIPT_GetRotSplineDef, SplineGetLastRot, G2Quat_ToEuler
 */
/*
 *  80160D4C: addiu       $sp, $sp, -0x30
 *  80160D50: sw          $s0, 0x20($sp)
 *  80160D54: addu        $s0, $a0, $zero
 *  80160D58: addiu       $a1, $sp, 0x18
 *  80160D5C: addiu       $a2, $sp, 0x1C
 *  80160D60: sw          $ra, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_80160D4C_AFF6C);

/*
 * func_80160E4C_B006C
 * VRAM 0x80160E4C, ROM 0x000B006C
 * Callees: SCRIPT_GetMultiSpline
 */
/*
 *  80160E4C: addiu       $sp, $sp, -0x30
 *  80160E50: sw          $s2, 0x20($sp)
 *  80160E54: addu        $s2, $a2, $zero
 *  80160E58: sw          $ra, 0x28($sp)
 *  80160E5C: sw          $s3, 0x24($sp)
 *  80160E60: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_80160E4C_B006C);

/*
 * func_80160F68_B0188
 * VRAM 0x80160F68, ROM 0x000B0188
 * Callees: none
 */
/*
 *  80160F68: addiu       $sp, $sp, -0x40
 *  80160F6C: sw          $s3, 0x2C($sp)
 *  80160F70: addu        $s3, $a0, $zero
 *  80160F74: sw          $s2, 0x28($sp)
 *  80160F78: addu        $s2, $a1, $zero
 *  80160F7C: addu        $a1, $zero, $zero
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_80160F68_B0188);

/*
 * kungfu_joyride_OnCreate
 * VRAM 0x801610EC, ROM 0x000B030C
 * Callees: none
 */
/*
 *  801610EC: addiu       $sp, $sp, -0x30
 *  801610F0: sw          $s0, 0x20($sp)
 *  801610F4: addu        $s0, $a0, $zero
 *  801610F8: sw          $ra, 0x2C($sp)
 *  801610FC: sw          $s2, 0x28($sp)
 *  80161100: sw          $s1, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_joyride_OnCreate);

/*
 * func_8016121C_B043C
 * VRAM 0x8016121C, ROM 0x000B043C
 * Callees: none
 */
/*
 *  8016121C: addiu       $sp, $sp, -0x28
 *  80161220: sw          $s0, 0x18($sp)
 *  80161224: addu        $s0, $a0, $zero
 *  80161228: addiu       $v0, $s0, 0xDA
 *  8016122C: sw          $ra, 0x20($sp)
 *  80161230: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_8016121C_B043C);

/*
 * kungfu_joyride_OnUpdate
 * VRAM 0x80161278, ROM 0x000B0498
 * Callees: none
 */
/*
 *  80161278: addiu       $sp, $sp, -0x38
 *  8016127C: sw          $s2, 0x28($sp)
 *  80161280: addu        $s2, $a0, $zero
 *  80161284: sw          $s3, 0x2C($sp)
 *  80161288: addu        $s3, $a1, $zero
 *  8016128C: sw          $s1, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_joyride_OnUpdate);

/*
 * kungfu_joyride_OnCollide
 * VRAM 0x80161570, ROM 0x000B0790
 * Callees: none
 */
/*
 *  80161570: addiu       $sp, $sp, -0x28
 *  80161574: sw          $s0, 0x18($sp)
 *  80161578: addu        $s0, $a0, $zero
 *  8016157C: sw          $s1, 0x1C($sp)
 *  80161580: addu        $s1, $a1, $zero
 *  80161584: sw          $ra, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_joyride_OnCollide);

/*
 * kungfu_leafgen_OnCreate
 * VRAM 0x8016163C, ROM 0x000B085C
 * Callees: OBTABLE_FindObject, 0x8006A020
 */
/*
 *  8016163C: addiu       $sp, $sp, -0x28
 *  80161640: addu        $a2, $a0, $zero
 *  80161644: sw          $ra, 0x24($sp)
 *  80161648: sw          $s0, 0x20($sp)
 *  8016164C: lui         $a1, 0x8016
 *  80161650: addiu       $a1, $a1, 0x2764
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_leafgen_OnCreate);

/*
 * func_801616D4_B08F4
 * VRAM 0x801616D4, ROM 0x000B08F4
 * Callees: none
 */
/*
 *  801616D4: addiu       $sp, $sp, -0x18
 *  801616D8: sw          $s0, 0x10($sp)
 *  801616DC: addu        $s0, $a0, $zero
 *  801616E0: addu        $t2, $a1, $zero
 *  801616E4: lw          $v1, 0x30($sp)
 *  801616E8: lw          $t1, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_801616D4_B08F4);

/*
 * func_80161944_B0B64
 * VRAM 0x80161944, ROM 0x000B0B64
 * Callees: 0x800162C0, RotMatrixX, RotMatrixY, RotMatrixZ
 */
/*
 *  80161944: addiu       $sp, $sp, -0x18
 *  80161948: sw          $s0, 0x10($sp)
 *  8016194C: sw          $ra, 0x14($sp)
 *  80161950: jal         func_800162C0
 *  80161954: addu        $s0, $a0, $zero
 *  80161958: lw          $a1, 0x14($s0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_80161944_B0B64);

/*
 * func_801619A4_B0BC4
 * VRAM 0x801619A4, ROM 0x000B0BC4
 * Callees: 0x8006A020
 */
/*
 *  801619A4: addiu       $sp, $sp, -0x38
 *  801619A8: sw          $ra, 0x30($sp)
 *  801619AC: sw          $s1, 0x2C($sp)
 *  801619B0: sw          $s0, 0x28($sp)
 *  801619B4: lw          $v0, 0xFC($a0)
 *  801619B8: nop
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", func_801619A4_B0BC4);

/*
 * kungfu_leafgen_OnUpdate
 * VRAM 0x80161A44, ROM 0x000B0C64
 * Callees: none
 */
/*
 *  80161A44: addiu       $sp, $sp, -0x30
 *  80161A48: sw          $s1, 0x1C($sp)
 *  80161A4C: addu        $s1, $a0, $zero
 *  80161A50: sw          $ra, 0x28($sp)
 *  80161A54: sw          $s3, 0x24($sp)
 *  80161A58: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_leafgen_OnUpdate);

/*
 * kungfu_leafgen_OnCollide
 * VRAM 0x80161B98, ROM 0x000B0DB8
 * Callees: MATH3D_ApplyMatrixT
 */
/*
 *  80161B98: addiu       $sp, $sp, -0x30
 *  80161B9C: sw          $s0, 0x20($sp)
 *  80161BA0: addu        $s0, $a0, $zero
 *  80161BA4: sw          $ra, 0x28($sp)
 *  80161BA8: sw          $s1, 0x24($sp)
 *  80161BAC: lw          $a0, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_leafgen_OnCollide);

/*
 * kungfu_funplat_OnCreate
 * VRAM 0x80161CD4, ROM 0x000B0EF4
 * Callees: COLLIDE_PointAndTerrain
 */
/*
 *  80161CD4: addiu       $sp, $sp, -0x28
 *  80161CD8: addu        $a3, $a0, $zero
 *  80161CDC: sw          $ra, 0x20($sp)
 *  80161CE0: lw          $v0, 0x24($a3)
 *  80161CE4: nop
 *  80161CE8: bnez        $v0, . + 4 + (0x4 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_funplat_OnCreate);

/*
 * kungfu_brkbone_OnCollide
 * VRAM 0x8016206C, ROM 0x000B128C
 * Callees: 0x80027500, INSTANCE_PlainDeath
 */
/*
 *  8016206C: addiu       $sp, $sp, -0x18
 *  80162070: sw          $s0, 0x10($sp)
 *  80162074: addu        $s0, $a0, $zero
 *  80162078: sw          $ra, 0x14($sp)
 *  8016207C: lw          $a0, 0x78($s0)
 *  80162080: jal         func_80027500
 */
INCLUDE_ASM("asm/nonmatchings/KUNGFU", kungfu_brkbone_OnCollide);
