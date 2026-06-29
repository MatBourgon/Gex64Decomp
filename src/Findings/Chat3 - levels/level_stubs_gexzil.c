/*
 * level_stubs_gexzil.c — Gexzilla vs. Mecharez
 * Level overlay: GEXZIL
 * ROM base: 0x0928A0, VRAM base: 0x80159720
 * Stubs: 87
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/* gexzil_bug_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_bug_OnCreate);

/*
 * gexzil_bug_OnUpdate
 * VRAM 0x801597FC, ROM 0x0009297C
 * Callees: 0x8002DAF8
 */
/*
 *  801597FC: addiu       $sp, $sp, -0x58
 *  80159800: sw          $s2, 0x50($sp)
 *  80159804: addu        $s2, $a0, $zero
 *  80159808: addiu       $a1, $zero, -0x1
 *  8015980C: sw          $ra, 0x54($sp)
 *  80159810: sw          $s1, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_bug_OnUpdate);

/*
 * gexzil_bug_OnCollide
 * VRAM 0x80159A90, ROM 0x00092C10
 * Callees: none
 */
/*
 *  80159A90: addiu       $sp, $sp, -0x20
 *  80159A94: sw          $s0, 0x10($sp)
 *  80159A98: addu        $s0, $a0, $zero
 *  80159A9C: sw          $ra, 0x18($sp)
 *  80159AA0: sw          $s1, 0x14($sp)
 *  80159AA4: lw          $a0, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_bug_OnCollide);

/*
 * func_80159B8C_92D0C
 * VRAM 0x80159B8C, ROM 0x00092D0C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159B8C: lui         $t1, 0x8007
 *  80159B90: lw          $t1, -0x338($t1)
 *  80159B94: addiu       $sp, $sp, -0x40
 *  80159B98: sw          $s4, 0x28($sp)
 *  80159B9C: lw          $s4, 0x50($sp)
 *  80159BA0: sw          $s6, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80159B8C_92D0C);

/*
 * func_80159DEC_92F6C
 * VRAM 0x80159DEC, ROM 0x00092F6C
 * Callees: none
 */
/*
 *  80159DEC: addiu       $sp, $sp, -0x80
 *  80159DF0: sw          $s6, 0x70($sp)
 *  80159DF4: addu        $s6, $a0, $zero
 *  80159DF8: sw          $ra, 0x78($sp)
 *  80159DFC: sw          $s7, 0x74($sp)
 *  80159E00: sw          $s5, 0x6C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80159DEC_92F6C);

/*
 * func_8015A09C_9321C
 * VRAM 0x8015A09C, ROM 0x0009321C
 * Callees: none
 */
/*
 *  8015A09C: addiu       $sp, $sp, -0x38
 *  8015A0A0: sw          $s3, 0x1C($sp)
 *  8015A0A4: addu        $s3, $a0, $zero
 *  8015A0A8: sw          $s2, 0x18($sp)
 *  8015A0AC: addu        $s2, $a1, $zero
 *  8015A0B0: sw          $s7, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015A09C_9321C);

/*
 * gexzil_ebolt_OnCreate
 * VRAM 0x8015A1D4, ROM 0x00093354
 * Callees: 0x80017AB8
 */
/*
 *  8015A1D4: addiu       $sp, $sp, -0x18
 *  8015A1D8: sw          $s0, 0x10($sp)
 *  8015A1DC: addu        $s0, $a0, $zero
 *  8015A1E0: sw          $ra, 0x14($sp)
 *  8015A1E4: lw          $v1, 0x10($s0)
 *  8015A1E8: lui         $v0, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_ebolt_OnCreate);

/*
 * gexzil_ebolt_OnUpdate
 * VRAM 0x8015A250, ROM 0x000933D0
 * Callees: 0x80159DEC
 */
/*
 *  8015A250: addiu       $sp, $sp, -0x18
 *  8015A254: sw          $s0, 0x10($sp)
 *  8015A258: addu        $s0, $a0, $zero
 *  8015A25C: sw          $ra, 0x14($sp)
 *  8015A260: lw          $a1, 0x100($s0)
 *  8015A264: jal         func_80159DEC
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_ebolt_OnUpdate);

/*
 * gexzil_bldg_OnCreate
 * VRAM 0x8015A2A8, ROM 0x00093428
 * Callees: none
 */
/*
 *  8015A2A8: addiu       $sp, $sp, -0x28
 *  8015A2AC: sw          $s0, 0x10($sp)
 *  8015A2B0: addu        $s0, $a0, $zero
 *  8015A2B4: addiu       $v0, $zero, 0x28
 *  8015A2B8: sw          $ra, 0x20($sp)
 *  8015A2BC: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_bldg_OnCreate);

/*
 * gexzil_bldg_OnUpdate
 * VRAM 0x8015A438, ROM 0x000935B8
 * Callees: none
 */
/*
 *  8015A438: addiu       $sp, $sp, -0x30
 *  8015A43C: sw          $s1, 0x1C($sp)
 *  8015A440: addu        $s1, $a0, $zero
 *  8015A444: sw          $ra, 0x28($sp)
 *  8015A448: sw          $s3, 0x24($sp)
 *  8015A44C: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_bldg_OnUpdate);

/*
 * gexzil_bldg_OnCollide
 * VRAM 0x8015A72C, ROM 0x000938AC
 * Callees: 0x80027500
 */
/*
 *  8015A72C: addiu       $sp, $sp, -0x28
 *  8015A730: sw          $s0, 0x10($sp)
 *  8015A734: addu        $s0, $a0, $zero
 *  8015A738: sw          $s1, 0x14($sp)
 *  8015A73C: addu        $s1, $a1, $zero
 *  8015A740: sw          $ra, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_bldg_OnCollide);

/*
 * func_8015A7F0_93970
 * VRAM 0x8015A7F0, ROM 0x00093970
 * Callees: none
 */
