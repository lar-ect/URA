
#include "ServoMotor.h" 

// motor esquerdo e direito 
ServoMotor sm;

void setup() {
  sm.setup(5,4);
  sm.calibra(1635,1470);
  

}

void loop() {
  sm.frente();
  delay(1000);
  sm.re();
  delay(1000);
  sm.parado();
  delay(1000);
  sm.viraDireita();
  delay(1000);
  sm.viraEsquerda();
  delay(1000);
}
