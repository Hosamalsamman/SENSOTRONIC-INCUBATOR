/*

 * adc.c
 *
 *  Created on: Jul 30, 2019
 *      Author: hosam
 */
#include <avr/io.h>
#include "PLATFORM_TYPES.h"


 adc_init(void)
{
	DDRA=0x00;
	ADCSRA=0x87;
	ADMUX=0xc0;
	ADMUX |=  (1 << REFS0);
}
///////////////////////////////////////////////////////
uint16 adc_read(uint8 channel)
{
	uint16 x=0;
	channel &=0x07;
	ADMUX|=channel;
	ADCSRA|=(1<<ADSC);
	while((ADCSRA&(1<<ADIF))==0);
	x=ADCL;
	x|=(ADCH<<8);
	return x;
}



