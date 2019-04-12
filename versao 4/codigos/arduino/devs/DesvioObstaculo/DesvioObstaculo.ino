#include "ServoMotor.h" 
#include "Ultrassom.h"

ServoMotor sm; 
// trig e echo 
Ultrassom us(9,8);


void setup() {
   us.setup(); 
   sm.setup(4,5); 
   sm.calibra(1470,1450); 
   Serial.begin(9600);
}

void loop() {
  //sm.viraDireita();
  sm.parado(); 
  int d = us.dist();
  Serial.println(d);
  delay(400);
  /*
  int d = us.dist();
  Serial.println(d); 
  if (d > 30) { 
    sm.frente();
  }
  else {
    sm.viraDireita(); 
    delay(500); 
  }
  delay(100); */ 
}
