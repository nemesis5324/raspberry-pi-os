#ifndef	_P_UART_PL011_H
#define	_P_UART_PL011_H

#include "peripherals/base.h"

#define UART_BASE_ADDRESS   (PBASE+0x00201000)


#define UART_DR_REG             (UART_BASE_ADDRESS+0x00)
#define UART_FR_REG             (UART_BASE_ADDRESS+0x18)
#define UART_IBRD_REG           (UART_BASE_ADDRESS+0x24)
#define UART_FBRD_REG           (UART_BASE_ADDRESS+0x28)
#define UART_LCR_H_REG          (UART_BASE_ADDRESS+0x2C)
#define UART_CR_REG             (UART_BASE_ADDRESS+0x30)

//UART baudrate calculation for PL011

#define MHz                     *1000000
#define UART_CLK                48 MHz      
#define UART_BAUD_RATE	        115200
#define UART_BAUD_DIV	        ((double)UART_CLK)/(16*UART_BAUD_RATE)            
#define UART_IBRD               (unsigned int)(UART_BAUD_DIV)
#define UART_FBRD               (unsigned int)((UART_BAUD_DIV - UART_IBRD)*64 + .5)


#endif  /*_P_UART_PL011_H */
