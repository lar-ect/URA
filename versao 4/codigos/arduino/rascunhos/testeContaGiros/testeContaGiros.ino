 #include <Servo.h>
 
 Servo mEsquerdo;
 Servo mDireito;

 bool sensorAtual = false; 
 bool sensorAnterior  = false; 

 int contTransicoes = 0; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  mEsquerdo.attach(4); 
  mEsquerdo.writeMicroseconds(1600); 
}

void loop() {
  // identificação dos pinos do sensore http://dm.lnwfile.com/_/dm/_raw/nv/kw/23.png 
  int ge = analogRead(A4); 
  Serial.print(sensorAtual); 
  Serial.println(); 
  if ( ge > 350) 
    sensorAtual = true; 
  else
    sensorAtual = false; 

 // detecta a transição da subida da onda 
 if ( ! sensorAnterior && sensorAtual ) {
  contTransicoes++; 
  if (contTransicoes > 60 )
    mEsquerdo.writeMicroseconds(1470);
 }
 sensorAnterior = sensorAtual; 
  
  
}
