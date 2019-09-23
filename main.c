/*

 * main.c
 *
 *  Created on: Aug 20, 2019
 *      Author: hosam
 */
#include<avr/io.h>
#include "temp_sensor.h"
#include "humidity.h"
#include "sev_seg_init.h"
#include "fan_heater_buzzer.h"
#include "PLATFORM_TYPES.h"
#include "timer2.h"
#include "switches.h"
////////////////////////////////////////////////////////////////////////////
volatile uint8 default_temp=37;
volatile uint8 default_humidity=50;
volatile uint16 actual_temp=0;
volatile uint16 actual_humidity=0;
extern volatile uint8 set_temp_flag;
extern volatile uint8 set_humidity_flag;
////////////////////////////////////////////////////////////////////////////////
int main(void)
{
	volatile uint8 increace_temp_flag=0;
	volatile uint8 decrease_temp_flag=0;
	volatile uint8 increase_humidity_flag=0;
	volatile uint8 decrease_humidity_flag=0;
	volatile uint8 increase_temp_counter=0;
	volatile uint8 decrease_temp_counter=0;
	volatile uint8 increase_humidity_counter=0;
	volatile uint8 decrease_humidity_counter=0;
/////////////////////////////////////////////////////////////////////////
	temp_sensor_init();
	actual_temp=temp_sensor_read();
	humidity_init();
	actual_humidity=humidity_read();
	seven_seg_init();
	fan_init();
	heater_init();
	buzzer_init();
	Timer_Start_Count();
	switches_init();
/////////////////////////////////////////////////////////////////////////
	while(1)
	{
		dis_const_temp(default_temp);
		dis_const_hum(default_humidity);
		dis_actual_temp(actual_temp);
		dis_actual_hum(actual_humidity);
/////////////////////////////////////////////////////////////////////////////////////////////////
		if(set_temp_flag==1)
		{
			if((PIND&(1<<PD0))==1)
			{
				increase_temp_counter++;
				if(increase_temp_counter==3)
				{
					if((PIND&(1<<PD0))==1)
						{
						if(increace_temp_flag==0)
							{
								increace_temp_flag=1;
								default_temp++;
								if(default_temp>99)
									{
										default_temp=99;
									}
							}

						increase_temp_counter=0;
						}
					else
						{
							increace_temp_flag=0;
						}
				}
			}
		}
///////////////////////////////////////////////////////////////////
		if(set_temp_flag==1)
				{
					if((PIND&(1<<PD1))==1)
					{
						decrease_temp_counter++;
						if(decrease_temp_counter==3)
						{
							if((PIND&(1<<PD1))==1)
								{
								if(decrease_temp_flag==0)
									{
										decrease_temp_flag=1;
										if(default_temp==0)
											{
												default_temp++;
											}
										default_temp--;
									}

								decrease_temp_counter=0;
								}
							else
								{
									decrease_temp_flag=0;
								}
						}
					}
				}
///////////////////////////////////////////////////////////////////////////////////////////////////
		if(set_humidity_flag==1)
				{
					if((PIND&(1<<PD4))==1)
					{
						increase_humidity_counter++;
						if(increase_humidity_counter==3)
						{
							if((PIND&(1<<PD0))==1)
								{
								if(increase_humidity_flag==0)
									{
										increase_humidity_flag=1;
										default_humidity++;
										if(default_humidity>99)
											{
												default_humidity=99;
											}
									}

								increase_humidity_counter=0;
								}
							else
								{
									increase_humidity_flag=0;
								}
						}
					}
				}
///////////////////////////////////////////////////////////////////////
		if(set_humidity_flag==1)
						{
							if((PIND&(1<<PD5))==1)
							{
								decrease_humidity_counter++;
								if(decrease_humidity_counter==3)
								{
									if((PIND&(1<<PD5))==1)
										{
										if(decrease_humidity_flag==0)
											{
												decrease_humidity_flag=1;
												if(default_humidity==0)
													{
														default_humidity++;
													}
												default_humidity--;
											}

										decrease_humidity_counter=0;
										}
									else
										{
											decrease_humidity_flag=0;
										}
								}
							}
						}
/////////////////////////////////////////////////////////////////////////////////////////////////
		if(actual_temp>(default_temp+1))
		{
			buzzer_on();
		}
		else if(actual_temp<(default_temp-1))
		{
			heater_on();
		}
		else
		{
			buzzer_off();
			heater_off();
		}

		if(actual_humidity>(default_humidity+1))
		{
			fan_on();
		}
		else
		{
			fan_off();
		}
	}
	return 0;
}

