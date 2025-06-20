#ifndef PROPIETARIO_H
#define PROPIETARIO_H
#include "DTNotificacion.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "Inmueble.h"
#include <vector>
#include <string>
#include <set>
#include <map>

class Inmueble;

using namespace std;

class Inmobiliaria;

class Propietario : public Usuario {
    private:
        string cuentaBancaria;
        string telefono;
        map<string, Inmobiliaria*> suscripciones;
        set<DTNotificacion> notificaciones;
        vector<Inmueble *> inmuebles;

    public:
        Propietario(string nickname, string contrasena, string nombre, string email, string cuentaBancaria, string telefono);
        ~Propietario();
        string getCuentaBancaria() const;
        string getTelefono() const;
        vector<Inmueble *> &getInmuebles();
        map<string, Inmobiliaria*> getSuscripciones() const;
        void setCuentaBancaria(string cuentaBancaria);
        void setTelefono(string telefono);
        void agregarSuscripcion(Inmobiliaria* inmobiliaria);//PRE: el propietario no esta suscripto a la inmobiliaria.
        void eliminarSuscripcion(string nicknameInmobiliaria);//PRE: el propietario esta suscripto a la inmobiliaria con nickname=nicknameInmobiliaria.
        bool estaSuscripto(const string &nicknameInmobiliaria);
        void agregarInmueble(Inmueble *inmueble);
        void agregarNotificacion(DTNotificacion const &notificacion);
        void eliminarNotificaciones();
        set<DTNotificacion> getNotificaciones() const;
};
#endif
