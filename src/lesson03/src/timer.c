#include "utils.h"
#include "printf.h"
#include "peripherals/timer.h"

const unsigned int interval = 33554432;         //~1Hz
unsigned int curVal = 0;

void timer_init ( void )
{
    unsigned int selector;
    selector = interval;
    selector |= TIMER_LOCAL_INT_EN | TIMER_LOCAL_EN;
	put32(TIMER_LOCAL_CTL, selector);
}

void handle_timer_irq( void ) 
{
    /*Do stuffs*/                                                      
    printf("Timer interrupt received\n\r");

    /*Reload the value*/
    unsigned int selector;
    selector = interval;
    selector |= TIMER_LOCAL_INT_EN | TIMER_LOCAL_EN;
    put32(TIMER_LOCAL_CTL, selector);

    /*Clear interrupt flag*/
	put32(TIMER_LOCAL_RL, TIMER_LOCAL_INT_CLR);
}
