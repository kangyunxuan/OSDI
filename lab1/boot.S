.section ".text.boot"
.global _start


_start:
    ldr x1, = _start
    mov sp, x1
    
    ldr x0, =_bss_start
    ldr x1, =_bss_end

clear_bss:
    cmp x0, x1
    b.ge run_main
    str xzr, [x0], #8
    b clear_bss

run_main:
   bl main

hang: 
    wfe
    b hang
