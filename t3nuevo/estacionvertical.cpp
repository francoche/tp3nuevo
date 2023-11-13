#include "estacionvertical.h"

Estacionvertical::Estacionvertical()
{
this->cont=1;
}

bool Estacionvertical::salidaestacion(int fila, int columna)
{
     std::cout<<"si"<<std::endl;
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
