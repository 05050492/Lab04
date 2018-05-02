#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {8,9,10,11,12,13,14,15};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  pinMode(6,INPUT);
}

void loop() 
{
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  boolean val=digitalRead(6);
  if(val)
  {
    sevseg.setNumber(0000, 0);
        sevseg.refreshDisplay();
        deciSeconds=0;
  }
  else
  {
 sevseg.setNumber(deciSeconds, 0);
  if (millis() - timer >= 300) 
  {
    timer += 300;
    deciSeconds++; 
    if (deciSeconds%100 == 59) 
    { 
      deciSeconds=deciSeconds+41;
    }
    else
    {
      deciSeconds=deciSeconds+1;
    }
   if (deciSeconds == 2400)
    deciSeconds =0 ;
  }
 
  sevseg.refreshDisplay(); // Must run repeatedly
  }
}
