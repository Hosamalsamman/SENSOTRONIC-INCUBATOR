/*
 * humidity.h
 *
 *  Created on: Aug 20, 2019
 *      Author: hosam
 */

#ifndef HUMIDITY_H_
#define HUMIDITY_H_

#include "PLATFORM_TYPES.h"

void humidity_init(void);
uint16 humidity_read(void);

#endif /* HUMIDITY_H_ */
