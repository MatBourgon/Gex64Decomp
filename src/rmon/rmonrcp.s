.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel __rmonRCPrunning
    /* 69F50 80069350 00001021 */  addu       $v0, $zero, $zero
    /* 69F54 80069354 3C08A404 */  lui        $t0, %hi(D_A4040010)
    /* 69F58 80069358 8D080010 */  lw         $t0, %lo(D_A4040010)($t0)
    /* 69F5C 8006935C 31080003 */  andi       $t0, $t0, 0x3
    /* 69F60 80069360 15000002 */  bnez       $t0, .L8006936C
    /* 69F64 80069364 00000000 */   nop
    /* 69F68 80069368 34420001 */  ori        $v0, $v0, 0x1
  .L8006936C:
    /* 69F6C 8006936C 03E00008 */  jr         $ra
    /* 69F70 80069370 00000000 */   nop
endlabel __rmonRCPrunning

glabel __rmonIdleRCP
    /* 69F74 80069374 3C04A404 */  lui        $a0, (0xA4040018 >> 16)
    /* 69F78 80069378 34840018 */  ori        $a0, $a0, (0xA4040018 & 0xFFFF)
  .L8006937C:
    /* 69F7C 8006937C 8C820000 */  lw         $v0, 0x0($a0)
    /* 69F80 80069380 1440FFFE */  bnez       $v0, .L8006937C
    /* 69F84 80069384 00000000 */   nop
    /* 69F88 80069388 24050082 */  addiu      $a1, $zero, 0x82
    /* 69F8C 8006938C 3C04A404 */  lui        $a0, (0xA4040010 >> 16)
    /* 69F90 80069390 34840010 */  ori        $a0, $a0, (0xA4040010 & 0xFFFF)
    /* 69F94 80069394 AC850000 */  sw         $a1, 0x0($a0)
  .L80069398:
    /* 69F98 80069398 3C04A404 */  lui        $a0, (0xA4040010 >> 16)
    /* 69F9C 8006939C 34840010 */  ori        $a0, $a0, (0xA4040010 & 0xFFFF)
    /* 69FA0 800693A0 8C820000 */  lw         $v0, 0x0($a0)
    /* 69FA4 800693A4 30420003 */  andi       $v0, $v0, 0x3
    /* 69FA8 800693A8 1040FFFB */  beqz       $v0, .L80069398
    /* 69FAC 800693AC 00000000 */   nop
    /* 69FB0 800693B0 03E00008 */  jr         $ra
    /* 69FB4 800693B4 00000000 */   nop
endlabel __rmonIdleRCP

glabel __rmonStepRCP
    /* 69FB8 800693B8 3C04A404 */  lui        $a0, (0xA4040010 >> 16)
    /* 69FBC 800693BC 34840010 */  ori        $a0, $a0, (0xA4040010 & 0xFFFF)
    /* 69FC0 800693C0 240500C5 */  addiu      $a1, $zero, 0xC5
    /* 69FC4 800693C4 1000FFF4 */  b          .L80069398
    /* 69FC8 800693C8 AC850000 */   sw        $a1, 0x0($a0)
endlabel __rmonStepRCP

glabel __rmonRunRCP
    /* 69FCC 800693CC 3C04A430 */  lui        $a0, (0xA430000C >> 16)
    /* 69FD0 800693D0 3484000C */  ori        $a0, $a0, (0xA430000C & 0xFFFF)
    /* 69FD4 800693D4 24050002 */  addiu      $a1, $zero, 0x2
    /* 69FD8 800693D8 AC850000 */  sw         $a1, 0x0($a0)
    /* 69FDC 800693DC 3C04A404 */  lui        $a0, (0xA4040010 >> 16)
    /* 69FE0 800693E0 34840010 */  ori        $a0, $a0, (0xA4040010 & 0xFFFF)
    /* 69FE4 800693E4 24050125 */  addiu      $a1, $zero, 0x125
    /* 69FE8 800693E8 03E00008 */  jr         $ra
    /* 69FEC 800693EC AC850000 */   sw        $a1, 0x0($a0)
endlabel __rmonRunRCP
