#include <Servo.h>
Servo myServo;

int const buttonPin = 13;
bool busy = 0;
bool pressing = 0;

void setup() {
  myServo.attach(9);
  pinMode(buttonPin, INPUT);
  myServo.write(0);
}

void loop() {
  if(digitalRead(buttonPin)){
    if(!pressing){
      pressing = 1;
      turn();
    }
  }
  else{
    pressing = 0;
  }
  
  delay(10);
}

void turn(){
  busy = !busy;
  myServo.write(175 * busy);
  delay(300);
}
