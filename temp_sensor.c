/*

 * temp_sensor.c
 *
 *  Created on: Aug 20, 2019
 *      Author: hosam
 */
#include "adc.h"
temp_sensor_init()
{
	adc_init();
}
///////////////////////////////////////
temp_sensor_read()
{
	uint16 x= (adc_read(1)*500/1023);
	return x;
}

