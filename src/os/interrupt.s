.include "macro.inc"

.set C0_SR, $12
.set SR_IE, 1

.set noreorder
.set gp=64

.section .text, "ax"


glabel __osDisableInt
    /* 5E900 8005DD00 40086000 */  mfc0       $t0, C0_SR
                                   and        $t1, $t0, ~SR_IE
    /* 5E90C 8005DD0C 40896000 */  mtc0       $t1, C0_SR
    /* 5E910 8005DD10 31020001 */  andi       $v0, $t0, SR_IE
    /* 5E914 8005DD14 00000000 */  nop
    /* 5E918 8005DD18 03E00008 */  jr         $ra
    /* 5E91C 8005DD1C 00000000 */   nop
endlabel __osDisableInt

glabel __osRestoreInt
    /* 5E920 8005DD20 40086000 */  mfc0       $t0, C0_SR
    /* 5E924 8005DD24 01044025 */  or         $t0, $t0, $a0
    /* 5E928 8005DD28 40886000 */  mtc0       $t0, C0_SR
    /* 5E92C 8005DD2C 00000000 */  nop
    /* 5E930 8005DD30 00000000 */  nop
    /* 5E934 8005DD34 03E00008 */  jr         $ra
    /* 5E938 8005DD38 00000000 */   nop
endlabel __osRestoreInt
    /* 5E93C 8005DD3C 00000000 */  nop
