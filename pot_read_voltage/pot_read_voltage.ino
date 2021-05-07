void setup() {
  Serial.begin(9600);

}
float prev = 0.0;
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  if( prev != voltage ){
    Serial.println("Voltage: ");
    Serial.println(voltage);  
    prev = voltage;
  }
}
