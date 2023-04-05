#include "juego.h"

Juego::Juego()
{
    this->puntaje=0;
    this->configuracion=new Config();

}

void Juego::setPuntaje(int x){
    this->puntaje=x;
}

int Juego::getPuntaje(){
    return this->puntaje;
}

void Juego::crearTablero(){
    this->tab=new Tablero(this->configuracion->getLimit());
    this->tab->CrearMatriz(this->configuracion->getDim());
}
void Juego::setConfig(Config* a){
    this->configuracion=a;
}
void Juego::setContador(int x){
    configuracion->setTimer(x);
}

int Juego::getDim(){
    return this->configuracion->getDim();
}

int Juego::getLimit(){
    return this->configuracion->getLimit();
}

int Juego::getSegundosEnemig(){
    return this->configuracion->getTimer();
}

int Juego::getVidas(){
 return this->configuracion->getVidas();
}

int Juego::getValorMatriz(int i,int j){
    return this->tab->valorMatriz(i,j);
}

void Juego::MovimientoParriba(int &x,int &y){
    this->tab->MovimientoParriba(x,y,configuracion->getDim());
}
void Juego::MovimientoPabajo(int &x,int &y){
    this->tab->MovimientoPabajo(x,y,configuracion->getDim());
}
void Juego::MovimientoPaizq(int &x,int &y){
    this->tab->MovimientoPaizq(x,y,configuracion->getDim());
}
void Juego::MovimientoPader(int &x,int &y){
    this->tab->MovimientoPader(x,y,configuracion->getDim());
}

void Juego::crearenemigo(){
    tab->crearEnemigos(this->configuracion->getDim());
}

void Juego::moverenemigo(){
    tab->movimientoEnemigo(this->configuracion->getDim());
}

void Juego::sacarvida(){

    if( this->tab->Enemigotocopersonaje() ==true){
        configuracion->setVidas(configuracion->getVidas()-1);
        tab->setTocarPersonaje(false);
    }
}

bool Juego::GamerOver(){
    bool a=false;
    if(this->configuracion->getVidas()==0){
        tab->sacarPersonajeDelTablero(configuracion->getDim());
        a=true;
    }
    return a;
}
