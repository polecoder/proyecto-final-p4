#include "../include/Propietario.h"
#include "../include/Usuario.h"

Propietario::Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono)
    : Usuario(nickname, contrasena, nombre, email), cuentaBancaria(cuentaBancaria), telefono(telefono) {
    // cuerpo del constructor si es necesario
}