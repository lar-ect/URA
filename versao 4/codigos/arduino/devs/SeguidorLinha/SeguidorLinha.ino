#include "ServoMotor.h"

int RightSensor = 10;
int LeftSensor = 11;

ServoMotor motores;

bool right, left;

void setup() {
  // put your setup code here, to run once:
  pinMode(RightSensor, INPUT);
  pinMode(LeftSensor, INPUT);
  motores.setup(4, 5);
  motores.calibra(1635,1470);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  right = digitalRead(RightSensor);
  left = digitalRead(LeftSensor);
  Serial.print("Dir: ");
  Serial.print(right);
  Serial.print(" Esq: ");
  Serial.println(left);

  if ( right == 0 && left == 0 ) // caminho certo
  {
      motores.frente();
      Serial.println("frente");
      delay(50);
      return;
  }

  else if ( right == 1 && left == 1 ) // condição de parada
  {
      motores.parado();
      Serial.println("parado");
      delay(2000);
      return;
  }
  
  else if ( left == 1 && right == 0 ) // linha detectada na esquerda
  {
      motores.viraEsquerda();
      Serial.println("esq");
      delay(50);
      return;
  }

  else if ( left == 0 && right == 1 ) // linha detectada na direita  
  {
      motores.viraDireita();
      Serial.println("dir");
      delay(50);
      return;
  }
  
  delay(10000);
}
