#ifndef ESTACIONVERTICAL_H
#define ESTACIONVERTICAL_H

#include "estacion.h"

class Estacionvertical : public Estacion
{
public:
    Estacionvertical();
    bool salidaestacion(int fila,int columna,int filastotales, int columnastotales);
    bool entradaestacion(int fila,int columna,int filastotales, int columnastotales);
};

#endif // ESTACIONVERTICAL_H
