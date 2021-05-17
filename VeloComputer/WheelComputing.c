/*
 * WheelComputing.c
 *
 * Created: 25.10.2020 16:11:38
 *  Author: wow12
 */ 
#include "WheelComputing.h"


float distance = 0;
uint32_t lastSignal = 0;
uint8_t maxSpeed = 0;

void wheel_init()
{
	EIMSK |= (1<<INT1); 
	EICRA |= (1<<ISC11);
	
	SH1106_char(0,16,'K',16,1);
	SH1106_char(7,16,'M',16,1);
	SH1106_char(14,16,':',16,1);
	SH1106_char(21,16,'0',16,1);
	SH1106_char(28,16,'0',16,1);
	SH1106_char(35,16,'.',16,1);
	SH1106_char(42,16,'0',16,1);
	SH1106_char(49,16,'0',16,1);
	SH1106_char(56,16,'0',16,1);
	
	SH1106_char(0,32,'K',16,1);
	SH1106_char(7,32,'M',16,1);
	SH1106_char(14,32,'/',16,1);
	SH1106_char(21,32,'H',16,1);
	SH1106_char(28,32,':',16,1);
	SH1106_char(35,32,'0',16,1);
	SH1106_char(42,32,'0',16,1);
	
	
	SH1106_char(56,32,'M',16,1);
	SH1106_char(63,32,'A',16,1);
	SH1106_char(70,32,'X',16,1);
	SH1106_char(77,32,':',16,1);
	SH1106_char(84,32,'0',16,1);
	SH1106_char(91,32,'0',16,1);
}

void handle_signal(uint32_t time)
{
	distance += M_PER_SIGNAL;
	display_distance();
	if (lastSignal != 0)
	{
		uint32_t diff = time - lastSignal;
		lastSignal = time;
		display_speed(diff);
	}else{		
		lastSignal = time;
	}
}

void display_speed(uint32_t diff)
{
	char speedString[2];
	uint8_t mSpeed = (uint8_t)(KM_PER_SIGNAL/diff*MILLIS_IN_HOUR);
	itoa(mSpeed,speedString,10);
	if(mSpeed >= 10){
		SH1106_char(35,32,speedString[0],16,1);
		SH1106_char(42,32,speedString[1],16,1);
	}else{
		SH1106_char(35,32,'0',16,1);
		SH1106_char(42,32,speedString[0],16,1);
	}
	
	if (mSpeed > maxSpeed)
	{
		maxSpeed = mSpeed;
		display_max_speed(speedString);
	}
}


void display_max_speed(char* speedString)
{
	if(maxSpeed >= 10){
		SH1106_char(84,32,speedString[0],16,1);
		SH1106_char(91,32,speedString[1],16,1);
	}else{
		SH1106_char(84,32,'0',16,1);
		SH1106_char(91,32,speedString[0],16,1);
	}
}

void display_distance()
{
	char str[5];
	itoa((uint16_t)distance,str,10);
	
	if(distance<10){
		SH1106_char(56,16,str[0],16,1);
		return;
	}
	if(distance<100){
		SH1106_char(49,16,str[0],16,1);
		SH1106_char(56,16,str[1],16,1);
		return;
	}
	if(distance<1000){
		SH1106_char(42,16,str[0],16,1);
		SH1106_char(49,16,str[1],16,1);
		SH1106_char(56,16,str[2],16,1);
		return;
	}
	if(distance<10000){
		SH1106_char(28,16,str[0],16,1);
		SH1106_char(42,16,str[1],16,1);
		SH1106_char(49,16,str[2],16,1);
		SH1106_char(56,16,str[3],16,1);	
		return;
	}
	SH1106_char(21,16,str[0],16,1);
	SH1106_char(28,16,str[1],16,1);
	SH1106_char(42,16,str[2],16,1);
	SH1106_char(49,16,str[3],16,1);
	SH1106_char(56,16,str[4],16,1);
	return;
}