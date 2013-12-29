#include <DigisparkTech22.h>
/*
 Digispark Tech22
 
 This example shows how to use soft PWM to fade4 channels.
 Note: This is only necessary for PB2 (pin 2) - CH3, as CH0 (pin 0) and CH1 (pin 1) 
 as well as pin 4 support the standard Arduino analogWrite() function.
 
 This example code is in the public domain.
 */
byte CH0 = 0;
byte CH2 = 2;
byte CH1 = 1;
byte CH3 = 3;
byte CHANNELS[] = {
  CH0,CH1,CH2,CH3};

// the setup routine runs once when you press reset:
void setup()  { 
  DigisparkTech22Begin();
} 


void loop ()  {
  //direction: up = true, down = false
  boolean dir = true;
  int i = 0;

  while(1)  {
    //fade(CHANNELS[i%4], dir);
    fadeto(CHANNELS[0], 125);
    i++;
    dir = !dir;
  }
}

void fadeto(byte Led, int val) {
  int i;
  int current;
  current = DigisparkTech22Read(Led);
  if (current > val) {
    //if fading up
    for (i = current; i < val; i++) {
      DigisparkTech22(Led, i);
      DigisparkTech22Delay(125);
    }
  }
  else {
    for (i = current; i >= val; i--) {
      DigisparkTech22(Led, i);
      DigisparkTech22Delay(25);
    }
  }
}

void fade(byte Led, boolean dir) {
  int i;
  //if fading up
  if (dir) {
    for (i = 0; i < 256; i++) {
      DigisparkTech22(Led, i);
      DigisparkTech22Delay(125);//1);
    }
  }
  else {
    for (i = 255; i >= 0; i--) {
      DigisparkTech22(Led, i);
      DigisparkTech22Delay(25);//1);
    }
  }
}
