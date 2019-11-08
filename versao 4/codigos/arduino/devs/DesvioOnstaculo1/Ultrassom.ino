#include "Ultrassom.h"

// trig e echo 
Ultrassom us(3,2); 

void setup() {
  Serial.begin(9600); 
  us.setup(); 
}

void loop() {
    Serial.println(us.dist());
    delay(1000); 
}
