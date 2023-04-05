#include "config.h"

Config::Config()
{
    this->vidas=3;
    this->dim=30;
    this->limitenemigo=200;
    this->TimeEnemigos=2000;
}

void Config::setVidas(int a)
{
    this->vidas=a;
}
void Config::setDim(int a){
    this->dim=a;
}
void Config::setTimer(int x){
    this->TimeEnemigos=x;
}
void Config::setLimiteEnemigo(int a)
{
    this->limitenemigo=a;
}
int Config::getVidas()
{
    return this->vidas;
}
int Config::getDim()
{
    return this->dim;
}
int Config::getLimit(){
    return this->limitenemigo;
}
int Config::getTimer(){
 return this->TimeEnemigos;
}
