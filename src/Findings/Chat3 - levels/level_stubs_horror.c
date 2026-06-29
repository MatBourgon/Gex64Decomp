/*
 * level_stubs_horror.c — Scream TV
 * Level overlay: HORROR
 * ROM base: 0x09CF50, VRAM base: 0x80159720
 * Stubs: 86
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/* horror_drawer_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_drawer_OnCreate);

/*
 * horror_drawer_OnUpdate
 * VRAM 0x80159770, ROM 0x0009CFA0
 * Callees: none
 */
/*
 *  80159770: addiu       $sp, $sp, -0x20
 *  80159774: sw          $s0, 0x18($sp)
 *  80159778: addu        $s0, $a0, $zero
 *  8015977C: sw          $ra, 0x1C($sp)
 *  80159780: lw          $v0, 0xFC($s0)
 *  80159784: lw          $v1, 0xF4($s0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_drawer_OnUpdate);

/* horror_chandb_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_chandb_OnCreate);

/*
 * horror_chandb_OnUpdate
 * VRAM 0x801598DC, ROM 0x0009D10C
 * Callees: none
 */
/*
 *  801598DC: addiu       $sp, $sp, -0x28
 *  801598E0: sw          $s0, 0x20($sp)
 *  801598E4: addu        $s0, $a0, $zero
 *  801598E8: sw          $ra, 0x24($sp)
 *  801598EC: lw          $v1, 0xF4($s0)
 *  801598F0: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_chandb_OnUpdate);

/*
 * horror_chandb_OnCollide
 * VRAM 0x80159A54, ROM 0x0009D284
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159A54: lw          $v1, 0x78($a0)
 *  80159A58: nop
 *  80159A5C: lh          $v0, 0x4($v1)
 *  80159A60: addiu       $a1, $zero, 0x1
 *  80159A64: bne         $v0, $a1, . + 4 + (0x2 << 2)
 *  80159A68: addiu       $v0, $zero, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_chandb_OnCollide);

/* horror_chand_OnCreate — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_chand_OnCreate);

/*
 * horror_chand_OnUpdate
 * VRAM 0x80159AB8, ROM 0x0009D2E8
 * Callees: none
 */
/*
 *  80159AB8: addiu       $sp, $sp, -0x28
 *  80159ABC: sw          $s0, 0x18($sp)
 *  80159AC0: addu        $s0, $a0, $zero
 *  80159AC4: sw          $ra, 0x20($sp)
 *  80159AC8: sw          $s1, 0x1C($sp)
 *  80159ACC: lw          $v0, 0x1C($s0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_chand_OnUpdate);

/*
 * horror_chand_OnCollide
 * VRAM 0x80159D08, ROM 0x0009D538
 * Callees: GenericCollide
 */
/*
 *  80159D08: addiu       $sp, $sp, -0x18
 *  80159D0C: sw          $ra, 0x10($sp)
 *  80159D10: lw          $v0, 0x78($a0)
 *  80159D14: nop
 *  80159D18: lh          $v1, 0x6($v0)
 *  80159D1C: addiu       $v0, $zero, 0x4
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_chand_OnCollide);

/*
 * horror_axe_OnCreate
 * VRAM 0x80159D5C, ROM 0x0009D58C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80159D5C: lw          $v0, 0x24($a0)
 *  80159D60: nop
 *  80159D64: lw          $v0, 0x0($v0)
 *  80159D68: nop
 *  80159D6C: bnez        $v0, . + 4 + (0x2 << 2)
 *  80159D70: addiu       $v0, $zero, 0x4
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_axe_OnCreate);

/*
 * func_80159D8C_9D5BC
 * VRAM 0x80159D8C, ROM 0x0009D5BC
 * Callees: none
 */
/*
 *  80159D8C: addiu       $sp, $sp, -0x20
 *  80159D90: sw          $s0, 0x10($sp)
 *  80159D94: addu        $s0, $a0, $zero
 *  80159D98: addu        $t0, $a1, $zero
 *  80159D9C: lw          $v1, 0x38($sp)
 *  80159DA0: lw          $a3, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_80159D8C_9D5BC);

/*
 * func_8015A014_9D844
 * VRAM 0x8015A014, ROM 0x0009D844
 * Callees: none
 */
/*
 *  8015A014: addiu       $sp, $sp, -0x20
 *  8015A018: addu        $a2, $a0, $zero
 *  8015A01C: sw          $ra, 0x18($sp)
 *  8015A020: lh          $v0, 0x20($a2)
 *  8015A024: lh          $a0, 0x50($a2)
 *  8015A028: lh          $v1, 0x44($a2)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_8015A014_9D844);

/*
 * horror_axe_OnUpdate
 * VRAM 0x8015A104, ROM 0x0009D934
 * Callees: none
 */
/*
 *  8015A104: addiu       $sp, $sp, -0x70
 *  8015A108: sw          $s2, 0x58($sp)
 *  8015A10C: addu        $s2, $a0, $zero
 *  8015A110: sw          $ra, 0x68($sp)
 *  8015A114: sw          $s5, 0x64($sp)
 *  8015A118: sw          $s4, 0x60($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_axe_OnUpdate);

/* horror_axe_OnCollide — address unknown (missing from symbol_addrs.txt) */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_axe_OnCollide);

/*
 * horror_face_OnCreate
 * VRAM 0x8015A52C, ROM 0x0009DD5C
 * Callees: none
 */
