#include "Ultrassom.h"

Ultrassom::Ultrassom(int t, int e) {
  trigPin = t;
  echoPin = e;
  timeOut = 4000; // 3000 µs = 50cm // 30000 µs = 5 m
}

long Ultrassom::tempo() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, timeOut);
  if ( duration == 0 ) {
    duration = timeOut;
  }
  return duration;
}

long Ultrassom::dist() {
  tempo();
  distanceCm = duration / 29 / 2 ;
  return distanceCm;

}
void Ultrassom::setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  
}
