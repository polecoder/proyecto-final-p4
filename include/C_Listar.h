#ifndef C_LISTAR
#define C_LISTAR
#include "DTUsuario.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliaria.h"
#include "DTInmuebleAdministrado.h"
#include "AdministraPropiedad.h"
#include "IControladorFechaActual.h"
#include "HandlerPublicacion.h"
#include "DTPublicacion.h"

#include <map>
#include <string>
#include <set>

using namespace std; // Esto evita tener que escribir std::

class Listar {
private:
    handlerInmobiliaria* Hinmobiliarias;
    IControladorFechaActual* fechaActual;
public:
    void inicializarHInmobiliarias(handlerInmobiliaria* handler);
    set<DTUsuario> listarInmobiliarias();
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);

    set<DTPublicacion> listarPublicacionesActivas(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo);
    DTPublicacion detalleInmueble(int codigoPublicacion);
};

#endif
