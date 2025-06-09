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
string Usuario:: getNickname() {
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