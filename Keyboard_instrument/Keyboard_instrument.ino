/*
  Keyboard Instrument
  Reads an analog resistor ladder on A0 and plays one of four notes
  through a buzzer on pin 7. The serial monitor shows the current
  analog reading to help tune the key ranges.
*/

// Button ladder / analog keyboard
// 5V ---- button network with different resistor paths ---- A0
// GND --- common return for the button network
//
// Piezo buzzer
// Pin 7 -- positive lead
// GND ---- negative lead

const int buzzerPin = 7;
const int keyboardPin = A0;

const int notes[] = {262, 294, 330, 349};

int noteIndexForReading(int keyVal) {
  if (keyVal >= 1018) {
    return 0;
  }

  if (keyVal >= 990 && keyVal <= 1010) {
    return 1;
  }

  if (keyVal >= 505 && keyVal <= 515) {
    return 2;
  }

  if (keyVal >= 5 && keyVal <= 10) {
    return 3;
  }

  return -1;
}


void setup() {
  Serial.begin(9600);
}

void loop() {
  int keyVal = analogRead(keyboardPin);
  int noteIndex = noteIndexForReading(keyVal);

  Serial.println(keyVal);

  if (noteIndex >= 0) {
    tone(buzzerPin, notes[noteIndex]);
  }
  else {
    noTone(buzzerPin);
  }
}
