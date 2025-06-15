
#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "AdministraPropiedad.h"
#include <string>
#include <vector>

class Inmobiliaria : public Usuario {
    private:
        std::string direccion;
        std::string url;
        std::string telefono;
        std::vector <AdministraPropiedad> administraProps;

    public:
        Inmobiliaria(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string direccion, std::string url, std::string telefono);
        ~Inmobiliaria();

        std::string getDireccion() ;
        std::string getUrl() ;
        std::string getTelefono() ;
        std::vector<AdministraPropiedad> getadministraProps() ;
};

#endif
