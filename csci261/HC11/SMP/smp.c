#include <stdio.h>
#include <stdlib.h>

/*==================================================
Behaviour: csci261 Task 6 (SMP)
Developed under Unix as starting point
for the HC11 prgram.

Note 1, there is no input error checking.
Note 2, stdint.h is not an option for this project.

Author: Peter Walsh Nov 1 2018
==================================================*/

unsigned char  pwgetc(void);
void pwputc(unsigned char);
void put1b(unsigned char*);
void put2b(unsigned char*);
void wstr(char*);
void wcrlf(void);
unsigned char getd(void);
unsigned char* geta(void);
unsigned char hexChar2int(unsigned char);
void demo(void);
void (*fp)(void);

char header[] = "CSCI 261 Simple Monitor Program (SMP)";
char menu[] = "Commands: (a)ssemble bbbb cc (d)ump bbbb cc (c)all bbbb (q)uit";
char prompt[] = "Enter command > ";
char error[] = "Command not found";

unsigned char mem[100];
char ch;
unsigned char* addr; 
unsigned char data, num;
unsigned short int i;

int main() {

   system( "/bin/stty --file=/dev/stdin -icanon" );

   for (i=0; i<100; i++) {
      mem[i] = i;
   }

   wcrlf();
   wstr(header);
   wcrlf(); wcrlf();

   while(1) {
   
      wstr(menu);
      wcrlf();
      wstr(prompt);

      ch = pwgetc();
      switch(ch) {
         case 'a' :
            pwputc(' ');
	    addr = geta();

            pwputc(' ');
	    data = getd();

	    *addr = data;

            wcrlf(); wcrlf();
	    break;
         case 'd' :
            pwputc(' ');
	    addr = geta();

            pwputc(' ');
	    num = getd();

            wcrlf();
	    for (i = 0; i < num; i++) {
	       if (i % 8 == 0) {
                  wcrlf();
               }  
	       put1b(addr);
	       addr++;
	    }
            wcrlf(); wcrlf();
	    break;
         case 'c' :
            pwputc(' ');
	    addr = geta();
            
            wcrlf(); wcrlf();

	    /*fp = (void(*)(void)) addr*/;
	    fp = (void(*)(void)) demo;
	    fp();

            wcrlf(); wcrlf();
	    break;
         case 'q' :
            wcrlf(); wcrlf();
	    return(0);
	    break;
         default :
            wcrlf();
            wstr(error);
            wcrlf(); wcrlf();
      }
   }
}

/* Utility Functions */

/* Read a byte containing 2 hex characters
   and return its integer equivalent (data)*/
unsigned char getd(void) {

   unsigned char c;
   unsigned char d;

   c = pwgetc();
   d = hexChar2int(c);

   d = d << 4;
   c = pwgetc();
   d = d + hexChar2int(c);

   return d;

}

/* Read 2 bytes containing 4 hex characters
   and return its integer equivalent (address)*/
unsigned char* geta(void) {

   unsigned char c;
   unsigned short int index;

   c = pwgetc();
   index = hexChar2int(c);

   index = index << 4;
   c = pwgetc();
   index = index + hexChar2int(c);

   index = index << 4;
   c = pwgetc();
   index = index + hexChar2int(c);

   index = index << 4;
   c = pwgetc();
   index = index + hexChar2int(c);

   /* address returned is a pointer into mem array */
   return mem + index;
}

/* Convert an ascii character representing 
   a hex digit to its integer equivalent */
unsigned char hexChar2int(unsigned char c) {
   
   if (c >= '0' && c <= '9') {
      return c - '0';
   } else if (c >= 'a' && c <= 'f') {
      return c -'a' + 10;
   } else {
      return 0; 
   }
}

/* Demo function to verify the (c)all operation */
void demo(void) {
   printf("Hello World");
}

/* Function stubs to Buffalo Monitor Routines */

unsigned char  pwgetc(void) {
   return getc(stdin);
}

void pwputc(unsigned char ch) {
   putc(ch, stdout);
}

void wstr(char* s) {
   printf(s);
}

void wcrlf(void) {
   printf("\n");
}

void put1b(unsigned char* chptr) {

   printf("%02x ", *chptr);

}

void put2b(unsigned char* chptr) {

   printf("%02x ", *chptr);
   chptr++;
   printf("%02x ", *chptr);

}
