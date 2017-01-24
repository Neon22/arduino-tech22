Arduino-tech22
==============

Allows the PWM to control tech22 Neon power supplies.
Implemented as a library for Arduino.
Used on the [Digispark](http://digistump.com/wiki/digispark)

* 4 channels (initially 0-3)
* leaving two pins spare for inputs
All done as software PWM using rgb LED as an initial guide.

#Usage:
Controls up to 4 channels of Tech22 Neon supplies.
In the loop function - place on/off/fadeto/setfade commands.

Use:
* on(channel). 
   * E.g. on(0) turns on channel 0.
* off(channel). 
   * E.g. off(2) turns off channel 2.
* pause(time). 
   * E.g. pause(2000) pauses for 2 seconds=2000 milliseconds
* pauserand(min, max). 
   * E.g. pauserand(2000,5000) pauses for random time between 2 and 5 seconds.
* fadeto(channel, value, duration). 
   * E.g. fadeto(2, 255, 5000) fades channel 2 from current value to full-on in 5 seconds.
   * E.g. fadeto(1, random(128,255), 3000) fades channel 1 over 3 seconds to a 
          random value between 50% and 100% on.
* setfade(channel, value)
   * E.g. setfade(2, 128) sets channel 2 brightness to 50% instantly.

#Installing
User-created libraries go in a subdirectory of your default sketch directory.
* On OSX, the new directory would be ~/Documents/Arduino/libraries/.
* On Windows, it would be My Documents\Arduino\libraries\.

Install by following instructions here:
https://www.arduino.cc/en/Guide/Libraries

Specifically:
Download the github files as a Zip file into your usual download location.
(we're going to install from ZIP which will copy the files to the library)

Under Sketch > Include Library click on "Add .ZIP Library"
Navigate to the downloaded zip and select it.

The examples wil be available under File > Examples
