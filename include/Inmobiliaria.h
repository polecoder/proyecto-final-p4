#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "Cliente.h"
#include "Propietario.h"
#include "AdministraPropiedad.h"
#include <string>
#include <map>
#include <vector>
using namespace std;
class Inmobiliaria : public Usuario {
    private:
        string direccion;
        string url;
        string telefono;
        vector <AdministraPropiedad> administraProps;
        map<string,Cliente> clientesAsociados;
        map<string,Propietario> PropietariosAsociados;

    public:
        Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        ~Inmobiliaria();

        string getDireccion() ;
        string getUrl() ;
        string getTelefono() ;
        vector<AdministraPropiedad> getadministraProps() ;
        void notificar(DTNotificacion notificacion);
};

#endif