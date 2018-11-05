/*
 * Exemplo de como usar o Bluetooth com SoftwareSerial 
 * Fonte: http://labdegaragem.com/forum/topics/tutorial-controlando-o-arduino-via-bluetooth 
 * 
 */

 
char c = 'x'; // Stores response of bluetooth device

void setup()
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  
}

void loop()
{
 
  if (Serial.available())
  {
      delay(10);  
      c = Serial.read();
      if (c == 'f') {
          digitalWrite(13,HIGH);
      }
      else if (c == 'r') {
          digitalWrite(13,LOW); 
      }
      
   }
   delay(1000); 
   Serial.println(c); 
}
