/*
 * level_stubs_rta.c — Sea Span (N64 Exclusive)
 * Level overlay: RTA
 * ROM base: 0x0D9D90, VRAM base: 0x80159720
 * Stubs: 61
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/* rta_zgrate_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zgrate_OnCreate);

/*
 * rta_zgrate_OnUpdate
 * VRAM 0x80159738, ROM 0x000D9DA8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159738: lui         $v0, 0x8016
 *  8015973C: lb          $v0, -0x10F0($v0)
 *  80159740: nop
 *  80159744: beqz        $v0, . + 4 + (0xA << 2)
 *  80159748: addiu       $sp, $sp, -0x8
 *  8015974C: lh          $v0, 0x4C($a0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zgrate_OnUpdate);

/*
 * rta_zshark_OnCreate
 * VRAM 0x80159784, ROM 0x000D9DF4
 * Callees: none
 */
/*
 *  80159784: addiu       $sp, $sp, -0x60
 *  80159788: sw          $s1, 0x54($sp)
 *  8015978C: addu        $s1, $a0, $zero
 *  80159790: sw          $ra, 0x5C($sp)
 *  80159794: sw          $s2, 0x58($sp)
 *  80159798: sw          $s0, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zshark_OnCreate);

/*
 * rta_zshark_OnUpdate
 * VRAM 0x8015986C, ROM 0x000D9EDC
 * Callees: none
 */
/*
 *  8015986C: addiu       $sp, $sp, -0xA8
 *  80159870: sw          $s1, 0x94($sp)
 *  80159874: addu        $s1, $a0, $zero
 *  80159878: sw          $ra, 0xA4($sp)
 *  8015987C: sw          $s4, 0xA0($sp)
 *  80159880: sw          $s3, 0x9C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zshark_OnUpdate);

/*
 * rta_zshark_OnCollide
 * VRAM 0x8015A1A8, ROM 0x000DA818
 * Callees: none
 */
/*
 *  8015A1A8: addiu       $sp, $sp, -0x18
 *  8015A1AC: sw          $s0, 0x10($sp)
 *  8015A1B0: addu        $s0, $a0, $zero
 *  8015A1B4: addu        $a2, $a1, $zero
 *  8015A1B8: sw          $ra, 0x14($sp)
 *  8015A1BC: lw          $a3, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zshark_OnCollide);

/*
 * func_8015A2B0_DA920
 * VRAM 0x8015A2B0, ROM 0x000DA920
 * Callees: none
 */
/*
 *  8015A2B0: addiu       $sp, $sp, -0x30
 *  8015A2B4: sw          $s0, 0x20($sp)
 *  8015A2B8: addu        $s0, $a0, $zero
 *  8015A2BC: sw          $ra, 0x28($sp)
 *  8015A2C0: sw          $s1, 0x24($sp)
 *  8015A2C4: lw          $a0, 0x38($s0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015A2B0_DA920);

/* rta_eel_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_eel_OnCreate);

/* rta_eel_OnUpdate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_eel_OnUpdate);

/* rta_eel_OnCollide — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_eel_OnCollide);

/*
 * rta_zturtle_OnCreate
 * VRAM 0x8015A8F4, ROM 0x000DAF64
 * Callees: none
 */
/*
 *  8015A8F4: addiu       $sp, $sp, -0x18
 *  8015A8F8: sw          $s0, 0x10($sp)
 *  8015A8FC: sw          $ra, 0x14($sp)
 *  8015A900: jal         func_800480F8
 *  8015A904: addu        $s0, $a0, $zero
 *  8015A908: addiu       $v0, $zero, 0x5
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zturtle_OnCreate);

/*
 * rta_zturtle_OnUpdate
 * VRAM 0x8015A948, ROM 0x000DAFB8
 * Callees: none
 */
/*
 *  8015A948: addiu       $sp, $sp, -0x38
 *  8015A94C: sw          $s1, 0x24($sp)
 *  8015A950: addu        $s1, $a0, $zero
 *  8015A954: addu        $a2, $a1, $zero
 *  8015A958: addiu       $v0, $zero, 0x5
 *  8015A95C: sw          $ra, 0x34($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zturtle_OnUpdate);

/*
 * rta_zturtle_OnCollide
 * VRAM 0x8015ABDC, ROM 0x000DB24C
 * Callees: none
 */
