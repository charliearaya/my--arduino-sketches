/*
  Light Theremin
  Calibrates a photoresistor on A5 for five seconds, then maps light levels
  to pitch on a piezo buzzer on pin 7. The LED on pin 13 stays on during
  calibration, and the current pitch is printed to the serial monitor.
*/

int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;
const int piezoPin = 7;
const int photoPin = A5;

int calibratedPitch(int sensorReading) {
  if (sensorHigh <= sensorLow) {
    return 0;
  }

  return map(sensorReading, sensorLow, sensorHigh, 50, 4000);
}

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while (millis() < 5000) {
    sensorValue = analogRead(photoPin);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }

    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(photoPin);

  int pitch = calibratedPitch(sensorValue);
  Serial.println(pitch);

  if (pitch <= 0) {
    noTone(piezoPin);
  }
  else {
    tone(piezoPin, pitch, 20);
  }

  delay(10);
}
