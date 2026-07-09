.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

.set C0_SR, $12

glabel __osSetSR
    /* 5EAB0 8005DEB0 40846000 */  mtc0       $a0, C0_SR
    /* 5EAB4 8005DEB4 00000000 */  nop
    /* 5EAB8 8005DEB8 03E00008 */  jr         $ra
    /* 5EABC 8005DEBC 00000000 */   nop
endlabel __osSetSR
