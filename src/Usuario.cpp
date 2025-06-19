#include "../include/Usuario.h"
#include <iostream>
using namespace std;

Usuario:: Usuario(std::string nickname, std::string contrasena, std::string nombre, std::string email){
    this->nickname = nickname;
    this->contrasena = contrasena;
    this->nombre = nombre;
    this->email = email;
};
Usuario:: ~Usuario(){

};
string Usuario:: getNickname() const{
    return nickname;
};
string Usuario:: getContrasena() const {
    return contrasena;
};
string Usuario:: getNombre() const {
    return nombre;
};
string Usuario:: getEmail() const {
    return email;   
};