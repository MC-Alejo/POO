#include "tablero.h"
#include <celda.h>
#include <cosa.h>
#include <pared.h>
#include <piso.h>
#include <stdlib.h>
#include <personaje.h>

//enemigos

#include <enemigoaleatorio.h>
#include <enemigoseguidor.h>
#include <enemigosalto.h>

Tablero::Tablero(int a)
{
    this->cantEnemigos=a;
    this->cantEnemigosActuales=0;
    this->tocarpersonaje=false;
    this->contadorde5=0;
}


void Tablero::CrearMatriz(int dim){
    int numero1=1;
    int numero2=0;
    bool verificador=false;
    int** Matriz = LLenarMat(dim,dim,numero1,numero2);

    Celda** MatrizAux;
    MatrizAux = new Celda*[dim];
    for(int i=0;i<dim;i++){
        MatrizAux[i]= new Celda[dim];
    }



    int **vistos;
    vistos = new int*[dim];

    for(unsigned int i=0; i<dim; i++){
        vistos[i] = new int[dim];
    }


    int posx=0;
    int posy=0;

    primerapos(Matriz,dim,dim,posx,posy,numero2);
    contadordevisitas(Matriz,posx,posy,numero1,vistos,dim,dim);
    verificador=matrizcerrada(Matriz,vistos,dim,dim,numero1,numero2);






//Ejercicio 7 (main)..................
    if(verificador==false){

    for (int i=0; i<dim; i++){
        for (int j=0; j<dim;j++){
            if((*(*(Matriz+i)+j))==numero1){
                if(filasdeunos(Matriz,i,j,dim,numero1)==true){
                    *(*(Matriz+i)+j) = numero2;
                }
                if(columnadeunos(Matriz,i,j,dim,numero1)==true){
                  *(*(Matriz+i)+j) = numero2;
                }
            }
        }
        }
    }




if(verificador==false)
{

    for (int i=0; i<dim; i++){
        for (int j=0; j<dim;j++){


                if((*(*(Matriz+i)+j)) == numero1)
                {


                    if(borradiagonal(Matriz,i-1,j-1,dim,dim,numero1,numero2)==true){
                        j=dim+1;
                        i=dim+1;
                        verificador=true;
                    }
                    else if(borradiagonal(Matriz,i-1,j+1,dim,dim,numero1,numero2)==true){
                        j=dim+1;
                        i=dim+1;
                        verificador=true;
                    }
                    else if(borradiagonal(Matriz,i+1,j-1,dim,dim,numero1,numero2)==true){
                        j=dim+1;
                        i=dim+1;
                        verificador=true;
                    }
                    else if(borradiagonal(Matriz,i+1,j+1,dim,dim,numero1,numero2)==true){
                        j=dim+1;
                        i=dim+1;
                        verificador=true;
                    }




                }
            }
         }
}

    this->board=MatrizAux;

//creo la matriz de celdas

    for (int i=0; i<dim; i++){
        for (int j=0; j<dim;j++){
            if(Matriz[i][j]==1)
            {
                Pared* a=new Pared();
                this->board[i][j].setCosa(a);
            }
            else {
                Piso* a=new Piso();
                this->board[i][j].setCosa(a);
            }
        }
    }


    posx=0;
    posy=0;

    generarpos(posx,posy,dim);

    Personaje *a=new Personaje();
    this->board[posx][posy].setCosa(a);



    for(int i=0; i<dim; i++){
        delete[] Matriz[i];
        delete[] vistos[i];

    }
    delete Matriz;
    delete vistos;
}


//.................................................................................................
//Movimientos

