#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include <string>

using namespace std;

class Propietario : public Usuario
{
private:
    string cuentaBancaria;
    string telefono;

public:
    Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
};

#endif