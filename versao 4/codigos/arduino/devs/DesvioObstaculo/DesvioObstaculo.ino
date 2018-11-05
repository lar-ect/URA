#include "ServoMotor.h" 
#include "Ultrassom.h"

ServoMotor sm; 
// trig e echo 
Ultrassom us(3,2); 

void setup() {
   us.setup(); 
   sm.setup(5,4); 
   sm.calibra(1610,1460); 
   Serial.begin(9600);
}

void loop() {
  int d = us.dist();
  Serial.println(d); 
  if (d > 30) {
    sm.frente();
  }
  else {
    sm.viraDireita(); 
  }
  delay(300); 
}
