#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(aumentartiempo()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearjuego()
{
    //int cant = 10;
    this->filas=this->ui->spinBox->value();
    this->columnas=this->ui->spinBox_2->value();
    this->botones = new QPushButton**[filas];
    for (int i = 0; i< filas; i++) {
        this->botones[i] = new QPushButton*[columnas];
        for(int j =0; j < columnas; j++) {
            this->botones[i][j] = new QPushButton(this);
            this->botones[i][j]->setText("camino");
            connect(botones[i][j], SIGNAL(clicked()), this, SLOT(graficador()));

            this->ui->gridLayout->addWidget(this->botones[i][j], i, j);
            QObject::connect(this->botones[i][j],
                             &QPushButton::clicked,
                             [=](){
                //this->botones[i][j]->setText(".");
            } );
        }
    }
    juego.setfilas(filas);
    juego.setcolumnas(columnas);
}
void MainWindow::reset()
{
    this->ui->lcdNumber->display(cronometro.get_tiempo());
}

void MainWindow::aumentartiempo()
{
    if(this->cronometro.get_tiempo()<10){
        this->cronometro.setaumentar();
        reset();
    }else{

        QMessageBox::information(this,"perdiste","perdiste");
        on_pushButton_2_clicked();
    }
}

void MainWindow::graficador()
{
    QPushButton * Aux = (QPushButton *)sender();
    int auxfila=0;
    int auxcolumna=0;
    for (int i = 0; i < filas; ++i) {
                for (int j = 0; j < columnas; ++j) {
                    if (botones[i][j] == Aux) {
                        auxfila = i;
                        auxcolumna = j;
                        break;
                    }
                }
            }
    if(juego.esadshacenteultimo(auxfila,auxcolumna) && juego.hayunaestacion(auxfila,auxcolumna)){
     this->botones[auxfila][auxcolumna]->setText(".");
     juego.moverultimo(auxfila,auxcolumna);
     juego.crearcamino(auxfila,auxcolumna);
    }
}


void MainWindow::on_pushButton_clicked()
{
    int a,b,c,d;
    crearjuego();
    timer.start(1000);
    juego.crearmatriz();
    juego.crearestaciones(a,b,c,d);
    this->botones[a][b]->setText("ESTACION "+QString::number(juego.gettipoestacion(a,b)));
    this->botones[c][d]->setText("ESTACION "+QString::number(juego.gettipoestacion(c,d)));
    this->botones[a][b]->setEnabled(false);

}


void MainWindow::on_pushButton_2_clicked()
{
    juego.borrarmatriz();
    this->timer.stop();
    this->cronometro.setreset();
    reset();
}

