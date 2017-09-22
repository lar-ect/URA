
#ifndef SENSORlINHA_H
#define SENSORlINHA_H

class SensorLinha {
  public:
    SensorLinha(int Sensor);
    bool detectedBySensor();
    int debug();
    void setLimiar(int l);






  private:
    int _sensor;
    int _l;



};

#endif  //endif SensorLinha







