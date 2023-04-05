#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <stdlib.h>
//#include <time.h>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QKeyEvent>

//PATH Global Variable declaration:
const char* Pared="A:/Users/Mati/Desktop/TP3/pared.png";
const char* Piso="A:/Users/Mati/Desktop/TP3/piso.png";
const char* Personaje="A:/Users/Mati/Desktop/TP3/personaje.jpg";
const char* Enemigo="A:/Users/Mati/Desktop/TP3/enemigo.png";
const char* EnemigoSeg="A:/Users/Mati/Desktop/TP3/enemigoSeguidor.png";
const char* EnemigoSalto="A:/Users/Mati/Desktop/TP3/enemigoSaltoDoble.png";


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->juegoX=new Juego();
    this->juegoX->crearTablero();
    ui->setupUi(this);
    this->inicializarMatriz();
    this->ui->vidas->setText("Vidas: " + QString::number(juegoX->getVidas()));
    //timers..........................................................................
    t1=new QTimer(this);
    enemig=new QTimer(this);
    actualizador=new QTimer(this);
    this->segundos=00;
    this->minutos=00;
    connect(t1,SIGNAL(timeout()),this,SLOT(timer()));
    connect(enemig,SIGNAL(timeout()),this,SLOT(timerenemigo()));
    connect(actualizador,SIGNAL(timeout()),this,SLOT(tiempoactualizacion()));
    t1->start(1000);
    enemig->start(this->juegoX->getSegundosEnemig());
    actualizador->start(200);
}

void MainWindow::tiempoactualizacion(){
    this->juegoX->sacarvida();
    this->ui->vidas->setText("Vidas: " + QString::number(juegoX->getVidas()));
    if(juegoX->GamerOver()==true){
       this->ui->GameOver->setText("¡¡¡GAMER OVER!!!");
       this->t1->stop();
       this->enemig->stop();
       this->actualizador->stop();
       this->ActImg();
    }
}

void MainWindow::timer(){
    this->segundos++;
    this->juegoX->setPuntaje(juegoX->getPuntaje()+1);
    this->ui->puntaje->setText("Puntaje: "+QString::number(this->juegoX->getPuntaje()));

    if(this->segundos<60){

        if((this->minutos>=10)&&(this->segundos<10)){
            this->ui->Segundos->setText(QString::number(minutos)+":0"+QString::number(segundos));
        }
        else if((this->minutos<10)&&(this->segundos<10)){
            this->ui->Segundos->setText("0"+QString::number(minutos)+":0"+QString::number(segundos));
        }
        else if((this->minutos>=10)&&(this->segundos>=10)){
            this->ui->Segundos->setText(QString::number(minutos)+":"+QString::number(segundos));
        }
        else if((this->minutos<10)&&(this->segundos>=10)){
            this->ui->Segundos->setText("0"+QString::number(minutos)+":"+QString::number(segundos));
        }
    }
    else{
        this->segundos=0;
        this->minutos++;
        this->juegoX->setPuntaje(juegoX->getPuntaje()+100);

        if(this->minutos<10){
            this->ui->Segundos->setText("0"+QString::number(minutos)+":0"+QString::number(segundos));
        }
        else{
            this->ui->Segundos->setText(QString::number(minutos)+":0"+QString::number(segundos));
        }
    }


    this->juegoX->moverenemigo();
    this->ActImg();
}

void MainWindow::timerenemigo(){

    this->juegoX->crearenemigo();
    this->ActImg();
}

