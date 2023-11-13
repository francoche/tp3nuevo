#include "camino.h"

Camino::Camino()
{
this->cont=0;
this->tipo=5;
}

bool Camino::salidaestacion(int fila, int columna)
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

bool Camino::entradaestacion(int fila, int columna)
{

}