/*
 *  8015A7F0: addiu       $sp, $sp, -0xD8
 *  8015A7F4: sw          $s2, 0xB8($sp)
 *  8015A7F8: addu        $s2, $a0, $zero
 *  8015A7FC: sw          $s3, 0xBC($sp)
 *  8015A800: addu        $s3, $a1, $zero
 *  8015A804: sw          $s0, 0xB0($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015A7F0_93970);

/*
 * func_8015AC68_93DE8
 * VRAM 0x8015AC68, ROM 0x00093DE8
 * Callees: 0x8015B334
 */
/*
 *  8015AC68: addiu       $sp, $sp, -0x78
 *  8015AC6C: sw          $s0, 0x60($sp)
 *  8015AC70: addu        $s0, $a0, $zero
 *  8015AC74: sw          $s1, 0x64($sp)
 *  8015AC78: addu        $s1, $a1, $zero
 *  8015AC7C: sw          $s3, 0x6C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015AC68_93DE8);

/*
 * func_8015AE68_93FE8
 * VRAM 0x8015AE68, ROM 0x00093FE8
 * Callees: INSTANCE_BirthCachedObject
 */
/*
 *  8015AE68: addiu       $sp, $sp, -0x40
 *  8015AE6C: sw          $s0, 0x28($sp)
 *  8015AE70: addu        $s0, $a0, $zero
 *  8015AE74: sw          $ra, 0x3C($sp)
 *  8015AE78: sw          $s4, 0x38($sp)
 *  8015AE7C: sw          $s3, 0x34($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015AE68_93FE8);

/*
 * func_8015B144_942C4
 * VRAM 0x8015B144, ROM 0x000942C4
 * Callees: none
 */
/*
 *  8015B144: addiu       $sp, $sp, -0x20
 *  8015B148: sw          $s0, 0x10($sp)
 *  8015B14C: addu        $s0, $a0, $zero
 *  8015B150: sw          $ra, 0x18($sp)
 *  8015B154: sw          $s1, 0x14($sp)
 *  8015B158: lw          $v0, 0xF8($s0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015B144_942C4);

/*
 * func_8015B220_943A0
 * VRAM 0x8015B220, ROM 0x000943A0
 * Callees: 0x8002DAF8
 */
/*
 *  8015B220: addiu       $sp, $sp, -0x18
 *  8015B224: sw          $s0, 0x10($sp)
 *  8015B228: addu        $s0, $a0, $zero
 *  8015B22C: sw          $ra, 0x14($sp)
 *  8015B230: lw          $v0, 0x14($s0)
 *  8015B234: addiu       $v1, $zero, -0x11
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015B220_943A0);

/*
 * func_8015B334_944B4
 * VRAM 0x8015B334, ROM 0x000944B4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B334: lw          $v0, 0x24($a0)
 *  8015B338: nop
 *  8015B33C: beqz        $v0, . + 4 + (0x6 << 2)
 *  8015B340: nop
 *  8015B344: lw          $v1, 0xFC($v0)
 *  8015B348: lw          $v0, 0x100($v0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015B334_944B4);

/* gexzil_mechjet_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_mechjet_OnCreate);

/*
 * gexzil_mechjet_OnUpdate
 * VRAM 0x8015B3B8, ROM 0x00094538
 * Callees: 0x8002DAF8
 */
/*
 *  8015B3B8: addiu       $sp, $sp, -0x18
 *  8015B3BC: sw          $s0, 0x10($sp)
 *  8015B3C0: addu        $s0, $a0, $zero
 *  8015B3C4: sw          $ra, 0x14($sp)
 *  8015B3C8: lw          $v1, 0xF4($s0)
 *  8015B3CC: nop
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_mechjet_OnUpdate);

/*
 * func_8015B460_945E0
 * VRAM 0x8015B460, ROM 0x000945E0
 * Callees: none
 */
/*
 *  8015B460: addiu       $sp, $sp, -0x80
 *  8015B464: sw          $s0, 0x70($sp)
 *  8015B468: addu        $s0, $a0, $zero
 *  8015B46C: sw          $ra, 0x78($sp)
 *  8015B470: sw          $s1, 0x74($sp)
 *  8015B474: lw          $v1, 0x28($s0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015B460_945E0);

/*
 * gexzil_mecha_OnCreate
 * VRAM 0x8015B6A8, ROM 0x00094828
 * Callees: INSTANCE_KillInstance, CAMERA_SetMode, memset, 0x8004C2F4
 */
/*
 *  8015B6A8: addiu       $sp, $sp, -0x30
 *  8015B6AC: sw          $s3, 0x24($sp)
 *  8015B6B0: addu        $s3, $a0, $zero
 *  8015B6B4: sw          $s4, 0x28($sp)
 *  8015B6B8: lui         $v1, 0x2
 *  8015B6BC: sw          $ra, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_mecha_OnCreate);

/*
 * func_8015B964_94AE4
 * VRAM 0x8015B964, ROM 0x00094AE4
 * Callees: ratan2, MATH3D_FastSqrt2, MATH3D_FastSqrt
 */
/*
 *  8015B964: addiu       $sp, $sp, -0x28
 *  8015B968: addu        $t0, $a1, $zero
 *  8015B96C: sw          $s0, 0x18($sp)
 *  8015B970: addu        $s0, $a2, $zero
 *  8015B974: sw          $ra, 0x20($sp)
 *  8015B978: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015B964_94AE4);

/*
 * gexzil_mecha_OnUpdate
 * VRAM 0x8015BA44, ROM 0x00094BC4
 * Callees: none
 */
