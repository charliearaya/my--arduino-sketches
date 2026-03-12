/*
  Color Mixing
  Reads three analog channels from red, green, and blue inputs and maps
  them directly to an RGB LED on pins 11, 9, and 10. Raw sensor values and
  the scaled PWM output values are printed to the serial monitor.
*/

// Analog color inputs
// A0 ---- red control input
// A1 ---- green control input
// A2 ---- blue control input
// Each input should be wired as an analog voltage source, such as a potentiometer.
//
// RGB LED outputs
// Pin 11 --- resistor --- red LED channel
// Pin 9 ---- resistor --- green LED channel
// Pin 10 --- resistor --- blue LED channel
// RGB LED common leg goes to GND for a common-cathode LED.

const int greenLedPin = 9;
const int blueLedPin = 10;
const int redLedPin = 11;

const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int greenValue = 0;
int blueValue = 0;

int redSensorValue = 0;
int greenSensorValue = 0;
int blueSensorValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);
  delay(5);


  Serial.print("\nRaw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.print(blueSensorValue);

  redValue = redSensorValue / 4;
  blueValue = blueSensorValue / 4;
  greenValue = greenSensorValue / 4;


  Serial.print("\nMapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);

  analogWrite(redLedPin, redValue);
  analogWrite(greenLedPin, greenValue);
  analogWrite(blueLedPin, blueValue);
}
