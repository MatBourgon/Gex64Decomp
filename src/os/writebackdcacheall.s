.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel osWritebackDCacheAll
    /* 57D60 80057160 3C088000 */  lui        $t0, 0x8000
    /* 57D64 80057164 240A2000 */  addiu      $t2, $zero, 0x2000
    /* 57D68 80057168 010A4821 */  addu       $t1, $t0, $t2
    /* 57D6C 8005716C 2529FFF0 */  addiu      $t1, $t1, -0x10
  .L80057170:
    /* 57D70 80057170 BD010000 */  cache      0x01, 0x0($t0) /* handwritten instruction */
    /* 57D74 80057174 0109082B */  sltu       $at, $t0, $t1
    /* 57D78 80057178 1420FFFD */  bnez       $at, .L80057170
    /* 57D7C 8005717C 25080010 */   addiu     $t0, $t0, (0x80000010 & 0xFFFF)
    /* 57D80 80057180 03E00008 */  jr         $ra
    /* 57D84 80057184 00000000 */   nop
endlabel osWritebackDCacheAll
    /* 57D88 80057188 00000000 */  nop
    /* 57D8C 8005718C 00000000 */  nop
