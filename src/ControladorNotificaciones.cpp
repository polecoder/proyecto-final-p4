#include <set>
#include "../include/Handlers.h"
#include "../include/DTNotificacion.h"
#include "../include/ControladorNotificaciones.h"

using namespace std;

ControladorNotificaciones *ControladorNotificaciones::instance = NULL;

ControladorNotificaciones::ControladorNotificaciones()
{
    this->handlerPropietarios = HandlerPropietarios::getInstance();
    this->handlerClientes = HandlerClientes::getInstance();
}

ControladorNotificaciones *ControladorNotificaciones::getInstance()
{
    if (instance == NULL)
    {
        instance = new ControladorNotificaciones;
    }
    return instance;
}

ControladorNotificaciones::~ControladorNotificaciones()
{
    // TODO: Revisar si corresponde eliminar los Handlers en este destructor
}

// PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true
void ControladorNotificaciones::borrarNotificaciones(string nicknameUsuario)
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
void ControladorNotificaciones::eliminarSuscripcion(string nicknameUsuario, set<string> inmobiliariasElegidas)
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