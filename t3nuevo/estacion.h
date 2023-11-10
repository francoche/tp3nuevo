#ifndef ESTACION_H
#define ESTACION_H
#include <iostream>

class Estacion
{
protected:
    int fila;
    int columna;
    int tipo;
public:
    Estacion();
    void setfila(int a);
    void setcolumna(int a);
    void settipo(int a);
    int getfila();
    int getcolumna();
    int gettipo();
    bool virtual salidaestacion(int fila,int columna)=0;
    bool virtual entradaestacion(int fila,int columna )=0;
};

#endif // ESTACION_H
