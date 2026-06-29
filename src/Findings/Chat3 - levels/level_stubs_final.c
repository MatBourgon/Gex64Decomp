/*
 * level_stubs_final.c — Channel Z (Final Boss)
 * Level overlay: FINAL
 * ROM base: 0x08A8C0, VRAM base: 0x80159720
 * Stubs: 64
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/* final_oldpoptv_OnUpdate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_oldpoptv_OnUpdate);

/*
 * final_lectro_OnCreate
 * VRAM 0x80159990, ROM 0x0008AB30
 * Callees: none
 */
/*
 *  80159990: addiu       $sp, $sp, -0x18
 *  80159994: sw          $s0, 0x10($sp)
 *  80159998: addu        $s0, $a0, $zero
 *  8015999C: sw          $ra, 0x14($sp)
 *  801599A0: lw          $v0, 0x10($s0)
 *  801599A4: nop
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_lectro_OnCreate);

/*
 * final_lectro_OnUpdate
 * VRAM 0x80159A00, ROM 0x0008ABA0
 * Callees: none
 */
/*
 *  80159A00: addiu       $sp, $sp, -0x20
 *  80159A04: sw          $s0, 0x18($sp)
 *  80159A08: addu        $s0, $a0, $zero
 *  80159A0C: sw          $ra, 0x1C($sp)
 *  80159A10: lw          $v0, 0x1C($s0)
 *  80159A14: nop
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_lectro_OnUpdate);

/*
 * final_probe_OnUpdate
 * VRAM 0x80159B80, ROM 0x0008AD20
 * Callees: none
 */
/*
 *  80159B80: addiu       $sp, $sp, -0x18
 *  80159B84: sw          $ra, 0x10($sp)
 *  80159B88: lw          $v0, 0x1C($a0)
 *  80159B8C: nop
 *  80159B90: lw          $v0, 0x2C($v0)
 *  80159B94: nop
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_probe_OnUpdate);

/*
 * final_reztvex_OnUpdate
 * VRAM 0x80159C28, ROM 0x0008ADC8
 * Callees: none
 */
/*
 *  80159C28: addiu       $sp, $sp, -0x18
 *  80159C2C: sw          $ra, 0x10($sp)
 *  80159C30: lhu         $v0, 0x56($a0)
 *  80159C34: lhu         $v1, 0x6A($a0)
 *  80159C38: addiu       $v0, $v0, 0x1
 *  80159C3C: sh          $v0, 0x56($a0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_reztvex_OnUpdate);

/* final_rezxpl_OnUpdate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_rezxpl_OnUpdate);

/*
 * final_rezbomb_OnCreate
 * VRAM 0x80159E0C, ROM 0x0008AFAC
 * Callees: OBTABLE_FindObject
 */
/*
 *  80159E0C: addiu       $sp, $sp, -0x18
 *  80159E10: sw          $s0, 0x10($sp)
 *  80159E14: addu        $s0, $a0, $zero
 *  80159E18: lui         $a0, 0x8016
 *  80159E1C: addiu       $a0, $a0, 0x1588
 *  80159E20: sw          $ra, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_rezbomb_OnCreate);

/*
 * func_80159E50_8AFF0
 * VRAM 0x80159E50, ROM 0x0008AFF0
 * Callees: none
 */
/*
 *  80159E50: addiu       $sp, $sp, -0x8
 *  80159E54: addu        $t2, $a0, $zero
 *  80159E58: addu        $t3, $a2, $zero
 *  80159E5C: lui         $t1, 0x5555
 *  80159E60: ori         $t1, $t1, 0x5556
 *  80159E64: lw          $t4, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_80159E50_8AFF0);

/*
 * func_8015A0DC_8B27C
 * VRAM 0x8015A0DC, ROM 0x0008B27C
 * Callees: 0x800162C0, RotMatrixX
 */
/*
 *  8015A0DC: addiu       $sp, $sp, -0x18
 *  8015A0E0: sw          $s0, 0x10($sp)
 *  8015A0E4: sw          $ra, 0x14($sp)
 *  8015A0E8: jal         func_800162C0
 *  8015A0EC: addu        $s0, $a0, $zero
 *  8015A0F0: lw          $a1, 0x14($s0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015A0DC_8B27C);

/*
 * func_8015A170_8B310
 * VRAM 0x8015A170, ROM 0x0008B310
 * Callees: none
 */
