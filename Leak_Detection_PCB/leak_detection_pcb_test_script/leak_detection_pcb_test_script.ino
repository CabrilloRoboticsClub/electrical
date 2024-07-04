#include <OneWire.h>
#include <Arduino.h>

int sensorPin = A0; // need to add AtoD conveter on next rev to clean things up
int sensorValue = 0;
int percent = 0;


int convertToPercent(int value);
void printValuesToSerial();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  percent = convertToPercent(sensorValue);
  printValuesToSerial();
  delay(1000);
}

int convertToPercent(int value) {
  int percentValue = map(value, 1023, 465, 0, 100);
  return percentValue;
}

void printValuesToSerial() {
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print(", Percent: ");
  Serial.println(percent);
}

