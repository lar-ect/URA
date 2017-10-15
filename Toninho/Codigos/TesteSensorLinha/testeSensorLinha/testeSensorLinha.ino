#include "SensorLinha.h"

/* coloque o numero do pino que vai
  utilizar na variavel pinoAnalogico.
  no meu caso foi o pino 1 */
int pinoAnalogico = 1;



/* chame a variavel especial SensorLinha com o numero
   entre parênteses do pino no meu caso eu coloquei a variavel
   pinoAnalogico, que  possui o valor igual a 1
*/

SensorLinha meuSensorLinha(pinoAnalogico);

/* escrevendo: "SensorLinha meuSensorLinha" .  você está declarando
    um tipo de variavel especial chamando ela de meuSensorLinha.

*/
void setup() {


  /*
     essa função serve para iniciar  a comunicação pelo USB,
     também conhecida como comunicação serial
  */
  Serial.begin(9600); //begin em portugues significa começar 


  /*
     após observar a intecidade das cores que o sensor captura
     você setara ou definir um Limiar, ou seja um valor limite
     que eu considerei que acima dele o sensor detectou o preto.
     no meu caso, observei o valor 700
  */
  meuSensorLinha.setLimiar(700);


}

void loop() {

  Serial.print("Sensor: ");
  Serial.println( analogRead(pinoAnalogico) );


  /*
     analogRead(pinoAnalogico),  essa função exibe valores entre 0 a 1023, que remetem a
     intencidade da luz , onde quando maior o valor mais escura é a cor capturada.
     já a função Serial.print(), perimite printar ou exibir esse valores no monitor Serial
     utilizei essas duas funções para encontrar o meu limiar
  */



  if ( meuSensorLinha.detectedBySensor() == true ){
      Serial.print("preto detectado");

   }
  else{ // significa que meuSensorLinha.detectedBySensor() == false 
      Serial.print("preto não detectado");
   }
   /*
      .detectedBySensor() é uma função especial do tipo SensorLinha, ela retorna apenas
      dois valores, verdadeiro ou falso, caso o valor detectado pelo sensor linha for
      maior que  seu limiar definido anteriormente, essa função retorna verdadeiro ou seja
      a cor do objeto que está abaixo do sensor é tão escura que podemos concluir que é o preto
      se não retornar verdadeiro, ou seja se for falso então a cor muito clara para podermos dizer
      que é preto. 

   */



}
