
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

  for(int i = 0; i <= numStrands; i++) {
    // Modular !!
    resetStrand(i);
  } 

  FastSPI_LED.show();

} /* END OF LOOP */

