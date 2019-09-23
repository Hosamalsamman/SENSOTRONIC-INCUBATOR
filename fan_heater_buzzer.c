/*

 * fan&heater&buzzer.c
 *
 *  Created on: Aug 21, 2019
 *      Author: hosam
 */

#include <avr/io.h>

fan_init()
{
	DDRC|=(1<<PC5);
}
fan_on()
{
	PORTC|=(1<<PC5);
}
fan_off()
{
	PORTC&=~(1<<PC5);
}
/////////////////////////////////////////////////////////////////////////
heater_init()
{
	DDRC|=(1<<PC6);
}
heater_on()
{
	PORTC|=(1<<PC6);
}
heater_off()
{
	PORTC&=~(1<<PC6);
}
//////////////////////////////////////////////////////////////////////////////
buzzer_init()
{
	DDRC|=(1<<PC7);
}
buzzer_on()
{
	PORTC|=(1<<PC7);
}
buzzer_off()
{
	PORTC&=~(1<<PC7);
}

