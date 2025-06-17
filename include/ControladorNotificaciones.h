#ifndef CONTROLADORNOTIFICACIONES_H
#define CONTROLADORNOTIFICACIONES_H

#include <set>
#include "Handlers.h"
#include "DTNotificacion.h"

using namespace std;

class ControladorNotificaciones
{
private:
    static ControladorNotificaciones *instance;
    HandlerPropietarios *handlerPropietarios;
    HandlerClientes *handlerClientes;
    /**
     * @brief Constructor de ControladorNotificaciones (PRIVADO)
     *
     */
    ControladorNotificaciones();

public:
    /**
     * @brief Getter para la instancia del ControladorNotificaciones
     *
     * @return ControladorNotificaciones
     */
    static ControladorNotificaciones *getInstance();
    /**
     * @brief Destructor de ControladorNotificaciones
     *
     */
    ~ControladorNotificaciones();
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
     * @brief Borra todas las notificaciones del usuario "u" en el sistema tal que u.nickname=nicknameUsuario
     *
     * PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true.
     *
     * @param nicknameUsuario
     */
    void borrarNotificaciones(string nicknameUsuario);
    /**
     * @brief Elimina la relación entre el usuario "u" en el sistema tal que u.nickname=nicknameUsuario y las inmobiliarias indicadas por parámetro
     *
     * PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario)) && (para todas inmobiliariasElegidas) existeInmobiliaria(nicknameInmobiliaria)
     *
     * @param nicknameUsuario El nickname del usuario del que se quieren eliminar las suscripciones
     * @param inmobiliariasElegidas Un set de todos los nicknames de las inmobiliarias a las que el usuario se va a desuscribir
     */
    void eliminarSuscripcion(string nicknameUsuario, set<string> inmobiliariasElegidas);
};

#endif