#include "juego.h"

Juego::Juego()
{

}

void Juego::crearmatriz()
{
    this->estaciones = new Estacion**[this->filas];
    this->ocuado=new bool*[this->filas];
    this->existeestacion=new bool*[this->filas];
    this->camino=new bool*[this->filas];
    for (int i = 0; i< filas; i++) {
        this->estaciones[i] = new Estacion*[this->columnas];
        this->ocuado[i]=new bool[this->columnas];
        this->existeestacion[i]=new bool[this->columnas];
        this->camino[i]=new bool[this->columnas];

    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            this->estaciones[i][j]=NULL;
            this->ocuado[i][j]=false;
            this->existeestacion[i][j]=false;
            this->camino[i][j]=false;


    }
    }
}

void Juego::borrarmatriz()
{
    for (int i = 0; i< filas; i++) {
        delete [] estaciones[i];
        delete [] ocuado[i];
        delete [] existeestacion[i];
    }
    delete [] estaciones;
    delete [] ocuado;
    delete [] existeestacion;
}

void Juego::setfilaultom(int a)
{
    this->filaultimo=a;
}

void Juego::setcolumnaultimo(int a)
{
    this->columnaultimo=a;
}

void Juego::setcolumnas(int a)
{
    this->columnas=a;
}

void Juego::setfilas(int a)
{
    this->filas=a;
}

void Juego::moverultimo(int fila, int columna)
{
    this->filaultimo=fila;
    this->columnaultimo=columna;
}

int Juego::gettipoestacion(int fila,int columna)
{
    return   this->estaciones[fila][columna]->gettipo();
}

void Juego::crearestaciones(int &a, int &b, int &c, int &d)
{
    srand(time(NULL));
    int f1,c1,f2,c2,t,t2;
    t=1+rand()%4;
    switch (t) {
    case 1:{f1=rand()%filas;
            c1=rand()%columnas;
            Estacion*aux=new Estacionnormal();
            estaciones[f1][c1]=aux;
            estaciones[f1][c1]->setfila(f1);
            estaciones[f1][c1]->setcolumna(c1);
            estaciones[f1][c1]->settipo(t);
            this->ocuado[f1][c1]=true;
            this->existeestacion[f1][c1]=true;
            this->filaultimo=f1;
            this->columnaultimo=c1;
            a=f1;b=c1;
            break;}
    case 2:{f1=rand()%filas;
            c1=rand()%columnas;
            Estacion*aux=new Estacionmultiple();
            estaciones[f1][c1]=aux;
            estaciones[f1][c1]->setfila(f1);
            estaciones[f1][c1]->setcolumna(c1);
            estaciones[f1][c1]->settipo(t);
            this->ocuado[f1][c1]=true;
            this->existeestacion[f1][c1]=true;
            this->filaultimo=f1;
            this->columnaultimo=c1;
            a=f1;b=c1;
            break;}
    case 3:{f1=rand()%filas;
            c1=1+rand()%(columnas-2);
            Estacion*aux=new EstacionHorizontal();
            estaciones[f1][c1]=aux;
            estaciones[f1][c1]->setfila(f1);
            estaciones[f1][c1]->setcolumna(c1);
            estaciones[f1][c1]->settipo(t);
            this->ocuado[f1][c1]=true;
            this->existeestacion[f1][c1]=true;
            this->filaultimo=f1;
            this->columnaultimo=c1;
            a=f1;b=c1;
            break;}
    case 4:{f1=1+rand()%(filas-2);
            c1=rand()%columnas;
            Estacion*aux=new Estacionvertical();
            estaciones[f1][c1]=aux;
            estaciones[f1][c1]->setfila(f1);
            estaciones[f1][c1]->setcolumna(c1);
            estaciones[f1][c1]->settipo(t);
            this->ocuado[f1][c1]=true;
            this->existeestacion[f1][c1]=true;
            this->filaultimo=f1;
            this->columnaultimo=c1;
            a=f1;b=c1;
            break;}

    }
    t2=1+rand()%4;
    switch (t2) {
    case 1:{f2=rand()%filas;
            c2=rand()%columnas;
            break;
        }
    case 2:{f2=rand()%filas;
            c2=rand()%columnas;
            break;
        }
    case 3:{f2=rand()%filas;
            c2=1+rand()%(columnas-2);
            break;
        }
    case 4:{f2=1+rand()%(filas-2);
            c2=rand()%columnas;
            break;}

    }

    while (this->ocuado[f2][c2] || esadshacenteestacion(f2,c2)) {
        switch (t2) {
        case 1:{f2=rand()%filas;
                c2=rand()%columnas;
                break;
            }
        case 2:{f2=rand()%filas;
                c2=rand()%columnas;
                break;
            }
        case 3:{f2=rand()%filas;
                c2=1+rand()%(columnas-2);
                break;
            }
        case 4:{f2=1+rand()%(filas-2);
                c2=rand()%columnas;
                break;}

        }
    }

    switch (t2) {
    case 1:{Estacion*aux=new Estacionnormal();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        c=f2;d=c2;
            break;
        }
    case 2:{Estacion*aux=new Estacionmultiple();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        c=f2;d=c2;
            break;
        }
    case 3:{Estacion*aux=new EstacionHorizontal();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        c=f2;d=c2;
            break;
        }
    case 4:{Estacion*aux=new Estacionvertical();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        c=f2;d=c2;
            break;}

    }

}

