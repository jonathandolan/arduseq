#include <MIDI.h>
#include <midi_Defs.h>
#include <midi_Message.h>
#include <midi_Namespace.h>
#include <midi_Settings.h>
#include <Wire.h>
#include <Adafruit_Trellis.h>
#include <Adafruit_UNTZtrument.h>

Adafruit_Trellis     T[4];
Adafruit_UNTZtrument untztrument(&T[0], &T[1], &T[2], &T[3]);
const uint8_t        addr[] = { 0x70, 0x71, 0x72, 0x73 };

MIDI_CREATE_DEFAULT_INSTANCE();

int noteNums[] = {87, 88, 89, 90, 
                  82, 83, 84, 85, 
                  77, 78, 79, 80,
                  72, 73, 74, 75,

                  91, 92, 93, 94,
                  86, 87, 88, 89,
                  81, 82, 83, 84,
                  76, 77, 78, 79,

                  67, 68, 69, 70,
                  62, 63, 64, 65,
                  57, 58, 59, 60,
                  52, 53, 54, 55,

                  71, 72, 73, 74,
                  66, 67, 68, 69,
                  61, 62, 63, 64,
                  56, 57, 58, 59};

void setup() {
  untztrument.begin(addr[0], addr[1], addr[2], addr[3]);
  untztrument.clear();
  untztrument.writeDisplay();

}


void loop() {
  if (untztrument.readSwitches()){
   for (int i = 0; i < 64; i++){
    if (untztrument.justPressed(i)){
     MIDI.sendNoteOn(noteNums[i], 127, 1);
    untztrument.setLED(i); 
    } else if (untztrument.justReleased(i)){
     MIDI.sendNoteOff(noteNums[i], 127, 1);
    untztrument.clrLED(i); 
    }
    untztrument.writeDisplay();
   } 
  }
}
