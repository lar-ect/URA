
#include "Ultrassom.h"
#include <SPI.h>
#include <SD.h>

File myFile;

// trig e echo 
Ultrassom usf(3,2);  // ultrassom frontal 
Ultrassom use(7,6); // ultrassom esquerdo 
Ultrassom usd(9,8); // ultrassom direito 

String tmpS; 

void setup() {
 
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
  tmpS = ""; 
}

void loop() {

    myFile = SD.open("test2.txt", FILE_WRITE);
    if (myFile) {
      int ve = use.dist(); 
      tmpS += ve;
      tmpS += " ";
      int vf = usf.dist();
      tmpS += vf;
      tmpS += " ";
      int vd = usd.dist();
      tmpS += vd;
      tmpS += " "; 
      
      Serial.print("Writing: ");
      Serial.println(tmpS); 
      myFile.println(tmpS);
      myFile.close();
      tmpS = ""; 
      Serial.println("done.");
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening txt file");
    }
   
    delay(1000); 
}
