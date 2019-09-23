#ifndef sev_seg_H
#define sev_seg_H

#include <avr/io.h>
#include <util/delay.h>
#include "PLATFORM_TYPES.h"

#define dealay_time 1         //between every segment
#define data_port_dir   DDRC   // to set port connect with BCD as output
#define control_port_dir  DDRB  // to set port connect with enables as output
#define data_port      PORTC     //to out data
#define control_port     PORTB   //to out enables
enum {seg1,seg2,seg3,seg4,seg5,seg6,seg7,seg8};  //8 segments

void seven_seg_init();       //Initialization
void dis_7_seg(uint8 actual_temp ,uint8 const_temp ,uint8 actual_hum, uint8 const_hum); //to display
void dis_actual_temp(uint8 actual_temp );
void dis_const_temp(uint8 const_temp );
void dis_actual_hum(uint8 actual_hum );
void dis_const_hum(uint8 const_hum );


#endif //sev_seg_H