/*
 *  8015BA44: addiu       $sp, $sp, -0x98
 *  8015BA48: sw          $s2, 0x88($sp)
 *  8015BA4C: addu        $s2, $a0, $zero
 *  8015BA50: sw          $s1, 0x84($sp)
 *  8015BA54: addu        $s1, $a1, $zero
 *  8015BA58: sw          $ra, 0x94($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_mecha_OnUpdate);

/*
 * func_8015C188_95308
 * VRAM 0x8015C188, ROM 0x00095308
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C188: lh          $v1, 0xC0($a1)
 *  8015C18C: nop
 *  8015C190: bnez        $v1, . + 4 + (0x7 << 2)
 *  8015C194: addiu       $v0, $zero, 0x1
 *  8015C198: lbu         $v1, 0x4E($a0)
 *  8015C19C: addiu       $v0, $zero, 0x4
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015C188_95308);

/*
 * func_8015C208_95388
 * VRAM 0x8015C208, ROM 0x00095388
 * Callees: none
 */
/*
 *  8015C208: addiu       $sp, $sp, -0x28
 *  8015C20C: sw          $s0, 0x18($sp)
 *  8015C210: addu        $s0, $a0, $zero
 *  8015C214: sw          $ra, 0x24($sp)
 *  8015C218: sw          $s2, 0x20($sp)
 *  8015C21C: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015C208_95388);

/*
 * gexzil_mekblst_OnCreate
 * VRAM 0x8015C36C, ROM 0x000954EC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C36C: lw          $v0, 0x10($a0)
 *  8015C370: lui         $v1, 0x10
 *  8015C374: sw          $zero, 0x1C($a0)
 *  8015C378: or          $v0, $v0, $v1
 *  8015C37C: jr          $ra
 *  8015C380: sw          $v0, 0x10($a0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_mekblst_OnCreate);

/* gexzil_mekblst_OnUpdate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_mekblst_OnUpdate);

/*
 * func_8015C484_95604
 * VRAM 0x8015C484, ROM 0x00095604
 * Callees: none
 */
/*
 *  8015C484: addiu       $sp, $sp, -0x18
 *  8015C488: sw          $ra, 0x10($sp)
 *  8015C48C: lw          $v0, 0x14($a0)
 *  8015C490: nop
 *  8015C494: andi        $v0, $v0, 0x10
 *  8015C498: beqz        $v0, . + 4 + (0x16 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015C484_95604);

/*
 * func_8015C504_95684
 * VRAM 0x8015C504, ROM 0x00095684
 * Callees: 0x8002E350
 */
/*
 *  8015C504: addiu       $sp, $sp, -0x20
 *  8015C508: sw          $s1, 0x14($sp)
 *  8015C50C: addu        $s1, $a0, $zero
 *  8015C510: sw          $s0, 0x10($sp)
 *  8015C514: addu        $s0, $a1, $zero
 *  8015C518: sw          $ra, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015C504_95684);

/*
 * func_8015C704_95884
 * VRAM 0x8015C704, ROM 0x00095884
 * Callees: none
 */
/*
 *  8015C704: addiu       $sp, $sp, -0x40
 *  8015C708: sw          $s0, 0x20($sp)
 *  8015C70C: addu        $s0, $a0, $zero
 *  8015C710: sw          $s2, 0x28($sp)
 *  8015C714: addu        $s2, $a1, $zero
 *  8015C718: sw          $s3, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015C704_95884);

/*
 * func_8015CADC_95C5C
 * VRAM 0x8015CADC, ROM 0x00095C5C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015CADC: lw          $v1, 0x14($a0)
 *  8015CAE0: nop
 *  8015CAE4: andi        $v0, $v1, 0x10
 *  8015CAE8: beqz        $v0, . + 4 + (0x1D << 2)
 *  8015CAEC: nop
 *  8015CAF0: lh          $v0, 0x4C($a1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015CADC_95C5C);

/*
 * func_8015CB68_95CE8
 * VRAM 0x8015CB68, ROM 0x00095CE8
 * Callees: none
 */
/*
 *  8015CB68: addiu       $sp, $sp, -0x20
 *  8015CB6C: sw          $s2, 0x18($sp)
 *  8015CB70: addu        $s2, $a0, $zero
 *  8015CB74: sw          $s1, 0x14($sp)
 *  8015CB78: addu        $s1, $a1, $zero
 *  8015CB7C: sll         $a2, $a2, 16
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015CB68_95CE8);

/*
 * func_8015CE34_95FB4
 * VRAM 0x8015CE34, ROM 0x00095FB4
 * Callees: none
 */
/*
 *  8015CE34: addiu       $sp, $sp, -0x30
 *  8015CE38: sw          $s2, 0x20($sp)
 *  8015CE3C: addu        $s2, $a0, $zero
 *  8015CE40: sw          $s1, 0x1C($sp)
 *  8015CE44: addu        $s1, $a1, $zero
 *  8015CE48: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015CE34_95FB4);

/*
 * func_8015D1D0_96350
 * VRAM 0x8015D1D0, ROM 0x00096350
 * Callees: none
 */
/*
 *  8015D1D0: addiu       $sp, $sp, -0x28
 *  8015D1D4: sw          $s1, 0x1C($sp)
 *  8015D1D8: addu        $s1, $a1, $zero
 *  8015D1DC: lui         $a1, 0x8007
 *  8015D1E0: lw          $a1, -0x338($a1)
 *  8015D1E4: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015D1D0_96350);

/*
 * func_8015D3C8_96548
 * VRAM 0x8015D3C8, ROM 0x00096548
 * Callees: none
 */
