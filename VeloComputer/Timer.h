/*
 * Timer.h
 *
 * Created: 25.10.2020 15:28:53
 *  Author: wow12
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include "sh1106.h"
#include <stdlib.h>

void timer_init();
void timer_increment();
uint32_t get_total_milliseconds();
void increment_seconds();
void increment_minutes();
void increment_hours();
void display_time();


#endif /* TIMER_H_ */