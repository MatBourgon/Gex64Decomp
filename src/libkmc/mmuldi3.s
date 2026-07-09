.include "macro.inc"

.set noat
.set noreorder
.set gp=64

.section .text, "ax"

glabel __muldi3
    /* 6B100 8006A500 00000000 */  nop
    /* 6B104 8006A504 00A60019 */  multu      $a1, $a2
    /* 6B108 8006A508 00004012 */  mflo       $t0
    /* 6B10C 8006A50C 00000000 */  nop
    /* 6B110 8006A510 00000000 */  nop
    /* 6B114 8006A514 00870019 */  multu      $a0, $a3
    /* 6B118 8006A518 00001812 */  mflo       $v1
    /* 6B11C 8006A51C 01034021 */  addu       $t0, $t0, $v1
    /* 6B120 8006A520 00000000 */  nop
    /* 6B124 8006A524 00860019 */  multu      $a0, $a2
    /* 6B128 8006A528 00001812 */  mflo       $v1
    /* 6B12C 8006A52C 00001010 */  mfhi       $v0
    /* 6B130 8006A530 03E00008 */  jr         $ra
    /* 6B134 8006A534 00481021 */   addu      $v0, $v0, $t0
endlabel __muldi3

glabel div64_64
    /* 6B138 8006A538 00631826 */  xor        $v1, $v1, $v1
    /* 6B13C 8006A53C 00C4C82B */  sltu       $t9, $a2, $a0
    /* 6B140 8006A540 1720000F */  bnez       $t9, div64_64_2
    /* 6B144 8006A544 00000000 */   nop
    /* 6B148 8006A548 1486000B */  bne        $a0, $a2, div64_64_1
    /* 6B14C 8006A54C 00000000 */   nop
    /* 6B150 8006A550 00E5C82B */  sltu       $t9, $a3, $a1
    /* 6B154 8006A554 1720000A */  bnez       $t9, div64_64_2
    /* 6B158 8006A558 00000000 */   nop
    /* 6B15C 8006A55C 14A70006 */  bne        $a1, $a3, div64_64_1
    /* 6B160 8006A560 00000000 */   nop

/* A == B */
    /* 6B164 8006A564 00A52826 */  xor        $a1, $a1, $a1
    /* 6B168 8006A568 00842026 */  xor        $a0, $a0, $a0
    /* 6B16C 8006A56C 24030001 */  addiu      $v1, $zero, 0x1
    /* 6B170 8006A570 03E00008 */  jr         $ra
    /* 6B174 8006A574 00421026 */   xor       $v0, $v0, $v0
div64_64_1:
    /* 6B178 8006A578 03E00008 */  jr         $ra
    /* 6B17C 8006A57C 00421026 */   xor       $v0, $v0, $v0

div64_64_2:
    /* 6B180 8006A580 24020001 */  addiu      $v0, $zero, 0x1
    /* 6B184 8006A584 3C088000 */  lui        $t0, (0x80000000 >> 16)

div64_64_3:
    /* 6B188 8006A588 00C8C824 */  and        $t9, $a2, $t0
    /* 6B18C 8006A58C 17200013 */  bnez       $t9, div64_64_7
    /* 6B190 8006A590 00000000 */   nop
    /* 6B194 8006A594 0007CFC2 */  srl        $t9, $a3, 31
    /* 6B198 8006A598 00063040 */  sll        $a2, $a2, 1
    /* 6B19C 8006A59C 00D93025 */  or         $a2, $a2, $t9
    /* 6B1A0 8006A5A0 00073840 */  sll        $a3, $a3, 1
    /* 6B1A4 8006A5A4 00C4C82B */  sltu       $t9, $a2, $a0
    /* 6B1A8 8006A5A8 17200006 */  bnez       $t9, div64_64_4
    /* 6B1AC 8006A5AC 00000000 */   nop
    /* 6B1B0 8006A5B0 14860006 */  bne        $a0, $a2, div64_64_5
    /* 6B1B4 8006A5B4 00000000 */   nop
    /* 6B1B8 8006A5B8 00E5C82B */  sltu       $t9, $a3, $a1
    /* 6B1BC 8006A5BC 13200003 */  beqz       $t9, div64_64_5
    /* 6B1C0 8006A5C0 00000000 */   nop

