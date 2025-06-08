#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include <string>

using namespace std;

class Inmobiliaria : public Usuario {
    private:
        string direccion;
        string url;
        string telefono;
    public:
        Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        ~Inmobiliaria();
        
        string getDireccion();
        string getUrl();
        string getTelefono();
};

#endif