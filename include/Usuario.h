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
        Usuario(); // Constructor por defecto
        Usuario(string nickname, string contrasena, string nombre, string email);
        virtual ~Usuario();
        string getNickname()const ;
        string getContrasena() ;
        string getNombre() ;
        string getEmail() ;
};

#endif