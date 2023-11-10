#include "estacionnormal.h"

Estacionnormal::Estacionnormal()
{

}

bool Estacionnormal::salidaestacion(int fila, int columna, int filastotales, int columnastotales)
{
    if(columna-1>=0) {
        return true;

    }

    if (columna+1<columnastotales ) {

        return true;
    }
    if (fila-1>=0 ) {

        return true;
     }


        if (fila+1<filastotales) {

            return true;
        }

        return false;
}

bool Estacionnormal::entradaestacion(int fila, int columna, int filastotales, int columnastotales)
{

}
