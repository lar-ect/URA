#include "PonteHL9110.h"
#include "ContaGiros.h" 

PonteHL9110 motorDC(9,8,10,11);

ContaGiros cg; 


void setup() {
  Serial.begin(9600); 
  motorDC.setup(); 
  cg.setup(A1,850); 
}

/**
 * O motor vai girar até uma contagem desejada de picos
 */
void testeContaGiros(){
  if ( cg.contaAte(20)) {
    motorDC.setSpeedA(1,100);
  }
  else {
    motorDC.stopMotorA();
  }
  
}

void testePicosPorTempo(){
  motorDC.setSpeedA(1,110);
  unsigned long picos =  cg.girosPorTempo(10000); 
  Serial.println(picos); 
}

void testeVelocidadeAtual(){
  motorDC.setSpeedA(1,250);
  // tempo configurado para 1 segundo (1000 ms)
  double vel = cg.getVelocidade(5000); 
  Serial.println(vel); 
}

void loop() {
  //testeVelocidadeAtual(); 

  
  //motorDC.setSpeedB(1,120);
  //delay(3000); 
  motorDC.stopMotorB();
  //delay(5000);
   

}
