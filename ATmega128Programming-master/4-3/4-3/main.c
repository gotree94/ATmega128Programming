/*
 * 4-3.c
 *
 * Created: 2025-02-24 오후 11:08:50
 * Author : Administrator
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void UART0_init(void);
void UART0_transmit(char data);
FILE OUTPUT \
	= FDEV_SETUP_STREAM(UART0_transmit, NULL, _FDEV_SETUP_WRITE);
	
void UART0_init(void)
{
	UBRR0H = 0x00;		// 9600 보레이트
	UBRR0L = 207;
	
	UCSR0A |= _BV(U2X0);		// 2배속
	UCSR0C |= 0x06;
	
	UCSR0B |= _BV(RXEN0);
	UCSR0B |= _BV(TXEN0);
}	

void UART0_transmit(char data)
{
	while(!(UCSR0A & (1<< UDRE0)) );
	UDR0 = data;
	
}

int main(void)
{
    UART0_init();
	stdout = &OUTPUT;

	printf("** Size of Data Types\n\r");
	printf("%d\n\r", sizeof(char));
	printf("%d\n\r", sizeof(int));
	printf("%d\n\r", sizeof(short));
	printf("%d\n\r", sizeof(long));
	printf("%d\n\r", sizeof(float));
	printf("%d\n\r", sizeof(double));

    while (1) 
    {
    }
	
	return 0;
}



