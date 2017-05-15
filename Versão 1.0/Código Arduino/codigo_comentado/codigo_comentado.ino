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
ls
int melodia[] = {
  660, 660, 660, 510, 660, 770, 380, 510, 380, 320, 440, 480, 450, 430, 380, 660, 760, 860, 700, 760, 660, 520, 580, 480, 510, 380, 320, 440, 480, 450, 430, 380, 660, 760, 860, 700, 760, 660, 520, 580, 480, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 500, 760, 720, 680, 620, 650, 1020, 1020, 1020, 380, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 585, 550, 500, 380, 500, 500, 500, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 500, 760, 720, 680, 620, 650, 1020, 1020, 1020, 380, 500, 760, 720, 680, 620, 650, 380, 430, 500, 430, 500, 570, 585, 550, 500, 380, 500, 500, 500, 500, 500, 500, 500, 580, 660, 500, 430, 380, 500, 500, 500, 500, 580, 660, 870, 760, 500, 500, 500, 500, 580, 660, 500, 430, 380, 660, 660, 660, 510, 660, 770, 380};
//Frequência de cada nota em hertz

int duracaodasnotas[] = {
  100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 80, 100, 100, 100, 80, 50, 100, 80, 50, 80, 80, 80, 80, 100, 100, 100, 100, 80, 100, 100, 100, 80, 50, 100, 80, 50, 80, 80, 80, 80, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 200, 80, 80, 80, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 150, 200, 80, 80, 80, 100, 100, 100, 100, 100, 150, 150, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 60, 80, 60, 80, 80, 80, 80, 80, 80, 60, 80, 60, 80, 80, 80, 80, 80, 60, 80, 60, 80, 80, 80, 80, 80, 80, 100, 100, 100, 100, 100, 100, 100};
//Duração das notas

int pausadepoisdasnotas[] = {
  150, 300, 300, 100, 300, 550, 575, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 450, 400, 500, 300, 330, 150, 300, 200, 200, 150, 300, 150, 350, 300, 150, 150, 500, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 220, 300, 100, 150, 150, 300, 300, 300, 150, 300, 300, 300, 100, 150, 150, 300, 300, 150, 150, 300, 150, 100, 420, 450, 420, 360, 300, 300, 150, 300, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 350, 150, 150, 550, 325, 600, 150, 300, 350, 150, 350, 150, 300, 150, 600, 150, 300, 300, 100, 300, 550, 575};
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
    option = Serial.read();    //Passa para option o valor da leitura da serial
    Serial.println(option);

    if (option != 'c' && option != 'a' && option != 'u' && option != 'k' && option != 'r') {
      Serial.println("Opcao Invalida");
    }

    if (option == 'c') {  //Inicia a opção manual continua
      manualContinua();
    }
    
    //motor1.detach();
    //motor2.detach();

    if (option == 'a') {    
      melodia();    //Toca a melodia
    }

    if (option == 'u') {    
      ultrassomAutomatica();    //Ultrassom automatica
    }

    if (option == 'k') {    
      seguidorDeLinha();    //Seguidor de linha
    }

    if (option == 'r') {           
      calibrar();    //Calibrar
    }
  }
}
