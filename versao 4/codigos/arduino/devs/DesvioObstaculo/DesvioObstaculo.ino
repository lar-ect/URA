#include "ServoMotor.h" 
#include "Ultrassom.h"

ServoMotor sm; 
// trig e echo 
Ultrassom us(6,5); 

void setup() {
   us.setup(); 
   sm.setup(11,10); 
   sm.calibra(1470,1470); 
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
    delay(500); 
  }
  delay(100); 
}
