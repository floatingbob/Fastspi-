/* 
 
 by Robert Werner
 floatingbob@icloud.com
 
 This sketch allows you to drive a strand of LEDs with a TM1009 chip. These
 LEDs currently drive from one pin, into LEDs that are hooked up in series. 
 Four strands blink at random speeds.
 
 I am currently attempting to streamline all my for statements that drive the LEDs into
 a single for array. 
 
 
 */

//--------------Maxbotix EZ1 Sensor Global Variables-----------------//

const int sensorPin = 5;
long value = 0;
int cm = 0;
int inches = 0;

//------------------------------------------------------------------//

#include <FastSPI_LED.h>
#define NUM_LEDS 300
struct CRGB { 
  unsigned char r; 
  unsigned char g; 
  unsigned char b; 
};
struct CRGB *leds;
int aPin = 4;

//----Millis Clock Global Variables------------------------------//

unsigned long currentMillis[9] = {
  0,0,0,0,0,0,0,0,0}; //millis timer array strands 1-4

unsigned long stepTime[9] = {
  0,0,0,0,0,0,0,0,0}; //step time clock restarter strands 1-4

unsigned long delayLED[9] = {
  20,20,20,20,20,20,20,20,20}; //delay array. !!!Randomizer further randomizes within sketch!

unsigned long strandLength[9] = {
  0,18,18,18,18,18,18,18,18}; //strand length (change this number for each rib of the umbrella)

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

int t[9] = {
  0,0,0,0,0,0,0,0}; //Strand timer varialbe that allows an LED to run the full length at one speed
int s = 0; //speed variable, which pulls a random number from the blinkSpeed[]

int reset = 0; //reset all LEDs when not sensing people

//---------------------------------------------------------------//

void setup() {
  FastSPI_LED.setLeds(NUM_LEDS);
  //FastSPI_LED.setChipset(CFastSPI_LED::SPI_SM16716);
  FastSPI_LED.setChipset(CFastSPI_LED::SPI_TM1809);
  //FastSPI_LED.setChipset(CFastSPI_LED::SPI_LPD6803);
  //FastSPI_LED.setChipset(CFastSPI_LED::SPI_HL1606);
  //FastSPI_LED.setChipset(CFastSPI_LED::SPI_595);
  //FastSPI_LED.setChipset(CFastSPI_LED::SPI_WS2801);
  FastSPI_LED.setPin(4); //set pin to drive LEDs
  FastSPI_LED.init(); //initiate the library for emenint use
  FastSPI_LED.start();

  leds = (struct CRGB*)FastSPI_LED.getRGBData(); 

  Serial.begin(9600);
  //  Serial.println("serial");

  randomSeed(analogRead(0));

}

//---------------------------------------------------------------//

