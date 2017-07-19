#include "Arduino.h"
#include "DCMotor.h"

DCMotor::DCMotor(int in1, int in2, int in3, int in4) {
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;




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
  stopDCMotor(_in1, _in2);
  stopDCMotor(_in3, _in4);

}

void DCMotor::slowForward() {

  if (slowMode(20))
    stop();

  else
    forward();

}

void DCMotor::slowBackward() {
  if (slowMode(20))
    stop();
  else
    backward();

}

void DCMotor::slowLeft() {
  if (slowMode(20))
    stop();
  else
    left();

}

void DCMotor::slowRight() {
  if (slowMode(20))
    stop();
  else
    right();

}

void DCMotor::leftBack() {

  antiClockwise(_in1, _in2);
  stopDCMotor(_in3, _in4);
}

void DCMotor::rightBack() {
  stopDCMotor(_in1, _in2);
  antiClockwise(_in3, _in4);
}

void DCMotor::clockwise(int inx, int iny) {
  digitalWrite(inx, 1); digitalWrite(iny, 0);
}

void DCMotor::antiClockwise(int inx, int iny) {
  digitalWrite(inx, 0); digitalWrite(iny, 1);
}

bool DCMotor::slowMode(long interval) {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis > interval) {

    estado = !estado;
    previousMillis = currentMillis;
  }

  if (estado)
    return true;
  else
    return false;

}

void DCMotor::stopDCMotor(int inx, int iny) {
  digitalWrite(inx, 0); digitalWrite(iny, 0);
}