/*
 *  8015ABDC: addiu       $sp, $sp, -0x18
 *  8015ABE0: addu        $a2, $a0, $zero
 *  8015ABE4: sw          $ra, 0x10($sp)
 *  8015ABE8: lw          $v0, 0xFC($a2)
 *  8015ABEC: nop
 *  8015ABF0: bnez        $v0, . + 4 + (0x25 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zturtle_OnCollide);

/*
 * rta_zarchsig_OnCollide
 * VRAM 0x8015AC98, ROM 0x000DB308
 * Callees: none
 */
/*
 *  8015AC98: addiu       $sp, $sp, -0x28
 *  8015AC9C: sw          $s2, 0x20($sp)
 *  8015ACA0: addu        $s2, $a0, $zero
 *  8015ACA4: sw          $ra, 0x24($sp)
 *  8015ACA8: sw          $s1, 0x1C($sp)
 *  8015ACAC: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zarchsig_OnCollide);

/*
 * rta_count_OnCreate
 * VRAM 0x8015AD64, ROM 0x000DB3D4
 * Callees: none
 */
/*
 *  8015AD64: addiu       $v0, $zero, 0x20
 *  8015AD68: sw          $v0, 0xFC($a0)
 *  8015AD6C: addiu       $v0, $zero, 0x15E
 *  8015AD70: sw          $v0, 0x100($a0)
 *  8015AD74: lw          $v0, 0x10($a0)
 *  8015AD78: lui         $v1, 0x8007
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_count_OnCreate);

/*
 * rta_count_OnUpdate
 * VRAM 0x8015AD9C, ROM 0x000DB40C
 * Callees: 0x8002E350
 */
/*
 *  8015AD9C: addiu       $sp, $sp, -0x18
 *  8015ADA0: addu        $a2, $a0, $zero
 *  8015ADA4: sw          $ra, 0x10($sp)
 *  8015ADA8: lw          $v0, 0x100($a2)
 *  8015ADAC: nop
 *  8015ADB0: slti        $v0, $v0, 0x7D1
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_count_OnUpdate);

/*
 * rta_zcargo_OnCollide
 * VRAM 0x8015AE58, ROM 0x000DB4C8
 * Callees: 0x80018B60
 */
/*
 *  8015AE58: addiu       $sp, $sp, -0x28
 *  8015AE5C: sw          $s0, 0x18($sp)
 *  8015AE60: addu        $s0, $a0, $zero
 *  8015AE64: sw          $ra, 0x20($sp)
 *  8015AE68: sw          $s1, 0x1C($sp)
 *  8015AE6C: lw          $v0, 0x18($s0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zcargo_OnCollide);

/*
 * rta_zwleak_OnCreate
 * VRAM 0x8015AEF4, ROM 0x000DB564
 * Callees: none
 */
/*
 *  8015AEF4: addiu       $sp, $sp, -0x20
 *  8015AEF8: sw          $s1, 0x14($sp)
 *  8015AEFC: addu        $s1, $a0, $zero
 *  8015AF00: addiu       $a0, $s1, 0xFC
 *  8015AF04: addu        $a1, $zero, $zero
 *  8015AF08: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zwleak_OnCreate);

/*
 * rta_zwleak_OnUpdate
 * VRAM 0x8015B028, ROM 0x000DB698
 * Callees: 0x8015B1D4, 0x8015A2B0
 */
/*
 *  8015B028: addiu       $sp, $sp, -0x18
 *  8015B02C: sw          $s0, 0x10($sp)
 *  8015B030: addu        $s0, $a0, $zero
 *  8015B034: sw          $ra, 0x14($sp)
 *  8015B038: lw          $v0, 0x104($s0)
 *  8015B03C: lui         $v1, 0x8016
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zwleak_OnUpdate);

/*
 * rta_zwleak_OnCollide
 * VRAM 0x8015B0E4, ROM 0x000DB754
 * Callees: none
 */
/*
 *  8015B0E4: addiu       $sp, $sp, -0x18
 *  8015B0E8: sw          $ra, 0x14($sp)
 *  8015B0EC: sw          $s0, 0x10($sp)
 *  8015B0F0: lw          $v1, 0x110($a0)
 *  8015B0F4: lw          $v0, 0x100($a0)
 *  8015B0F8: nop
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zwleak_OnCollide);

/*
 * func_8015B1D4_DB844
 * VRAM 0x8015B1D4, ROM 0x000DB844
 * Callees: OBTABLE_FindObject, 0x8006A020
 */
