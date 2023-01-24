
/* Traffic Light Example Starting Point */
/* See Lab9 csci355 */
/* Peter Walsh 2017 */

#define toJumpTableOpcode *(volatile unsigned char *)(0x00d0)
#define toJumpTableISR *(volatile short int *)(0x00d1)

#define porta *(volatile unsigned char *)(0x1000)
#define tcnt *(volatile short int *)(0x100e)
#define tctl1 *(volatile unsigned char *)(0x1020)
#define tflg1 *(volatile unsigned char *)(0x1023)
#define tflg2 *(volatile unsigned char *)(0x1025)
#define tmsk2 *(volatile unsigned char *)(0x1024)

#define MAXCOUNT 200
#define CLR 0x80
#define SET 0x80

extern unsigned short d1 __asm__("_.d1");
extern unsigned short tmp __asm__("_.tmp");
extern unsigned short z __asm__("_.z");
extern unsigned short xy __asm__("_.xy");

void toISR(void) __attribute__((interrupt));
void setLights(void); 

volatile unsigned char STATE;
volatile unsigned char COUNT;
volatile unsigned char SETLIGHTS;


unsigned char _start() {

   toJumpTableOpcode = 0x7e;
   toJumpTableISR = (short int *) toISR;

   tmsk2 |= SET;
   tflg2 |= CLR;

   STATE = 0;
   COUNT = 0;
   SETLIGHTS = 1;

   __asm__("cli"); /* enable interrupts */

   while (1) {
      if (SETLIGHTS) {
         setLights();
	 SETLIGHTS = 0;
      }
   }

   return (0);
}

void setLights(void) {

   if (STATE == 0) {
      porta &= 0x9f;
   } else if (STATE == 1) {
      porta = (porta & 0x9f) | 0x20;
   } else if (STATE == 2) {
      porta = (porta & 0x9f) | 0x40;
   } else if  (STATE == 3) {
      porta |= 0x60;
   }

}

void toISR(void) {

   if (COUNT == MAXCOUNT) {	
      if (STATE == 3) {
         STATE = 0;
      } else {
         STATE = STATE + 1;
      }
      SETLIGHTS = 1;
      COUNT = 0;
   } else {
      COUNT = COUNT + 1;
   }

   tflg2 |= CLR;
}