div64_64_4:
    /* 6B1C4 8006A5C4 0801A962 */  j          div64_64_3
    /* 6B1C8 8006A5C8 00021040 */   sll       $v0, $v0, 1

div64_64_5:
    /* 6B1CC 8006A5CC 0006CFC0 */  sll        $t9, $a2, 31
    /* 6B1D0 8006A5D0 00073842 */  srl        $a3, $a3, 1
    /* 6B1D4 8006A5D4 00F93825 */  or         $a3, $a3, $t9
    /* 6B1D8 8006A5D8 00063042 */  srl        $a2, $a2, 1

div64_64_7:
    /* 6B1DC 8006A5DC 00C4C82B */  sltu       $t9, $a2, $a0
    /* 6B1E0 8006A5E0 17200006 */  bnez       $t9, div64_64_8
    /* 6B1E4 8006A5E4 00000000 */   nop
    /* 6B1E8 8006A5E8 14860009 */  bne        $a0, $a2, div64_64_9
    /* 6B1EC 8006A5EC 00000000 */   nop
    /* 6B1F0 8006A5F0 00A7C82B */  sltu       $t9, $a1, $a3
    /* 6B1F4 8006A5F4 17200006 */  bnez       $t9, div64_64_9
    /* 6B1F8 8006A5F8 00000000 */   nop

div64_64_8:
    /* 6B1FC 8006A5FC 00A7C82B */  sltu       $t9, $a1, $a3
    /* 6B200 8006A600 00A72823 */  subu       $a1, $a1, $a3
    /* 6B204 8006A604 00862023 */  subu       $a0, $a0, $a2
    /* 6B208 8006A608 00992023 */  subu       $a0, $a0, $t9
    /* 6B20C 8006A60C 00621825 */  or         $v1, $v1, $v0

div64_64_9:
    /* 6B210 8006A610 0006CFC0 */  sll        $t9, $a2, 31
    /* 6B214 8006A614 00073842 */  srl        $a3, $a3, 1
    /* 6B218 8006A618 00F93825 */  or         $a3, $a3, $t9
    /* 6B21C 8006A61C 00063042 */  srl        $a2, $a2, 1
    /* 6B220 8006A620 00021042 */  srl        $v0, $v0, 1
    /* 6B224 8006A624 1440FFED */  bnez       $v0, div64_64_7
    /* 6B228 8006A628 00000000 */   nop

    /* 6B22C 8006A62C 03E00008 */  jr         $ra
    /* 6B230 8006A630 00421026 */   xor       $v0, $v0, $v0
endlabel div64_64

glabel div64_32
    /* 6B234 8006A634 0087001B */  divu       $zero, $a0, $a3
    /* 6B238 8006A638 14E00002 */  bnez       $a3, .L8006A644
    /* 6B23C 8006A63C 00000000 */   nop
    /* 6B240 8006A640 0007000D */  break      7
  .L8006A644:
    /* 6B244 8006A644 00005012 */  mflo       $t2
    /* 6B248 8006A648 00002010 */  mfhi       $a0
    /* 6B24C 8006A64C 01084026 */  xor        $t0, $t0, $t0
    
div64_32_0:
    /* 6B250 8006A650 1080001E */  beqz       $a0, div64_32_2
    /* 6B254 8006A654 00000000 */   nop
    /* 6B258 8006A658 00A01821 */  addu       $v1, $a1, $zero
    /* 6B25C 8006A65C 00801021 */  addu       $v0, $a0, $zero
    /* 6B260 8006A660 00E04821 */  addu       $t1, $a3, $zero

