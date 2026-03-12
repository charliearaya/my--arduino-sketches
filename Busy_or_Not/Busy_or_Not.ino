/*
  Busy or Not
  Uses a button on pin 13 to toggle a servo on pin 9 between two positions.
  Each press flips the indicator between an idle angle and a busy angle to
  create a simple mechanical status sign.
*/

// Pushbutton
// Pin 13 -- button -- 5V
// GND connection depends on whether you use an external pull-down resistor.
//
// Servo
// Pin 9 -- signal
// 5V ---- VCC
// GND --- GND

#include <Servo.h>
Servo myServo;

const int buttonPin = 13;
const int servoPin = 9;
const int idleAngle = 0;
const int busyAngle = 175;

bool busy = false;
bool isPressing = false;

void turn() {
  busy = !busy;
  myServo.write(busy ? busyAngle : idleAngle);
  delay(300);
}

void setup() {
  myServo.attach(servoPin);
  pinMode(buttonPin, INPUT);
  myServo.write(idleAngle);
}

void loop() {
  if (digitalRead(buttonPin)) {
    if (!isPressing) {
      isPressing = true;
      turn();
    }
  }
  else {
    isPressing = false;
  }

  delay(10);
}
