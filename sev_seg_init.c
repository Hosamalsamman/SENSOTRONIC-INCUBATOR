#include "sev_seg_init.h"

void seven_seg_init(){
	control_port_dir =0xFF;     //set control port output
	data_port_dir   |=0x0F;     //set 4pins(0,1,2,3) of data as output
	control_port   =0x00;      //out 0 in the first
	data_port    &=~0x0F;      //out 0 in the first
}

void dis_7_seg(uint8 actual_temp ,uint8 const_temp ,uint8 actual_hum, uint8 const_hum)
{
	uint8 temp1;              //just variable
	temp1 = actual_temp % 10;   //to get fist num.
	control_port = (1<<seg2);   //place to display
	data_port=(data_port&0xf0)|(temp1&0x0f); //insert num in data port
	_delay_ms(dealay_time);                  //dalay

	temp1 = actual_temp / 10;         //to get fist num.
	control_port = (1<<seg1);         //place to display
	data_port=(data_port&0xf0)|(temp1&0x0f);  //insert num in data port
	_delay_ms(dealay_time);

	uint8 temp2;
	temp2 = const_temp % 10;
	control_port = (1<<seg4);
	data_port=(data_port&0xf0)|(temp2&0x0f);
	_delay_ms(dealay_time);

	temp2 = const_temp / 10;
	control_port = (1<<seg3);
	data_port=(data_port&0xf0)|(temp2&0x0f);
	_delay_ms(dealay_time);

	////////////////////////////////////////////

	uint8 temp3;
	temp3 = actual_hum % 10;
	control_port = (1<<seg6);
	data_port=(data_port&0xf0)|(temp3&0x0f);
	_delay_ms(dealay_time);

	temp3 = actual_hum / 10;
	control_port = (1<<seg5);
	data_port=(data_port&0xf0)|(temp3&0x0f);
	_delay_ms(dealay_time);

	uint8 temp4;
	temp4 = const_hum % 10;
	control_port = (1<<seg8);
	data_port=(data_port&0xf0)|(temp4&0x0f);
	_delay_ms(dealay_time);

	temp4 = const_hum / 10;
	control_port = (1<<seg7);
	data_port=(data_port&0xf0)|(temp4&0x0f);
	_delay_ms(dealay_time);

}
void dis_actual_temp(uint8 actual_temp )
{
	uint8 temp1;              //just variable
	temp1 = actual_temp % 10;   //to get fist num.
	control_port = (1<<seg2);   //place to display
	data_port=(data_port&0xf0)|(temp1&0x0f); //insert num in data port
	_delay_ms(dealay_time);                  //dalay

	temp1 = actual_temp / 10;         //to get fist num.
	control_port = (1<<seg1);         //place to display
	data_port=(data_port&0xf0)|(temp1&0x0f);  //insert num in data port
	_delay_ms(dealay_time);
}
void dis_const_temp(uint8 const_temp ){
	uint8 temp2;
	temp2 = const_temp % 10;
	control_port = (1<<seg4);
	data_port=(data_port&0xf0)|(temp2&0x0f);
	_delay_ms(dealay_time);

	temp2 = const_temp / 10;
	control_port = (1<<seg3);
	data_port=(data_port&0xf0)|(temp2&0x0f);
	_delay_ms(dealay_time);

}
void dis_actual_hum(uint8 actual_hum ){
	uint8 temp3;
	temp3 = actual_hum % 10;
	control_port = (1<<seg6);
	data_port=(data_port&0xf0)|(temp3&0x0f);
	_delay_ms(dealay_time);

	temp3 = actual_hum / 10;
	control_port = (1<<seg5);
	data_port=(data_port&0xf0)|(temp3&0x0f);
	_delay_ms(dealay_time);
}
void dis_const_hum(uint8 const_hum ){
	uint8 temp4;
	temp4 = const_hum % 10;
	control_port = (1<<seg8);
	data_port=(data_port&0xf0)|(temp4&0x0f);
	_delay_ms(dealay_time);

	temp4 = const_hum / 10;
	control_port = (1<<seg7);
	data_port=(data_port&0xf0)|(temp4&0x0f);
	_delay_ms(dealay_time);
}
