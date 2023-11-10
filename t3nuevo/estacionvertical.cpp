#include "estacionvertical.h"

Estacionvertical::Estacionvertical()
{

}

bool Estacionvertical::salidaestacion(int fila, int columna)
{
    if(fila==this->fila-1 && columna==this->columna){
        return true;
    }
    if(fila==this->fila+1 && columna==this->columna){
        return true;
    }
    return false;
}

bool Estacionvertical::entradaestacion(int fila, int columna)
{

}
