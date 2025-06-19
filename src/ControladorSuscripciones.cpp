#include "../include/ControladorSuscripciones.h"
#include <set>
#include <map>

using namespace std;

ControladorSuscripciones *ControladorSuscripciones::instancia =NULL;

ControladorSuscripciones::ControladorSuscripciones(){
    this->handlerInmobiliaria = HandlerInmobiliaria::getInstancia();
    this->handlerPropietarios = HandlerPropietarios::getInstancia();
    this->handlerClientes = HandlerClientes::getInstancia();
};

ControladorSuscripciones *ControladorSuscripciones::getInstancia(){
    if(instancia == NULL){
        instancia = new ControladorSuscripciones();
    }
    return instancia;
}
ControladorSuscripciones::~ControladorSuscripciones(){};

void ControladorSuscripciones::suscribirse(string nicknameUsuario, set<string> inmobiliariasElegidas){
    if(this->handlerClientes->existeCliente(nicknameUsuario)){
        Cliente *cliente = this->handlerClientes->getCliente(nicknameUsuario);
        for(set<string>::iterator it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); ++it){
            string nicknameInmobiliaria = *it;
            Inmobiliaria *inmobiliaria = this->handlerInmobiliaria->DevolverInmobiliaria(nicknameInmobiliaria);
            cliente->agregarSuscripcion(inmobiliaria);
            inmobiliaria->agregarClienteSuscripto(cliente);
        }
    }
    if(this->handlerPropietarios->existePropietario(nicknameUsuario)){
        Propietario *propietario = this->handlerPropietarios->getPropietario(nicknameUsuario);
        for(set<string>::iterator it = inmobiliariasElegidas.begin(); it != inmobiliariasElegidas.end(); ++it){
            string nicknameInmobiliaria = *it;
            Inmobiliaria *inmobiliaria = this->handlerInmobiliaria->DevolverInmobiliaria(nicknameInmobiliaria);
            propietario->agregarSuscripcion(inmobiliaria);
            inmobiliaria->agregarPropietarioSuscripto(propietario);
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