#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "DTNotificacion.h"
#include <string>
#include <set>
#include <map>

using namespace std;

class Inmobiliaria;

class Propietario : public Usuario {
    private:
        string cuentaBancaria;
        string telefono;
        map<string, Inmobiliaria*> suscripciones;
        set<DTNotificacion> notificaciones;

    public:
        Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
        ~Propietario();
        string getCuentaBancaria() const;
        string getTelefono() const;
        map<string, Inmobiliaria*> getSuscripciones() const;
        void setCuentaBancaria(string cuentaBancaria);
        void setTelefono(string telefono);
        void agregarSuscripcion(Inmobiliaria* inmobiliaria);//PRE: el propietario no esta suscripto a la inmobiliaria.
        void eliminarSuscripcion(string nicknameInmobiliaria);//PRE: el propietario esta suscripto a la inmobiliaria con nickname=nicknameInmobiliaria.
        bool estaSuscripto(const string &nicknameInmobiliaria);
        void agregarNotificacion(DTNotificacion notificacion);
        void eliminarNotificaciones();
};


#endif