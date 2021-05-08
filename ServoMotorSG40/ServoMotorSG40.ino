#include <Servo.h>

Servo servo;

int pos = 0;    // variable to store the servo position

void setup() {
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  servo.write(0);
}


// Servo Motor, which will return to 0 degree after exactly 1 minute, every 1 second is 6 degrees.


void loop() {
  //First 30 seconds, 180/6 = 30 seconds, forward
  for (pos = 0; pos <= 180; pos += 6) {
    servo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(1000);                       // waits 1000ms for it to reach
  }
  // Next 30 seconds, backwards..
  for (pos = 180; pos >= 0; pos -= 6) { 
    servo.write(pos);              
    delay(1000);                       
  }
}
