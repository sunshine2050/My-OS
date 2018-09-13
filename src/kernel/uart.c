#include <stddef.h>
#include <stdint.h>
#include "D:\Samy\Build OS\raspi-kernel\include\kernel\uart.h"

inline void mmio_write(uint32_t reg, uint32_t data)
{
	*(volatile uint32_t*)reg = data;
}

inline uint32_t mmio_read(uint32_t reg)
{
	return *(volatile uint32_t*)reg;
}

void delay(int32_t count)
{
	asm volatile("__delay_%=: subs %[count], %[count], #1; bne __delay_%=\n": "=r"(count): [count]"0"(count) : "cc");
}


void uart_init()
{
	//disable all aspects of UART Hardware in UART control register
	mmio_write(UART0_CR, 0x00000000);

	mmio_write(GPPUD, 0x00000000);
	delay(150);

	mmio_write(GPPUDCLK0, (1<<14) | (1<<15));
	delay(150);

	mmio_write(GPPUDCLK0, 0x00000000);

	//sets all flags in the interrupt clear register which clears all
	//pending interrupts from the UART hardware
	mmio_write(UART0_ICR, 0x7FF);

	//sets 115200 bits-per-second 
	mmio_write(UART0_IBRD, 1);
	mmio_write(UART0_FBRD, 40);

	//hold data in 8 item deep FIFO (1<<4)
	//data sent or received will have 8-bit long (1<<5) | (1<<6)
	mmio_write(UART0_LCRH, (1<<4) | (1<<5) | (1<<6));

	//disable all interrupts by writing 1 to the relevant bits of the IMSC 
	//Interrupt mast set clear register
	mmio_write(UART0_IMSC, (1 << 1) | (1 << 4) | (1 << 5) | (1 << 6) |
            (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10));

	//bit 0 enable UART hardware
	//bit 8,9 receive & send data
	mmio_write(UART0_CR, (1<<0) | (1<<8) | (1<<9));
}

void uart_putc(unsigned char c)
{
	while(mmio_read(UART0_FR) & (1<<5)){}
	mmio_write(UART0_DR, c);
}

unsigned char uart_getc()
{
	while(mmio_read(UART0_FR) & (1<<4)){}
	return mmio_read(UART0_DR);
}

void uart_puts(const char* str)
{
	for(size_t i = 0; str[i]!='\0'; i++)
		uart_putc((unsigned char)str[i]);
}
