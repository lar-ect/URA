#include "Arduino.h"
#include "URA.h"

DCMotor::DCMotor(int in1, int in2, int in3, int in4, int enA = 0, int enB = 0) {
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
  _enA = enA;
  _enB = enB;

}

void DCMotor::forward() {
  clockwise(_in1, _in2);
  clockwise(_in3, _in4);
}

void DCMotor::backward() {
  antiClockwise(_in1, _in2);
  antiClockwise(_in3, _in4);
}

void DCMotor::left() {
  antiClockwise(_in1, _in2);
  clockwise(_in3, _in4);
}

void DCMotor::right() {
  clockwise(_in1, _in2);
  antiClockwise(_in3, _in4);
}

void DCMotor::stop() {
  digitalWrite(_in1, 0); digitalWrite(_in2, 0);
  digitalWrite(_in3, 0); digitalWrite(_in4, 0);
}

void DCMotor::clockwise(int inx, int iny) {
  digitalWrite(inx, 1); digitalWrite(iny, 0);
}
void DCMotor::antiClockwise(int inx, int iny) {
  digitalWrite(inx, 0); digitalWrite(iny, 1);
}

void DCMotor::leftBack() {

  antiClockwise(_in1, _in2);
}

void DCMotor::rightBack() {

  antiClockwise(_in3, _in4);
}

void DCMotor::setup() {
  pinMode(_in1, OUTPUT);
  pinMode(_in2, OUTPUT);
  pinMode(_in3, OUTPUT);
  pinMode(_in4, OUTPUT);
  pinMode(_enA, OUTPUT);
  pinMode(_enB, OUTPUT);
  Serial.begin(9600);
  Serial.println(_enA);
  digitalWrite(_enA, HIGH);
  digitalWrite(_enB, HIGH);
}


Sensor::Sensor(int pin) {
  _pin = pin;

}
void Sensor::setup() {
  pinMode(_pin, INPUT);
}

boolean Sensor::detected() {
  return digitalRead(_pin);
}

Ultrasonic::Ultrasonic(int TRIG, int ECHO) {
  Trig_pin = TRIG;
  Echo_pin = ECHO;
  Time_out = 3000; // 3000 µs = 50cm // 30000 µs = 5 m
}



long Ultrasonic::tempo() {
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin, HIGH, Time_out);
  if ( duration == 0 ) {
    duration = Time_out;
  }
  return duration;
}

long Ultrasonic::dist() {
  tempo();
  distance_cm = duration / 29 / 2 ;
  return distance_cm;

}
void Ultrasonic::setup() {
  pinMode(Trig_pin, OUTPUT);
  pinMode(Echo_pin, INPUT);
}


