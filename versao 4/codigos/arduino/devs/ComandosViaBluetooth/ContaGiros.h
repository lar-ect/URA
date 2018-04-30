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
        unsigned long  velocidadeRoda(); 
        bool contaAte(long cont); 
        
    private: 
        unsigned long contadorPicos; 
        bool pulsoAtual; 
        bool pulsoAnterior; 
        int pin; 
        int limiar; 
        // tempo 
        unsigned long deltaTempo;
        unsigned long ultimoTempo; 
        unsigned long ultimoContadorPicos; 
        unsigned long deltaContadorPicos;  

        //Distância percorida por uma volta completa da roda 
        double distRoda;
        //Quantidade de fendas no disco 
        double qtFendas; 
        
        unsigned long distanciaParaPicos(double dist);
        double picosParaDistancia(unsigned long picos);  

 };

#endif 
