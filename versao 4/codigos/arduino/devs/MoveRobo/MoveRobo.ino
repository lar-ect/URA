#include "MoveRobo.h"

MoveRobo mv; 

void setup() {
  
  mv.setup(5,4,1610,1460); 
}

void loop() {
  
  mv.comandoTempo(CMD_FRENTE,2000);
  //mv.comandoTempo(CMD_RE,2000);
  //mv.comandoTempo(CMD_GIRA_DIREITA,3000);
  //mv.comandoTempo(CMD_GIRA_ESQUERDA,3000);
  //mv.comandoTempo(CMD_PARA,1000); 
}
