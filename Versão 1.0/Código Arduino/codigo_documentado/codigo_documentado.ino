#include <Servo.h>  //Inclui a biblioteca para utilização do servo motor

#define TAM 30          //Constante para o tamanho do vetor

#define TRIG 8          //Pino Trig do sensor ultrassônico conectado ao pino 8

#define ECHO 9          //Pino ECO do sensor ultrassônico conectado ao pino 9

#define BOTAO 7         //Botão conectado ao pino digital 7

#define BIP 6           //Buzzer conectado ao pino digital 6

#define SERVO1 2        //Servo conectado ao pino digital 2

#define SERVO4 13       //Servo conectado ao pino digital 13

#define DMOTOR 1000     //Nome referência para 1000 milisegundos

#define LINHA1 3        //Sensor de linha conectado ao pino digital 3

#define LINHA2 4       //Sensor de linha conectado ao pino digital 4

Servo motor1, motor2;   //Cria dois objetos da classe Servo para o controle dos Servo motores

int tempo = 0, te = 0, td = 0, t;

int melodia[] = {660, 660, 660, 510, 660, 770, 380, 510, 380, 320, 440, 480, 450, 430, 380, 660, 760, 860, 700, 760, 660, 520, 580, 480, 510, 380, 320, 440, 480, 450, 430, 380, 660, 760, 860, 700, 760, 660, 520, 580, 480, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 500, 760, 720, 680, 620, 650, 1020, 1020, 1020, 380, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 585, 550, 500, 380, 500, 500, 500, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 500, 760, 720, 680, 620, 650, 1020, 1020, 1020, 380, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 585, 550, 500, 380, 500, 500, 500, 500, 500, 500, 500, 580, 660, 500, 430, 380, 500, 500, 500, 500, 580, 660, 870, 760, 500, 500, 500, 500, 580, 660, 500, 430, 380, 660, 660, 660, 510, 660, 770, 380};
//Frequência de cada nota em hertz

int duracaodasnotas[] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 80, 100, 100, 100, 80, 50, 100, 80, 50, 80, 80, 80, 80, 100, 100, 100, 100, 80, 100, 100, 100, 80, 50, 100, 80, 50, 80, 80, 80, 80, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 200, 80, 80, 80, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 200, 80, 80, 80, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 60, 80, 60, 80, 80, 80, 80, 80, 80, 60, 80, 60, 80, 80, 80, 80, 80, 60, 80, 60, 80, 80, 80, 80, 80, 80, 100, 100, 100, 100, 100, 100, 100};
//Duração das notas

int pausadepoisdasnotas[] = {150, 300, 300, 100, 300, 550, 575, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 350, 150, 150, 550, 325, 600, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 300, 100, 300, 550, 575};
//Pausa depois das notas

char v[TAM];    //Cria um vetor v de 30 posições
char n[TAM];    //Cria um vetor n de 30 posições

char option , comando;    //Variáveis para armazenar os comandos enviados pela Serial
int flag = 0;

void setup() {

  Serial.begin(9600);           //Inicia a Serial
  pinMode(TRIG, OUTPUT);        //Define pino 8 como saída
  pinMode(ECHO, INPUT);         //Define pino 9 como entrada
  pinMode(BOTAO, INPUT);        //Define pino 7 como entrada
  pinMode(BIP, OUTPUT);         //Define pino 6 como saída
  pinMode(3, INPUT);            //Define pino 3 como entrada
  digitalWrite(BOTAO, HIGH);    //Escreve no pino 7 o valor alto

  for (int i = 0; i < TAM; i++) {     //Preenche todas as posições dos vetores v e n com o caracter p
    v[i] = 'p';
    n[i] = 'p';
  }
  while (!Serial.available());        //Arguarda a serial ser aberta

  Serial.println("Escolha uma das opcoes: a= automatica, m= manual, c= manual continua. Para trocar de opcao basta escolher 's'");
}

