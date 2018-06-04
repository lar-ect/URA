/* 
 *  Configurar com os caracteres utilizados no código 
 * 
 * Usar o Tx -> Rx e Rx -> Tx (bluetooth -> Arduíno) 
 * 
 */

#include "MoveRobo.h"

MoveRobo mv; 
 

#include "Ultrassom.h"
#include <SPI.h>
#include <SD.h>

File myFile;

// trig e echo 
Ultrassom usd(3,2); // ultrassom frontal 
Ultrassom use(7,6); // ultrassom esquerdo 
Ultrassom usf(9,8); // ultrassom direito 

int comandoAtual; 



void setup() {

  mv.setup(5,4,1610,1460); 
  Serial.begin(9600);
  comandoAtual = CMD_PARA; 
 
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  
  usf.setup();
  use.setup();
  usd.setup();
 
}

void salvaDados(int ve, int vf, int vd, char cmd) {
  myFile = SD.open("test3.txt", FILE_WRITE);
  if (myFile) {
      String tmpS = ""; 
      //int ve = use.dist(); 
      tmpS += ve;
      tmpS += " ";
      //int vf = usf.dist();
      tmpS += vf;
      tmpS += " ";
      //int vd = usd.dist();
      tmpS += vd;
      tmpS += " "; 
      tmpS += cmd;
      
      Serial.print("Writing: ");
      Serial.println(tmpS); 
      myFile.println(tmpS);
      myFile.close();
 
      Serial.println("done.");
  } else {
      // if the file didn't open, print an error:
      Serial.println("error opening txt file");
  }
}

void loop() {
  if (Serial.available())
  { 
    mv.ativaProximoCMD(); 
    char c = Serial.read();
    if (c == 'f' || c == 'd' ||  c == 'e' || c == 'r' ) {
      salvaDados(use.dist(), usf.dist(), usd.dist(), c ); 
    }
    if (c == 'f') {
      // move para frente 
      comandoAtual = CMD_FRENTE; 
    }
    else if (c == 'r') {
      // move para trás 
      comandoAtual = CMD_RE; 
    } 
    else if (c == 'd') {
      comandoAtual = CMD_GIRA_DIREITA;
    }
    else if (c == 'e') {
      comandoAtual = CMD_GIRA_ESQUERDA;  
    }
    else if (c == 'q') {
      comandoAtual = CMD_PARA; 
    }
    else {
      comandoAtual = CMD_PARA; 
    }
    //Serial.println(c);     
   
    delay(20); 
  }
  mv.comandoTempo(comandoAtual,1000);
}
