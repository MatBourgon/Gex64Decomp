.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.set C0_CAUSE, $13

.text

glabel __osGetCause
    mfc0       $v0, C0_CAUSE
    jr         $ra
endlabel __osGetCause
