.include "pwbmlib.h"

;============================================-=
; File:
       .file "pwbmlib.h"
; Behaviour:
;      Library of Buffalo Monitor Routines.
; Assumptions:
;      Routines only modify registers and the stack.
; Board:
;      CME11-E9-EVBU (with the PW link HACK)
; Author:
;      Peter Walsh
;============================================-=

;----------------------------------------------
;            Text Section (code and data)
;----------------------------------------------
.sect .text

;======================
; Buff routine stubs
;======================

set OUTSTRGO, 0xffca
set OUTCRLF, 0xffc4

.global wstr
.global wcrlf

wcrlf:  jsr OUTCRLF
        rts

wstr:   xgdx
        jsr OUTSTRGO
        rts

.end
