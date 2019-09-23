/*

 * switches.c
 *
 *  Created on: Aug 23, 2019
 *      Author: hosam
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "PLATFORM_TYPES.h"


volatile uint8 set_temp_flag=0;
volatile uint8 set_humidity_flag=0;


switches_init()
{
	DDRD=0x00;
	PORTD=0xFF;
	GICR|=(1<<INT0)|(1<<INT1);
	MCUCR|=(1<<ISC01)|(1<<ISC11);
	sei();
}

///////////////////////////////////////////////////////

ISR(INT0_vect)
{
	if(set_temp_flag==0)
	{
		set_temp_flag=1;
	}
	else if(set_temp_flag==1)
	{
		set_temp_flag=0;
	}
}

/////////////////////////////////////////////////////////

ISR(INT1_vect)
{
	if(set_humidity_flag==0)
	{
		set_humidity_flag=1;
	}
	else if(set_humidity_flag==1)
	{
		set_humidity_flag=0;
	}
}
