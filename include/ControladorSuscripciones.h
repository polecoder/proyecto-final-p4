#ifndef CONTROLADORSUSCRIPCIONES_H
#define CONTROLADORSUSCRIPCIONES_H

#include <set>
#include "Handlers.h"
#include "DTNotificacion.h"
#include "IControladorSuscripciones.h"

using namespace std;

class ControladorSuscripciones : public IControladorSuscripciones
{
private:
    static ControladorSuscripciones *instance;
    HandlerPropietarios *handlerPropietarios;
    HandlerClientes *handlerClientes;
    /**
     * @brief Constructor de ControladorSuscripciones (PRIVADO)
     *
     */
    ControladorSuscripciones();

public:
    /**
     * @brief Getter para la instancia del ControladorSuscripciones
     *
     * @return ControladorSuscripciones
     */
    static ControladorSuscripciones *getInstance();
    /**
     * @brief Destructor de ControladorSuscripciones
     *
     */
    ~ControladorSuscripciones();
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