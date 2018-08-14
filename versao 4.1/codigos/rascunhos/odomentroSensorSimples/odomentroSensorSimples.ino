int pinSensor = A1; 

void setup() {
  pinMode(pinSensor,INPUT); 
  Serial.begin(9600); 
   
  
}

void loop() {
  int val = analogRead(pinSensor);
  Serial.println(val); 

}
