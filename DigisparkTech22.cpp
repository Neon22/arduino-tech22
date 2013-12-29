#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "DigisparkTech22.h"
#include "Arduino.h"

#define set(x) |= (1<<x) 
#define clr(x) &=~(1<<x) 
#define inv(x) ^=(1<<x)

#define CH3_CLEAR (pinlevelB &= ~(1 << CH3)) // 
#define CH2_CLEAR (pinlevelB &= ~(1 << CH2)) // map CH2 to PB2
#define CH1_CLEAR (pinlevelB &= ~(1 << CH1)) // 
#define CH0_CLEAR (pinlevelB &= ~(1 << CH0)) // 
#define PORTB_MASK  (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3)
#define CH3 PB3
#define CH2 PB2
#define CH1 PB1
#define CH0 PB0


unsigned char DigisparkPWMcompare[4]; 
volatile unsigned char DigisparkPWMcompbuff[4];

void DigisparkTech22Begin() {                

  pinMode(3, OUTPUT); 
  pinMode(2, OUTPUT); 
  pinMode(1, OUTPUT); 
  pinMode(0, OUTPUT); 
  //CLKPR = (1 << CLKPCE);        // enable clock prescaler update
  //CLKPR = 0;                    // set clock to maximum (= crystal)


  DigisparkPWMcompare[0] = 0x00;// set default PWM values
  DigisparkPWMcompare[1] = 0x00;// set default PWM values
  DigisparkPWMcompare[2] = 0x00;// set default PWM values
  DigisparkPWMcompare[3] = 0x00;// set default PWM values
  DigisparkPWMcompbuff[0] = 0x00;// set default PWM values
  DigisparkPWMcompbuff[1] = 0x00;// set default PWM values
  DigisparkPWMcompbuff[2] = 0x00;// set default PWM values
  DigisparkPWMcompbuff[3] = 0x00;// set default PWM values
  

  TIFR = (1 << TOV0);           // clear interrupt flag
  TIMSK = (1 << TOIE0);         // enable overflow interrupt
  TCCR0B = (1 << CS00);         // start timer, no prescale

  sei(); 
}

void DigisparkTech22(int pin,int value){
	DigisparkPWMcompbuff[pin] = value;
}

int DigisparkTech22Read(int pin) {
	return DigisparkPWMcompbuff[pin];
}

void DigisparkTech22Delay(int ms) {
  while (ms) {
    _delay_ms(1);
    ms--;
  }
}

ISR (TIM0_OVF_vect) {
  static unsigned char pinlevelB=PORTB_MASK;
  static unsigned char softcount=0xFF;

  PORTB = pinlevelB;            // update outputs
  
  if(++softcount == 0){         // increment modulo 256 counter and update
                                // the compare values only when counter = 0.
    DigisparkPWMcompare[0] = DigisparkPWMcompbuff[0]; // verbose code for speed
    DigisparkPWMcompare[1] = DigisparkPWMcompbuff[1]; // verbose code for speed
    DigisparkPWMcompare[2] = DigisparkPWMcompbuff[2]; // verbose code for speed
	DigisparkPWMcompare[3] = DigisparkPWMcompbuff[3]; // verbose code for speed

    pinlevelB = PORTB_MASK;     // set all port pins high
  }
  // clear port pin on compare match (executed on next interrupt)
  if(DigisparkPWMcompare[0] == softcount) CH0_CLEAR;
  if(DigisparkPWMcompare[1] == softcount) CH1_CLEAR;
  if(DigisparkPWMcompare[2] == softcount) CH2_CLEAR;
  if(DigisparkPWMcompare[3] == softcount) CH3_CLEAR;
}

