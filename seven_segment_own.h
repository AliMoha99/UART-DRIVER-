/*
 * seven_segment_own.h
 *
 *  Created on: Jul 29, 2020
 *      Author: MeGa
 */


#ifndef SEVEN_SEGMENTS_H_
#define SEVEN_SEGMENTS_H_

#include<avr/io.h>
#include<util/delay.h>



extern void seven_segment_init(void);
extern void display_4_Digits_7Segment(unsigned int number);
extern void stop_watch();


#endif /* SEVEN_SEGMENT_OWN_H_ */
