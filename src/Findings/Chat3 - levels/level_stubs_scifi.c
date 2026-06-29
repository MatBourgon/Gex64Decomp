/*
 * level_stubs_scifi.c — Rocket Channel
 * Level overlay: SCIFI
 * ROM base: 0x0DF540, VRAM base: 0x80159720
 * Stubs: 79
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/*
 * func_80159720_DF540
 * VRAM 0x80159720, ROM 0x000DF540
 * Callees: none
 */
/*
 *  80159720: addiu       $sp, $sp, -0x18
 *  80159724: lui         $v0, 0x8007
 *  80159728: lw          $v0, 0x681C($v0)
 *  8015972C: sll         $a0, $a0, 16
 *  80159730: sw          $ra, 0x10($sp)
 *  80159734: lw          $a2, 0x1C($v0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80159720_DF540);

/*
 * func_801598A4_DF6C4
 * VRAM 0x801598A4, ROM 0x000DF6C4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  801598A4: lui         $v0, 0x8007
 *  801598A8: lw          $v0, 0x681C($v0)
 *  801598AC: addiu       $sp, $sp, -0x18
 *  801598B0: beqz        $v0, . + 4 + (0x51 << 2)
 *  801598B4: sw          $ra, 0x10($sp)
 *  801598B8: lw          $v0, 0x1C($v0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_801598A4_DF6C4);

/*
 * func_80159A08_DF828
 * VRAM 0x80159A08, ROM 0x000DF828
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159A08: lui         $v0, 0x8007
 *  80159A0C: lw          $v0, 0x681C($v0)
 *  80159A10: nop
 *  80159A14: lw          $a0, 0x1C($v0)
 *  80159A18: nop
 *  80159A1C: lh          $v1, 0x18($a0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80159A08_DF828);

/*
 * func_80159A84_DF8A4
 * VRAM 0x80159A84, ROM 0x000DF8A4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159A84: lui         $v0, 0x8007
 *  80159A88: lw          $v0, -0x3060($v0)
 *  80159A8C: addiu       $sp, $sp, -0x18
 *  80159A90: sw          $ra, 0x14($sp)
 *  80159A94: sw          $s0, 0x10($sp)
 *  80159A98: lw          $s0, 0x20($v0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80159A84_DF8A4);

/*
 * func_80159B10_DF930
 * VRAM 0x80159B10, ROM 0x000DF930
 * Callees: none
 */
/*
 *  80159B10: addiu       $sp, $sp, -0x18
 *  80159B14: addu        $a3, $a0, $zero
 *  80159B18: addiu       $v0, $zero, 0x78
 *  80159B1C: sw          $ra, 0x10($sp)
 *  80159B20: lh          $a2, 0x10($a3)
 *  80159B24: lh          $a0, 0x8($a3)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80159B10_DF930);

/*
 * func_80159D54_DFB74
 * VRAM 0x80159D54, ROM 0x000DFB74
 * Callees: none
 */
/*
 *  80159D54: addiu       $sp, $sp, -0x28
 *  80159D58: sw          $s0, 0x18($sp)
 *  80159D5C: addu        $s0, $a0, $zero
 *  80159D60: sw          $ra, 0x20($sp)
 *  80159D64: sw          $s1, 0x1C($sp)
 *  80159D68: lh          $a0, 0x18($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80159D54_DFB74);

/*
 * func_80159E3C_DFC5C
 * VRAM 0x80159E3C, ROM 0x000DFC5C
 * Callees: none
 */
/*
 *  80159E3C: addiu       $sp, $sp, -0x30
 *  80159E40: sw          $s1, 0x24($sp)
 *  80159E44: addu        $s1, $a1, $zero
 *  80159E48: lui         $a1, 0x8007
 *  80159E4C: lw          $a1, 0x681C($a1)
 *  80159E50: addiu       $v1, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80159E3C_DFC5C);

/*
 * scifi_dust_OnCreate
 * VRAM 0x8015A024, ROM 0x000DFE44
 * Callees: 0x8006A020
 */
/*
 *  8015A024: addiu       $sp, $sp, -0x18
 *  8015A028: sw          $s0, 0x10($sp)
 *  8015A02C: sw          $ra, 0x14($sp)
 *  8015A030: jal         func_8006A020
 *  8015A034: addu        $s0, $a0, $zero
 *  8015A038: lui         $v1, 0x6666
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_dust_OnCreate);

/*
 * scifi_dust_OnUpdate
 * VRAM 0x8015A07C, ROM 0x000DFE9C
 * Callees: INSTANCE_KillInstance
 */
/*
 *  8015A07C: addiu       $sp, $sp, -0x18
 *  8015A080: sw          $ra, 0x10($sp)
 *  8015A084: lw          $v1, 0xFC($a0)
 *  8015A088: lhu         $v0, 0x4C($a0)
 *  8015A08C: nop
 *  8015A090: subu        $v0, $v0, $v1
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_dust_OnUpdate);

/*
 * scifi_rocket_OnCreate
 * VRAM 0x8015A29C, ROM 0x000E00BC
 * Callees: none
 */
