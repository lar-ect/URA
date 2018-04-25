#include "ControleMovimento.h" 

ControleMovimento::ControleMovimento(){
  distRoda = 7.4*3.1415; //2*raio*pi em centimetros 
  qtFendas = 20; 
 
}

long ControleMovimento::distanciaParaPicos(double dist) {
  // (dist / distRoda) = ( picos / qtFendas)
  return (dist/distRoda)*qtFendas; 
  
}

double ControleMovimento::picosParaDistancia(long picos){
  // (dist / distRoda) = ( picos / qtFendas)
  return  picos/(qtFendas*distRoda);
}

double ControleMovimento::calculaVelocidadeRE(){
  
}

void ControleMovimento::setup(int pinEMotor, int pinDMotor, int pinESensor, int pinDSensor){
  contaGE.setup(pinESensor,200);
  contaGD.setup(pinDSensor,600);
  mEsquerdo.attach(pinEMotor); 
  mDireito.attach(pinDMotor); 
  pararMDireito = 1470; 
  pararMEsquerdo = 1620;  
 
} 

void ControleMovimento::setup(int pinEMotor, int pinDMotor, int pinESensor, int pinDSensor, int pwmEsq, int pwmDir){
  contaGE.setup(pinESensor,200);
  contaGD.setup(pinDSensor,600);
  mEsquerdo.attach(pinEMotor); 
  mDireito.attach(pinDMotor); 
  pararMDireito = pwmDir; 
  pararMEsquerdo = pwmEsq;  

  Serial.begin(9600); 
} 

void ControleMovimento::moveMotores(int pulsoEsq, int pulsoDir) {
    mEsquerdo.writeMicroseconds(pararMEsquerdo - pulsoEsq); 
    mDireito.writeMicroseconds(pararMDireito + pulsoDir); 
  
}

void ControleMovimento::percorreDistancia(double dist){
  if ( contaGD.contaAte(distanciaParaPicos(dist))) {
    moveMotores(0,100); 
  }
  else {
    moveMotores(0,0); 
  } 
}

void ControleMovimento::giraAte(unsigned long cont){
  if ( contaGE.contaAte(cont)) {
    moveMotores(100,100); 
  }
  else {
    moveMotores(0,0); 
  }
  Serial.println(contaGE.velocidadeRoda()); 

}

/* Deve ser chamada no loop principal */
void ControleMovimento::atualizaSensores(){
  contaGE.atualiza();
  contaGD.atualiza(); 

}


/*

void ControleMovimento::contaGiros(int cmd, int cont){
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

*/
