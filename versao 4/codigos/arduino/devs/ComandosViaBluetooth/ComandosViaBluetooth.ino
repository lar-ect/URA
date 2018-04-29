/*
 * Baixa o aplicativo de controle remoto para arduino bluetooth 
 * https://play.google.com/store/apps/details?id=com.giumig.apps.bluetoothserialmonitor 
 * Configurar com os caracteres utilizados no código 
 * 
 * Usar o Tx -> Rx e Rx -> Tx (bluetooth -> Arduíno) 
 */

#include "ControleMovimento.h"
ControleMovimento cm; 

 
 
int delta; 
 

void setup() {
   delta = 20; 
   cm.setup(5,4,A5,A4,1640,1460); 
   Serial.begin(9600);
}

void loop() {
  if (Serial.available())
  { 
    char c = Serial.read();

 
    if (c == 'f') {
      // move para frente 
      cm.moveMotores(100, 100);
    }
    else if (c == 'r') {
      // move para trás 
      cm.moveMotores(-100, -100);  
    } 
    else if (c == 'd') {
      cm.moveMotores(0, 100); 
    }
    else if (c == 'e') {
      cm.moveMotores(100, 0);    
    }
    else if (c == 'q') {
      cm.moveMotores(0, 0);  
    }
    Serial.println(c); 
  } 
  delay(20); 
}
