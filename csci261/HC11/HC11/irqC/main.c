
/* C version of irqA */

#define irqJumpTableOpcode *(volatile unsigned char *)(0x00ee)
#define irqJumpTableISR *(volatile short int *)(0x00ef)

extern unsigned short d1 __asm__("_.d1");
extern unsigned short tmp __asm__("_.tmp");
extern unsigned short z __asm__("_.z");
extern unsigned short xy __asm__("_.xy");

void irqCount(void) __attribute__((interrupt));

unsigned char COUNT;

unsigned char _start() {
   COUNT = 0;
   irqJumpTableOpcode = 0x7e;
   irqJumpTableISR = (short int *) irqCount;

   __asm__("cli"); /* enable interrupts */
   while (1);
   return (0);
}

void irqCount(void) {
   COUNT=COUNT+1;
   __asm__("xirqCount:"); /* insert an exit label for testing purposes */
}