/*
 *  8015A29C: addiu       $sp, $sp, -0x18
 *  8015A2A0: addu        $a2, $a0, $zero
 *  8015A2A4: sw          $ra, 0x10($sp)
 *  8015A2A8: lw          $a0, 0x10($a2)
 *  8015A2AC: lui         $v0, 0x2
 *  8015A2B0: and         $v0, $a0, $v0
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rocket_OnCreate);

/*
 * func_8015A36C_E018C
 * VRAM 0x8015A36C, ROM 0x000E018C
 * Callees: 0x80041FD0
 */
/*
 *  8015A36C: addiu       $sp, $sp, -0x50
 *  8015A370: sw          $s0, 0x40($sp)
 *  8015A374: addu        $s0, $a2, $zero
 *  8015A378: sw          $s1, 0x44($sp)
 *  8015A37C: addu        $s1, $a3, $zero
 *  8015A380: sw          $ra, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015A36C_E018C);

/*
 * func_8015A3F4_E0214
 * VRAM 0x8015A3F4, ROM 0x000E0214
 * Callees: none
 */
/*
 *  8015A3F4: addiu       $sp, $sp, -0x30
 *  8015A3F8: sw          $s1, 0x24($sp)
 *  8015A3FC: addu        $s1, $a2, $zero
 *  8015A400: addu        $a1, $a3, $zero
 *  8015A404: sw          $ra, 0x28($sp)
 *  8015A408: sw          $s0, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015A3F4_E0214);

/*
 * scifi_rocket_OnUpdate
 * VRAM 0x8015A46C, ROM 0x000E028C
 * Callees: none
 */
/*
 *  8015A46C: addiu       $sp, $sp, -0x30
 *  8015A470: sw          $s0, 0x18($sp)
 *  8015A474: addu        $s0, $a0, $zero
 *  8015A478: sw          $s1, 0x1C($sp)
 *  8015A47C: sw          $ra, 0x28($sp)
 *  8015A480: sw          $s3, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rocket_OnUpdate);

/*
 * scifi_rocket_OnCollide
 * VRAM 0x8015A61C, ROM 0x000E043C
 * Callees: GenericCollide
 */
/*
 *  8015A61C: addiu       $sp, $sp, -0x20
 *  8015A620: sw          $s1, 0x14($sp)
 *  8015A624: addu        $s1, $a0, $zero
 *  8015A628: sw          $ra, 0x18($sp)
 *  8015A62C: sw          $s0, 0x10($sp)
 *  8015A630: lw          $s0, 0x78($s1)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rocket_OnCollide);

/*
 * scifi_onoff_OnCollide
 * VRAM 0x8015A884, ROM 0x000E06A4
 * Callees: none
 */
/*
 *  8015A884: addiu       $sp, $sp, -0x18
 *  8015A888: addu        $t2, $zero, $zero
 *  8015A88C: addu        $t6, $zero, $zero
 *  8015A890: addu        $t3, $zero, $zero
 *  8015A894: sw          $ra, 0x10($sp)
 *  8015A898: lw          $a3, 0x24($a0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_onoff_OnCollide);

/*
 * scifi_bub_OnCreate
 * VRAM 0x8015AB04, ROM 0x000E0924
 * Callees: none
 */
/*
 *  8015AB04: addiu       $sp, $sp, -0x18
 *  8015AB08: sw          $s0, 0x10($sp)
 *  8015AB0C: addu        $s0, $a0, $zero
 *  8015AB10: sw          $ra, 0x14($sp)
 *  8015AB14: lw          $v0, 0x18($s0)
 *  8015AB18: lw          $v1, 0x24($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_bub_OnCreate);

/*
 * func_8015AC28_E0A48
 * VRAM 0x8015AC28, ROM 0x000E0A48
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015AC28: lw          $v1, 0x18($a0)
 *  8015AC2C: lh          $v0, 0xC2($a0)
 *  8015AC30: lw          $v1, 0xC($v1)
 *  8015AC34: sll         $v0, $v0, 2
 *  8015AC38: addu        $v0, $v0, $v1
 *  8015AC3C: lw          $v0, 0x0($v0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015AC28_E0A48);

/*
 * scifi_bub_OnUpdate
 * VRAM 0x8015AD74, ROM 0x000E0B94
 * Callees: 0x80047E64
 */
/*
 *  8015AD74: addiu       $sp, $sp, -0x20
 *  8015AD78: sw          $s0, 0x10($sp)
 *  8015AD7C: addu        $s0, $a0, $zero
 *  8015AD80: sw          $s1, 0x14($sp)
 *  8015AD84: addu        $s1, $a1, $zero
 *  8015AD88: sw          $ra, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_bub_OnUpdate);

/*
 * scifi_bub_OnCollide
 * VRAM 0x8015AF30, ROM 0x000E0D50
 * Callees: none
 */
/*
 *  8015AF30: addiu       $sp, $sp, -0x18
 *  8015AF34: sw          $s0, 0x10($sp)
 *  8015AF38: addu        $s0, $a0, $zero
 *  8015AF3C: sw          $ra, 0x14($sp)
 *  8015AF40: lw          $a0, 0x78($s0)
 *  8015AF44: lw          $v0, 0xC($a1)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_bub_OnCollide);

/*
 * scifi_eel_OnCreate
 * VRAM 0x8015AF94, ROM 0x000E0DB4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015AF94: lw          $v0, 0x10($a0)
 *  8015AF98: lw          $v1, 0x18($a0)
 *  8015AF9C: sb          $zero, 0x4E($a0)
 *  8015AFA0: sh          $zero, 0x5E($a0)
 *  8015AFA4: sw          $zero, 0xDC($a0)
 *  8015AFA8: sw          $zero, 0xF4($a0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_eel_OnCreate);

/*
 * scifi_eel_OnUpdate
 * VRAM 0x8015AFD8, ROM 0x000E0DF8
 * Callees: none
 */
