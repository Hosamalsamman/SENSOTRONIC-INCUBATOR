/*
 * temp_sensor.h
 *
 *  Created on: Aug 20, 2019
 *      Author: hosam
 */

#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "PLATFORM_TYPES.h"

void temp_sensor_init(void);
uint8 temp_sensor_read(void);

#endif /* TEMP_SENSOR_H_ */
