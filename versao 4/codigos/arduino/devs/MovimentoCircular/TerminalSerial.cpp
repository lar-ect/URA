#include "TerminalSerial.h"

TerminalSerial TerminalSerial::comeco() {

  for (int i = 0; i < 20; i++) {
    
    vLinear[i] = 0.00;
    vAngular[i] = 0.00;
    raio[i] = 0.00;
    angulo[i] = 0.00;

  }
}

char TerminalSerial::charRead() {
  
  char c = 45;                           //char de desvio de erros do Serial
  do {
    
    if (Serial.available()) {
      
      do {
        
        if (Serial.available())
        
          c = Serial.read();
          
      } while (c == 10);                  //Proteção contra LINE FEED    
      if (c != 45 && c != 'p' && c != 'r' && c != 'w' && c != 'd') {
        
        Serial.println("Caracter recebido esta invalido");
        c = 45;
        
      }
      
    }
    
  } while (c != 45 && c != 'p' && c != 'r' && c != 'w' && c != 'd'); 
  return c;
  
}

double TerminalSerial::numRead(int limite) {

  int num = 0;

  do {
    
    do {
      
      if (Serial.available()) {
        
        num = Serial.parseInt();
        if (num > 0) 
        
          Serial.println(num);
        
        if (num > limite) {
          
          num = 0;
          Serial.println("Dado recebido esta invalido");
          
        }
        
      }
      
    } while (num <= 0);
    
  } while (abs(num) > limite);
  
  return num;
}

void TerminalSerial::getExperimento(unsigned i, double dtempo) {
  
  if (i >= 20)
  
    Serial.println("Memoria de dados cheia");
    
  Serial.println("Insira a medida de Raio em centimetros");
  raio[i] = numRead(100) / 100;
  Serial.println("Insira a medida entre ({0 e 360}) em graus");
  angulo[i] = numRead(360); 
  //CALCULOS
  vAngular[i] = ((angulo[i] / 180.00) * PI) / dtempo;
  vLinear[i] = vAngular[i] * raio[i];
  
}

void TerminalSerial::deletarDado() {

  unsigned i;
  Serial.println("Qual Experimento voce deseja excluir?");

  i = numRead(20) - 1;          //i começa do 1
  
  if (i != 20) {
    
    for (int n = i; n <= 20 && ( raio[n] != 0 || angulo[n] != 0 || vAngular[n] != 0 || vLinear[n] != 0); n++) {
      
      vLinear[n] =  vLinear[n + 1];
      vAngular[n] = vAngular[n + 1];
      raio[n] = raio[n + 1];
      angulo[n] = angulo[n + 1];
      
    }
    
  }
  
  else
  
    Serial.println("erro");

}

void TerminalSerial::printExperimento() {

  for (int i = 0; i < 20 ; i++) {
    
    if ((raio[i] == 0.00 || angulo[i] == 0.00 || vAngular[i] == 0.00 || vLinear[i] == 0.00))
    
      break;
      
    Serial.print(i + 1);
    Serial.print(":: Raio = ");
    Serial.print(raio[i]);
    Serial.print(" m ");
    Serial.print("; Angulo = ");
    Serial.print(angulo[i]);
    Serial.print(" º ");
    Serial.print("; Velocidade Angular = ");
    Serial.print(vAngular[i]);
    Serial.print(" rad/s ");
    Serial.print("; Velocidade Linear = ");
    Serial.print(vLinear[i]);
    Serial.println(" m/s ");
    
  }
  
}

int TerminalSerial::velocidade() {

  Serial.println("insira velocidade do carrinho entre ({0 e 255})");
  int speed = numRead(255);
  return speed;

}
