#ifndef CONFIG_H
#define CONFIG_H
#include <qtimer.h>


class Config
{
private:
    int dim;
    int vidas;
    int TimeEnemigos;
    int limitenemigo;
public:
    Config();
    void setVidas(int);
    void setDim(int);
    void setTimer(int);
    void setLimiteEnemigo(int);
    int getVidas();
    int getDim();
    int getLimit();
    int getTimer();

};

#endif // CONFIG_H
