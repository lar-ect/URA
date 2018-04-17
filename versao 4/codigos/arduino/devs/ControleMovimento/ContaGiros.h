#ifndef CONTAGIROS_H
#define CONTAGIROS_H
 
#include <Arduino.h>



 class ContaGiros 
 {
     public: 
        ContaGiros();
        // Seta o pino do sensor e o limiar 
        void setup(int p, int l); 
        // atualiza() deve ser chamada no loop principal constatemente 
        void atualiza(); 
        int getContador(); 
        void zeraContador(); 
        bool contaAte(unsigned long cont); 
        
    private: 
        unsigned long contadorPicos; 
        bool pulsoAtual; 
        bool pulsoAnterior; 
        int pin; 
        int limiar; 

 };

#endif 