/*
 *  8015A170: addiu       $sp, $sp, -0x80
 *  8015A174: sw          $ra, 0x7C($sp)
 *  8015A178: sw          $fp, 0x78($sp)
 *  8015A17C: sw          $s7, 0x74($sp)
 *  8015A180: sw          $s6, 0x70($sp)
 *  8015A184: sw          $s5, 0x6C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015A170_8B310);

/*
 * func_8015A3DC_8B57C
 * VRAM 0x8015A3DC, ROM 0x0008B57C
 * Callees: 0x80016894
 */
/*
 *  8015A3DC: addiu       $sp, $sp, -0x20
 *  8015A3E0: sw          $s0, 0x18($sp)
 *  8015A3E4: sw          $ra, 0x1C($sp)
 *  8015A3E8: jal         func_80016894
 *  8015A3EC: addu        $s0, $a0, $zero
 *  8015A3F0: lh          $v1, 0x44($s0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015A3DC_8B57C);

/*
 * func_8015A434_8B5D4
 * VRAM 0x8015A434, ROM 0x0008B5D4
 * Callees: none
 */
/*
 *  8015A434: addiu       $sp, $sp, -0x38
 *  8015A438: sw          $s0, 0x30($sp)
 *  8015A43C: addu        $s0, $a0, $zero
 *  8015A440: beqz        $a1, . + 4 + (0x1D << 2)
 *  8015A444: sw          $ra, 0x34($sp)
 *  8015A448: lw          $v0, 0xC($a1)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015A434_8B5D4);

/*
 * func_8015A4C8_8B668
 * VRAM 0x8015A4C8, ROM 0x0008B668
 * Callees: none
 */
/*
 *  8015A4C8: addiu       $sp, $sp, -0x30
 *  8015A4CC: sw          $ra, 0x2C($sp)
 *  8015A4D0: beqz        $a1, . + 4 + (0x2B << 2)
 *  8015A4D4: sw          $s0, 0x28($sp)
 *  8015A4D8: lw          $v0, 0xC($a1)
 *  8015A4DC: nop
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015A4C8_8B668);

/*
 * func_8015A590_8B730
 * VRAM 0x8015A590, ROM 0x0008B730
 * Callees: none
 */
/*
 *  8015A590: addiu       $sp, $sp, -0x60
 *  8015A594: sw          $s1, 0x54($sp)
 *  8015A598: addu        $s1, $a0, $zero
 *  8015A59C: sw          $ra, 0x5C($sp)
 *  8015A5A0: sw          $s2, 0x58($sp)
 *  8015A5A4: sw          $s0, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015A590_8B730);

/*
 * func_8015A78C_8B92C
 * VRAM 0x8015A78C, ROM 0x0008B92C
 * Callees: none
 */
/*
 *  8015A78C: addiu       $sp, $sp, -0x28
 *  8015A790: sw          $s0, 0x18($sp)
 *  8015A794: addu        $s0, $a0, $zero
 *  8015A798: sw          $ra, 0x20($sp)
 *  8015A79C: sw          $s1, 0x1C($sp)
 *  8015A7A0: lw          $a1, 0xF8($s0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015A78C_8B92C);

/*
 * final_rezbomb_OnUpdate
 * VRAM 0x8015A814, ROM 0x0008B9B4
 * Callees: none
 */
/*
 *  8015A814: addiu       $sp, $sp, -0x60
 *  8015A818: sw          $s1, 0x54($sp)
 *  8015A81C: addu        $s1, $a0, $zero
 *  8015A820: sw          $ra, 0x5C($sp)
 *  8015A824: sw          $s2, 0x58($sp)
 *  8015A828: sw          $s0, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_rezbomb_OnUpdate);

/*
 * func_8015A9F0_8BB90
 * VRAM 0x8015A9F0, ROM 0x0008BB90
 * Callees: none
 */
/*
 *  8015A9F0: addiu       $sp, $sp, -0x20
 *  8015A9F4: addu        $t3, $a0, $zero
 *  8015A9F8: addu        $t2, $zero, $zero
 *  8015A9FC: addiu       $v0, $zero, 0x2D00
 *  8015AA00: lh          $v1, 0x48($t3)
 *  8015AA04: addu        $t0, $zero, $zero
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015A9F0_8BB90);

/*
 * func_8015AC70_8BE10
 * VRAM 0x8015AC70, ROM 0x0008BE10
 * Callees: none
 */
