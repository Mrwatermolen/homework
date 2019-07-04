#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin)
{
	pinMode(pin,OUTPUT);
	_pin=pin;
	_time=250;
}

void Morse::dot()
{
	digitalWrite(_pin,HIGH);
	delay(_time);
	digitalWrite(_pin,LOW);
	delay(_time);
}

void Morse::dash()
{
	digitalWrite(_pin,HIGH);
	delay(_time*4);
	digitalWrite(_pin,LOW);
	delay(_time);
}

void Morse::c_time()
{
	digitalWrite(_pin,LOW);
	delay(_time*3);
}

void Morse::w_time()
{
	digitalWrite(_pin,LOW);
	delay(_time*7);
}