/*
 *  8015AFD8: addiu       $sp, $sp, -0x20
 *  8015AFDC: sw          $s0, 0x10($sp)
 *  8015AFE0: addu        $s0, $a0, $zero
 *  8015AFE4: sw          $ra, 0x18($sp)
 *  8015AFE8: sw          $s1, 0x14($sp)
 *  8015AFEC: lw          $v1, 0xC($a1)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_eel_OnUpdate);

/*
 * scifi_eel_OnCollide
 * VRAM 0x8015B344, ROM 0x000E1164
 * Callees: none
 */
/*
 *  8015B344: addiu       $sp, $sp, -0x18
 *  8015B348: sw          $s0, 0x10($sp)
 *  8015B34C: addu        $s0, $a0, $zero
 *  8015B350: sw          $ra, 0x14($sp)
 *  8015B354: lw          $a0, 0x78($s0)
 *  8015B358: jal         func_80027500
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_eel_OnCollide);

/*
 * scifi_stmvent_OnCreate
 * VRAM 0x8015B388, ROM 0x000E11A8
 * Callees: RotMatrix
 */
/*
 *  8015B388: addiu       $sp, $sp, -0x40
 *  8015B38C: sw          $s0, 0x30($sp)
 *  8015B390: addu        $s0, $a0, $zero
 *  8015B394: addiu       $a1, $sp, 0x10
 *  8015B398: sw          $ra, 0x38($sp)
 *  8015B39C: sw          $s1, 0x34($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_stmvent_OnCreate);

/*
 * func_8015B4BC_E12DC
 * VRAM 0x8015B4BC, ROM 0x000E12DC
 * Callees: none
 */
/*
 *  8015B4BC: addiu       $sp, $sp, -0x18
 *  8015B4C0: sw          $s0, 0x10($sp)
 *  8015B4C4: addu        $s0, $a0, $zero
 *  8015B4C8: sw          $ra, 0x14($sp)
 *  8015B4CC: lhu         $a2, 0x6C($s0)
 *  8015B4D0: lhu         $v0, 0x24($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015B4BC_E12DC);

/*
 * func_8015B5F0_E1410
 * VRAM 0x8015B5F0, ROM 0x000E1410
 * Callees: none
 */
/*
 *  8015B5F0: addiu       $sp, $sp, -0x48
 *  8015B5F4: sw          $s0, 0x38($sp)
 *  8015B5F8: addu        $s0, $a0, $zero
 *  8015B5FC: lui         $a0, 0x8016
 *  8015B600: addiu       $a0, $a0, 0x4E48
 *  8015B604: sw          $ra, 0x40($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015B5F0_E1410);

/*
 * scifi_stmvent_OnUpdate
 * VRAM 0x8015B7D0, ROM 0x000E15F0
 * Callees: rezop_simontv_OnCollide
 */
/*
 *  8015B7D0: addiu       $sp, $sp, -0x20
 *  8015B7D4: sw          $s0, 0x18($sp)
 *  8015B7D8: addu        $s0, $a0, $zero
 *  8015B7DC: sw          $ra, 0x1C($sp)
 *  8015B7E0: lw          $v0, 0xDC($s0)
 *  8015B7E4: nop
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_stmvent_OnUpdate);

/*
 * func_8015B904_E1724
 * VRAM 0x8015B904, ROM 0x000E1724
 * Callees: none
 */
/*
 *  8015B904: addiu       $sp, $sp, -0x8
 *  8015B908: addu        $t2, $a0, $zero
 *  8015B90C: addu        $t3, $a2, $zero
 *  8015B910: lui         $t1, 0x5555
 *  8015B914: ori         $t1, $t1, 0x5556
 *  8015B918: lw          $t4, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015B904_E1724);

/*
 * func_8015BB90_E19B0
 * VRAM 0x8015BB90, ROM 0x000E19B0
 * Callees: 0x800162C0, RotMatrixX
 */
/*
 *  8015BB90: addiu       $sp, $sp, -0x18
 *  8015BB94: sw          $s0, 0x10($sp)
 *  8015BB98: sw          $ra, 0x14($sp)
 *  8015BB9C: jal         func_800162C0
 *  8015BBA0: addu        $s0, $a0, $zero
 *  8015BBA4: lw          $a1, 0x14($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015BB90_E19B0);

/*
 * func_8015BC24_E1A44
 * VRAM 0x8015BC24, ROM 0x000E1A44
 * Callees: none
 */
/*
 *  8015BC24: addiu       $sp, $sp, -0x80
 *  8015BC28: sw          $ra, 0x7C($sp)
 *  8015BC2C: sw          $fp, 0x78($sp)
 *  8015BC30: sw          $s7, 0x74($sp)
 *  8015BC34: sw          $s6, 0x70($sp)
 *  8015BC38: sw          $s5, 0x6C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015BC24_E1A44);

/*
 * scifi_genbrk_OnUpdate
 * VRAM 0x8015BE98, ROM 0x000E1CB8
 * Callees: looney_jimboat_OnUpdate
 */
