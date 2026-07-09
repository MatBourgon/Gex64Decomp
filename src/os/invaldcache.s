.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel osInvalDCache
    /* 57B50 80056F50 18A00020 */  blez       $a1, .L80056FD4
    /* 57B54 80056F54 00000000 */   nop
    /* 57B58 80056F58 240B2000 */  addiu      $t3, $zero, 0x2000
    /* 57B5C 80056F5C 00AB082B */  sltu       $at, $a1, $t3
    /* 57B60 80056F60 1020001E */  beqz       $at, .L80056FDC
    /* 57B64 80056F64 00000000 */   nop
    /* 57B68 80056F68 00804021 */  addu       $t0, $a0, $zero
    /* 57B6C 80056F6C 00854821 */  addu       $t1, $a0, $a1
    /* 57B70 80056F70 0109082B */  sltu       $at, $t0, $t1
    /* 57B74 80056F74 10200017 */  beqz       $at, .L80056FD4
    /* 57B78 80056F78 00000000 */   nop
    /* 57B7C 80056F7C 2529FFF0 */  addiu      $t1, $t1, -0x10
    /* 57B80 80056F80 310A000F */  andi       $t2, $t0, 0xF
    /* 57B84 80056F84 11400007 */  beqz       $t2, .L80056FA4
    /* 57B88 80056F88 00000000 */   nop
    /* 57B8C 80056F8C 010A4023 */  subu       $t0, $t0, $t2
    /* 57B90 80056F90 BD150000 */  cache      0x15, 0x0($t0) /* handwritten instruction */
    /* 57B94 80056F94 0109082B */  sltu       $at, $t0, $t1
    /* 57B98 80056F98 1020000E */  beqz       $at, .L80056FD4
    /* 57B9C 80056F9C 00000000 */   nop
    /* 57BA0 80056FA0 25080010 */  addiu      $t0, $t0, 0x10
  .L80056FA4:
    /* 57BA4 80056FA4 312A000F */  andi       $t2, $t1, 0xF
    /* 57BA8 80056FA8 11400006 */  beqz       $t2, .L80056FC4
    /* 57BAC 80056FAC 00000000 */   nop
    /* 57BB0 80056FB0 012A4823 */  subu       $t1, $t1, $t2
    /* 57BB4 80056FB4 BD350010 */  cache      0x15, 0x10($t1) /* handwritten instruction */
    /* 57BB8 80056FB8 0128082B */  sltu       $at, $t1, $t0
    /* 57BBC 80056FBC 14200005 */  bnez       $at, .L80056FD4
    /* 57BC0 80056FC0 00000000 */   nop
  .L80056FC4:
    /* 57BC4 80056FC4 BD110000 */  cache      0x11, 0x0($t0) /* handwritten instruction */
    /* 57BC8 80056FC8 0109082B */  sltu       $at, $t0, $t1
    /* 57BCC 80056FCC 1420FFFD */  bnez       $at, .L80056FC4
    /* 57BD0 80056FD0 25080010 */   addiu     $t0, $t0, 0x10
  .L80056FD4:
    /* 57BD4 80056FD4 03E00008 */  jr         $ra
    /* 57BD8 80056FD8 00000000 */   nop
  .L80056FDC:
    /* 57BDC 80056FDC 3C088000 */  lui        $t0, 0x8000
    /* 57BE0 80056FE0 010B4821 */  addu       $t1, $t0, $t3
    /* 57BE4 80056FE4 2529FFF0 */  addiu      $t1, $t1, -0x10
  .L80056FE8:
    /* 57BE8 80056FE8 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* 57BEC 80056FEC 0109082B */  sltu       $at, $t0, $t1
    /* 57BF0 80056FF0 1420FFFD */  bnez       $at, .L80056FE8
    /* 57BF4 80056FF4 25080010 */   addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* 57BF8 80056FF8 03E00008 */  jr         $ra
    /* 57BFC 80056FFC 00000000 */   nop
endlabel osInvalDCache
