  const int greenledpin = 9;
  const int blueledpin = 10;
  const int redledpin = 11;

  const int tempSensorPin = A0;


  float weightedRed = 0;
  float weightedBlue = 0;
  float weightedTemp = 20;
  float redValue = 0;
  int greenValue = 0;
  float blueValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(greenledpin, OUTPUT);
  pinMode(blueledpin, OUTPUT);
  pinMode(redledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int sensorValue = analogRead(tempSensorPin);
  float voltage = (sensorValue/1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100;
  Serial.print("\n");
  Serial.print(weightedTemp);

  //30 grader = red
  //20 grader = blue
  weightedTemp = weightedTemp * 0.9 + temperature * 0.1;
  
  redValue = 51 * (weightedTemp - 20.0);
  
  if(redValue > 255)
    redValue = 255;
  else if(redValue < 10)
    redValue = 0;

  blueValue = 255 - redValue;
  if(blueValue < 10)
    blueValue = 0;


  
  Serial.print("\t Red value: ");
  Serial.print(weightedRed);
  Serial.print("\t Blue value: ");
  Serial.print(weightedBlue);

  weightedRed = weightedRed * 0.9 + redValue * 0.1;
  weightedBlue = weightedBlue * 0.9 + blueValue * 0.1;
  analogWrite(redledpin, weightedRed);
  //analogWrite(greenledpin, greenValue);
  analogWrite(blueledpin, weightedBlue);
  delay(50);
}
