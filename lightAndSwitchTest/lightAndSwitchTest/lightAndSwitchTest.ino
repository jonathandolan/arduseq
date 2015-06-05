

#include <Wire.h>
#include <Adafruit_Trellis.h>
#include <Adafruit_UNTZtrument.h>

#define LED 13 // Pin for heartbeat LED (shows code is working)


Adafruit_Trellis     T[4];
Adafruit_UNTZtrument untztrument(&T[0], &T[1], &T[2], &T[3]);
const uint8_t        addr[] = { 0x70, 0x71, 0x72, 0x73 };

void setup() {
  pinMode(LED, OUTPUT);
  untztrument.begin(addr[0], addr[1], addr[2], addr[3]);
  untztrument.clear();
  untztrument.writeDisplay();

}


void loop() {
 int i = 0;
 for (i = 0; i < 64; i++){
   untztrument.setLED(i);
   untztrument.writeDisplay();
   delay(500);
   
 }
 
 untztrument.clear();
 untztrument.writeDisplay();
 
 while (true){
  untztrument.readSwitches();
 for (int i = 0; i < 64; i++){
  if (untztrument.justPressed(i)){
   untztrument.setLED(i);
  } 
 }
 untztrument.writeDisplay();
 }
}
