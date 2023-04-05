#include "celda.h"
#include <cosa.h>
#include <personaje.h>
#include <pared.h>
#include <piso.h>
#include <enemigoaleatorio.h>
#include <enemigosalto.h>
#include <enemigoseguidor.h>

Celda::Celda()
{
    c=nullptr;
}

void Celda::setCosa(Cosa* a){
   c=a;
}

int Celda::getIDCosa(){
    return this->c->getID();
}

Cosa* Celda::getCosa(){
    return c;
}

void Celda::setSemovio(int a){
    this->c->setSemovio(a);
}

int Celda::getSemovio(){
    return this->c->getSemovio();
}
