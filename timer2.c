/*

 * timer2.c

 *
 *  Created on: Aug 20, 2019
 *      Author: hosam
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "PLATFORM_TYPES.h"
#include "temp_sensor.h"
#include "humidity.h"

extern volatile uint16 actual_temp;
extern volatile uint16 actual_humidity;

void Timer_Start_Count(void)
{
	TCNT2=0;
	TCCR2=0x07;		//normal mode,1024 prescaler.
	TIMSK=(1<<TOIE2);
	sei();
}

ISR(TIMER2_OVF_vect)
{
	uint16 overflows=0;
	overflows++;
	if(overflows>=900)                   //30 seconds
	{
		overflows=0;
		actual_temp=temp_sensor_read();
		actual_humidity=humidity_read();
	}

}