/*
 *  8015AC70: addiu       $sp, $sp, -0x30
 *  8015AC74: sw          $s1, 0x24($sp)
 *  8015AC78: addu        $s1, $a0, $zero
 *  8015AC7C: lui         $a0, 0x8007
 *  8015AC80: lw          $a0, -0x3060($a0)
 *  8015AC84: lui         $v1, 0x8007
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015AC70_8BE10);

/*
 * func_8015ADC4_8BF64
 * VRAM 0x8015ADC4, ROM 0x0008BF64
 * Callees: none
 */
/*
 *  8015ADC4: addiu       $sp, $sp, -0x28
 *  8015ADC8: sw          $ra, 0x24($sp)
 *  8015ADCC: sw          $s0, 0x20($sp)
 *  8015ADD0: lh          $v0, 0x48($a0)
 *  8015ADD4: lui         $a1, 0x8007
 *  8015ADD8: lw          $a1, -0x338($a1)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015ADC4_8BF64);

/*
 * func_8015AE98_8C038
 * VRAM 0x8015AE98, ROM 0x0008C038
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: 0x80003234
 */
/*
 *  8015AE98: lui         $v0, 0x8007
 *  8015AE9C: lw          $v0, -0x3060($v0)
 *  8015AEA0: lui         $v1, 0x8008
 *  8015AEA4: lw          $v1, -0x7A38($v1)
 *  8015AEA8: lui         $a0, 0x8007
 *  8015AEAC: lw          $a0, -0x338($a0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015AE98_8C038);

/*
 * func_8015AED8_8C078
 * VRAM 0x8015AED8, ROM 0x0008C078
 * Callees: none
 */
/*
 *  8015AED8: addiu       $sp, $sp, -0x28
 *  8015AEDC: sw          $s0, 0x18($sp)
 *  8015AEE0: addu        $s0, $a0, $zero
 *  8015AEE4: sw          $s1, 0x1C($sp)
 *  8015AEE8: addu        $s1, $a2, $zero
 *  8015AEEC: sw          $ra, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015AED8_8C078);

/*
 * func_8015B07C_8C21C
 * VRAM 0x8015B07C, ROM 0x0008C21C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: ratan2
 */
/*
 *  8015B07C: lui         $v1, 0x8007
 *  8015B080: lw          $v1, -0x3060($v1)
 *  8015B084: addiu       $sp, $sp, -0x28
 *  8015B088: sw          $s1, 0x1C($sp)
 *  8015B08C: addu        $s1, $a0, $zero
 *  8015B090: sw          $ra, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015B07C_8C21C);

/*
 * func_8015B130_8C2D0
 * VRAM 0x8015B130, ROM 0x0008C2D0
 * Callees: none
 */
/*
 *  8015B130: addiu       $sp, $sp, -0x28
 *  8015B134: sw          $s1, 0x1C($sp)
 *  8015B138: addu        $s1, $a0, $zero
 *  8015B13C: sw          $s2, 0x20($sp)
 *  8015B140: addu        $s2, $a2, $zero
 *  8015B144: addiu       $v0, $zero, 0x2D00
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015B130_8C2D0);

/*
 * func_8015B1D8_8C378
 * VRAM 0x8015B1D8, ROM 0x0008C378
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: ratan2, 0x8004ACB0
 */
/*
 *  8015B1D8: lui         $a2, 0x8007
 *  8015B1DC: lw          $a2, -0x3060($a2)
 *  8015B1E0: addiu       $sp, $sp, -0x20
 *  8015B1E4: sw          $s0, 0x18($sp)
 *  8015B1E8: addu        $s0, $a1, $zero
 *  8015B1EC: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015B1D8_8C378);

/*
 * func_8015B268_8C408
 * VRAM 0x8015B268, ROM 0x0008C408
 * Callees: none
 */