void Tablero::MovimientoParriba(int &x,int &y,int dim){
    int posx=0;
    int posy=0;
    BuscarPersonaje(posx,posy,dim);
    x=posx;
    y=posy;

    if((posx-1)>=0){


    if(this->board[posx-1][posy].getIDCosa()==0)
    {
        Cosa* aux=this->board[posx][posy].getCosa();
        Cosa* aux2=this->board[posx-1][posy].getCosa();
        this->board[posx-1][posy].setCosa(aux);
        this->board[posx][posy].setCosa(aux2);
    }
    else if((valorMatriz(x-1,y)==3)||(valorMatriz(x-1,y)==4)||(valorMatriz(x-1,y)==5))
    {
        eliminarEnemigo(x-1,y);
        setTocarPersonaje(true);
        Cosa* aux=this->board[posx][posy].getCosa();
        Cosa* aux2=this->board[posx-1][posy].getCosa();
        this->board[posx-1][posy].setCosa(aux);
        this->board[posx][posy].setCosa(aux2);
    }
    }

}



void Tablero::MovimientoPabajo(int &x,int &y,int dim){
    int posx=0;
    int posy=0;
    BuscarPersonaje(posx,posy,dim);
    x=posx;
    y=posy;

    if((posx+1)<dim){

    if(board[posx+1][posy].getIDCosa()==0)
    {
        Cosa* aux=board[posx][posy].getCosa();
        Cosa* aux2=board[posx+1][posy].getCosa();
        board[posx+1][posy].setCosa(aux);
        board[posx][posy].setCosa(aux2);
    }
    else if((valorMatriz(x+1,y)==3)||(valorMatriz(x+1,y)==4)||(valorMatriz(x+1,y)==5))
    {
        eliminarEnemigo(x+1,y);
        setTocarPersonaje(true);
        Cosa* aux=board[posx][posy].getCosa();
        Cosa* aux2=board[posx+1][posy].getCosa();
        board[posx+1][posy].setCosa(aux);
        board[posx][posy].setCosa(aux2);
    }
   }

}

void Tablero::MovimientoPaizq(int &x,int &y,int dim){
    int posx=0;
    int posy=0;
    BuscarPersonaje(posx,posy,dim);
    x=posx;
    y=posy;

    if((posy-1)>=0){

    if(board[posx][posy-1].getIDCosa()==0)
    {
        Cosa* aux=board[posx][posy].getCosa();
        Cosa* aux2=board[posx][posy-1].getCosa();
        board[posx][posy-1].setCosa(aux);
        board[posx][posy].setCosa(aux2);
    }
    else if((valorMatriz(x,y-1)==3)||(valorMatriz(x,y-1)==4)||(valorMatriz(x,y-1)==5))
    {
        eliminarEnemigo(x,y-1);
        setTocarPersonaje(true);
        Cosa* aux=board[posx][posy].getCosa();
        Cosa* aux2=board[posx][posy-1].getCosa();
        board[posx][posy-1].setCosa(aux);
        board[posx][posy].setCosa(aux2);
    }
}
}

void Tablero::MovimientoPader(int &x,int &y, int dim){

    int posx=0;
    int posy=0;
    BuscarPersonaje(posx,posy,dim);
    x=posx;
    y=posy;

    if((posy+1)<dim){

        if(board[posx][posy+1].getIDCosa()==0)
    {
        Cosa* aux=board[posx][posy].getCosa();
        Cosa* aux2=board[posx][posy+1].getCosa();
        board[posx][posy+1].setCosa(aux);
        board[posx][posy].setCosa(aux2);
    }
        else if((valorMatriz(x,y+1)==3)||(valorMatriz(x,y+1)==4)||(valorMatriz(x,y+1)==5))
        {
            eliminarEnemigo(x,y+1);
            setTocarPersonaje(true);
            Cosa* aux=board[posx][posy].getCosa();
            Cosa* aux2=board[posx][posy+1].getCosa();
            board[posx][posy+1].setCosa(aux);
            board[posx][posy].setCosa(aux2);
        }
        }
 }

//BUSCAR PERSONAJE........................................................................................................
void Tablero::BuscarPersonaje(int& x,int& y,int dim){

    for (int i=0; i<dim; i++){
        for (int j=0; j<dim;j++){
            if(board[i][j].getIDCosa()==2){
                x=i;
                y=j;
                i=1+dim;
                j=1+dim;
            }
        }
    }
}


