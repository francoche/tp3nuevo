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
    this->tipo=new int*[this->filas];
    this->estaziones=new eestacion*[this->filas];
    for (int i = 0; i< filas; i++) {
        this->estaciones[i] = new Estacion*[this->columnas];
        this->ocuado[i]=new bool[this->columnas];
        this->existeestacion[i]=new bool[this->columnas];
        this->camino[i]=new bool[this->columnas];
        this->tipo[i]=new int[this->columnas];
        this->estaziones[i]=new eestacion[this->columnas];


    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            this->estaciones[i][j]=NULL;
            this->ocuado[i][j]=false;
            this->existeestacion[i][j]=false;
            this->camino[i][j]=false;
            this->tipo[i][j]=0;



    }
    }
}

void Juego::borrarmatriz()
{
    for (int i = 0; i< filas; i++) {
        delete [] estaciones[i];
        delete [] ocuado[i];
        delete [] existeestacion[i];
        delete [] tipo[i];
        delete [] estaziones[i];

    }
    delete [] estaciones;
    delete [] ocuado;
    delete [] existeestacion;
    delete [] tipo;
    delete [] estaziones;

}

void Juego::setfilaultom(int a)
{
    this->filaultimo=a;
}

void Juego::setcolumnaultimo(int a)
{
    this->columnaultimo=a;
}

int Juego::getfilaultimo()
{
    return this->filaultimo;
}

int Juego::getcolumnaultimo()
{
    return this->columnaultimo;
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
            this->camino[f1][c1]=true;
            this->tipo[f1][c1]=t;
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
            this->camino[f1][c1]=true;
            this->tipo[f1][c1]=t;
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
            this->camino[f1][c1]=true;
            this->tipo[f1][c1]=t;
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
            this->camino[f1][c1]=true;
            this->tipo[f1][c1]=t;
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
        this->ocuado[f2][c2]=true;
        this->tipo[f2][c2]=t2;
        c=f2;d=c2;
            break;
        }
    case 2:{Estacion*aux=new Estacionmultiple();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        this->ocuado[f2][c2]=true;
         this->tipo[f2][c2]=t2;
        c=f2;d=c2;
            break;
        }
    case 3:{Estacion*aux=new EstacionHorizontal();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        this->ocuado[f2][c2]=true;
         this->tipo[f2][c2]=t2;
        c=f2;d=c2;
            break;
        }
    case 4:{Estacion*aux=new Estacionvertical();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        this->ocuado[f2][c2]=true;
         this->tipo[f2][c2]=t2;
        c=f2;d=c2;
            break;}

    }
    this->filaproxestacion=f2;
    this->columnaproxestacion=c2;

}

bool Juego::crearproximaestacion(int &a,int &b)
{

    this->ocuado[filaproxestacion][columnaproxestacion]=true;
    int cont=0,cont2=0;
    srand(time(NULL));
    int f2,c2,t2;
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

    while ( this->ocuado[f2][c2] || esadshacenteestacion(f2,c2)) {
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
        cont++;
        if(cont>30){
            cont=0;
            cont2++;
            t2=1+rand()%4;
            if(cont2>50){
                return true;
            }
        }

    }

    switch (t2) {
    case 1:{Estacion*aux=new Estacionnormal();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
       this->ocuado[f2][c2]=true;
         this->tipo[f2][c2]=t2;
        a=f2;b=c2;
            break;
        }
    case 2:{Estacion*aux=new Estacionmultiple();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        this->ocuado[f2][c2]=true;
         this->tipo[f2][c2]=t2;
        a=f2;b=c2;
            break;
        }
    case 3:{Estacion*aux=new EstacionHorizontal();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        this->ocuado[f2][c2]=true;
         this->tipo[f2][c2]=t2;
        a=f2;b=c2;
            break;
        }
    case 4:{Estacion*aux=new Estacionvertical();
        estaciones[f2][c2]=aux;
        estaciones[f2][c2]->setfila(f2);
        estaciones[f2][c2]->setcolumna(c2);
        estaciones[f2][c2]->settipo(t2);
        this->existeestacion[f2][c2]=true;
        this->ocuado[f2][c2]=true;
         this->tipo[f2][c2]=t2;
        a=f2;b=c2;
            break;}

    }
    this->filaproxestacion=f2;
    this->columnaproxestacion=c2;
    return true;

}


