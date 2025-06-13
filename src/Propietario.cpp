#include "Usuario.h"
#include "DTNotificacion.h"
#include "Propietario.h"
#include <set>
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