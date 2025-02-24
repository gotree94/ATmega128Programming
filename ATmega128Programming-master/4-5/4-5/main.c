/*
 * 4-5.c
 *
 * Created: 2025-02-24 오후 11:27:59
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

	float r1, r2, r3, r4;
	
	r1 = 3/2;
	r2 = 3.0 / 2;
	r3 = 3/2.0;
	r4 = 3.0 / 2.0;

	printf("Result 1 : %f\n\r", r1);
	printf("Result 2 : %f\n\r", r2);
	printf("Result 3 : %f\n\r", r3);
	printf("Result 4 : %f\n\r", r4);

	while (1){}
	
	return 0;
}

