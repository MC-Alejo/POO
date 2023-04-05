#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <juego.h>

#include <QMainWindow>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void ActImg();
    int minutos;
    int segundos;
    QTimer* enemig;
    QTimer* t1;
    QTimer* actualizador;
    Juego* juegoX;
    QLabel *** labels;
    Ui::MainWindow *ui;
    unsigned long dim;
    void inicializarMatriz();
    int getValorMatriz(int i, int j);
    int limiterango(int i,int j);

public slots:
    void keyPressEvent(QKeyEvent * e);
    void timer();
    void timerenemigo();
    void tiempoactualizacion();

};

#endif // MAINWINDOW_H
