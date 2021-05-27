#include "utils.h"
#include "mm.h"
#include "mini_uart.h"

static unsigned int processor = 0;	// global variable to sinc the processors

void kernel_main(unsigned int  proc_id)		// get processor id as 'char' from 'x0'
{

	while (processor != proc_id) {}	// wait to execute

	if (proc_id == 0) {				// only the master (processor id = 0) initialize uart
		uart_init();
	}

    if(processor==0)uart_send_string("This is core number 0 \r\n");
    if(processor==1)uart_send_string("This is core number 1 \r\n");
    if(processor==2)uart_send_string("This is core number 2 \r\n");
    if(processor==3)uart_send_string("This is core number 3 \r\n");
	processor++;					// increment 'processor' to enable the next core to execute

	if (proc_id == 3){
		while (1) {
			uart_send(uart_recv());	// only the master echos the typed character through uart
		}

	} else {
		while (1) {}				// all the other cores in loop here
	}

}
