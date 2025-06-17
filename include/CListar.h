#ifndef C_LISTAR
#define C_LISTAR
#include "DTUsuario.h"
#include "DTInmueble.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliaria.h"
#include "DTInmuebleAdministrado.h"
#include "AdministraPropiedad.h"
#include "IControladorFechaActual.h"
#include "HandlerPublicacion.h"
#include "DTPublicacion.h"
#include "DTCasa.h"
#include "DTApartamento.h"
#include "Casa.h"
#include "Apartamento.h"

#include <map>
#include <string>
#include <set>

using namespace std; // Esto evita tener que escribir std::

class Listar {
private:
    static Listar* instancia;
    HandlerInmobiliaria* Hinmobiliarias;
    IControladorFechaActual* fechaActual;
public:
    static Listar* getInstancia();

    set<DTUsuario> listarInmobiliarias();
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);

    set<DTPublicacion> listarPublicaciones(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo);
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion);
};

#endif
