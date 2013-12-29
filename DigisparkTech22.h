/*
  DigisparkPWM.h - Library for pwm on PB2 on ATTINY85.
  Created by Digistump
  Released into the public domain.
*/
#ifndef DigisparkTech22_h
#define DigisparkTech22_h


void DigisparkTech22Begin();
void DigisparkTech22Delay(int ms);
int  DigisparkTech22Read(int pin);
void DigisparkTech22(int pin,int value);

#endif