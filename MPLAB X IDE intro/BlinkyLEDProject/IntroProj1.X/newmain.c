#include <xc.h>

#pragma config WDTE = OFF       // WDT operating mode (WDT Disabled; SWDTEN is ignored)

// defines
#define _XTAL_FREQ 2000000

#define OFF 0
#define ON  1

// forward decs
void delayOneSecond(void);
void initLED(void);
void setLED(int state);

// vars
int numBlinks = 0;

//------------------------------------------------------------------------------
// main
void main(void) 
    {
    initLED();
    while (1)
        {
        setLED(ON);
        delayOneSecond();
        setLED(OFF);
        delayOneSecond();
        numBlinks++;
        }
    return;
    }

//------------------------------------------------------------------------------
// init
void initLED(void)
    {
    ANSELF &= 0xF7;     // RF3 -> digital
    TRISF  &= 0xF7;     // RF3 -> output;
    }

//------------------------------------------------------------------------------
// setLED
void setLED(int state)
    {
    if (state == ON)
        LATF &= 0xF7;
    else
        LATF |= 0x08;
    }

//------------------------------------------------------------------------------
// delayOneSecond
void delayOneSecond(void)
    {
    __delay_ms(1000);
    }
