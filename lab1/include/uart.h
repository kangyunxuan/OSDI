#ifndef __UART_H__
#define __UART_H__

void uart_init();

char uart_read();

void uart_write(unsigned int data);

void uart_put(const char *s);
#endif