/*
 *  8015B268: addiu       $sp, $sp, -0x28
 *  8015B26C: sw          $ra, 0x24($sp)
 *  8015B270: sw          $s0, 0x20($sp)
 *  8015B274: lhu         $v0, 0x48($a0)
 *  8015B278: lw          $s0, 0x8($a1)
 *  8015B27C: addiu       $a1, $sp, 0x18
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015B268_8C408);

/*
 * func_8015B30C_8C4AC
 * VRAM 0x8015B30C, ROM 0x0008C4AC
 * Callees: none
 */
/*
 *  8015B30C: addiu       $sp, $sp, -0x60
 *  8015B310: sw          $s1, 0x54($sp)
 *  8015B314: addu        $s1, $a1, $zero
 *  8015B318: sw          $ra, 0x5C($sp)
 *  8015B31C: sw          $s2, 0x58($sp)
 *  8015B320: sw          $s0, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015B30C_8C4AC);

/*
 * final_rezzull_OnCreate
 * VRAM 0x8015B4C0, ROM 0x0008C660
 * Callees: none
 */
/*
 *  8015B4C0: addiu       $sp, $sp, -0x20
 *  8015B4C4: sw          $s0, 0x10($sp)
 *  8015B4C8: addu        $s0, $a0, $zero
 *  8015B4CC: sw          $s2, 0x18($sp)
 *  8015B4D0: addu        $s2, $a1, $zero
 *  8015B4D4: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_rezzull_OnCreate);

/*
 * func_8015B658_8C7F8
 * VRAM 0x8015B658, ROM 0x0008C7F8
 * Callees: none
 */
/*
 *  8015B658: addiu       $sp, $sp, -0x38
 *  8015B65C: lw          $v0, 0x48($sp)
 *  8015B660: sw          $s3, 0x24($sp)
 *  8015B664: addu        $s3, $a2, $zero
 *  8015B668: sw          $s2, 0x20($sp)
 *  8015B66C: addu        $s2, $a3, $zero
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015B658_8C7F8);

/*
 * func_8015BB78_8CD18
 * VRAM 0x8015BB78, ROM 0x0008CD18
 * Callees: none
 */
/*
 *  8015BB78: addiu       $sp, $sp, -0x30
 *  8015BB7C: sw          $s3, 0x24($sp)
 *  8015BB80: addu        $s3, $a0, $zero
 *  8015BB84: sw          $s2, 0x20($sp)
 *  8015BB88: addu        $s2, $a1, $zero
 *  8015BB8C: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015BB78_8CD18);

/*
 * func_8015BD84_8CF24
 * VRAM 0x8015BD84, ROM 0x0008CF24
 * Callees: none
 */
/*
 *  8015BD84: addiu       $sp, $sp, -0x80
 *  8015BD88: sw          $s2, 0x70($sp)
 *  8015BD8C: addu        $s2, $a0, $zero
 *  8015BD90: sw          $s3, 0x74($sp)
 *  8015BD94: addu        $s3, $a1, $zero
 *  8015BD98: sw          $ra, 0x78($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015BD84_8CF24);

/*
 * func_8015BFB8_8D158
 * VRAM 0x8015BFB8, ROM 0x0008D158
 * Callees: 0x800170E8
 */
/*
 *  8015BFB8: addiu       $sp, $sp, -0x30
 *  8015BFBC: sw          $ra, 0x2C($sp)
 *  8015BFC0: sw          $s0, 0x28($sp)
 *  8015BFC4: lw          $s0, 0xFC($a0)
 *  8015BFC8: nop
 *  8015BFCC: lw          $v0, 0x54($s0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015BFB8_8D158);

/*
 * func_8015C0A0_8D240
 * VRAM 0x8015C0A0, ROM 0x0008D240
 * Callees: none
 */
/*
 *  8015C0A0: addiu       $sp, $sp, -0x28
 *  8015C0A4: sw          $s1, 0x1C($sp)
 *  8015C0A8: addu        $s1, $a0, $zero
 *  8015C0AC: sw          $ra, 0x24($sp)
 *  8015C0B0: sw          $s2, 0x20($sp)
 *  8015C0B4: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015C0A0_8D240);

/*
 * func_8015C220_8D3C0
 * VRAM 0x8015C220, ROM 0x0008D3C0
 * Callees: none
 */
