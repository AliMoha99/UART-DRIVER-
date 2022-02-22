/*
 * main.c
 *
 *  Created on: Aug 9, 2020
 *      Author: MeGa
 */
#include<avr/io.h>
#include<util/delay.h>

int main()
{
	LCD_init();
		init_uart();
		seven_segment_init();
		ADC_init();
	unsigned char mode =0;
	unsigned int ADC_reading=0;
		unsigned int reading_in_mv=0;
		unsigned char temp=0;

		send_one_letter('A');
	 UART_SEND_string("ALI MOHAMED ELSIAD ");

	 _delay_ms(1000);
	mode= receive_the_letter();

	switch(mode)
	{
	case 1:
		counter_7_segment();
		 UART_SEND_string(" counting now ");
		 LCD_go_to(1,1);
		 LCD_Send_string("counting now");
		break;
	case 2:
		while(1)
		{
		        ADC_reading=ADC_Get_Reading_mv(6);
				reading_in_mv=ADC_reading*4.88;
				temp=reading_in_mv/10;
				display_4_Digits_7Segment(temp);
		 UART_SEND_string("  temperature is : ");
		 UART_SEND_string(temp+30);
		 LCD_go_to(1,1);
		 LCD_Send_string("temp is :");
		 LCD_go_to(2,5);
		 LCD_Send_string(temp+30);
		}
		break;



	}





	return 0;
}

