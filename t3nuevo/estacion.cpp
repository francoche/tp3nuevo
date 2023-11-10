#include "estacion.h"

Estacion::Estacion()
{

}

void Estacion::setfila(int a)
{
    this->fila=a;
}

void Estacion::setcolumna(int a)
{
    this->columna=a;
}

void Estacion::settipo(int a)
{
    this->tipo=a;
}


int Estacion::getfila()
{
    return this->fila;
}

int Estacion::getcolumna()
{
    return this->columna;
}

int Estacion::gettipo()
{
    return this->tipo;
}


