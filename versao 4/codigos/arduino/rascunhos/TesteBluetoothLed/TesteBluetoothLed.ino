/*
 * Exemplo de como usar o Bluetooth com SoftwareSerial 
 * Fonte: http://labdegaragem.com/forum/topics/tutorial-controlando-o-arduino-via-bluetooth 
 * 
 */

 
String command = ""; // Stores response of bluetooth device

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
      char c = Serial.read();
      if (c == 'f') {
          digitalWrite(13,HIGH);
      }
      else if (c == 'r') {
          digitalWrite(13,LOW); 
      }
      
   }
}
