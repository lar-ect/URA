
#include "ServoMotor.h" 

// motor esquerdo e direito 
ServoMotor sm;

void setup() {
  sm.setup(5,4);
  sm.calibra(1635,1470);
  

}

void loop() {
  //sm.frente(); 
  //sm.re();
  //sm.parado();
  //sm.viraDireita();
  //sm.viraEsquerda();
}
