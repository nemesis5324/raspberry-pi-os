#include "utils.h"
#include "peripherals/uart_pl011.h"
#include "peripherals/gpio.h"

void uart_send ( char c )
{
	while(1) {
		if(!(get32(UART_FR_REG)&0x20))         // If transmit FIFO is not full 
			break;
	}
	put32(UART_DR_REG,c);
}

char uart_recv ( void )
{
	while(1) {
		if(!(get32(UART_FR_REG)&0x10))             // Receive FIFO is not empty 
			break;
	}
	return(get32(UART_DR_REG)&0xFF);
}

void uart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init ( void )
{
	unsigned int selector;

	selector = get32(GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 4<<12;                      // set alt0 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 4<<15;                      // set alt0 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);

    put32(UART_IBRD_REG, UART_IBRD);
    put32(UART_FBRD_REG, UART_FBRD); 
    put32(UART_LCR_H_REG, 0x70);   //8 bit no parity
    put32(UART_CR_REG, 0x301);              //Enable TX, RX, UART

}
