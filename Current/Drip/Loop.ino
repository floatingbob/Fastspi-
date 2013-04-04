
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Blink Min/Max
  int maX = 35;          
  int miN = 1;


  // #FTW
  for(int i = 0; i <= numStrands; i++) {
    
    // Delay
    randomizer[i] = delayLED[i] + random(1, 100);
    
    // Set Random Speed
    speed[i] = random(blinkSpeed[miN],blinkSpeed[maX]);
    
    // Reset Current Millisecond
    currentMillis[i] = millis();
    
    // Check & Reset LED Strand
    resetStrand(i);
    
  } 

  // Light Them LEDs !!!
  FastSPI_LED.show();

} /* END OF LOOP */

