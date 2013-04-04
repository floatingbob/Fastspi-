/* by Robert Werner
 floatingbob@icloud.com
 This sketch allows you to drive a strand of LEDs with a TM1809 chip. These
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
 
 NEW - 03/16/13
 6. Everything that can be enumerated is within an array except for the actual strand operation.
 It's just too large for me to comprehend. 
 7. Added the sensor to the sketch again
 
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
unsigned long currentMillis[6] = {
  0,0,0,0,0,0}; //millis timer array strands 1-4

unsigned long stepTime[6] = {
  0,0,0,0,0,0}; //step time clock restarter strands 1-4

unsigned long delayLED[5] = {
  20,20,20,20,20}; //delay array. !!!Randomizer further randomizes within sketch!

unsigned long strandLength[5] = {
  0,18,18,18,18}; //strand length (change this number for each rib of the umbrella)

int startLED[5] = {
  0, 0, strandLength[1], strandLength[1] + strandLength[2],strandLength[1] + strandLength[2] +
    strandLength[3]}; //global load of start position based upon strand length

int LEDsections[5] = {
  0, startLED[1],startLED[2], startLED[3], startLED[4]}; //starting position 
//of the led (this number drives the LED through the strand from thsi start position)

int endLED[5] = {
  0, startLED[1] + strandLength[1], startLED[2] + strandLength[2], startLED[3] + strandLength[3],
  startLED[4] + strandLength[4]}; //starting point of LED + strandLength


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
    delayLED[4] + random(1,100)            };

  value = pulseIn(sensorPin, HIGH);
  cm = value/58; //pulse width is 58 microseconds per cm
  inches = value / 147; //which is 147 microseconds per inch
  Serial.print(cm);
  Serial.print(" cm, ");
  Serial.print(inches);
  Serial.print("in");
  Serial.println();
  //        delay(1000);

  currentMillis[5] = millis();

  if (inches <= 20) { 

    Serial.println(currentMillis[5]);



    //------------------Strand 1------------------/
    int k; 
    for(k = LEDsections[1]; k < endLED[1]; k++) {
      currentMillis[1] = millis();
      if(currentMillis[1] - stepTime[1] >= randomizer[1]) { //turn off LEDs 
        leds[LEDsections[1]].b = 0; 
        leds[LEDsections[1]].g = 0; 
        leds[LEDsections[1]].r = 0;

        LEDsections[1]++;
        //      Serial.println("LEDsections[1]");
        //      Serial.println(LEDsections[1]);


        if(LEDsections[1] == endLED[1]){
          LEDsections[1] = startLED[1];
        }

        leds[LEDsections[1]].b = 255; 
        leds[LEDsections[1]].g = 255; 
        leds[LEDsections[1]].r = 255;

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

        leds[LEDsections[2]].b = 255; 
        leds[LEDsections[2]].g = 255; 
        leds[LEDsections[2]].r = 255;

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

        leds[LEDsections[3]].b = 255; 
        leds[LEDsections[3]].g = 255; 
        leds[LEDsections[3]].r = 255;

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

        leds[LEDsections[4]].b = 255; 
        leds[LEDsections[4]].g = 255; 
        leds[LEDsections[4]].r = 255;

        stepTime[4] = currentMillis[4];

      }
    }
    //--------------Strand 4-----------------------//

    FastSPI_LED.show();
    Serial.println("LED's On ");

  }  
  else{

    int n;

    for(n = 0; n < NUM_LEDS; n++){
      memset(leds, 0, NUM_LEDS *3);
      leds[n].b = 0;
      leds[n].g = 0;
      leds[n].r = 0;
      n++;

      if( n == NUM_LEDS){
        n = 0;
      }

      FastSPI_LED.show();
      Serial.println("No people detected. ");
    }
  }



}















































