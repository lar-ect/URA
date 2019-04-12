#include "SOMArduino.h"

SOMArduino::SOMArduino( ) {

}

void SOMArduino::setup(){

}


float SOMArduino::distancia(int caracteristicas[SOM_MAX_F], int i, int j){
  float soma = 0;
  for (int f=0; f<SOM_MAX_F; f++){
    soma += pow(caracteristicas[f] - matrizNeuronios[i][j][f],2); 
  }
  return  sqrt(soma); 
}

void SOMArduino::melhorDistancia(int caracteristicas[SOM_MAX_F], int &melhorL, int &melhorC){
  melhorL = 0;
  melhorC = 0; 
  //Serial.print( " - " ); 
  float melhorDist = distancia(caracteristicas,melhorL,melhorC); 
  for(int i=0; i < SOM_MAX_L; i++) {
    for(int j=0; j < SOM_MAX_C; j++) {
      float d = distancia(caracteristicas,i,j);
      if(d < melhorDist){
        melhorL = i;
        melhorC = j;
        melhorDist = d;  
      }
    }
  }
}

char SOMArduino::melhorResposta(int caracteristicas[SOM_MAX_F]){
  int melhorLinha=0; 
  int melhorColuna=0; 
  melhorDistancia(caracteristicas,melhorLinha, melhorColuna); 
  return matrizLabels[melhorLinha][melhorColuna];
}
