#ifndef C_LISTAR
#define C_LISTAR
#include "DTUsuario.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliarias.h"
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
#include "HandlerClientes.h"
#include "HandlerPropietarios.h"

#include <map>
#include <string>
#include <set>

using namespace std; // Esto evita tener que escribir std::

class ControladorListar: public IControladorListar {
private:
    static ControladorListar *instancia;
    HandlerPropietarios* handlerPropietarios;
    HandlerClientes* handlerClientes;
    HandlerInmobiliaria* handlerInmobiliaria;
    ControladorFechaActual* fechaActual;
    ControladorListar();
public:
    static ControladorListar* getInstancia();
    ~ControladorListar();

    set<DTUsuario> listarInmobiliarias();
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);

    set<DTPublicacion> listarPublicaciones(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo);
    DTInmueble detalleInmueblePublicacion(int codigoPublicacion);

    set<DTUsuario> listarInmobiliariasNoSuscripto(string nicknameUsuario);//PRE: existe un usuario con nickname=nicknameUsuario.
};

#endif