/*
 *  8015BE98: addiu       $sp, $sp, -0x18
 *  8015BE9C: sw          $ra, 0x10($sp)
 *  8015BEA0: jal         func_8001ACF4
 *  8015BEA4: nop
 *  8015BEA8: lw          $ra, 0x10($sp)
 *  8015BEAC: addiu       $sp, $sp, 0x18
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_genbrk_OnUpdate);

/*
 * scifi_genbrk_OnCollide
 * VRAM 0x8015BEB8, ROM 0x000E1CD8
 * Callees: none
 */
/*
 *  8015BEB8: addiu       $sp, $sp, -0x18
 *  8015BEBC: sw          $s0, 0x10($sp)
 *  8015BEC0: addu        $s0, $a0, $zero
 *  8015BEC4: sw          $ra, 0x14($sp)
 *  8015BEC8: lw          $a0, 0x78($s0)
 *  8015BECC: jal         func_80027500
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_genbrk_OnCollide);

/*
 * func_8015BF08_E1D28
 * VRAM 0x8015BF08, ROM 0x000E1D28
 * Callees: OBTABLE_FindObject, INSTANCE_BirthObject
 */
/*
 *  8015BF08: addiu       $sp, $sp, -0x18
 *  8015BF0C: sw          $s0, 0x10($sp)
 *  8015BF10: addu        $s0, $a0, $zero
 *  8015BF14: lui         $a0, 0x8016
 *  8015BF18: addiu       $a0, $a0, 0x4E54
 *  8015BF1C: sw          $ra, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015BF08_E1D28);

/*
 * func_8015BFA8_E1DC8
 * VRAM 0x8015BFA8, ROM 0x000E1DC8
 * Callees: 0x8002E350
 */
/*
 *  8015BFA8: addiu       $sp, $sp, -0x18
 *  8015BFAC: sw          $ra, 0x10($sp)
 *  8015BFB0: lw          $v0, 0x10($a0)
 *  8015BFB4: addiu       $v1, $zero, -0x401
 *  8015BFB8: and         $v0, $v0, $v1
 *  8015BFBC: jal         func_8002E350
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015BFA8_E1DC8);

/*
 * func_8015BFD4_E1DF4
 * VRAM 0x8015BFD4, ROM 0x000E1DF4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015BFD4: lw          $a3, 0x20($a0)
 *  8015BFD8: nop
 *  8015BFDC: lh          $v1, 0x0($a3)
 *  8015BFE0: lh          $t0, 0x2($a3)
 *  8015BFE4: nop
 *  8015BFE8: mult        $v1, $t0
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015BFD4_E1DF4);

/* scifi_bldbota_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_bldbota_OnCreate);

/* scifi_bldbota_OnUpdate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_bldbota_OnUpdate);

/*
 * scifi_abubble_OnCreate
 * VRAM 0x8015C158, ROM 0x000E1F78
 * Callees: none
 */
/*
 *  8015C158: addiu       $sp, $sp, -0x18
 *  8015C15C: sw          $s0, 0x10($sp)
 *  8015C160: addu        $s0, $a0, $zero
 *  8015C164: sw          $ra, 0x14($sp)
 *  8015C168: lw          $v0, 0x18($s0)
 *  8015C16C: lw          $v1, 0x24($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_abubble_OnCreate);

/*
 * scifi_abubble_OnUpdate
 * VRAM 0x8015C21C, ROM 0x000E203C
 * Callees: none
 */
/*
 *  8015C21C: addiu       $sp, $sp, -0x20
 *  8015C220: sw          $ra, 0x18($sp)
 *  8015C224: lh          $v0, 0x106($a0)
 *  8015C228: lh          $v1, 0x102($a0)
 *  8015C22C: nop
 *  8015C230: slt         $v0, $v0, $v1
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_abubble_OnUpdate);

/*
 * scifi_abubble_OnCollide
 * VRAM 0x8015C290, ROM 0x000E20B0
 * Callees: spy_qsofa_OnCreate
 */
/*
 *  8015C290: addiu       $sp, $sp, -0x18
 *  8015C294: sw          $s0, 0x10($sp)
 *  8015C298: addu        $s0, $a0, $zero
 *  8015C29C: sw          $ra, 0x14($sp)
 *  8015C2A0: lw          $a0, 0x78($s0)
 *  8015C2A4: lw          $v0, 0xC($a1)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_abubble_OnCollide);

/*
 * scifi_acrate_OnCreate
 * VRAM 0x8015C300, ROM 0x000E2120
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C300: lw          $v0, 0x18($a0)
 *  8015C304: lw          $v1, 0x24($a0)
 *  8015C308: lw          $a1, 0x1C($v0)
 *  8015C30C: nop
 *  8015C310: beqz        $v1, . + 4 + (0x8 << 2)
 *  8015C314: addiu       $a2, $a0, 0xFC
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_acrate_OnCreate);

/*
 * scifi_acrate_OnCollide
 * VRAM 0x8015C38C, ROM 0x000E21AC
 * Callees: none
 */
