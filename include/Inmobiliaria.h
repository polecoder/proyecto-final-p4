#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "AdministraPropiedad.h"
#include "Cliente.h"
#include "Propietario.h"
#include <string>
#include <vector>

using namespace std;

class Inmobiliaria : public Usuario {
    private:
        string direccion;
        string url;
        string telefono;
        vector <AdministraPropiedad> administraProps;
        map<string, Cliente*> coleccionClientes; // se guardan los clientes suscriptos para recibir notificaciones.
        map<string, Propietario*> coleccionPropietarios;// se guardan los propietarios suscriptos para recibir notificaciones.

    public:
        Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        ~Inmobiliaria();

        string getDireccion() ;
        string getUrl() ;
        string getTelefono() ;
        vector<AdministraPropiedad> getadministraProps();
        void agregarClienteSuscripto(Cliente *cliente);
        void agregarPropietarioSuscripto(Propietario *propietario);
};

#endif