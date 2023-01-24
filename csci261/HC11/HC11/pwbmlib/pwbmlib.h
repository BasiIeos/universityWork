;============================================-=
; File:
       .file "pwbmlib.h" 
; Behaviour: 
;      Library of Buffalo Monitor Routines
; Assumptions:
;      Routines only modify registers and the stack.
; Board:
;      CME11-E9-EVBU (with the PW link HACK)
; Author:
;      Peter Walsh
;============================================-=

;---------------------------------------------
; Behaviour:
;    Buffalo Monitor OUTCRLF
; Assumptions:
;    none
; Restriction:
;    subroutine may only accesses registers and the stack
; Register and Memory Usage:
;    Precondition:
;      none
;    Postcondition:
;      none
;    Destroys:
;      none
;---------------------------------------------
.global wcrlf
.global xwcrlf


;---------------------------------------------
; Behaviour:
;    Buffalo Monitor OUTSTRGO
; Assumptions:
;    none
; Restriction:
;    subroutine may only accesses registers and the stack
; Register and Memory Usage:
;    Precondition:
;      accd contains the address of the first character in the string
;    Postcondition:
;      none
;    Destroys:
;      none
;---------------------------------------------
.global wstr
.global xwstr