/*
 *  8015D3C8: addiu       $sp, $sp, -0x28
 *  8015D3CC: sw          $s0, 0x18($sp)
 *  8015D3D0: addu        $s0, $a0, $zero
 *  8015D3D4: sw          $ra, 0x24($sp)
 *  8015D3D8: sw          $s2, 0x20($sp)
 *  8015D3DC: sw          $s1, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015D3C8_96548);

/*
 * func_8015D64C_967CC
 * VRAM 0x8015D64C, ROM 0x000967CC
 * Callees: none
 */
/*
 *  8015D64C: addiu       $sp, $sp, -0x20
 *  8015D650: sw          $s0, 0x10($sp)
 *  8015D654: addu        $s0, $a0, $zero
 *  8015D658: sw          $s1, 0x14($sp)
 *  8015D65C: addu        $s1, $a1, $zero
 *  8015D660: addiu       $a0, $zero, 0xA
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015D64C_967CC);

/*
 * func_8015D998_96B18
 * VRAM 0x8015D998, ROM 0x00096B18
 * Callees: 0x8016034C, CAMERA_SetShake
 */
/*
 *  8015D998: addiu       $sp, $sp, -0x28
 *  8015D99C: sw          $s1, 0x14($sp)
 *  8015D9A0: addu        $s1, $a0, $zero
 *  8015D9A4: sw          $s0, 0x10($sp)
 *  8015D9A8: addu        $s0, $a1, $zero
 *  8015D9AC: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015D998_96B18);

/*
 * func_8015DB38_96CB8
 * VRAM 0x8015DB38, ROM 0x00096CB8
 * Callees: none
 */
/*
 *  8015DB38: addiu       $sp, $sp, -0x38
 *  8015DB3C: sw          $s0, 0x20($sp)
 *  8015DB40: addu        $s0, $a0, $zero
 *  8015DB44: sw          $s1, 0x24($sp)
 *  8015DB48: addu        $s1, $a1, $zero
 *  8015DB4C: sw          $s3, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015DB38_96CB8);

/*
 * func_8015DD28_96EA8
 * VRAM 0x8015DD28, ROM 0x00096EA8
 * Callees: CAMERA_SetMode
 */
/*
 *  8015DD28: addiu       $sp, $sp, -0x58
 *  8015DD2C: sw          $s1, 0x4C($sp)
 *  8015DD30: addu        $s1, $a2, $zero
 *  8015DD34: sw          $ra, 0x50($sp)
 *  8015DD38: sw          $s0, 0x48($sp)
 *  8015DD3C: lh          $v0, 0x4C12($s1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015DD28_96EA8);

/*
 * func_8015E084_97204
 * VRAM 0x8015E084, ROM 0x00097204
 * Callees: none
 */
/*
 *  8015E084: addiu       $sp, $sp, -0x28
 *  8015E088: sw          $s2, 0x20($sp)
 *  8015E08C: addu        $s2, $a0, $zero
 *  8015E090: sw          $s0, 0x18($sp)
 *  8015E094: addu        $s0, $a1, $zero
 *  8015E098: sw          $ra, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015E084_97204);

/*
 * func_8015E390_97510
 * VRAM 0x8015E390, ROM 0x00097510
 * Callees: none
 */
/*
 *  8015E390: addiu       $sp, $sp, -0xD8
 *  8015E394: sw          $s4, 0xC0($sp)
 *  8015E398: addu        $s4, $a0, $zero
 *  8015E39C: sw          $s1, 0xB4($sp)
 *  8015E3A0: addu        $s1, $a1, $zero
 *  8015E3A4: sw          $s7, 0xCC($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015E390_97510);

/*
 * func_8015E8C0_97A40
 * VRAM 0x8015E8C0, ROM 0x00097A40
 * Callees: none
 */
/*
 *  8015E8C0: addiu       $sp, $sp, -0x28
 *  8015E8C4: sw          $s1, 0x1C($sp)
 *  8015E8C8: addu        $s1, $a0, $zero
 *  8015E8CC: sw          $ra, 0x24($sp)
 *  8015E8D0: sw          $s2, 0x20($sp)
 *  8015E8D4: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015E8C0_97A40);

/*
 * func_8015EA18_97B98
 * VRAM 0x8015EA18, ROM 0x00097B98
 * Callees: 0x8015C188
 */
/*
 *  8015EA18: addiu       $sp, $sp, -0x18
 *  8015EA1C: sw          $s0, 0x10($sp)
 *  8015EA20: addu        $s0, $a1, $zero
 *  8015EA24: addiu       $v1, $zero, -0x11
 *  8015EA28: sw          $ra, 0x14($sp)
 *  8015EA2C: lw          $v0, 0x14($a0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015EA18_97B98);

/*
 * func_8015EA68_97BE8
 * VRAM 0x8015EA68, ROM 0x00097BE8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015EA68: lw          $v0, 0x1C($a0)
 *  8015EA6C: nop
 *  8015EA70: lw          $a2, 0x20($v0)
 *  8015EA74: addiu       $v0, $zero, 0x9
 *  8015EA78: sh          $v0, 0x26($a1)
 *  8015EA7C: addiu       $v0, $zero, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015EA68_97BE8);

/*
 * func_8015EAB8_97C38
 * VRAM 0x8015EAB8, ROM 0x00097C38
 * Callees: 0x8015C188
 */
