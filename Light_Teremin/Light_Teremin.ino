int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

const int ledPin = 13;
const int piezoPin = 7;
const int photoPin = A5;


void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  while(millis() < 5000){
    sensorValue = analogRead(photoPin);
    if(sensorValue > sensorHigh)
      sensorHigh = sensorValue;

    if(sensorValue < sensorLow)
      sensorLow = sensorValue;
  }

  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  

}

void loop() {
  sensorValue = analogRead(photoPin);

  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
  Serial.println(pitch);

  if(pitch < 0)
    noTone(piezoPin);
  else
    tone(piezoPin, pitch, 20);
  
  delay(10);

}