/*
 *  8015A52C: addu        $a1, $a0, $zero
 *  8015A530: addiu       $v0, $zero, 0x1
 *  8015A534: lui         $v1, 0x10
 *  8015A538: sw          $v0, 0xF4($a1)
 *  8015A53C: lw          $v0, 0x10($a1)
 *  8015A540: lw          $a0, 0x24($a1)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_face_OnCreate);

/*
 * horror_face_OnUpdate
 * VRAM 0x8015A578, ROM 0x0009DDA8
 * Callees: none
 */
/*
 *  8015A578: addiu       $sp, $sp, -0x28
 *  8015A57C: sw          $s0, 0x18($sp)
 *  8015A580: addu        $s0, $a0, $zero
 *  8015A584: sw          $ra, 0x20($sp)
 *  8015A588: sw          $s1, 0x1C($sp)
 *  8015A58C: lw          $v1, 0xF4($s0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_face_OnUpdate);

/*
 * horror_face_OnCollide
 * VRAM 0x8015A720, ROM 0x0009DF50
 * Callees: none
 */
/*
 *  8015A720: addiu       $sp, $sp, -0x18
 *  8015A724: addiu       $v0, $zero, 0x1
 *  8015A728: sw          $ra, 0x10($sp)
 *  8015A72C: lw          $a2, 0xF4($a0)
 *  8015A730: lw          $v1, 0x78($a0)
 *  8015A734: bne         $a2, $v0, . + 4 + (0xC << 2)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_face_OnCollide);

/*
 * horror_zombie_OnCreate
 * VRAM 0x8015A778, ROM 0x0009DFA8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015A778: lw          $v0, 0x10($a0)
 *  8015A77C: lui         $v1, 0x2
 *  8015A780: and         $v0, $v0, $v1
 *  8015A784: lw          $v1, 0x24($a0)
 *  8015A788: nop
 *  8015A78C: beqz        $v0, . + 4 + (0xD << 2)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_zombie_OnCreate);

/*
 * horror_zombie_OnUpdate
 * VRAM 0x8015A7F0, ROM 0x0009E020
 * Callees: none
 */
/*
 *  8015A7F0: addiu       $sp, $sp, -0x68
 *  8015A7F4: sw          $s2, 0x50($sp)
 *  8015A7F8: addu        $s2, $a0, $zero
 *  8015A7FC: sw          $s5, 0x5C($sp)
 *  8015A800: addu        $s5, $a1, $zero
 *  8015A804: sw          $ra, 0x60($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_zombie_OnUpdate);

/*
 * horror_zombie_OnCollide
 * VRAM 0x8015AEC8, ROM 0x0009E6F8
 * Callees: none
 */
/*
 *  8015AEC8: addiu       $sp, $sp, -0x30
 *  8015AECC: sw          $s1, 0x14($sp)
 *  8015AED0: addu        $s1, $a0, $zero
 *  8015AED4: addu        $a2, $a1, $zero
 *  8015AED8: sw          $ra, 0x28($sp)
 *  8015AEDC: sw          $s5, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_zombie_OnCollide);

/*
 * horror_zomarm_OnCreate
 * VRAM 0x8015B27C, ROM 0x0009EAAC
 * Callees: 0x8006A020
 */
/*
 *  8015B27C: addiu       $sp, $sp, -0x18
 *  8015B280: sw          $s0, 0x10($sp)
 *  8015B284: addu        $s0, $a0, $zero
 *  8015B288: addiu       $v0, $zero, -0x10
 *  8015B28C: sw          $ra, 0x14($sp)
 *  8015B290: sw          $v0, 0xE4($s0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_zomarm_OnCreate);

/*
 * horror_zomarm_OnUpdate
 * VRAM 0x8015B2EC, ROM 0x0009EB1C
 * Callees: none
 */
/*
 *  8015B2EC: addiu       $sp, $sp, -0x18
 *  8015B2F0: sw          $s0, 0x10($sp)
 *  8015B2F4: addu        $s0, $a0, $zero
 *  8015B2F8: sw          $ra, 0x14($sp)
 *  8015B2FC: lw          $v1, 0xF4($s0)
 *  8015B300: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_zomarm_OnUpdate);

/*
 * horror_zomarm_OnCollide
 * VRAM 0x8015B448, ROM 0x0009EC78
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015B448: lw          $a1, 0x78($a0)
 *  8015B44C: nop
 *  8015B450: lw          $v0, 0xC($a1)
 *  8015B454: nop
 *  8015B458: lhu         $v0, 0x6($v0)
 *  8015B45C: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_zomarm_OnCollide);

/*
 * horror_zomleg_OnCreate
 * VRAM 0x8015B4C4, ROM 0x0009ECF4
 * Callees: none
 */
/*
 *  8015B4C4: addiu       $v0, $zero, 0x1
 *  8015B4C8: sw          $v0, 0xF4($a0)
 *  8015B4CC: addiu       $v0, $zero, 0x3C
 *  8015B4D0: jr          $ra
 *  8015B4D4: sw          $v0, 0xFC($a0)
 *  8015B4D8: addiu       $sp, $sp, -0x20
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_zomleg_OnCreate);

/*
 * horror_zomleg_OnUpdate
 * VRAM 0x8015B4D8, ROM 0x0009ED08
 * Callees: 0x8003A6AC
 */
/*
 *  8015B4D8: addiu       $sp, $sp, -0x20
 *  8015B4DC: sw          $s0, 0x18($sp)
 *  8015B4E0: addu        $s0, $a0, $zero
 *  8015B4E4: sw          $ra, 0x1C($sp)
 *  8015B4E8: lw          $v1, 0xF4($s0)
 *  8015B4EC: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_zomleg_OnUpdate);

/*
 * horror_huck_OnCreate
 * VRAM 0x8015B5BC, ROM 0x0009EDEC
 * Callees: none
 */
