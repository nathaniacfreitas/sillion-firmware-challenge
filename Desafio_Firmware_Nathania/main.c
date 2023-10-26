/*
 * Desafio_Firmware_Nathania.c
 *
 * Created: 25-Oct-23 11:36:35
 * Author : Nathania Freitas
 */ 


#define F_CPU 16000000UL


#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>


const int buttonDirection = DDD6;     
const int motorDirection =  DDD7;

const int buttonPin = PIND6;

const int motorPort =  PORTD7;

bool buttonState = 0;
const int turnOffMilliseconds = 10000;

int setbit(int number, int position) {
	return number | (1 << position);
}

int unsetbit(int number, int position) {
	return number & ~(1 << position);
}

int main(void) {
	DDRD = unsetbit(DDRD, buttonDirection);
	DDRD = setbit(DDRD, motorDirection);
	PORTD = 0;
		
    while (1) {
		buttonState = (PIND & (1 << buttonPin));

		if (buttonState == 1) {
			PORTD = setbit(PORTD, motorPort);

			_delay_ms(turnOffMilliseconds);

			PORTD = unsetbit(PORTD, motorPort); 
		}
    }
}

