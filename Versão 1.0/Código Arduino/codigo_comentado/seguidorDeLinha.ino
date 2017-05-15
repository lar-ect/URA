
//Funçao que segue linha

void seguidorDeLinha(){
  digitalWrite(6, HIGH);        //Emite um sinal sonoro
  delay(500);
  digitalWrite(6, LOW);
  delay(500);

  Serial.println("Voce escolheu a opcao Manual Continua: f= para frente, t= tras, d= direita, e= esquerda, p= parar. ");

  int seg1, seg2;     //Variáveis para amrmazenar as leituras dos sensores de linha

  while (comando != 's') {          //Permanece no laço até que o usuário digite a letra s
    if (Serial.available()) {
      comando = Serial.read();
      Serial.println(comando);
      motor1.detach();
      motor2.detach();
      delay(DMOTOR);
    }

    seg1 = digitalRead(LINHA1);
    seg2 = digitalRead(LINHA2);
    motor1.attach(SERVO1);
    motor2.attach(SERVO4);
    motor1.write(95);
    motor2.write(75);

    if (seg2 == 1) {            // Se o sensor conectado ao pino 3 detectou uma linha
      motor1.detach();
      motor2.detach();
      delay(1000);
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);

      while (seg2 == 1) {             //Permanece no laço até que o robô saia da linha
        seg2 = digitalRead(LINHA2);
        motor1.write(70);
        motor2.write(70);
      }
      motor1.detach();
      motor2.detach();
      delay(1000);
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
    }

    if (seg1 == 1) {            // Se o sensor conectado ao pino 4 detectou uma linha
      motor1.detach();
      motor2.detach();
      delay(1000);
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);

      while (seg1 == 1) {              //Permanece no laço até que o robô saia da linha
        seg1 = digitalRead(LINHA1);
        motor1.write(110);
        motor2.write(110);
      }
      motor1.detach();
      motor2.detach();
      delay(1000);
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
    }

  }
  Serial.println("Trocar opcao"); 
}