/*
 *  8015B5BC: addiu       $sp, $sp, -0x18
 *  8015B5C0: lui         $v0, 0x2
 *  8015B5C4: sw          $ra, 0x10($sp)
 *  8015B5C8: lw          $a3, 0x10($a0)
 *  8015B5CC: lw          $a2, 0x24($a0)
 *  8015B5D0: and         $v0, $a3, $v0
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_huck_OnCreate);

/*
 * horror_huck_OnUpdate
 * VRAM 0x8015B688, ROM 0x0009EEB8
 * Callees: none
 */
/*
 *  8015B688: addiu       $sp, $sp, -0x58
 *  8015B68C: sw          $s1, 0x3C($sp)
 *  8015B690: addu        $s1, $a0, $zero
 *  8015B694: sw          $s4, 0x48($sp)
 *  8015B698: addu        $s4, $a1, $zero
 *  8015B69C: sw          $ra, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_huck_OnUpdate);

/*
 * horror_huck_OnCollide
 * VRAM 0x8015BB38, ROM 0x0009F368
 * Callees: none
 */
/*
 *  8015BB38: addiu       $sp, $sp, -0x18
 *  8015BB3C: sw          $s0, 0x10($sp)
 *  8015BB40: addu        $s0, $a0, $zero
 *  8015BB44: addu        $a2, $a1, $zero
 *  8015BB48: sw          $ra, 0x14($sp)
 *  8015BB4C: lw          $a1, 0x78($s0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_huck_OnCollide);

/*
 * horror_huckhed_OnCreate
 * VRAM 0x8015BD14, ROM 0x0009F544
 * Callees: 0x8015BF7C, INSTANCE_PlainDeath
 */
/*
 *  8015BD14: addiu       $sp, $sp, -0x18
 *  8015BD18: sw          $s0, 0x10($sp)
 *  8015BD1C: addu        $s0, $a0, $zero
 *  8015BD20: sw          $ra, 0x14($sp)
 *  8015BD24: lw          $v0, 0x10($s0)
 *  8015BD28: lui         $v1, 0x2
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_huckhed_OnCreate);

/*
 * horror_huckhed_OnUpdate
 * VRAM 0x8015BDFC, ROM 0x0009F62C
 * Callees: none
 */
/*
 *  8015BDFC: addiu       $sp, $sp, -0x18
 *  8015BE00: sw          $s0, 0x10($sp)
 *  8015BE04: addu        $s0, $a0, $zero
 *  8015BE08: sw          $ra, 0x14($sp)
 *  8015BE0C: lw          $v1, 0xF4($s0)
 *  8015BE10: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_huckhed_OnUpdate);

/*
 * func_8015BF7C_9F7AC
 * VRAM 0x8015BF7C, ROM 0x0009F7AC
 * Callees: none
 */
/*
 *  8015BF7C: addiu       $sp, $sp, -0x18
 *  8015BF80: sw          $ra, 0x10($sp)
 *  8015BF84: lw          $v0, 0x10($a1)
 *  8015BF88: addu        $t0, $a0, $zero
 *  8015BF8C: lw          $a0, 0x4($v0)
 *  8015BF90: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_8015BF7C_9F7AC);

/*
 * horror_huckhed_OnCollide
 * VRAM 0x8015C028, ROM 0x0009F858
 * Callees: 0x8015BF7C
 */
/*
 *  8015C028: addiu       $sp, $sp, -0x30
 *  8015C02C: sw          $s1, 0x1C($sp)
 *  8015C030: addu        $s1, $a0, $zero
 *  8015C034: sw          $ra, 0x28($sp)
 *  8015C038: sw          $s3, 0x24($sp)
 *  8015C03C: sw          $s2, 0x20($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_huckhed_OnCollide);

/*
 * horror_gate_OnCreate
 * VRAM 0x8015C1AC, ROM 0x0009F9DC
 * Callees: none
 */
/*
 *  8015C1AC: addiu       $sp, $sp, -0x18
 *  8015C1B0: sw          $ra, 0x10($sp)
 *  8015C1B4: lw          $v0, 0x24($a0)
 *  8015C1B8: nop
 *  8015C1BC: beqz        $v0, . + 4 + (0x9 << 2)
 *  8015C1C0: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_gate_OnCreate);

/*
 * horror_gate_OnUpdate
 * VRAM 0x8015C1F4, ROM 0x0009FA24
 * Callees: none
 */
/*
 *  8015C1F4: addiu       $sp, $sp, -0x18
 *  8015C1F8: sw          $ra, 0x10($sp)
 *  8015C1FC: lw          $a1, 0x24($a0)
 *  8015C200: nop
 *  8015C204: beqz        $a1, . + 4 + (0x12 << 2)
 *  8015C208: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_gate_OnUpdate);

/*
 * horror_fltchst_OnCreate
 * VRAM 0x8015C268, ROM 0x0009FA98
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C268: lw          $v0, 0x24($a0)
 *  8015C26C: nop
 *  8015C270: bnez        $v0, . + 4 + (0x7 << 2)
 *  8015C274: sw          $zero, 0xF4($a0)
 *  8015C278: lui         $v0, 0x8002
 *  8015C27C: addiu       $v0, $v0, -0x530C
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_fltchst_OnCreate);

/*
 * horror_fltchst_OnUpdate
 * VRAM 0x8015C480, ROM 0x0009FCB0
 * Callees: none
 */
