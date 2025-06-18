
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


#endif