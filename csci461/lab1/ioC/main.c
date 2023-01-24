/*==============================================
   Behaviour: 
      while (1)
         reads input from serial line
         if '0' then write 0x00 to port A and echo '0' back on serial line 
         else if '1' write 0xFF to port A and echo '1' back on serial line
         else if '2' re-enter BUFFALO monitor

   Physical Setup:
      Connect EVBU to breadboard with a common ground
      Connect PA6 to a led on breadboard
   Assumptions:
      none 
   Board:
      CME11-E9-EVBU
   Author:
      Peter Walsh Oct 19 2018
==============================================*/

#define porta *(volatile unsigned char *)(0x1000)
#define ONLED 0xff
#define OFFLED 0x00

unsigned char  getc(void);
void putc(unsigned char);
void wstr(char* s);
void wcrlf(void);

unsigned char ch;
char str[] = "Hello World CSCI 261 in C \4";

void _start(void) {

  __asm__("lds #_stack");	

  wstr(str);
  wcrlf();

  while (1) {
     ch = getc();
     if (ch == '0') {
        putc(ch);
	porta = 0x00;
     } else if (ch == '1') {
        putc(ch);
	porta = 0xff;
     } else if (ch == '2') {
        __asm__("swi");
     }
   }
}
