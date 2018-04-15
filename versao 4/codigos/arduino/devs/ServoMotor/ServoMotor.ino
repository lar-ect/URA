
#include "ServoMotor.h" 

ServoMotor sv(5,4);

void setup() {
  sv.setup();
  sv.calibra(1640,1470); 
  

}

void loop() {
  //sv.frente(); 
  //sv.re();
  sv.parado();
  //sv.viraDireita();
  //sv.viraEsquerda();
}
