<<<<<<< HEAD
#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"

class AdministraPropiedad {
    private:
        DTFecha* fecha;

    public:
        AdministraPropiedad(DTFecha* fecha);
        ~AdministraPropiedad();
};

#endif
=======
#ifndef ADMINISTRAPROPIEDAD_H
#define ADMINISTRAPROPIEDAD_H
#include "DTFecha.h"
#include "Inmueble.h"
#include "Publicacion.h"
#include "DTFecha.h"
#include "ControladorFechaActual.h"
#include <map>

class AdministraPropiedad {
    private:
        DTFecha* fecha;
        int ultimaPublicacion;
        Inmueble* inmueble;
        map<int,Publicacion> publicaciones;

    public:
        AdministraPropiedad(DTFecha* fecha, Inmueble inmueble); // Se inicializa con ultimaPublicacion = 0 y con un map vacio
        ~AdministraPropiedad(); // TODO: no se si borramos las publicaciones o no

        Inmueble getInmueble();  
        int getUltimaPublicacion();  

        void setUltimaPublicacion(int up);
        void agregarPublicacion(int codigo, Publicacion publicacion);

        bool existePublicacion(DTFecha fecha, TipoPublicacion tipoPublicacion);
        Publicacion encontrarPublicacionActiva(TipoPublicacion tipoPublicacion);
};

#endif
>>>>>>> 4f76a58b1d5350245de078f27e3caaafaa547ee3
