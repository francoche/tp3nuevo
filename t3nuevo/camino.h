#ifndef CAMINO_H
#define CAMINO_H

#include "estacion.h"

class Camino : public Estacion
{
public:
    Camino();
    bool salidaestacion(int fila,int columna);
    bool entradaestacion(int fila,int columna);
};

#endif // CAMINO_H
