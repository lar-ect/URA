#include "Arduino.h"
#include "SensorLinha.h"

SensorLinha::SensorLinha(int leftSensor) {
  _LeftSensor = leftSensor;
  pinMode(_LeftSensor, INPUT);


}

SensorLinha::SensorLinha(int leftSensor, int rightSensor) {
  _LeftSensor = leftSensor;
  _RightSensor = rightSensor;

  pinMode(_LeftSensor, INPUT);
  pinMode(_RightSensor, INPUT);
}


SensorLinha::SensorLinha(int leftSensor, int middleSensor, int rightSensor) {
  _LeftSensor = leftSensor;
  _MiddleSensor = middleSensor;
  _RightSensor = rightSensor;

  pinMode(_LeftSensor, INPUT);
  pinMode(_MiddleSensor, INPUT);
  pinMode(_RightSensor, INPUT);
}

bool SensorLinha::detectedByLeft() {



  if (digitalRead(_LeftSensor))
    return false;
    
  else
    return true;


}

bool SensorLinha::detectedByMiddle() {

  if ( digitalRead(_MiddleSensor) )
    return false;
    
  else
    return true;



}

bool SensorLinha::detectedByRight() {

  if ( digitalRead(_RightSensor) )
    return false;
    
  else
    return true;



}







