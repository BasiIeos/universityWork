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
void put1b(unsigned char*);
void wstr(char* s);
void wcrlf(void);
unsigned char getd(void);
unsigned char* geta(void);
unsigned char hexChar2int(unsigned char);
//void demo(void);
void (*fp)(void);

char ch;

char header[] = "CSCI 261 Simple Monitor Program (SMP)\4";
char menu[] = "Commands: (a)ssemble bbbb cc (d)ump bbbb cc (c)all bbbb (q)uit\4";
char prompt[] = "Enter command > \4";
char error[] = "Command not found\4";

char ch;
unsigned char* addr; 
unsigned char data, num;
unsigned short int i;

unsigned char _start(void) {

  __asm__("lds #_stack");	


  wstr(header);
  wcrlf();

  while (1) {
     /*ch = getc();
     if (ch == '0') {
        putc(ch);
	porta = 0x00;
     } else if (ch == '1') {
        putc(ch);
	porta = 0xff;
     } else if (ch == '2') {
        __asm__("swi");
     }*/     
         
         case 'a' :
            putc(' ');
            addr = geta();

            putc(' ');
            data = getd();

            *addr = data;

            wcrlf(); wcrlf();
            break;
         case 'd' :
            putc(' ');
            addr = geta();

            putc(' ');
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
            putc(' ');
            addr = geta();

            wcrlf(); wcrlf();

            fp = (void(*)(void)) addr;
            //fp = (void(*)(void)) demo;
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

unsigned char getd(void) {

   unsigned char c;
   unsigned char d;

   c = getc();
   d = hexChar2int(c);

   d = d << 4;
   c = getc();
   d = d + hexChar2int(c);

   return d;

}

unsigned char* geta(void) {

   unsigned char c;
   unsigned short int index;

   c = getc();
   index = hexChar2int(c);

   index = index << 4;
   c = getc();
   index = index + hexChar2int(c);

   index = index << 4;
   c = getc();
   index = index + hexChar2int(c);

   index = index << 4;
   c = getc();
   index = index + hexChar2int(c);

   /* address returned is a pointer into mem array */
   return *index;
}

unsigned char hexChar2int(unsigned char c) {

   if (c >= '0' && c <= '9') {
      return c - '0';
   } else if (c >= 'a' && c <= 'f') {
      return c -'a' + 10;
   } else {
      return 0;
   }
}

void put1b(unsigned char* chptr) {

   printf("%02x ", *chptr);

}

