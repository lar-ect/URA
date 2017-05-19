
//Funçao para a opcao Manual Continua

void manualContinua() {

  digitalWrite(6, HIGH);    //Emite um sinal sonoro
  delay(500);
  digitalWrite(6, LOW);
  delay(500);

  bool fast = true;
  char aux;
  Serial.println("Voce escolheu a opcao Manual Continua: f= para frente, t= tras, d= direita, e= esquerda, p= parar. ");

  while (comando != 's') {  // Mantem no laço até que o usuário digite s  
    if (Serial.available()) {
      comando = 0;
      comando = Serial.read();

      if (aux != comando) {
        motor1.detach();
        motor2.detach();
        if (!fast) {
          if (Serial.available()) {
            comando = Serial.read();
            break;
          }
          delay(600);
        }
      }

      aux = comando;
    }
    int seg = 11, but = 0;


    if (comando == 'y') {   //gira no sentido horário
      fast = false;
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(180);
      motor2.write(0);
    }

    if (comando == 'f' && seg > 10) {
      fast = false;
      seg = dist();
      Serial.println(seg);
      if (seg > 0 && seg <= 10 || seg < 0) {  // Se a distância for menor do que 10 cm "desligue" os motores
        motor1.detach();
        motor2.detach();
      }
      else {
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
      }
      motor1.write(180);
      motor2.write(0);
    }

    but = 0;

    if (comando == 't' && but == 0 ) {  // Anda pra frente caso o Botão esteje pressionado
      fast = false;
      but = digitalRead(BOTAO);
      Serial.println(but);
      if (but == 0) {
        motor1.detach();
        motor2.detach();
      }
      else {
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
      }
      motor1.write(0);
      motor2.write(180);
    }
    if (comando == 'b') { //Anda pra trás
      fast = false;
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(0);
      motor2.write(180);
    }
    if (comando == 'e') {   //Girar no sentido anti-horario
      fast = false;
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(0);
      motor2.write(0);
    }
    if (comando == 'd') {   //Girar no sentido horario
      fast = false;
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(180);
      motor2.write(180);
    }
    if (comando == 'p') {   //Desligar os motores
      fast = true;
      motor1.detach();
      motor2.detach();
    }

  }
  Serial.println("Trocar opcao");
}
