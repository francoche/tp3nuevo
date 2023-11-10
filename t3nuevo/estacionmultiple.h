#ifndef ESTACIONMULTIPLE_H
#define ESTACIONMULTIPLE_H

#include "estacion.h"

class Estacionmultiple : public Estacion
{
public:
    Estacionmultiple();
    bool salidaestacion(int fila,int columna);
    bool entradaestacion(int fila,int columna);

};

#endif // ESTACIONMULTIPLE_H
