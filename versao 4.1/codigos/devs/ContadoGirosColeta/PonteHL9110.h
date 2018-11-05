
#ifndef PONTEHL9110_H
#define PONTEHL9110_H
 
#include <Arduino.h>

// Motor A_1A -> PWM Speed
// Motor A_1B -> Direction 
// Motor B_1A -> PWM Speed
// Motor B_1B -> Direction 

class PonteHL9110
{
  public:
    PonteHL9110(int pA_1A, int pA_1B, int pB_1A, int pB_1B);
    void setup();
    void setSpeedA(int d, int pwm); //d -> 1 or 0,  pwm -> 0 until 255 
    void setSpeedB(int d, int pwm); //d -> 1 or 0,  pwm -> 0 until 255 
    void stopMotorA(); 
    void stopMotorB(); 
    

  private:
    int pinAPWM;
    int pinADir;
    int pinBPWM;
    int pinBDir;
}; 
 
#endif
