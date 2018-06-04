/*
 * Sensor digital de reflência 
 */

int pinSensor = 12; 

void setup() {
  pinMode(pinSensor,INPUT); 
  Serial.begin(9600); 
   
  
}

void loop() {
  int val = digitalRead(pinSensor);
  Serial.println(val); 

}
