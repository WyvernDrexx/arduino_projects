//LED Blink using input from Button

const int ledPin = 13;
const int buttonPin = 2;

int buttonState;
int lastButtonState= 0 ;
int ledState = 1;

unsigned long lastDebounceTime = 0;
unsigned long lastDebounceDelay = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, ledState);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(buttonPin);

  if(buttonState != lastButtonState){
    lastDebounceTime = millis();
  }

  if(millis() - lastDebounceTime > lastDebounceDelay ){
    if(reading != buttonState){
      buttonState = reading;
      if(buttonState){
      ledState = !ledState;  
    }
    }
    
  }
  
  
  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}
