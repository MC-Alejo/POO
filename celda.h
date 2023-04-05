#ifndef CELDA_H
#define CELDA_H
#include <cosa.h>


class Celda
{
private:
    Cosa* c;
public:
    Celda();
    void setCosa(Cosa*);
    int getIDCosa();
    void setSemovio(int);
    int getSemovio();
    Cosa* getCosa();
};

#endif // CELDA_H