/*
 *  8015C480: addiu       $sp, $sp, -0x30
 *  8015C484: sw          $s0, 0x18($sp)
 *  8015C488: addu        $s0, $a0, $zero
 *  8015C48C: sw          $s2, 0x20($sp)
 *  8015C490: sw          $ra, 0x28($sp)
 *  8015C494: sw          $s3, 0x24($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_fltchst_OnUpdate);

/*
 * horror_fltchst_OnCollide
 * VRAM 0x8015C74C, ROM 0x0009FF7C
 * Callees: none
 */
/*
 *  8015C74C: addiu       $sp, $sp, -0x20
 *  8015C750: sw          $s0, 0x10($sp)
 *  8015C754: addu        $s0, $a0, $zero
 *  8015C758: addu        $a2, $a1, $zero
 *  8015C75C: sw          $ra, 0x18($sp)
 *  8015C760: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_fltchst_OnCollide);

/*
 * horror_ledge_OnCreate
 * VRAM 0x8015C8A4, ROM 0x000A00D4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C8A4: lw          $v1, 0x24($a0)
 *  8015C8A8: addiu       $v0, $zero, 0xA
 *  8015C8AC: beqz        $v1, . + 4 + (0x6 << 2)
 *  8015C8B0: sw          $v0, 0x100($a0)
 *  8015C8B4: lw          $v1, 0x0($v1)
 *  8015C8B8: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_ledge_OnCreate);

/*
 * horror_ledge_OnUpdate
 * VRAM 0x8015C8D0, ROM 0x000A0100
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015C8D0: lw          $v1, 0xF4($a0)
 *  8015C8D4: addiu       $a1, $zero, 0x1
 *  8015C8D8: bne         $v1, $a1, . + 4 + (0xD << 2)
 *  8015C8DC: addiu       $v0, $zero, 0x2
 *  8015C8E0: lw          $a1, 0xFC($a0)
 *  8015C8E4: lw          $v1, 0x100($a0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_ledge_OnUpdate);

/*
 * horror_ldgeact_OnUpdate
 * VRAM 0x8015C958, ROM 0x000A0188
 * Callees: none
 */
/*
 *  8015C958: addiu       $sp, $sp, -0x18
 *  8015C95C: addu        $a3, $a1, $zero
 *  8015C960: sw          $ra, 0x14($sp)
 *  8015C964: sw          $s0, 0x10($sp)
 *  8015C968: lw          $a1, 0x1C($a0)
 *  8015C96C: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_ldgeact_OnUpdate);

/*
 * horror_bkshlf_OnUpdate
 * VRAM 0x8015CA44, ROM 0x000A0274
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015CA44: lw          $v1, 0xF8($a0)
 *  8015CA48: addiu       $v0, $zero, 0x1
 *  8015CA4C: bne         $v1, $v0, . + 4 + (0x5 << 2)
 *  8015CA50: nop
 *  8015CA54: lhu         $v0, 0x64($a0)
 *  8015CA58: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_bkshlf_OnUpdate);

/*
 * horror_bkshlf_OnCollide
 * VRAM 0x8015CA88, ROM 0x000A02B8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015CA88: lw          $a2, 0x78($a0)
 *  8015CA8C: nop
 *  8015CA90: lh          $a3, 0x6($a2)
 *  8015CA94: addiu       $v0, $zero, 0x1
 *  8015CA98: bne         $a3, $v0, . + 4 + (0x1A << 2)
 *  8015CA9C: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_bkshlf_OnCollide);

/*
 * horror_fltlamp_OnCreate
 * VRAM 0x8015CB0C, ROM 0x000A033C
 * Callees: none
 */
/*
 *  8015CB0C: addiu       $sp, $sp, -0x48
 *  8015CB10: sw          $s0, 0x30($sp)
 *  8015CB14: addu        $s0, $a0, $zero
 *  8015CB18: sw          $s3, 0x3C($sp)
 *  8015CB1C: sw          $ra, 0x40($sp)
 *  8015CB20: sw          $s2, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_fltlamp_OnCreate);

/*
 * horror_fltlamp_OnUpdate
 * VRAM 0x8015CF04, ROM 0x000A0734
 * Callees: none
 */
/*
 *  8015CF04: addiu       $sp, $sp, -0xC8
 *  8015CF08: sw          $s1, 0xA4($sp)
 *  8015CF0C: addu        $s1, $a0, $zero
 *  8015CF10: sw          $s7, 0xBC($sp)
 *  8015CF14: addu        $s7, $a1, $zero
 *  8015CF18: sw          $ra, 0xC4($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_fltlamp_OnUpdate);

/*
 * horror_polter_OnCreate
 * VRAM 0x8015DEE4, ROM 0x000A1714
 * Callees: none
 */
/*
 *  8015DEE4: addiu       $v0, $zero, 0x1
 *  8015DEE8: sh          $v0, 0x68($a0)
 *  8015DEEC: sh          $v0, 0x6A($a0)
 *  8015DEF0: jr          $ra
 *  8015DEF4: sh          $v0, 0x6C($a0)
 *  8015DEF8: addu        $a2, $a0, $zero
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_polter_OnCreate);

/*
 * horror_polter_OnUpdate
 * VRAM 0x8015DEF8, ROM 0x000A1728
 * Callees: none
 */
