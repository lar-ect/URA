#include "ContaGiros.h" 

ContaGiros::ContaGiros(){
  pulsoAtual = false;
  pulsoAnterior = false; 
  contadorPicos = 0; 
  deltaTempo = 1000; 
  ultimoContadorPicos = 0; 
}


void ContaGiros::setup(int p, int l){
  pin = p; 
  limiar = l; 
}

void ContaGiros::atualiza(){
  int inSensor = analogRead(pin); 
  if (inSensor > limiar) {
    pulsoAtual = true;
  }
  else {
    pulsoAtual = false; 
  }
  // detecta transição de subida 
  if ( ! pulsoAnterior &&  pulsoAtual ){
    contadorPicos++; 
  }

  pulsoAnterior = pulsoAtual; 
   
}

unsigned long  ContaGiros::velocidadeRoda() { 
  unsigned long tempoAtual = millis();
  if (tempoAtual - ultimoTempo > deltaTempo ) {
    deltaContadorPicos = contadorPicos - ultimoContadorPicos; 
    ultimoTempo = tempoAtual; 
    ultimoContadorPicos = contadorPicos;
      
  }
  return deltaContadorPicos; 
  
}


int ContaGiros::getContador(){
  return contadorPicos; 
}

void ContaGiros::zeraContador() {
  contadorPicos = 0;
  ultimoContadorPicos = 0;  

}

bool ContaGiros::contaAte(unsigned long cont){
  if( cont <= contadorPicos){
    return false;    
  }
  else{
    return true; 
  }
}
