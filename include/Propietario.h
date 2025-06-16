#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "DTNotificacion.h"
#include "Usuario.h"
#include <string>

class Propietario : public Usuario {
    private:
        std::string cuentaBancaria;
        std::string telefono;
        set<DTNotificacion> notificaciones;
    public:
        Propietario(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string cuentaBancaria, std::string telefono);
        void agregarNotificacion(DTNotificacion notificacion);
};

#endif