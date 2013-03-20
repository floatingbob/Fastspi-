/* by Robert Werner
 floatingbob@icloud.com
 This sketch allows you to drive a strand of LEDs with a TM1009 chip. These
 LEDs currently drive from one pin, into LEDs that are hooked up in series. 
 Four strands blink at random speeds.
 
 NEW - 03/15/13 
 1. SENSOR was causing an ERROR with the timer for LEDS. Removed sensor//
 2. TIMER works again! Tried to move it within the sketch, but realized that I can't!
 Delay timer runs everything globally. Need to come up with another randomizer for 
 within the sketch. 
 3. Added randomizer variable within the loop for each strand.
 4. Add array for millis clock
 5. Finish staggering a fake digit for 0 in the arrays so the numbers match strands
 6. Everything that can be enumerated is within an array except for the actual strand operation.
 It's just too large for me to comprehend. 
 
 */
//--------------Maxbotix EZ1 Sensor Global Variables-----------------//
const int sensorPin = 5;
long value = 0;
int cm = 0;
int inches = 0;
//------------------------------------------------------------------//

#include <FastSPI_LED.h>
#define NUM_LEDS 200
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
  0, 0, strandLength[1], strandLength[1] + strandLength[2],strandLength[1] + strandLength[2] +
    strandLength[3], strandLength[1] + strandLength[2] +
    strandLength[3] + strandLength[4], strandLength[1] + strandLength[2] +
    strandLength[3] + strandLength[4] + strandLength[5],strandLength[1] + strandLength[2] +
    strandLength[3] + strandLength[4] + strandLength[5] + strandLength[6],strandLength[1] + strandLength[2] +
    strandLength[3] + strandLength[4] + strandLength[5] + strandLength[6] + strandLength[7]
}; //global load of start position based upon strand length

int LEDsections[9] = {
  0, startLED[1],startLED[2], startLED[3], startLED[4], startLED[5], startLED[6],startLED[7],startLED[8], 
}; //starting position 
//of the led (this number drives the LED through the strand from thsi start position)

int endLED[9] = {
  0, startLED[1] + strandLength[1], startLED[2] + strandLength[2], startLED[3] + strandLength[3],
  startLED[4] + strandLength[4], startLED[5] + strandLength[5], startLED[6] + strandLength[6],
    startLED[7] + strandLength[7], startLED[8] + strandLength[8] }; //starting point of LED + strandLength


int reset = 0; //reset all LEDs when not sensing people
//---------------------------------------------------------------//

void setup()
{
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

}