/*
 *  8015B1D4: addiu       $sp, $sp, -0x50
 *  8015B1D8: sw          $s0, 0x28($sp)
 *  8015B1DC: addu        $s0, $a0, $zero
 *  8015B1E0: lui         $a0, 0x8016
 *  8015B1E4: addiu       $a0, $a0, -0x118C
 *  8015B1E8: sw          $ra, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015B1D4_DB844);

/*
 * func_8015B4EC_DBB5C
 * VRAM 0x8015B4EC, ROM 0x000DBB5C
 * Callees: none
 */
/*
 *  8015B4EC: addiu       $sp, $sp, -0x18
 *  8015B4F0: addu        $a2, $a0, $zero
 *  8015B4F4: sw          $ra, 0x10($sp)
 *  8015B4F8: lh          $v0, 0x20($a2)
 *  8015B4FC: lh          $t0, 0x50($a2)
 *  8015B500: lh          $v1, 0x56($a2)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015B4EC_DBB5C);

/*
 * rta_zgeyser_OnCreate
 * VRAM 0x8015B5A8, ROM 0x000DBC18
 * Callees: none
 */
/*
 *  8015B5A8: addiu       $sp, $sp, -0x18
 *  8015B5AC: sw          $s0, 0x10($sp)
 *  8015B5B0: addu        $s0, $a0, $zero
 *  8015B5B4: lui         $a0, 0x8016
 *  8015B5B8: addiu       $a0, $a0, -0x118C
 *  8015B5BC: sw          $ra, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zgeyser_OnCreate);

/*
 * rta_zgeyser_OnUpdate
 * VRAM 0x8015B5FC, ROM 0x000DBC6C
 * Callees: none
 */
/*
 *  8015B5FC: addiu       $sp, $sp, -0x80
 *  8015B600: sw          $s1, 0x5C($sp)
 *  8015B604: addu        $s1, $a0, $zero
 *  8015B608: sw          $ra, 0x7C($sp)
 *  8015B60C: sw          $fp, 0x78($sp)
 *  8015B610: sw          $s7, 0x74($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zgeyser_OnUpdate);

/*
 * rta_zgeyser_OnCollide
 * VRAM 0x8015B92C, ROM 0x000DBF9C
 * Callees: COLLIDE_UpdateAllTransforms
 */
/*
 *  8015B92C: addiu       $sp, $sp, -0x38
 *  8015B930: addu        $a2, $a1, $zero
 *  8015B934: sw          $ra, 0x34($sp)
 *  8015B938: sw          $s0, 0x30($sp)
 *  8015B93C: lw          $v0, 0x78($a0)
 *  8015B940: lw          $v1, 0xC($a2)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zgeyser_OnCollide);

/*
 * rta_zdoor_OnCreate
 * VRAM 0x8015BA78, ROM 0x000DC0E8
 * Callees: none
 */
/*
 *  8015BA78: addiu       $sp, $sp, -0x20
 *  8015BA7C: sw          $s1, 0x14($sp)
 *  8015BA80: addu        $s1, $a0, $zero
 *  8015BA84: sw          $ra, 0x18($sp)
 *  8015BA88: sw          $s0, 0x10($sp)
 *  8015BA8C: lw          $a0, 0x10($s1)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zdoor_OnCreate);

/*
 * rta_zdoor_OnUpdate
 * VRAM 0x8015BB84, ROM 0x000DC1F4
 * Callees: none
 */
/*
 *  8015BB84: addiu       $sp, $sp, -0x20
 *  8015BB88: sw          $s0, 0x10($sp)
 *  8015BB8C: addu        $s0, $a0, $zero
 *  8015BB90: sw          $ra, 0x18($sp)
 *  8015BB94: sw          $s1, 0x14($sp)
 *  8015BB98: lw          $a2, 0x24($s0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zdoor_OnUpdate);

/*
 * func_8015BD04_DC374
 * VRAM 0x8015BD04, ROM 0x000DC374
 * Callees: none
 */
