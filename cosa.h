#ifndef COSA_H
#define COSA_H


class Cosa
{
protected:
    int ID;
    int semovio;
public:
    Cosa();
    int getID();
    void setSemovio(int);
    int getSemovio();
    virtual ~Cosa()=0;
};

#endif // COSA_H
