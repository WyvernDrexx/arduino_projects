#include "pitches.h"

#define MICROPHONE_PIN 13   // This is the ECHO pin
#define SPEAKER_PIN 12      // This is the TRIG pin

#define SOUND_PIN 8

void setup() {
  // put your setup code here, to run once:
  pinMode(MICROPHONE_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long pulseTime;
  digitalWrite(SPEAKER_PIN, LOW);
  delay(2);
  digitalWrite(SPEAKER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SPEAKER_PIN, LOW);
  pulseTime = pulseIn(MICROPHONE_PIN, HIGH);
  long distanceInCM = (pulseTime / 29) / 2;
  int duration = map(distanceInCM, 2, 3000, 80, 1000);
  Serial.println(duration);
  tone(SOUND_PIN, NOTE_D8, duration);
  delay((duration)*1.30);
  Serial.println(distanceInCM);
  noTone(SOUND_PIN);
}
