#include "mini_uart.h"

void kernel_main(int core)
{
	uart_init();
	if(core==0){
		uart_send_string("Hello from CPU number 0\r\n");

		while (1) {
			uart_send(uart_recv());
		}
	}
	if(core==1){
                uart_send_string("Hello from CPU number 1\r\n");

                while (1) {
                        uart_send(uart_recv());
                }
        }
	if(core==2){
                uart_send_string("Hello from CPU number 2\r\n");

                while (1) {
                        uart_send(uart_recv());
                }
        }
	if(core==3){
                uart_send_string("Hello from CPU number 3\r\n");

                while (1) {
                        uart_send(uart_recv());
                }
        }


}
