#ifndef C_SUBE_Y_BAJA
#define C_SUBE_Y_BAJA
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
    static SubeYBaja* Instancia;
    HandlerInmobiliaria* Hinmobiliarias;
    IControladorFechaActual* fechaActual;
    HandlerPublicacion* HPublicacion;
    SubeYBaja();  // Constructor
public:
    static SubeYBaja* getInstancia();
    ~SubeYBaja(); // Destructor
    bool altaPublicacion(string nicknameInmobiliaria, int codigoInmueble,TipoPublicacion tipoPublicacion, string texto, float precio);
};



#endif