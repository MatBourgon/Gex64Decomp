.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.set C0_COMPARE, $11

.text

glabel __osSetCompare
    mtc0       $a0, C0_COMPARE
    jr         $ra
endlabel __osSetCompare