//SACAR PERSONAJE DEL TABLERO...............................................................................................

void Tablero::sacarPersonajeDelTablero(int dim){
    int posx=0;
    int posy=0;
    BuscarPersonaje(posx,posy,dim);
    Piso* aux=new Piso();
    this->board[posx][posy].setCosa(aux);


}

//CRACION ENEMIGOS.......................................................................................................


void Tablero::crearEnemigos(int dim){

  if(this->comprobarLimiteEnemigo()==true)
{
    int posx=0;
    int posy=0;
    int rd=1+rand()%(2+1);
    generarpos(posx,posy,dim);
    contadorde5++;
    int multiplo=0;

   if(rd==1){
        EnemigoAleatorio *a=new EnemigoAleatorio();
        this->board[posx][posy].setCosa(a);
        this->cantEnemigosActuales++;
       }
    else{
        EnemigoSeguidor *e=new EnemigoSeguidor();
        this->board[posx][posy].setCosa(e);
        this->cantEnemigosActuales++;

        }

   multiplo=contadorde5%5;

    if(multiplo==0){
        EnemigoSalto *c=new EnemigoSalto();
        this->board[posx][posy].setCosa(c);
        this->cantEnemigosActuales++;
    }

    }



}


//MOVIMIENTO ENEMIGO..........................................................................................................

void Tablero::movimientoEnemigo(int dim)
{
    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            if(this->valorMatriz(i,j)==3)
            {
                if(this->board[i][j].getSemovio() == 0)
                {
                    this->board[i][j].setSemovio(1);
                    this->MovimientoEAleatorio(i,j,dim);
                }
            }
            else if(this->valorMatriz(i,j)==5)
            {
                if(this->board[i][j].getSemovio()==0)
                {
                    this->board[i][j].setSemovio(1);
                    this->MovimientoSeguidor(i,j,dim);
                }

            }
            else if(this->valorMatriz(i,j)==4)
            {
                if(this->board[i][j].getSemovio()==0)
                {
                    this->board[i][j].setSemovio(1);
                    this->MovimientoSaltoSeguidor(i,j,dim);
                }
            }
        }
    }

    for(int i=0;i<dim;i++){
        for(int j=0;j<dim;j++){
            this->board[i][j].setSemovio(0);
        }
    }

}


//ENEMIGO ALEATORIO (SU MOVIMIENTO).....................................................................................................

void Tablero::MovimientoEAleatorio(int x, int y,int dim)
{
    int random=1+rand()%(4+1);

    switch (random)
    {
    case 1: //movimiento para abajo
        if((x-1)>=0){


        if(valorMatriz(x-1,y)==0)
        {
            moverEabj(x,y);
        }
        else if(valorMatriz(x-1,y)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
        }
        else if ((valorMatriz(x-1,y)==3)||(valorMatriz(x-1,y)==4)||(valorMatriz(x-1,y)==5)) {
            eliminarEnemigo(x,y);
            eliminarEnemigo(x-1,y);
        }
        }
        break;


    case 2: //movimiento para arriba
        if((x+1)<dim){

        if(valorMatriz(x+1,y)==0)
        {
            moverEarr(x,y);
        }
        else if(valorMatriz(x+1,y)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
        }
        else if((valorMatriz(x+1,y)==3)||(valorMatriz(x+1,y)==4)||(valorMatriz(x+1,y)==5)){
        eliminarEnemigo(x,y);
        eliminarEnemigo(x+1,y);
    }
       }
        break;


    case 3: //movimiento para derecha
        if((y+1)<dim){

            if(valorMatriz(x,y+1)==0)
        {
            moverEder(x,y);
        }
            else if(valorMatriz(x,y+1)==2){
                eliminarEnemigo(x,y);
                setTocarPersonaje(true);
            }
            else if((valorMatriz(x,y+1)==3)||(valorMatriz(x,y+1)==4)||(valorMatriz(x,y+1)==5)){
                eliminarEnemigo(x,y);
                eliminarEnemigo(x,y+1);
            }
            }

      break;


    default://movimiento para izquierda

        if((y-1)>=0){

        if(valorMatriz(x,y-1)==0)
        {
            moverEizq(x,y);
        }
        else if (valorMatriz(x,y-1)==2) {
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
        }
        else if((valorMatriz(x,y-1)==3)||(valorMatriz(x,y-1)==4)||(valorMatriz(x,y-1)==5)){
            eliminarEnemigo(x,y);
            eliminarEnemigo(x,y-1);
        }

    }


    }


}


