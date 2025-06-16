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
    HandlerInmobiliaria* Hinmobiliarias;
    HandlerPropietario* Hpropietarios;
    HandlerCliente* Hclientes;
    IControladorFechaActual* fechaActual;
public:
    void inicializarHInmobiliarias(HandlerInmobiliaria* handler);
    bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio);


    bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
    bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string url, string telefono);
    bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
};



#endif