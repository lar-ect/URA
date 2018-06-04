#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H
#include <Arduino.h> 
#include <Servo.h>

 class ServoMotor 
 {
     public: 
       
        ServoMotor();
        void setup(int pinEsq, int pinDir); 
        void frente();  
        void viraDireita(); 
        void viraEsquerda(); 
        void re(); 
        void parado();
        void calibra(int pEsq, int pDir);

      
        
    private: 
 
        int paradoDireito; 
        int paradoEsquerdo;
        int intensidade; 
       
        
        Servo mEsquerdo;
        Servo mDireito; 
 };

#endif 
