#ifndef ESTACIONMULTIPLE_H
#define ESTACIONMULTIPLE_H

#include "estacion.h"

class Estacionmultiple : public Estacion
{
public:
    Estacionmultiple();
    bool salidaestacion(int fila,int columna,int filastotales, int columnastotales);
    bool entradaestacion(int fila,int columna,int filastotales, int columnastotales);
};

#endif // ESTACIONMULTIPLE_H