void Juego::crearcamino(int fila, int columna)
{
    this->camino[fila][columna]=true;
}

bool Juego::esadshacenteestacion(int fila, int columna)
{
    std::cout<<"hola"<<std::endl;
if(fila-1>=0 && this->existeestacion[fila-1][columna]){
    std::cout<<"hola1"<<std::endl;
    return true;
}
if(fila+1<(this->filas-1) && this->existeestacion[fila+1][columna]){
    std::cout<<"hola2"<<std::endl;
    return true;
}
if(columna-1>=0 && this->existeestacion[fila][columna-1]){
    std::cout<<"hola3"<<std::endl;
    return true;
}
if(columna+1<(this->columnas-1) && this->existeestacion[fila][columna+1]){
    std::cout<<"hola4"<<std::endl;
    return true;
}
return false;
}

bool Juego::esadshacenteultimo(int fila, int columna)
{

        if(fila-1>=0 && this->filaultimo==fila-1 && this->columnaultimo==columna){
            return true;
        }
        if(fila+1<(this->filas) && this->filaultimo==fila+1 && this->columnaultimo==columna){
            return true;
        }
        if(columna-1>=0 && this->filaultimo==fila && this->columnaultimo==columna-1){
            return true;
        }
        if(columna+1<(this->columnas) && this->filaultimo==fila && this->columnaultimo==columna+1){
            return true;
        }
        return false;

}

bool Juego::hayunaestacion(int fila, int columna)
{
   if(fila-1>=0 && this->existeestacion[fila-1][columna]){
       return this->estaciones[fila-1][columna]->salidaestacion(fila,columna,filas,columnas);
   }
   if(fila+1<(this->filas-1) && this->existeestacion[fila+1][columna]){
       return this->estaciones[fila+1][columna]->salidaestacion(fila,columna,filas,columnas);
   }
   if(columna-1>=0 && this->existeestacion[fila][columna-1]){
        return this->estaciones[fila][columna-1]->salidaestacion(fila,columna,filas,columnas);
   }
   if(columna+1<(this->columnas-1) && this->existeestacion[fila][columna+1]){
        return this->estaciones[fila][columna+1]->salidaestacion(fila,columna,filas,columnas);
   }
   return false;
}

bool Juego::hayuncamino(int fila, int columna)
{
    if(fila-1>=0 && this->camino[fila-1][columna]){
        return true;
    }
    if(fila+1<(this->filas-1) && this->camino[fila+1][columna]){
        return true;
    }
    if(columna-1>=0 && this->camino[fila][columna-1]){
         return true;
    }
    if(columna+1<(this->columnas-1) && this->camino[fila][columna+1]){
         return true;
    }
    return false;
}




















