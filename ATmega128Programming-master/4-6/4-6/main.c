/*
 * 4-6.c
 *
 * Created: 2025-02-24 오후 11:32:52
 * Author : Administrator
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

void UART0_init(void);
void UART0_transmit(char data);
FILE OUTPUT = FDEV_SETUP_STREAM(UART0_transmit, NULL, _FDEV_SETUP_WRITE);

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

	int n1 = 3, n2 = 5;
	
	if(n1 == n2){		// 대입연산자의 잘못된 사용
		printf("N1 is equal to N2 ??\n\r");
	}

	n1 = 3; n2 = 5;
	printf("Equal : %d\n\r", n1 == n2);
	printf("Not Equal : %d\n\r", n1 != n2);
	printf("Assignment : %d\n\r", n1 = n2);

	while (1){}
	
	return 0;
}

