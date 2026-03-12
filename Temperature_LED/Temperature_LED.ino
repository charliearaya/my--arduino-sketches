/*
  Temperature LED
  Reads a temperature sensor on A0 and blends two LEDs to show the result.
  Cooler temperatures drive the blue LED, warmer temperatures drive the red
  LED, and the serial monitor prints the smoothed temperature and output values.
*/

const int greenLedPin = 9;
const int blueLedPin = 10;
const int redLedPin = 11;

const int tempSensorPin = A0;

const float minTemperatureC = 20.0;
const float maxTemperatureC = 25.0;
const float smoothingFactor = 0.1;

float weightedRed = 0;
float weightedBlue = 0;
float weightedTemp = minTemperatureC;

float clampToByte(float value) {
  if (value < 0) {
    return 0;
  }

  if (value > 255) {
    return 255;
  }

  return value;
}

void setup() {
  Serial.begin(9600);

  pinMode(greenLedPin, OUTPUT);
  pinMode(blueLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(tempSensorPin);
  float voltage = (sensorValue / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;
  float redValue;
  float blueValue;

  // 20 C maps to blue and 25 C maps to red.
  weightedTemp = weightedTemp * (1.0 - smoothingFactor) + temperature * smoothingFactor;

  redValue = 255.0 * (weightedTemp - minTemperatureC) / (maxTemperatureC - minTemperatureC);
  redValue = clampToByte(redValue);
  if (redValue < 10) {
    redValue = 0;
  }

  blueValue = 255 - redValue;
  if (blueValue < 10) {
    blueValue = 0;
  }

  weightedRed = weightedRed * (1.0 - smoothingFactor) + redValue * smoothingFactor;
  weightedBlue = weightedBlue * (1.0 - smoothingFactor) + blueValue * smoothingFactor;

  Serial.print("\nTemp C: ");
  Serial.print(weightedTemp);
  Serial.print("\t Red value: ");
  Serial.print(weightedRed);
  Serial.print("\t Blue value: ");
  Serial.print(weightedBlue);

  analogWrite(redLedPin, weightedRed);
  analogWrite(blueLedPin, weightedBlue);
  delay(50);
}
