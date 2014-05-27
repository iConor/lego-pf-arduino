lego-pf-arduino
===============
*LEGO Power Functions Arduino Library*

I found this fantastic library that has allowed me to control my LEGEO 4X4 Crawler (9398) using an Arduino and an infrared LED. My first sketch using the library would not compile. I started digging and eventually read in the [Arduino release notes](http://arduino.cc/en/Main/ReleaseNotes) that they renamed the WProgram.h file to Arduino.h. I made that same change in this library's header file and, kapow - it works!

**Original:** SuperCow's LEGOPowerFunctions Library for Arduino - [Source](http://www.eurobricks.com/forum/index.php?showtopic=31640 "Eurobricks")  | [Download](http://rjwiersma.nl/img/LEGOPowerFunctions.rar "LEGOPowerFunctions Library")