void Juego::crearcamino(int fila, int columna)
{
    Estacion*aux=new Camino();
    aux->setfila(fila);
    aux->setcolumna(columna);
    this->camino[fila][columna]=true;
    this->ocuado[fila][columna]=true;
    this->estaciones[fila][columna]=aux;
}

void Juego::resetecamino(int fila, int columna)
{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
             this->camino[i][j]=false;

         }

    }
    this->camino[fila][columna]=true;
}

void Juego::resetestaciones(int fila, int columna)
{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
             this->existeestacion[i][j]=false;

         }

    }
    this->existeestacion[fila][columna]=true;
}


bool Juego::esadshacenteestacion(int fila, int columna)
{
    std::cout<<"hola"<<std::endl;
if(fila-1>=0 && this->existeestacion[fila-1][columna]){
    std::cout<<"hola1"<<std::endl;
    return true;
}
if(fila+1<(this->filas) && this->existeestacion[fila+1][columna]){
    std::cout<<"hola2"<<std::endl;
    return true;
}
if(columna-1>=0 && this->existeestacion[fila][columna-1]){
    std::cout<<"hola3"<<std::endl;
    return true;
}
if(columna+1<(this->columnas) && this->existeestacion[fila][columna+1]){
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
     std::cout<<"fila utlimo "<<fila<<std::endl;
      std::cout<<"columna ultimo "<<columna<<std::endl;
    if(fila+1<this->filas && this->camino[fila+1][columna]){
        if(this->estaciones[fila+1][columna]->salidaestacion(fila,columna)){
            return true;
    }

    }
   if(fila-1>=0 && this->camino[fila-1][columna]){
       if(this->estaciones[fila-1][columna]->salidaestacion(fila,columna)){
           return true;
   }

   }
   if(columna-1>=0 && this->camino[fila][columna-1]){
        if(this->estaciones[fila][columna-1]->salidaestacion(fila,columna)){
            return true;

   }

   }
   if(columna+1<this->columnas && this->camino[fila][columna+1]){
       if(this->estaciones[fila][columna+1]->salidaestacion(fila,columna)){
           return true;

  }

   }
   return false;
}

bool Juego::hayunaestacion2(int fila, int columna,int fila2,int columna2)
{
    std::cout<<"fila utlimo "<<fila<<std::endl;
     std::cout<<"columna ultimo "<<columna<<std::endl;
   if(fila+1<this->filas && this->existeestacion[fila+1][columna] && fila+1==fila2 && columna==columna2/*!ocuado[fila+1][columna]&&(fila+1==this->filaproxestacion && columna==this->columnaproxestacion)*/){
       /*if(this->estaciones[fila+1][columna]->salidaestacion(fila,columna)){
           std::cout<<"skereeeeeeeeeeeeeeeeeee1 "<<std::endl;
           return true;
   }*/
       return this->estaciones[fila+1][columna]->salidaestacion(fila,columna);

   }
  if(fila-1>=0 && this->existeestacion[fila-1][columna]&& fila-1==fila2 && columna==columna2/*!ocuado[fila-1][columna]&&(fila-1==this->filaproxestacion && columna==this->columnaproxestacion)*/){
      /*if(this->estaciones[fila-1][columna]->salidaestacion(fila,columna)){
          std::cout<<"skereeeeeeeeeeeeeeeeeee2 "<<std::endl;
          return true;
  }*/
      return this->estaciones[fila-1][columna]->salidaestacion(fila,columna);

  }
  if(columna-1>=0 && this->existeestacion[fila][columna-1] && fila==fila2 && columna-1==columna2/*!ocuado[fila][columna-1]&&(fila==this->filaproxestacion && columna-1==this->columnaproxestacion)*/){
       /*if(this->estaciones[fila][columna-1]->salidaestacion(fila,columna)){
           std::cout<<"skereeeeeeeeeeeeeeeeeee3 "<<std::endl;
           return true;

  }*/
      return this->estaciones[fila][columna-1]->salidaestacion(fila,columna);

  }
  if(columna+1<this->columnas && this->existeestacion[fila][columna+1] && fila==fila2 && columna+1==columna2/*&&!ocuado[fila][columna+1]&&(fila==this->filaproxestacion && columna+1==this->columnaproxestacion)*/){
      /*if(this->estaciones[fila][columna+1]->salidaestacion(filaultimo,columnaultimo)){
          std::cout<<"skereeeeeeeeeeeeeeeeeee4 "<<std::endl;
          return true;

 }*/
      return this->estaciones[fila][columna+1]->salidaestacion(filaultimo,columnaultimo);

  }
  return false;
}

bool Juego::sobreestacion(int fila, int columna)
{
    if(this->existeestacion[fila][columna]){
        return true;
    }
    return false;
}

/*bool Juego::chequearentrada(int fila, int columna)
{
    return this->estaciones[fila][columna]->salidaestacion(this->filaultimo,this->columnaultimo);
}*/

bool Juego::estacionclikeada(int fila, int columna)
{
    this->estaciones[fila][columna]->disminuircontador();
    this->estaciones[fila][columna]->setclikeada();
    if(this->estaciones[fila][columna]->getcontador()==0){
        return true;
    }


    return false;
}

bool Juego::chekearclikeada(int fila, int columna)
{
    return this->estaciones[fila][columna]->getclikeada();
}

void Juego::archivardimensiones(int a, int b)
{
    ofstream archivo("dimensiones.txt");
    archivo<<"Filas: "<<a<<" Columnas: "<<b<<'\n';
    archivo.close();

}

void Juego::leerdimensiones(int &a,int &b)
{
    char aux[200];int f;int c;
    ifstream archivo1("dimensiones.txt");
    archivo1>>aux>>f>>aux>>c;
    setfilas(f);
    setcolumnas(c);
    a=f;b=c;
    archivo1.close();

}

void Juego::guardarpartida(int timer)
{
    guardar aux;
    aux.filas=this->filas;
    aux.columnas=this->columnas;
    aux.filaultimo=this->filaultimo;
    aux.columnaulltimo=this->columnaultimo;
    aux.filaproxestacion=this->filaproxestacion;
    aux.columnaproxestacion=this->columnaproxestacion;
    aux.timer=timer;
    ofstream archivo("ultimapart.dat",ios::binary);
    archivo.write((char*)&aux,sizeof (guardar));
    archivo.close();
}

void Juego::guardarocupado()
{
    ofstream archivo("ocupado.dat", ios::binary);


        archivo.write(reinterpret_cast<char*>(&filas), sizeof(int));
        archivo.write(reinterpret_cast<char*>(&columnas), sizeof(int));


        for (int i = 0; i < filas; i++) {
            archivo.write(reinterpret_cast<char*>(ocuado[i]), columnas * sizeof(bool));

        }

        archivo.close();
}

void Juego::guardarcamino()
{
    ofstream archivo("camino.dat", ios::binary);


        archivo.write(reinterpret_cast<char*>(&filas), sizeof(int));
        archivo.write(reinterpret_cast<char*>(&columnas), sizeof(int));


        for (int i = 0; i < filas; i++) {
            archivo.write(reinterpret_cast<char*>(camino[i]), columnas * sizeof(bool));

        }

        archivo.close();
}

void Juego::guardartipo()
{

    ofstream archivo("tipo.dat",ios::binary);


        archivo.write(reinterpret_cast<char*>(&filas), sizeof(int));
        archivo.write(reinterpret_cast<char*>(&columnas), sizeof(int));


        for (int i = 0; i < filas; i++) {
            archivo.write(reinterpret_cast<char*>(tipo[i]), columnas * sizeof(int));


        }

        archivo.close();
}

void Juego::guardarexiestacion()
{
    ofstream archivo("exiestacion.dat", ios::binary);


        archivo.write(reinterpret_cast<char*>(&filas), sizeof(int));
        archivo.write(reinterpret_cast<char*>(&columnas), sizeof(int));


        for (int i = 0; i < filas; i++) {
            archivo.write(reinterpret_cast<char*>(existeestacion[i]), columnas * sizeof(bool));

        }

        archivo.close();
}

void Juego::guardareztaciones()
{
    copiarmatrizestacione();
    ofstream archivo("estaziones.dat", ios::binary);


        archivo.write(reinterpret_cast<char*>(&filas), sizeof(int));
        archivo.write(reinterpret_cast<char*>(&columnas), sizeof(int));


        for (int i = 0; i < filas; i++) {
            archivo.write(reinterpret_cast<char*>(estaziones[i]), columnas * sizeof(eestacion));

        }

        archivo.close();

}

void Juego::copiarmatrizestacione()
{
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            if(existeestacion[i][j]){
                estaziones[i][j].fila=estaciones[i][j]->getfila();
                estaziones[i][j].columna=estaciones[i][j]->getcolumna();
                estaziones[i][j].cont=estaciones[i][j]->getcontador();
                estaziones[i][j].tipo=estaciones[i][j]->gettipo();
                estaziones[i][j].clikeada=estaciones[i][j]->getclikeada();

            }
        }
    }
}