/*
 *  8015EAB8: addiu       $sp, $sp, -0x18
 *  8015EABC: sw          $s0, 0x10($sp)
 *  8015EAC0: addu        $s0, $a0, $zero
 *  8015EAC4: addiu       $v0, $zero, 0x1
 *  8015EAC8: sw          $ra, 0x14($sp)
 *  8015EACC: sw          $v0, 0x54($a1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015EAB8_97C38);

/*
 * func_8015EAFC_97C7C
 * VRAM 0x8015EAFC, ROM 0x00097C7C
 * Callees: none
 */
/*
 *  8015EAFC: addiu       $sp, $sp, -0x18
 *  8015EB00: sw          $s0, 0x10($sp)
 *  8015EB04: addu        $s0, $a0, $zero
 *  8015EB08: addiu       $v0, $zero, 0x14
 *  8015EB0C: sw          $ra, 0x14($sp)
 *  8015EB10: jal         func_8015C188
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015EAFC_97C7C);

/*
 * func_8015EB38_97CB8
 * VRAM 0x8015EB38, ROM 0x00097CB8
 * Callees: none
 */
/*
 *  8015EB38: addiu       $v0, $zero, 0xA
 *  8015EB3C: sw          $zero, 0x54($a1)
 *  8015EB40: sh          $v0, 0x26($a1)
 *  8015EB44: sb          $zero, 0x4E($a0)
 *  8015EB48: sh          $zero, 0x5E($a0)
 *  8015EB4C: sh          $zero, 0x14($a1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015EB38_97CB8);

/*
 * func_8015EB68_97CE8
 * VRAM 0x8015EB68, ROM 0x00097CE8
 * Callees: none
 */
/*
 *  8015EB68: addiu       $sp, $sp, -0x10
 *  8015EB6C: lh          $v0, 0x2($a0)
 *  8015EB70: lh          $v1, 0x0($a1)
 *  8015EB74: addu        $a3, $v0, $zero
 *  8015EB78: slt         $v0, $v0, $v1
 *  8015EB7C: beqz        $v0, . + 4 + (0x15 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015EB68_97CE8);

/*
 * func_8015EC5C_97DDC
 * VRAM 0x8015EC5C, ROM 0x00097DDC
 * Callees: horror_zombie_OnUpdate, 0x8015EB68
 */
/*
 *  8015EC5C: addiu       $sp, $sp, -0x40
 *  8015EC60: sw          $s3, 0x34($sp)
 *  8015EC64: addu        $s3, $a0, $zero
 *  8015EC68: sw          $s2, 0x30($sp)
 *  8015EC6C: addu        $s2, $a1, $zero
 *  8015EC70: addiu       $a1, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015EC5C_97DDC);

/*
 * func_8015F11C_9829C
 * VRAM 0x8015F11C, ROM 0x0009829C
 * Callees: 0x8015F93C
 */
/*
 *  8015F11C: addiu       $sp, $sp, -0x38
 *  8015F120: sw          $s3, 0x24($sp)
 *  8015F124: addu        $s3, $a0, $zero
 *  8015F128: sw          $s2, 0x20($sp)
 *  8015F12C: addu        $s2, $a1, $zero
 *  8015F130: sw          $s0, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015F11C_9829C);

/*
 * func_8015F558_986D8
 * VRAM 0x8015F558, ROM 0x000986D8
 * Callees: none
 */
/*
 *  8015F558: addiu       $v0, $zero, 0x3
 *  8015F55C: sh          $v0, 0x26($a1)
 *  8015F560: addiu       $v0, $zero, 0x6
 *  8015F564: sb          $v0, 0x4E($a0)
 *  8015F568: sh          $zero, 0x5E($a0)
 *  8015F56C: sh          $zero, 0x14($a1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015F558_986D8);

/*
 * func_8015F588_98708
 * VRAM 0x8015F588, ROM 0x00098708
 * Callees: none
 */
/*
 *  8015F588: addiu       $v0, $zero, 0x1
 *  8015F58C: sh          $v0, 0x26($a1)
 *  8015F590: lbu         $v1, 0x4E($a0)
 *  8015F594: addiu       $v0, $zero, 0x6
 *  8015F598: beq         $v1, $v0, . + 4 + (0x9 << 2)
 *  8015F59C: addiu       $v0, $zero, 0x6
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015F588_98708);

/*
 * func_8015F5D4_98754
 * VRAM 0x8015F5D4, ROM 0x00098754
 * Callees: none
 */
/*
 *  8015F5D4: addiu       $sp, $sp, -0x18
 *  8015F5D8: sw          $ra, 0x10($sp)
 *  8015F5DC: lw          $v0, 0x18($a1)
 *  8015F5E0: nop
 *  8015F5E4: andi        $v0, $v0, 0x200
 *  8015F5E8: beqz        $v0, . + 4 + (0x5 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015F5D4_98754);

/*
 * func_8015F680_98800
 * VRAM 0x8015F680, ROM 0x00098800
 * Callees: none
 */
/*
 *  8015F680: addiu       $sp, $sp, -0x18
 *  8015F684: sw          $ra, 0x14($sp)
 *  8015F688: sw          $s0, 0x10($sp)
 *  8015F68C: lw          $v0, 0x18($a0)
 *  8015F690: nop
 *  8015F694: lw          $s0, 0x1C($v0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015F680_98800);

/*
 * func_8015F708_98888
 * VRAM 0x8015F708, ROM 0x00098888
 * Callees: none
 */
/*
 *  8015F708: addiu       $sp, $sp, -0x28
 *  8015F70C: sw          $ra, 0x24($sp)
 *  8015F710: sw          $s4, 0x20($sp)
 *  8015F714: sw          $s3, 0x1C($sp)
 *  8015F718: sw          $s2, 0x18($sp)
 *  8015F71C: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015F708_98888);

/*
 * func_8015F7B4_98934
 * VRAM 0x8015F7B4, ROM 0x00098934
 * Callees: none
 */
