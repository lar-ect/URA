
//Recebe um numero tempo e trava o programa durante este tempo
//ao mesmo tempo que verifica se o usuario digitou S

void delay2(int tempo) {
  for (int i = 0; i < tempo; i++) {
    if (Serial.available()) {
      if (Serial.read() == 's') {
        flag++;
      }
    }
    delay(1);
  }
}
