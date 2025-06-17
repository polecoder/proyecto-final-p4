#ifndef ICONTROLADORLISTAR_H
#define ICONTROLADORLISTAR_H

#include <string>
#include <set>
#include "DTNotificacion.h"
#include "DTUsuario.h"

using namespace std;

class IControladorListar
{
public:
    /**
     * @brief Devuelve todas las notificaciones del usuario "u" en el sistema tal que u.nickname=nicknameUsuario
     *
     * PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true.
     *
     * @param nicknameUsuario
     *
     * @return set<DTNotificacion> que contiene todas las notificaciones del usuario "u"
     */
    virtual set<DTNotificacion> listarNotificacionesDeUsuario(string nicknameUsuario) = 0;
    /**
     * @brief Lista el nickname y nombre de todas las Inmobiliarias a las que el usuario "u" en el sistema tal que u.nickname=nicknameUsuario está suscrito
     *
     * PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario))
     *
     * @param nicknameUsuario El nickname del usuario del que se quieren listar las suscripciones
     * @return set<DTUsuario> que contiene el nickname y nombre de todas las Inmobiliarias a las que el usuario está suscrito
     */
    virtual set<DTUsuario> listarSuscripciones(string nicknameUsuario) = 0;
    /**
     * @brief Destructor de IControladorListar
     *
     */
    virtual ~IControladorListar() {}
};

#endif