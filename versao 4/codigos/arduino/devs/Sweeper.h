#ifndef SWEEPER_H
#define SWEEPER_H
 
#include <Arduino.h>
#include "Servo.h"
#include <Array.h>

class Sweeper
{
  public:
    Sweeper(int trig, int echo, int servoPin,int dcA,int dcB,int dcC,int dcD);//De cima pra baixo no ultrassom e sinal do servo
    void setup(Servo myservo);
    long tempo();
    long dist();
    long distSemOutlier();
    void sweeping(Servo myservo,char * movimento, int n,int distancias[4], int angulos[4],int angMax, int angMin);    
    int findSmallestElement(int distancias[], int angulos[],int sizeOfArrays);
    void movMotor(const char * seila,const char * seilatbm);
    void movSweeper(const char * bananananannana,int delayInterval);
    void execution(int flag);
    int clusterCalc(int dist, int ang);
    void LED_teste(int flag);
    void ultrassomTeste(Servo myservo);
    void ultrassomDataget(Servo myservo,int angMin,int angMax);
  private:
    int trigPin;
    int echoPin;
    int servoPin;
    int dcPinA,dcPinB,dcPinC,dcPinD;
    int sentido;
    long timeOut;
    long duration, distanceCm, distanceInc;
  
};
 
#endif
