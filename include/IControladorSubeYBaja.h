#ifndef ICONTROLADORSubeYBaja_H
#define ICONTROLADORSubeYBaja_H

#include <string>
#include "TipoPublicacion.h"
using namespace std;

class IControladorSubeYBaja {
    public:
        virtual  bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio)=0;
};

#endif