div64_32_1:
    /* 6B264 8006A664 0002CFC0 */  sll        $t9, $v0, 31
    /* 6B268 8006A668 00031842 */  srl        $v1, $v1, 1
    /* 6B26C 8006A66C 00791825 */  or         $v1, $v1, $t9
    /* 6B270 8006A670 00021042 */  srl        $v0, $v0, 1
    /* 6B274 8006A674 1440FFFB */  bnez       $v0, div64_32_1
    /* 6B278 8006A678 00094842 */   srl       $t1, $t1, 1
    /* 6B27C 8006A67C 25290001 */  addiu      $t1, $t1, 0x1

    /* 6B280 8006A680 0069001B */  divu       $zero, $v1, $t1
    /* 6B284 8006A684 15200002 */  bnez       $t1, .L8006A690
    /* 6B288 8006A688 00000000 */   nop
    /* 6B28C 8006A68C 0007000D */  break      7

  .L8006A690:
    /* 6B290 8006A690 00001812 */  mflo       $v1
    /* 6B294 8006A694 00421026 */  xor        $v0, $v0, $v0
    /* 6B298 8006A698 01034021 */  addu       $t0, $t0, $v1
    /* 6B29C 8006A69C 0103C82B */  sltu       $t9, $t0, $v1
    /* 6B2A0 8006A6A0 01425021 */  addu       $t2, $t2, $v0
    /* 6B2A4 8006A6A4 01595021 */  addu       $t2, $t2, $t9
    /* 6B2A8 8006A6A8 00000000 */  nop
    /* 6B2AC 8006A6AC 00670019 */  multu      $v1, $a3
    /* 6B2B0 8006A6B0 00001812 */  mflo       $v1
    /* 6B2B4 8006A6B4 00001010 */  mfhi       $v0
    /* 6B2B8 8006A6B8 00A3C82B */  sltu       $t9, $a1, $v1
    /* 6B2BC 8006A6BC 00A32823 */  subu       $a1, $a1, $v1
    /* 6B2C0 8006A6C0 00822023 */  subu       $a0, $a0, $v0
    /* 6B2C4 8006A6C4 0801A994 */  j          div64_32_0
    /* 6B2C8 8006A6C8 00992023 */   subu      $a0, $a0, $t9

div64_32_2:
    /* 6B2CC 8006A6CC 00A7001B */  divu       $zero, $a1, $a3
    /* 6B2D0 8006A6D0 14E00002 */  bnez       $a3, .L8006A6DC
    /* 6B2D4 8006A6D4 00000000 */   nop
    /* 6B2D8 8006A6D8 0007000D */  break      7
  .L8006A6DC:
    /* 6B2DC 8006A6DC 00001812 */  mflo       $v1
    /* 6B2E0 8006A6E0 00004810 */  mfhi       $t1
    /* 6B2E4 8006A6E4 00421026 */  xor        $v0, $v0, $v0
    /* 6B2E8 8006A6E8 00681821 */  addu       $v1, $v1, $t0
    /* 6B2EC 8006A6EC 0068C82B */  sltu       $t9, $v1, $t0
    /* 6B2F0 8006A6F0 004A1021 */  addu       $v0, $v0, $t2
    /* 6B2F4 8006A6F4 03E00008 */  jr         $ra
    /* 6B2F8 8006A6F8 00591021 */   addu      $v0, $v0, $t9
endlabel div64_32
    /* 6B2FC 8006A6FC 00000000 */  nop

glabel __divdi3
    /* 6B300 8006A700 3C088000 */  li        $t0, 0x80000000
    /* 6B304 8006A704 00801821 */  addu       $v1, $a0, $zero
    /* 6B308 8006A708 00661826 */  xor        $v1, $v1, $a2
    /* 6B30C 8006A70C 0104C824 */  and        $t9, $t0, $a0
    /* 6B310 8006A710 13200007 */  beqz       $t9, divdi1
    /* 6B314 8006A714 00000000 */   nop
    /* 6B318 8006A718 2409FFFF */  addiu      $t1, $zero, -0x1
    /* 6B31C 8006A71C 00A92826 */  xor        $a1, $a1, $t1
    /* 6B320 8006A720 00892026 */  xor        $a0, $a0, $t1
    /* 6B324 8006A724 24A50001 */  addiu      $a1, $a1, 0x1
    /* 6B328 8006A728 2CB90001 */  sltiu      $t9, $a1, 0x1
    /* 6B32C 8006A72C 00992021 */  addu       $a0, $a0, $t9

