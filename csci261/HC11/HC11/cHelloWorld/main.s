;;;-----------------------------------------
;;; Start MC68HC11 gcc assembly output
;;; gcc compiler 3.3.6-m68hc1x-20060122
;;; Command:	/usr/lib/gcc-lib/m68hc11/3.3.6-m68hc1x-20060122/cc1 -quiet -D__GNUC__=3 -D__GNUC_MINOR__=3 -D__GNUC_PATCHLEVEL__=6 -Dmc68hc1x -D__mc68hc1x__ -D__mc68hc1x -D__HAVE_SHORT_INT__ -D__INT__=16 -Dmc6811 -DMC6811 -Dmc68hc11 main.c -quiet -dumpbase main.c -mshort -auxbase main -Os -fomit-frame-pointer -o main.s
;;; Compiled:	Thu Nov 16 10:43:46 2017
;;; (META)compiled by GNU C version 6.3.0 20170221.
;;;-----------------------------------------
	.file	"main.c"
	.mode mshort
	.globl	str
	.sect	.data
	.type	str, @object
	.size	str, 100
str:
	.string	"Hello World \004"
	.zero	86
	; extern	wstr
	; extern	wcrlf
	.sect	.text
	.globl	_start
	.type	_start,@function
_start:
	ldd	#str
	bsr	wstr
	bsr	wcrlf
	ldab	#88
	stab	str+1
	ldd	#str
	bsr	wstr
	bsr	wcrlf
; Begin inline assembler code
#APP
	swi
; End of inline assembler code
#NO_APP
	rts
	.size	_start, .-_start
	.ident	"GCC: (GNU) 3.3.6-m68hc1x-20060122"
