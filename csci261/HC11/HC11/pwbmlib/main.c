/* Program to demonstrate the use of pwcslib and pwbmlib */

void  wstr(char *);
void  wcrlf(void);

extern s1, s2;

void _start(void) {

  __asm__("lds #_stack");	

  wstr((char *) &s1);
  wcrlf();
  wstr((char *) &s2);
  wcrlf();

  __asm__("swi");
}

__asm__("s1: .ascii \"The string is\" \n .byte 0x4 \n");
__asm__("s2: .ascii \"Peter\" \n .byte 0x4 \n");
