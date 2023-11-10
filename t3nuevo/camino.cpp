#include "camino.h"

Camino::Camino()
{

}

bool Camino::salidaestacion(int fila, int columna)
{
    if(fila==this->fila+1 && columna==this->columna){
        return true;
    }
    if(fila==this->fila-1 && columna==this->columna){
        return true;
    }
    if(fila==this->fila && columna==this->columna+1){
        return true;
    }
    if(fila==this->fila && columna==this->columna-1){
        return true;
    }
    return false;
}

bool Camino::entradaestacion(int fila, int columna)
{

}
