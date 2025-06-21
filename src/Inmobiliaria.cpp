#include "../include/Inmobiliaria.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

Inmobiliaria::Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)
    : Usuario(nickname, contrasena, nombre, email) // Llama al constructor de Usuario
{
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
    // El vector administraProps se inicializa solo
}

Inmobiliaria::~Inmobiliaria() {};

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

map<string, Cliente *> Inmobiliaria::getClientesSuscritos() const
{
    return clientesSuscritos;
}

map<string, Propietario *> Inmobiliaria::getPropietariosRepresentados() const
{
    return propietariosRepresentados;
}

map<string, Propietario *> Inmobiliaria::getPropietariosSuscritos() const
{
    return propietariosSuscritos;
}

vector<AdministraPropiedad *> Inmobiliaria::getAdministraProps() const
{
    return administraProps;
}

void Inmobiliaria::agregarClienteSuscripto(Cliente *cliente)
{
    this->clientesSuscritos[cliente->getNickname()] = cliente;
}

void Inmobiliaria::agregarPropietarioRepresentado(Propietario *propietario)
{
    this->propietariosRepresentados[propietario->getNickname()] = propietario;
}

void Inmobiliaria::agregarPropietarioSuscrito(Propietario *propietario)
{
    this->propietariosSuscritos[propietario->getNickname()] = propietario;
}

void Inmobiliaria::agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad)
{
    this->administraProps.push_back(administraPropiedad);
}

void Inmobiliaria::eliminarClienteSuscrito(string nicknameCliente)
{
    this->clientesSuscritos.erase(nicknameCliente);
}

void Inmobiliaria::eliminarPropietarioRepresentado(string nicknamePropietario)
{
    this->propietariosRepresentados.erase(nicknamePropietario);
}

void Inmobiliaria::eliminarPropietarioSuscrito(string nicknamePropietario)
{
    this->propietariosSuscritos.erase(nicknamePropietario);
}

void Inmobiliaria::notificar(DTNotificacion notificacion)
{
    map<string, Cliente *>::iterator it;
    map<string, Propietario *>::iterator it2;
    for (it = clientesSuscritos.begin(); it != clientesSuscritos.end(); it++)
    {
        it->second->agregarNotificacion(notificacion);
    };
    for (it2 = propietariosSuscritos.begin(); it2 != propietariosSuscritos.end(); it2++)
    {
        it2->second->agregarNotificacion(notificacion);
    }
}

ostream &operator<<(ostream &os, const Inmobiliaria &i)
{
    os << "INMOBILIARIA: [nickname: " << i.getNickname() << "; contrasena: " << i.getContrasena() << "; nombre: " << i.getNombre() << "; email: " << i.getEmail() << "; direccion: " << i.getDireccion() << "; Url: " << i.getUrl() << "; documento: " << i.getTelefono() << "]";
    return os;
}