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
        map<int,Publicacion> Publis;

    public:
        AdministraPropiedad(DTFecha* fecha, Inmueble Inmueble);// se inicializa con ultimapublicacion 0 y con un map vacio
        ~AdministraPropiedad(); //no se si borramos las publicaciones o no

        Inmueble getinmueble();  
        int getultimaPublicacion();  

        void setultimaPublicacion(int up);
        void agregarPubli(int codigo, Publicacion publi);

        bool existepubli(DTFecha fecha, TipoPublicacion tipoPublicacion);
        Publicacion encontrarPu(TipoPublicacion tipoPublicacion);
       
        

};

#endif