/*
 *  8015DEF8: addu        $a2, $a0, $zero
 *  8015DEFC: lw          $v1, 0xF4($a2)
 *  8015DF00: addiu       $v0, $zero, 0x1
 *  8015DF04: bne         $v1, $v0, . + 4 + (0x37 << 2)
 *  8015DF08: addiu       $sp, $sp, -0x18
 *  8015DF0C: lui         $v0, 0x8007
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_polter_OnUpdate);

/*
 * func_8015E05C_A188C
 * VRAM 0x8015E05C, ROM 0x000A188C
 * Callees: none
 */
/*
 *  8015E05C: addiu       $sp, $sp, -0x20
 *  8015E060: sw          $s0, 0x10($sp)
 *  8015E064: addu        $s0, $a0, $zero
 *  8015E068: addiu       $v0, $zero, 0x1
 *  8015E06C: sw          $ra, 0x18($sp)
 *  8015E070: sw          $s1, 0x14($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_8015E05C_A188C);

/*
 * func_8015E1A8_A19D8
 * VRAM 0x8015E1A8, ROM 0x000A19D8
 * Callees: INSTANCE_PlainDeath
 */
/*
 *  8015E1A8: addiu       $sp, $sp, -0x18
 *  8015E1AC: sw          $ra, 0x10($sp)
 *  8015E1B0: lw          $a2, 0x78($a0)
 *  8015E1B4: nop
 *  8015E1B8: lh          $v1, 0x6($a2)
 *  8015E1BC: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_8015E1A8_A19D8);

/*
 * func_8015E220_A1A50
 * VRAM 0x8015E220, ROM 0x000A1A50
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015E220: lw          $v0, 0x1C($a0)
 *  8015E224: nop
 *  8015E228: lw          $v1, 0x4($v0)
 *  8015E22C: nop
 *  8015E230: beqz        $v1, . + 4 + (0xA << 2)
 *  8015E234: addu        $a0, $zero, $zero
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_8015E220_A1A50);

/*
 * horror_skel_OnCreate
 * VRAM 0x8015E264, ROM 0x000A1A94
 * Callees: 0x8003A6AC, 0x8003A4E0
 */
/*
 *  8015E264: addiu       $sp, $sp, -0x28
 *  8015E268: sw          $s0, 0x10($sp)
 *  8015E26C: addu        $s0, $a0, $zero
 *  8015E270: addiu       $v0, $zero, 0x18
 *  8015E274: sw          $ra, 0x20($sp)
 *  8015E278: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_skel_OnCreate);

/*
 * horror_skel_OnUpdate
 * VRAM 0x8015E3A4, ROM 0x000A1BD4
 * Callees: none
 */
/*
 *  8015E3A4: addiu       $sp, $sp, -0xD0
 *  8015E3A8: sw          $s2, 0xB8($sp)
 *  8015E3AC: addu        $s2, $a0, $zero
 *  8015E3B0: lui         $a0, 0x8007
 *  8015E3B4: lw          $a0, -0x3060($a0)
 *  8015E3B8: sw          $s5, 0xC4($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_skel_OnUpdate);

/*
 * horror_skel_OnCollide
 * VRAM 0x8015F024, ROM 0x000A2854
 * Callees: none
 */
/*
 *  8015F024: addiu       $sp, $sp, -0x28
 *  8015F028: sw          $s0, 0x10($sp)
 *  8015F02C: addu        $s0, $a0, $zero
 *  8015F030: sw          $s2, 0x18($sp)
 *  8015F034: addu        $s2, $a1, $zero
 *  8015F038: sw          $s3, 0x1C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_skel_OnCollide);

/*
 * horror_skelh_OnCreate
 * VRAM 0x8015F234, ROM 0x000A2A64
 * Callees: none
 */
/*
 *  8015F234: addu        $a1, $a0, $zero
 *  8015F238: lw          $v0, 0x28($a1)
 *  8015F23C: nop
 *  8015F240: beqz        $v0, . + 4 + (0x13 << 2)
 *  8015F244: sw          $zero, 0xF4($a1)
 *  8015F248: lw          $v0, 0x1C($v0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_skelh_OnCreate);

/*
 * horror_skelh_OnUpdate
 * VRAM 0x8015F298, ROM 0x000A2AC8
 * Callees: INSTANCE_KillInstance
 */
/*
 *  8015F298: addiu       $sp, $sp, -0x28
 *  8015F29C: sw          $s0, 0x18($sp)
 *  8015F2A0: addu        $s0, $a0, $zero
 *  8015F2A4: sw          $ra, 0x20($sp)
 *  8015F2A8: sw          $s1, 0x1C($sp)
 *  8015F2AC: lw          $v0, 0x28($s0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_skelh_OnUpdate);

/*
 * horror_skelh_OnCollide
 * VRAM 0x8015F3A0, ROM 0x000A2BD0
 * Callees: INSTANCE_PlainDeath
 */
/*
 *  8015F3A0: addiu       $sp, $sp, -0x18
 *  8015F3A4: sw          $ra, 0x10($sp)
 *  8015F3A8: lw          $a2, 0x78($a0)
 *  8015F3AC: nop
 *  8015F3B0: lh          $v1, 0x6($a2)
 *  8015F3B4: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_skelh_OnCollide);

/*
 * horror_fltlamp_OnCollide
 * VRAM 0x8015F45C, ROM 0x000A2C8C
 * Callees: none
 */
/*
 *  8015F45C: addiu       $sp, $sp, -0x38
 *  8015F460: addu        $t1, $a0, $zero
 *  8015F464: addu        $a2, $a1, $zero
 *  8015F468: lui         $v1, 0x1
 *  8015F46C: sw          $ra, 0x30($sp)
 *  8015F470: lw          $a3, 0x78($t1)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_fltlamp_OnCollide);

/*
 * func_8015F620_A2E50
 * VRAM 0x8015F620, ROM 0x000A2E50
 * Callees: none
 */
