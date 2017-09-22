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
SensorUltrassom teste (trigger,echo);

void setup() {

  /*
       A variavel do Tipo SensorUltrassom tem uma função como .debug()
       no meu caso fica teste.debug();
       essa função só funciona com a Comunicação pelo cabo Usb
       ligado ou também conhecida como Comunicação Sereal
  */

 //essa é a função que começa comunicação sereal
   Serial.begin(9600);
  

}

void loop() {

  teste.debug();
  /*
 * essa função exibe em centímentros a distancia no monitor serial  entre o sensor 
 * e o primeiro obstaculo que tem pela frente,
 */

}