/*
 *  8015F7B4: addiu       $sp, $sp, -0x30
 *  8015F7B8: sw          $s4, 0x28($sp)
 *  8015F7BC: addu        $s4, $a0, $zero
 *  8015F7C0: sw          $s2, 0x20($sp)
 *  8015F7C4: addu        $s2, $a1, $zero
 *  8015F7C8: sw          $s3, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015F7B4_98934);

/*
 * func_8015F93C_98ABC
 * VRAM 0x8015F93C, ROM 0x00098ABC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F93C: lw          $v0, 0x18($a0)
 *  8015F940: addu        $t0, $zero, $zero
 *  8015F944: lw          $t4, 0x1C($v0)
 *  8015F948: lui         $t2, 0x4000
 *  8015F94C: lw          $a3, 0xA4($t4)
 *  8015F950: nop
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015F93C_98ABC);

/*
 * func_8015FA98_98C18
 * VRAM 0x8015FA98, ROM 0x00098C18
 * Callees: none
 */
/*
 *  8015FA98: addiu       $sp, $sp, -0xA8
 *  8015FA9C: sw          $s2, 0x88($sp)
 *  8015FAA0: addu        $s2, $a1, $zero
 *  8015FAA4: sw          $ra, 0xA4($sp)
 *  8015FAA8: sw          $fp, 0xA0($sp)
 *  8015FAAC: sw          $s7, 0x9C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015FA98_98C18);

/*
 * func_8015FD80_98F00
 * VRAM 0x8015FD80, ROM 0x00098F00
 * Callees: MATH3D_FastSqrt2, MATH3D_FastSqrt
 */
/*
 *  8015FD80: addiu       $sp, $sp, -0x60
 *  8015FD84: sw          $s4, 0x50($sp)
 *  8015FD88: addu        $s4, $a0, $zero
 *  8015FD8C: lui         $a0, 0x8007
 *  8015FD90: lw          $a0, -0x338($a0)
 *  8015FD94: sw          $ra, 0x5C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015FD80_98F00);

/*
 * func_8015FF80_99100
 * VRAM 0x8015FF80, ROM 0x00099100
 * Callees: none
 */
/*
 *  8015FF80: addu        $a2, $a0, $zero
 *  8015FF84: addiu       $v0, $zero, 0x28
 *  8015FF88: lw          $v1, 0x1C($a2)
 *  8015FF8C: lh          $a0, 0x26($a1)
 *  8015FF90: lw          $a3, 0x20($v1)
 *  8015FF94: nop
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015FF80_99100);

/*
 * func_8015FFDC_9915C
 * VRAM 0x8015FFDC, ROM 0x0009915C
 * Callees: none
 */
/*
 *  8015FFDC: addiu       $sp, $sp, -0x20
 *  8015FFE0: sw          $ra, 0x1C($sp)
 *  8015FFE4: sw          $s2, 0x18($sp)
 *  8015FFE8: sw          $s1, 0x14($sp)
 *  8015FFEC: sw          $s0, 0x10($sp)
 *  8015FFF0: lh          $v0, 0x3E($a1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8015FFDC_9915C);

/*
 * func_8016014C_992CC
 * VRAM 0x8016014C, ROM 0x000992CC
 * Callees: OBTABLE_FindObject
 */
/*
 *  8016014C: addiu       $sp, $sp, -0x8
 *  80160150: lh          $v1, 0x2C($a1)
 *  80160154: addiu       $v0, $zero, -0x1
 *  80160158: bne         $v1, $v0, . + 4 + (0x1C << 2)
 *  8016015C: addu        $a2, $zero, $zero
 *  80160160: lh          $v0, 0x3C($a1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8016014C_992CC);

/*
 * func_801601D8_99358
 * VRAM 0x801601D8, ROM 0x00099358
 * Callees: OBTABLE_FindObject
 */
/*
 *  801601D8: addiu       $sp, $sp, -0x28
 *  801601DC: sw          $ra, 0x20($sp)
 *  801601E0: sw          $s1, 0x1C($sp)
 *  801601E4: sw          $s0, 0x18($sp)
 *  801601E8: lh          $v0, 0x50($a1)
 *  801601EC: nop
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_801601D8_99358);

/*
 * func_8016034C_994CC
 * VRAM 0x8016034C, ROM 0x000994CC
 * Callees: none
 */
/*
 *  8016034C: addiu       $sp, $sp, -0x40
 *  80160350: sw          $s2, 0x28($sp)
 *  80160354: addu        $s2, $a0, $zero
 *  80160358: sw          $s1, 0x24($sp)
 *  8016035C: addu        $s1, $a1, $zero
 *  80160360: sw          $ra, 0x3C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8016034C_994CC);

/*
 * gexzil_mecha_OnCollide
 * VRAM 0x80160704, ROM 0x00099884
 * Callees: none
 */
/*
 *  80160704: addiu       $sp, $sp, -0x38
 *  80160708: sw          $s0, 0x20($sp)
 *  8016070C: addu        $s0, $a0, $zero
 *  80160710: sw          $s3, 0x2C($sp)
 *  80160714: addu        $s3, $a1, $zero
 *  80160718: sw          $ra, 0x34($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_mecha_OnCollide);

/*
 * func_80160B70_99CF0
 * VRAM 0x80160B70, ROM 0x00099CF0
 * Callees: none
 */
