#include "DHT.h"

#define DHT_PIN 2

#define DHT_TYPE 11

DHT dht(DHT_PIN, DHT_TYPE);

void setup(){
  Serial.begin(9600);  
  pinMode(DHT_PIN, INPUT_PULLUP);
  dht.begin();
}

void loop(){
  
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

  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ["); 
  Serial.print(t);
  Serial.print(" *C ] [");
  Serial.print(f);
  Serial.print(" *F]\t");
  Serial.print("Heat index: ");
  Serial.print(hi);
  Serial.println(" *F");
  }