//ENEMIGO SEGUIDOR (SU MOVIMIENTO)........................................................................................................

void Tablero::MovimientoSeguidor(int x, int y, int dim){
    int posx=0;
    int posy=0;
    BuscarPersonaje(posx,posy,dim);


    if(y<posy){

        if(valorMatriz(x,y+1)==0){
            moverEder(x,y);
            return;
        }
        else if(valorMatriz(x,y+1)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
        }
        else if((valorMatriz(x,y+1)==3)||(valorMatriz(x,y+1)==4)||(valorMatriz(x,y+1)==5)){
            eliminarEnemigo(x,y);
            eliminarEnemigo(x,y+1);
        }
        else if (valorMatriz(x,y+1)==1){
                 MovimientoEAleatorio(x,y,dim);
                 return;
        }
       }

   else if(y>posy){
        if(valorMatriz(x,y-1)==0)

        {
            moverEizq(x,y);
            return;
        }
        else if(valorMatriz(x,y-1)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
        }
        else if((valorMatriz(x,y-1)==3)||(valorMatriz(x,y-1)==4)||(valorMatriz(x,y-1)==5)){
            eliminarEnemigo(x,y);
            eliminarEnemigo(x,y-1);
        }
        else if(valorMatriz(x,y-1)==1){
            MovimientoEAleatorio(x,y,dim);
            return;
        }

        }


    if(x>posx)
    {
        if(valorMatriz(x-1,y)==0)
        {
           moverEabj(x,y);
           return;
        }
        else if(valorMatriz(x-1,y)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
        }
        else if ((valorMatriz(x-1,y)==3)||(valorMatriz(x-1,y)==4)||(valorMatriz(x-1,y)==5)) {
            eliminarEnemigo(x,y);
            eliminarEnemigo(x-1,y);
        }
        else if(valorMatriz(x-1,y)==1){
            MovimientoEAleatorio(x,y,dim);
            return;
            }


        }

    else if(x<posx){
        if(valorMatriz(x+1,y)==0){
            moverEarr(x,y);
            }
            else if(valorMatriz(x+1,y)==2){
                eliminarEnemigo(x,y);
                setTocarPersonaje(true);
            }
            else if((valorMatriz(x+1,y)==3)||(valorMatriz(x+1,y)==4)||(valorMatriz(x+1,y)==5)){
            eliminarEnemigo(x,y);
            eliminarEnemigo(x+1,y);
            }
            else if(valorMatriz(x+1,y)==1){
              MovimientoEAleatorio(x,y,dim);
            }
        }

}


//ENEMIGO SALTO DOBLE (SU MOVIMIENTO)...................................................................................................

