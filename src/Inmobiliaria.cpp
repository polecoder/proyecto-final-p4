#include "../include/Inmobiliaria.h"
#include <iostream>

using namespace std;

Inmobiliaria::Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)
    : Usuario(nickname, contrasena, nombre, email)
{
    this->direccion = direccion;
    this->url = url;
    this->telefono = telefono;
}
Inmobiliaria::~Inmobiliaria() {
};

string Inmobiliaria::getDireccion()
{
    return direccion;
};
string Inmobiliaria::getUrl()
{
    return url;
};
map<string, Propietario *> Inmobiliaria::getPropietarios()
{
    return propietariosRepresentados;
}
void Inmobiliaria::agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad)
{
    this->administraPropiedad.push_back(administraPropiedad);
}
string Inmobiliaria::getTelefono()
{
    return telefono;
};