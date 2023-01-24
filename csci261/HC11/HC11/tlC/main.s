;;;-----------------------------------------
;;; Start MC68HC11 gcc assembly output
;;; gcc compiler 3.3.6-m68hc1x-20060122
;;; Command:	/usr/lib/gcc-lib/m68hc11/3.3.6-m68hc1x-20060122/cc1 -quiet -D__GNUC__=3 -D__GNUC_MINOR__=3 -D__GNUC_PATCHLEVEL__=6 -Dmc68hc1x -D__mc68hc1x__ -D__mc68hc1x -D__HAVE_SHORT_INT__ -D__INT__=16 -Dmc6811 -DMC6811 -Dmc68hc11 main.c -quiet -dumpbase main.c -mshort -auxbase main -Os -fomit-frame-pointer -o main.s
;;; Compiled:	Thu Nov 16 10:22:14 2017
;;; (META)compiled by GNU C version 6.3.0 20170221.
;;;-----------------------------------------
	.file	"main.c"
	.mode mshort
	; extern	toISR
	; extern	setLights
	.sect	.text
	.globl	_start
	.type	_start,@function
_start:
	ldx	#208
	ldab	#126
	stab	0,x
	ldx	#209
	ldd	#toISR
	std	0,x
	ldx	#4132
	bset	0,x, #-128
	ldx	#4133
	bset	0,x, #-128
	clr	STATE
	clr	COUNT
	ldab	#1
	stab	SETLIGHTS
; Begin inline assembler code
#APP
	cli
; End of inline assembler code
#NO_APP
.L7:
	ldab	SETLIGHTS
	beq	.L7
	bsr	setLights
	clr	SETLIGHTS
	bra	.L7
	.size	_start, .-_start
	.globl	setLights
	.type	setLights,@function
setLights:
	ldab	STATE
	bne	.L9
	ldx	#4096
	bclr	0,x, #96
	rts
.L9:
	ldab	STATE
	cmpb	#1
	bne	.L11
	ldx	#4096
	ldab	0,x
	andb	#-97
	orab	#32
	bra	.L16
.L11:
	ldab	STATE
	cmpb	#2
	bne	.L13
	ldx	#4096
	ldab	0,x
	andb	#-97
	orab	#64
.L16:
	stab	0,x
	rts
.L13:
	ldab	STATE
	cmpb	#3
	bne	.L8
	ldx	#4096
	bset	0,x, #96
.L8:
	rts
	.size	setLights, .-setLights
	.globl	toISR
	.type	toISR,@function
	.interrupt	toISR
toISR:
	ldx	*_.tmp
	pshx
	ldx	*_.z
	pshx
	ldx	*_.xy
	pshx
	ldab	COUNT
	cmpb	#-56
	bne	.L18
	ldab	STATE
	cmpb	#3
	bne	.L19
	clr	STATE
	bra	.L20
.L19:
	ldab	STATE
	incb
	stab	STATE
.L20:
	ldab	#1
	stab	SETLIGHTS
	clr	COUNT
	bra	.L21
.L18:
	ldab	COUNT
	incb
	stab	COUNT
.L21:
	ldx	#4133
	bset	0,x, #-128
	pulx
	stx	*_.xy
	pulx
	stx	*_.z
	pulx
	stx	*_.tmp
	rti
	.size	toISR, .-toISR
	.comm	STATE,1,1
	.comm	COUNT,1,1
	.comm	SETLIGHTS,1,1
	.ident	"GCC: (GNU) 3.3.6-m68hc1x-20060122"
