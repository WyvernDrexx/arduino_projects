void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  Serial.println(reading);
  int thisPitch = map(reading, 400, 1000, 300,1500);
  tone(8,thisPitch * 10, 10);
  delay(1);
}
