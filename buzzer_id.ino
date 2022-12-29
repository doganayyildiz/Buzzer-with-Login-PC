#include <Keyboard.h>
const int ledPin = 3;
const int knockSensor = A0;
const int thresold = 1;
int counter = 0;
int sensorReading = 0;
int ledState = LOW;
int counter=0;

void setup() {
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
Keyboard.begin();
}

void loop() {

sensorReading = analogRead(knockSensor);
Serial.println(sensorReading);
if (sensorReading >=thresold){
  ledState = !ledState;
  digitalWrite(ledPin,ledState);
  Serial.println("knock");
  counter++;
  if (counter ==8){
    Keyboard.print("enter_the_ loginkey");
    Keyboard.press(176);
    Keyboard.releaseAll();
    counter=0;
  }  
}

delay(50);
}
