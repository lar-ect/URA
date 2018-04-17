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
        void giraAte( unsigned long cont);
        void percorreDistancia(double dist); 
        void atualizaSensores(); 
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
        //Distância percorida por uma volta completa da roda 
        double distRoda;
        //Quantidade de fendas no disco 
        int qtFendas; 
        
        long distanciaParaPicos(double dist); 

        /*
        // atributos para tratar o tempo de execução de um comando  
        bool proximoComando; 
        bool temComandoAtivo; 
        unsigned long tempoExecComando;
        unsigned long ultimoTempo;
*/

 };

#endif 
