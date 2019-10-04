#include "Sweeper.h"
#include "Servo.h"
#include <Array.h>
//Sweeper construtor e setup inicializam as portas pro ultrassom e pros motores DC.
//Sweeper dist() retorna a distância relacionada á onda do ultrassom.
//Consequentemente existem leituras fantasmas, logo Sweeper distSemOutlier()
//tenta retornar uma leitura mais segura
//Sweeper Sweeping() faz a varredura pra esquerda ou direita, dependendo do número
//de intervalos desejado
//Sweeper movMotor() e movSweeper() são métodos de movimentação do carro
//Sweeper ultrassomTeste() é pra testar o distSemOutlier()
//O resto é direcionado ao processamento por k-means
Sweeper::Sweeper(int t, int e,int s,int dcA,int dcB,int dcC,int dcD) {
  trigPin = t;
  echoPin = e;
  servoPin = s;
  dcPinA = dcA;
  dcPinB = dcB;
  dcPinC = dcC;
  dcPinD = dcD;
  timeOut = 6000; // 3000 �s = 50cm // 30000 �s = 5 m
  
}
void Sweeper::setup(Servo myservo) {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(dcPinA, OUTPUT);
  pinMode(dcPinB, OUTPUT);
  pinMode(dcPinC, OUTPUT);
  pinMode(dcPinD, OUTPUT);
  myservo.attach(servoPin);

}

long Sweeper::tempo() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, timeOut);
  if ( duration == 0 ) {
    duration = timeOut;
  }
  return duration;
}

long Sweeper::dist() {
  tempo();
  distanceCm = duration / 29 / 2 ;
  return distanceCm;

}
long Sweeper::distSemOutlier(){
  long x = dist();
  long y = dist();
  long z = dist();
  if(x == y && x == z) return x;
  else{
    while(x != y || x != z){
      x = dist();
      y = dist();  
      z = dist();
    }
    return x;
  }
}


int Sweeper::findSmallestElement(int distancias[], int angulos[],int sizeOfArrays){
   int tronoDist = distancias[0];
   int tronoAng = angulos[0];

   for(int i=0; i<sizeOfArrays; i++) {
      if(tronoDist > distancias[i]) {
         tronoDist = distancias[i];
         tronoAng = angulos[i];
      }
   }
   return tronoDist,tronoAng;
}
void Sweeper::sweeping(Servo myservo,char * movimento,int n, int distancias[7], int angulos[7],int angMax, int angMin){
  int i =0;
  if(movimento == "pradireita"){
    for(int pos =angMax; pos>angMin; pos-=(angMax - angMin)/n){
      myservo.write(pos); 
      delay(200);
      distancias[i] = distSemOutlier(); 
      angulos[i] = pos;
      i++;
      
    }
  }
  else if(movimento == "praesquerda"){
    for(int pos =angMin; pos<angMax; pos+=(angMax - angMin)/n){
      myservo.write(pos); 
      delay(200);
      distancias[i] = distSemOutlier(); 
      angulos[i] = pos;
      i++;
    }   
  }

}
void Sweeper::execution(int flag){
   switch(flag){
        case 0:
          movSweeper("frente",200);
          movSweeper("paradisgraça",50);
        break;
        case 1:
          movSweeper("viraesquerda", 200);
          movSweeper("paradisgraça",50);
        break;
        case 2:
          movSweeper("viradireita", 200);
          movSweeper("paradisgraça",50);
        break;
        case 3:
          movSweeper("frente", 200);
          movSweeper("paradisgraça",50);
        break;
   }
}