/*
 *  8015BD04: addu        $a1, $a0, $zero
 *  8015BD08: lw          $v0, 0x24($a1)
 *  8015BD0C: lw          $v1, 0xF4($a1)
 *  8015BD10: lw          $v0, 0x0($v0)
 *  8015BD14: nop
 *  8015BD18: bne         $v1, $v0, . + 4 + (0x7 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015BD04_DC374);

/*
 * func_8015BD54_DC3C4
 * VRAM 0x8015BD54, ROM 0x000DC3C4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015BD54: lw          $v0, 0xF8($a0)
 *  8015BD58: lw          $a1, 0x24($a0)
 *  8015BD5C: nop
 *  8015BD60: bnez        $v0, . + 4 + (0x3 << 2)
 *  8015BD64: addu        $a2, $zero, $zero
 *  8015BD68: j           func_8015BE28
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015BD54_DC3C4);

/*
 * rta_zswitch_OnCreate
 * VRAM 0x8015BE30, ROM 0x000DC4A0
 * Callees: none
 */
/*
 *  8015BE30: addiu       $sp, $sp, -0x20
 *  8015BE34: sw          $s0, 0x10($sp)
 *  8015BE38: addu        $s0, $a0, $zero
 *  8015BE3C: sw          $ra, 0x18($sp)
 *  8015BE40: sw          $s1, 0x14($sp)
 *  8015BE44: lw          $v1, 0x10($s0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zswitch_OnCreate);

/* rta_zswitch_OnUpdate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zswitch_OnUpdate);

/* rta_zswitch_OnCollide — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zswitch_OnCollide);

/*
 * rta_zswitchm_OnCreate
 * VRAM 0x8015C24C, ROM 0x000DC8BC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C24C: lui         $v0, 0x8016
 *  8015C250: lw          $v0, -0x11F8($v0)
 *  8015C254: lui         $v1, 0x8016
 *  8015C258: lw          $v1, -0x11FC($v1)
 *  8015C25C: addiu       $sp, $sp, -0x20
 *  8015C260: sw          $s0, 0x10($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zswitchm_OnCreate);

/*
 * func_8015C344_DC9B4
 * VRAM 0x8015C344, ROM 0x000DC9B4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C344: beqz        $a0, . + 4 + (0x14 << 2)
 *  8015C348: addu        $v1, $zero, $zero
 *  8015C34C: lw          $a0, 0x18($a0)
 *  8015C350: nop
 *  8015C354: beqz        $a0, . + 4 + (0x10 << 2)
 *  8015C358: nop
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015C344_DC9B4);

/*
 * rta_zbubgen_OnCreate
 * VRAM 0x8015C3A0, ROM 0x000DCA10
 * Callees: none
 */
/*
 *  8015C3A0: addiu       $sp, $sp, -0x18
 *  8015C3A4: sw          $s0, 0x10($sp)
 *  8015C3A8: addu        $s0, $a0, $zero
 *  8015C3AC: sw          $ra, 0x14($sp)
 *  8015C3B0: lw          $v1, 0x10($s0)
 *  8015C3B4: lui         $v0, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zbubgen_OnCreate);

/*
 * rta_zbubgen_OnUpdate
 * VRAM 0x8015C440, ROM 0x000DCAB0
 * Callees: none
 */
/*
 *  8015C440: addiu       $sp, $sp, -0x38
 *  8015C444: sw          $s1, 0x24($sp)
 *  8015C448: addu        $s1, $a0, $zero
 *  8015C44C: sw          $s3, 0x2C($sp)
 *  8015C450: sw          $ra, 0x30($sp)
 *  8015C454: sw          $s2, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zbubgen_OnUpdate);

/*
 * rta_zarrow_OnCreate
 * VRAM 0x8015C81C, ROM 0x000DCE8C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C81C: lw          $v1, 0x10($a0)
 *  8015C820: lui         $v0, 0x2
 *  8015C824: and         $v0, $v1, $v0
 *  8015C828: beqz        $v0, . + 4 + (0x8 << 2)
 *  8015C82C: lui         $v0, 0x1
 *  8015C830: lw          $v0, 0x1C($a0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zarrow_OnCreate);

/*
 * rta_zarrow_OnUpdate
 * VRAM 0x8015C864, ROM 0x000DCED4
 * Callees: none
 */
/*
 *  8015C864: addiu       $sp, $sp, -0x18
 *  8015C868: sw          $ra, 0x10($sp)
 *  8015C86C: lw          $v0, 0xFC($a0)
 *  8015C870: nop
 *  8015C874: addiu       $v0, $v0, 0x1
 *  8015C878: sw          $v0, 0xFC($a0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zarrow_OnUpdate);

/*
 * func_8015C8C8_DCF38
 * VRAM 0x8015C8C8, ROM 0x000DCF38
 * Callees: none
 */
