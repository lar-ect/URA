
//funçao para a opcao Ultrassom automatica

void ultrassomAutomatica(){
  
  digitalWrite(6, HIGH);    //Emite um sinal sonoro
  delay(500);
  digitalWrite(6, LOW);
  delay(500);
  
  Serial.println("Voce escolheu a opcao Ultrassom automatica ");
  while (comando != 's') {
    if (Serial.available()) {
      comando = Serial.read();
      Serial.println(comando);
    }
    t = 30;
    motor1.attach(SERVO1);    //Vincula o pino  2 ao motor1
    motor2.attach(SERVO4);    //Vincula o pino  14 ao motor2
    motor1.write(120);        //Gira no sentido anti-horario
    motor2.write(0);
    delay(300);
    t = dist();
    
    if (t > 0 && t < 23) {    //Se a distancia estiver entre 0 e 23 cm
      motor1.write(40);       //Anda pra frente por 600 milliSegundos
      motor2.write(40);
      delay(600);
      motor1.detach();        //Desvincula o motor1 do pino 2
      motor2.detach();        //Desvincula o motor2 do pino 14
      delay(1000);
      
      do {                    //Garante que a variavel te seja positiva
        te = dist();
      } 
      while (te < 0);
      
      delay(100);
      Serial.print(" aehoue: ");
      Serial.println(te);
      motor1.attach(SERVO1);  
      motor2.attach(SERVO4);
      motor1.write(140);    //Anda para tras 
      motor2.write(140);
      delay(1200);
      
      do {
        td = dist();
      }
      while (td < 0);
      motor1.detach();
      motor2.detach();
      delay(1000);
      /* motor1.attach(SERVO1);
       motor2.attach(SERVO4);
       motor1.write(40);
       motor2.write(40);
       delay(600); */
      Serial.print(" aehoud: ");
      Serial.println(td);
      if (te > td) {
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
        motor1.write(40);
        motor2.write(40);
        delay(1200);
        motor1.detach();
        motor2.detach();
        delay(1000);
      }
      else {
        /* motor1.attach(SERVO1);
         motor2.attach(SERVO4);
         motor1.write(140);
         motor2.write(140);
         delay(600);
         motor1.detach();
         motor2.detach(); */
      }

    }
  }
  Serial.println("Trocar opcao");  
}  
