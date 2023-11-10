#ifndef ESTACIONHORIZONTAL_H
#define ESTACIONHORIZONTAL_H

#include "estacion.h"

class EstacionHorizontal : public Estacion
{
public:
    EstacionHorizontal();
    bool salidaestacion(int fila,int columna);
    bool entradaestacion(int fila,int columna);
};

#endif // ESTACIONHORIZONTAL_H
