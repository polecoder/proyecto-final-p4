#include "../include/HPUsuario.h"
#include "../include/Propietario.h"

#include <iostream>
using namespace std;

inmobiliaria::Usuario::Propietario(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono)
    : Usuario(nickname, contrasena, nombre, email), direccion(direccion), url(url), telefono(telefono) {
    
}
// Constructor de Propietario