/*
 *  8015F620: addiu       $sp, $sp, -0x18
 *  8015F624: sw          $s0, 0x10($sp)
 *  8015F628: addu        $s0, $a0, $zero
 *  8015F62C: sw          $ra, 0x14($sp)
 *  8015F630: lhu         $a2, 0x6C($s0)
 *  8015F634: lhu         $v0, 0x24($s0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_8015F620_A2E50);

/*
 * horror_spray_OnUpdate
 * VRAM 0x8015F744, ROM 0x000A2F74
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8015F744: lui         $v0, 0x8007
 *  8015F748: lw          $v0, -0x3060($v0)
 *  8015F74C: addiu       $sp, $sp, -0x48
 *  8015F750: sw          $s0, 0x38($sp)
 *  8015F754: addu        $s0, $a0, $zero
 *  8015F758: sw          $ra, 0x44($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_spray_OnUpdate);

/*
 * horror_spray_OnCollide
 * VRAM 0x8015F9A8, ROM 0x000A31D8
 * Callees: none
 */
/*
 *  8015F9A8: addiu       $sp, $sp, -0x18
 *  8015F9AC: sw          $s0, 0x10($sp)
 *  8015F9B0: addu        $s0, $a0, $zero
 *  8015F9B4: sw          $ra, 0x14($sp)
 *  8015F9B8: lw          $a0, 0x78($s0)
 *  8015F9BC: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_spray_OnCollide);

/*
 * horror_bug_OnUpdate
 * VRAM 0x8015FC34, ROM 0x000A3464
 * Callees: 0x8002DAF8, ScriptGetPosSpline, SplineGetNext, SplineGetData
 */
/*
 *  8015FC34: addiu       $sp, $sp, -0x58
 *  8015FC38: sw          $s2, 0x50($sp)
 *  8015FC3C: addu        $s2, $a0, $zero
 *  8015FC40: addiu       $a1, $zero, -0x1
 *  8015FC44: sw          $ra, 0x54($sp)
 *  8015FC48: sw          $s1, 0x4C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_bug_OnUpdate);

/*
 * horror_bouncer_OnUpdate
 * VRAM 0x80160048, ROM 0x000A3878
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: ratan2
 */
/*
 *  80160048: lui         $v1, 0x8007
 *  8016004C: lw          $v1, -0x3060($v1)
 *  80160050: addiu       $sp, $sp, -0x68
 *  80160054: sw          $s1, 0x44($sp)
 *  80160058: addu        $s1, $a0, $zero
 *  8016005C: sw          $ra, 0x64($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_bouncer_OnUpdate);

/*
 * horror_flasher_OnUpdate
 * VRAM 0x80160B40, ROM 0x000A4370
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80160B40: lui         $v0, 0x8007
 *  80160B44: lw          $v0, -0x338($v0)
 *  80160B48: addiu       $sp, $sp, -0x18
 *  80160B4C: sw          $ra, 0x10($sp)
 *  80160B50: lw          $a0, 0xE0($v0)
 *  80160B54: lui         $v0, 0xCCCC
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_flasher_OnUpdate);

/*
 * horror_hhelev_OnCreate
 * VRAM 0x80160BB4, ROM 0x000A43E4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80160BB4: lw          $v0, 0x10($a0)
 *  80160BB8: nop
 *  80160BBC: ori         $v0, $v0, 0x400
 *  80160BC0: jr          $ra
 *  80160BC4: sw          $v0, 0x10($a0)
 *  80160BC8: jr          $ra
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_hhelev_OnCreate);

/*
 * horror_evileye_OnUpdate
 * VRAM 0x80160BD0, ROM 0x000A4400
 * Callees: none
 */
/*
 *  80160BD0: addiu       $sp, $sp, -0x58
 *  80160BD4: sw          $s4, 0x48($sp)
 *  80160BD8: addu        $s4, $a0, $zero
 *  80160BDC: addiu       $v0, $zero, 0x1
 *  80160BE0: sw          $ra, 0x54($sp)
 *  80160BE4: sw          $s6, 0x50($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_evileye_OnUpdate);

/*
 * horror_evileye_OnCollide
 * VRAM 0x80160ECC, ROM 0x000A46FC
 * Callees: none
 */
/*
 *  80160ECC: addiu       $sp, $sp, -0x20
 *  80160ED0: sw          $ra, 0x18($sp)
 *  80160ED4: lw          $v0, 0x78($a0)
 *  80160ED8: nop
 *  80160EDC: lw          $v1, 0x14($v0)
 *  80160EE0: lui         $v0, 0x8007
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_evileye_OnCollide);

/*
 * horror_splitob_OnCreate
 * VRAM 0x80160F60, ROM 0x000A4790
 * Callees: none
 */
/*
 *  80160F60: addiu       $sp, $sp, -0x28
 *  80160F64: sw          $s0, 0x20($sp)
 *  80160F68: addu        $s0, $a0, $zero
 *  80160F6C: sw          $ra, 0x24($sp)
 *  80160F70: lhu         $v0, 0x48($s0)
 *  80160F74: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_splitob_OnCreate);

/*
 * horror_splitob_OnUpdate
 * VRAM 0x80161038, ROM 0x000A4868
 * Callees: none
 */
