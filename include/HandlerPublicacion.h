#ifndef HANDLERPUBLICACION
#define HANDLERPUBLICACION

#include "Publicacion.h"
#include "TipoInmueble.h"

#include <map>
#include <vector>
#include <string>

using namespace std;

class HandlerPublicacion
{
private:
    static HandlerPublicacion *instancia;
    map<int, Publicacion*> coleccionPublicaciones;
    HandlerPublicacion();

public:
    
    static HandlerPublicacion *getInstancia();

    void agregarPublicacion( Publicacion* &publicacion);// Agrega una publicacion a la coleccion de publicacion, la clave es el codigo de la publicacion

    void eliminarPublicacion(int codigo);

    Publicacion* getPublicacion(int codigo);

};

#endif