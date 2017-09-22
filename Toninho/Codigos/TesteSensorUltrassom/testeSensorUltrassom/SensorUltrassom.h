#ifndef SENSORULTRASSOM


#define SENSORULTRASSOM


class SensorUltrassom {
  public:

    SensorUltrassom(int trigger, int echo);
    int getDistance (); // Código de Marcos Paulo Manjão  (https://mpsdantas.github.io/)
    void debug();
    
  private:
  
  int _trigger;
  int _echo;
};

#endif  //endif SensorUltrassom