/*
 *  8015C38C: addiu       $sp, $sp, -0x20
 *  8015C390: sw          $s0, 0x10($sp)
 *  8015C394: addu        $s0, $a0, $zero
 *  8015C398: sw          $ra, 0x18($sp)
 *  8015C39C: sw          $s1, 0x14($sp)
 *  8015C3A0: lw          $a0, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_acrate_OnCollide);

/*
 * scifi_xa_OnUpdate
 * VRAM 0x8015C47C, ROM 0x000E229C
 * Callees: none
 */
/*
 *  8015C47C: addiu       $sp, $sp, -0x18
 *  8015C480: sw          $ra, 0x10($sp)
 *  8015C484: lw          $v0, 0xFC($a0)
 *  8015C488: lhu         $v1, 0x6A($a0)
 *  8015C48C: addiu       $v0, $v0, 0x1
 *  8015C490: sw          $v0, 0xFC($a0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_xa_OnUpdate);

/*
 * scifi_apod_OnCreate
 * VRAM 0x8015C4D8, ROM 0x000E22F8
 * Callees: 0x800331BC
 */
/*
 *  8015C4D8: addiu       $sp, $sp, -0x20
 *  8015C4DC: sw          $s0, 0x10($sp)
 *  8015C4E0: addu        $s0, $a0, $zero
 *  8015C4E4: lui         $a0, 0x1
 *  8015C4E8: sw          $ra, 0x18($sp)
 *  8015C4EC: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_apod_OnCreate);

/*
 * func_8015C5CC_E23EC
 * VRAM 0x8015C5CC, ROM 0x000E23EC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C5CC: sw          $a2, 0x8($sp)
 *  8015C5D0: sw          $a3, 0xC($sp)
 *  8015C5D4: addiu       $sp, $sp, -0x20
 *  8015C5D8: sw          $s2, 0x18($sp)
 *  8015C5DC: addu        $s2, $a1, $zero
 *  8015C5E0: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015C5CC_E23EC);

/*
 * scifi_apod_OnUpdate
 * VRAM 0x8015C69C, ROM 0x000E24BC
 * Callees: none
 */
/*
 *  8015C69C: addiu       $sp, $sp, -0x70
 *  8015C6A0: sw          $s2, 0x50($sp)
 *  8015C6A4: addu        $s2, $a0, $zero
 *  8015C6A8: sw          $s3, 0x54($sp)
 *  8015C6AC: addu        $s3, $a1, $zero
 *  8015C6B0: sw          $ra, 0x68($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_apod_OnUpdate);

/*
 * scifi_apod_OnCollide
 * VRAM 0x8015CBFC, ROM 0x000E2A1C
 * Callees: none
 */
/*
 *  8015CBFC: addiu       $sp, $sp, -0x18
 *  8015CC00: sw          $ra, 0x10($sp)
 *  8015CC04: lw          $a2, 0x78($a0)
 *  8015CC08: lw          $v0, 0xC($a1)
 *  8015CC0C: lw          $v1, 0x14($a2)
 *  8015CC10: nop
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_apod_OnCollide);

/*
 * scifi_alien_OnCreate
 * VRAM 0x8015CC4C, ROM 0x000E2A6C
 * Callees: none
 */
/*
 *  8015CC4C: addiu       $sp, $sp, -0x18
 *  8015CC50: sw          $s0, 0x10($sp)
 *  8015CC54: addu        $s0, $a0, $zero
 *  8015CC58: sw          $ra, 0x14($sp)
 *  8015CC5C: lw          $v0, 0x20($s0)
 *  8015CC60: nop
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_alien_OnCreate);

/*
 * scifi_alien_OnUpdate
 * VRAM 0x8015CD68, ROM 0x000E2B88
 * Callees: none
 */
/*
 *  8015CD68: addiu       $sp, $sp, -0x70
 *  8015CD6C: sw          $s0, 0x48($sp)
 *  8015CD70: addu        $s0, $a0, $zero
 *  8015CD74: sw          $s2, 0x50($sp)
 *  8015CD78: addu        $s2, $a1, $zero
 *  8015CD7C: sw          $s7, 0x64($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_alien_OnUpdate);

/*
 * scifi_alien_OnCollide
 * VRAM 0x8015D590, ROM 0x000E33B0
 * Callees: none
 */
/*
 *  8015D590: addiu       $sp, $sp, -0x38
 *  8015D594: sw          $s1, 0x14($sp)
 *  8015D598: addu        $s1, $a0, $zero
 *  8015D59C: sw          $s3, 0x1C($sp)
 *  8015D5A0: addu        $s3, $a1, $zero
 *  8015D5A4: sw          $s6, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_alien_OnCollide);

/*
 * scifi_gas_OnCreate
 * VRAM 0x8015D8DC, ROM 0x000E36FC
 * Callees: none
 */
/*
 *  8015D8DC: addiu       $sp, $sp, -0x28
 *  8015D8E0: sw          $s0, 0x10($sp)
 *  8015D8E4: addu        $s0, $a0, $zero
 *  8015D8E8: sw          $s1, 0x14($sp)
 *  8015D8EC: addu        $s1, $zero, $zero
 *  8015D8F0: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_gas_OnCreate);

/*
 * scifi_gas_OnUpdate
 * VRAM 0x8015DB20, ROM 0x000E3940
 * Callees: none
 */
