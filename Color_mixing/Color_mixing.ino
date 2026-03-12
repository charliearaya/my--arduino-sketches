  const int greenledpin = 9;
  const int blueledpin = 10;
  const int redledpin = 11;

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
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(greenledpin, OUTPUT);
  pinMode(blueledpin, OUTPUT);
  pinMode(redledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
redSensorValue = analogRead(redSensorPin);
delay(5);
 greenSensorValue = analogRead(greenSensorPin);
delay(5);
 blueSensorValue = analogRead(blueSensorPin);
delay(5);


  Serial.print("\nRaw Sensor Values \t red: ");
  Serial.print(redSensorValue);
  Serial.print("\t greed: ");
  Serial.print(greenSensorValue);
  Serial.print("\t blue: ");
  Serial.print(blueSensorValue);
  

  redValue = redSensorValue/4;
  blueValue = blueSensorValue/4;
  greenValue = greenSensorValue/4;


  Serial.print("\nMapped Sensor Values \t red: ");
  Serial.print(redValue);
  Serial.print("\t green: ");
  Serial.print(greenValue);
  Serial.print("\t blue: ");
  Serial.print(blueValue);

  analogWrite(redledpin, redValue);
  analogWrite(greenledpin, greenValue);
  analogWrite(blueledpin, blueValue);
  //delay(1000);
}
