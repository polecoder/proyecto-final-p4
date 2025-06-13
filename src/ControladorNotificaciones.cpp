#include <set>
#include "Handlers.h"
#include "DTNotificacion.h"
#include "ControladorNotificaciones.h"

using namespace std;

ControladorNotificaciones *ControladorNotificaciones::instance = NULL;

ControladorNotificaciones::ControladorNotificaciones()
{
    this->handlerPropietarios = HandlerPropietarios::getInstance();
    this->handlerInmobiliarias = HandlerInmobiliarias::getInstance();
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
set<DTNotificacion> ControladorNotificaciones::listarNotificacionesDeUsuario(string nicknameUsuario)
{
    if (this->handlerClientes->existeCliente(nicknameUsuario))
    {
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        return cliente->getNotificaciones();
    }
    else
    {
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        return propietario->getNotificaciones();
    }
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