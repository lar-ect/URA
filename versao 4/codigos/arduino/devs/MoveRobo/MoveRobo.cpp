#include "MoveRobo.h" 

MoveRobo::MoveRobo(){
 
}

void MoveRobo::setup(int pinE, int pinD){
  sm.setup(5,4);
  sm.calibra(1635,1470); 
  proximoComando = true; 
  temComandoAtivo = false; 
} 

void MoveRobo::setup(int pinE, int pinD, int tempEsq, int tempDir){
  sm.setup(5,4);
  sm.calibra(tempEsq,tempDir); 
  proximoComando = true; 
  temComandoAtivo = false; 
} 

void MoveRobo::executeComando(int comando){
    if (comando == CMD_FRENTE) {
      sm.frente(); 
    } else if (comando == CMD_RE) {
      sm.re(); 
    } else if (comando == CMD_GIRA_DIREITA) {
      sm.viraDireita();
    } else if (comando == CMD_GIRA_ESQUERDA) {
      sm.viraEsquerda();
    } else if (comando == CMD_PARA) {
      sm.parado();
    }
    
}


void MoveRobo::comandoTempo(int cmd, unsigned long tempo){
  unsigned long tempoAtual = millis();
  
  if (proximoComando && ! temComandoAtivo ) {
    proximoComando = false; 
    temComandoAtivo = true; 
    ultimoTempo=millis();
    executeComando(cmd); 
  } else {
    if ((tempoAtual - ultimoTempo > tempo) && temComandoAtivo ) {
      sm.parado();  
      temComandoAtivo = false; 
    } 
  }
}

