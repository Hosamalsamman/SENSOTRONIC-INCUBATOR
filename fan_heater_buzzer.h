/*
 * fan&heater&buzzer.h
 *
 *  Created on: Aug 21, 2019
 *      Author: hosam
 */

#ifndef FAN_HEATER_BUZZER_H_
#define FAN_HEATER_BUZZER_H_

void fan_init(void);
void fan_on(void);
void fan_off(void);
//////////////////////////////////////////////////////////////
void heater_init(void);
void heater_on(void);
void heater_off(void);
//////////////////////////////////////////////////////////////
void buzzer_init(void);
void buzzer_on(void);
void buzzer_off(void);

#endif /* FAN_HEATER_BUZZER_H_ */
