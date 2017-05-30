#ifndef URA_H
#define URA_H




class DCMotor
{
  public:
    DCMotor(int in1, int in2, int in3, int in4, int enA = 0, int enB = 0);
    void forward();
    void backward();
    void left();
    void right();
    void stop();
    void leftBack();
    void rightBack();
    void setup();
  private:
    void clockwise(int inx, int iny);
    void antiClockwise(int inx, int iny);
    int _in1, _in2, _in3, _in4, _enA, _enB;
    //const int  IN1 = 5, IN2 = 4, IN3 = 3, IN4 = 2;//pinos

};

class Sensor
{
  public:
    Sensor(int pin);
    void setup();
    boolean detected();
  private:
    int _pin;
};

class Ultrasonic
{
  public:
    Ultrasonic(int TRIG, int ECHO);
    void setup();
    long tempo();
    long dist();

  private:
    int Trig_pin;
    int Echo_pin;
    long Time_out;
    long duration, distance_cm, distance_inc;
};
#endif
