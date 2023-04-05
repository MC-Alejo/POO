#include "cosa.h"

Cosa::Cosa()
{

}

int Cosa::getID()
{
    return this->ID;
}

void Cosa::setSemovio(int a){
    this->semovio=a;
}

int Cosa::getSemovio(){
    return this->semovio;
}

Cosa::~Cosa(){}

