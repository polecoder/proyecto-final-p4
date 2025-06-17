
#ifndef USUARIO_H
#define USUARIO_H
#include <string>

class Usuario {
    private:
        std::string nickname;
        std::string contrasena;
        std::string nombre;
        std::string email;

    public:
        Usuario(); // Constructor por defecto
        Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email);
        virtual ~Usuario();
<<<<<<< HEAD
        std::string getNickname() ;
=======
        std::string getNickname()const ;
>>>>>>> origin/main
        std::string getContrasena() ;
        std::string getNombre() ;
        std::string getEmail() ;
};

#endif