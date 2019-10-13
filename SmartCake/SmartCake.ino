// Icon images are stored in tabs ^ e.g. Alert.h etc above this line
// more than one icon can be in a header file

// Arrays containing FLASH images can be created with UTFT library tool:
// (libraries\UTFT\Tools\ImageConverter565.exe)
// Convert to .c format then copy into a new tab

/*
  This sketch demonstrates loading images from arrays stored in program (FLASH) memory.

  Works with TFT_eSPI library here:
  https://github.com/Bodmer/TFT_eSPI

  This sketch does not use/need any fonts at all...

  Code derived from ILI9341_due library example

  Make sure all the display driver and pin comnenctions are correct by
  editting the User_Setup.h file in the TFT_eSPI library folder.

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  #########################################################################
*/

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

// Include the header files that contain the icons

#include "Close.h"
#include "XT_DAC_Audio.h";
#include "BirthdaySong.h"

XT_DAC_Audio_Class DacAudio(25,0);    // Create the main player class object. 
                                      // Use GPIO 25, one of the 2 DAC pins and timer 0
                                      
                                      // create an object of type XT_Wav_Class that is used by 
                                      // the dac audio class (above), passing wav data as parameter.
XT_Wav_Class BirthdaySong(BirthdaySong_wav);   

unsigned long previousMillis = 0;  //will store last time LED was blinked
int led = 16;

void setup()
{
   pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
tft.begin();
  tft.setRotation(1);  // landscape

  tft.fillScreen(TFT_BLACK);

  // Swap the colour byte order when rendering
  tft.setSwapBytes(true);

  // Draw the icons
  
  

  // Pause here to admire the icons!
  
   //BirthdaySong.RepeatForever=true;  
 DacAudio.Play(&BirthdaySong); 
 
}

void loop()
{
  DacAudio.FillBuffer();
  unsigned long currentMillis = millis(); // store the current time
   
   
   if (currentMillis - previousMillis >= 1000 && currentMillis - previousMillis <= 2000){ 
   tft.pushImage(50, 50, closeWidth, closeHeight, close0);
   }
   if (currentMillis - previousMillis >= 2000 && currentMillis - previousMillis <= 4000) {
   tft.pushImage(50, 50, closeWidth, closeHeight, close1);
   }
   if (currentMillis - previousMillis >= 4000 && currentMillis - previousMillis <= 6000) {
   tft.pushImage(50, 50, closeWidth, closeHeight, close2);
   }
   if (currentMillis - previousMillis >= 6000 && currentMillis - previousMillis <= 8000) {
   tft.pushImage(50, 50, closeWidth, closeHeight, close3);
   }
   if (currentMillis - previousMillis >= 8000 && currentMillis - previousMillis <= 10000) {
   tft.pushImage(50, 50, closeWidth, closeHeight, close4);
   }
   if (currentMillis - previousMillis >= 10000 && currentMillis - previousMillis <= 12000) {
   digitalWrite(led, LOW);
   }

  // Loop filling and clearing screen
 
}
