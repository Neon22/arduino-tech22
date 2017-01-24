Arduino-tech22
==============

Allows the PWM to control tech22 Neon power supplies.
Implemented as a library for Arduino.
Used on the [Digispark](http://digistump.com/wiki/digispark)

* 4 channels (initially 0-3)
* leaving two pins spare for inputs
All done as software PWM using rgb LED as an initial guide.

#Install
User-created libraries go in a subdirectory of your default sketch directory.
* On OSX, the new directory would be ~/Documents/Arduino/libraries/.
* On Windows, it would be My Documents\Arduino\libraries\.

Install by following instructions here:
https://www.arduino.cc/en/Guide/Libraries

Specifically:
Download teh github files as a Zip file into your usual download location.
(we're going to install from ZIP which will copy the files to the library)

Under Sketch > Include Library click on "Add .ZIP Library"
Navigate to the downloaded zip and select it.

The examples wil be available under File > Examples
