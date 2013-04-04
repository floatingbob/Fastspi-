
//---------------------------------------------------------------//
// SETUP

void setup() {
  
  // FastSPI Setup
  FastSPI_LED.setLeds(NUM_LEDS);
  FastSPI_LED.setChipset(CFastSPI_LED::SPI_TM1809);
  FastSPI_LED.setPin(outputPin);
  
  // FastSPI Init & Start
  FastSPI_LED.init();
  FastSPI_LED.start();

  leds = (struct CRGB*)FastSPI_LED.getRGBData(); 

  // Serial Begin
  Serial.begin(9600);

  randomSeed(analogRead(0));

} /* END OF SETUP */
