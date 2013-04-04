
//---------------------------------------------------------------//
// RESET

void resetStrand(int index) {
  
  // Is It At the End ?? Then Reset
  if (index >= endLED[index]){
    //timer[index] = speed[index];
  }
  
  // Is Our Timer Ready To Switch ?? 
  if(currentMillis[index] - stepTime[index] >= timer[index]) {
    
    // Turn The LEDs Black
    leds[LEDsections[index]].r = 0;
    leds[LEDsections[index]].g = 0;
    leds[LEDsections[index]].b = 0;

    // Increment
    LEDsections[index]++;

    // Go Back To The Beginning
    if(LEDsections[index] == endLED[index]){
      LEDsections[index] = startLED[index];
      //timer[index] = speed[index];
    }

    // Turn The LEDs White
    leds[LEDsections[index]].r = 255;
    leds[LEDsections[index]].g = 255;
    leds[LEDsections[index]].b = 255;

    // Reset Our Timer
    stepTime[index] = currentMillis[index];
  }
  
  
}
