#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H
#include <Arduino.h>
#include <Servo.h>

class ServoMotor
{
  public:
    ServoMotor();
    void setup(int pinEsquerda, int pinDireita);
    void frente();
    void viraDireita();
    void viraEsquerda();
    void re();
    void parado();
    void velocidade(int Vel);
    void calibra(int pEsq, int pDir);

  private:
    int paradoDireito ;
    int paradoEsquerdo;
    int intensidade;
    int pinEsq, pinDir;

    Servo mEsquerdo;
    Servo mDireito;
};

#endif