bool **Juego::leerbool(char*a)
{
    ifstream archivo(a, ios::binary);



        archivo.read(reinterpret_cast<char*>(&filas), sizeof(int));
        archivo.read(reinterpret_cast<char*>(&columnas), sizeof(int));

        bool** matriz = new bool*[filas];
        for (int i = 0; i < filas; i++) {
            matriz[i] = new bool[columnas];
            archivo.read(reinterpret_cast<char*>(matriz[i]), columnas * sizeof(bool));
        }

        archivo.close();
        return matriz;
}

int **Juego::leertipo()
{
    ifstream archivo("tipo.dat", ios::binary);


        archivo.read(reinterpret_cast<char*>(&filas), sizeof(int));
        archivo.read(reinterpret_cast<char*>(&columnas), sizeof(int));

        int** matriz = new int*[filas];
        for (int i = 0; i < filas; i++) {
            matriz[i] = new int[columnas];
            archivo.read(reinterpret_cast<char*>(matriz[i]), columnas * sizeof(int));
        }

        archivo.close();
        return matriz;
}

eestacion **Juego::leerestaziones()
{
    ifstream archivo("estaziones.dat", ios::binary);


        archivo.read(reinterpret_cast<char*>(&filas), sizeof(int));
        archivo.read(reinterpret_cast<char*>(&columnas), sizeof(int));

        eestacion** matriz = new eestacion*[filas];
        for (int i = 0; i < filas; i++) {
            matriz[i] = new eestacion[columnas];
            archivo.read(reinterpret_cast<char*>(matriz[i]), columnas * sizeof(eestacion));
        }

        archivo.close();
        return matriz;
}







