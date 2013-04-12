
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Blink Min/Max
  int maX = 35;          
  int miN = 1;

  for(int i = 0; i <= numStrands; i++) {
      
      // Set Random Speed
      speed[i] = random(blinkSpeed[miN],blinkSpeed[maX]);
      
      // Reset Current Millisecond
      currentMillis[i] = millis();
      
      for(int k = 0; k <= endLED[1]; k++) {   
        // Check & Reset LED Strand
        resetStrand(k, i);
      }
      
  } 

  // Light Them LEDs !!!
  FastSPI_LED.show();

} /* END OF LOOP */

