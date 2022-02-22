/*
 * adc.c
 *
 *  Created on: Jul 18, 2020
 *      Author: MeGa
 */

#include<avr/io.h>
#include<util/delay.h>

#include "lcd.h"
#include"seven_segment_own.h"









#define TEMP 1
#define LDR  0

void ADC_init(void);
unsigned int ADC_Get_Reading_mv( unsigned char CH);







/*
	while(1)
	{
		ADC_reading=ADC_Get_Reading_mv(2);
		display_4_Digits_7Segment(ADC_reading);

		if(ADC_reading<50)
		{
			PORTD |=(1<<PD7);
		}
		else
		{                                                 /////////////////////////////////////////////////

			PORTD &=~(1<<PD7);
		}

		//		_delay_ms(1000);

	}


*/





void ADC_init(void)
{

	ADMUX=0b01000000;
	ADCSRA=0b10000111;
}

unsigned int ADC_Get_Reading_mv(unsigned char CH)
{
	ADCSRA |=(1<<ADIF);    // set to one when the conversion complete


	ADMUX=((ADMUX&0xF8)|CH);   //  enable channel of analog to digital conversion
	ADCSRA |=(1<<ADSC);


	while(!(ADCSRA&(1<<ADIF)));

	return ADC;   ///////////////// ????????????/////////////////////////////////
}





