#ifndef C_SUBE_Y_BAJA
#define C_SUBE_Y_BAJA
#include "HandlerInmobiliaria.h"
#include "HandlerPropietario.h"
#include "HandlerCliente.h"

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
#include "IControladorSubeYBaja.h"
#include "Apartamento.h"
#include "TipoInmueble.h"
#include <string>


using namespace std;

class SubeYBaja : public IControladorSubeYBaja{
private:

    static SubeYBaja* Instancia;
    HandlerInmobiliaria* Hinmobiliarias;
    HandlerPropietario* Hpropietario;
    HandlerCliente* Hcliente;
    IControladorFechaActual* fechaActual;
    HandlerPublicacion* HPublicacion;
    SubeYBaja();  // Constructor
public:
    static SubeYBaja* getInstancia();
    ~SubeYBaja(); // Destructor
    bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio);

     bool altaPropietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
    bool altaInmobiliaria(string nickname, string contrasena, string nombre, string email, string url, string telefono);
    bool altaCliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);

};



#endif