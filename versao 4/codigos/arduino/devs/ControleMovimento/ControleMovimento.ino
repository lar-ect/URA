#include "ControleMovimento.h"
ControleMovimento cm; 


void setup() {
  cm.setup(5,4,A5,A4); 

}

void loop() {
  cm.atualizaSensores(); 
  //cm.giraAte(40); 
  cm.percorreDistancia(25); 
  
}
