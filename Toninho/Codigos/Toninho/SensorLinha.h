
#ifndef SENSORlINHA_H
#define SENSORlINHA_H

class SensorLinha {
  public:
    SensorLinha(int leftSensor);
    SensorLinha(int leftSensor, int rightSensor);
    SensorLinha(int leftSensor, int middleSensor, int rightSensor);
    bool detectedByLeft();
    bool detectedByMiddle();
    bool detectedByRight();
   
    
        
    
    
  private:
    int _LeftSensor, _RightSensor, _MiddleSensor;
    
    
    
};

#endif  //endif SensorLinha







