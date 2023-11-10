#include "estacionmultiple.h"

Estacionmultiple::Estacionmultiple()
{

}

bool Estacionmultiple::salidaestacion(int fila, int columna,int filastotales, int columnastotales)
{
    if(columna-1>=0 && fila==this->fila && columna-1==this->columna){
        return true;
    }
    if(fila-1>=0 && fila-1==this->fila && columna==this->columna){
        return true;
    }
    if(fila+1<filastotales && fila+1==this->fila && columna==this->columna){
        return true;
    }
    if(columna+1<columnastotales && fila==this->columna && columna+1==this->columna){
        return true;
    }
    return false;
}

bool Estacionmultiple::entradaestacion(int fila, int columna,int filastotales, int columnastotales)
{

}
