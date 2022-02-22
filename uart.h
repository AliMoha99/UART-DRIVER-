/*
 * uart.h
 *
 *  Created on: Aug 9, 2020
 *      Author: MeGa
 */

#ifndef UART_H_
#define UART_H_
#define FOSC 8000000
#define BAUD 9600

extern void init_uart();
extern void send_one_letter(unsigned char letter);
extern char receive_the_letter();
extern void ready_to_send();
extern void readt_to_receive();
extern void counter_7_segment(void);



#endif /* UART_H_ */