/*
 *  80161038: addu        $a2, $a0, $zero
 *  8016103C: lui         $a1, 0x8007
 *  80161040: lw          $a1, -0x3060($a1)
 *  80161044: lw          $v1, 0x100($a2)
 *  80161048: lh          $a0, 0x4C($a1)
 *  8016104C: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_splitob_OnUpdate);

/*
 * horror_elevpan_OnCreate
 * VRAM 0x8016109C, ROM 0x000A48CC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  8016109C: lw          $v0, 0x10($a0)
 *  801610A0: lw          $v1, 0x24($a0)
 *  801610A4: ori         $v0, $v0, 0x80
 *  801610A8: sw          $v0, 0x10($a0)
 *  801610AC: lh          $v1, 0x0($v1)
 *  801610B0: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_elevpan_OnCreate);

/*
 * horror_elevpan_OnUpdate
 * VRAM 0x801610C8, ROM 0x000A48F8
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  801610C8: lui         $v0, 0x8008
 *  801610CC: lw          $v0, -0x79AC($v0)
 *  801610D0: lw          $a1, 0x24($a0)
 *  801610D4: nop
 *  801610D8: beqz        $v0, . + 4 + (0x7 << 2)
 *  801610DC: addiu       $v0, $zero, 0x1
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_elevpan_OnUpdate);

/*
 * horror_onoff_OnCollide
 * VRAM 0x80161310, ROM 0x000A4B40
 * Callees: none
 */
/*
 *  80161310: addiu       $sp, $sp, -0x18
 *  80161314: addu        $t2, $zero, $zero
 *  80161318: addu        $t6, $zero, $zero
 *  8016131C: addu        $t3, $zero, $zero
 *  80161320: sw          $ra, 0x10($sp)
 *  80161324: lw          $a3, 0x24($a0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_onoff_OnCollide);

/*
 * horror_funplat_OnCreate
 * VRAM 0x80161590, ROM 0x000A4DC0
 * Callees: COLLIDE_PointAndTerrain
 */
/*
 *  80161590: addiu       $sp, $sp, -0x28
 *  80161594: addu        $a3, $a0, $zero
 *  80161598: sw          $ra, 0x20($sp)
 *  8016159C: lw          $v0, 0x24($a3)
 *  801615A0: nop
 *  801615A4: bnez        $v0, . + 4 + (0x4 << 2)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_funplat_OnCreate);

/*
 * horror_door_OnCreate
 * VRAM 0x80161918, ROM 0x000A5148
 * Callees: MATH3D_SetUnityMatrix
 */
/*
 *  80161918: addiu       $sp, $sp, -0x70
 *  8016191C: sw          $s1, 0x5C($sp)
 *  80161920: addu        $s1, $a0, $zero
 *  80161924: sw          $ra, 0x6C($sp)
 *  80161928: sw          $s4, 0x68($sp)
 *  8016192C: sw          $s3, 0x64($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_door_OnCreate);

/*
 * func_80161F4C_A577C
 * VRAM 0x80161F4C, ROM 0x000A577C
 * Callees: MATH3D_SetUnityMatrix
 */
/*
 *  80161F4C: addiu       $sp, $sp, -0x50
 *  80161F50: sw          $s0, 0x48($sp)
 *  80161F54: addu        $s0, $a0, $zero
 *  80161F58: sw          $ra, 0x4C($sp)
 *  80161F5C: jal         func_80030B5C
 *  80161F60: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_80161F4C_A577C);

/*
 * func_80162024_A5854
 * VRAM 0x80162024, ROM 0x000A5854
 * Callees: MATH3D_SetUnityMatrix
 */
/*
 *  80162024: addiu       $sp, $sp, -0x50
 *  80162028: sw          $s0, 0x48($sp)
 *  8016202C: addu        $s0, $a0, $zero
 *  80162030: sw          $ra, 0x4C($sp)
 *  80162034: jal         func_80030B5C
 *  80162038: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_80162024_A5854);

/*
 * func_80162118_A5948
 * VRAM 0x80162118, ROM 0x000A5948
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ
 */
/*
 *  80162118: addiu       $sp, $sp, -0x50
 *  8016211C: sw          $s0, 0x48($sp)
 *  80162120: addu        $s0, $a0, $zero
 *  80162124: sw          $ra, 0x4C($sp)
 *  80162128: jal         func_80030B5C
 *  8016212C: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_80162118_A5948);

/*
 * func_80162214_A5A44
 * VRAM 0x80162214, ROM 0x000A5A44
 * Callees: MATH3D_SetUnityMatrix, RotMatrixZ, 0x8000B054
 */
/*
 *  80162214: addiu       $sp, $sp, -0x50
 *  80162218: sw          $s0, 0x48($sp)
 *  8016221C: addu        $s0, $a0, $zero
 *  80162220: sw          $ra, 0x4C($sp)
 *  80162224: jal         func_80030B5C
 *  80162228: addiu       $a0, $sp, 0x10
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_80162214_A5A44);

/*
 * func_801622E4_A5B14
 * VRAM 0x801622E4, ROM 0x000A5B14
 * Callees: 0x8000B054
 */
/*
 *  801622E4: addiu       $sp, $sp, -0x28
 *  801622E8: sw          $s0, 0x10($sp)
 *  801622EC: addu        $s0, $a1, $zero
 *  801622F0: sw          $ra, 0x20($sp)
 *  801622F4: sw          $s3, 0x1C($sp)
 *  801622F8: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_801622E4_A5B14);

/*
 * func_801623DC_A5C0C
 * VRAM 0x801623DC, ROM 0x000A5C0C
 * Callees: 0x801622E4, 0x80003234
 */
