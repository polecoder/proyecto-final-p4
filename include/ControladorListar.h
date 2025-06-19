#ifndef CONTROLADORLISTAR_H
#define CONTROLADORLISTAR_H

#include <set>
#include "HandlerPropietarios.h"
#include "HandlerClientes.h"
#include "HandlerInmobiliarias.h"
#include "DTNotificacion.h"
#include "DTUsuario.h"
#include "IControladorListar.h"

using namespace std;

class ControladorListar : public IControladorListar
{
private:
    static ControladorListar *instancia;
    HandlerPropietarios *handlerPropietarios;
    HandlerClientes *handlerClientes;
    HandlerInmobiliarias *handlerInmobiliarias;
    IControladorFechaActual *interfazFechaActual;
    ControladorListar();

public:
    static ControladorListar *getInstancia();
    ~ControladorListar();
    /**
     * @brief TODO: Agregar descripción de la operación
     *
     * @return set<DTUsuario> TODO: Agregar descripción de los datos de retorno
     */
    set<DTUsuario> listarInmobiliarias();
    /**
     * @brief TODO: Agregar descripción de la operación
     *
     * @param nicknameInmobiliaria TODO: Agregar descripción de parámetros
     * @return set<DTInmuebleAdministrado> TODO: Agregar descripción de los datos de retorno
     */
    set<DTInmuebleAdministrado> listarInmueblesAdministrados(string nicknameInmobiliaria);
    /**
     * @brief Devuelve todas las notificaciones del usuario "u" en el sistema tal que u.nickname=nicknameUsuario
     *
     * PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true.
     *
     * @param nicknameUsuario
     *
     * @return set<DTNotificacion> que contiene todas las notificaciones del usuario "u"
     */
    set<DTNotificacion> listarNotificacionesDeUsuario(string nicknameUsuario);
    /**
     * @brief Lista el nickname y nombre de todas las Inmobiliarias a las que el usuario "u" en el sistema tal que u.nickname=nicknameUsuario está suscrito
     *
     * PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario))
     *
     * @param nicknameUsuario El nickname del usuario del que se quieren listar las suscripciones
     * @return set<DTUsuario> que contiene el nickname y nombre de todas las Inmobiliarias a las que el usuario está suscrito
     */
    set<DTUsuario> listarSuscripciones(string nicknameUsuario);
};

#endif