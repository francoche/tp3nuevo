#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&timer,SIGNAL(timeout()),this,SLOT(aumentartiempo()));
    auto palette = ui->lcdNumber->palette();
    palette.setColor(palette.Light, QColor(0, 0, 0));
    palette.setColor(palette.WindowText, Qt::black);
    ui->lcdNumber->setPalette(palette);
    this->ui->pushButton_2->setEnabled(false);
    this->ui->pushButton_3->setEnabled(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::crearjuego()
{
    //int cant = 10;
    //this->filas=this->ui->spinBox->value();
    //this->columnas=this->ui->spinBox_2->value();

    this->botones = new QPushButton**[filas];
    for (int i = 0; i< filas; i++) {
        this->botones[i] = new QPushButton*[columnas];
        for(int j =0; j < columnas; j++) {
            this->botones[i][j] = new QPushButton(this);
            this->botones[i][j]->setText("camino");
            connect(botones[i][j], SIGNAL(clicked()), this, SLOT(graficador()));
            botones[i][j]->setStyleSheet("QPushButton {background-color:rgb(255, 255, 255); height: 25px; width: 25px; border-radius: 25%; border-style: solid; border-width: 7px; }");
            this->ui->gridLayout->addWidget(this->botones[i][j], i, j);
            QObject::connect(this->botones[i][j],
                             &QPushButton::clicked,
                             [=](){
                //this->botones[i][j]->setText(".");
            } );
        }
    }
    //juego.setfilas(filas);
    //juego.setcolumnas(columnas);
}
void MainWindow::reset()
{
    this->ui->lcdNumber->display(cronometro.get_tiempo());
}

void MainWindow::aumentartiempo()
{
    auto palette = ui->lcdNumber->palette();
    palette.setColor(palette.WindowText, Qt::red);
    if(this->cronometro.get_tiempo()<10){
        if(this->cronometro.get_tiempo()>5){
        this->ui->lcdNumber->setPalette(palette);}
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

        int a,b;
        if(juego.hayunaestacion2(juego.getfilaultimo(),juego.getcolumnaultimo(),auxfila,auxcolumna) && juego.sobreestacion(auxfila,auxcolumna)){

            auto palette = ui->lcdNumber->palette();
            palette.setColor(palette.WindowText, Qt::black);
            this->ui->lcdNumber->setPalette(palette);
           juego.moverultimo(auxfila,auxcolumna);
           juego.resetecamino(auxfila,auxcolumna);
           bool aux=juego.crearproximaestacion(a,b);
           if(!juego.chekearclikeada(auxfila,auxcolumna) && aux){
               cronometro.setreset();
               reset();
           this->botones[a][b]->setText("ESTACION "+QString::number(juego.gettipoestacion(a,b)));
           }
           if(aux==false){
               on_pushButton_2_clicked();
               QMessageBox::information(this,"ganaste","ganaste");
               return;


           }
           if(juego.estacionclikeada(auxfila,auxcolumna)){
           this->botones[auxfila][auxcolumna]->setEnabled(false);
           }else{
             this->botones[auxfila][auxcolumna]->setText("/ESTACION/ "+QString::number(juego.gettipoestacion(auxfila,auxcolumna)));
           }
        }
     if((juego.esadshacenteultimo(auxfila,auxcolumna) && juego.hayunaestacion(auxfila,auxcolumna) &&!juego.sobreestacion(auxfila,auxcolumna))){
     this->botones[auxfila][auxcolumna]->setText(".");
     this->botones[auxfila][auxcolumna]->setEnabled(false);
     juego.moverultimo(auxfila,auxcolumna);
     juego.crearcamino(auxfila,auxcolumna);
     juego.resetecamino(auxfila,auxcolumna);
     }
}


void MainWindow::on_pushButton_clicked()
{
    this->ui->pushButton_3->setEnabled(false);
    this->ui->pushButton_2->setEnabled(true);
    this->ui->pushButton->setEnabled(false);

    juego.archivardimensiones(this->ui->spinBox->value(),this->ui->spinBox_2->value());
    juego.leerdimensiones(filas,columnas);
    cout<<"tierra"<<filas<<" "<<columnas;
    int a,b,c,d;
    crearjuego();
    juego.crearmatriz();
    bool aux=juego.crearestaciones(a,b,c,d);
    if(aux){
    timer.start(1000);
    this->botones[a][b]->setText("ESTACION "+QString::number(juego.gettipoestacion(a,b)));
    this->botones[c][d]->setText("ESTACION "+QString::number(juego.gettipoestacion(c,d)));
    if(juego.estacionclikeada(a,b)){
    this->botones[a][b]->setEnabled(false);

    }
    }
    else{
        QMessageBox::information(this,"Error","dimensiones muy pequenias");
        on_pushButton_2_clicked();
        return;
    }
    botones[a][b]->setStyleSheet("QPushButton {background-color:rgb(255, 255, 51); height: 25px; width: 25px; border-radius: 25%; border-style: solid; border-width: 7px; }");



}


void MainWindow::on_pushButton_2_clicked()
{
    this->timer.stop();
    auto palette = ui->lcdNumber->palette();
    palette.setColor(palette.WindowText, Qt::black);
    this->ui->lcdNumber->setPalette(palette);
    this->ui->pushButton_3->setEnabled(false);
    this->ui->pushButton_2->setEnabled(false);
    this->ui->pushButton->setEnabled(true);
    juego.borrarmatriz();
    for (int i = 0; i< filas; i++) {
        for (int j = 0; j< columnas; j++) {
            this->botones[i][j]->deleteLater();
        }
    }
    for (int i = 0; i< filas; i++) {
            delete [] this->botones[i];
        }
        delete [] this->botones;


    this->cronometro.setreset();
    reset();

}


void MainWindow::on_pushButton_3_clicked()
{
    juego.guardareztaciones();
    //juego.guardartipo();
    juego.guardarpartida(this->ui->lcdNumber->value());
    juego.guardarcamino();
    juego.guardarocupado();
    juego.guardarexiestacion();


}


void MainWindow::on_pushButton_4_clicked()
{
    this->ui->pushButton_3->setEnabled(true);
    this->ui->pushButton_2->setEnabled(true);
    this->ui->pushButton->setEnabled(false);
    int tiempito;
    juego.cargarpartida(tiempito);
    juego.leerdimensiones(filas,columnas);
    crearjuego();
    juego.crearmatriz();
    juego.cargarmatrices();
    juego.recrearmatrizestaciones();
    cronometro.settiempo(tiempito);
    reset();
    timer.start(1000);
    regraficar();

}
void MainWindow::regraficar()
{

    for (int i = 0; i < this->filas; i++) {
     for (int j = 0; j < this->columnas; j++) {
       if(juego.recargarocupado(i,j)){
         this->botones[i][j]->setEnabled(false);
           cout<<"esequiel";
       }
       if(juego.recargarestacion(i,j)){
         this->botones[i][j]->setText("ESTACION "+QString::number(juego.gettipoestacion(i,j)));

       }
       if(juego.recargarestacion(i,j)==false && juego.recargarocupado(i,j)==true){
           this->botones[i][j]->setText(".");
       }
       if(juego.chekeartipo2(i,j)){
           this->botones[i][j]->setText("/ESTACION/ "+QString::number(juego.gettipoestacion(i,j)));
           this->botones[i][j]->setEnabled(true);
       }
       if(juego.chekearultimo(i,j)){
           this->botones[i][j]->setEnabled(true);
       }
       if(juego.getfilaultimo()==i && juego.getcolumnaultimo()==j){
           botones[i][j]->setStyleSheet("QPushButton {background-color:rgb(255, 255, 51); height: 25px; width: 25px; border-radius: 25%; border-style: solid; border-width: 7px; }");

       }


     }
    }

}