void MainWindow::inicializarMatriz() {
    //En el ejemplo voy usando dim = 30
    this->dim = this->juegoX->getDim();

    this->labels = new QLabel**[dim];
    for (unsigned long i = 0; i < dim; i++) {
        this->labels[i] = new QLabel*[dim];
        for (unsigned long j = 0; j < dim; j++) {

                this->labels[i][j] = new QLabel();
                this->labels[i][j]->setBackgroundRole(QPalette::Dark);
                this->labels[i][j]->setScaledContents(true);

                this->labels[i][j]->setFixedSize(17,17);
                this->labels[i][j]->setText(" ");
                this->ui->gridLayout->addWidget(labels[i][j] ,i,j);
        }

    }

    for (unsigned long i = 0; i < dim; i++) {
        for (unsigned long j = 0; j < dim; j++) {
            if (this->getValorMatriz(i,j)==1) {
                QPixmap pix(Pared);

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);

            } else if(this->getValorMatriz(i,j)==0){
                QPixmap pix(Piso);

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);
            }
            else if(this->getValorMatriz(i,j)==2){
                QPixmap pix(Personaje);

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);
            }
        }
     }

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *e) {

    int x=0;
    int y=0;

    if(e->key() == Qt::Key_Left ) {

        this->juegoX->MovimientoPaizq(x,y);
            if(this->limiterango(x,y-1)==2){
        QPixmap aux(Personaje);
        aux= aux.scaled(17,17,Qt::KeepAspectRatio);
        QPixmap aux2(Piso);
        aux2= aux2.scaled(17,17,Qt::KeepAspectRatio);
        this->labels[x][y]->setPixmap(aux2);
        this->labels[x][y-1]->setPixmap(aux);
            }

    }

    if(e->key() == Qt::Key_Right) {

            this->juegoX->MovimientoPader(x,y);
            if(this->limiterango(x,y+1)==2){
            QPixmap aux(Personaje);
            aux= aux.scaled(17,17,Qt::KeepAspectRatio);
            QPixmap aux2(Piso);
            aux2= aux2.scaled(17,17,Qt::KeepAspectRatio);
            this->labels[x][y]->setPixmap(aux2);
            this->labels[x][y+1]->setPixmap(aux);
            }

    }

    if(e->key() == Qt::Key_Up ) {



            this->juegoX->MovimientoParriba(x,y);

          if(this->limiterango(x-1,y)==2){

            QPixmap aux(Personaje);
            aux= aux.scaled(17,17,Qt::KeepAspectRatio);
            QPixmap aux2(Piso);
            aux2= aux2.scaled(17,17,Qt::KeepAspectRatio);
            this->labels[x][y]->setPixmap(aux2);
            this->labels[x-1][y]->setPixmap(aux);

            }

    }

    if(e->key() == Qt::Key_Down) {


            this->juegoX->MovimientoPabajo(x,y);

        if(this->limiterango(x+1,y)==2){


            QPixmap aux(Personaje);
            aux= aux.scaled(17,17,Qt::KeepAspectRatio);
            QPixmap aux2(Piso);
            aux2= aux2.scaled(17,17,Qt::KeepAspectRatio);
            this->labels[x][y]->setPixmap(aux2);
            this->labels[x+1][y]->setPixmap(aux);
        }

    }

}


/**
 * Esta función debe retornar el valor de la matriz de mapas en la posición i , j
 * Yo retorno un valor aleatorio, pero ustedes tienen que usar la función del tp1.
 */
int MainWindow::getValorMatriz(int i, int j)
{
    return this->juegoX->getValorMatriz(i,j);
}

int MainWindow::limiterango(int i,int j){
    if((i<this->juegoX->getDim())&&(i>=0)){
        if((j<this->juegoX->getDim())&&(j>=0)){
            return this->juegoX->getValorMatriz(i,j);
        }
    }
    else return -1;
}

void MainWindow::ActImg()
{
    for(int i=0;i<this->dim;i++){
        for(int j=0;j<this->dim;j++){
            if(getValorMatriz(i,j)==0)
            {
                QPixmap aux2(Piso);
                aux2= aux2.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(aux2);
            }
            else if((getValorMatriz(i,j)==3))
            {
                QPixmap aux2(Enemigo);
                aux2= aux2.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(aux2);
            }
            else if(getValorMatriz(i,j)==4){
                QPixmap aux2(EnemigoSalto);
                aux2= aux2.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(aux2);
            }
            else if (getValorMatriz(i,j)==5) {
                QPixmap aux2(EnemigoSeg);
                aux2= aux2.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(aux2);
            }
        }
    }
}