/*
 *  8015C220: addiu       $sp, $sp, -0x20
 *  8015C224: sw          $ra, 0x18($sp)
 *  8015C228: lw          $v0, 0x8($a1)
 *  8015C22C: nop
 *  8015C230: lw          $v0, 0xE0($v0)
 *  8015C234: lw          $v1, 0xFC($a0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015C220_8D3C0);

/*
 * func_8015C39C_8D53C
 * VRAM 0x8015C39C, ROM 0x0008D53C
 * Callees: none
 */
/*
 *  8015C39C: addiu       $sp, $sp, -0x40
 *  8015C3A0: sw          $s2, 0x30($sp)
 *  8015C3A4: addu        $s2, $a0, $zero
 *  8015C3A8: sw          $s3, 0x34($sp)
 *  8015C3AC: addu        $s3, $a1, $zero
 *  8015C3B0: sw          $ra, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015C39C_8D53C);

/*
 * func_8015C850_8D9F0
 * VRAM 0x8015C850, ROM 0x0008D9F0
 * Callees: none
 */
/*
 *  8015C850: addiu       $sp, $sp, -0x40
 *  8015C854: sw          $s1, 0x34($sp)
 *  8015C858: addu        $s1, $a1, $zero
 *  8015C85C: sw          $s2, 0x38($sp)
 *  8015C860: addu        $s2, $a2, $zero
 *  8015C864: sw          $ra, 0x3C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015C850_8D9F0);

/*
 * func_8015C9D0_8DB70
 * VRAM 0x8015C9D0, ROM 0x0008DB70
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C9D0: lui         $v0, 0x2AAA
 *  8015C9D4: lui         $v1, 0x8016
 *  8015C9D8: lw          $v1, 0x153C($v1)
 *  8015C9DC: ori         $v0, $v0, 0xAAAB
 *  8015C9E0: addiu       $v1, $v1, 0x1
 *  8015C9E4: mult        $v1, $v0
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015C9D0_8DB70);

/*
 * func_8015CAF8_8DC98
 * VRAM 0x8015CAF8, ROM 0x0008DC98
 * Callees: none
 */
/*
 *  8015CAF8: addiu       $a3, $zero, 0x7
 *  8015CAFC: addiu       $a2, $a0, 0x7
 *  8015CB00: andi        $v1, $a1, 0xF
 *  8015CB04: sltiu       $v0, $v1, 0xA
 *  8015CB08: beqz        $v0, . + 4 + (0x3 << 2)
 *  8015CB0C: sra         $a1, $a1, 4
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015CAF8_8DC98);

/*
 * func_8015CB34_8DCD4
 * VRAM 0x8015CB34, ROM 0x0008DCD4
 * Callees: none
 */
/*
 *  8015CB34: addiu       $a3, $zero, 0x3
 *  8015CB38: addiu       $a2, $a0, 0x3
 *  8015CB3C: andi        $v1, $a1, 0xF
 *  8015CB40: sll         $v0, $a1, 16
 *  8015CB44: sra         $a1, $v0, 20
 *  8015CB48: sltiu       $v0, $v1, 0xA
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015CB34_8DCD4);

/*
 * func_8015CB70_8DD10
 * VRAM 0x8015CB70, ROM 0x0008DD10
 * Callees: osSyncPrintf
 */
/*
 *  8015CB70: addiu       $sp, $sp, -0x30
 *  8015CB74: slti        $a2, $a2, 0x29
 *  8015CB78: sw          $ra, 0x2C($sp)
 *  8015CB7C: sw          $s2, 0x28($sp)
 *  8015CB80: sw          $s1, 0x24($sp)
 *  8015CB84: sw          $s0, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015CB70_8DD10);

/*
 * func_8015CC64_8DE04
 * VRAM 0x8015CC64, ROM 0x0008DE04
 * Callees: none
 */
/*
 *  8015CC64: addiu       $sp, $sp, -0x30
 *  8015CC68: sw          $s2, 0x28($sp)
 *  8015CC6C: addu        $s2, $a0, $zero
 *  8015CC70: addiu       $v0, $zero, 0x96
 *  8015CC74: slti        $a2, $a2, 0x29
 *  8015CC78: sw          $ra, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015CC64_8DE04);

/*
 * func_8015CD54_8DEF4
 * VRAM 0x8015CD54, ROM 0x0008DEF4
 * Callees: none
 */
