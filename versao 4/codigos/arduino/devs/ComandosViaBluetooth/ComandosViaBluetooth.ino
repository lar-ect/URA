/*
 * Baixa o aplicativo de controle remoto para arduino bluetooth 
 * https://play.google.com/store/apps/details?id=com.giumig.apps.bluetoothserialmonitor 
 * Configurar com os caracteres utilizados no código 
 * 
 * Usar o Tx -> Rx e Rx -> Tx (bluetooth -> Arduíno) 
 */

#include "ControleMovimento.h"
ControleMovimento cm; 

long passosE = 20;
long passosD = 20; 
 
int delta; 
 

void setup() {
   delta = 20; 
   cm.setup(5,4,A5,A4,1640,1460); 
   Serial.begin(9600);
}

void loop() {
  cm.atualizaSensores(); 
  if (Serial.available())
  { 
    char c = Serial.read();

 
    if (c == 'f') {
      // move para frente 
      passosE = 20; 
      passosD = 20; 
 
    }
    else if (c == 'r') {
      // move para trás 
      passosE = -20; 
      passosD = -20; 
    } 
    else if (c == 'd') {
      passosE = 0; 
      passosD = 20; 
    }
    else if (c == 'e') {
      passosE = 20; 
      passosD = 0;    
    }
    else if (c == 'q') {
      passosE = 0; 
      passosD = 0; 
    }
    Serial.println(c); 
  } 
  cm.giraAte(passosE, passosD); 
  //delay(20); 
}
