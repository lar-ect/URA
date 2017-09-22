#include "Arduino.h"
#include "SensorUltrassom.h"

SensorUltrassom::SensorUltrassom(int trigger, int echo) {
  _trigger = trigger;
  _echo = echo;

  pinMode(_trigger, OUTPUT);
  pinMode(_echo, INPUT);
  digitalWrite(_trigger, LOW);

}

int SensorUltrassom::getDistance() {
   //seta o pino 12 com um pulso baixo "LOW" ou desligado ou ainda 0  
    digitalWrite(_trigger, LOW);  
  // delay de 2 microssegundos  
    delayMicroseconds(2);  
  //seta o pino 12 com pulso alto "HIGH" ou ligado ou ainda 1  
    digitalWrite(_trigger, HIGH);  
  //delay de 10 microssegundos  
    delayMicroseconds(10);  
  //seta o pino 12 com pulso baixo novamente  
    digitalWrite(_trigger, LOW);  
  //pulseInt lê o tempo entre a chamada e o pino entrar em high  
     long duration = pulseIn(_echo,HIGH);  
  //Esse calculo é baseado em s = v . t, lembrando que o tempo vem dobrado  
  //porque é o tempo de ida e volta do ultrassom  
     long distancia = duration /29 / 2 ;  
    return distancia;

  // velocidade do Som em 25 graus Celsius é iguaç a  346,3 m/s

}

void SensorUltrassom::debug(){

  Serial.print("Utrassom: ");
  Serial.print( getDistance() );
  Serial.println(" cm");

}