void Juego::cargarpartida(int &timer)
{

    guardar aux;
    ifstream archivo("ultimapart.dat", ios::binary);
    archivo.read((char*)&aux,sizeof (guardar));
    this->filas=aux.filas;
    cout<<aux.filas;
    this->columnas=aux.columnas;
    cout<<aux.columnas;
    archivardimensiones(filas,columnas);
    this->filaultimo=aux.filaultimo;
    cout<<filaultimo;
    this->columnaultimo=aux.columnaulltimo;
    cout<<columnaultimo;
    this->filaproxestacion=aux.filaproxestacion;
    this->columnaproxestacion=aux.columnaproxestacion;
    timer=aux.timer;
    archivo.close();

    /*bool**aux2;
    aux2=leerbool("ocupado.dat");
    this->ocuado=new bool *[filas];
    for (int i = 0; i< filas; i++) {
       this->ocuado[i]=new bool[columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->ocuado[i][j]=aux2[i][j];
    }
    }
    aux2=leerbool("camino.dat");
    this->camino=new bool *[filas];
    for (int i = 0; i< filas; i++) {
       this->camino[i]=new bool[columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->camino[i][j]=aux2[i][j];
    }
    }
    bool **aux3=leerbool("exiestacion.dat");
    this->existeestacion=new bool *[filas];
    for (int i = 0; i< filas; i++) {
       this->existeestacion[i]=new bool[columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->existeestacion[i][j]=aux3[i][j];
    }
    }
    int **aux4=leertipo();
    this->tipo=new int *[filas];
    for (int i = 0; i< filas; i++) {
       this->tipo[i]=new int[columnas];
    }
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->tipo[i][j]=aux4[i][j];
    }
    }*/




}

