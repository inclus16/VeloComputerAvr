/*
 * VeloComputer.c
 *
 * Created: 10.05.2021 18:58:06
 * Author : wow12
 */ 
#include <avr/io.h>
#define F_CPU 20000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "sh1106.h"
#include "Timer.h"
#include "WheelComputing.h"

int main(void)
{
	sei();
    /* Replace with your application code */
	DDRD |= (1<<PORTD5)|(1<<PORTD6)|(1<<PORTD7);
	DDRB |= (1<<PORTB1);
	_delay_ms(100);
	SH1106_begin();
	SH1106_clear();
	timer_init();
	wheel_init();	
    while (1) 
    {	    
	    SH1106_display();
	}
}
 
 ISR (TIMER1_COMPA_vect)
 {
	 timer_increment();
	 
 }
 
 ISR(INT1_vect){
	 handle_signal(get_total_milliseconds());	 
 }