/*
 *  8015C8C8: addiu       $sp, $sp, -0x38
 *  8015C8CC: sw          $s1, 0x2C($sp)
 *  8015C8D0: addu        $s1, $a3, $zero
 *  8015C8D4: sw          $ra, 0x34($sp)
 *  8015C8D8: sw          $s2, 0x30($sp)
 *  8015C8DC: sw          $s0, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015C8C8_DCF38);

/*
 * func_8015CA24_DD094
 * VRAM 0x8015CA24, ROM 0x000DD094
 * Callees: none
 */
/*
 *  8015CA24: addiu       $sp, $sp, -0x38
 *  8015CA28: sw          $s2, 0x28($sp)
 *  8015CA2C: addu        $s2, $a0, $zero
 *  8015CA30: sw          $s3, 0x2C($sp)
 *  8015CA34: addu        $s3, $a1, $zero
 *  8015CA38: sw          $s0, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015CA24_DD094);

/*
 * rta_fxgen_OnCreate
 * VRAM 0x8015CB50, ROM 0x000DD1C0
 * Callees: none
 */
/*
 *  8015CB50: addiu       $sp, $sp, -0x18
 *  8015CB54: sw          $s0, 0x10($sp)
 *  8015CB58: addu        $s0, $a0, $zero
 *  8015CB5C: sw          $ra, 0x14($sp)
 *  8015CB60: lw          $v0, 0x24($s0)
 *  8015CB64: nop
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_fxgen_OnCreate);

/*
 * rta_fxgen_OnUpdate
 * VRAM 0x8015CBC0, ROM 0x000DD230
 * Callees: none
 */
/*
 *  8015CBC0: addiu       $sp, $sp, -0x40
 *  8015CBC4: sw          $s0, 0x28($sp)
 *  8015CBC8: addu        $s0, $a0, $zero
 *  8015CBCC: sw          $ra, 0x3C($sp)
 *  8015CBD0: sw          $s4, 0x38($sp)
 *  8015CBD4: sw          $s3, 0x34($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_fxgen_OnUpdate);

/*
 * func_8015CE34_DD4A4
 * VRAM 0x8015CE34, ROM 0x000DD4A4
 * Callees: MATH3D_ApplyMatrixSV, 0x800176E8, 0x80017CD8, 0x80017D28
 */
/*
 *  8015CE34: addiu       $sp, $sp, -0x30
 *  8015CE38: sw          $s0, 0x20($sp)
 *  8015CE3C: addu        $s0, $a0, $zero
 *  8015CE40: sw          $s2, 0x28($sp)
 *  8015CE44: addu        $s2, $a2, $zero
 *  8015CE48: addiu       $a2, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015CE34_DD4A4);

/*
 * rta_zstmvent_OnCreate
 * VRAM 0x8015CF10, ROM 0x000DD580
 * Callees: memset, OBTABLE_FindObject
 */
/*
 *  8015CF10: addiu       $sp, $sp, -0x18
 *  8015CF14: sw          $s0, 0x10($sp)
 *  8015CF18: addu        $s0, $a0, $zero
 *  8015CF1C: addiu       $a0, $s0, 0xFC
 *  8015CF20: addiu       $v0, $zero, 0x2000
 *  8015CF24: sw          $ra, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zstmvent_OnCreate);

/*
 * rta_zstmvent_OnUpdate
 * VRAM 0x8015CFAC, ROM 0x000DD61C
 * Callees: none
 */
/*
 *  8015CFAC: addiu       $sp, $sp, -0x20
 *  8015CFB0: sw          $s0, 0x10($sp)
 *  8015CFB4: addu        $s0, $a0, $zero
 *  8015CFB8: sw          $ra, 0x18($sp)
 *  8015CFBC: sw          $s1, 0x14($sp)
 *  8015CFC0: lw          $v0, 0x104($s0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zstmvent_OnUpdate);

/*
 * func_8015D0B4_DD724
 * VRAM 0x8015D0B4, ROM 0x000DD724
 * Callees: none
 */
/*
 *  8015D0B4: addiu       $sp, $sp, -0x38
 *  8015D0B8: sw          $s0, 0x28($sp)
 *  8015D0BC: addu        $s0, $a0, $zero
 *  8015D0C0: sw          $ra, 0x30($sp)
 *  8015D0C4: sw          $s1, 0x2C($sp)
 *  8015D0C8: lw          $v0, 0xFC($s0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015D0B4_DD724);

/*
 * rta_zstmvent_OnCollide
 * VRAM 0x8015D1D4, ROM 0x000DD844
 * Callees: none
 */
