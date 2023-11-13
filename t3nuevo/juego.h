#ifndef JUEGO_H
#define JUEGO_H
#include "estacionhorizontal.h"
#include "estacionmultiple.h"
#include "estacionnormal.h"
#include "estacionvertical.h"
#include "camino.h"
#include<cstdlib>
#include<ctime>
#include <fstream>
#include <iostream>
#include <string>

struct guardar{
    int filas;
    int columnas;
    int filaultimo;
    int columnaulltimo;
    int filaproxestacion;
    int columnaproxestacion;
    int timer;
};
struct eestacion{
    int tipo;
    int fila;
    int columna;
    int cont;
    bool clikeada;
};

using namespace std;
class Juego
{
private:
    Estacion***estaciones;
    bool**ocuado;
    bool**existeestacion;
    bool**camino;
    int **tipo;
    eestacion**estaziones;
    int filas;
    int columnas;
    int filaultimo;
    int columnaultimo;
    int filaproxestacion;
    int columnaproxestacion;
public:
    Juego();
    void crearmatriz();
    void borrarmatriz();
    void setfilaultom(int a);
    void setcolumnaultimo(int a);
    int getfilaultimo();
    int getcolumnaultimo();
    void setcolumnas(int a);
    void setfilas(int a);
    void moverultimo(int fila,int columna);
    int gettipoestacion(int fila,int columna);
    void crearestaciones(int &a,int &b,int &c,int &d);
    bool crearproximaestacion(int &a,int &b);
    void crearcamino(int fila,int columna);
    void resetecamino(int fila, int columna);
    void resetestaciones(int fila,int columna);
    bool esadshacenteestacion(int fila,int columna);
    bool esadshacenteultimo(int fila,int columna);
    bool hayunaestacion(int fila,int columna);
    bool hayunaestacion2(int fila,int columna,int fila2,int columna2);
    bool sobreestacion(int fila,int columna);
    //bool chequearentrada(int fila, int columna);
    bool estacionclikeada(int fila, int columna);
    bool chekearclikeada(int fila,int columna);

    void archivardimensiones(int a,int b);
    void leerdimensiones(int &a,int &b);

    void guardarpartida(int timer);
    void guardarocupado();
    void guardarcamino();
    void guardartipo();
    void guardarexiestacion();
    void guardareztaciones();
    void copiarmatrizestacione();




    bool** leerbool(char*a);
    int **leertipo();
    eestacion**leerestaziones();


    void cargarpartida(int &timer);
    void cargarmatrices();

    bool recargarocupado(int a,int b);
    bool recargarestacion(int a,int b);
    void recrearmatrizestaciones();
    bool chekeartipo2(int a,int b);
    bool chekearultimo(int a,int b);







};

#endif // JUEGO_H
