/* 
 
 by Robert Werner
 floatingbob@icloud.com
 
 This sketch allows you to drive a strand of LEDs with a TM1009 chip. These
 LEDs currently drive from one pin, into LEDs that are hooked up in series. 
 Four strands blink at random speeds.
 
 I am currently attempting to streamline all my for statements that drive the LEDs into
 a single for array. 
 
 
 */


//---------------------------------------------------------------//
// VARIABLES

// INCLUDES  
#include <FastSPI_LED.h>

// DEFINES
#define NUM_LEDS 300

// GLOBALS
struct CRGB { 
  unsigned char r; 
  unsigned char g; 
  unsigned char b; 
};
struct CRGB *leds;
int outputPin = 4;

// MAXBOTIX
const int sensorPin = 5;
long value = 0;
int cm = 0;
int inches = 0;

// CLOCK
unsigned long currentMillis[9] = {0,0,0,0,0,0,0,0,0}; //millis timer array strands 1-4

unsigned long stepTime[9] = {0,0,0,0,0,0,0,0,0}; //step time clock restarter strands 1-4

unsigned long delayLED[9] = {20,20,20,20,20,20,20,20,20}; //delay array. !!!Randomizer further randomizes within sketch!

unsigned long strandLength[9] = {0,18,18,18,18,18,18,18,18}; //strand length (change this number for each rib of the umbrella)

int startLED[9] = { 
  //  0,0,18,36,54,72,90,108,126
  0,
  0,
  strandLength[1],
  strandLength[1] + strandLength[2],
  strandLength[1] + strandLength[2] + strandLength[3],
  strandLength[1] + strandLength[2] + strandLength[3] + strandLength[4],
  strandLength[1] + strandLength[2] + strandLength[3] + strandLength[4] + strandLength[5],
  strandLength[1] + strandLength[2] + strandLength[3] + strandLength[4] + strandLength[5] + strandLength[6],
  strandLength[1] + strandLength[2] + strandLength[3] + strandLength[4] + strandLength[5] + strandLength[6] + strandLength[7]
}; //global load of start position based upon strand length

int LEDsections[9] = {
  0, startLED[1],startLED[2], startLED[3], startLED[4], startLED[5], startLED[6],startLED[7],startLED[8], 
}; //starting position 
//of the led (this number drives the LED through the strand from thsi start position)

int endLED[9] = {
  0, startLED[1] + strandLength[1], startLED[2] + strandLength[2], startLED[3] + strandLength[3],
  startLED[4] + strandLength[4], startLED[5] + strandLength[5], startLED[6] + strandLength[6],
  startLED[7] + strandLength[7], startLED[8] + strandLength[8] }; //starting point of LED + strandLength

int blinkSpeed[101] = {
  0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,
  41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,67,68,69,70,71,72,73,74,75,76,78,79,
  80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,99,100};

long randNumber;

int t[9] = {0,0,0,0,0,0,0,0}; //Strand timer varialbe that allows an LED to run the full length at one speed

int s = 0; //speed variable, which pulls a random number from the blinkSpeed[]

int reset = 0; //reset all LEDs when not sensing people












