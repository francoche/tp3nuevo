#ifndef ESTACIONVERTICAL_H
#define ESTACIONVERTICAL_H

#include "estacion.h"

class Estacionvertical : public Estacion
{
public:
    Estacionvertical();
    bool salidaestacion(int fila,int columna);
    bool entradaestacion(int fila,int columna);

};

#endif // ESTACIONVERTICAL_H
