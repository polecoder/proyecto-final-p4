#include <set>
#include "../include/HandlerPropietarios.h"
#include "../include/HandlerClientes.h"
#include "../include/HandlerInmobiliarias.h"
#include "../include/DTNotificacion.h"
#include "../include/ControladorListar.h"
#include "../include/DTUsuario.h"

using namespace std;

ControladorListar *ControladorListar::instancia = NULL;

ControladorListar::ControladorListar()
{
    this->handlerPropietarios = HandlerPropietarios::getInstancia();
    this->handlerClientes = HandlerClientes::getInstancia();
    this->handlerInmobiliarias = HandlerInmobiliarias::getInstancia();
    this->interfazFechaActual = ControladorFechaActual::getInstancia();
}

ControladorListar *ControladorListar::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ControladorListar;
    }
    return instancia;
}

ControladorListar::~ControladorListar() {}

set<DTUsuario> ControladorListar::listarInmobiliarias()
{
    map<string, Inmobiliaria *> inmo = this->handlerInmobiliarias->getColeccionInmobiliarias();
    set<DTUsuario> salida;
    map<string, Inmobiliaria *>::iterator it;
    for (it = inmo.begin(); it != inmo.end(); ++it)
    {
        salida.insert(DTUsuario(it->first, it->second->getNombre())); // first es el nickname, second es el objeto inmobiliaria
    }
    return salida;
}

set<DTInmuebleAdministrado> ControladorListar::listarInmueblesAdministrados(string nicknameInmobiliaria)
{
    vector<AdministraPropiedad *> adProp = this->handlerInmobiliarias->getColeccionAdministraPropiedad(nicknameInmobiliaria);
    set<DTInmuebleAdministrado> salida;
    vector<AdministraPropiedad *>::iterator it;
    for (it = adProp.begin(); it != adProp.end(); ++it)
    {
        salida.insert(DTInmuebleAdministrado(((*it)->getInmueble())->getCodigo(), ((*it)->getInmueble())->getDireccion(), this->interfazFechaActual->getFechaActual()));
    }
    return salida;
}

// PRE-CONDICIÓN: (existePropietario(nicknameUsuario) || existeCliente(nicknameUsuario)) == true
set<DTNotificacion> ControladorListar::listarNotificacionesDeUsuario(string nicknameUsuario)
{
    // TODO: Implementar con dynamic_cast<>
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

// PRE-CONDICIÓN: (existeCliente(nicknameUsuario) || existePropietario(nicknameUsuario))
set<DTUsuario> ControladorListar::listarSuscripciones(string nicknameUsuario)
{
    // TODO: Implementar con dynamic_cast<>
    // TODO: Hacerlo sin if/else (no se me ocurre mejor forma que esta)
    set<DTUsuario> resultado;
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

set<DTUsuario> ControladorListar::listarPropietarios(){

    map<string, Propietario *> propietarios = this->handlerPropietarios->getColeccionPropietarios();
    set<DTUsuario> Mostrar;
    map<string, Propietario *>::iterator it;
    for (it = propietarios.begin(); it != propietarios.end(); ++it)
    {
        Mostrar.insert(DTUsuario(it->first, it->second->getNombre())); // first es el nickname, second es el objeto propietario
    }
    return Mostrar;
}