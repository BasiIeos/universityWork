//CSCI 461 Lab1
//Vasily Kontorer

#define JTOpcode *(volatile unsigned char *)(0x00dc)
#define JTSync *(volatile short int *)(0x00dd)

#define porta *(volatile unsigned char *)(0x1000)
#define tcnt *(volatile short int *)(0x100e)
#define toc2 *(volatile unsigned char *)(0x1018)
#define tmsk1 *(volatile unsigned char *)(0x1022)
#define tflg1 *(volatile unsigned char *)(0x1023)

#define HG 0x00 
#define HY 0x20
#define FG 0x60
#define FY 0x40
#define JUMP 0x7e
#define IC2ON 0x02
#define OC2ON 0x40
#define OC2OFF 0x40
#define Mask 0x9f
#define LTOMAX 40 * 294
#define STOMAX 40 * 98
#define SYNC 20

extern unsigned short d1 __asm__("_.d1");
extern unsigned short tmp __asm__("_.tmp");
extern unsigned short z __asm__("_.z");
extern unsigned short xy __asm__("_.xy");

void syncInterrupt(void) __attribute__((interrupt));
void newSync(void);
void getCar(void);
void shortTimer();
void longTimer();
void getState();
void setLights();

volatile unsigned char SYNCFLAG = 0;
volatile unsigned char CAR = 0;
volatile unsigned char STATE = 0;
volatile unsigned char STOFLAG = 0;
volatile unsigned char LTOFLAG = 0;
volatile unsigned short int STOCOUNT = 0;
volatile unsigned short int LTOCOUNT = 0;

void _start(void) 
{

    __asm__("sei"); // disable interrupts
    JTOpcode = JUMP;
    JTSync = (short int *) syncInterrupt;

    tmsk1 |= OC2ON;
    tflg1 |= OC2OFF;
    toc2 = tcnt + SYNC;

    setLights();

    __asm__("cli"); // enable interrupts
    
    while (1) 
    {
        newSync();
        getCar();
        shortTimer();
        longTimer();
        getState();
        setLights();
    }
}

void newSync()
{
    SYNCFLAG = 0;
    while (!SYNCFLAG);
}

void getCar()
{
    if (porta & IC2ON) 
        CAR = 1;
    else
        CAR = 0;
}

void syncInterrupt()
{
    SYNCFLAG = 1;
    tflg1 |= OC2OFF;
    toc2 += SYNC; 
}

void shortTimer()
{ 
    if (STOCOUNT < STOMAX) 
        STOCOUNT = STOCOUNT +1;
    if (STOCOUNT == STOMAX) 
        STOFLAG = 1;
    else
        STOFLAG = 0;
}


void longTimer()
{
    if (LTOCOUNT < LTOMAX)
        LTOCOUNT = LTOCOUNT +1;
    if (LTOCOUNT == LTOMAX)
        LTOFLAG = 1;
    else
        LTOFLAG = 0;
}


void getState()
{
    switch(STATE) 
    {
        case HG:
            if (CAR && LTOFLAG) 
            {
                STATE = HY;
                STOCOUNT = 0;
                LTOCOUNT = 0;
            } 
        break;
        case HY:
            if (STOFLAG) 
            {
                STATE = FG;
                STOCOUNT = 0;
                LTOCOUNT = 0;
            }
        break;
        case FG:
            if ((!CAR && STOFLAG) || LTOFLAG) 
            {
                STATE = FY;
                STOCOUNT = 0;
                LTOCOUNT = 0;
            }
        break;
        case FY:
            if (STOFLAG) 
            {
                STATE = HG;
                STOCOUNT = 0;
                LTOCOUNT = 0;
            }
        break;
    }
}


void setLights()
{
    porta = (porta & Mask) | STATE;
}

// Resources:
// CSCI 261 Lab 5
// CSCI 261 Lab 8
// CSCI 355 Lab 9
//
// Pins used on the HC11 board:
// GND (HC11) <- GND (BreadBoard)
// PA1IC2 (HC11) -> SW1 (BreadBoard)
// PA5OC3 (HC11) -> Ch2+ (DI-155)
// PA6OC2 (HC11) -> Ch1+ (DI-155)