/*
 *  8015DB20: addiu       $sp, $sp, -0x20
 *  8015DB24: sw          $s0, 0x10($sp)
 *  8015DB28: addu        $s0, $a0, $zero
 *  8015DB2C: sw          $s1, 0x14($sp)
 *  8015DB30: addiu       $s1, $s0, 0xFC
 *  8015DB34: sw          $ra, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_gas_OnUpdate);

/*
 * scifi_gas_OnCollide
 * VRAM 0x8015DD64, ROM 0x000E3B84
 * Callees: 0x80027578
 */
/*
 *  8015DD64: addiu       $sp, $sp, -0x18
 *  8015DD68: sw          $ra, 0x10($sp)
 *  8015DD6C: lw          $v0, 0x78($a0)
 *  8015DD70: nop
 *  8015DD74: lw          $a2, 0x14($v0)
 *  8015DD78: nop
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_gas_OnCollide);

/*
 * scifi_mylot_OnCreate
 * VRAM 0x8015DE08, ROM 0x000E3C28
 * Callees: none
 */
/*
 *  8015DE08: addiu       $sp, $sp, -0x58
 *  8015DE0C: sw          $s0, 0x48($sp)
 *  8015DE10: addu        $s0, $a0, $zero
 *  8015DE14: sw          $ra, 0x54($sp)
 *  8015DE18: sw          $s2, 0x50($sp)
 *  8015DE1C: sw          $s1, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_mylot_OnCreate);

/*
 * func_8015E070_E3E90
 * VRAM 0x8015E070, ROM 0x000E3E90
 * Callees: MATH3D_SetUnityMatrix, RotMatrixX, RotMatrixY, RotMatrixZ
 */
/*
 *  8015E070: addiu       $sp, $sp, -0x48
 *  8015E074: sw          $s0, 0x40($sp)
 *  8015E078: addu        $s0, $a0, $zero
 *  8015E07C: sw          $ra, 0x44($sp)
 *  8015E080: jal         func_80030B5C
 *  8015E084: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E070_E3E90);

/*
 * func_8015E108_E3F28
 * VRAM 0x8015E108, ROM 0x000E3F28
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ
 */
/*
 *  8015E108: lhu         $v0, 0x60($a0)
 *  8015E10C: lhu         $v1, 0x62($a0)
 *  8015E110: andi        $v0, $v0, 0xFFF
 *  8015E114: andi        $v1, $v1, 0xFFF
 *  8015E118: sh          $v0, 0x60($a0)
 *  8015E11C: sh          $v1, 0x62($a0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E108_E3F28);

/*
 * func_8015E130_E3F50
 * VRAM 0x8015E130, ROM 0x000E3F50
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ
 */
/*
 *  8015E130: addiu       $sp, $sp, -0x58
 *  8015E134: sw          $s1, 0x4C($sp)
 *  8015E138: addu        $s1, $a0, $zero
 *  8015E13C: sw          $s0, 0x48($sp)
 *  8015E140: addu        $s0, $a1, $zero
 *  8015E144: sw          $ra, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E130_E3F50);

/*
 * func_8015E234_E4054
 * VRAM 0x8015E234, ROM 0x000E4054
 * Callees: none
 */
/*
 *  8015E234: addiu       $sp, $sp, -0x60
 *  8015E238: sw          $s0, 0x48($sp)
 *  8015E23C: addu        $s0, $a0, $zero
 *  8015E240: sw          $s2, 0x50($sp)
 *  8015E244: addu        $s2, $a1, $zero
 *  8015E248: sw          $s3, 0x54($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E234_E4054);

/*
 * func_8015E3AC_E41CC
 * VRAM 0x8015E3AC, ROM 0x000E41CC
 * Callees: MATH3D_SetUnityMatrix
 */
/*
 *  8015E3AC: addiu       $sp, $sp, -0x58
 *  8015E3B0: sw          $s0, 0x48($sp)
 *  8015E3B4: addu        $s0, $a0, $zero
 *  8015E3B8: sw          $s1, 0x4C($sp)
 *  8015E3BC: addu        $s1, $a1, $zero
 *  8015E3C0: sw          $ra, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E3AC_E41CC);

/*
 * func_8015E4D0_E42F0
 * VRAM 0x8015E4D0, ROM 0x000E42F0
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ
 */
/*
 *  8015E4D0: addiu       $sp, $sp, -0x58
 *  8015E4D4: sw          $s1, 0x4C($sp)
 *  8015E4D8: addu        $s1, $a0, $zero
 *  8015E4DC: sw          $s0, 0x48($sp)
 *  8015E4E0: addu        $s0, $a1, $zero
 *  8015E4E4: sw          $ra, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E4D0_E42F0);

/*
 * func_8015E5D4_E43F4
 * VRAM 0x8015E5D4, ROM 0x000E43F4
 * Callees: RotMatrix
 */
/*
 *  8015E5D4: addiu       $sp, $sp, -0x58
 *  8015E5D8: sw          $s2, 0x50($sp)
 *  8015E5DC: addu        $s2, $a0, $zero
 *  8015E5E0: sw          $s1, 0x4C($sp)
 *  8015E5E4: addu        $s1, $a1, $zero
 *  8015E5E8: sw          $s0, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E5D4_E43F4);

/*
 * func_8015E6B8_E44D8
 * VRAM 0x8015E6B8, ROM 0x000E44D8
 * Callees: RotMatrix
 */