void Tablero::MovimientoSaltoSeguidor(int x, int y, int dim){
   int posx=0;
    int posy=0;
    int bandera=0;


/*    bandera=personaje_enemigosalto(x,y);

    if(bandera==1)
        return;

*/

    BuscarPersonaje(posx,posy,dim);

    if(y<posy){
      if((y+2)<dim){

       if(valorMatriz(x,y+2)==0){
            dobleder(x,y);
            return;
        }
        else if(valorMatriz(x,y+2)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
            return;
        }
        else if((valorMatriz(x,y+2)==3)||(valorMatriz(x,y+2)==4)||(valorMatriz(x,y+2)==5)){
            eliminarEnemigo(x,y);
            eliminarEnemigo(x,y+2);
            return;
        }
        else if(valorMatriz(x,y+2)==1){
            MovimientoEAleatorio(x,y,dim);
            return;
        }
        }

       }

   if(y>posy){
       if((y-2)>=0){

        if(valorMatriz(x,y-2)==0)

               {
                   dobleizq(x,y);
                   return;
               }
       else if(valorMatriz(x,y-2)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
            return;
        }
        else if((valorMatriz(x,y-2)==3)||(valorMatriz(x,y-2)==4)||(valorMatriz(x,y-2)==5)){
            eliminarEnemigo(x,y);
            eliminarEnemigo(x,y-2);
            return;
        }
       else if(valorMatriz(x,y-2)==1){
           MovimientoEAleatorio(x,y,dim);
           return;
       }

        }
      }



    if(x>posx)
    {
        if((x-2)>=0){

        if(valorMatriz(x-2,y)==0)
        {
           dobleabaj(x,y);
           return;
        }
        else if(valorMatriz(x-2,y)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
            return;
        }
        else if ((valorMatriz(x-2,y)==3)||(valorMatriz(x-2,y)==4)||(valorMatriz(x-2,y)==5)) {
            eliminarEnemigo(x,y);
            eliminarEnemigo(x-2,y);
            return;
        }
        else if(valorMatriz(x-2,y)==1){
           MovimientoEAleatorio(x,y,dim);
           return;
        }

        }
    }


    if(x<posx){
        if((x+2)<dim){
        if(valorMatriz(x+2,y)==0){
            doblearri(x,y);
            return;
            }
            else if(valorMatriz(x+2,y)==2){
                eliminarEnemigo(x,y);
                setTocarPersonaje(true);
                return;
            }
            else if((valorMatriz(x+2,y)==3)||(valorMatriz(x+2,y)==4)||(valorMatriz(x+2,y)==5)){
            eliminarEnemigo(x,y);
            eliminarEnemigo(x+2,y);
            return;
            }
            else if(valorMatriz(x+2,y)==1){
                MovimientoEAleatorio(x,y,dim);
                return;
            }

        }
    }


}

//SI EL PERSONAJE TOCA EL ENEMIGO.......................................................................................................

bool Tablero::Enemigotocopersonaje(){
    return this->tocarpersonaje;
}

void Tablero::setTocarPersonaje(bool a){
    this->tocarpersonaje=a;
}


//ELIMINAR ENEMIGO...............................................................................................................

void Tablero::eliminarEnemigo(int x, int y){
    if((valorMatriz(x,y)==3)||(valorMatriz(x,y)==4)||(valorMatriz(x,y)==5))
    {
    Piso* aux=new Piso();
    this->board[x][y].setCosa(aux);
    this->cantEnemigosActuales--;
    }
}


//TOMAR EL VALOR DE UNA MATRIZ...................................................................................................

int Tablero::valorMatriz(int x,int y){
    return board[x][y].getIDCosa();
}


//LIMITE ENEMIGO (COMPROBANTE)..............................................................................................

bool Tablero::comprobarLimiteEnemigo(){
    bool estadisponible=true;

    if(this->cantEnemigos==this->cantEnemigosActuales)
    {
        estadisponible=false;
    }

    return estadisponible;
}




void Tablero::setcantEnemigos(int x){
    this->cantEnemigos=x;
}


//GENERAR UNA POS. RANDOM...........................................................................................................

void Tablero::generarpos(int &x,int &y,int dim){

    x=rand()%((dim-1)+1);
    y=rand()%((dim-1)+1);

    while(valorMatriz(x,y)!=0)
    {
        x=rand()%((dim-1)+1);
        y=rand()%((dim-1)+1);
    }


}


//MOVIMIENTOS DE LOS ENEMIGOS........................................................................................................

void Tablero::moverEizq(int x,int y){
//MOVER ENEMIGO PARA LA IZ.
    Cosa* aux=board[x][y].getCosa();
    Cosa* aux2=board[x][y-1].getCosa();
    board[x][y-1].setCosa(aux);
    board[x][y].setCosa(aux2);

}

