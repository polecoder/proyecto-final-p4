#ifndef C_LISTAR
#define C_LISTAR
#include "DTUsuario.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliaria.h"
#include "DTInmuebleAdministrado.h"
#include "IControladorListar.h"
#include "AdministraPropiedad.h"
#include "ControladorFechaActual.h"
#include "HandlerPublicacion.h"
#include "DTPublicacion.h"
#include "DTInmueble.h"
#include "DTCasa.h"
#include "DTApartamento.h"
#include "Casa.h"
#include "Apartamento.h"

#include <map>
#include <string>
#include <set>

using namespace std; // Esto evita tener que escribir std::

class Listar: public IControladorListar {
private:
    static Listar* instancia;
    HandlerInmobiliaria* Hinmobiliarias;
    ControladorFechaActual* fechaActual;
    Listar();
public:
    static Listar* getInstancia();
    ~Listar();

    set<DTUsuario> listarInmobiliarias();
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);

    set<DTPublicacion> listarPublicaciones(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo);
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion);
};

#endif
