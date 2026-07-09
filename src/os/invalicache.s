.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel osInvalICache
    /* 57C00 80057000 18A00011 */  blez       $a1, .L80057048
    /* 57C04 80057004 00000000 */   nop
    /* 57C08 80057008 240B4000 */  addiu      $t3, $zero, 0x4000
    /* 57C0C 8005700C 00AB082B */  sltu       $at, $a1, $t3
    /* 57C10 80057010 1020000F */  beqz       $at, .L80057050
    /* 57C14 80057014 00000000 */   nop
    /* 57C18 80057018 00804021 */  addu       $t0, $a0, $zero
    /* 57C1C 8005701C 00854821 */  addu       $t1, $a0, $a1
    /* 57C20 80057020 0109082B */  sltu       $at, $t0, $t1
    /* 57C24 80057024 10200008 */  beqz       $at, .L80057048
    /* 57C28 80057028 00000000 */   nop
    /* 57C2C 8005702C 2529FFE0 */  addiu      $t1, $t1, -0x20
    /* 57C30 80057030 310A001F */  andi       $t2, $t0, 0x1F
    /* 57C34 80057034 010A4023 */  subu       $t0, $t0, $t2
  .L80057038:
    /* 57C38 80057038 BD100000 */  cache      0x10, 0x0($t0) /* handwritten instruction */
    /* 57C3C 8005703C 0109082B */  sltu       $at, $t0, $t1
    /* 57C40 80057040 1420FFFD */  bnez       $at, .L80057038
    /* 57C44 80057044 25080020 */   addiu     $t0, $t0, 0x20
  .L80057048:
    /* 57C48 80057048 03E00008 */  jr         $ra
    /* 57C4C 8005704C 00000000 */   nop
  .L80057050:
    /* 57C50 80057050 3C088000 */  lui        $t0, 0x8000
    /* 57C54 80057054 010B4821 */  addu       $t1, $t0, $t3
    /* 57C58 80057058 2529FFE0 */  addiu      $t1, $t1, -0x20
  .L8005705C:
    /* 57C5C 8005705C BD000000 */  cache      0x00, 0x0($t0) /* handwritten instruction */
    /* 57C60 80057060 0109082B */  sltu       $at, $t0, $t1
    /* 57C64 80057064 1420FFFD */  bnez       $at, .L8005705C
    /* 57C68 80057068 25080020 */   addiu     $t0, $t0, (0x80000020 & 0xFFFF)
    /* 57C6C 8005706C 03E00008 */  jr         $ra
    /* 57C70 80057070 00000000 */   nop
endlabel osInvalICache
