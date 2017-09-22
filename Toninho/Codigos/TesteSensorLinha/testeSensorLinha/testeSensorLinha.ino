#include "SensorLinha.h"

/* coloque o numero do pino que vai
  utilizar na variavel pinoAnalogico.
  no meu caso foi o pino 1 */
int pinoAnalogico = 1;



/* chame a variavel especial SensorLinha com o numero
   entre parênteses do pino no meu caso eu coloquei a variavel
   pinoAnalogico, que  possui o valor igual a 1
*/

SensorLinha meuSensorLinha(1);

/* escrevendo: "SensorLinha meuSensorLinha" .  você está declarando
    um tipo de variavel especial chamando ela de meuSensorLinha.

*/
void setup() {


  /*
       A variavel do Tipo SensorLinha tem funções como .debug()
       no meu caso fica   meuSensorLinha.debug();
       essa função só funciona com a Comunicação pelo cabo Usb
       ligado ou também conhecida como Comunicação Sereal
  */

  //essa é a função que começa cominicação sereal
  Serial.begin(9600);

}

void loop() {

  meuSensorLinha.debug();
/*
 * essa função exibe valores entre 0 a 1023, que remetem a
 * intencidade da luz , onde quando maior o valor mais escura
 * é a cor capturada, esse valores são vistos no monitor Serial
 */

 meuSensorLinha.setLimiar(700);

/*
 * após observar a intecidade das cores que o sensor captura
 * você setara ou definir um Limiar, ou seja um valor limite 
 * que eu considerei que acima dele o sensor detectou o preto.
 * no meu caso, observei o valor 700
 */

  /*
   * existe a função .detectedBySensor, no meu caso
   * meuSensorLinha.detectedBySensor(), que volta 2 estados
   * verdadeiro e falso, se verdaeiro significa que o valor  
   * do sensor é maior que o limiar, ou seja ele achou a linha preta
   */


}
