
/*
 * Experimento para estudo da cinemática
 * - Estudo do movimento retilíneo uniforme 
 * 
 * Obtenção do tempo para o cálculo da velocidade considerando 
 * que o distância entre o ponto inicial e final é conhecida 
 * 
 * As marcações dos pontos são linhas pretas
 * 
 * Quando o robô ler o branco o sinal do sensor é 0 
 */
#include "ServoMotor.h" 

// motor esquerdo e direito 
ServoMotor sm;

// armazena o comando vindo da serial 
char c = 'x';
// para contagem das transições entre branco e preto 
int contMudanca = 0; 
// contador de tempo 
unsigned long tempoInicial; 
unsigned long primeiroTempo; 
unsigned long tempoAtual;
// Sensor instaldo no pino 12 
int pinSensor = 12; 
// estados do sensor 
bool refAnterior = false; // lendo branco recebe 0 
bool refAtual = false;  // lendo branco recebe 0  

void setup() {
  Serial.begin(9600); 
  pinMode(pinSensor,INPUT); 
  sm.setup(2,3);
  sm.calibra(1475,1465);
  delay(100); 
  sm.parado(); 
}

void loop() {
  refAtual = digitalRead(pinSensor);
  // Ler um caracter da porta serial quando disponível 
  if (Serial.available())
  {
    c = Serial.read();
    if (c == 'i') { // iniciar o experimento 
      sm.frente(); 
    }
    else if (c == 'p') { // parar o experimento 
      sm.parado();
      contMudanca = 0; 
    }
  }
  if ( ! refAnterior && refAtual) { // detectar transição entre branco e preto 
    contMudanca++; 
    if (contMudanca == 1) { // primeira transição 
      primeiroTempo = millis(); 
      Serial.println("1: 0"); 
    }
    else {
      tempoAtual = millis(); 
      Serial.print(contMudanca);
      Serial.print(": "); 
      Serial.println(tempoAtual - primeiroTempo); 
    }
    
    
  }
  
  refAnterior = refAtual; 
  delay(30); // intervalo mínimo entre as leituras do sensor de reflectância 
}