/*
 *  801623DC: addiu       $sp, $sp, -0x18
 *  801623E0: sw          $ra, 0x10($sp)
 *  801623E4: lhu         $v0, 0xCC($a3)
 *  801623E8: lw          $v1, 0x8($a0)
 *  801623EC: andi        $v0, $v0, 0x10
 *  801623F0: bnez        $v0, . + 4 + (0xD << 2)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_801623DC_A5C0C);

/*
 * func_80162438_A5C68
 * VRAM 0x80162438, ROM 0x000A5C68
 * Callees: 0x80003234
 */
/*
 *  80162438: addiu       $sp, $sp, -0x18
 *  8016243C: sw          $ra, 0x14($sp)
 *  80162440: sw          $s0, 0x10($sp)
 *  80162444: lw          $s0, 0x8($a0)
 *  80162448: lh          $v0, 0xA($a1)
 *  8016244C: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_80162438_A5C68);

/*
 * func_801624B4_A5CE4
 * VRAM 0x801624B4, ROM 0x000A5CE4
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  801624B4: lw          $v1, 0x1C($a0)
 *  801624B8: sh          $a1, 0xCA($a0)
 *  801624BC: lw          $v0, 0x4($v1)
 *  801624C0: nop
 *  801624C4: lw          $v0, 0x0($v0)
 *  801624C8: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_801624B4_A5CE4);

/*
 * func_80162524_A5D54
 * VRAM 0x80162524, ROM 0x000A5D54
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: none
 */
/*
 *  80162524: lh          $v1, 0x3B8($a0)
 *  80162528: lh          $v0, 0x0($a1)
 *  8016252C: nop
 *  80162530: bne         $v1, $v0, . + 4 + (0x10 << 2)
 *  80162534: addu        $a2, $zero, $zero
 *  80162538: lh          $v1, 0x3BA($a0)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_80162524_A5D54);

/*
 * func_8016257C_A5DAC
 * VRAM 0x8016257C, ROM 0x000A5DAC
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: 0x80162524, CAMERA_SetMode
 */
/*
 *  8016257C: lui         $v0, 0x8007
 *  80162580: lw          $v0, -0x338($v0)
 *  80162584: addiu       $sp, $sp, -0x20
 *  80162588: sw          $s1, 0x14($sp)
 *  8016258C: addu        $s1, $a0, $zero
 *  80162590: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_8016257C_A5DAC);

/*
 * horror_door_OnUpdate
 * VRAM 0x8016264C, ROM 0x000A5E7C
 * NOTE: Fragment — no prologue (compiler-split function tail or shared exit block)
 * Callees: 0x80033200, 0x800506B8
 */
/*
 *  8016264C: lui         $v0, 0x8007
 *  80162650: lw          $v0, -0x338($v0)
 *  80162654: addiu       $sp, $sp, -0xA0
 *  80162658: sw          $s2, 0x80($sp)
 *  8016265C: addu        $s2, $a0, $zero
 *  80162660: sw          $s0, 0x78($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_door_OnUpdate);

/*
 * func_80163B88_A73B8
 * VRAM 0x80163B88, ROM 0x000A73B8
 * Callees: SCRIPT_GetMultiSpline, SCRIPT_GetPosSplineDef, SCRIPT_GetSplineFrameNumber, 0x8002DAF8
 */
/*
 *  80163B88: addiu       $sp, $sp, -0x38
 *  80163B8C: sw          $s0, 0x18($sp)
 *  80163B90: addu        $s0, $a0, $zero
 *  80163B94: addiu       $a1, $sp, 0x10
 *  80163B98: sw          $ra, 0x34($sp)
 *  80163B9C: sw          $s6, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", func_80163B88_A73B8);

/*
 * horror_reza_OnCreate
 * VRAM 0x80163DE0, ROM 0x000A7610
 * Callees: SCRIPT_CountFramesInSpline, strcmp, 0x8004A7B8
 */
/*
 *  80163DE0: addiu       $sp, $sp, -0x20
 *  80163DE4: sw          $s0, 0x10($sp)
 *  80163DE8: addu        $s0, $a0, $zero
 *  80163DEC: lui         $v1, 0x10
 *  80163DF0: sw          $ra, 0x1C($sp)
 *  80163DF4: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_reza_OnCreate);

/*
 * horror_reza_OnUpdate
 * VRAM 0x80163F58, ROM 0x000A7788
 * Callees: 0x8004A820, 0x8004A7B8, strcmp, 0x80163B88
 */
/*
 *  80163F58: addiu       $sp, $sp, -0x88
 *  80163F5C: sw          $s1, 0x6C($sp)
 *  80163F60: addu        $s1, $a0, $zero
 *  80163F64: sw          $s4, 0x78($sp)
 *  80163F68: addu        $s4, $a1, $zero
 *  80163F6C: lui         $a1, 0x8016
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_reza_OnUpdate);

/*
 * horror_reza_OnCollide
 * VRAM 0x801645B0, ROM 0x000A7DE0
 * Callees: 0x8004A7B8, 0x80022714
 */
/*
 *  801645B0: addiu       $sp, $sp, -0x20
 *  801645B4: sw          $ra, 0x18($sp)
 *  801645B8: lw          $a2, 0x78($a0)
 *  801645BC: lw          $v0, 0xC($a1)
 *  801645C0: lw          $v1, 0x14($a2)
 *  801645C4: nop
 */
INCLUDE_ASM("asm/nonmatchings/HORROR", horror_reza_OnCollide);
