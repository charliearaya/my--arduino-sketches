/*
  Mood Cue
  Reads a potentiometer on A0 and maps that value to a servo angle.
  The servo on pin 9 follows the knob position, and the serial monitor
  prints both the raw sensor value and the mapped angle.
*/

#include <Servo.h>
Servo myServo;

int const potPin = A0;
int potVal;
int angle;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  Serial.print("\npotVal: ");
  Serial.print(potVal);

  angle = map(potVal, 0 , 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.print(angle);

  myServo.write(angle);
  delay(15);

}
