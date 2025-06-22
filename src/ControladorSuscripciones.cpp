#include <set>
#include "../include/HandlerPropietarios.h"
#include "../include/HandlerClientes.h"
#include "../include/HandlerInmobiliarias.h"
#include "../include/DTNotificacion.h"
#include "../include/ControladorSuscripciones.h"
#include <map>
#include <iostream>

using namespace std;

ControladorSuscripciones *ControladorSuscripciones::instancia = NULL;

ControladorSuscripciones::ControladorSuscripciones()
{
    this->handlerInmobiliarias = HandlerInmobiliarias::getInstancia();
    this->handlerPropietarios = HandlerPropietarios::getInstancia();
    this->handlerClientes = HandlerClientes::getInstancia();
};

ControladorSuscripciones *ControladorSuscripciones::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ControladorSuscripciones();
    }
    return instancia;
}
ControladorSuscripciones::~ControladorSuscripciones() {};

void ControladorSuscripciones::borrarNotificaciones(string nicknameUsuario)
{
    if (this->handlerClientes->existeCliente(nicknameUsuario))
    {
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        cliente->eliminarNotificaciones();
    }
    else
    {
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        propietario->eliminarNotificaciones();
    }
}

void ControladorSuscripciones::suscribirse(string nicknameUsuario, set<string> inmobiliariasElegidas)
{
    if (this->handlerClientes->existeCliente(nicknameUsuario))
    {
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        for (set<string>::iterator it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); ++it)
        {
            string nicknameInmobiliaria = *it;
            Inmobiliaria *inmobiliaria = this->handlerInmobiliarias->getInmobiliaria(nicknameInmobiliaria);
            cliente->agregarSuscripcion(inmobiliaria);
            inmobiliaria->agregarClienteSuscripto(cliente);
        }
    }
    if (this->handlerPropietarios->existePropietario(nicknameUsuario))
    {
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        for (set<string>::iterator it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); ++it)
        {
            string nicknameInmobiliaria = *it;
            Inmobiliaria *inmobiliaria = this->handlerInmobiliarias->getInmobiliaria(nicknameInmobiliaria);
            propietario->agregarSuscripcion(inmobiliaria);
            inmobiliaria->agregarPropietarioSuscrito(propietario);
        }
    }
}

void ControladorSuscripciones::eliminarSuscripcion(string nicknameUsuario, set<string> inmobiliariasElegidas)
{
    // TODO: Hacerlo sin if/else (no se me ocurre mejor forma que esta)
    if (this->handlerClientes->existeCliente(nicknameUsuario))
    {
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        set<string>::iterator it;
        for (it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); ++it)
        {
            cliente->eliminarSuscripcion(*it);
            Inmobiliaria *inmobiliaria = this->handlerInmobiliarias->getInmobiliaria(*it);
            inmobiliaria->eliminarClienteSuscrito(nicknameUsuario);
        }
    }
    else
    {
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        set<string>::iterator it;
        for (it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); ++it)
        {
            propietario->eliminarSuscripcion(*it);
            Inmobiliaria *inmobiliaria = this->handlerInmobiliarias->getInmobiliaria(*it);
            inmobiliaria->eliminarPropietarioSuscrito(nicknameUsuario);
        }
    }
}
