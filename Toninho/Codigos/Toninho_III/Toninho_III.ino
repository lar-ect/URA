#include "URA.h"

//DCMotor dcMotor(5,7,3,2,4,6);
Sensor esq(9), Dir(8);
Ultrasonic ultrassonic(11,12);

 DCMotor dcMotor(5,7,2,3,4,6); //Para placa nova do URA
//DCMotor dcMotor(6,5,4,2,3,7);// Para Toninho III
//DCMotor dcMotor(12,13,9,8,11,10); //Para o shield de arduino UNO  



void setup() {
  Serial.begin(9600);
  Serial.println("TONINHO II");
 
  dcMotor.setup();
  esq.setup();
  Dir.setup();
  ultrassonic.setup();
}

void loop() {
//  
    // dcMotor.left();      // ele vira para a esquerda (jeito 1 )
   // dcMotor.righ();      // ele vira para a direita (jeito 1)
  //  dcMotor.forward();  // ele segue em frente    
 // dcMotor.rightBack(); // ele vira para a direita (jeito 2)   
    //dcMotor.leftBack(); // ele vira para a esquerda (jeito 2)
    /*
    dcMotor.forward();
    delay(3000);
    dcMotor.backward();
    delay(3000);
    */
    

//  
    /*  
    Serial.print(esq.detected());
    Serial.print('\t');
    Serial.println(Dir.detected());
    */
    Serial.println(ultrassonic.dist());

   // digitalWrite(4);
  
}