void Sweeper::movMotor(const char * lado,const char * sentido){
  if(lado == "dir"){
    if(sentido == "frente"){
      digitalWrite(dcPinB,LOW);
      digitalWrite(dcPinA,HIGH);
    }
    else{
      digitalWrite(dcPinB,HIGH);
      digitalWrite(dcPinA,HIGH);      
    }
  }
  else{
    if(sentido == "frente"){
      digitalWrite(dcPinC,LOW);
      digitalWrite(dcPinD,HIGH);
    }
    else{
      digitalWrite(dcPinC,HIGH);
      digitalWrite(dcPinD,HIGH);      
    }
  }
}
void Sweeper::movSweeper(const char * movimento,int delayInterval){ 
  if(movimento == "frente"){
    movMotor("dir","frente");
    movMotor("esq","frente");
    delay(delayInterval);
  }
  else if(movimento == "tras"){
    digitalWrite(dcPinB,HIGH);
    digitalWrite(dcPinA,LOW);
    digitalWrite(dcPinC,HIGH);
    digitalWrite(dcPinD,LOW);
    delay(delayInterval);   
  }
  else if(movimento == "viradireita"){
    movMotor("esq","frente");
    movMotor("dir","parado");  
    delay(delayInterval);   
   }
  else if(movimento == "viraesquerda"){
    movMotor("esq","parado");
    movMotor("dir","frente");    
    delay(delayInterval);
  }
  else{
    pinMode(dcPinA, INPUT);
    pinMode(dcPinB, INPUT);
    pinMode(dcPinC, INPUT);
    pinMode(dcPinD, INPUT);  
    delay(delayInterval);
    pinMode(dcPinA, OUTPUT);
    pinMode(dcPinB, OUTPUT);
    pinMode(dcPinC, OUTPUT);
    pinMode(dcPinD, OUTPUT);  
  }
  
}
int Sweeper::clusterCalc(int dist, int ang){
  int flag = 0;
  int distCluster0 = sqrt(abs(dist - 13.5) + abs(ang - 30));
  int distCluster1 = sqrt(abs(dist - 12) + abs(ang - 70));
  int distCluster2 = sqrt(abs(dist - 11.75) + abs(ang - 110));
  int distCluster3 = sqrt(abs(dist - 11) + abs(ang - 145));
  int menorDist = distCluster0;
  if(distCluster1 < menorDist){
    flag = 1;
    menorDist = distCluster1;
  } 
  if(distCluster2 < menorDist){
    flag = 2;
    menorDist = distCluster2;   
  }
  if (distCluster3 < menorDist ){
    flag = 3;
    menorDist = distCluster3; 
  }
  
  return menorDist,flag;
}
void Sweeper::LED_teste(int flag){

  switch(flag){
        case 0:
             digitalWrite(11,LOW);
             digitalWrite(10,LOW);
        break;
        case 1:
             digitalWrite(11,LOW);
             digitalWrite(10,HIGH);
        break;
        case 2:
             digitalWrite(11,HIGH);
             digitalWrite(10,LOW);
        break;
        case 3:
             digitalWrite(11,HIGH);
             digitalWrite(10,HIGH);
        break;
      }
}
void Sweeper::ultrassomTeste(Servo myservo){
  myservo.write(20);
  delay(500);
  Serial.print(distSemOutlier());
  Serial.print(" ");
  myservo.write(48);
  delay(500);
  Serial.print(distSemOutlier());
  Serial.print(" ");  
  myservo.write(112);
  delay(500);
  Serial.print(distSemOutlier());
  Serial.print(" ");
  myservo.write(138);
  delay(500);
  Serial.print(distSemOutlier());
  Serial.println(" ");
  
  myservo.write(138);
  delay(500);
  Serial.print(distSemOutlier());
  Serial.print(" ");
  myservo.write(112);
  delay(500);
  Serial.print(distSemOutlier());
  Serial.print(" ");  
  myservo.write(48);
  delay(500);
  Serial.print(distSemOutlier());
  Serial.print(" ");
  myservo.write(20);
  delay(500);
  Serial.print(distSemOutlier());
  Serial.println(" ");  
  
}
void Sweeper::ultrassomDataget(Servo myservo,int angMin,int angMax){
  Serial.println("Ang,dist,class");
  for(int i =angMin; i < angMax; i++){
    myservo.write(i);
    int temp = distSemOutlier(); 
    if(temp < 20){
      if(i > 90){
        Serial.print(i);
        Serial.print(",");
        Serial.print(temp);
        Serial.print(",");
        Serial.println('0');
        }
      else {
        Serial.print(i);
        Serial.print(",");
        Serial.print(temp);
        Serial.print(",");
        Serial.println('1');
        
        }
      }   
    
    
    
    delay(200);
    }
  

}

