;;;-----------------------------------------
;;; Start MC68HC11 gcc assembly output
;;; gcc compiler 3.3.6-m68hc1x-20060122
;;; Command:	/usr/lib/gcc-lib/m68hc11/3.3.6-m68hc1x-20060122/cc1 -quiet -D__GNUC__=3 -D__GNUC_MINOR__=3 -D__GNUC_PATCHLEVEL__=6 -Dmc68hc1x -D__mc68hc1x__ -D__mc68hc1x -D__HAVE_SHORT_INT__ -D__INT__=16 -Dmc6811 -DMC6811 -Dmc68hc11 main.c -quiet -dumpbase main.c -mshort -auxbase main -Os -fomit-frame-pointer -o main.s
;;; Compiled:	Wed Nov  7 20:29:53 2018
;;; (META)compiled by GNU C version 6.3.0 20170221.
;;;-----------------------------------------
	.file	"main.c"
	.mode mshort
	.globl	str
	.sect	.data
	.type	str, @object
	.size	str, 28
str:
	.string	"Hello World CSCI 261 in C \004"
	; extern	wstr
	; extern	wcrlf
	; extern	getc
	; extern	putc
	.sect	.text
	.globl	_start
	.type	_start,@function
_start:
; Begin inline assembler code
#APP
	lds #_stack
; End of inline assembler code
#NO_APP
	ldd	#str
	bsr	wstr
	bsr	wcrlf
.L11:
	bsr	getc
	stab	ch
	cmpb	#48
	bne	.L5
	ldab	#48
	bsr	putc
	ldx	#4096
	clr	0,x
	bra	.L11
.L5:
	cmpb	#49
	bne	.L7
	ldab	#49
	bsr	putc
	ldx	#4096
	ldab	#-1
	stab	0,x
	bra	.L11
.L7:
	cmpb	#50
	bne	.L11
; Begin inline assembler code
#APP
	swi
; End of inline assembler code
#NO_APP
	bra	.L11
	.size	_start, .-_start
	.comm	ch,1,1
	.ident	"GCC: (GNU) 3.3.6-m68hc1x-20060122"
