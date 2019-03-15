#include "ServoMotor.h" 



ServoMotor::ServoMotor(){
 
}

void ServoMotor::setup(int pinEsquerda,int pinDireita){
    paradoDireito = 1500; 
    paradoEsquerdo = 1500;
    intensDir = 230;
    intensEsq = 420;  
    mDireito.attach(pinDireita);
    mEsquerdo.attach(pinEsquerda);  


} 

void ServoMotor::calibra(int pEsq, int pDir){
    paradoDireito = pDir; 
    paradoEsquerdo = pEsq;
}

void ServoMotor::frente(){
    mDireito.writeMicroseconds(paradoDireito+intensDir); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo-intensEsq); 
} 

void ServoMotor::viraDireita(){
    mDireito.writeMicroseconds(paradoDireito-intensDir); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo-intensEsq); 
} 

void ServoMotor::viraEsquerda(){
    mDireito.writeMicroseconds(paradoDireito+intensDir); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo+intensEsq); 

} 

void ServoMotor::re(){
    mDireito.writeMicroseconds(paradoDireito-intensDir); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo+intensEsq); 
} 

void ServoMotor::parado(){
    mDireito.writeMicroseconds(paradoDireito); 
    mEsquerdo.writeMicroseconds(paradoEsquerdo); 
}
