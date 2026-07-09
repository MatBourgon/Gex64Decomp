.include "macro.inc"

.set noreorder
.set gp=64

.section .text, "ax"

glabel _bzero
    /* 5CD60 8005C160 00041823 */  negu       $v1, $a0
    /* 5CD64 8005C164 28A1000C */  blt        $a1, 12, bytezero
    /* 5CD6C 8005C16C 00000000 */   nop
    /* 5CD70 8005C170 30630003 */  andi       $v1, $v1, 0x3
    /* 5CD74 8005C174 10600003 */  beqz       $v1, blkzero
    /* 5CD78 8005C178 00A32823 */   subu      $a1, $a1, $v1
    /* 5CD7C 8005C17C A8800000 */  swl        $zero, 0x0($a0)
    /* 5CD80 8005C180 00832021 */  addu       $a0, $a0, $v1
blkzero:
    /* 5CD88 8005C188 00A13824 */  and        $a3, $a1, ~31
    /* 5CD8C 8005C18C 10E0000C */  beqz       $a3, wordzero
    /* 5CD90 8005C190 00A72823 */   subu      $a1, $a1, $a3
    /* 5CD94 8005C194 00E43821 */  addu       $a3, $a3, $a0
  .L8005C198:
    /* 5CD98 8005C198 AC800000 */  sw         $zero, 0x0($a0)
    /* 5CD9C 8005C19C AC800004 */  sw         $zero, 0x4($a0)
    /* 5CDA0 8005C1A0 AC800008 */  sw         $zero, 0x8($a0)
    /* 5CDA4 8005C1A4 AC80000C */  sw         $zero, 0xC($a0)
    /* 5CDA8 8005C1A8 24840020 */  addiu      $a0, $a0, 0x20
    /* 5CDAC 8005C1AC AC80FFF0 */  sw         $zero, -0x10($a0)
    /* 5CDB0 8005C1B0 AC80FFF4 */  sw         $zero, -0xC($a0)
    /* 5CDB4 8005C1B4 AC80FFF8 */  sw         $zero, -0x8($a0)
    /* 5CDB8 8005C1B8 1487FFF7 */  bne        $a0, $a3, .L8005C198
    /* 5CDBC 8005C1BC AC80FFFC */   sw        $zero, -0x4($a0)

wordzero:
    /* 5CDC4 8005C1C4 00A13824 */  and        $a3, $a1, ~3
    /* 5CDC8 8005C1C8 10E00005 */  beqz       $a3, bytezero
    /* 5CDCC 8005C1CC 00A72823 */   subu      $a1, $a1, $a3
    /* 5CDD0 8005C1D0 00E43821 */  addu       $a3, $a3, $a0
  .L8005C1D4:
    /* 5CDD4 8005C1D4 24840004 */  addiu      $a0, $a0, 0x4
    /* 5CDD8 8005C1D8 1487FFFE */  bne        $a0, $a3, .L8005C1D4
    /* 5CDDC 8005C1DC AC80FFFC */   sw        $zero, -0x4($a0)

bytezero:
    /* 5CDE0 8005C1E0 18A00005 */  blez       $a1, zerodone
    /* 5CDE4 8005C1E4 00000000 */   nop
    /* 5CDE8 8005C1E8 00A42821 */  addu       $a1, $a1, $a0
  .L8005C1EC:
    /* 5CDEC 8005C1EC 24840001 */  addiu      $a0, $a0, 0x1
    /* 5CDF0 8005C1F0 1485FFFE */  bne        $a0, $a1, .L8005C1EC
    /* 5CDF4 8005C1F4 A080FFFF */   sb        $zero, -0x1($a0)
zerodone:
    /* 5CDF8 8005C1F8 03E00008 */  jr         $ra
    /* 5CDFC 8005C1FC 00000000 */   nop
endlabel _bzero