/*
 *  80160B70: addiu       $sp, $sp, -0x18
 *  80160B74: sw          $a0, 0x18($sp)
 *  80160B78: lh          $v0, 0x18($sp)
 *  80160B7C: sw          $a1, 0x1C($sp)
 *  80160B80: lh          $v1, 0x1C($sp)
 *  80160B84: nop
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80160B70_99CF0);

/*
 * func_80160BD8_99D58
 * VRAM 0x80160BD8, ROM 0x00099D58
 * Callees: ratan2
 */
/*
 *  80160BD8: addiu       $sp, $sp, -0x18
 *  80160BDC: sw          $a1, 0x1C($sp)
 *  80160BE0: lh          $v1, 0x1E($sp)
 *  80160BE4: sw          $a0, 0x18($sp)
 *  80160BE8: lh          $a0, 0x1A($sp)
 *  80160BEC: lh          $v0, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80160BD8_99D58);

/*
 * func_80160C28_99DA8
 * VRAM 0x80160C28, ROM 0x00099DA8
 * Callees: none
 */
/*
 *  80160C28: addiu       $sp, $sp, -0x30
 *  80160C2C: addu        $t3, $zero, $zero
 *  80160C30: lh          $v1, 0x0($a0)
 *  80160C34: lh          $v0, 0x0($a1)
 *  80160C38: nop
 *  80160C3C: addu        $t5, $v0, $zero
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80160C28_99DA8);

/*
 * func_80160DF8_99F78
 * VRAM 0x80160DF8, ROM 0x00099F78
 * Callees: none
 */
/*
 *  80160DF8: addiu       $sp, $sp, -0xB8
 *  80160DFC: sw          $s1, 0x94($sp)
 *  80160E00: lui         $s1, 0x8008
 *  80160E04: lw          $s1, -0x7D78($s1)
 *  80160E08: sw          $fp, 0xB0($sp)
 *  80160E0C: addu        $fp, $a0, $zero
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80160DF8_99F78);

/*
 * func_801614B0_9A630
 * VRAM 0x801614B0, ROM 0x0009A630
 * Callees: none
 */
/*
 *  801614B0: addiu       $sp, $sp, -0x10
 *  801614B4: lui         $a2, 0x4000
 *  801614B8: lui         $a1, 0x8008
 *  801614BC: lw          $a1, -0x7D78($a1)
 *  801614C0: nop
 *  801614C4: lb          $v0, 0x7($a1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_801614B0_9A630);

/*
 * func_80161538_9A6B8
 * VRAM 0x80161538, ROM 0x0009A6B8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80161538: lui         $v0, 0x8015
 *  8016153C: lw          $v0, 0x3A70($v0)
 *  80161540: nop
 *  80161544: beq         $a0, $v0, . + 4 + (0x16 << 2)
 *  80161548: addu        $v0, $zero, $zero
 *  8016154C: lui         $v0, 0x800C
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80161538_9A6B8);

/*
 * func_801615A8_9A728
 * VRAM 0x801615A8, ROM 0x0009A728
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  801615A8: lui         $v0, 0x8015
 *  801615AC: lw          $v0, 0x3A70($v0)
 *  801615B0: addu        $a1, $a0, $zero
 *  801615B4: beq         $a1, $v0, . + 4 + (0x19 << 2)
 *  801615B8: addu        $v0, $zero, $zero
 *  801615BC: lui         $v0, 0x800C
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_801615A8_9A728);

/*
 * func_80161624_9A7A4
 * VRAM 0x80161624, ROM 0x0009A7A4
 * Callees: none
 */
/*
 *  80161624: addiu       $sp, $sp, -0x68
 *  80161628: sw          $s4, 0x50($sp)
 *  8016162C: addu        $s4, $a0, $zero
 *  80161630: sw          $s6, 0x58($sp)
 *  80161634: addu        $s6, $zero, $zero
 *  80161638: sw          $s3, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80161624_9A7A4);

/*
 * func_80161938_9AAB8
 * VRAM 0x80161938, ROM 0x0009AAB8
 * Callees: none
 */
/*
 *  80161938: addu        $a3, $a0, $zero
 *  8016193C: lhu         $a0, 0x0($a1)
 *  80161940: lh          $v0, 0x4($a1)
 *  80161944: lh          $v1, 0x0($a1)
 *  80161948: addu        $a2, $v0, $zero
 *  8016194C: slt         $v0, $v0, $v1
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80161938_9AAB8);

/*
 * func_80161A18_9AB98
 * VRAM 0x80161A18, ROM 0x0009AB98
 * Callees: none
 */
/*
 *  80161A18: addiu       $sp, $sp, -0x40
 *  80161A1C: sw          $s6, 0x30($sp)
 *  80161A20: addu        $s6, $a0, $zero
 *  80161A24: sw          $s7, 0x34($sp)
 *  80161A28: addu        $s7, $a1, $zero
 *  80161A2C: sw          $s5, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80161A18_9AB98);

/*
 * func_80161B4C_9ACCC
 * VRAM 0x80161B4C, ROM 0x0009ACCC
 * Callees: none
 */
/*
 *  80161B4C: addiu       $sp, $sp, -0x50
 *  80161B50: sw          $s1, 0x3C($sp)
 *  80161B54: addu        $s1, $a0, $zero
 *  80161B58: sw          $s0, 0x38($sp)
 *  80161B5C: addu        $s0, $a1, $zero
 *  80161B60: sw          $ra, 0x48($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80161B4C_9ACCC);

/*
 * func_80161EC4_9B044
 * VRAM 0x80161EC4, ROM 0x0009B044
 * Callees: 0x80161B4C
 */