/*
 *  8015CD54: addiu       $sp, $sp, -0x38
 *  8015CD58: slti        $a2, $a2, 0x29
 *  8015CD5C: sw          $ra, 0x34($sp)
 *  8015CD60: sw          $s4, 0x30($sp)
 *  8015CD64: sw          $s3, 0x2C($sp)
 *  8015CD68: sw          $s2, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015CD54_8DEF4);

/*
 * func_8015CDF0_8DF90
 * VRAM 0x8015CDF0, ROM 0x0008DF90
 * Callees: osSyncPrintf, 0x8015CB34
 */
/*
 *  8015CDF0: addiu       $sp, $sp, -0x30
 *  8015CDF4: slti        $a2, $a2, 0x29
 *  8015CDF8: sw          $ra, 0x28($sp)
 *  8015CDFC: sw          $s1, 0x24($sp)
 *  8015CE00: bnez        $a2, . + 4 + (0x3C << 2)
 *  8015CE04: sw          $s0, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015CDF0_8DF90);

/*
 * func_8015CF08_8E0A8
 * VRAM 0x8015CF08, ROM 0x0008E0A8
 * Callees: none
 */
/*
 *  8015CF08: addiu       $sp, $sp, -0x18
 *  8015CF0C: slti        $a2, $a2, 0x29
 *  8015CF10: bnez        $a2, . + 4 + (0x3D << 2)
 *  8015CF14: sw          $ra, 0x10($sp)
 *  8015CF18: addiu       $a0, $zero, 0x78
 *  8015CF1C: addiu       $a1, $zero, 0x5A
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015CF08_8E0A8);

/*
 * func_8015D018_8E1B8
 * VRAM 0x8015D018, ROM 0x0008E1B8
 * Callees: OBTABLE_FindObject, 0x8006A020
 */
/*
 *  8015D018: addiu       $sp, $sp, -0x68
 *  8015D01C: sw          $s6, 0x58($sp)
 *  8015D020: addu        $s6, $a1, $zero
 *  8015D024: sw          $s3, 0x4C($sp)
 *  8015D028: addu        $s3, $a2, $zero
 *  8015D02C: sw          $s0, 0x40($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015D018_8E1B8);

/*
 * final_rezzull_OnUpdate
 * VRAM 0x8015D1E8, ROM 0x0008E388
 * Callees: 0x80000F24
 */
/*
 *  8015D1E8: addiu       $sp, $sp, -0x70
 *  8015D1EC: sw          $s2, 0x60($sp)
 *  8015D1F0: addu        $s2, $a0, $zero
 *  8015D1F4: sw          $s3, 0x64($sp)
 *  8015D1F8: addu        $s3, $a1, $zero
 *  8015D1FC: sw          $ra, 0x68($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_rezzull_OnUpdate);

/*
 * final_rezzull_OnCollide
 * VRAM 0x8015E3EC, ROM 0x0008F58C
 * Callees: none
 */
/*
 *  8015E3EC: addiu       $sp, $sp, -0x40
 *  8015E3F0: sw          $s0, 0x30($sp)
 *  8015E3F4: addu        $s0, $a0, $zero
 *  8015E3F8: sw          $ra, 0x38($sp)
 *  8015E3FC: sw          $s1, 0x34($sp)
 *  8015E400: lw          $s1, 0xFC($s0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_rezzull_OnCollide);

/*
 * func_8015E788_8F928
 * VRAM 0x8015E788, ROM 0x0008F928
 * Callees: none
 */
/*
 *  8015E788: addiu       $sp, $sp, -0x50
 *  8015E78C: sw          $s1, 0x44($sp)
 *  8015E790: addu        $s1, $a0, $zero
 *  8015E794: sw          $ra, 0x48($sp)
 *  8015E798: sw          $s0, 0x40($sp)
 *  8015E79C: lw          $v0, 0x108($s1)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015E788_8F928);

/*
 * final_popper_OnCreate
 * VRAM 0x8015E950, ROM 0x0008FAF0
 * Callees: OBTABLE_FindObject
 */
/*
 *  8015E950: addiu       $sp, $sp, -0x18
 *  8015E954: sw          $s0, 0x10($sp)
 *  8015E958: addu        $s0, $a0, $zero
 *  8015E95C: addiu       $v0, $zero, 0x2
 *  8015E960: sw          $ra, 0x14($sp)
 *  8015E964: sh          $v0, 0xFC($s0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_popper_OnCreate);

/*
 * final_popper_OnUpdate
 * VRAM 0x8015E9B8, ROM 0x0008FB58
 * Callees: none
 */
