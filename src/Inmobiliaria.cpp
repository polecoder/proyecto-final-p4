#include "../include/Inmobiliaria.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

Inmobiliaria::Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)
    :Usuario(nickname, contrasena, nombre, email) // Llama al constructor de Usuario
{
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
    // El vector administraProps se inicializa solo
}
Inmobiliaria::~Inmobiliaria() {
};

string Inmobiliaria::getDireccion() const
{
    return direccion;
};
string Inmobiliaria::getUrl() const
{
    return url;
};
string Inmobiliaria::getTelefono() const
{
    return telefono;
};
vector<AdministraPropiedad *> Inmobiliaria::getadministraProps() const
{
    return administraProps;
};

map<string, Propietario *> Inmobiliaria::getPropietarios()
{
    return PropietariosAsociados;
}

void Inmobiliaria::notificar(DTNotificacion notificacion)
{
    map<string, Cliente *>::iterator it;
    map<string, Propietario *>::iterator it2;
    for (it = clientesAsociados.begin(); it != clientesAsociados.end(); it++)
    {
        (*it).second->agregarNotificacion(notificacion);
    };
    for (it2 = PropietariosAsociados.begin(); it2 != PropietariosAsociados.end(); it++)
    {
        (*it2).second->agregarNotificacion(notificacion);
    }
}
void Inmobiliaria::agregarClienteSuscripto(Cliente *cliente){
    this->clientesAsociados[cliente->getNickname()] = cliente;
};

void Inmobiliaria::agregarPropietario(Propietario *propietario){
    this->PropietariosAsociados[propietario->getNickname()] = propietario;
};

void Inmobiliaria::eliminarPropietario(string nicknamePropietario){
    this->PropietariosAsociados.erase(nicknamePropietario);
};

void Inmobiliaria::agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad)
{
    this->administraPropiedad.push_back(administraPropiedad);
}

