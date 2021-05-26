#include "uart_pl011.h"
#include "peripherals/uart_pl011.h" 

void kernel_main(void)
{
	uart_init();
	uart_send_string("Hello, world!\r\n");
	while (1) {
		uart_send(uart_recv());
	}
}
