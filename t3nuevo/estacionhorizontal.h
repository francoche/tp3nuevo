#ifndef ESTACIONHORIZONTAL_H
#define ESTACIONHORIZONTAL_H

#include "estacion.h"

class EstacionHorizontal : public Estacion
{
public:
    EstacionHorizontal();
    bool salidaestacion(int fila,int columna,int filastotales, int columnastotales);
    bool entradaestacion(int fila,int columna,int filastotales, int columnastotales);
};

#endif // ESTACIONHORIZONTAL_H
