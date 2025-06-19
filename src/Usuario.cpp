<<<<<<< HEAD
#include "../include/Usuario.h"
#include <iostream>
using namespace std;


Usuario::Usuario() {
    nickname = "";
    contrasena = "";
    nombre = "";
    email = "";
}

Usuario::Usuario(string nickname,string contrasena,string nombre,string email){

    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
};
Usuario:: ~Usuario(){

};


string Usuario:: getNickname()const {

    return nickname;
};
string Usuario:: getContrasena() {
    return contrasena;
};
string Usuario:: getNombre() {
    return nombre;
};
string Usuario:: getEmail() {
    return email;   


};

=======
#include <string>
#include "../include/Usuario.h"

using namespace std;

Usuario::Usuario(string nickname, string contrasena, string nombre, string email)
{
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
}

Usuario::~Usuario() {}

string Usuario::getNickname() const
{
    return this->nickname;
}

string Usuario::getContrasena() const
{
    return this->contrasena;
}

string Usuario::getNombre() const
{
    return this->nombre;
}

string Usuario::getEmail() const
{
    return this->email;
}

void Usuario::setNickname(string nickname)
{
    this->nickname = nickname;
}

void Usuario::setContrasena(string contrasena)
{
    this->contrasena = contrasena;
}

void Usuario::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Usuario::setEmail(string email)
{
    this->email = email;
}
>>>>>>> origin/main
