/*
 * uart.c
 *
 *  Created on: Aug 9, 2020
 *      Author: MeGa
 */
#include<avr/io.h>
#include<util/delay.h>
#include"uart.h"



void init_uart()
{
	unsigned int rate=0;
	    UCSRB = (1 << RXEN) | (1 << TXEN);
		UCSRC = (1 << URSEL) | (3 << UCSZ0);
		rate= FOSC/16/BAUD-1;
		UBRRL=rate;
		UBRRH=(rate<<8);


}
void ready_to_send()
{
	while (!( UCSRA & (1<<UDRE))) ;
	//LCD_go_to(1,1);
//	LCD_Send_string(" uart is ready ");
	_delay_ms(3000);
	clear_lcd ();


}
void readt_to_receive()
{
	while (!(UCSRA & (1<<RXC)));
	LCD_go_to(1,1);
	LCD_Send_string(" Receiving complete ! ");
	_delay_ms(3000);
		clear_lcd ();

}
void send_one_letter(unsigned char letter)
{
	 ready_to_send();
	 UDR=letter;

}
char receive_the_letter()
{
	readt_to_receive();
	return UDR ;
}
void UART_SEND_string(char *array)
{

	while(*array !='\0')
	{

		send_one_letter(*array++);

	}

}
void counter_7_segment()
{
	unsigned int number=0;
	unsigned char digit1=0,digit2=0,digit3=0,digit4=0;
		unsigned int temp=0;
while(number<=1000)
{

		digit4=number/1000;
		temp=number%1000;

		digit3=temp/100;
		temp=temp%100;

		digit2=temp/10;

		digit1=temp%10;


		if(number>1000)
		{

			PORTC &=~(1<<PC5);
			PORTC |=(1<<PC4);
			PORTC |=(1<<PC3);
			PORTC |=(1<<PC2);
			PORTB = digit4;
			_delay_ms(5);

		}

		if(number>100)
		{

			PORTC |=(1<<PC5);
			PORTC &=~(1<<PC4);
			PORTC |=(1<<PC3);
			PORTC |=(1<<PC2);

			PORTB = digit3;
			_delay_ms(5);
		}

		if(number>10)
		{

			PORTC |=(1<<PC5);
			PORTC |=(1<<PC4);
			PORTC &=~(1<<PC3);
			PORTC |=(1<<PC2);

			PORTB = digit2;
			_delay_ms(5);
		}


		PORTC |=(1<<PC5);
		PORTC |=(1<<PC4);
		PORTC |=(1<<PC3);
		PORTC &=~(1<<PC2);
		PORTB = digit1;
		_delay_ms(5);


	}


}