/*
 *  8015E6B8: addiu       $sp, $sp, -0x58
 *  8015E6BC: sw          $s2, 0x50($sp)
 *  8015E6C0: addu        $s2, $a0, $zero
 *  8015E6C4: sw          $s1, 0x4C($sp)
 *  8015E6C8: addu        $s1, $a1, $zero
 *  8015E6CC: sw          $s0, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E6B8_E44D8);

/*
 * func_8015E7A0_E45C0
 * VRAM 0x8015E7A0, ROM 0x000E45C0
 * Callees: none
 */
/*
 *  8015E7A0: addiu       $sp, $sp, -0xA8
 *  8015E7A4: sw          $s3, 0x9C($sp)
 *  8015E7A8: addu        $s3, $a0, $zero
 *  8015E7AC: sw          $s0, 0x90($sp)
 *  8015E7B0: addu        $s0, $a3, $zero
 *  8015E7B4: sw          $s1, 0x94($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E7A0_E45C0);

/*
 * func_8015E9A0_E47C0
 * VRAM 0x8015E9A0, ROM 0x000E47C0
 * Callees: none
 */
/*
 *  8015E9A0: addiu       $sp, $sp, -0xA8
 *  8015E9A4: sw          $s3, 0x9C($sp)
 *  8015E9A8: addu        $s3, $a0, $zero
 *  8015E9AC: sw          $s0, 0x90($sp)
 *  8015E9B0: lw          $s0, 0xB8($sp)
 *  8015E9B4: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015E9A0_E47C0);

/*
 * func_8015EB98_E49B8
 * VRAM 0x8015EB98, ROM 0x000E49B8
 * Callees: none
 */
/*
 *  8015EB98: addiu       $sp, $sp, -0x8
 *  8015EB9C: addu        $t0, $a1, $zero
 *  8015EBA0: addu        $t1, $a2, $zero
 *  8015EBA4: sll         $a2, $a2, 16
 *  8015EBA8: lh          $a3, 0x4C($a0)
 *  8015EBAC: sll         $a1, $a1, 16
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_8015EB98_E49B8);

/*
 * scifi_mylot_OnUpdate
 * VRAM 0x8015EC1C, ROM 0x000E4A3C
 * Callees: ratan2
 */
/*
 *  8015EC1C: addiu       $sp, $sp, -0x140
 *  8015EC20: sw          $s1, 0x11C($sp)
 *  8015EC24: addu        $s1, $a0, $zero
 *  8015EC28: sw          $ra, 0x13C($sp)
 *  8015EC2C: sw          $fp, 0x138($sp)
 *  8015EC30: sw          $s7, 0x134($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_mylot_OnUpdate);

/*
 * scifi_mylot_OnCollide
 * VRAM 0x8016153C, ROM 0x000E735C
 * Callees: none
 */
/*
 *  8016153C: addiu       $sp, $sp, -0x30
 *  80161540: sw          $s1, 0x14($sp)
 *  80161544: addu        $s1, $a0, $zero
 *  80161548: sw          $s4, 0x20($sp)
 *  8016154C: addu        $s4, $a1, $zero
 *  80161550: sw          $s6, 0x28($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_mylot_OnCollide);

/*
 * scifi_rt_OnCreate
 * VRAM 0x80161A34, ROM 0x000E7854
 * Callees: none
 */
/*
 *  80161A34: addiu       $sp, $sp, -0x30
 *  80161A38: sw          $s0, 0x20($sp)
 *  80161A3C: addu        $s0, $a0, $zero
 *  80161A40: sw          $ra, 0x28($sp)
 *  80161A44: sw          $s1, 0x24($sp)
 *  80161A48: lw          $v0, 0x18($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rt_OnCreate);

/*
 * func_80161C3C_E7A5C
 * VRAM 0x80161C3C, ROM 0x000E7A5C
 * Callees: OBTABLE_FindObject, INSTANCE_BirthObject, 0x80047E64
 */
/*
 *  80161C3C: addiu       $sp, $sp, -0x28
 *  80161C40: sw          $s0, 0x10($sp)
 *  80161C44: addu        $s0, $a0, $zero
 *  80161C48: sw          $ra, 0x20($sp)
 *  80161C4C: sw          $s3, 0x1C($sp)
 *  80161C50: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80161C3C_E7A5C);

/*
 * func_80161D18_E7B38
 * VRAM 0x80161D18, ROM 0x000E7B38
 * Callees: none
 */
/*
 *  80161D18: addiu       $sp, $sp, -0x8
 *  80161D1C: lui         $v0, 0x3000
 *  80161D20: lw          $v1, 0x18($a0)
 *  80161D24: ori         $v0, $v0, 0xFF
 *  80161D28: sw          $v0, 0x0($sp)
 *  80161D2C: lui         $v0, 0x3000
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80161D18_E7B38);

/*
 * func_80161DF4_E7C14
 * VRAM 0x80161DF4, ROM 0x000E7C14
 * Callees: none
 */
