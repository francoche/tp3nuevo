#ifndef ESTACIONNORMAL_H
#define ESTACIONNORMAL_H

#include "estacion.h"

class Estacionnormal : public Estacion
{
public:
    Estacionnormal();
    bool salidaestacion(int fila,int columna,int filastotales, int columnastotales);
    bool entradaestacion(int fila,int columna,int filastotales, int columnastotales);
};

#endif // ESTACIONNORMAL_H
