#ifndef CONTROLADORLISTAR_H
#define CONTROLADORLISTAR_H

#include <set>
#include "Handlers.h"
#include "DTNotificacion.h"
#include "DTUsuario.h"

using namespace std;

class ControladorListar
{
private:
    static ControladorListar *instance;
    HandlerPropietarios *handlerPropietarios;
    HandlerClientes *handlerClientes;
    /**
     * @brief Constructor de ControladorListar (PRIVADO)
     *
     */
    ControladorListar();

public:
    /**
     * @brief Getter para la instancia del ControladorListar
     *
     * @return ControladorListar
     */
    static ControladorListar *getInstance();
    /**
     * @brief Destructor de ControladorListar
     *
     */
    ~ControladorListar();
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