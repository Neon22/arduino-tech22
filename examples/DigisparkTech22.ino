#include <DigisparkTech22.h>
/*
 Digispark Tech22
 
 This example shows how to use soft PWM to fade4 channels.
 Note: This implements software PWM even though its not required for pins 0,1 (CH 0,1) 
 - these two pins have hardware PWM support courtesy of the standard Arduino analogWrite() function.
 But we do all 4 here in software PWM.
 
 This example code is in the public domain.
 */
 
byte CH0 = 0;
byte CH1 = 1;
byte CH2 = 2;
byte CH3 = 3;
byte CHANNELS[] = {CH0,CH1,CH2,CH3}; // use this for easy access to all 4 channels

// the setup routine runs once when you press reset:
void setup()  { 
	// setup the software interrupt based PWM routines
	DigisparkTech22Begin();
} 

// runs after setup and loops forever
void loop ()  {
	//direction: up = true, down = false
	boolean dir = true;
	int i = 0;
	while(1)  {
		//fade(CHANNELS[i%4], dir);
		// simple example fades channel zero up
		fadeto(CHANNELS[0], 125);
		i++;
		dir = !dir;
	}
}

// General functions that control a channel and do not need to be adjusted
// Just call them in your loop code.


void fadeto(byte Led, int val) {
	// read the current value and fade from wherever we are now to the new value.
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
	// fade up to maximum or,
	// fade down to minimum
	int i;
	
	if (dir) {
		// fading up
		for (i = 0; i < 256; i++) {
			DigisparkTech22(Led, i);
			DigisparkTech22Delay(125);//1);
		}
	}
	else { // fading down
		for (i = 255; i >= 0; i--) {
			DigisparkTech22(Led, i);
			DigisparkTech22Delay(25);//1);
		}
	}
}
