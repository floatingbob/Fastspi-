
//---------------------------------------------------------------//
// LOOP

void loop() {
  
  // Blink Min/Max
  int maX = 35;          
  int miN = 1;
  
  // Blink Speed
  int speed[9] = {
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
    
    // Reset Current Millisecond
    currentMillis[i] = millis();
    
    // Check & Reset LED Strand
    resetStrand(i);
    
  } 

  // Light Them LEDs !
  FastSPI_LED.show();

} /* END OF LOOP */