/*
 *  8015D1D4: addiu       $sp, $sp, -0x18
 *  8015D1D8: sw          $ra, 0x10($sp)
 *  8015D1DC: lw          $v0, 0x78($a0)
 *  8015D1E0: lw          $v1, 0xC($a1)
 *  8015D1E4: lw          $a0, 0x14($v0)
 *  8015D1E8: nop
 */
INCLUDE_ASM("asm/nonmatchings/RTA", rta_zstmvent_OnCollide);

/*
 * func_8015D20C_DD87C
 * VRAM 0x8015D20C, ROM 0x000DD87C
 * Callees: none
 */
/*
 *  8015D20C: addiu       $sp, $sp, -0x38
 *  8015D210: sw          $s0, 0x28($sp)
 *  8015D214: lw          $s0, 0x48($sp)
 *  8015D218: sw          $ra, 0x34($sp)
 *  8015D21C: sw          $s2, 0x30($sp)
 *  8015D220: sw          $s1, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015D20C_DD87C);

/*
 * func_8015D374_DD9E4
 * VRAM 0x8015D374, ROM 0x000DD9E4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015D374: lui         $v0, 0x8016
 *  8015D378: lw          $v0, -0x11E0($v0)
 *  8015D37C: addiu       $sp, $sp, -0x28
 *  8015D380: sw          $s0, 0x18($sp)
 *  8015D384: addu        $s0, $a0, $zero
 *  8015D388: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015D374_DD9E4);

/*
 * func_8015D548_DDBB8
 * VRAM 0x8015D548, ROM 0x000DDBB8
 * Callees: none
 */
/*
 *  8015D548: addiu       $sp, $sp, -0x48
 *  8015D54C: sw          $s0, 0x20($sp)
 *  8015D550: addu        $s0, $a0, $zero
 *  8015D554: sw          $ra, 0x40($sp)
 *  8015D558: sw          $s7, 0x3C($sp)
 *  8015D55C: sw          $s6, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015D548_DDBB8);

/*
 * func_8015D74C_DDDBC
 * VRAM 0x8015D74C, ROM 0x000DDDBC
 * Callees: none
 */
/*
 *  8015D74C: addiu       $sp, $sp, -0x68
 *  8015D750: sw          $s1, 0x54($sp)
 *  8015D754: addu        $s1, $a0, $zero
 *  8015D758: sw          $ra, 0x64($sp)
 *  8015D75C: sw          $s4, 0x60($sp)
 *  8015D760: sw          $s3, 0x5C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015D74C_DDDBC);

/*
 * func_8015D9A0_DE010
 * VRAM 0x8015D9A0, ROM 0x000DE010
 * Callees: MATH3D_ApplyMatrixSV
 */
/*
 *  8015D9A0: addiu       $sp, $sp, -0x30
 *  8015D9A4: sw          $s1, 0x24($sp)
 *  8015D9A8: addu        $s1, $a0, $zero
 *  8015D9AC: sw          $ra, 0x28($sp)
 *  8015D9B0: sw          $s0, 0x20($sp)
 *  8015D9B4: lw          $v1, 0xF8($s1)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015D9A0_DE010);

/*
 * func_8015DAF0_DE160
 * VRAM 0x8015DAF0, ROM 0x000DE160
 * Callees: none
 */
/*
 *  8015DAF0: addiu       $sp, $sp, -0x20
 *  8015DAF4: sw          $s0, 0x10($sp)
 *  8015DAF8: addu        $s0, $a0, $zero
 *  8015DAFC: sw          $s1, 0x14($sp)
 *  8015DB00: sw          $ra, 0x1C($sp)
 *  8015DB04: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015DAF0_DE160);

/*
 * func_8015DE80_DE4F0
 * VRAM 0x8015DE80, ROM 0x000DE4F0
 * Callees: none
 */
/*
 *  8015DE80: addiu       $sp, $sp, -0x48
 *  8015DE84: sw          $ra, 0x40($sp)
 *  8015DE88: lw          $v0, 0x78($a0)
 *  8015DE8C: nop
 *  8015DE90: lw          $a0, 0x14($v0)
 *  8015DE94: nop
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015DE80_DE4F0);

/*
 * func_8015DF08_DE578
 * VRAM 0x8015DF08, ROM 0x000DE578
 * Callees: none
 */