void loop (){
  int randomizer[5] ={
    0, delayLED[1] + random(1,100), delayLED[2] + random(1,100),delayLED[3] + random(1,100),
    delayLED[4] + random(1,100)  };
  //  int randomizer[1] = delayLED[1] + random(1,200);
  //  int randomizer[2] = delayLED[2] + random(1,200);
  //  int randomizer[3] = delayLED[3] + random(1,200);
  //  int randomizer[4] = delayLED[4] + random(1,200);
  //  value = pulseIn(sensorPin, HIGH);
  //  cm = value/58; //pulse width is 58 microseconds per cm
  //  inches = value / 147; //which is 147 microseconds per inch
  ////  Serial.print(cm);
  ////  Serial.print(" cm, ");
  ////  Serial.print(inches);
  ////  Serial.print("in");
  ////  Serial.println();
  //  if (inches <= 10) {



  //------------------Strand 1------------------/
  int k; 
  for(k = LEDsections[1]; k < endLED[1]; k++) {
    currentMillis[1] = millis();
    if(currentMillis[1] - stepTime[1] >= randomizer[1]) { //turn off LEDs 
      leds[LEDsections[1]].b = 0; 
      leds[LEDsections[1]].g = 0; 
      leds[LEDsections[1]].r = 0;

      LEDsections[1]++;
      Serial.println("LEDsections[1]");
      Serial.println(LEDsections[1]);


      if(LEDsections[1] == endLED[1]){
        LEDsections[1] = startLED[1];
      }

      leds[LEDsections[1]].b = 180; 
      leds[LEDsections[1]].g = 180; 
      leds[LEDsections[1]].r = 180;

      stepTime[1] = currentMillis[1];

    }
  }
  //--------------Strand 1-----------------------//

  //------------------Strand 2------------------/
  int j;

  for(j = startLED[2]; j < endLED[2]; j++) {
    currentMillis[2] = millis();
    if(currentMillis[2] - stepTime[2] >= randomizer[2]) { //turn off LEDs 
      leds[LEDsections[2]].b = 0; 
      leds[LEDsections[2]].g = 0; 
      leds[LEDsections[2]].r = 0;

      LEDsections[2]++;

      if(LEDsections[2] == endLED[2]){
        LEDsections[2] = startLED[2];
      }

      leds[LEDsections[2]].b = 180; 
      leds[LEDsections[2]].g = 180; 
      leds[LEDsections[2]].r = 180;

      stepTime[2] = currentMillis[2];

    }
  }
  //--------------Strand 2-----------------------//
  //------------------Strand 3------------------/
  int l;

  for(l = startLED[3]; l < endLED[3]; l++) {
    currentMillis[3] = millis();
    if(currentMillis[3] - stepTime[3] >= randomizer[3]) { //turn off LEDs 
      leds[LEDsections[3]].b = 0; 
      leds[LEDsections[3]].g = 0; 
      leds[LEDsections[3]].r = 0;

      LEDsections[3]++;

      if(LEDsections[3] == endLED[3]){
        LEDsections[3] = startLED[3];
      }

      leds[LEDsections[3]].b = 180; 
      leds[LEDsections[3]].g = 180; 
      leds[LEDsections[3]].r = 180;

      stepTime[3] = currentMillis[3];
    }
  }
  //--------------Strand 3-----------------------//

  //------------------Strand 4------------------/
  int m;

  for(m = startLED[4]; m < endLED[4]; m++) {
    currentMillis[4] = millis();
    if(currentMillis[4] - stepTime[4] >= randomizer[4]) { //turn off LEDs 
      leds[LEDsections[4]].b = 0; 
      leds[LEDsections[4]].g = 0; 
      leds[LEDsections[4]].r = 0;

      LEDsections[4]++;

      if(LEDsections[4] == endLED[4]){
        LEDsections[4] = startLED[4];
      }

      leds[LEDsections[4]].b = 180; 
      leds[LEDsections[4]].g = 180; 
      leds[LEDsections[4]].r = 180;

      stepTime[4] = currentMillis[4];

    }
  }
  //--------------Strand 4-----------------------//
  //------------------Strand 5------------------/
  int n;

  for(n = startLED[5]; n < endLED[5]; n++) {
    currentMillis[5] = millis();
    if(currentMillis[5] - stepTime[5] >= randomizer[5]) { //turn off LEDs 
      leds[LEDsections[5]].b = 0; 
      leds[LEDsections[5]].g = 0; 
      leds[LEDsections[5]].r = 0;

      LEDsections[5]++;

      if(LEDsections[5] == endLED[5]){
        LEDsections[5] = startLED[5];
      }

      leds[LEDsections[5]].b = 180; 
      leds[LEDsections[5]].g = 180; 
      leds[LEDsections[5]].r = 180;

      stepTime[5] = currentMillis[5];

    }
  }
  //--------------Strand 5-----------------------//
  //------------------Strand 6------------------/
  int o;

  for(o = startLED[6]; o < endLED[6]; o++) {
    currentMillis[6] = millis();
    if(currentMillis[6] - stepTime[6] >= randomizer[6]) { //turn off LEDs 
      leds[LEDsections[6]].b = 0; 
      leds[LEDsections[6]].g = 0; 
      leds[LEDsections[6]].r = 0;

      LEDsections[6]++;

      if(LEDsections[6] == endLED[6]){
        LEDsections[6] = startLED[6];
      }

      leds[LEDsections[6]].b = 180; 
      leds[LEDsections[6]].g = 180; 
      leds[LEDsections[6]].r = 180;

      stepTime[6] = currentMillis[6];

    }
  }
  //--------------Strand 6-----------------------//
   //------------------Strand 7------------------/
  int p;

  for(p = startLED[7]; p < endLED[7]; p++) {
    currentMillis[7] = millis();
    if(currentMillis[7] - stepTime[7] >= randomizer[7]) { //turn off LEDs 
      leds[LEDsections[7]].b = 0; 
      leds[LEDsections[7]].g = 0; 
      leds[LEDsections[7]].r = 0;

      LEDsections[7]++;

      if(LEDsections[7] == endLED[7]){
        LEDsections[7] = startLED[7];
      }

      leds[LEDsections[7]].b = 180; 
      leds[LEDsections[7]].g = 180; 
      leds[LEDsections[7]].r = 180;

      stepTime[7] = currentMillis[7];

    }
  }
  //--------------Strand 7-----------------------//
   //------------------Strand 8------------------/
  int q;

  for(q = startLED[8]; q < endLED[8]; q++) {
    currentMillis[8] = millis();
    if(currentMillis[8] - stepTime[8] >= randomizer[8]) { //turn off LEDs 
      leds[LEDsections[8]].b = 0; 
      leds[LEDsections[8]].g = 0; 
      leds[LEDsections[8]].r = 0;

      LEDsections[8]++;

      if(LEDsections[8] == endLED[8]){
        LEDsections[8] = startLED[8];
      }

      leds[LEDsections[8]].b = 180; 
      leds[LEDsections[8]].g = 180; 
      leds[LEDsections[8]].r = 180;

      stepTime[8] = currentMillis[8];

    }
  }
  //--------------Strand 8-----------------------//

  FastSPI_LED.show();
  Serial.println("LED's On ");
  //  }
  //  else{
  //    
  //    int n;
  ////    delay(8000);
  //    
  //    for(n = 0; n < NUM_LEDS; n++){
  //      leds[reset].b = 0;
  //      leds[reset].g = 0;
  //      leds[reset].r = 0;
  //      reset++;
  //      
  //      if(reset == NUM_LEDS){
  //        reset = 0;
  //      }
  //
  //      FastSPI_LED.show();
  //      Serial.println("No people detected. ");
  //    }
  //
  //
  //  }
}




































