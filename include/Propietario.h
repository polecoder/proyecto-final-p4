#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "Usuario.h"
#include "Inmobiliaria.h"
#include <string>
#include <map>

using namespace std;

class Propietario : public Usuario {
    private:
        string cuentaBancaria;
        string telefono;
        map<string, Inmobiliaria*> suscripciones;

    public:
        Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
        ~Propietario();
        string getCuentaBancaria();
        string getTelefono();
        map<string, Inmobiliaria*> getSuscripciones();
        void setCuentaBancaria(string cuentaBancaria);
        void setTelefono(string telefono);
        void agregarSuscripcion(Inmobiliaria* &inmobiliaria);//PRE: el propietario no esta suscripto a la inmobiliaria.
        void eliminarSuscripcion(string &nicknameInmobiliaria);//PRE: el propietario esta suscripto a la inmobiliaria con nickname=nicknameInmobiliaria.
};


#endif