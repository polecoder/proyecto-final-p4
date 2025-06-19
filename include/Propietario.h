#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "DTNotificacion.h"
#include "Usuario.h"
#include <string>
#include <set>

using namespace std;

class Propietario : public Usuario {
    private:
        string cuentaBancaria;
        string telefono;
        set<DTNotificacion> notificaciones;
    public:
        Propietario(string nickname,string contrasena,string nombre,string email,string cuentaBancaria,string telefono);
        ~Propietario();
        void agregarNotificacion(DTNotificacion notificacion);
};

#endif