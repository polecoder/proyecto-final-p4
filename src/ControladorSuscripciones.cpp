#include <set>
#include "../include/Handlers.h"
#include "../include/DTNotificacion.h"
#include "../include/ControladorSuscripciones.h"

using namespace std;

ControladorSuscripciones *ControladorSuscripciones::instance = NULL;

ControladorSuscripciones::ControladorSuscripciones()
{
    this->handlerPropietarios = HandlerPropietarios::getInstance();
    this->handlerClientes = HandlerClientes::getInstance();
}

ControladorSuscripciones *ControladorSuscripciones::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorSuscripciones;
    }
    return instance;
}

ControladorSuscripciones::~ControladorSuscripciones()
{
    // TODO: Revisar si corresponde eliminar los Handlers en este destructor
}

// PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true
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

// PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario)) && (para todas inmobiliariasElegidas) existeInmobiliaria(nicknameInmobiliaria)
void ControladorSuscripciones::eliminarSuscripcion(string nicknameUsuario, set<string> inmobiliariasElegidas)
{
    // TODO: Hacerlo sin if/else (no se me ocurre mejor forma que esta)
    if (this->handlerClientes->existeCliente(nicknameUsuario))
    {
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        set<string>::iterator it;
        for (it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); it++)
        {
            cliente->eliminarSuscripcion(*it);
        }
    }
    else
    {
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        set<string>::iterator it;
        for (it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); it++)
        {
            propietario->eliminarSuscripcion(*it);
        }
    }
}