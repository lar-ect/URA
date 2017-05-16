
//Toca uma melodia

void melodia(){
  //Indicação de entrada
  flag = 0; 
  int tempo = 0;
  char v[TAM], n[TAM];
  for (int i = 0; i < TAM; i++) { //Preenche os vetores n e v com o caracter x.
    n[i] = 'x'; 
    v[i] = 'x';
  }
  while (flag == 0) { // Enquanto a variável flag for 0, lê o número de bytes até encontrar o caracter x, ou até o tempo acabar.
    while (!Serial.available());
    Serial.setTimeout(60000);
    Serial.readBytesUntil('x', v, TAM);

    if (v[0] == 's') {
      flag++;
    }

    for (int j = 0; v[j] != 'x' && flag == 0; j++) { // Laço para definir o tom para tocar uma nota,se o caracter do vetor v for 1.
      int w = 0;
      if (v[j] == 'm') {
        j++;
        if (v[j] == '1') {
          for (int nota = 0; nota < 156; nota++) {
            int duracaodanota = duracaodasnotas[nota];
            tone(BIP, melodia[nota], duracaodanota);
            delay2(pausadepoisdasnotas[nota]);
          }
        }
        if (v[j] == '2') { // Define um tom específico caso o caracter na posição j do vetor v seja 2.
          tone(9, 600, 1000); 
          delay2(1000);
        }
      }
      if (v[j] >= '0' && v[j] <= '9') { // Caso o caracter na posição j do vetor estiver entre 0 e 9, copia esse valor para o vetor n.
        for (w = 0; v[j] >= '0' && v[j] <= '9'; j++ ) {
          n[w] = v[j]; 
          w++;
        }
        j = j - 1;
        tempo = atoi(n);// Converte os caracteres do vetor n em números.
        if (v[j - w] == 'f') {
          motor1.attach(SERVO1);
          motor2.attach(SERVO4);
          motor1.write(180);
          motor2.write(0);
          delay2(tempo);
          motor1.detach();
          motor2.detach();
          delay2(DMOTOR);
        }
        if (v[j - w] == 't') {
          motor1.attach(SERVO1);
          motor2.attach(SERVO4);
          motor1.write(0);
          motor2.write(180);
          delay2(tempo);
          motor1.detach();
          motor2.detach();
          delay2(DMOTOR);
        }
        if (v[j - w] == 'd') {
          motor1.attach(SERVO1);
          motor2.attach(SERVO4);
          motor1.write(180);
          motor2.write(180);
          delay2(tempo);
          motor1.detach();
          motor2.detach();
          delay2(DMOTOR);
        }
        if (v[j - w] == 'e') {
          motor1.attach(SERVO1);
          motor2.attach(SERVO4);
          motor1.write(0);
          motor2.write(0);
          delay2(tempo);
          motor1.detach();
          motor2.detach();
          delay2(DMOTOR);
        }
        tempo = 0;
        for (int i = 0; i < TAM; i++) { // Preenche todas as posições do vetor n com o caracter p.
          n[i] = 'p';
        }
      }
    }
    for (int i = 0; i < TAM; i++) {// Preenche todas as posições do vetor n e v com o caracter x.
      n[i] = 'x'; 
      v[i] = 'x';
    }
  }
}
