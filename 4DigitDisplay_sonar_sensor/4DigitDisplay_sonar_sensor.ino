#include "SevSeg.h"
#include "math.h"
#include "pitches.h"

#define MICROPHONE_PIN A0   // This is the ECHO pin
#define SPEAKER_PIN A1      // This is the TRIG pin

#define SOUND_PIN A2

unsigned long previousMillis = 0;
unsigned long tonePreviousMillis = 0;

const int interval = 1000;
const int toneInterval = 100 * 1.30;
long distanceInCM = 0;
SevSeg sevseg; //Initiate a seven segment controller object


void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5,};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = 0;
  // variable above indicates that 4 resistors were placed on the digit pins.
  // set variable to 1 if you want to use 8 resistors on the segment pins.
  sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  Serial.begin(9600);
  pinMode(MICROPHONE_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
}
void loop() {
  long pulseTime;
  unsigned long currentMillis = millis();
  sevseg.setNumber(distanceInCM);
  sevseg.refreshDisplay(); // Must run repeatedly
  if ( currentMillis - previousMillis > interval ) {
    previousMillis = currentMillis;
    digitalWrite(SPEAKER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(SPEAKER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(SPEAKER_PIN, LOW);
    pulseTime = pulseIn(MICROPHONE_PIN, HIGH);
    distanceInCM = (pulseTime / 29) / 2;
    tone(SOUND_PIN, NOTE_D8, 100);
    tonePreviousMillis = millis();
    return;
  }

  if(currentMillis - tonePreviousMillis > toneInterval){
    noTone(SOUND_PIN);
  }

}
