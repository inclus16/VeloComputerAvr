/*
 * Timer.c
 *
 * Created: 25.10.2020 15:21:28
 *  Author: wow12
 */ 
#include "Timer.h"

volatile uint8_t seconds = 0;
volatile uint8_t minutes = 0;
volatile uint8_t hours = 0;
volatile uint16_t milliseconds = 0;
volatile uint32_t totalMilliseconds = 0;

void timer_init()
{
	TCCR1B |= (1<<CS12) | (1<<CS10) | (1<<WGM12);
	TIMSK1 |= (1<<OCIE1A);
	TCNT1H = 0; 
	OCR1A = 19;
	SH1106_char(0,0,'0',16,1);
	SH1106_char(7,0,'0',16,1);
	SH1106_char(14,0,':',16,1);
	SH1106_char(21,0,'0',16,1);
	SH1106_char(28,0,'0',16,1);
	SH1106_char(35,0,':',16,1);
	SH1106_char(42,0,'0',16,1);
	SH1106_char(49,0,'0',16,1);
}


void timer_increment()
{
	milliseconds ++;
	totalMilliseconds ++;
	if(milliseconds>=1000){
		increment_seconds();
		display_time();
		milliseconds=0;
	}
}

void increment_seconds()
{
	seconds++;
	if(seconds==59){
		increment_minutes();
		seconds=0;
	}
}

void increment_minutes()
{
	minutes++;
	if (minutes==59)
	{
		increment_hours();
		minutes=0;
	}
		
}

void increment_hours()
{	
	hours++;	
}

void display_time()
{
	char str[2];
	itoa(seconds,str,10);
	if(seconds>=10){
		SH1106_char(42,0,str[0],16,1);
		SH1106_char(49,0,str[1],16,1);
	}else{
		SH1106_char(42,0,'0',16,1);
		SH1106_char(49,0,str[0],16,1);		
	}
	str[0]='0';
	str[1]='0';
	itoa(minutes,str,10);
	if(minutes>=10){
		SH1106_char(21,0,str[0],16,1);
		SH1106_char(28,0,str[1],16,1);
	}else{
		SH1106_char(21,0,'0',16,1);
		SH1106_char(28,0,str[0],16,1);		
	}
	str[0]='0';
	str[1]='0';
	itoa(hours,str,10);
	if(hours>=10){
		SH1106_char(21,0,str[0],16,1);
		SH1106_char(28,0,str[1],16,1);		
	}else{
		SH1106_char(0,0,'0',16,1);
		SH1106_char(7,0,str[0],16,1);		
	}
}

uint32_t get_total_milliseconds(){
	return totalMilliseconds;
}