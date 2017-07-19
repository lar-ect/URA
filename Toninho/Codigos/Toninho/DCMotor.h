#ifndef DCMOTOR_H
#define DCMOTOR_H




class DCMotor
{
  public:
    DCMotor(int in1, int in2, int in3, int in4);
    void forward();
    void backward();
    void left();
    void right();
    void stop();
    void slowForward();
    void slowBackward();
    void slowLeft();
    void slowRight();
    void leftBack();
    void rightBack();
    
  private:
    void clockwise(int inx, int iny);
    void antiClockwise(int inx, int iny);
    bool slowMode(long interval);
    void stopDCMotor(int inx, int iny);
    int _in1, _in2, _in3, _in4;
    unsigned long previousMillis = millis();
    bool estado = false;
    //const int  IN1 = 5, IN2 = 4, IN3 = 3, IN4 = 2;//pinos

};

#endif  //endif DCMotor

