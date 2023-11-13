#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>

class Estacion
{
protected:
    int fila;
    int columna;
    int tipo;
    int cont;
    bool clikeada=false;
public:
    Estacion();
    void setfila(int a);
    void setcolumna(int a);
    void settipo(int a);
    int getfila();
    int getcolumna();
    int gettipo();
    void setcontador(int a);
    void disminuircontador();
    int getcontador();
    void setclikeada();
    bool getclikeada();
    bool virtual salidaestacion(int fila,int columna)=0;
    bool virtual entradaestacion(int fila,int columna )=0;
};

#endif // ESTACION_H
