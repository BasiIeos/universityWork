;;;-----------------------------------------
;;; Start MC68HC11 gcc assembly output
;;; gcc compiler 3.3.6-m68hc1x-20060122
;;; Command:	/usr/lib/gcc-lib/m68hc11/3.3.6-m68hc1x-20060122/cc1 -quiet -D__GNUC__=3 -D__GNUC_MINOR__=3 -D__GNUC_PATCHLEVEL__=6 -Dmc68hc1x -D__mc68hc1x__ -D__mc68hc1x -D__HAVE_SHORT_INT__ -D__INT__=16 -Dmc6811 -DMC6811 -Dmc68hc11 main.c -quiet -dumpbase main.c -mshort -auxbase main -Os -fomit-frame-pointer -o main.s
;;; Compiled:	Thu Nov 16 08:37:30 2017
;;; (META)compiled by GNU C version 6.3.0 20170221.
;;;-----------------------------------------
	.file	"main.c"
	.mode mshort
	; extern	irqCount
	.sect	.text
	.globl	_start
	.type	_start,@function
_start:
	clr	COUNT
	ldx	#238
	ldab	#126
	stab	0,x
	ldx	#239
	ldd	#irqCount
	std	0,x
; Begin inline assembler code
#APP
	cli
; End of inline assembler code
#NO_APP
.L2:
	bra	.L2
	.size	_start, .-_start
	.globl	irqCount
	.type	irqCount,@function
	.interrupt	irqCount
irqCount:
	ldx	*_.tmp
	pshx
	ldx	*_.z
	pshx
	ldx	*_.xy
	pshx
	inc	COUNT
; Begin inline assembler code
#APP
	xirqCount:
; End of inline assembler code
#NO_APP
	pulx
	stx	*_.xy
	pulx
	stx	*_.z
	pulx
	stx	*_.tmp
	rti
	.size	irqCount, .-irqCount
	.comm	COUNT,1,1
	.ident	"GCC: (GNU) 3.3.6-m68hc1x-20060122"
