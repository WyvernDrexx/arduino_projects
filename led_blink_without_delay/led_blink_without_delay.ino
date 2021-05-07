const int ledPinOne = LED_BUILTIN;
const int ledPinTwo = 12;

int ledState = LOW;
int ledStateTwo = HIGH;

unsigned long prevMillis = 0;

const int interval = 300; //Milliseconds

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPinOne, OUTPUT);
  pinMode(ledPinTwo, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();
  if(currentMillis - prevMillis >= interval){
    if(ledState){
      ledState = LOW;  
      ledStateTwo = HIGH;
    } else {
      ledState = HIGH;  
      ledStateTwo = LOW;
    }
    prevMillis = currentMillis;
    digitalWrite(ledPinOne, ledState);
    digitalWrite(ledPinTwo, ledStateTwo);
  }
  
}
