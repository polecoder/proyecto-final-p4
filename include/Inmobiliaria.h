
#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H
#include "Usuario.h"
#include "Cliente.h"
#include "Propietario.h"
#include "AdministraPropiedad.h"
#include "Cliente.h"
#include "Propietario.h"
#include "DTNotificacion.h"
#include <string>
#include <map>
#include <vector>

class AdministraPropiedad;
class Cliente;
class Propietario;

using namespace std;

class Inmobiliaria : public Usuario {
    private:
        string direccion;
        string url;
        string telefono;
        vector <AdministraPropiedad*> administraProps;
        map<string, Cliente*> clientesAsociados; // se guardan los clientes suscriptos para recibir notificaciones.
        map<string, Propietario*> PropietariosAsociados;// se guardan los propietarios suscriptos para recibir notificaciones.

    public:
        Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
        ~Inmobiliaria();

        string getDireccion() const;
        string getUrl() const;
        string getTelefono() const;
        map<string, Propietario *> getPropietarios();
        vector<AdministraPropiedad*> getadministraProps() const;
        void agregarClienteSuscripto(Cliente *cliente);
        void agregarPropietario(Propietario *propietario);
        void agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad);
        void eliminarPropietario(string nicknamePropietario);
        void notificar(DTNotificacion notificacion);
};

#endif
