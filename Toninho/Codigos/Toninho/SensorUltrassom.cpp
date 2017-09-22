#include "Arduino.h"
#include "SensorUltrassom.h"

SensorUltrassom::SensorUltrassom(int trigger, int echo) {
  _trigger = trigger;
  _echo = echo;

  pinMode(_trigger, OUTPUT);
  pinMode(_echo, INPUT);
  digitalWrite(_trigger, LOW);

}

long SensorUltrassom::getDistance() {
  float duration, distance_cm;

  digitalWrite(_trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigger, LOW);
  duration = pulseIn(_echo, HIGH, 3000);
  if ( duration == 0 ) {
    duration = 3000;
  }

  distance_cm = duration / 29 / 2 ;

  return distance_cm;


  // velocidade do Som em 25 graus Celsius é iguaç a  346,3 m/s

}

void SensorUltrassom::debug(){

  Serial.print("Utrassom: ");
  Serial.println( getDistance() );

}










