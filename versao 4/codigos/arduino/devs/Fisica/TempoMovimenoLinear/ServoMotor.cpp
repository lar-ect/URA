#include "ServoMotor.h" 



ServoMotor::ServoMotor(){
 
}

void ServoMotor::setup(int pinEsquerda,int pinDireita){
    paradoDireito = 1500; 
    paradoEsquerdo = 1500;
    intensidade = 400; 
    mDireito.attach(pinDireita);
    mEsquerdo.attach(pinEsquerda);  


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
