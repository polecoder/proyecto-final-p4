#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "AdministraPropiedad.h"
#include <string>
#include <vector>
using namespace std;
class Inmobiliaria : public Usuario {
    private:
        string direccion;
        string url;
        string telefono;
        vector <AdministraPropiedad> administraProps;

    public:
        Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        ~Inmobiliaria();

        string getDireccion() ;
        string getUrl() ;
        string getTelefono() ;
        vector<AdministraPropiedad> getadministraProps() ;
};

#endif