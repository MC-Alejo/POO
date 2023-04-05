#ifndef TABLERO_H
#define TABLERO_H
#include <celda.h>
#include <cosa.h>
#include <pared.h>
#include <piso.h>

#include <QtCore/QObject>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

class Tablero
{
private:
    Celda** board;
    int cantEnemigos;
    int cantEnemigosActuales;
    bool tocarpersonaje;
    int contadorde5;
public:
    Tablero(int);
    void CrearMatriz(int);
    void crearEnemigos(int);
    void generarpos(int&,int&,int);
    void movimientoEnemigo(int);
    void eliminarEnemigo(int,int);
    int valorMatriz(int,int);
    bool comprobarLimiteEnemigo();
    void setcantEnemigos(int);
    void MovimientoEAleatorio(int,int,int);
    void MovimientoSeguidor(int,int,int);
    void MovimientoSaltoSeguidor(int,int,int);
    void BuscarPersonaje(int&,int&,int);
    bool Enemigotocopersonaje();
    void setTocarPersonaje(bool);
    void sacarPersonajeDelTablero(int);
    int personaje_enemigosalto(int,int);

    //Movimiento Personaje:
    void MovimientoParriba(int &x,int &y,int);
    void MovimientoPabajo(int &x,int &y,int);
    void MovimientoPaizq(int &x,int &y,int);
    void MovimientoPader(int &x,int &y,int);

    //Movimeinto Enemigo:
    void moverEizq(int,int);
    void moverEder(int,int);
    void moverEarr(int,int);
    void moverEabj(int,int);
    void dobleizq(int,int);
    void dobleder(int,int);
    void doblearri(int,int);
    void dobleabaj(int,int);

    //Funciones Ejercicio 7 "crear matriz abierta"
    int **LLenarMat(int,int,int,int);
    void primerapos(int **,int,int, int &x,int &y,int);
    void contadordevisitas(int **,int,int, int,int **,int,int);
    bool matrizcerrada(int **, int **, int,int,int,int);
    bool filasdeunos(int **,int, int,int , int);
    bool columnadeunos(int **,int, int,int,int);
    bool borradiagonal(int **,int,int,int,int,int,int);
};

#endif // TABLERO_H