void loop() {

  option = 'p';
  comando = 'p';

  if (Serial.available()) {
    option = Serial.read();
    Serial.println(option);
    if (option == 'm' || option == 'a' || option == 's' || option == 'c' || option == 'u') {
    }
    else {
      Serial.println("Opcao Invalida");
    }
  }

  if (option == 'c') {
    digitalWrite(6, HIGH);
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
    bool fast = true;
    char aux;
    Serial.println("Voce escolheu a opcao Manual Continua: f= para frente, t= tras, d= direita, e= esquerda, p= parar. ");
    while (comando != 's')
    { if (Serial.available()) {
        comando = 0; comando = Serial.read();

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
      int seg = 0, but = 0;
      seg = 11;

      if (comando == 'y') {
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
        if (seg > 0 && seg <= 10 || seg < 0) {
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
      if (comando == 't' && but == 0 ) {
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
      if (comando == 'b') {
        fast = false;
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
        motor1.write(0);
        motor2.write(180);
      }
      if (comando == 'e') {
        fast = false;
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
        motor1.write(0);
        motor2.write(0);
      }
      if (comando == 'd') {
        fast = false;
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
        motor1.write(180);
        motor2.write(180);
      }
      if (comando == 'p') {
        fast = true;
        motor1.detach();
        motor2.detach();
      }

    }
    Serial.println("Trocar opcao");
  }

  motor1.detach();
  motor2.detach();

  if (option == 'a') {
    //Indicação de entrada
    flag = 0;
    int tempo = 0;
    char v[TAM], n[TAM];
    for (int i = 0; i < TAM; i++) {
      n[i] = 'x'; v[i] = 'x';
    }
    while (flag == 0) {
      while (!Serial.available());
      Serial.setTimeout(60000);
      Serial.readBytesUntil('x', v, TAM);

      if (v[0] == 's') {
        flag++;
      }

      for (int j = 0; v[j] != 'x' && flag == 0; j++) {
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
          if (v[j] == '2') {
            tone(9, 600, 1000); delay2(1000);
          }
        }
        if (v[j] >= '0' && v[j] <= '9') {
          for (w = 0; v[j] >= '0' && v[j] <= '9'; j++ ) {
            n[w] = v[j]; w++;
          }
          j = j - 1;
          tempo = atoi(n);
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
          for (int i = 0; i < TAM; i++) {
            n[i] = 'p';
          }
        }
      }
      for (int i = 0; i < TAM; i++) {
        n[i] = 'x'; v[i] = 'x';
      }
    }
  }
  if (option == 'u') {
    digitalWrite(6, HIGH);
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
      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(120);
      motor2.write(0);
      delay(300);
      t = dist();
      if (t > 0 && t < 23) {
        motor1.write(40);
        motor2.write(40);
        delay(600);
        motor1.detach();
        motor2.detach();
        delay(1000);
        do {
          te = dist();
        } while (te < 0);
        delay(100);
        Serial.print(" aehoue: ");
        Serial.println(te);
        motor1.attach(SERVO1);
        motor2.attach(SERVO4);
        motor1.write(140);
        motor2.write(140);
        delay(1200);
        do {
          td = dist();
        } while (td < 0);
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

  if (option == 'k') {           //Caso o usuário tenha digitado a letra k

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

  if (option == 'r') {           //Caso o usuário tenha digitado a letra r
    
    digitalWrite(6, HIGH);        //Emite um sinal sonoro
    delay(500);
    digitalWrite(6, LOW);
    delay(500);
    Serial.println("CALIBRAR ");

    while (comando != 's') {      //Permanece no laço até que o usuário digite a letra s
      if (Serial.available()) {
        comando = Serial.read();
        Serial.println(comando);
        motor1.detach();
        motor2.detach();
      }

      motor1.attach(SERVO1);
      motor2.attach(SERVO4);
      motor1.write(90);
      motor2.write(90);

    }
    Serial.println("Trocar opcao");
  }
}
