.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.set C0_COUNT, $9

.text

glabel osGetCount
    mfc0       $v0, C0_COUNT
    jr         $ra
endlabel osGetCount
