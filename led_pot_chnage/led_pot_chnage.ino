void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue = analogRead(A0);
  int ledValue = map(potValue, 0, 1023, 0, 1500);
  analogWrite(9, ledValue);
  Serial.println("Potetiometer value: ");
  Serial.println(potValue);
  Serial.println("LED Output Value: ");
  Serial.println(ledValue);
  delay(2);
}
