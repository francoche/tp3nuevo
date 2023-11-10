#ifndef JUEGO_H
#define JUEGO_H
#include "estacionhorizontal.h"
#include "estacionmultiple.h"
#include "estacionnormal.h"
#include "estacionvertical.h"
#include "camino.h"
#include<cstdlib>
#include<ctime>
#include <iostream>
class Juego
{
private:
    Estacion***estaciones;
    bool**ocuado;
    bool**existeestacion;
    bool**camino;
    int filas;
    int columnas;
    int filaultimo;
    int columnaultimo;
public:
    Juego();
    void crearmatriz();
    void borrarmatriz();
    void setfilaultom(int a);
    void setcolumnaultimo(int a);
    void setcolumnas(int a);
    void setfilas(int a);
    void moverultimo(int fila,int columna);
    int gettipoestacion(int fila,int columna);
    void crearestaciones(int &a,int &b,int &c,int &d);
    void crearcamino(int fila,int columna);
    bool esadshacenteestacion(int fila,int columna);
    bool esadshacenteultimo(int fila,int columna);
    bool hayunaestacion(int fila,int columna);
    bool hayuncamino(int fila,int columna);

};

#endif // JUEGO_H
