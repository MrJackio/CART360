//  FRIMPO's ARDUINO CODE  //
// BY: JACK HARRISON
//The code is quite simple but when combined with the tracker and Unity becomes a complex set of interactions

int L1sensorPin = A1;        //Frimpo's Mouth sensor
int L2sensorPin = A2;        //Frimpo's Eye sensor
int P1sensorPin = A0;        //Squeeze Frimpo sensor
int ledPin = 13;              //LED for troubleshooting
int LightSensorValue1 = 0;    //Frimpo's Mouth value
int LightSensorValue2 = 0;    //Frimpo's Eye value
int PressureSensorValue = 0;   //Frimpo's Squeeze value

void setup() {

  pinMode(ledPin, OUTPUT); //Output for LED for Troubleshooting
  Serial.begin(9600);
  //Outputs for Vive Tracker
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

}

void loop() {
  // read the value from the sensors (for troubleshooting):
  // Serial.print(LightSensorValue1);
  // Serial.print(LightSensorValue2);
  // Serial.print(PressureSensorValue);

  LightSensorValue1 = analogRead(L1sensorPin);
  LightSensorValue2 = analogRead(L2sensorPin);
  PressureSensorValue = analogRead(P1sensorPin);

//Ideally for these I would use Average Function's, but ran out of time before implimenting 

  //LIGHT SENSOR 1 (Frimpo's Mouth)
  if (LightSensorValue1 < 8) {
    //Send ON to tracker, power on LED for troubleshooting
    digitalWrite(11, HIGH);
    digitalWrite(4, LOW);
  } else {
    //Don't activate Tracker, don't turn on LED
    digitalWrite(11, LOW);
    digitalWrite(4, HIGH);
  }
  
  //LIGHT SENSOR 2 (Frimpo's Eye)
  if (LightSensorValue2 < 16) {
    digitalWrite(11, HIGH);
    digitalWrite(5, LOW);
  } else {
    digitalWrite(11, LOW);
    digitalWrite(5, HIGH);
  }

  //PRESURE SENSOR (Frimpo's Body)
  if (PressureSensorValue > 12) {
    digitalWrite(11, HIGH);
    digitalWrite(6, LOW);
  } else {
    digitalWrite(11, LOW);
    digitalWrite(6, HIGH);
  }
}
