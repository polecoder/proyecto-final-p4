#ifndef CONTROLADORSUSCRIPCIONES_H
#define CONTROLADORSUSCRIPCIONES_H

#include <set>
#include <string>
#include "Handlers.h"
#include "DTUsuario.h"

using namespace std;

class ControladorSuscripciones
{
private:
    static ControladorSuscripciones *instance;
    HandlerPropietarios *handlerPropietarios;
    HandlerInmobiliarias *handlerInmobiliarias;
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
     * @brief Lista el nickname y nombre de todas las Inmobiliarias a las que el usuario "u" en el sistema tal que u.nickname=nicknameUsuario está suscrito
     *
     * PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario))
     *
     * @param nicknameUsuario El nickname del usuario del que se quieren listar las suscripciones
     * @return set<DTUsuario> que contiene el nickname y nombre de todas las Inmobiliarias a las que el usuario está suscrito
     */
    set<DTUsuario> listarSuscripciones(string nicknameUsuario);
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