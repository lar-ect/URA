#include "MoveRobo.h" 

MoveRobo::MoveRobo(){
 

}

void MoveRobo::setup(int pinE, int pinD){
 
  sm.setup(5,4);
  sm.calibra(1635,1470); 
  proximoComando = true; 
  temComandoAtivo = false; 
   
} 

void MoveRobo::executeComando(int comando){
    if (CMD_FRENTE) {
      sm.frente(); 
    } else if (CMD_RE) {
      sm.re(); 
    } else if (CMD_GIRA_DIREITA) {
      sm.viraDireita();
    } else if (CMD_GIRA_ESQUERDA) {
      sm.viraEsquerda();
    } else if (CMD_PARA) {
      sm.parado();
    }
    
}


void MoveRobo::comandoTempo(int cmd, unsigned long tempo){
  unsigned long tempoAtual = millis();
  
  if (proximoComando) {
    proximoComando=false; 
    ultimoTempo=millis();
    executeComando(cmd); 
  } else {
    if (tempoAtual - ultimoTempo > tempo ) {
      sm.parado();  
    } 
  }
}