/*
 *  8015E9B8: addiu       $sp, $sp, -0x28
 *  8015E9BC: sw          $s0, 0x18($sp)
 *  8015E9C0: addu        $s0, $a0, $zero
 *  8015E9C4: sw          $s1, 0x1C($sp)
 *  8015E9C8: sw          $ra, 0x20($sp)
 *  8015E9CC: lh          $v1, 0xFC($s0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_popper_OnUpdate);

/*
 * final_popper_OnCollide
 * VRAM 0x8015ED38, ROM 0x0008FED8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015ED38: lw          $v0, 0x78($a0)
 *  8015ED3C: nop
 *  8015ED40: lw          $v0, 0x14($v0)
 *  8015ED44: nop
 *  8015ED48: lw          $v0, 0x18($v0)
 *  8015ED4C: nop
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_popper_OnCollide);

/*
 * final_finaltv_OnUpdate
 * VRAM 0x8015EDC4, ROM 0x0008FF64
 * Callees: none
 */
/*
 *  8015EDC4: addiu       $sp, $sp, -0x20
 *  8015EDC8: sw          $s0, 0x18($sp)
 *  8015EDCC: addu        $s0, $a0, $zero
 *  8015EDD0: sw          $ra, 0x1C($sp)
 *  8015EDD4: lw          $v0, 0xFC($s0)
 *  8015EDD8: nop
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_finaltv_OnUpdate);

/*
 * final_finaltv_OnCollide
 * VRAM 0x8015EE74, ROM 0x00090014
 * Callees: none
 */
/*
 *  8015EE74: addiu       $sp, $sp, -0x18
 *  8015EE78: sw          $ra, 0x10($sp)
 *  8015EE7C: lw          $v0, 0x78($a0)
 *  8015EE80: nop
 *  8015EE84: lw          $v0, 0x14($v0)
 *  8015EE88: nop
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_finaltv_OnCollide);

/*
 * func_8015EEF4_90094
 * VRAM 0x8015EEF4, ROM 0x00090094
 * Callees: 0x8006A020
 */
/*
 *  8015EEF4: addiu       $sp, $sp, -0x48
 *  8015EEF8: sw          $s1, 0x3C($sp)
 *  8015EEFC: addu        $s1, $a2, $zero
 *  8015EF00: sw          $ra, 0x40($sp)
 *  8015EF04: beqz        $a1, . + 4 + (0x50 << 2)
 *  8015EF08: sw          $s0, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015EEF4_90094);

/*
 * func_8015F05C_901FC
 * VRAM 0x8015F05C, ROM 0x000901FC
 * Callees: 0x800170E8, _COLLIDE_MakeNormal, CAMERA_LengthSVector
 */
/*
 *  8015F05C: addiu       $sp, $sp, -0x30
 *  8015F060: beqz        $a1, . + 4 + (0x15 << 2)
 *  8015F064: sw          $ra, 0x28($sp)
 *  8015F068: lw          $v0, 0xC($a1)
 *  8015F06C: nop
 *  8015F070: lw          $a0, 0x1C($v0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015F05C_901FC);

/*
 * func_8015F0C8_90268
 * VRAM 0x8015F0C8, ROM 0x00090268
 * Callees: _COLLIDE_MakeNormal, CAMERA_LengthSVector
 */
/*
 *  8015F0C8: addiu       $sp, $sp, -0x20
 *  8015F0CC: sw          $s0, 0x18($sp)
 *  8015F0D0: addu        $s0, $a3, $zero
 *  8015F0D4: sw          $ra, 0x1C($sp)
 *  8015F0D8: jal         func_80012A1C
 *  8015F0DC: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015F0C8_90268);

/*
 * func_8015F13C_902DC
 * VRAM 0x8015F13C, ROM 0x000902DC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F13C: lui         $v0, 0x8016
 *  8015F140: lw          $v0, 0x1544($v0)
 *  8015F144: nop
 *  8015F148: bnez        $v0, . + 4 + (0x14 << 2)
 *  8015F14C: nop
 *  8015F150: lhu         $v0, 0x0($a0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015F13C_902DC);

/*
 * func_8015F200_903A0
 * VRAM 0x8015F200, ROM 0x000903A0
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F200: lui         $v0, 0x8016
 *  8015F204: lw          $v0, 0x1544($v0)
 *  8015F208: addiu       $sp, $sp, -0x18
 *  8015F20C: beqz        $v0, . + 4 + (0x96 << 2)
 *  8015F210: sw          $ra, 0x10($sp)
 *  8015F214: lui         $t0, 0x8015
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015F200_903A0);

/*
 * func_8015F480_90620
 * VRAM 0x8015F480, ROM 0x00090620
 * Callees: none
 */
