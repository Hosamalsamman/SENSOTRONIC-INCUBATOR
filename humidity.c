/*

 * humidity.c
 *
 *  Created on: Aug 20, 2019
 *      Author: hosam
 */
#include "adc.h"


humidity_init()
{
	adc_init();
}
////////////////////////////////////////////
humidity_read()
{
	return (adc_read(2));
}

