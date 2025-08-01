#ifndef CONTROLADORLISTAR_H
#define CONTROLADORLISTAR_H
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "HandlerInmobiliarias.h"
#include "HandlerClientes.h"
#include "HandlerPropietarios.h"
#include "HandlerInmueble.h"
#include "IControladorListar.h"
#include "AdministraPropiedad.h"
#include "ControladorFechaActual.h"
#include "HandlerPublicacion.h"
#include "DTUsuario.h"
#include "DTInmuebleAdministrado.h"
#include "DTInmuebleListado.h"
#include "DTPublicacion.h"
#include "DTInmueble.h"
#include "DTCasa.h"
#include "DTApartamento.h"
#include "DTNotificacion.h"
#include "Casa.h"
#include "Apartamento.h"

#include <map>
#include <string>
#include <set>

using namespace std; // Esto evita tener que escribir std::

class ControladorListar : public IControladorListar
{
private:
    static ControladorListar *instancia;
    HandlerPropietarios *handlerPropietarios;
    HandlerClientes *handlerClientes;
    HandlerInmobiliarias *handlerInmobiliarias;
    HandlerInmueble *handlerInmueble;
    HandlerPublicacion *handlerPublicaciones;
    IControladorFechaActual *interfazFechaActual;
    ControladorListar();

public:
    static ControladorListar *getInstancia();
    static void destroy();
    ~ControladorListar();

    set<DTInmuebleListado> listarInmuebles();                                                    // Devuelve la información de código, dirección y nombre del propietario de los inmuebles de la coleccion
    set<DTInmuebleListado> getInmueblesNoAdministradosInmobiliaria(string nicknameInmobiliaria); // Obtiene los inmuebles que no son administrados por la inmobiliaria

    set<DTUsuario> listarInmobiliarias();
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);
    set<DTNotificacion> listarNotificacionesDeUsuario(string nicknameUsuario);
    set<DTUsuario> listarSuscripciones(string nicknameUsuario);
    set<DTUsuario> listarPropietarios();

    set<DTPublicacion> listarPublicaciones(TipoPublicacion tipoPub, float precioMin, float precioMax, TipoInmueble tipo);
    DTInmueble *detalleInmueblePublicacion(int codigoPublicacion);
    DTInmueble *detalleInmueble(int codigoInmueble);
    set<DTUsuario> listarInmobiliariasNoSuscripto(string nicknameUsuario); // PRE: existe un usuario con nickname=nicknameUsuario.
};

#endif
