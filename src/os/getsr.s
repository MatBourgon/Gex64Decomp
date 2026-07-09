.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.set C0_SR, $12

.text

glabel __osGetSR
    mfc0       $v0, C0_SR
    jr         $ra
endlabel __osGetSR
