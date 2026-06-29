/*
 * level_stubs_map.c — World Map (map5)
 * Level overlay: MAP
 * ROM base: 0x0BA150, VRAM base: 0x80159720
 * Stubs: 7
 *
 * Generated from gex64decomp INCLUDE_ASM stubs.
 * Includes first instruction block and JAL callee list per stub.
 */
#include "common.h"
#include "types/Instance.h"
#include "types/GameTracker.h"

/*
 * map_lktorch_OnUpdate
 * VRAM 0x80159EC8, ROM 0x000BA8F8
 * Callees: none
 */
/*
 *  80159EC8: addiu       $sp, $sp, -0x38
 *  80159ECC: sw          $s0, 0x28($sp)
 *  80159ED0: addu        $s0, $a0, $zero
 *  80159ED4: sw          $ra, 0x34($sp)
 *  80159ED8: sw          $s2, 0x30($sp)
 *  80159EDC: sw          $s1, 0x2C($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MAP", map_lktorch_OnUpdate);

/*
 * map_speaker_OnUpdate
 * VRAM 0x8015AB2C, ROM 0x000BB55C
 * Callees: none
 */
/*
 *  8015AB2C: addiu       $sp, $sp, -0x40
 *  8015AB30: sw          $s2, 0x30($sp)
 *  8015AB34: addu        $s2, $a0, $zero
 *  8015AB38: sw          $s0, 0x28($sp)
 *  8015AB3C: addu        $s0, $a1, $zero
 *  8015AB40: sw          $s4, 0x38($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MAP", map_speaker_OnUpdate);

/*
 * map_start_OnUpdate
 * VRAM 0x8015B330, ROM 0x000BBD60
 * Callees: none
 */
/*
 *  8015B330: addiu       $sp, $sp, -0x30
 *  8015B334: sw          $s3, 0x1C($sp)
 *  8015B338: addu        $s3, $a0, $zero
 *  8015B33C: lui         $a0, 0x8007
 *  8015B340: lw          $a0, -0x3060($a0)
 *  8015B344: sw          $s2, 0x18($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MAP", map_start_OnUpdate);

/*
 * func_8015B96C_BC39C
 * VRAM 0x8015B96C, ROM 0x000BC39C
 * Callees: 0x8004A368
 */
/*
 *  8015B96C: addiu       $sp, $sp, -0xE8
 *  8015B970: sw          $s5, 0xD4($sp)
 *  8015B974: addu        $s5, $a0, $zero
 *  8015B978: sw          $ra, 0xE4($sp)
 *  8015B97C: sw          $fp, 0xE0($sp)
 *  8015B980: sw          $s7, 0xDC($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MAP", func_8015B96C_BC39C);

/*
 * map_tvmenu_OnUpdate
 * VRAM 0x8015C2D8, ROM 0x000BCD08
 * Callees: none
 */
/*
 *  8015C2D8: addiu       $sp, $sp, -0x28
 *  8015C2DC: sw          $s2, 0x18($sp)
 *  8015C2E0: addu        $s2, $a0, $zero
 *  8015C2E4: sw          $s3, 0x1C($sp)
 *  8015C2E8: addu        $s3, $a1, $zero
 *  8015C2EC: sw          $s0, 0x10($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MAP", map_tvmenu_OnUpdate);

/*
 * map_ctrlbutn_OnUpdate
 * VRAM 0x8015CDE0, ROM 0x000BD810
 * Callees: none
 */
/*
 *  8015CDE0: addiu       $sp, $sp, -0x58
 *  8015CDE4: sw          $s6, 0x48($sp)
 *  8015CDE8: addu        $s6, $a1, $zero
 *  8015CDEC: sw          $s7, 0x4C($sp)
 *  8015CDF0: addu        $s7, $zero, $zero
 *  8015CDF4: sw          $s0, 0x30($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MAP", map_ctrlbutn_OnUpdate);

/*
 * func_8015D6F0_BE120
 * VRAM 0x8015D6F0, ROM 0x000BE120
 * Callees: OBTABLE_FindObject, 0x8003A6AC, 0x8003A4E0
 */
/*
 *  8015D6F0: addiu       $sp, $sp, -0x48
 *  8015D6F4: sw          $s1, 0x24($sp)
 *  8015D6F8: addu        $s1, $a0, $zero
 *  8015D6FC: sw          $s6, 0x38($sp)
 *  8015D700: addu        $s6, $a1, $zero
 *  8015D704: sw          $ra, 0x44($sp)
 */
INCLUDE_ASM("asm/nonmatchings/MAP", func_8015D6F0_BE120);