/*
 *  80161DF4: addiu       $sp, $sp, -0x8
 *  80161DF8: lui         $v0, 0x3000
 *  80161DFC: lw          $v1, 0x18($a1)
 *  80161E00: ori         $v0, $v0, 0xFF
 *  80161E04: sw          $v0, 0x0($sp)
 *  80161E08: lui         $v0, 0x3000
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80161DF4_E7C14);

/*
 * func_80161ED0_E7CF0
 * VRAM 0x80161ED0, ROM 0x000E7CF0
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80161ED0: lw          $v0, 0x18($a1)
 *  80161ED4: nop
 *  80161ED8: beqz        $v0, . + 4 + (0x1B << 2)
 *  80161EDC: lui         $a1, 0x3000
 *  80161EE0: lw          $v0, 0xC($v0)
 *  80161EE4: nop
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80161ED0_E7CF0);

/*
 * func_80161F50_E7D70
 * VRAM 0x80161F50, ROM 0x000E7D70
 * Callees: none
 */
/*
 *  80161F50: addiu       $sp, $sp, -0x20
 *  80161F54: sw          $s0, 0x10($sp)
 *  80161F58: addu        $s0, $a0, $zero
 *  80161F5C: sw          $ra, 0x18($sp)
 *  80161F60: sw          $s1, 0x14($sp)
 *  80161F64: lw          $v0, 0x18($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80161F50_E7D70);

/*
 * func_80162154_E7F74
 * VRAM 0x80162154, ROM 0x000E7F74
 * Callees: MATH3D_SetUnityMatrix, RotMatrix, RotMatrixZ
 */
/*
 *  80162154: addiu       $sp, $sp, -0x48
 *  80162158: sw          $s1, 0x3C($sp)
 *  8016215C: addu        $s1, $a0, $zero
 *  80162160: sw          $s0, 0x38($sp)
 *  80162164: addu        $s0, $a1, $zero
 *  80162168: sw          $ra, 0x40($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_80162154_E7F74);

/*
 * func_801621D4_E7FF4
 * VRAM 0x801621D4, ROM 0x000E7FF4
 * Callees: MATH3D_SetUnityMatrix, RotMatrixX, RotMatrix, MulMatrix0
 */
/*
 *  801621D4: addiu       $sp, $sp, -0xA8
 *  801621D8: sw          $s3, 0x9C($sp)
 *  801621DC: addu        $s3, $a0, $zero
 *  801621E0: sw          $s0, 0x90($sp)
 *  801621E4: lw          $s0, 0xB8($sp)
 *  801621E8: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", func_801621D4_E7FF4);

/*
 * scifi_rt_OnUpdate
 * VRAM 0x801623CC, ROM 0x000E81EC
 * Callees: ratan2, 0x8004A820, 0x8004A8A8
 */
/*
 *  801623CC: addiu       $sp, $sp, -0x178
 *  801623D0: sw          $s1, 0x154($sp)
 *  801623D4: addu        $s1, $a0, $zero
 *  801623D8: sw          $ra, 0x174($sp)
 *  801623DC: sw          $fp, 0x170($sp)
 *  801623E0: sw          $s7, 0x16C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rt_OnUpdate);

/*
 * scifi_rt_OnCollide
 * VRAM 0x8016484C, ROM 0x000EA66C
 * Callees: strcmp, 0x80027500, 0x80022714, COLLIDE_UpdateAllTransforms
 */
/*
 *  8016484C: addiu       $sp, $sp, -0x38
 *  80164850: sw          $s1, 0x1C($sp)
 *  80164854: addu        $s1, $a0, $zero
 *  80164858: sw          $s6, 0x30($sp)
 *  8016485C: addu        $s6, $a1, $zero
 *  80164860: sw          $s5, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rt_OnCollide);

/*
 * scifi_rtblast_OnCreate
 * VRAM 0x80164B90, ROM 0x000EA9B0
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80164B90: lwl         $v0, 0x48($a0)
 *  80164B94: lwr         $v0, 0x4B($a0)
 *  80164B98: lh          $v1, 0x4C($a0)
 *  80164B9C: swl         $v0, 0x58($a0)
 *  80164BA0: swr         $v0, 0x5B($a0)
 *  80164BA4: sh          $v1, 0x5C($a0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rtblast_OnCreate);

/*
 * scifi_rtblast_OnUpdate
 * VRAM 0x80164BD0, ROM 0x000EA9F0
 * Callees: INSTANCE_PlainDeath, 0x80047E64
 */
/*
 *  80164BD0: addiu       $sp, $sp, -0x18
 *  80164BD4: sw          $s0, 0x10($sp)
 *  80164BD8: addu        $s0, $a0, $zero
 *  80164BDC: sw          $ra, 0x14($sp)
 *  80164BE0: lhu         $v0, 0x48($s0)
 *  80164BE4: lhu         $v1, 0x58($s0)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rtblast_OnUpdate);

/*
 * scifi_rtblast_OnCollide
 * VRAM 0x80164C74, ROM 0x000EAA94
 * Callees: strcmp, 0x8002275C, INSTANCE_PlainDeath, 0x800256A8
 */
/*
 *  80164C74: addiu       $sp, $sp, -0x20
 *  80164C78: sw          $s2, 0x18($sp)
 *  80164C7C: addu        $s2, $a0, $zero
 *  80164C80: sw          $ra, 0x1C($sp)
 *  80164C84: sw          $s1, 0x14($sp)
 *  80164C88: sw          $s0, 0x10($sp)
 */
INCLUDE_ASM("asm/nonmatchings/SCIFI", scifi_rtblast_OnCollide);
