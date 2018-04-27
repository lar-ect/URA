#include <Servo.h>
#include "ContaGiros.h" 


Servo motor;
ContaGiros cg; 

// variaveis para o controle de velocidade 
unsigned long parado = 1620; 
unsigned long ajusteMotor = 30; 
unsigned long deltaT = 2000; 
unsigned long tempoAnterior = 0; 
double termoIntegral = 0; 
double Kp = 1.1; 
double Ki = 0.02; 


void setup() {
  motor.attach(5); 
  cg.setup(A5,200); 
  Serial.begin(9600); 

}

/*
 * Gira até contar vinte fendas 
 */
void testeContadorDePicos(){
  
  if ( cg.contaAte(20)) {
    motor.writeMicroseconds(1700); 
  }
  else {
    motor.writeMicroseconds(1640);
  }
  
}

void testePicosPorTempo(){
  motor.writeMicroseconds(1670);
  unsigned long picos =  cg.girosPorTempo(2000); 
   Serial.println(picos); 
}

void testeVelocidadeAtual(){
  motor.writeMicroseconds(1660);
  // tempo configurado para 1 segundo (1000 ms)
  double vel = cg.getVelocidade(1000); 
  Serial.println(vel); 
}

void testeControleVelocidade() {
  // erro = velocidade desejada - velocidade estimada 
  unsigned long tempoAtual = millis(); 
  double velocidade =  cg.getVelocidade(deltaT);
  if ( tempoAtual - tempoAnterior > deltaT ) {
    double erro = 14 - velocidade;
    termoIntegral += Ki*erro; 
    Serial.println(velocidade);
    ajusteMotor += erro*Kp + termoIntegral; 
    tempoAnterior = tempoAtual; 
  }
  if (ajusteMotor > 300 ) {
    ajusteMotor = 300; 
  }
  motor.writeMicroseconds(parado+ajusteMotor);
}

void loop() {
   //testeContadorDePicos(); 
   //testePicosPorTempo();
   //testeVelocidadeAtual();
   testeControleVelocidade(); 
}
