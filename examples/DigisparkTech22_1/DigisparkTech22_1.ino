#include <DigisparkTech22.h>
/*
 Digispark Tech22
 Controls up to 4 channels of Tech22 Neon supplies.
 In loop function - place on/off/fadeto/setfade commands.
 Use:
 on(channel). 
   - E.g. on(0) turns on channel 0.
 off(channel). 
   - E.g. off(2) turns off channel 2.
 pause(time). 
   - E.g. pause(2000) pauses for 2 seconds=2000 milliseconds
 pauserand(min, max). 
   - E.g. pauserand(2000,5000) pauses for random time between 2 and 5 seconds.
 fadeto(channel, value, duration). 
   - E.g. fadeto(2, 255, 5000) fades channel 2 from current value to full-on in 5 seconds.
   - E.g. fadeto(1, random(128,255), 3000) fades channel 1 over 3 seconds to a 
          random value between 50% and 100% on.
 setfade(channel, value)
   - E.g. setfade(2, 128) sets channel 2 brightness to 50% instantly.
 */
 
/// defines in here:
byte CH0 = 0;
byte CH1 = 1;
byte CH2 = 2;
byte CH3 = 3;
byte CHANNELS[] = {CH0,CH1,CH2,CH3};
// this setup routine runs once when you reset.
void setup()  { 
  DigisparkTech22Begin();
} 


//-------------------
// put sequence in here

void loop ()  {
  // all off to start
  off(0);
  off(1);
  off(2);
  off(3);
  int i;
  // Main loop:
  while(1)  {
    // On in seq 1..4
    fadeto(CH0, 255, 500);
    pauserand(1000,5000);
    fadeto(CH1, 255, 500);
    pauserand(1000,5000);
    fadeto(CH2, 255, 500);
    pauserand(1000,5000);
    fadeto(CH3, 255, 500);
    pauserand(1000,5000);
    // off in seq 1..4
    fadeto(CH0, 0, 500);
    pauserand(1000,5000);
    fadeto(CH1, 0, 500);
    pauserand(1000,5000);
    fadeto(CH2, 0, 500);
    pauserand(1000,5000);
    fadeto(CH3, 0, 500);
    pauserand(1000,5000);
    //on/off in seq 1,3,2,4
    i=0;
    while (i < 4) {
      fadeto(CH0, 255, 500);
      pauserand(1000,5000);
      fadeto(CH0, 0, 500);
      fadeto(CH2, 255, 500);
      pauserand(1000,5000);
      fadeto(CH2, 0, 500);
      fadeto(CH1, 255, 500);
      pauserand(1000,5000);
      fadeto(CH1, 0, 500);
      fadeto(CH3, 255, 500);
      pauserand(1000,5000);
      fadeto(CH3, 0, 500);
      i++;
    }
  }
}

//-------------------------------------
// support functions to switch on, off, pause, and fadteto, setfade over time
void on(byte channel)  {
  DigisparkTech22(CHANNELS[channel], 255);
}

void off(byte channel)  {
  DigisparkTech22(CHANNELS[channel], 0);
}

void pause(int millisec)  {
  DigisparkTech22Delay(millisec);
}

void pauserand(int min_ms, int max_ms)  {
  DigisparkTech22Delay(random(min_ms, max_ms));
}

void setfade(byte channel, int val)  {
    DigisparkTech22(CHANNELS[channel], val);
}

void fadeto(byte channel, int val, int dur) {
  int i;
  int current = DigisparkTech22Read(CHANNELS[channel]);
  int dly = (dur/100 * 64) / abs(current-val+1); //+1 to avoid divide zero error
  if (current < val) {
    //fading up from current to val
    for (i = current; i < val; i++) {
      DigisparkTech22(CHANNELS[channel], i);
      DigisparkTech22Delay(dly);
    }
  }
  else { // fading down from current to val
    for (i = current; i >= val; i--) {
      DigisparkTech22(CHANNELS[channel], i);
      DigisparkTech22Delay(dly);
    }
  }
}

