#include "addr/addr_gpio.h"
#include "addr/addr_uart.h"

void uart_init(){

    *AUX_ENABLES |= 1; // enable mini UART
    *AUX_MU_CNTL_REG = 0; //disable tx/rx when config
    *AUX_MU_IER_REG = 0; //disable interrupt
    *AUX_MU_LCR_REG = 3; //set data size = 8 bit
    *AUX_MU_MCR_REG = 0; //disable auto flow control
    *AUX_MU_BAUD = 270; //baud rate = 115200
    *AUX_MU_IIR_REG = 6; 
    *AUX_MU_CNTL_REG = 3; //enable tx/rx



    unsigned int cnt;
    unsigned int r = *GPFSEL1 ;
    r &= ~((7 <<12) | (7 <<15)); //clear gpio 14, 15
    r |= ((2 << 12) | (2 << 15)); // set ALT5
    *GPFSEL1 = r;
    *GPPUD =0;
    for(cnt=150; cnt>0 ; cnt--){
        asm volatile("nop");
    }
    *GPPUDCLK0 = (1 << 14) | (1 << 15);
    for(cnt=150; cnt>0 ; cnt--){
        asm volatile("nop");
    } 
    *GPPUDCLK0 = 0;
}

char uart_read(){
    char data;
    while(!(*AUX_MU_LSR_REG & 0x01)){
        asm volatile("nop");
    }
    data = (char)(*AUX_MU_IO_REG);
    return data=='\r'?'\n':data;
    
}

void uart_write(unsigned int data){
    while(!(*AUX_MU_LSR_REG & (1<<5))){
        asm volatile("nop");
    }
    *AUX_MU_IO_REG = data;
}

void uart_put(const char *s) {
    while(*s){
        if(*s == '\n'){
            uart_write('\r');
        }
        uart_write(*s++);
    }
}

