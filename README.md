Fastspi-
========
I am currently working from the library and sketches provided at   http://code.google.com/p/fastspi/


This is an Arduino sketch that uses the fastspi library to drive the TM1809 chip and LEDs with an ultrasonic sensor

Currently I have the Fastspi library working to drive a strip of LEDs out or one arduino pin at a time. I have been able 
to modify the sketch to alternate the drive between two pins with the use of a trigger switch

I am trying to find the right ultra sonic sensor that will rech 25 feet, then incorporate that sensor as a trigger for
my LED strand. 

Eventually I would like to create a class from this library with instances for each pin, then call that up within my 
sketch. 
