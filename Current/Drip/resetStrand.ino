
//---------------------------------------------------------------//
// RESET

void resetStrand(int index) {
  
  if (k >= endLED[index]){
    t[index] = s[index];
  }
  
  if(currentMillis[index] - stepTime[index] >= t[index] ){
    leds[LEDsections[index]].r = 0;
    leds[LEDsections[index]].g = 0;
    leds[LEDsections[index]].b = 0;

    LEDsections[index]++;

    if(LEDsections[index] == endLED[index]){
      LEDsections[index] = startLED[index];
      t[index] = s[index];
    }

    leds[LEDsections[index]].r = 255;
    leds[LEDsections[index]].g = 255;
    leds[LEDsections[index]].b = 255;

    stepTime[index] = currentMillis[index];
  }
  
  
}
