#ifndef JUEGO_H
#define JUEGO_H
#include <qtimer.h>
#include <tablero.h>
#include <config.h>

class Juego
{
private:
    Config* configuracion;
    //int contadortiempo;
    Tablero* tab;
    int puntaje;
public:
    Juego();
    void setPuntaje(int);
    int getPuntaje();
    void crearTablero();
    void setConfig(Config*);
    void setContador(int);
    int getVidas();
    int getDim();
    int getLimit();
    int getValorMatriz(int,int);
    void crearenemigo();
    int getSegundosEnemig();
    void moverenemigo();
    void MovimientoParriba(int &x,int &y);
    void MovimientoPabajo(int &x,int &y);
    void MovimientoPaizq(int &x,int &y);
    void MovimientoPader(int &x,int &y);
    void sacarvida();
    bool GamerOver();
};

#endif // JUEGO_H
