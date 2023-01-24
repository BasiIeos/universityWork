;;;-----------------------------------------
;;; Start MC68HC11 gcc assembly output
;;; gcc compiler 3.3.6-m68hc1x-20060122
;;; Command:	/usr/lib/gcc-lib/m68hc11/3.3.6-m68hc1x-20060122/cc1 -quiet -D__GNUC__=3 -D__GNUC_MINOR__=3 -D__GNUC_PATCHLEVEL__=6 -Dmc68hc1x -D__mc68hc1x__ -D__mc68hc1x -D__HAVE_SHORT_INT__ -D__INT__=16 -Dmc6811 -DMC6811 -Dmc68hc11 main.c -quiet -dumpbase main.c -mshort -auxbase main -Os -fomit-frame-pointer -o main.s
;;; Compiled:	Fri Feb 14 16:48:01 2020
;;; (META)compiled by GNU C version 6.3.0 20170221.
;;;-----------------------------------------
	.file	"main.c"
	.mode mshort
	.globl	SYNCFLAG
	.sect	.data
	.type	SYNCFLAG, @object
	.size	SYNCFLAG, 1
SYNCFLAG:
	.byte	0
	.globl	CAR
	.type	CAR, @object
	.size	CAR, 1
CAR:
	.byte	0
	.globl	STATE
	.type	STATE, @object
	.size	STATE, 1
STATE:
	.byte	0
	.globl	STOFLAG
	.type	STOFLAG, @object
	.size	STOFLAG, 1
STOFLAG:
	.byte	0
	.globl	LTOFLAG
	.type	LTOFLAG, @object
	.size	LTOFLAG, 1
LTOFLAG:
	.byte	0
	.globl	STOCOUNT
	.type	STOCOUNT, @object
	.size	STOCOUNT, 2
STOCOUNT:
	.word	0
	.globl	LTOCOUNT
	.type	LTOCOUNT, @object
	.size	LTOCOUNT, 2
LTOCOUNT:
	.word	0
	; extern	syncInterrupt
	; extern	setLights
	; extern	newSync
	; extern	getCar
	; extern	shortTimer
	; extern	longTimer
	; extern	getState
	.sect	.text
	.globl	_start
	.type	_start,@function
_start:
; Begin inline assembler code
#APP
	sei
; End of inline assembler code
#NO_APP
	ldx	#220
	ldab	#126
	stab	0,x
	ldx	#221
	ldd	#syncInterrupt
	std	0,x
	ldx	#4130
	bset	0,x, #64
	ldx	#4131
	bset	0,x, #64
	ldx	#4110
	ldd	0,x
	addb	#20
	ldx	#4120
	stab	0,x
	bsr	setLights
; Begin inline assembler code
#APP
	cli
; End of inline assembler code
#NO_APP
.L5:
	bsr	newSync
	bsr	getCar
	bsr	shortTimer
	bsr	longTimer
	bsr	getState
	bsr	setLights
	bra	.L5
	.size	_start, .-_start
	.globl	newSync
	.type	newSync,@function
newSync:
	clr	SYNCFLAG
.L7:
	ldab	SYNCFLAG
	beq	.L7
	rts
	.size	newSync, .-newSync
	.globl	getCar
	.type	getCar,@function
getCar:
	ldx	#4096
	ldab	0,x
	anda	#0
	andb	#2
	std	*_.tmp
	beq	.L11
	ldab	#1
.L11:
	stab	CAR
	rts
	.size	getCar, .-getCar
	.globl	syncInterrupt
	.type	syncInterrupt,@function
	.interrupt	syncInterrupt
syncInterrupt:
	ldx	*_.tmp
	pshx
	ldx	*_.z
	pshx
	ldx	*_.xy
	pshx
	ldab	#1
	stab	SYNCFLAG
	ldx	#4131
	bset	0,x, #64
	ldx	#4120
	ldab	0,x
	addb	#20
	stab	0,x
	pulx
	stx	*_.xy
	pulx
	stx	*_.z
	pulx
	stx	*_.tmp
	rti
	.size	syncInterrupt, .-syncInterrupt
	.globl	shortTimer
	.type	shortTimer,@function
shortTimer:
	ldd	STOCOUNT
	cpd	#3919
	bhi	.L15
	ldx	STOCOUNT
	inx
	stx	STOCOUNT
.L15:
	ldd	STOCOUNT
	cpd	#3920
	bne	.L16
	ldab	#1
	stab	STOFLAG
	rts
.L16:
	clr	STOFLAG
	rts
	.size	shortTimer, .-shortTimer
	.globl	longTimer
	.type	longTimer,@function
longTimer:
	ldd	LTOCOUNT
	cpd	#11759
	bhi	.L19
	ldx	LTOCOUNT
	inx
	stx	LTOCOUNT
.L19:
	ldd	LTOCOUNT
	cpd	#11760
	bne	.L20
	ldab	#1
	stab	LTOFLAG
	rts
.L20:
	clr	LTOFLAG
	rts
	.size	longTimer, .-longTimer
	.globl	getState
	.type	getState,@function
getState:
	ldab	STATE
	stab	*_.tmp+1
	ldx	*_.tmp
	xgdx
	clra
	xgdx
	cpx	#64
	beq	.L32
	bgt	.L36
	cpx	#0
	beq	.L24
	cpx	#32
	beq	.L26
	rts
.L36:
	cpx	#96
	beq	.L28
	rts
.L24:
	ldab	CAR
	beq	.L22
	ldab	LTOFLAG
	beq	.L22
	ldab	#32
	stab	STATE
	stx	STOCOUNT
	stx	LTOCOUNT
	rts
.L26:
	ldab	STOFLAG
	beq	.L22
	ldab	#96
	bra	.L37
.L28:
	ldab	CAR
	bne	.L31
	ldab	STOFLAG
	bne	.L30
.L31:
	ldab	LTOFLAG
	beq	.L22
.L30:
	ldab	#64
.L37:
	stab	STATE
	clr	STOCOUNT+1
	clr	STOCOUNT
	clr	LTOCOUNT+1
	clr	LTOCOUNT
	rts
.L32:
	ldab	STOFLAG
	beq	.L22
	clr	STATE
	clr	STOCOUNT+1
	clr	STOCOUNT
	clr	LTOCOUNT+1
	clr	LTOCOUNT
.L22:
	rts
	.size	getState, .-getState
	.globl	setLights
	.type	setLights,@function
setLights:
	pshx
	ldx	#4096
	ldab	0,x
	andb	#-97
	tsy
	stab	0,y
	ldab	STATE
	orab	0,y
	stab	1,y
	stab	0,x
	pulx
	rts
	.size	setLights, .-setLights
	.ident	"GCC: (GNU) 3.3.6-m68hc1x-20060122"
