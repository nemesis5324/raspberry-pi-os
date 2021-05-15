#include "mini_uart.h"

void kernel_main(int core)
{
	if(core==0){
		uart_init();
		uart_send_string("Hello from CPU number 0\r\n");
	}
	if(core==1){
		delay(125000000);
                uart_send_string("Hello from CPU number 1\r\n");
        }
	if(core==2){
		delay(250000000);
                uart_send_string("Hello from CPU number 2\r\n");
        }
	if(core==3){
		delay(375000000);
                uart_send_string("Hello from CPU number 3\r\n");

                while (1) {
                        uart_send(uart_recv());
                }
        }


}
