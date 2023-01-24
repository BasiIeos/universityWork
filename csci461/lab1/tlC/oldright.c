/*
CSCI 461 Lab 1 - Traffic Light Controller
Liam Stokes
576853659

Rev 1.0

*/

#define toJumpTableOpcode *(volatile unsigned char *)(0x00dc)
#define toJumpTableSYNC *(volatile short int *)(0x00dd)

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
#define MASK 0x9f
#define LTOMAX 40 * 300
#define STOMAX 20 * 200
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

    toJumpTableOpcode = JUMP;
    toJumpTableSYNC = (short int *) syncInterrupt;

    tmsk1 |= OC2ON;
    tflg1 |= OC2OFF;
    toc2 = tcnt + SYNC;

    setLights();

    __asm__("cli");
    
    while (1) 
    {
        newSync();
        getCar();
        shortTimer();
        longTimer();
        getState();
        setLights();
    }
    return(0);
}

void newSync()
{
    SYNCFLAG = 0;
    while (!SYNCFLAG){};
}


void getCar()
{
    if (porta & IC2ON) 
    { 
        CAR = 1;
    }
    else
    {
        CAR = 0;
    } 
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
    {
        STOCOUNT = STOCOUNT +1;
    }
    

    if (STOCOUNT == STOMAX) 
    {
        STOFLAG = 1;
    } 
    else 
    {
        STOFLAG = 0;
    }
}


void longTimer(){

    if (LTOCOUNT < LTOMAX) 
    {
        LTOCOUNT = LTOCOUNT +1;
    }
   
    if (LTOCOUNT == LTOMAX) 
    {
        LTOFLAG = 1;
    } 
    else 
    {
        LTOFLAG = 0;
    }
}


void getState(){
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


void setLights(){
    porta = (porta & MASK) | STATE;
}
