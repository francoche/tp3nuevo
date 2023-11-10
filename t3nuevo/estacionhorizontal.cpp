#include "estacionhorizontal.h"

EstacionHorizontal::EstacionHorizontal()
{

}

bool EstacionHorizontal::salidaestacion(int fila, int columna,int filastotales, int columnastotales)
{
    if(fila==this->fila && columna==this->columna-1){
        return true;
    }
    if(fila==this->fila && columna==this->columna+1){
        return true;
    }
    return false;
}

bool EstacionHorizontal::entradaestacion(int fila, int columna,int filastotales, int columnastotales)
{

}
