#ifndef ICONTROLADORSUSCRIPCIONES_H
#define ICONTROLADORSUSCRIPCIONES_H

#include <string>
#include <set>

using namespace std;

class IControladorSuscripciones
{
public:
    /**
     * @brief Borra todas las notificaciones del usuario "u" en el sistema tal que u.nickname=nicknameUsuario
     *
     * PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true.
     *
     * @param nicknameUsuario
     */
    virtual void borrarNotificaciones(string nicknameUsuario) = 0;
    /**
     * @brief Elimina la relación entre el usuario "u" en el sistema tal que u.nickname=nicknameUsuario y las inmobiliarias indicadas por parámetro
     *
     * PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario)) && (para todas inmobiliariasElegidas) existeInmobiliaria(nicknameInmobiliaria)
     *
     * @param nicknameUsuario El nickname del usuario del que se quieren eliminar las suscripciones
     * @param inmobiliariasElegidas Un set de todos los nicknames de las inmobiliarias a las que el usuario se va a desuscribir
     */
    virtual void eliminarSuscripcion(string nicknameUsuario, set<string> inmobiliariasElegidas) = 0;
    /**
     * @brief Destructor de IControladorSuscripciones
     *
     */
    virtual ~IControladorSuscripciones() {}
};

#endif