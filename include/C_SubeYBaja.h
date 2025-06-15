#ifndef SUBE_Y_BAJA
#define SUBE_Y_BAJA
#include "Publicacion.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliaria.h"
#include "DTFecha.h"
#include "IControladorFechaActual.h"
#include "AdministraPropiedad.h"
#include "TipoPublicacion.h"

#include <string>
using namespace std;

class SubeYBaja{
private:
    handlerInmobiliaria* Hinmobiliarias;
    IControladorFechaActual* fechaActual;
public:
    // TODO: Agregar constructor y destructor
    void inicializarHInmobiliarias(handlerInmobiliaria* handler);
    bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio);
    
    
    bool altaPropietario(nickname:String, contrasena:String, nombre:String, email:String, cuentaBancaria:String, telefono:String);
    bool altaInmobiliaria(nickname:String, contrasena:String, nombre:String, email:String, url:String, telefono:String);
    bool altaCliente(nickname:String, contrasena:String, nombre:String, email:String, apellido:String, documento:String);
};



#endif
