#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "DTNotificacion.h"
#include <string>
#include <set>
#include <map>

class Inmobiliaria;

class Cliente : public Usuario {
    private:
        string apellido;
        string documento;
        map<string, Inmobiliaria*> suscripciones;
        set<DTNotificacion> notificaciones;

    public:
        Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
        ~Cliente();
        string getApellido();
        string getDocumento();
        map<string, Inmobiliaria*> getSuscripciones();
        void setApellido(string &apellido);
        void setDocumento(string &apellido);
        void agregarSuscripcion(Inmobiliaria* &inmobiliaria);// PRE: el cliente no esta suscripto a la inmobiliaria con nickname=nicknameInmobiliaria.
        void eliminarSuscripcion(string &nicknameInmobiliaria);// PRE: el cliente esta suscripto a la inmobiliaria con nickname=nicknameInmobiliaria.
        bool estaSuscripto(const string &nicknameInmobiliaria);
        void agregarNotificacion(DTNotificacion notificacion);
};

#endif