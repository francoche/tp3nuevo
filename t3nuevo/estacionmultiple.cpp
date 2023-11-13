#include "estacionmultiple.h"

Estacionmultiple::Estacionmultiple()
{
this->cont=2;
}

bool Estacionmultiple::salidaestacion(int fila, int columna)
{
    if(fila-1==this->fila && columna==this->columna){
        std::cout<<"no ando1"<<std::endl;
        return true;
    }
    if( fila+1==this->fila && columna==this->columna){
        std::cout<<"no ando2"<<std::endl;
        return true;
    }
    if( fila==this->fila && columna-1==this->columna){
        std::cout<<"no ando3"<<std::endl;
        return true;
    }
    if(fila==this->fila && columna+1==this->columna){
        std::cout<<"no ando4"<<std::endl;
        return true;
    }
    return false;
}

bool Estacionmultiple::entradaestacion(int fila, int columna)
{

}