/*
 *  8015F480: addiu       $sp, $sp, -0xF0
 *  8015F484: sw          $s1, 0xCC($sp)
 *  8015F488: addu        $s1, $a0, $zero
 *  8015F48C: sw          $s3, 0xD4($sp)
 *  8015F490: addu        $s3, $a1, $zero
 *  8015F494: sw          $ra, 0xE8($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015F480_90620);

/*
 * func_8015F818_909B8
 * VRAM 0x8015F818, ROM 0x000909B8
 * Callees: ratan2
 */
/*
 *  8015F818: addiu       $sp, $sp, -0x28
 *  8015F81C: sw          $s1, 0x1C($sp)
 *  8015F820: addu        $s1, $a0, $zero
 *  8015F824: addu        $v1, $a1, $zero
 *  8015F828: sw          $ra, 0x24($sp)
 *  8015F82C: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015F818_909B8);

/*
 * func_8015F964_90B04
 * VRAM 0x8015F964, ROM 0x00090B04
 * Callees: none
 */
/*
 *  8015F964: addiu       $sp, $sp, -0x28
 *  8015F968: sw          $ra, 0x24($sp)
 *  8015F96C: sw          $s2, 0x20($sp)
 *  8015F970: sw          $s1, 0x1C($sp)
 *  8015F974: sw          $s0, 0x18($sp)
 *  8015F978: lw          $t2, 0x24($a0)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015F964_90B04);

/*
 * func_8015FAF8_90C98
 * VRAM 0x8015FAF8, ROM 0x00090C98
 * Callees: CAMERA_LengthSVector
 */
/*
 *  8015FAF8: addiu       $sp, $sp, -0x40
 *  8015FAFC: sw          $s1, 0x34($sp)
 *  8015FB00: addu        $s1, $a0, $zero
 *  8015FB04: lui         $a0, 0x8007
 *  8015FB08: lw          $a0, -0x3060($a0)
 *  8015FB0C: sw          $ra, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015FAF8_90C98);

/*
 * func_8015FC3C_90DDC
 * VRAM 0x8015FC3C, ROM 0x00090DDC
 * Callees: 0x8006A020, OBTABLE_FindObject
 */
/*
 *  8015FC3C: addiu       $sp, $sp, -0x60
 *  8015FC40: sw          $s2, 0x50($sp)
 *  8015FC44: addu        $s2, $a0, $zero
 *  8015FC48: lui         $a0, 0x8016
 *  8015FC4C: addiu       $a0, $a0, 0x1588
 *  8015FC50: sw          $ra, 0x5C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", func_8015FC3C_90DDC);

/*
 * final_frez_OnUpdate
 * VRAM 0x8015FEAC, ROM 0x0009104C
 * Callees: none
 */
/*
 *  8015FEAC: addiu       $sp, $sp, -0xA0
 *  8015FEB0: sw          $s0, 0x88($sp)
 *  8015FEB4: addu        $s0, $a0, $zero
 *  8015FEB8: sw          $s4, 0x98($sp)
 *  8015FEBC: addu        $s4, $a1, $zero
 *  8015FEC0: sw          $ra, 0x9C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_frez_OnUpdate);

/*
 * final_rezcam_OnUpdate
 * VRAM 0x80161180, ROM 0x00092320
 * Callees: 0x80002734, 0x80005E8C
 */
/*
 *  80161180: addiu       $sp, $sp, -0x50
 *  80161184: sw          $s1, 0x34($sp)
 *  80161188: addu        $s1, $a0, $zero
 *  8016118C: sw          $s2, 0x38($sp)
 *  80161190: addu        $s2, $a1, $zero
 *  80161194: sw          $ra, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/FINAL", final_rezcam_OnUpdate);