/*
 *  80161EC4: addiu       $sp, $sp, -0x18
 *  80161EC8: sw          $ra, 0x10($sp)
 *  80161ECC: jal         func_80161B4C
 *  80161ED0: addiu       $a1, $a1, 0x8
 *  80161ED4: lw          $ra, 0x10($sp)
 *  80161ED8: addiu       $sp, $sp, 0x18
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80161EC4_9B044);

/*
 * func_80161EE4_9B064
 * VRAM 0x80161EE4, ROM 0x0009B064
 * Callees: none
 */
/*
 *  80161EE4: addiu       $sp, $sp, -0x38
 *  80161EE8: sw          $s3, 0x24($sp)
 *  80161EEC: lui         $s3, 0x8008
 *  80161EF0: lw          $s3, -0x7D78($s3)
 *  80161EF4: sw          $s4, 0x28($sp)
 *  80161EF8: addu        $s4, $a0, $zero
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80161EE4_9B064);

/*
 * func_80161FF8_9B178
 * VRAM 0x80161FF8, ROM 0x0009B178
 * Callees: 0x80161624, 0x80161EE4
 */
/*
 *  80161FF8: addiu       $sp, $sp, -0x18
 *  80161FFC: sw          $s0, 0x10($sp)
 *  80162000: sw          $ra, 0x14($sp)
 *  80162004: jal         func_80161624
 *  80162008: addu        $s0, $a0, $zero
 *  8016200C: jal         func_80161EE4
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80161FF8_9B178);

/*
 * func_80162024_9B1A4
 * VRAM 0x80162024, ROM 0x0009B1A4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80162024: lui         $v1, 0x8008
 *  80162028: lw          $v1, -0x7D78($v1)
 *  8016202C: addiu       $sp, $sp, -0x28
 *  80162030: sw          $ra, 0x24($sp)
 *  80162034: sw          $s4, 0x20($sp)
 *  80162038: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_80162024_9B1A4);

/*
 * func_8016218C_9B30C
 * VRAM 0x8016218C, ROM 0x0009B30C
 * Callees: none
 */
/*
 *  8016218C: addiu       $sp, $sp, -0x30
 *  80162190: sw          $ra, 0x2C($sp)
 *  80162194: sw          $s2, 0x28($sp)
 *  80162198: sw          $s1, 0x24($sp)
 *  8016219C: sw          $s0, 0x20($sp)
 *  801621A0: lwl         $v0, 0x0($a1)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", func_8016218C_9B30C);

/*
 * gexzil_gas_OnCreate
 * VRAM 0x80162330, ROM 0x0009B4B0
 * Callees: none
 */
/*
 *  80162330: addiu       $sp, $sp, -0x28
 *  80162334: sw          $s0, 0x10($sp)
 *  80162338: addu        $s0, $a0, $zero
 *  8016233C: sw          $s1, 0x14($sp)
 *  80162340: addu        $s1, $zero, $zero
 *  80162344: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_gas_OnCreate);

/*
 * gexzil_gas_OnUpdate
 * VRAM 0x80162574, ROM 0x0009B6F4
 * Callees: none
 */
/*
 *  80162574: addiu       $sp, $sp, -0x20
 *  80162578: sw          $s0, 0x10($sp)
 *  8016257C: addu        $s0, $a0, $zero
 *  80162580: sw          $s1, 0x14($sp)
 *  80162584: addiu       $s1, $s0, 0xFC
 *  80162588: sw          $ra, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_gas_OnUpdate);

/*
 * gexzil_gas_OnCollide
 * VRAM 0x801627B8, ROM 0x0009B938
 * Callees: 0x80027578, 0x800223F8
 */
/*
 *  801627B8: addiu       $sp, $sp, -0x18
 *  801627BC: sw          $ra, 0x10($sp)
 *  801627C0: lw          $v0, 0x78($a0)
 *  801627C4: nop
 *  801627C8: lw          $a2, 0x14($v0)
 *  801627CC: nop
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_gas_OnCollide);

/*
 * gexzil_explode_OnCreate
 * VRAM 0x8016285C, ROM 0x0009B9DC
 * Callees: 0x8006A020
 */
/*
 *  8016285C: addiu       $sp, $sp, -0x38
 *  80162860: sw          $s0, 0x28($sp)
 *  80162864: addu        $s0, $a0, $zero
 *  80162868: sw          $ra, 0x30($sp)
 *  8016286C: sw          $s1, 0x2C($sp)
 *  80162870: lw          $v1, 0x18($s0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_explode_OnCreate);

/*
 * gexzil_explode_OnUpdate
 * VRAM 0x80162990, ROM 0x0009BB10
 * Callees: 0x80033200, 0x800506B8, INSTANCE_KillInstance
 */
/*
 *  80162990: addiu       $sp, $sp, -0x28
 *  80162994: sw          $s0, 0x18($sp)
 *  80162998: addu        $s0, $a0, $zero
 *  8016299C: sw          $ra, 0x20($sp)
 *  801629A0: sw          $s1, 0x1C($sp)
 *  801629A4: lw          $a0, 0x100($s0)
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_explode_OnUpdate);

/*
 * gexzil_explode_OnCollide
 * VRAM 0x80162A40, ROM 0x0009BBC0
 * Callees: 0x80022714
 */
/*
 *  80162A40: addiu       $sp, $sp, -0x18
 *  80162A44: sw          $ra, 0x10($sp)
 *  80162A48: lw          $a2, 0x78($a0)
 *  80162A4C: lw          $v0, 0xC($a1)
 *  80162A50: lw          $v1, 0x14($a2)
 *  80162A54: nop
 */
INCLUDE_ASM("asm/nonmatchings/GEXZIL", gexzil_explode_OnCollide);
