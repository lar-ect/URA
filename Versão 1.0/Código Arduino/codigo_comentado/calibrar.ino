
//Funçao para calibrar

void calibrar(){
  digitalWrite(6, HIGH);        //Emite um sinal sonoro
  delay(500);
  digitalWrite(6, LOW);
  delay(500);
  Serial.println("CALIBRAR ");

  while (comando != 's') {      //Permanece no laço até que o usuário digite a letra s
    if (Serial.available()) {
      comando = Serial.read();
      Serial.println(comando);
      motor1.detach();          //Desvincula o motor1 do pino 2
      motor2.detach();          //Desvincula o motor2 do pino 14
    }

    motor1.attach(SERVO1);      //Vincula o pino  2 ao motor1
    motor2.attach(SERVO4);      //Vincula o pino 14 ao motor2
    motor1.write(90);           //Deixa os motores parados
    motor2.write(90);

  }
  Serial.println("Trocar opcao"); 
}
