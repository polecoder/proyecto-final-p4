<<<<<<< HEAD
#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include <string>

class Cliente : public Usuario {
    private:
        std::string apellido;
        std::string documento;

    public:
        Cliente(std::string nickname, std::string contrasena, std::string nombre, std::string email, std::string apellido, std::string documento);
        ~Cliente();
};

=======
#ifndef CLIENTE_H
#define CLIENTE_H
#include "Usuario.h"
#include "DTNotificacion.h"
#include <string>
#include <set>

using namespace std;

class Cliente : public Usuario {
    private:
        string apellido;
        string documento;
        set<DTNotificacion> notificaciones;
    public:
        Cliente(string nickname, string contrasena, string nombre, string email, string apellido, string documento);
        ~Cliente();
        void agregarNotificacion(DTNotificacion notificacion);
};

>>>>>>> origin/main
#endif