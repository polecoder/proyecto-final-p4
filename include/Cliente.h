#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "DTNotificacion.h"
#include "Inmobiliaria.h"
#include "DTNotificacion.h"
#include <map>
#include <string>
#include <string>
#include <set>

using namespace std;

// Forward declaration
class Inmobiliaria;

class Cliente : public Usuario {
    private:
        std::string apellido;
        std::string documento;

    public:
        Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
        ~Cliente();
        string getApellido() const;
        string getDocumento() const;
        set<DTNotificacion> getNotificaciones() const;
        map<string, Inmobiliaria*> getSuscripciones() const;
        void setApellido(string apellido);
        void setDocumento(string apellido);
        void agregarSuscripcion(Inmobiliaria* &inmobiliaria);// PRE: el cliente no esta suscripto a la inmobiliaria con nickname=nicknameInmobiliaria.
        void eliminarSuscripcion(string nicknameInmobiliaria);// PRE: el cliente esta suscripto a la inmobiliaria con nickname=nicknameInmobiliaria.
        bool estaSuscripto(const string nicknameInmobiliaria);
        void agregarNotificacion(DTNotificacion const &notificacion);
        void eliminarNotificaciones();
};

#endif