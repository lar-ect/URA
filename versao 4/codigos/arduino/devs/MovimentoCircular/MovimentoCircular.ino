
#include "ServoMotor.h" 

// motor esquerdo e direito 
ServoMotor sm;

int pinSensorEsq = 10;
int pinSensorDir = 11;  

void setup() {
  sm.setup(3,2);
  sm.calibra(1435,1420);
  pinMode(pinSensorEsq,INPUT);
  pinMode(pinSensorDir,INPUT);  
  Serial.begin(9600); 

}

void loop() {
  //sm.frente();
  sm.parado(); 
  int val = digitalRead(pinSensorEsq); 
  Serial.print(val); 
  Serial.print(" "); 
  val = digitalRead(pinSensorDir);
  Serial.println(val); 
  delay(500); 
}