/*
 *  8015DF08: addiu       $sp, $sp, -0x188
 *  8015DF0C: sw          $s0, 0x178($sp)
 *  8015DF10: addu        $s0, $a0, $zero
 *  8015DF14: addiu       $v0, $zero, 0x64
 *  8015DF18: sh          $v0, 0x16($sp)
 *  8015DF1C: addiu       $v0, $zero, 0x2710
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015DF08_DE578);

/*
 * func_8015E038_DE6A8
 * VRAM 0x8015E038, ROM 0x000DE6A8
 * Callees: none
 */
/*
 *  8015E038: addiu       $sp, $sp, -0x20
 *  8015E03C: sw          $s0, 0x10($sp)
 *  8015E040: addu        $s0, $a0, $zero
 *  8015E044: sw          $s1, 0x14($sp)
 *  8015E048: addu        $s1, $a1, $zero
 *  8015E04C: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015E038_DE6A8);

/*
 * func_8015E228_DE898
 * VRAM 0x8015E228, ROM 0x000DE898
 * Callees: OBTABLE_FindObject
 */
/*
 *  8015E228: addiu       $sp, $sp, -0x18
 *  8015E22C: addiu       $v0, $zero, 0x6
 *  8015E230: sw          $ra, 0x10($sp)
 *  8015E234: sw          $v0, 0xF4($a0)
 *  8015E238: addiu       $v0, $zero, 0x1A
 *  8015E23C: sh          $v0, 0x5E($a0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015E228_DE898);

/*
 * func_8015E27C_DE8EC
 * VRAM 0x8015E27C, ROM 0x000DE8EC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015E27C: lhu         $v0, 0x8($a0)
 *  8015E280: lui         $at, 0x8016
 *  8015E284: sh          $v0, -0x1130($at)
 *  8015E288: lhu         $v0, 0xA($a0)
 *  8015E28C: lui         $at, 0x8016
 *  8015E290: sh          $v0, -0x112E($at)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015E27C_DE8EC);

/*
 * func_8015E3AC_DEA1C
 * VRAM 0x8015E3AC, ROM 0x000DEA1C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015E3AC: lui         $v0, 0x8016
 *  8015E3B0: lhu         $v0, -0x1130($v0)
 *  8015E3B4: nop
 *  8015E3B8: sh          $v0, 0x8($a0)
 *  8015E3BC: lui         $v0, 0x8016
 *  8015E3C0: lhu         $v0, -0x112E($v0)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015E3AC_DEA1C);

/*
 * func_8015E538_DEBA8
 * VRAM 0x8015E538, ROM 0x000DEBA8
 * Callees: memset, MATH3D_SetUnityMatrix, RotMatrixX, RotMatrixY
 */
/*
 *  8015E538: addiu       $sp, $sp, -0x50
 *  8015E53C: sw          $s1, 0x3C($sp)
 *  8015E540: addu        $s1, $a0, $zero
 *  8015E544: addiu       $a0, $sp, 0x10
 *  8015E548: sw          $s2, 0x40($sp)
 *  8015E54C: addu        $s2, $a1, $zero
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015E538_DEBA8);

/*
 * func_8015E5E0_DEC50
 * VRAM 0x8015E5E0, ROM 0x000DEC50
 * Callees: 0x8015E538, 0x80002734
 */
/*
 *  8015E5E0: addiu       $sp, $sp, -0x60
 *  8015E5E4: sw          $s1, 0x54($sp)
 *  8015E5E8: addu        $s1, $a0, $zero
 *  8015E5EC: sw          $s0, 0x50($sp)
 *  8015E5F0: addu        $s0, $a1, $zero
 *  8015E5F4: negu        $a1, $a3
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015E5E0_DEC50);

/*
 * func_8015E6F4_DED64
 * VRAM 0x8015E6F4, ROM 0x000DED64
 * Callees: 0x80002734, 0x8015E538
 */
/*
 *  8015E6F4: addiu       $sp, $sp, -0x60
 *  8015E6F8: sw          $s3, 0x4C($sp)
 *  8015E6FC: addu        $s3, $a0, $zero
 *  8015E700: sw          $ra, 0x58($sp)
 *  8015E704: sw          $s5, 0x54($sp)
 *  8015E708: sw          $s4, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/RTA", func_8015E6F4_DED64);
