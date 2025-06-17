#include <set>
#include <string>
#include "Handlers.h"
#include "DTUsuario.h"
#include "ControladorSuscripciones.h"

using namespace std;

ControladorSuscripciones *ControladorSuscripciones::instance = NULL;

ControladorSuscripciones::ControladorSuscripciones()
{
    this->handlerPropietarios = HandlerPropietarios::getInstance();
    this->handlerInmobiliarias = HandlerInmobiliarias::getInstance();
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

// PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario))
set<DTUsuario> ControladorSuscripciones::listarSuscripciones(string nicknameUsuario)
{
    set<DTUsuario> resultado;
    // TODO: Hacerlo sin if/else (no se me ocurre mejor forma que esta)
    if (this->handlerClientes->existeCliente(nicknameUsuario))
    {
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        map<string, Inmobiliaria *> suscripcionesCliente = cliente->getSuscripciones();
        map<string, Inmobiliaria *>::iterator it;
        for (it = suscripcionesCliente.begin(); it != suscripcionesCliente.end(); it++)
        {
            DTUsuario datosCliente(it->first, it->second->getNombre()); // Creo el objeto de forma estática (sin new)
            resultado.insert(datosCliente);
        }
    }
    else
    {
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        map<string, Inmobiliaria *> suscripcionesPropietario = propietario->getSuscripciones();
        map<string, Inmobiliaria *>::iterator it;
        for (it = suscripcionesPropietario.begin(); it != suscripcionesPropietario.end(); it++)
        {
            DTUsuario datosPropietario(it->first, it->second->getNombre()); // Creo el objeto de forma estática (sin new)
            resultado.insert(datosPropietario);
        }
    }
    return resultado;
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