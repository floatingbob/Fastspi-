
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Current
  currentMillis[1] = millis();
  currentMillis[2] = millis();
  currentMillis[3] = millis();
  currentMillis[4] = millis();
  currentMillis[5] = millis();
  currentMillis[6] = millis();
  currentMillis[7] = millis();
  currentMillis[8] = millis();

  // Blink Min/Max
  int maX = 35;          
  int miN = 1;
  
  // Blink Speed
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
  };

  int k;
  for(k = 0; k <= endLED[1]; k++) {

    // Strand 1
    if (k >= endLED[1]){
      //      t[1] = s[1];
      //      t[2] = s[2];
      //      t[3] = s[3];
      //      t[4] = s[4];
      //      t[5] = s[5];
      //      t[6] = s[6];
      //      t[7] = s[7];
      //      t[8] = s[8];
    }

    if(currentMillis[1] - stepTime[1] >= t[1]) {
      // Black
      leds[LEDsections[1]].r = 0;
      leds[LEDsections[1]].g = 0;
      leds[LEDsections[1]].b = 0;
      Serial.println(randNumber);
      
      LEDsections[1]++;

      // Start Over
      if(LEDsections[1] == endLED[1]){
        LEDsections[1] = startLED[1];
        t[1] = s[1];
        Serial.println(s[1]);
      }

      // White
      leds[LEDsections[1]].r = 255;
      leds[LEDsections[1]].g = 255;
      leds[LEDsections[1]].b = 255;
      stepTime[1] = currentMillis[1];
    }

    // Strand 2
    if (k >= endLED[2]){
      t[2] = s[2];
    }

    if(currentMillis[2] - stepTime[2] >= t[2] ){
      leds[LEDsections[2]].r = 0;
      leds[LEDsections[2]].g = 0;
      leds[LEDsections[2]].b = 0;
      
      LEDsections[2]++;

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

    // Strand 3
    if (k >= endLED[3]){
      t[3] = s[3];
    }
    
    if(currentMillis[3] - stepTime[3] >= t[3] ){
      leds[LEDsections[3]].r = 0;
      leds[LEDsections[3]].g = 0;
      leds[LEDsections[3]].b = 0;

      LEDsections[3]++;

      if(LEDsections[3] == endLED[3]){
        LEDsections[3] = startLED[3];
        t[3] = s[3];
      }

      leds[LEDsections[3]].r = 255;
      leds[LEDsections[3]].g = 255;
      leds[LEDsections[3]].b = 255;

      stepTime[3] = currentMillis[3];
    }
    
    // Strand 4
    if (k >= endLED[4]){
      t[4] = s[4];
    }

    if(currentMillis[4] - stepTime[4] >=t[4] ){
      leds[LEDsections[4]].r = 0;
      leds[LEDsections[4]].g = 0;
      leds[LEDsections[4]].b = 0;
      
      LEDsections[4]++;

      if(LEDsections[4] == endLED[4]){
        LEDsections[4] = startLED[4];
        t[4] = s[4];
      }

      leds[LEDsections[4]].r = 255;
      leds[LEDsections[4]].g = 255;
      leds[LEDsections[4]].b = 255;

      stepTime[4] = currentMillis[4];
    }
    
    // Strand 5
    if (k >= endLED[5]){
      t[5] = s[5];
    }
    
    if(currentMillis[5] - stepTime[5] >= t[5] ){
      leds[LEDsections[5]].r = 0;
      leds[LEDsections[5]].g = 0;
      leds[LEDsections[5]].b = 0;
      
      LEDsections[5]++;

      if(LEDsections[5] == endLED[5]){
        LEDsections[5] = startLED[5];
        t[5] = s[5];
      }

      leds[LEDsections[5]].r = 255;
      leds[LEDsections[5]].g = 255;
      leds[LEDsections[5]].b = 255;

      stepTime[5] = currentMillis[5];
    }
    
    // Strand 6
    if (k >= endLED[6]){
      t[6] = s[6];
    }

    if(currentMillis[6] - stepTime[6] >= t[6] ){
      leds[LEDsections[6]].r = 0;
      leds[LEDsections[6]].g = 0;
      leds[LEDsections[6]].b = 0;

      LEDsections[6]++;

      if(LEDsections[6] == endLED[6]){
        LEDsections[6] = startLED[6];
        t[6] = s[6];
      }

      leds[LEDsections[6]].r = 255;
      leds[LEDsections[6]].g = 255;
      leds[LEDsections[6]].b = 255;

      stepTime[6] = currentMillis[6];
    }
    
    // Strand 7
    if (k >= endLED[7]){
      t[7] = s[7];
    }
    
    if(currentMillis[7] - stepTime[7] >= t[7] ){
      leds[LEDsections[7]].r = 0;
      leds[LEDsections[7]].g = 0;
      leds[LEDsections[7]].b = 0;

      LEDsections[7]++;

      if(LEDsections[7] == endLED[7]){
        LEDsections[7] = startLED[7];
        t[7] = s[7];
      }

      leds[LEDsections[7]].r = 255;
      leds[LEDsections[7]].g = 255;
      leds[LEDsections[7]].b = 255;

      stepTime[7] = currentMillis[7];
    }
    
    // Strand 8
    if (k >= endLED[8]){
      t[8] = s[8];
    }
    
    if(currentMillis[8] - stepTime[8] >= t[8] ){
      leds[LEDsections[8]].r = 0;
      leds[LEDsections[8]].g = 0;
      leds[LEDsections[8]].b = 0;

      LEDsections[8]++;

      if(LEDsections[8] == endLED[8]){
        LEDsections[8] = startLED[8];
        t[8] = s[8];
      }

      leds[LEDsections[8]].r = 255;
      leds[LEDsections[8]].g = 255;
      leds[LEDsections[8]].b = 255;

      stepTime[8] = currentMillis[8];
    }
    
  } /* end of for */

  FastSPI_LED.show();

} /* END OF LOOP */

