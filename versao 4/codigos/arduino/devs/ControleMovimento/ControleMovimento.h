#ifndef CONTROLEMOVIMENTO_H
#define CONTROLEMOVIMENTO_H

#include "ContaGiros.h"
#include <Servo.h>

 

#define SENSOR_ESQUERDO 1
#define SENSOR_DIRETO 2



 class ControleMovimento 
 {
     public: 
        ControleMovimento();
        void setup(int pinEMotor, int pinDMotor, int pinESensor, int pinDSensor);  
        void setup(int pinEMotor, int pinDMotor, int pinESensor, int pinDSensor, int pwmEsq, int pwmDir); 
        void giraAte( unsigned long cont);
        void percorreDistancia(double dist); 
        void atualizaSensores(); 
        double calculaVelocidadeRE();
        double calculaVelocidadeRD(); 
        
        void moveMotores(int pulsoEsq, int pulsoDir); 
 
        
    private:
        // Contador de giros para roda esquerda 
        ContaGiros contaGE;  
        // Contador de giros para roda direita
        ContaGiros contaGD; 
        Servo mEsquerdo;
        Servo mDireito; 
        int pararMDireito; 
        int pararMEsquerdo; 

        /*
        // atributos para tratar o tempo de execução de um comando  
        bool proximoComando; 
        bool temComandoAtivo; 
        unsigned long tempoExecComando;
        unsigned long ultimoTempo;
*/

 };

#endif 
