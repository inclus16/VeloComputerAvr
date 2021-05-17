/*
 * WheelComputing.h
 *
 * Created: 25.10.2020 16:09:48
 *  Author: wow12
 */ 


#ifndef WHEELCOMPUTING_H_
#define WHEELCOMPUTING_H_
#define M_PER_SIGNAL 3.14*26/100
#define KM_PER_SIGNAL M_PER_SIGNAL/1000
#define MILLIS_IN_HOUR 3600000

#include "sh1106.h"
#include <stdlib.h>

void wheel_init();
void handle_signal(uint32_t time);
void increment_time();
void display_distance();
void display_speed();
void display_max_speed(char* speedString);

#endif /* WHEELCOMPUTING_H_ */