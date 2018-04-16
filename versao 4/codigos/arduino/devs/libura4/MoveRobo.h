#ifndef MOVEROBO_H
#define MOVEROBO_H
#include "ServoMotor.h" 

#define CMD_FRENTE 1
#define CMD_RE 2
#define CMD_GIRA_DIREITA 3 
#define CMD_GIRA_ESQUERDA 4 
#define CMD_PARA 5


 class MoveRobo 
 {
     public: 
        MoveRobo();
        void setup(int pinE, int pinD); 


        void comandoTempo(int cmd, unsigned long t);
        void executeComando(int comando); 
        void reseta();
        
    private: 
        ServoMotor sm; 
         

        // atributos para tratar o tempo de execução de um comando  
        bool proximoComando; 
        bool temComandoAtivo; 
        unsigned long tempoExecComando;
        unsigned long ultimoTempo;


 };

#endif 
