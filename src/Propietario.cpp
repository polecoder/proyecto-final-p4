#include "Usuario.h"
#include "DTNotificacion.h"
#include "Propietario.h"
#include "Inmobiliaria.h"
#include <set>
#include <map>
#include <string>

using namespace std;

Propietario::Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)
    : Usuario(nickname, contrasena, nombre, email)
{
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
}

Propietario::~Propietario() {}

string Propietario::getCuentaBancaria()
{
    return this->cuentaBancaria;
}

string Propietario::getTelefono()
{
    return this->telefono;
}

set<DTNotificacion> Propietario::getNotificaciones()
{
    return this->notificaciones;
}

map<string, Inmobiliaria *> Propietario::getSuscripciones()
{
    return this->suscripciones;
}

void Propietario::setCuentaBancaria(string cuentaBancaria)
{
    this->cuentaBancaria = cuentaBancaria;
}

void Propietario::setTelefono(string telefono)
{
    this->telefono = telefono;
}

void Propietario::agregarNotificacion(DTNotificacion const &notificacion)
{
    this->notificaciones.insert(notificacion);
}

void Propietario::eliminarNotificaciones()
{
    this->notificaciones.clear();
}

void Propietario::agregarSuscripcion(Inmobiliaria *inmobiliaria)
{
    this->suscripciones[inmobiliaria->getNickname()] = inmobiliaria;
}

void Propietario::eliminarSuscripcion(string nicknameInmobiliaria)
{
    // find() retorna this->suscripciones.end() si el elemento no existe
    map<string, Inmobiliaria *>::iterator it = this->suscripciones.find(nicknameInmobiliaria);
    if (it != this->suscripciones.end())
    {
        delete it->second; // Llama al destructor de Inmobiliaria
        suscripciones.erase(it);
    }
}