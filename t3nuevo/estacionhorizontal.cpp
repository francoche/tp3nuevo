#include "estacionhorizontal.h"

EstacionHorizontal::EstacionHorizontal()
{
this->cont=1;
}

bool EstacionHorizontal::salidaestacion(int fila, int columna)
{
    if(fila==this->fila && columna==this->columna-1){
        return true;
    }
    if(fila==this->fila && columna==this->columna+1){
        return true;
    }
    return false;
}

bool EstacionHorizontal::entradaestacion(int fila, int columna)
{

}
