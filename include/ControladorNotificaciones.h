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
    HandlerInmobiliarias *handlerInmobiliarias;
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
};

#endif