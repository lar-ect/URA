#include "PonteHL9110.h"

PonteHL9110 motorDC(9,8,10,11);

void setup() {
  motorDC.setup(); 
  // put your setup code here, to run once:

}

void loop() {
  motorDC.setSpeedB(1,120);
  delay(3000); 
  motorDC.stopMotorB();
  delay(5000);
   

}
