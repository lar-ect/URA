
///LEMBRAR QUE O PINO RECEPÇÃO (Rx) DO BLUETOOTH DEVE RECEBER TENSÃO 3V3
///DIVISOR DE TENSÃO ==> resistor ligado ao 5V = Rv;resistor ligado ao GND = Rg;Voltagem de entrada = Ve (5V por padrão do Arduino); Voltagem de saída = Vo (deve ser 3.3 V)
/// Ve-->Rv-->^Vo^-->Rg-->GND
///CALCULO : Vo=(Rg*Ve)/(Rv+Rg) ==> 0.66=Rg/(Rv+Rg) == (5/3.3)-1 = (Rv/Rg) ≃≃ 0.5152*Rg = Rv
/// Lembrar que o (Rx,Tx) da Placa Bluetooth é conectada no arduino respectivamente (Tx,Rx)
///(Rx,Tx)BT-->(Tx,Rx)ARDUINO -RECEPÇÃO -TRANSMISSÃO
///Configurar com os caracteres utilizados no código

#include "TerminalSerial.h"

TerminalSerial ts;

char c = 45;

int pinSensor = 4;
const int AIA = 10;     //
const int AIB = 11;     //  PORTAS PWM ~
const int BIA = 6;      //   ~3 ~5 ~6 ~9 ~10 ~11
const int BIB = 9;      //

int variavelTempo, passaNaLinha = 0;
double tempoPorVolta = 0;
unsigned i = 0;
bool s;
int speed = 255;

//=====================================
//       FUNÇÕES DE MOVIMENTO

void re()
{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}
void frente()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}
void parado() {
  analogWrite(AIA, 0);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, 0);
}
void esq()
{
  analogWrite(AIA, speed);
  analogWrite(AIB, 0);
  analogWrite(BIA, 0);
  analogWrite(BIB, speed);
}
void dir()

{
  analogWrite(AIA, 0);
  analogWrite(AIB, speed);
  analogWrite(BIA, speed);
  analogWrite(BIB, 0);
}

//================================================
//                  SETUP

void setup() {

  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);
  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);
  pinMode(pinSensor, INPUT);

  parado();
  ts.comeco();

  s = (digitalRead(pinSensor));
  Serial.begin(9600);
  Serial.println("Digite 'w' para começar");
  Serial.flush();
  delay(100);
}

//=========================================
//              LOOP

void loop() {
  do {
    if (Serial.available())
      c = Serial.read();
  } while (c == 10);
  if (c == 'w')
    frente();
  else if (c == 's')
    re();
  else if (c == 'a')
    esq();
  else if (c == 'd')
    dir();
  else if (c == 'p') {
    parado();
  }

  //-----------------------------------------
  //    OBTENÇÃO DA DIFERENÇA DE TEMPO

  int sensor = digitalRead(pinSensor);                    //Leitura do sensor

  if (!s == sensor) {
    
    if (passaNaLinha == 0) 
    
      variavelTempo = millis();                           //Se houver mudança de estado e estiver na primeira iteração começa a contagem de tempo
      
    passaNaLinha++;
    s = (sensor);
    
  }
  
  if (passaNaLinha == 3) {
    
    tempoPorVolta = (millis() - variavelTempo) / 1000.00; //Se passaNaLinha for 3, tem-se tempo por volta ja em segundos
    parado();
    passaNaLinha++;
    
  }

  //-----------------------------------------
  //            OPERAÇÕES
  
  if (passaNaLinha >= 3 && c != 'p') {                    //Se passaNaLinha for 3, significa que houve 3 mudanças de estado, obtendo os valores apenas do inicio ou do final de uma fita
    
    Serial.print(i);
    Serial.print(':');
    Serial.print(tempoPorVolta);
    Serial.println(" segundos");

    ts.getExperimento(i, tempoPorVolta);  //obtenção dos parâmetros do experimento

    Serial.print("Digite caracter de comando: w->continua; p->imprimir experimentos; d->deletar experimento; r->resetar todos experimentos");

    do {

      c = ts.charRead();                  //digitação e verificação do char de comando

      if (c == 'd')                       //deletar i (1-n) Experimento
        ts.deletarDado();
      if (c == 'p')                       //imprimir todos os experimentos
        ts.printExperimento();
      if (c == 'r') {                     //apaga todos os dados salvos
        ts.comeco();
        speed = ts.velocidade();          //reseta a velocidade de 0 a 255
      }

    } while (c != 'w');                   //checagem de permissão para recomeçar o a função loop

    passaNaLinha = 0;
    i++;

    Serial.println("Digite 'w' para começar");
    
  }
  
}
