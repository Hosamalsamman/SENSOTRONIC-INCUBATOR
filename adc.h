/*
 * adc.h
 *
 *  Created on: Jul 30, 2019
 *      Author: hosam
 */

#ifndef ADC_H_
#define ADC_H_
#include "PLATFORM_TYPES.h"

void adc_init(void);
uint16 adc_read(uint8 channel);


#endif /* ADC_H_ */
