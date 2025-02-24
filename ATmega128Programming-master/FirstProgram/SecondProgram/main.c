/*
 * SecondProgram.c
 *
 * Created: 2025-02-24 오후 10:47:54
 * Author : Administrator
 */ 
#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRA |= 0x01;	//PA0 핀을 출력으로 설정
	
    /* Replace with your application code */
    while (1) 
    {
		PORTA |= 0x01;		//PA0 핀에 연결된 LED 켜기
		_delay_ms(500);		//0.5초 대기
		PORTA &= ~0x01;		//PA0핀에 연결된 LED 끄기
		_delay_ms(500);
    }
	
	return 0;
}

