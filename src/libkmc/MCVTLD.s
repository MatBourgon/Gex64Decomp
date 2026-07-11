/*
    Copyright (c) 1995,1996 by Kyoto Micro Computer Co. Ltd.
    All Rights Reserved.
*/

/*
	(double) -> (long long)
*/

	.align 4
.globl __fixunsdfdi
.globl __fixdfdi
__fixdfdi:
__fixunsdfdi:
    subu    $sp, $sp, 0x8
    s.d     $f12, 0x0($sp)
    lw      $a0, 0x0($sp)
    lw      $a1, 0x4($sp)
    addu    $sp, $sp, 0x8
    addu    $v1, $a0, $zero
    srl     $a0, $a0, 20
    andi    $a0, $a0, 0x7FF
	  .set    noreorder
    sltiu   $t9, $a0, 0x3FF
    bne     $t9, $0, Zero_ret
    addiu   $a0, $a0, -0x3FF
	  .set    reorder
    sltiu   $t9, $a0, 64
    beqz    $t9, Big_ret
    addu    $a2, $v1, $zero
    addu    $a3, $a1, $zero
    addu    $v0, $v1, $zero
    li      $t9, 0xFFFFF
    and     $v0, $v0, $t9
    li      $t9, 0x100000
    or      $v0, $v0, $t9
    .set    noreorder
    sltiu   $t9, $a0, 52
    bne     $t9, $0, fixdf0
    addiu   $a0, $a0, -52
    .set    reorder
    beqz    $a0, fixdf2
    addu    $v1, $a0, $zero
    subu    $a0, $a0, 32
    subu    $a0, $0, $a0
    addu    $a1, $a3, $zero
    srlv    $a1, $a1, $a0
    addu    $a0, $v1, $zero
    sllv    $v0, $v0, $a0
    or      $v0, $v0, $a1
    sllv    $a3, $a3, $a0
    j       fixdf2
fixdf0:
    subu    $a0, $0, $a0
    addu    $v1, $a0, $zero
    sltiu   $t9, $a0, 32
    addiu   $a0, $a0, -32
    bnez    $t9, fixdf1
    addu    $a3, $v0, $zero
    xor     $v0, $v0, $v0
    srlv    $a3, $a3, $a0
    j       fixdf2
fixdf1:
    subu    $a0, $0, $a0
    addu    $a1, $v0, $zero
    sllv    $a1, $a1, $a0
    addu    $a0, $v1, $zero
    srlv    $a3, $a3, $a0
    or      $a3, $a3, $a1
    srlv    $v0, $v0, $a0
fixdf2:
    li      $t9, 0x80000000
    and     $t9, $t9, $a2
    beqz    $t9, fixdf3
    li      $v1, 0xffffffff
    xor     $a3, $a3, $v1
    xor     $v0, $v0, $v1
    addu    $a3, $a3, 0x1
    sltu    $t9, $a3, 0x1
    addu    $v0, $v0, $t9
fixdf3:
    addu    $v1, $a3, $zero
    jr      $ra
Big_ret:
    li      $v1, 0x00000000
    li      $v0, 0x80000000
    jr      $ra
Zero_ret:
    xor     $v0, $v0, $v0
    xor     $v1, $v1, $v1
    jr      $ra

/*
	(long long) -> (double)
*/

  .align 4
.globl __floatdidf
__floatdidf:
    addu    $v1, $a1, $zero
    addu    $v0, $a0, $zero
    or      $a0, $a0, $a1
    bne     $a0, $0, loc0
    subu    $sp, $sp, 0x8
    sw      $v0, 0x0($sp)
    sw      $v1, 0x4($sp)
    l.d     $f0, 0x0($sp)
    addu    $sp, $sp, 0x8
    jr      $ra
loc0:
    xor     $a2, $a2, $a2
    li      $a0, 0x80000000
    and     $t9, $a0, $v0
    beqz    $t9, fld0
    li      $a3, 0xffffffff
    xor     $v1, $v1, $a3
    xor     $v0, $v0, $a3
    addu    $v1, $v1, 0x1
    sltu    $t9, $v1, 0x1
    addu    $v0, $v0, $t9
    addu    $a2, $a0, $zero 
fld0:
    xor     $a0, $a0, $a0
    li      $t9, (0xFFE00000)
    and     $t9, $t9, $v0
    beqz    $t9, fld2
fld1:
    sll     $t9, $v0, 31
    srl     $v1, $v1, 1
    or      $v1, $v1, $t9
    srl     $v0, $v0, 1
    addiu   $a0, $a0, 0x1
    li      $t9, (0xFFE00000)
    and     $t9, $t9, $v0
    bnez    $t9, fld1
    j       fld5
fld2:
    li      $t9, (0x100000)
    and     $t9, $t9, $v0
    bne     $t9, $0, fld5
    srl     $t9, $v1, 31
    sll     $v0, $v0, 1
    or      $v0, $v0, $t9
    sll     $v1, $v1, 1
    addiu   $a0, $a0, -0x1
    j       fld2
fld5:
    li      $t9, (0xFFFFF)
    and     $v0, $v0, $t9
    or      $v0, $v0, $a2
    addu    $a0, $a0, 0x433
    sll     $a0, $a0, 20
    or      $v0, $v0, $a0
    subu    $sp, $sp, 0x8
    sw      $v0, 0x0($sp)
    sw      $v1, 0x4($sp)
    ldc1    $f0, 0x0($sp)
    addiu   $sp, $sp, 0x8
    jr      $ra
