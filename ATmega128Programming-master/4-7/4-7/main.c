/*
 * 4-7.c
 *
 * Created: 2025-02-24 오후 11:37:04
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

	int count, sum;
	
	count = 1; sum = 0;
	do{
		sum+= count;
		count++;
	}while(count <= 10);
	printf("do-while : %d\n\r", sum);
	
	count = 1; sum = 0;
	while (count <= 10){
		sum += count;
		count++;
	}
	printf("while : %d\n\r", sum);
	
	for(int count =1, sum = 0; count <= 10; count++){
		sum += count;
	}
	printf("for	: %d\n\r",sum);
	
	while(1){}
	return 0;
	
	return 0;
}



