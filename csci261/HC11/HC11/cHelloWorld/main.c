/* Buffalo i/o library Starting Point */

#include "foolib.h"

char str[100] = "Hello World \4";

void _start(void) {

  wstr((char *) str);
  wcrlf();

  str[1] = 'X';
  wstr((char *) str);
  wcrlf(); 

   __asm__("swi");
}

