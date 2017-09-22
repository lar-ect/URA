#include "Arduino.h"
#include "SensorLinha.h"

SensorLinha::SensorLinha(int sensor) {
  _sensor = sensor;

  _l = 700;

}

bool SensorLinha::detectedBySensor() {


  if (analogRead(_sensor) > _l)
    return true;

  else
    return false;


}

int SensorLinha::debug() {

  Serial.print("Sensor: ");
  Serial.println( analogRead(_sensor) );

}



void SensorLinha::setLimiar(int l) {
  _l = l;
}


