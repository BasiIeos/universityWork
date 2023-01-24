;;;-----------------------------------------
;;; Start MC68HC11 gcc assembly output
;;; gcc compiler 3.3.6-m68hc1x-20060122
;;; Command:	/usr/lib/gcc-lib/m68hc11/3.3.6-m68hc1x-20060122/cc1 -quiet -D__GNUC__=3 -D__GNUC_MINOR__=3 -D__GNUC_PATCHLEVEL__=6 -Dmc68hc1x -D__mc68hc1x__ -D__mc68hc1x -D__HAVE_SHORT_INT__ -D__INT__=16 -Dmc6811 -DMC6811 -Dmc68hc11 main.c -quiet -dumpbase main.c -mshort -auxbase main -Os -fomit-frame-pointer -o main.s
;;; Compiled:	Fri Dec 14 17:13:05 2018
;;; (META)compiled by GNU C version 6.3.0 20170221.
;;;-----------------------------------------
	.file	"main.c"
	.mode mshort
	; extern	foo
	; extern	increment
	.sect	.text
	.globl	main
	.type	main,@function
main:
	pshx
	ldx	#5
	pshx
	ldd	#4
	bsr	foo
	ldd	#23
	tsx
	std	2,x
	tsx
	xgdx
	addd	#2
	bsr	increment
	ins
	ins
	clra
	clrb
	pulx
	rts
	.size	main, .-main
	.globl	foo
	.type	foo,@function
foo:
	tsx
	addd	2,x
	addd	#3
	rts
	.size	foo, .-foo
	.globl	increment
	.type	increment,@function
increment:
	xgdx
	inc	0,x
	rts
	.size	increment, .-increment
	.comm	c,1,1
	.ident	"GCC: (GNU) 3.3.6-m68hc1x-20060122"
