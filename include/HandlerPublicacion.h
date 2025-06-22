#ifndef HANDLERPUBLICACION
#define HANDLERPUBLICACION

#include "Publicacion.h"
#include "TipoInmueble.h"

#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

class HandlerPublicacion
{
private:
    static HandlerPublicacion *instancia;
    map<int, Publicacion *> coleccionPublicaciones;
    HandlerPublicacion();

public:
    static HandlerPublicacion *getInstancia();
    static void destroy();
    ~HandlerPublicacion();

    void agregarPublicacion(Publicacion *publicacion); // Agrega una publicacion a la coleccion de publicacion, la clave es el codigo de la publicacion.
    void eliminarPublicacion(int codigo);              // se elimiina de la coleccion la publicacion con p.codigo=codigo.
    bool existePublicacion(int codigo);                // devuelve true si existe una publicacion con p.codigo=codigo.
    Publicacion *getPublicacion(int codigo);           // devuelve un puntgero a una publicacion con p.codigo=codigo.
    set<Publicacion *> obtenerPublicacionesActivas();  // devuelve todas las publicaciones activas.
    void imprimirColeccionPublicaciones();
};

#endif