#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario {
    private:
        string nickname;
        string contrasena;
        string nombre;
        string email;

    public:
        Usuario(string nickname, string contrasena, string nombre, string email);
        virtual ~Usuario();
        string getNickname() const ;
        string getContrasena() const ;
        string getNombre() const ;
        string getEmail() const ;
};

#endif