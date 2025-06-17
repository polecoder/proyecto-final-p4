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
<<<<<<< HEAD
};
=======
};
>>>>>>> origin/main
