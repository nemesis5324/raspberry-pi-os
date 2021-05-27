#include "mm.h"

.section ".text.boot"

.globl _start
_start:
    mrs    x0, mpidr_el1 
    and    x0, x0,#0x3         //Check processor ID 
    cbz    x0, init_bss        //If CPU0 -> clean .bss section  

    b      init_stack

proc_hang:
    b      proc_hang

init_bss:
    adr    x0, bss_begin
    adr    x1, bss_end
    sub    x1, x1, x0
    bl     memzero


init_stack:                    //Create delicated stack for every core 
    mrs    x0, mpidr_el1 
    and    x0, x0,#0x3         //Check processor ID 
    mov    x1, x0              //Store processor id in x1
    mov    x2, #0x1000         //Stack offset in 4kb
    mul    x1, x1, x2          //Multiply stack offset with processor id
    add    x1, x1, #LOW_MEMORY //Offset from LOW_MEMORY (~4MB)
    mov    sp, x1 
    bl    kernel_main          //Now x0 is passed to kernel_main 
