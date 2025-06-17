#include "Usuario.h"
#include "DTNotificacion.h"
#include "Cliente.h"
#include "Inmobiliaria.h"
#include <set>
#include <map>
#include <string>

using namespace std;

Cliente::Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento)
    : Usuario(nickname, contrasena, nombre, email)
{
    this->apellido = apellido;
    this->documento = documento;
}

Cliente::~Cliente() {}

string Cliente::getApellido()
{
    return this->apellido;
}

string Cliente::getDocumento()
{
    return this->documento;
}

set<DTNotificacion> Cliente::getNotificaciones()
{
    return this->notificaciones;
}

map<string, Inmobiliaria *> Cliente::getSuscripciones()
{
    return this->suscripciones;
}

void Cliente::setApellido(string apellido)
{
    this->apellido = apellido;
}

void Cliente::setDocumento(string documento)
{
    this->documento = documento;
}

void Cliente::agregarNotificacion(DTNotificacion const &notificacion)
{
    this->notificaciones.insert(notificacion);
}

void Cliente::eliminarNotificaciones()
{
    this->notificaciones.clear();
}

void Cliente::agregarSuscripcion(Inmobiliaria *inmobiliaria)
{
    this->suscripciones[inmobiliaria->getNickname()] = inmobiliaria;
}

void Cliente::eliminarSuscripcion(string nicknameInmobiliaria)
{
    // find() retorna this->suscripciones.end() si el elemento no existe
    map<string, Inmobiliaria *>::iterator it = this->suscripciones.find(nicknameInmobiliaria);
    if (it != this->suscripciones.end())
    {
        delete it->second; // Llama al destructor de Inmobiliaria
        suscripciones.erase(it);
    }
}