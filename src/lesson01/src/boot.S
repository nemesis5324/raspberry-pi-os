#include "mm.h"

.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1		
	and	x0, x0,#0xFF		// Check processor id
	mov	x3, x0			// Copy processor ID to x3	
	adr	x0, bss_begin
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero
	mov	x0, x3
	mov	sp, #LOW_MEMORY 
	bl	kernel_main
