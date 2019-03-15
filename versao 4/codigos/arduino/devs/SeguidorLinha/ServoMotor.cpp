#include "ServoMotor.h"

ServoMotor::ServoMotor()
{
}

void ServoMotor::setup(int pinEsquerda, int pinDireita)
{
    pinEsq = pinEsquerda;
    pinDir = pinDireita;
    intensidade = 400;
    mDireito.attach(pinDir);
    mEsquerdo.attach(pinEsq);
}

void ServoMotor::velocidade(int Vel)
{
    if (Vel + paradoDireito > 2000)
        Vel = 500;
    intensidade = Vel;
}

void ServoMotor::calibra(int pEsq, int pDir)
{
    paradoDireito = pDir;
    paradoEsquerdo = pEsq;
}

void ServoMotor::frente()
{
    setup(pinEsq, pinDir);
    mDireito.writeMicroseconds(paradoDireito + intensidade);
    mEsquerdo.writeMicroseconds(paradoEsquerdo - intensidade);
}

void ServoMotor::viraDireita()
{
    setup(pinEsq, pinDir);
    mDireito.writeMicroseconds(paradoDireito - intensidade);
    mEsquerdo.writeMicroseconds(paradoEsquerdo - intensidade);
}

void ServoMotor::viraEsquerda()
{
    setup(pinEsq, pinDir);
    mDireito.writeMicroseconds(paradoDireito + intensidade);
    mEsquerdo.writeMicroseconds(paradoEsquerdo + intensidade);
}

void ServoMotor::re()
{
    setup(pinEsq, pinDir);
    mDireito.writeMicroseconds(paradoDireito - intensidade);
    mEsquerdo.writeMicroseconds(paradoEsquerdo + intensidade);
}

void ServoMotor::parado()
{
    mDireito.detach();
    mEsquerdo.detach();
}
