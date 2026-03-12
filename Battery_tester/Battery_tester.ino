/*
  Battery Tester
  Measures a CR2032 battery through a voltage divider on A0 using the
  internal analog reference. Three LEDs indicate whether the battery is
  good, usable, or low, and the measured voltage is printed over serial.
*/

// CR2032 (+)
//     |
//    R1  (10k)
//     |
//     +-------> A0   (Arduino measures here)
//     |
//    R2  (4.7k)
//     |
// CR2032 (−) ---------> GND (Arduino)

// Pin 8  ---- resistor (220Ω) ----|>|---- GND   (Green LED)
// Pin 9  ---- resistor (220Ω) ----|>|---- GND   (Yellow LED)
// Pin 10 ---- resistor (220Ω) ----|>|---- GND   (Red LED)

const int batteryPin = A0;

const int ledGood = 8;
const int ledOk = 9;
const int ledLow = 10;

// divider ratio calculation
const float R1 = 10000.0;
const float R2 = 4700.0;
const float dividerFactor = (R1 + R2) / R2;

void setup() {

  analogReference(INTERNAL);   // use 1.1V reference

  pinMode(ledGood, OUTPUT);
  pinMode(ledOk, OUTPUT);
  pinMode(ledLow, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int raw = analogRead(batteryPin);

  float voltageAtPin = raw * (1.1 / 1023.0);
  float batteryVoltage = voltageAtPin * dividerFactor;

  Serial.println(batteryVoltage);

  digitalWrite(ledGood, LOW); // Brand new CR2032 → 3.0 – 3.3 V
  digitalWrite(ledOk, LOW); // Used → 2.7 – 3.0 V
  digitalWrite(ledLow, LOW); // Weak → 2.5 – 2.7 V

  if (batteryVoltage >= 3.0) {
    digitalWrite(ledGood, HIGH);
  }
  else if (batteryVoltage >= 2.7) {
    digitalWrite(ledOk, HIGH);
  }
  else if (batteryVoltage >= 0.1) {
    digitalWrite(ledLow, HIGH);
  }

  delay(800);
}
