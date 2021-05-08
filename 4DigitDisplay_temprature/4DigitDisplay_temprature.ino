#include "SevSeg.h"
#include "DHT.h"
#include "math.h"

#define DHT_PIN A0

#define DHT_TYPE 11

unsigned long previousMillis = 0;
float temprature = -400.00;
const int interval = 2000;

SevSeg sevseg; //Initiate a seven segment controller object
DHT dht(DHT_PIN, DHT_TYPE);

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
  pinMode(DHT_PIN, INPUT_PULLUP);
  dht.begin();
}
void loop() {
  char temp[7];
  unsigned long currentMillis = millis();
  sevseg.refreshDisplay(); // Must run repeatedly
  if ( currentMillis - previousMillis > interval ) {
    previousMillis = currentMillis;
    temprature = getTemprature();
    dtostrf(temprature, 4, 2, temp);
  }
  if ( temprature == -400.00 ) {
    sevseg.setChars("LOAD");
  } else {
    sevseg.setChars(temp);
  }
}

float getTemprature() {
  float t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return 0;
  }
  return t;
}
