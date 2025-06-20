#ifndef ICONTROLADORLISTAR_H
#define ICONTROLADORLISTAR_H

#include <set>
#include <string>
#include "DTNotificacion.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "TipoPublicacion.h"
#include "TipoInmueble.h"
#include "DTPublicacion.h"
#include "DTInmueble.h"

using namespace std;

class IControladorListar{
    public:
        virtual set<DTUsuario> listarInmobiliarias()=0;
        virtual set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria)=0;
        virtual set<DTNotificacion> listarNotificacionesDeUsuario(string nicknameUsuario) = 0;
        virtual set<DTUsuario> listarSuscripciones(string nicknameUsuario) = 0;
        virtual set<DTPublicacion> listarPublicaciones(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo)=0;
        virtual DTInmueble detalleInmueblePublicacion(int codigoPublicacion)=0;
        virtual set<DTUsuario> listarInmobiliariasNoSuscripto(string nicknameUsuario)=0;
};

#endif