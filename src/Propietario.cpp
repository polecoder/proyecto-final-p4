#include "Propietario.h"
#include "Usuario.h"
#include <set>
#include <string>

using namespace std;

Propietario::Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)
    : Usuario(nickname, contrasena, nombre, email)
{
    this->cuentaBancaria = cuentaBancaria;
    this->telefono = telefono;
}

string Propietario::getCuentaBancaria()
{
    return cuentaBancaria;
}

string Propietario::getTelefono()
{
    return telefono;
}

void Propietario::setCuentaBancaria(string cuentaBancaria)
{
    this->cuentaBancaria = cuentaBancaria;
}

void Propietario::setTelefono(string telefono)
{
    this->telefono = telefono;
}

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
