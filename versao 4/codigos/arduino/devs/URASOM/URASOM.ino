#include "SOMArduino.h"
#include "MoveRobo.h"
#include "Ultrassom.h"

MoveRobo mv; 
 
Ultrassom usd(3,2);  // ultrassom  
Ultrassom use(7,6); // ultrassom  
Ultrassom usf(9,8); // ultrassom frente 

int comandoAtual; 
int vSensores[SOM_MAX_F]; 

SOMArduino som; 

void testeFuncaoDistancia(){
  int vc[] = {18, 16, 55}; 
  int melhorLinha=0; 
  int melhorColuna=0; 
  som.melhorDistancia(vc,melhorLinha, melhorColuna); 
  Serial.print(melhorLinha);
  Serial.print(" - ");
  Serial.println(melhorColuna);  
}

void testeReposta() {
  int vc[] = {18, 68, 55}; 
  int melhorLinha=0; 
  int melhorColuna=0; 
  som.melhorDistancia(vc,melhorLinha, melhorColuna); 
  Serial.println(som.getLabel(melhorLinha,melhorColuna));
}

void testeMelhorResposta() {
  int vc[] = {18, 68, 22}; 
  Serial.println(som.melhorResposta(vc)); 
}

void testeRedeSOM(){
  vSensores[0] = use.dist();
  vSensores[1] = usf.dist(); 
  vSensores[2] = usd.dist(); 
  mv.ativaProximoCMD(); 
  
  char c = som.melhorResposta(vSensores); 

  
  for( int i; i <3; i++) {
    Serial.print(vSensores[i]);
    Serial.print(" "); 
  }
  Serial.println(c); 
  
  comandoAtual = mv.converteCharParaCmd(c);
  //Serial.println(comandoAtual);
  mv.comandoTempo(comandoAtual,100);
  
}

void teste2RedeSOM(){

  
  char c = som.melhorResposta(vSensores); 

  
  for( int i; i <3; i++) {
    Serial.print(vSensores[i]);
    Serial.print(" "); 
  }
  Serial.println(c); 
  
  comandoAtual = mv.converteCharParaCmd(c);
  //Serial.println(comandoAtual);
  if ( ! mv.comandoTempo(comandoAtual,50) ) {
    vSensores[0] = use.dist();
    vSensores[1] = usf.dist(); 
    vSensores[2] = usd.dist(); 
    mv.ativaProximoCMD(); 
  }
  
}

void setup() {
  Serial.begin(9600); 
  comandoAtual = CMD_PARA; 
  mv.setup(4,5,1470,1450, -400); 
  usf.setup();
  use.setup();
  usd.setup();
}

void loop() {
  //delay(50); 
  //testeFuncaoDistancia(); 
  //testeReposta();  
  //testeMelhorResposta();
  //testeRedeSOM();
  teste2RedeSOM(); 
  //mv.comandoTempo(CMD_FRENTE,1000);


}
