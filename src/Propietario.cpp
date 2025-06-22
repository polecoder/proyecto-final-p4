#include "../include/Usuario.h"
#include "../include/DTNotificacion.h"
#include "../include/Propietario.h"
#include "../include/Inmobiliaria.h"
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

Propietario::~Propietario()
{
    this->notificaciones.clear();
    this->suscripciones.clear();
    this->inmuebles.clear();
}

string Propietario::getCuentaBancaria() const
{
    return this->cuentaBancaria;
}

string Propietario::getTelefono() const
{
    return this->telefono;
}

set<DTNotificacion> Propietario::getNotificaciones() const
{
    return this->notificaciones;
}

map<string, Inmobiliaria *> Propietario::getSuscripciones() const
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
        // delete it->second; // Llama al destructor de Inmobiliaria
        suscripciones.erase(it);
    }
}
bool Propietario::estaSuscripto(const string &nicknameInmobiliaria)
{
    return this->suscripciones.find(nicknameInmobiliaria) != this->suscripciones.end();
};
void Propietario::agregarInmueble(Inmueble *inmueble)
{
    // Asegura que el inmueble no sea vacio y no este vinculado al propietario
    if ((inmueble != NULL) && find(inmuebles.begin(), inmuebles.end(), inmueble) == inmuebles.end())
    {
        inmueble->setPropietario(this);
        inmuebles.push_back(inmueble);
    }
}

vector<Inmueble *> &Propietario::getInmuebles()
{
    return inmuebles;
}

ostream &operator<<(ostream &os, const Propietario &p)
{
    os << "PROPIETARIO: [nickname: " << p.getNickname() << "; contrasena: " << p.getContrasena() << "; nombre: " << p.getNombre() << "; email: " << p.getEmail() << "; cuenta bancaria: " << p.getCuentaBancaria() << "; telefono: " << p.getTelefono() << "]";
    return os;
}