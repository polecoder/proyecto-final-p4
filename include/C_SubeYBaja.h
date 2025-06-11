#ifndef SUBE_Y_BAJA
#define SUBE_Y_BAJA
#include "Publicacion.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliaria.h"
#include "HandlerPublicacion.h"
#include "DTFecha.h"
#include "IControladorFechaActual.h"
#include "AdministraPropiedad.h"
#include "TipoPublicacion.h"
#include "DTNotificacion.h"
#include "Casa.h"
#include "Apartamento.h"
#include "TipoInmueble.h"
#include <string>

using namespace std;

class SubeYBaja{
private:
    handlerInmobiliaria* Hinmobiliarias;
    IControladorFechaActual* fechaActual;
    HandlerPublicacion* HPublicacion;
public:
    SubeYBaja();  // Constructor
    ~SubeYBaja(); // Destructor
    bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio);
};



#endif