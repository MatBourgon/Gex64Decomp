.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel osWritebackDCache
    /* 57CE0 800570E0 18A00011 */  blez       $a1, .L80057128
    /* 57CE4 800570E4 00000000 */   nop
    /* 57CE8 800570E8 240B2000 */  addiu      $t3, $zero, 0x2000
    /* 57CEC 800570EC 00AB082B */  sltu       $at, $a1, $t3
    /* 57CF0 800570F0 1020000F */  beqz       $at, .L80057130
    /* 57CF4 800570F4 00000000 */   nop
    /* 57CF8 800570F8 00804021 */  addu       $t0, $a0, $zero
    /* 57CFC 800570FC 00854821 */  addu       $t1, $a0, $a1
    /* 57D00 80057100 0109082B */  sltu       $at, $t0, $t1
    /* 57D04 80057104 10200008 */  beqz       $at, .L80057128
    /* 57D08 80057108 00000000 */   nop
    /* 57D0C 8005710C 2529FFF0 */  addiu      $t1, $t1, -0x10
    /* 57D10 80057110 310A000F */  andi       $t2, $t0, 0xF
    /* 57D14 80057114 010A4023 */  subu       $t0, $t0, $t2
  .L80057118:
    /* 57D18 80057118 BD190000 */  cache      0x19, 0x0($t0) /* handwritten instruction */
    /* 57D1C 8005711C 0109082B */  sltu       $at, $t0, $t1
    /* 57D20 80057120 1420FFFD */  bnez       $at, .L80057118
    /* 57D24 80057124 25080010 */   addiu     $t0, $t0, 0x10
  .L80057128:
    /* 57D28 80057128 03E00008 */  jr         $ra
    /* 57D2C 8005712C 00000000 */   nop
  .L80057130:
    /* 57D30 80057130 3C088000 */  lui        $t0, 0x8000
    /* 57D34 80057134 010B4821 */  addu       $t1, $t0, $t3
    /* 57D38 80057138 2529FFF0 */  addiu      $t1, $t1, -0x10
  .L8005713C:
    /* 57D3C 8005713C BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* 57D40 80057140 0109082B */  sltu       $at, $t0, $t1
    /* 57D44 80057144 1420FFFD */  bnez       $at, .L8005713C
    /* 57D48 80057148 25080010 */   addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* 57D4C 8005714C 03E00008 */  jr         $ra
    /* 57D50 80057150 00000000 */   nop
endlabel osWritebackDCache
    /* 57D54 80057154 00000000 */  nop
    /* 57D58 80057158 00000000 */  nop
    /* 57D5C 8005715C 00000000 */  nop