void loop() {

  //  int randomizer[9] ={
  //    0,
  //    delayLED[1] + random(1,100),
  //    delayLED[2] + random(1,100),
  //    delayLED[3] + random(1,100),
  //    delayLED[4] + random(1,100),
  //    delayLED[5] + random(1,100),
  //    delayLED[6] + random(1,100),
  //    delayLED[7] + random(1,100),
  //    delayLED[8] + random(1,100)
  //    };

  //    randNumber = random(1,50);
  //  Serial.println(randNumber);

  currentMillis[1] = millis();
  currentMillis[2] = millis();
  currentMillis[3] = millis();
  currentMillis[4] = millis();
  currentMillis[5] = millis();
  currentMillis[6] = millis();
  currentMillis[7] = millis();
  currentMillis[8] = millis();

  int maX = 35;          //blinkSpeed Index maximum within the array
  int miN = 1;          //blinkSpeed Index minimum within the array of 100 numbers
  int s[9] = {
    random(blinkSpeed[miN],blinkSpeed[maX]), //0
    random(blinkSpeed[miN],blinkSpeed[maX]), //1
    random(blinkSpeed[miN],blinkSpeed[maX]), //2
    random(blinkSpeed[miN],blinkSpeed[maX]), //3
    random(blinkSpeed[miN],blinkSpeed[maX]), //4
    random(blinkSpeed[miN],blinkSpeed[maX]), //5
    random(blinkSpeed[miN],blinkSpeed[maX]), //6
    random(blinkSpeed[miN],blinkSpeed[maX]), //7 
    random(blinkSpeed[miN],blinkSpeed[maX])  //8

    };   //Initializes s with random number between miN-maX

    int k;                                        //
  for(k = 0; k <= endLED[1]; k++){              //Looks through LEDs to see if we've reached end of strand 1

    //Serial.print("K is ");
    //Serial.println(k); 

    //-------Strand 1---------------------------------------------------------------------
    if (k >= endLED[1]){                        //If we have, then set temporary t back to s for new random #
      //      t[1] = s[1];
      //      t[2] = s[2];
      //      t[3] = s[3];
      //      t[4] = s[4];
      //      t[5] = s[5];
      //      t[6] = s[6];
      //      t[7] = s[7];
      //      t[8] = s[8];

    }

    if(currentMillis[1] - stepTime[1] >= t[1]){
      leds[LEDsections[1]].r = 0;
      leds[LEDsections[1]].g = 0;
      leds[LEDsections[1]].b = 0;
      Serial.println(randNumber);
      LEDsections[1]++;
      //          Serial.println("LEDsections[]");
      //          Serial.println(LEDsections[9]);

      if(LEDsections[1] == endLED[1]){
        LEDsections[1] = startLED[1];
        t[1] = s[1];
        Serial.println(s[1]);

      }

      leds[LEDsections[1]].r = 255;
      leds[LEDsections[1]].g = 255;
      leds[LEDsections[1]].b = 255;

      stepTime[1] = currentMillis[1];
    }

    //-------Strand 2----------------------------------------------------
    if (k >= endLED[2]){                        //If we have, then set temporary t back to s for new random #
      t[2] = s[2];

    }

    if(currentMillis[2] - stepTime[2] >= t[2] ){
      leds[LEDsections[2]].r = 0;
      leds[LEDsections[2]].g = 0;
      leds[LEDsections[2]].b = 0;

      LEDsections[2]++;
      //          Serial.println("LEDsections[]");
      //          Serial.println(LEDsections[2]);

      if(LEDsections[2] == endLED[2]){
        LEDsections[2] = startLED[2];
        t[2] = s[2];
        Serial.println(s[2]);
      }

      leds[LEDsections[2]].r = 255;
      leds[LEDsections[2]].g = 255;
      leds[LEDsections[2]].b = 255;

      stepTime[2] = currentMillis[2];
    }

    //--------Strand 3-------------------------------------------------------
    if (k >= endLED[3]){                        //If we have, then set temporary t back to s for new random #
      t[3] = s[3];
    }
    if(currentMillis[3] - stepTime[3] >= t[3] ){
      leds[LEDsections[3]].r = 0;
      leds[LEDsections[3]].g = 0;
      leds[LEDsections[3]].b = 0;

      LEDsections[3]++;
      //          Serial.println("LEDsections[]");
      //          Serial.println(LEDsections[3]);

      if(LEDsections[3] == endLED[3]){
        LEDsections[3] = startLED[3];
        t[3] = s[3];
      }

      leds[LEDsections[3]].r = 255;
      leds[LEDsections[3]].g = 255;
      leds[LEDsections[3]].b = 255;

      stepTime[3] = currentMillis[3];
    }
    //------Strand 4--------------------------------------------------------------
    if (k >= endLED[4]){            //If we reach end of strand, then set temporary t back to s for new random #
      t[4] = s[4];
    }

    if(currentMillis[4] - stepTime[4] >=t[4] ){
      leds[LEDsections[4]].r = 0;
      leds[LEDsections[4]].g = 0;
      leds[LEDsections[4]].b = 0;

      LEDsections[4]++;
      //          Serial.println("LEDsections[]");
      //          Serial.println(LEDsections[4]);

      if(LEDsections[4] == endLED[4]){
        LEDsections[4] = startLED[4];
        t[4] = s[4];
      }

      leds[LEDsections[4]].r = 255;
      leds[LEDsections[4]].g = 255;
      leds[LEDsections[4]].b = 255;

      stepTime[4] = currentMillis[4];
    }
    //-------Strand 5-------------------------------------------------------------
    if (k >= endLED[5]){            //If we reach end of strand, then set temporary t back to s for new random #
      t[5] = s[5];
    }
    if(currentMillis[5] - stepTime[5] >= t[5] ){
      leds[LEDsections[5]].r = 0;
      leds[LEDsections[5]].g = 0;
      leds[LEDsections[5]].b = 0;

      LEDsections[5]++;
      //          Serial.println("LEDsections[]");
      //          Serial.println(LEDsections[4]);

      if(LEDsections[5] == endLED[5]){
        LEDsections[5] = startLED[5];
        t[5] = s[5];
      }

      leds[LEDsections[5]].r = 255;
      leds[LEDsections[5]].g = 255;
      leds[LEDsections[5]].b = 255;

      stepTime[5] = currentMillis[5];
    }
    //-------Strand 6-------------------------------------------------------------
    if (k >= endLED[6]){            //If we reach end of strand, then set temporary t back to s for new random #
      t[6] = s[6];
    }

    if(currentMillis[6] - stepTime[6] >= t[6] ){
      leds[LEDsections[6]].r = 0;
      leds[LEDsections[6]].g = 0;
      leds[LEDsections[6]].b = 0;

      LEDsections[6]++;
      //          Serial.println("LEDsections[]");
      //          Serial.println(LEDsections[6]);

      if(LEDsections[6] == endLED[6]){
        LEDsections[6] = startLED[6];
        t[6] = s[6];
      }

      leds[LEDsections[6]].r = 255;
      leds[LEDsections[6]].g = 255;
      leds[LEDsections[6]].b = 255;

      stepTime[6] = currentMillis[6];
    }
    //-------Strand 7-------------------------------------------------------------
    if (k >= endLED[7]){            //If we reach end of strand, then set temporary t back to s for new random #
      t[7] = s[7];
    }
    if(currentMillis[7] - stepTime[7] >= t[7] ){
      leds[LEDsections[7]].r = 0;
      leds[LEDsections[7]].g = 0;
      leds[LEDsections[7]].b = 0;

      LEDsections[7]++;
      //          Serial.println("LEDsections[]");
      //          Serial.println(LEDsections[7]);

      if(LEDsections[7] == endLED[7]){
        LEDsections[7] = startLED[7];
        t[7] = s[7];
      }

      leds[LEDsections[7]].r = 255;
      leds[LEDsections[7]].g = 255;
      leds[LEDsections[7]].b = 255;

      stepTime[7] = currentMillis[7];
    }
    //-------Strand 8-------------------------------------------------------------
    if (k >= endLED[8]){            //If we reach end of strand, then set temporary t back to s for new random #
      t[8] = s[8];
    }
    if(currentMillis[8] - stepTime[8] >= t[8] ){
      leds[LEDsections[8]].r = 0;
      leds[LEDsections[8]].g = 0;
      leds[LEDsections[8]].b = 0;

      LEDsections[8]++;
      //          Serial.println("LEDsections[]");
      //          Serial.println(LEDsections[8]);

      if(LEDsections[8] == endLED[8]){
        LEDsections[8] = startLED[8];
        t[8] = s[8];
      }

      leds[LEDsections[8]].r = 255;
      leds[LEDsections[8]].g = 255;
      leds[LEDsections[8]].b = 255;

      stepTime[8] = currentMillis[8];
    }
  }

  FastSPI_LED.show();
  //      Serial.println("LEDs On");

  //  }
}

//}

