void Juego::cargarmatrices()
{
    bool**aux2;
    aux2=leerbool("ocupado.dat");
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->ocuado[i][j]=aux2[i][j];
    }
    }
    aux2=leerbool("camino.dat");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->camino[i][j]=aux2[i][j];
    }
    }
    bool **aux3=leerbool("exiestacion.dat");

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->existeestacion[i][j]=aux3[i][j];
    }
    }
    int **aux4=leertipo();

    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->tipo[i][j]=aux4[i][j];
    }
    }
    eestacion**aux5=leerestaziones();
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        this->estaziones[i][j]=aux5[i][j];
    }
    }


}
bool Juego::recargarocupado(int a, int b)
{
    if(ocuado[a][b] ){

         return true;


    }
    return false;

}

bool Juego::recargarestacion(int a, int b)
{
    if(existeestacion[a][b]){

        return true;
    }
    return false;
}

void Juego::recrearmatrizestaciones()
{
    int t;
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
        cout<<"fila "<<i<<"columna "<<j<<"tipo "<<this->tipo[i][j]<<"ecistencia "<<existeestacion[i][j]<<endl;
            if(existeestacion[i][j]==true){
                cout<<"entreeeeeeeeeeeeeeeeeeeeee"<<endl;
              t=tipo[i][j];
              switch (t) {
              case 1:{
                  Estacion*aux=new  Estacionnormal();
                  aux->setfila(i);
                  aux->setcolumna(j);
                  aux->settipo(t);
                  estaciones[i][j]=aux;
                  break;


              }
             case 2:{
                  Estacion*aux=new  Estacionmultiple();
                  aux->setfila(i);
                  aux->setcolumna(j);
                  aux->settipo(t);
                  aux->setcontador(estaziones[i][j].cont);
                  if(estaziones[i][j].cont<2){
                      aux->setclikeada();
                  }
                  estaciones[i][j]=aux;
                  break;


              }
              case 3:{
                  Estacion*aux=new  EstacionHorizontal();
                  aux->setfila(i);
                  aux->setcolumna(j);
                  aux->settipo(t);
                  estaciones[i][j]=aux;
                  break;

              }
              case 4:{
                  Estacion*aux=new  Estacionvertical();
                  aux->setfila(i);
                  aux->setcolumna(j);
                  aux->settipo(t);
                  estaciones[i][j]=aux;
                  break;
              }
            }


            }
            if(ocuado[i][j] && !existeestacion[i][j]){
                Estacion*aux=new  Camino();
                aux->setfila(i);
                aux->setcolumna(j);
                estaciones[i][j]=aux;
            }

    }
}

}

bool Juego::chekeartipo2(int a, int b)
{
    if(existeestacion[a][b] && estaziones[a][b].tipo==2 && estaziones[a][b].cont==1){
        return true;
    }
    return false;
}

bool Juego::chekearultimo(int a, int b)
{
    if(a==filaproxestacion && b==columnaproxestacion){
        return true;
    }
    return false;
}



































