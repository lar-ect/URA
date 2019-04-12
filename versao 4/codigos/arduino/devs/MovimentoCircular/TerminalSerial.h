#include <Arduino.h>
class TerminalSerial {

  public:
    TerminalSerial comeco();
    double numRead(int limite);                     //class
    char charRead();
    void getExperimento(unsigned i, double dtempo); //lap
    void deletarDado();
    void printExperimento();      //f
    int velocidade();             //lap

  private:
    double vLinear[20];
    double vAngular[20];
    unsigned tempo[20];
    unsigned angulo[20];
    double raio[20];
};
