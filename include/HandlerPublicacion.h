#ifndef HANDLERPUBLICACION
#define HANDLERPUBLICACION

#include "Publicacion.h"

#include <map>
#include <set>
#include <string>

using namespace std;

class HandlerPublicacion
{
private:
    static HandlerPublicacion *instancia;
    map<int, Publicacion> coleccionPublicaciones;
    HandlerPublicacion();

public:
    
    static HandlerPublicacion *getInstancia();

    void agregarPublicacion(const Publicacion &publicacion);// Agrega una publicacion a la coleccion de publicacion, la clave es el codigo de la publicacion

    void eliminarPublicacion(int codigo);

    bool existePublicacion(int codigo);

    Publicacion getPublicacion(int codigo);

    set<Publicacion> obtenerPublicacionesActivas(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo);
};

#endif