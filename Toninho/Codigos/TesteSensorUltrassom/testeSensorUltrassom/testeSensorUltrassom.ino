#include "SensorUltrassom.h"
/*
  Coloque numeros dos pinos referentes ao trig
  e echo aqui  \/
*/
int trigger = 12;
int echo = 13;

/* chame a variavel especial SensorUltrassom com os numeros
   entre parênteses dos pinos no meu caso  foram as variaveis
   trigger, echo, que  possuem os valores 12 e 13 respectivamente
*/
SensorUltrassom ultra (trigger, echo);

void setup() {

  /*
       essa função serve para iniciar  a comunicação pelo USB,
       também conhecida como comunicação serial
  */
  
 
  Serial.begin(9600);  //begin em portugues significa começar 


}

void loop() {

  Serial.print("Utrassom: ");
  Serial.print( ultra.getDistance() );
  Serial.println(" cm");
  /*
    essa função exibe em centímentros a distancia no monitor serial  entre o sensor
    e o primeiro obstaculo que tem pela frente,
  */

}