divdi1:
    /* 6B330 8006A730 0106C824 */  and        $t9, $t0, $a2
    /* 6B334 8006A734 13200007 */  beqz       $t9, divdi2
    /* 6B338 8006A738 00000000 */   nop
    /* 6B33C 8006A73C 2409FFFF */  addiu      $t1, $zero, -0x1
    /* 6B340 8006A740 00E93826 */  xor        $a3, $a3, $t1
    /* 6B344 8006A744 00C93026 */  xor        $a2, $a2, $t1
    /* 6B348 8006A748 24E70001 */  addiu      $a3, $a3, 0x1
    /* 6B34C 8006A74C 2CF90001 */  sltiu      $t9, $a3, 0x1
    /* 6B350 8006A750 00D93021 */  addu       $a2, $a2, $t9

divdi2:
    /* 6B354 8006A754 00681824 */  and        $v1, $v1, $t0
    /* 6B358 8006A758 10600045 */  beqz       $v1, div_com
    /* 6B35C 8006A75C 00000000 */   nop
    /* 6B360 8006A760 14C00006 */  bnez       $a2, divdi64
    /* 6B364 8006A764 00000000 */   nop
    /* 6B368 8006A768 03E06821 */  addu       $t5, $ra, $zero
    /* 6B36C 8006A76C 0C01A98D */  jal        div64_32
    /* 6B370 8006A770 00000000 */   nop
    /* 6B374 8006A774 0801A9E3 */  j          divdi_ret
    /* 6B378 8006A778 01A0F821 */   addu      $ra, $t5, $zero

divdi64:
    /* 6B37C 8006A77C 03E06821 */  addu       $t5, $ra, $zero
    /* 6B380 8006A780 0C01A94E */  jal        div64_64
    /* 6B384 8006A784 00000000 */   nop
    /* 6B388 8006A788 01A0F821 */  addu       $ra, $t5, $zero

divdi_ret:
    /* 6B38C 8006A78C 2407FFFF */  addiu      $a3, $zero, -0x1
    /* 6B390 8006A790 00671826 */  xor        $v1, $v1, $a3
    /* 6B394 8006A794 00471026 */  xor        $v0, $v0, $a3
    /* 6B398 8006A798 24630001 */  addiu      $v1, $v1, 0x1
    /* 6B39C 8006A79C 2C790001 */  sltiu      $t9, $v1, 0x1
    /* 6B3A0 8006A7A0 03E00008 */  jr         $ra
    /* 6B3A4 8006A7A4 00591021 */   addu      $v0, $v0, $t9
endlabel __divdi3
    /* 6B3A8 8006A7A8 00000000 */  nop
    /* 6B3AC 8006A7AC 00000000 */  nop

glabel __moddi3
    /* 6B3B0 8006A7B0 3C088000 */  lui        $t0, (0x80000000 >> 16)
    /* 6B3B4 8006A7B4 00801821 */  addu       $v1, $a0, $zero
    /* 6B3B8 8006A7B8 0104C824 */  and        $t9, $t0, $a0
    /* 6B3BC 8006A7BC 13200007 */  beqz       $t9, moddi1
    /* 6B3C0 8006A7C0 00000000 */   nop
    /* 6B3C4 8006A7C4 2409FFFF */  addiu      $t1, $zero, -0x1
    /* 6B3C8 8006A7C8 00A92826 */  xor        $a1, $a1, $t1
    /* 6B3CC 8006A7CC 00892026 */  xor        $a0, $a0, $t1
    /* 6B3D0 8006A7D0 24A50001 */  addiu      $a1, $a1, 0x1
    /* 6B3D4 8006A7D4 2CB90001 */  sltiu      $t9, $a1, 0x1
    /* 6B3D8 8006A7D8 00992021 */  addu       $a0, $a0, $t9

moddi1:
    /* 6B3DC 8006A7DC 0106C824 */  and        $t9, $t0, $a2
    /* 6B3E0 8006A7E0 13200007 */  beqz       $t9, moddi2
    /* 6B3E4 8006A7E4 00000000 */   nop
    /* 6B3E8 8006A7E8 2409FFFF */  addiu      $t1, $zero, -0x1
    /* 6B3EC 8006A7EC 00E93826 */  xor        $a3, $a3, $t1
    /* 6B3F0 8006A7F0 00C93026 */  xor        $a2, $a2, $t1
    /* 6B3F4 8006A7F4 24E70001 */  addiu      $a3, $a3, 0x1
    /* 6B3F8 8006A7F8 2CF90001 */  sltiu      $t9, $a3, 0x1
    /* 6B3FC 8006A7FC 00D93021 */  addu       $a2, $a2, $t9

