
#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "Inmueble.h"
#include "Publicacion.h"
#include "Inmobiliaria.h"
#include "DTFecha.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "ControladorFechaActual.h"
#include <map>

class Publicacion;
class Inmueble;
class Inmobiliaria;

class AdministraPropiedad{
    private:
        DTFecha* fecha;
        int ultimaPublicacion;
        Inmueble* inmueble;
        map<int, Publicacion*> publicaciones;
        Inmobiliaria* inmobiliaria;

    public:
        AdministraPropiedad(DTFecha* fecha, Inmueble* inmueble, Inmobiliaria* inmo); // Se inicializa con ultimaPublicacion = 0 y con un map vacio
        ~AdministraPropiedad(); // TODO: no se si borramos las publicaciones o no

        Inmueble* getInmueble();  
        int getUltimaPublicacion();  

        void setUltimaPublicacion(int up);
        void agregarPublicacion(int codigo, Publicacion *publicacion);

        bool existePublicacion(DTFecha fecha, TipoPublicacion tipoPublicacion);
        Publicacion* encontrarPublicacionActiva(TipoPublicacion tipoPublicacion);

        Inmobiliaria* getInmobiliaria();
};

#endif

