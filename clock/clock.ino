#include "SevSeg.h"
int h=0, m=0;
SevSeg sevseg; //Initiate a seven segment controller object
void setup() {
byte numDigits = 4;
byte digitPins[] = {2,3,4,5};
byte segmentPins[] = {8,9,10,11,12,13,14,15};
sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = millis();
  static int m = 59;
  static int h = 23;
  
  if (millis()>=timer)
  {
    timer += 10;
    if(++m>=60)
    {
      m=0;
      
      if(++h>=24)
         h=0;
     }
    sevseg.setNumber(h*100+m);
  }
    sevseg.refreshDisplay(); // Must run repeatedly 
  }






 