moddi2:
    /* 6B400 8006A800 00681824 */  and        $v1, $v1, $t0
    /* 6B404 8006A804 10600022 */  beqz       $v1, __umoddi3
    /* 6B408 8006A808 00000000 */   nop
    /* 6B40C 8006A80C 14C00008 */  bnez       $a2, moddi64
    /* 6B410 8006A810 00000000 */   nop
    /* 6B414 8006A814 03E06821 */  addu       $t5, $ra, $zero
    /* 6B418 8006A818 0C01A98D */  jal        div64_32
    /* 6B41C 8006A81C 00000000 */   nop
    /* 6B420 8006A820 01A0F821 */  addu       $ra, $t5, $zero
    /* 6B424 8006A824 01201821 */  addu       $v1, $t1, $zero
    /* 6B428 8006A828 0801AA12 */  j          moddi_ret
    /* 6B42C 8006A82C 00421026 */   xor       $v0, $v0, $v0

moddi64:
    /* 6B430 8006A830 03E06821 */  addu       $t5, $ra, $zero
    /* 6B434 8006A834 0C01A94E */  jal        div64_64
    /* 6B438 8006A838 00000000 */   nop
    /* 6B43C 8006A83C 01A0F821 */  addu       $ra, $t5, $zero
    /* 6B440 8006A840 00A01821 */  addu       $v1, $a1, $zero
    /* 6B444 8006A844 00801021 */  addu       $v0, $a0, $zero

moddi_ret:
    /* 6B448 8006A848 2407FFFF */  addiu      $a3, $zero, -0x1
    /* 6B44C 8006A84C 00671826 */  xor        $v1, $v1, $a3
    /* 6B450 8006A850 00471026 */  xor        $v0, $v0, $a3
    /* 6B454 8006A854 24630001 */  addiu      $v1, $v1, 0x1
    /* 6B458 8006A858 2C790001 */  sltiu      $t9, $v1, 0x1
    /* 6B45C 8006A85C 03E00008 */  jr         $ra
    /* 6B460 8006A860 00591021 */   addu      $v0, $v0, $t9
endlabel __moddi3

.align 4
glabel __udivdi3
div_com:
    /* 6B470 8006A870 14C00003 */  bnez       $a2, udivdi64
    /* 6B474 8006A874 00000000 */   nop
    /* 6B478 8006A878 0801A98D */  j          div64_32
    /* 6B47C 8006A87C 00000000 */   nop
udivdi64:
    /* 6B480 8006A880 0801A94E */  j          div64_64
    /* 6B484 8006A884 00000000 */   nop
endlabel __udivdi3

.align 4
glabel __umoddi3
    /* 6B490 8006A890 14C00008 */  bnez       $a2, umoddi64
    /* 6B494 8006A894 00000000 */   nop
    /* 6B498 8006A898 03E06821 */  addu       $t5, $ra, $zero
    /* 6B49C 8006A89C 0C01A98D */  jal        div64_32
    /* 6B4A0 8006A8A0 00000000 */   nop
    /* 6B4A4 8006A8A4 01A0F821 */  addu       $ra, $t5, $zero
    /* 6B4A8 8006A8A8 01201821 */  addu       $v1, $t1, $zero
    /* 6B4AC 8006A8AC 03E00008 */  jr         $ra
    /* 6B4B0 8006A8B0 00421026 */   xor       $v0, $v0, $v0

umoddi64:
    /* 6B4B4 8006A8B4 03E06821 */  addu       $t5, $ra, $zero
    /* 6B4B8 8006A8B8 0C01A94E */  jal        div64_64
    /* 6B4BC 8006A8BC 00000000 */   nop
    /* 6B4C0 8006A8C0 01A0F821 */  addu       $ra, $t5, $zero
    /* 6B4C4 8006A8C4 00A01821 */  addu       $v1, $a1, $zero
    /* 6B4C8 8006A8C8 03E00008 */  jr         $ra
    /* 6B4CC 8006A8CC 00801021 */   addu      $v0, $a0, $zero
endlabel __umoddi3
