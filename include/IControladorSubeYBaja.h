#ifndef ICONTROLADORSubeYBaja_H
#define ICONTROLADORSubeYBaja_H

#include "CSubeYBaja.h"

class IControladorSubeYBaja {
    public:
        virtual  bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio)=0;
};

#endif