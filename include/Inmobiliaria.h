
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

class Inmobiliaria : public Usuario
{
private:
    string direccion;
    string url;
    string telefono;
    vector<AdministraPropiedad *> administraProps;
    map<string, Cliente *> clientesSuscritos; // se guardan los clientes suscriptos para recibir notificaciones.
    map<string, Propietario *> propietariosRepresentados;
    map<string, Propietario *> propietariosSuscritos; // se guardan los propietarios suscriptos para recibir notificaciones.

public:
    Inmobiliaria(string nickname, string contrasena, string nombre, string email, string direccion, string url, string telefono);
    ~Inmobiliaria();

    string getDireccion() const;
    string getUrl() const;
    string getTelefono() const;
    map<string, Cliente *> getClientesSuscritos() const;
    map<string, Propietario *> getPropietariosRepresentados() const;
    map<string, Propietario *> getPropietariosSuscritos() const;
    vector<AdministraPropiedad *> getAdministraProps() const;

    void agregarClienteSuscripto(Cliente *cliente);
    void agregarPropietarioRepresentado(Propietario *propietario);
    void agregarPropietarioSuscrito(Propietario *propietario);
    void agregarAdministraPropiedad(AdministraPropiedad *administraPropiedad);

    void eliminarClienteSuscrito(string nicknameCliente);
    void eliminarPropietarioRepresentado(string nicknamePropietario);
    void eliminarPropietarioSuscrito(string nicknamePropietario);
    void notificar(DTNotificacion notificacion);
};

ostream &operator<<(ostream &os, const Inmobiliaria &i);

#endif
