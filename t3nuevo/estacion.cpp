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

void Estacion::disminuircontador()
{
    this->cont=this->cont-1;
}

int Estacion::getcontador()
{
    return this->cont;
}

void Estacion::setclikeada()
{
    this->clikeada=true;
}

bool Estacion::getclikeada()
{
    return this->clikeada;
}


