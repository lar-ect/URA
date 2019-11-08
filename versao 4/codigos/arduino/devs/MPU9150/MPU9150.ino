// I2C device class (I2Cdev) demonstration Arduino sketch for MPU9150
// 1/4/2013 original by Jeff Rowberg <jeff@rowberg.net> at https://github.com/jrowberg/i2cdevlib
//          modified by Aaron Weiss <aaron@sparkfun.com>
//
// Changelog:
//     2011-10-07 - initial release
//     2013-1-4 - added raw magnetometer output

/* ============================================
I2Cdev device library code is placed under the MIT license

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#include "Wire.h"

// I2Cdev and MPU9150 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include "I2Cdev.h"
#include "MPU9150.h"
#include "helper_3dmath.h"
//#include <AK8963.h>

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for InvenSense evaluation board)
// AD0 high = 0x69
MPU9150 accelGyroMag;

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t mx, my, mz;

#define G_GAIN 0.00875
#define AA 0.98

float acelx, acely, acelz, rate_gyr_x, rate_gyr_y, rate_gyr_z, gyroXangle, gyroYangle, gyroZangle;
float AccXangle, AccYangle, AccZangle, CFangleX, CFangleY, CFangleZ;
float const_calib = 16071.82;
float const_gravid = 9.81;

unsigned long pT;

void setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();
    // initialize serial communication
    // (38400 chosen because it works as well at 8MHz as it does at 16MHz, but
    // it's really up to you depending on your project)
    Serial.begin(115200);
    // Inicializa o dispositivo I2C
    Serial.println("Initializing I2C devices...");
    accelGyroMag.initialize();
    // Verifica a Conecção;
    Serial.println("Testing device connections...");
    Serial.println(accelGyroMag.testConnection() ? "MPU9150 connection successful" : "MPU9150 connection failed");
    unsigned long pT = 0; //contador para determinar tempo de inicialização
}
void loop() {
    unsigned long cT = millis();//contar o tempo de loop;
    accelGyroMag.getMotion9(&ax, &ay, &az, &gx, &gy, &gz, &mx, &my, &mz);//obtem os valores brutos dos sensores;
    unsigned long dT = cT - pT;
    pT = cT;
    acelx = ax * const_gravid / const_calib;
    acely = ay * const_gravid / const_calib;
    acelz = az * const_gravid / const_calib;
    // Converte valor do acelerometro com base nos 3 eixos
    AccXangle = (atan2(ax, sqrt(pow(ay,2) + pow(az,2)))*180) / 3.14;
    AccYangle = (atan2(ay, sqrt(pow(ax,2) + pow(az,2)))*180) / 3.14;
    AccZangle = (atan2(az, sqrt(pow(ax,2) + pow(ay,2)))*180) / 3.14;

    // Converte valor do giro em graus por seg
    // multiplicando uma contante relacionada à taxa de amostragem do sensor
    // nesse caso, a taxa é +-250g -> 0.00875
    rate_gyr_x = gx*G_GAIN;
    rate_gyr_y = gy*G_GAIN;
    rate_gyr_z = gz*G_GAIN;
    // Calcula a distância percorrida por integração simples
    // com base no tempo de loop (dT = cT - pT)
    gyroXangle+=rate_gyr_x*dT;
    gyroYangle+=rate_gyr_y*dT;
    gyroZangle+=rate_gyr_z*dT;
    // Fusão dos dados: giro + accel
    // Métodos: filtro complementar ou filtro de kalman
    // Optei pelo Filtro Complementar por ser mais simples de se aplicar do que o Filtro de Kalman.
    // Eficiencia bastante satisfatoria, segundo teoria
    // Atribui peso de 0.98 ao valor do giro e 0.02 ao acelerometro
    // O giroscópio tem leitura muito boa, mas também apresenta oscilação do valor.
    // Acelerômetro, por outro lado, é muito ruidoso, mas o desvio é zero.
    CFangleX=AA*(CFangleX+rate_gyr_x*(dT/1000)) +(1 - AA) * AccXangle;
    CFangleY=AA*(CFangleY+rate_gyr_y*(dT/1000)) +(1 - AA) * AccYangle;
    CFangleZ=AA*(CFangleZ+rate_gyr_z*(dT/1000)) +(1 - AA) * AccZangle;

//    these methods (and a few others) are also available
//    accelGyroMag.getAcceleration(&ax, &ay, &az);
//    accelGyroMag.getRotation(&gx, &gy, &gz);
    //Exibe os angulos
    Serial.print("X ");
    Serial.print(CFangleX);Serial.print("\t");
    Serial.print("Y ");
    Serial.print(CFangleY);Serial.print("\t");
    Serial.print("Z ");
    Serial.print(CFangleZ);Serial.print("\t");
//    Serial.print(ax); Serial.print("\t");
//    Serial.print(ay); Serial.print("\t");
//    Serial.print(az); Serial.print("\t");
//    Serial.print(gx); Serial.print("\t");
//    Serial.print(gy); Serial.print("\t");
//    Serial.print(gz); Serial.print("\t");
//    Serial.print(int(mx)/**int(mx)*/); Serial.print("\t");
//    Serial.print(int(my)/**int(my)*/); Serial.print("\t");
//    Serial.print(int(mz)/**int(mz)*/); Serial.print("\t | ");

    

//    const float N = 256;
//    float mag = mx*mx/N + my*my/N + mz*mz/N;
    //Serial.print(mag); Serial.print("\t");
//    for (int i=0; i<mag; i++)
//        Serial.print("*");
  Serial.print("\n");
    //delay(50);
}

