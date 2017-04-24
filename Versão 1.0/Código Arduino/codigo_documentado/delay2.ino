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
