
#include "PonteHL9110.h"


PonteHL9110::PonteHL9110(int pA_1A, int pA_1B, int pB_1A, int pB_1B){
   pinAPWM = pA_1A; 
   pinBPWM = pB_1A; 
   pinADir = pA_1B;
   pinBDir = pB_1B;

}

void PonteHL9110::setup() {
   pinMode( pinAPWM, OUTPUT );
   pinMode( pinADir, OUTPUT );
   pinMode( pinBPWM, OUTPUT );
   pinMode( pinBDir, OUTPUT );

   digitalWrite( pinAPWM, LOW );
   digitalWrite( pinADir, LOW );
   digitalWrite( pinBPWM, LOW );
   digitalWrite( pinBDir, LOW );
}
    
void PonteHL9110::setSpeedA(int d, int pwm){
   digitalWrite( pinADir, d ); // direction:  forward -> HIGH
   analogWrite( pinAPWM, 255-pwm ); // PWM speed  
} 

void PonteHL9110::setSpeedB(int d, int pwm){
   digitalWrite( pinBDir, d ); // direction:  forward -> HIGH
   if(d){  
      analogWrite( pinBPWM, 255-pwm ); // PWM speed  
   }
   else {
      analogWrite( pinBPWM, pwm );
   }
}

void PonteHL9110::stopMotorA(){
   digitalWrite( pinADir, LOW );
   digitalWrite( pinAPWM, LOW );
}

void PonteHL9110::stopMotorB(){
   digitalWrite( pinBDir, LOW );
   digitalWrite( pinBPWM, LOW );
}

