#include "ServoMotor.h" 
 

ServoMotor sm; 
int delta; 
char c; 

void setup() {
   delta = 20; 
   sm.setup(5,4); 
   sm.calibra(1620,1460); 
   Serial.begin(9600);

}

void loop() {
  if (Serial.available())
  { 
    char novoC = Serial.read();

    if (novoC == 't') {
      sm.incrementaVelocidade(delta); 
    }
    else if (novoC == 'o') {
      sm.incrementaVelocidade(-delta);
    }
    else {
      c = novoC; 
    }
    if (c == 'f') {
      // move para frente 
      sm.frente();
    }
    else if (c == 'r') {
      // move para trás 
      sm.re();  
    } 
    else if (c == 'd') {
      sm.viraDireita(); 
    }
    else if (c == 'e') {
      sm.viraEsquerda();   
    }
    else if (c == 'q') {
      sm.parado(); 
    }
    
    Serial.println(c); 
  } 
  delay(20); 
}
