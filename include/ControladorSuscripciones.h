#ifndef CONTROLADORSUSCRIPCIONES_H
#define CONTROLADORSUSCRIPCIONES_H

#include <set>
#include "HandlerClientes.h"
#include "HandlerPropietarios.h"
#include "HandlerInmobiliarias.h"
#include "IControladorSuscripciones.h"
#include <DTUsuario.h>
#include <string>

using namespace std;

class ControladorSuscripciones : public IControladorSuscripciones
{
private:
    static ControladorSuscripciones *instancia;
    HandlerPropietarios *handlerPropietarios;
    HandlerClientes *handlerClientes;
    HandlerInmobiliaria *handlerInmobiliaria;
    ControladorSuscripciones();

public:

    static ControladorSuscripciones *getInstancia();
    ~ControladorSuscripciones();

    // set<DTUsuario> listarSuscripciones(string nicknameUsuario);
     /**
     * @brief Borra todas las notificaciones del usuario "u" en el sistema tal que u.nickname=nicknameUsuario
     *
     * PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true.
     *
     * @param nicknameUsuario
     */
    void borrarNotificaciones(string nicknameUsuario);
    void suscribirse(string nicknameUsuario, set<string> inmobiliariasElegidas);//PRE: existe usuario con nickname=nicknameUsuario && existen todas las inmobiliarias del set y ademas no estan relacionadas con el usuario. 
    void eliminarSuscripcion(string nicknameUsuario, set<string> inmobiliariasElegidas);

};

#endif