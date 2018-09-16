#include <common/stdio.h>
#include <common/stdlib.h>
#include <kernel/uart.h>

char getc(void){
	return uart_getc();
}
void putc(char c){
	uart_putc(c);
}
void puts(const char* s){
	int i;
	for(i=0; s[i]!='\0';i++)
		putc(s[i]);
}