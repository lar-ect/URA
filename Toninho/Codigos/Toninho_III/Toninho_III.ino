#include "URA.h"

//DCMotor dcMotor(5,7,3,2,4,6);
Sensor sensor1(8), sensor2(9);
Ultrasonic ultrassonic();

// DCMotor dcMotor(5,7,3,2,4,6); Para placa nova do URA
DCMotor dcMotor(6,5,4,2,3,7);// Para Toninho III



void setup() {
  Serial.begin(9600);
  Serial.println("TONINHO II");
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  dcMotor.setup();
  sensor1.setup();
  
}

void loop() {
//  
    // dcMotor.left();      // ele vira para a esquerda (jeito 1 )
   // dcMotor.righ();      // ele vira para a direita (jeito 1)
  //  dcMotor.forward();  // ele segue em frente    
 // dcMotor.rightBack(); // ele vira para a direita (jeito 2)   
    //dcMotor.leftBack(); // ele vira para a esquerda (jeito 2)
    dcMotor.forward();
//     
    //Serial.println(sensor1.detected());
   

   // digitalWrite(4);
  
}