void Tablero::moverEder(int x,int y)
{
   //MOVE EL ENEMIGO PARA DER
    Cosa* aux=board[x][y].getCosa();
    Cosa* aux2=board[x][y+1].getCosa();
    board[x][y+1].setCosa(aux);
    board[x][y].setCosa(aux2);
}

void Tablero::moverEarr(int x, int y)
{
    //MOVIMIENTO PARRIBA
    Cosa* aux=board[x][y].getCosa();
    Cosa* aux2=board[x+1][y].getCosa();
    board[x+1][y].setCosa(aux);
    board[x][y].setCosa(aux2);
}

void Tablero::moverEabj(int x, int y)
{
    //MOV PABAJO
    Cosa* aux=board[x][y].getCosa();
    Cosa* aux2=board[x-1][y].getCosa();
    board[x-1][y].setCosa(aux);
    board[x][y].setCosa(aux2);
}

void Tablero::dobleder(int x, int y){
    Cosa* aux=board[x][y].getCosa();
    Cosa* aux2=board[x][y+2].getCosa();
    board[x][y+2].setCosa(aux);
    board[x][y].setCosa(aux2);
}

void Tablero::dobleizq(int x, int y){
    Cosa* aux=board[x][y].getCosa();
    Cosa* aux2=board[x][y-2].getCosa();
    board[x][y-2].setCosa(aux);
    board[x][y].setCosa(aux2);
}

void Tablero::dobleabaj(int x, int y){
    Cosa* aux=board[x][y].getCosa();
    Cosa* aux2=board[x-2][y].getCosa();
    board[x-2][y].setCosa(aux);
    board[x][y].setCosa(aux2);
}

void Tablero::doblearri(int x, int y){
    Cosa* aux=board[x][y].getCosa();
    Cosa* aux2=board[x+2][y].getCosa();
    board[x+2][y].setCosa(aux);
    board[x][y].setCosa(aux2);
}


int Tablero::personaje_enemigosalto(int x, int y){

    int Bandera=0;

    if(valorMatriz(x,y+1)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
            Bandera=1;
        }
    else if(valorMatriz(x,y-1)==2)
        {
                eliminarEnemigo(x,y);
                setTocarPersonaje(true);
                Bandera=1;
         }
    else if(valorMatriz(x-1,y)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
            Bandera=1;
    }
    else if(valorMatriz(x+1,y)==2){
            eliminarEnemigo(x,y);
            setTocarPersonaje(true);
            Bandera=1;
        }
    else {
        Bandera=0;
    }


    return Bandera;

}












//ejercicio 7 funciones


//EJERCICIO 5...................................................................................................................................................................
int ** Tablero::LLenarMat(int Nfilas,int Ncolumnas,int pared,int libre){
    int random;
    int **MatrizAux;
    MatrizAux = new int*[Nfilas];
    for(int i=0;i<Nfilas;i++){
        MatrizAux[i]= new int[Ncolumnas];
    }

    if (pared==libre){
        for (int i=0; i<Nfilas; i++){
            for (int j=0; j<Ncolumnas;j++){
                *(*(MatrizAux+i)+j)=pared;
            }
    }
    }
    else{
        for (int i=0; i<Nfilas; i++){
            for (int j=0; j<Ncolumnas;j++){
                random=1+rand()%(101-1);
                if(random>=50)
                {
                    *(*(MatrizAux+i)+j)=libre;
                }
                else {*(*(MatrizAux+i)+j) = pared;}
            }
        }

    }
    return MatrizAux;
}


//buscar la primera posicion de un cero............

