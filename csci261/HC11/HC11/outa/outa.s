;============================================-=
; File:
       .file "outa.s" 
; Behaviour: 
;      Output 'P' to serial line
; Assumptions:
;      none
; Board:
;      CME11-E9-EVBU 
; Author/Date:
;      Peter Walsh Nov 2018
;==========================================-=

;----------------------------------------
;            Text Section (code and data)
;----------------------------------------
.global _start
.sect .text

set OUTA, 0xffb8

_start: 
          psha           ; save a
          ldaa #0x50     ; load 'P'
          jsr  OUTA
          pula
          rts         

#set up dummy frame pointer
.global _.frame
_.frame: .word


.end
