#include "ServoMotor.h" 



ServoMotor::ServoMotor(){
 
}

void ServoMotor::setup(int pinEsquerda,int pinDireita){
    paradoDireito = 1500; 
    paradoEsquerdo = 1500;
    intensidade = 200; 
    mDireito.attach(pinDireita);
    mEsquerdo.attach(pinEsquerda);  


} 

void ServoMotor::incrementaVelocidade(int delta) {
  intensidade = intensidade + delta; 
  if (intensidade > 400 ) {
    intensidade = 400; 
  }
  else if (intensidade < 0) {
    intensidade = 0; 
  }
  Serial.println(intensidade); 
}

void ServoMotor::calibra(int pEsq, int pDir){
    paradoDireito = pDir; 
    paradoEsquerdo = pEsq;
}

void ServoMotor::frente(){
    mDireito.writeMicroseconds(paradoDireito+intensidade); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo-intensidade); 
} 

void ServoMotor::viraDireita(){
    mDireito.writeMicroseconds(paradoDireito-intensidade); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo-intensidade); 
} 

void ServoMotor::viraEsquerda(){
    mDireito.writeMicroseconds(paradoDireito+intensidade); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo+intensidade); 

} 

void ServoMotor::re(){
    mDireito.writeMicroseconds(paradoDireito-intensidade); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo+intensidade); 
} 

void ServoMotor::parado(){
    mDireito.writeMicroseconds(paradoDireito); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo); 
}
