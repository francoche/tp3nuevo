#include "cronometro.h"

Cronometro::Cronometro()
{

}

void Cronometro::settiempo(int a)
{
   this->seg=a;
}

void Cronometro::setaumentar()
{
    this->seg++;
}

void Cronometro::setreset()
{
    this->seg=0;
}

int Cronometro::get_tiempo()
{
    return this->seg;
}
