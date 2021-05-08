#include "DHT.h"

#define DHT_PIN A0

#define DHT_TYPE 11

/*

  First Pin: +ve
  Second Pin: Signal/Output Pin (Pin 2)
  Third Pin: No connection
  Fourth Pin: Ground / -ve
*/

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  pinMode(DHT_PIN, INPUT_PULLUP);
  dht.begin();
}

void loop() {

  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index
  // Must send in temp in Fahrenheit!
  float hi = dht.computeHeatIndex(f, h);

  Serial.println("Humidity: " + String(h, 2) + "%");
  Serial.println("Temperature: " + String(t) + " *C | " + String(f) + " *F");
  //  Serial.print(f);
  //  Serial.print(" *F\t");
  Serial.println("Heat index: " + String(hi));
}
