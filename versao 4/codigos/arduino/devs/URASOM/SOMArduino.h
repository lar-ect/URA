
#ifndef SOMARDINO_H
#define SOMARDINO_H
 
#include <Arduino.h>

#define SOM_MAX_L 6
#define SOM_MAX_C 6
#define SOM_MAX_F 3 


class SOMArduino
{
  public:
    SOMArduino( );
    void setup();
    char melhorResposta(int caracteristicas[SOM_MAX_F]);
    void melhorDistancia(int caracteristicas[SOM_MAX_F], int &melhorL, int &melhorC);
    float distancia(int caracteristicas[SOM_MAX_F], int i, int j); 
    char getLabel(int i, int j); 
 

  private:
    int matrizNeuronios[SOM_MAX_L][SOM_MAX_C][SOM_MAX_F] = {
      { {64, 30, 67},  {60, 47, 67},  {62, 61, 67},  {58, 67, 54},  {60, 67, 37},  {67, 67, 16} },
      { {57, 40, 67},  {51, 51, 67},  {47, 60, 67},  {48, 67, 56},  {54, 67, 43},  {62, 62, 18} },
      { {43, 45, 67},  {35, 52, 67},  {26, 59, 67},  {32, 60, 61},  {41, 59, 53},  {53, 53, 23} },
      { {19, 40, 66},  {19, 41, 67},  {19, 42, 67},  {19, 38, 62},  {19, 33, 54},  {19, 15, 25} },
      { {19, 33, 66},  {20, 31, 67},  {20, 29, 67},  {20, 29, 60},  {20, 25, 47},  {19, 14, 20} },
      { {19, 22, 62},  {21, 23, 67},  {21, 22, 67},  {21, 21, 57},  {20, 18, 40},  {19, 14, 20} }
    }; 

    char matrizLabels[SOM_MAX_L][SOM_MAX_C] = {
      {'e', 'f', 'f', 'f', 'f', 'f'},
      {'e', 'f', 'f', 'f', 'f', 'f'},
      {'e', 'f', 'f', 'f', 'f', 'f'},
      {'e', 'e', 'e', 'e', 'e', 'e'},
      {'e', 'e', 'e', 'e', 'e', 'e'},
      {'e', 'e', 'e', 'e', 'e', 'e'}
    };
}; 
 
#endif