void Tablero::primerapos(int **Matriz,int Nfilas,int Ncolumnas, int &x,int &y,int libre)
{
    for(int i=0;i<Nfilas;i++){
       for(int j=0;j<Ncolumnas;j++){
           if(*(*(Matriz+i)+j)==libre)
           {
               x=i;
               y=j;
               j=Ncolumnas+1;
               i=Nfilas+1;
           }
       }
    }

}
//EJERCICIO 6................................................................................................................................................................................................
void Tablero::contadordevisitas(int **Matriz,int x,int y, int pared,int **visite,int Nfilas,int Ncolumnas)
{
    if((x>=Nfilas) || (y>=Ncolumnas))
        return;

    if ((x<0)||(y<0))
        return;

    if (*(*(visite+x)+y)==1)
        return;


    if((*(*(Matriz+x)+y))==pared)
    {return;}
    else{
            *(*(visite+x)+y) = 1;
            contadordevisitas(Matriz,x+1,y,pared,visite,Nfilas,Ncolumnas);
            contadordevisitas(Matriz,x,y-1,pared,visite,Nfilas,Ncolumnas);
            contadordevisitas(Matriz,x-1,y,pared,visite,Nfilas,Ncolumnas);
            contadordevisitas(Matriz,x,y+1,pared,visite,Nfilas,Ncolumnas);
        }
}


bool Tablero::matrizcerrada(int **Matriz, int **visite, int Nfila,int Ncolumna,int pared,int libre){
    int acumulador=0;
    for (int i=0; i<Nfila; i++){
        for(int j=0; j<Ncolumna; j++){
            if((*(*(Matriz+i)+j))==pared){
                acumulador++;
            }
        }
      }
    if ((acumulador)==(Nfila*Ncolumna)){
        return false;
    }
    else{
    int acum=0;
    int acum1=0;

    for (int i=0; i<Nfila; i++){
        for(int j=0; j<Ncolumna; j++){
            if(*(*(visite+i)+j) == 1){
                acum++;
            }
            if(*(*(Matriz+i)+j) == libre){
                acum1++;
            }
        }
    }

    if (acum==acum1){
        return true;
    }
    else {return false;}
}
}




//EJERCICIO 7.......................................................................................................................................................................................................................

bool Tablero::filasdeunos(int **Matriz,int x, int y,int Nfilas, int pared){
    int contador=0;
    for(int i=x;i<Nfilas;i++){
        if((*(*(Matriz+i)+y))==pared)
        {
            contador++;
        }

       }
    if(contador==Nfilas){
        return true;
    }
    else {return false;}
}

bool Tablero::columnadeunos(int **Matriz,int x, int y,int Ncolumnas,int pared)
{
    int contador=0;
    for(int j=y;j<Ncolumnas;j++)
        {
        if((*(*(Matriz+x)+j))==pared)
        {
            contador++;
        }

       }
    if(contador==Ncolumnas)
    {
        return true;
    }
    else {return false;}
}

bool Tablero::borradiagonal(int **Matriz,int x,int y,int Nfilas,int Ncolumnas,int pared,int libre)
{


    if((x>=Nfilas) || (y>=Ncolumnas))
        return false;

    if ((x<0)||(y<0))
        return false;


     if( *(*(Matriz+x)+y) == pared)
     {
         *(*(Matriz+x)+y) = libre;
         int pos1=0;
         int pos2=0;
         int **MatrizAux;
         MatrizAux = new int*[Nfilas];
         for(int i=0;i<Nfilas;i++)
         {
             MatrizAux[i]= new int[Ncolumnas];
         }
         primerapos(Matriz,Nfilas,Ncolumnas,pos1,pos2,libre);
         contadordevisitas(Matriz,pos1,pos2,pared,MatrizAux,Nfilas,Ncolumnas);
         if(matrizcerrada(Matriz,MatrizAux,Nfilas,Ncolumnas,pared,libre)==true){

            for(int i=0; i<Nfilas; i++){
                delete[] MatrizAux[i];

            }
            delete MatrizAux;

            return true;
         }
         else{
             for(int i=0; i<Nfilas; i++)
             {
                 delete[] MatrizAux[i];

             }
             delete MatrizAux;

             return false;
            }



     }
     else{return false;}

}

