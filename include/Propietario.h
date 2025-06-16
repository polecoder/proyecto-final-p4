#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "DTNotificacion.h"
#include <string>
#include <set>
using namespace std;

class Propietario : public Usuario {
    private:
        string cuentaBancaria;
        string telefono;
        set<DTNotificacion> notificaciones;

    public:
        Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);

        string getCuentaBancaria();
        string getTelefono();
        set<DTNotificacion> getNotificaciones();
};

#endif
