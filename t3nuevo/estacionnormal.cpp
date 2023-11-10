#include "estacionnormal.h"

Estacionnormal::Estacionnormal()
{

}

bool Estacionnormal::salidaestacion(int fila, int columna)
{   std::cout<<"no ando"<<std::endl;
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

bool Estacionnormal::entradaestacion(int fila, int columna)
{

}
