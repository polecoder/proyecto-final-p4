#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
//#include "DTNotificaciones.h"
#include <string>
#include <set>
using namespace std;

class Propietario : public Usuario {
    private:
        string cuentaBancaria;
        string telefono;
        set<DTNotificaciones> notificaciones;

    public:
        Propietario(string nickname, string contrasena, string nombre, string email, std::string cuentaBancaria, string telefono);

        string getCuentaBancaria();
        string getTelefono();
        set<DTNotificaciones> getNotificaciones();
};

#endif